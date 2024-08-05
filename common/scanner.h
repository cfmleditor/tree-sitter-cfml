#include "tag.h"
#include "tree_sitter/parser.h"

#include <wctype.h>
#include <stdio.h>

enum TokenType {
    AUTOMATIC_SEMICOLON,
    TERNARY_QMARK,
    LOGICAL_OR,
    START_TAG_NAME,
    SCRIPT_START_TAG_NAME,
    STYLE_START_TAG_NAME,
    END_TAG_NAME,
    ERRONEOUS_END_TAG_NAME,
    SELF_CLOSING_TAG_DELIMITER,
    IMPLICIT_END_TAG,
    RAW_TEXT,
    CFML_COMMENT,
    CFQUERY_CONTENT,
    CF_OPEN_TAG,
    CF_CLOSE_TAG,
    CFSAVECONTENT_CONTENT,
    CLOSE_TAG_DELIM,
    CF_OUTPUT_TAG,
    // HTML_HASH,
};

typedef struct {
    Array(Tag) tags;
} Scanner;

typedef enum {
    REJECT,     // Semicolon is illegal, ie a syntax error occurred
    NO_NEWLINE, // Unclear if semicolon will be legal, continue
    ACCEPT,     // Semicolon is legal, assuming a comment was encountered
} WhitespaceResult;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static unsigned serialize(Scanner *scanner, char *buffer) {
    uint16_t tag_count = scanner->tags.size > UINT16_MAX ? UINT16_MAX : scanner->tags.size;
    uint16_t serialized_tag_count = 0;

    unsigned size = sizeof(tag_count);
    memcpy(&buffer[size], &tag_count, sizeof(tag_count));
    size += sizeof(tag_count);

    for (; serialized_tag_count < tag_count; serialized_tag_count++) {
        Tag tag = scanner->tags.contents[serialized_tag_count];
        if (tag.type == CUSTOM) {
            unsigned name_length = tag.custom_tag_name.size;
            if (name_length > UINT8_MAX) {
                name_length = UINT8_MAX;
            }
            if (size + 2 + name_length >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
                break;
            }
            buffer[size++] = (char)tag.type;
            buffer[size++] = (char)name_length;
            strncpy(&buffer[size], tag.custom_tag_name.contents, name_length);
            size += name_length;
        } else {
            if (size + 1 >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
                break;
            }
            buffer[size++] = (char)tag.type;
        }
    }

    memcpy(&buffer[0], &serialized_tag_count, sizeof(serialized_tag_count));
    return size;
}

static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
    for (unsigned i = 0; i < scanner->tags.size; i++) {
        tag_free(&scanner->tags.contents[i]);
    }
    array_clear(&scanner->tags);

    if (length > 0) {
        unsigned size = 0;
        uint16_t tag_count = 0;
        uint16_t serialized_tag_count = 0;

        memcpy(&serialized_tag_count, &buffer[size], sizeof(serialized_tag_count));
        size += sizeof(serialized_tag_count);

        memcpy(&tag_count, &buffer[size], sizeof(tag_count));
        size += sizeof(tag_count);

        array_reserve(&scanner->tags, tag_count);
        if (tag_count > 0) {
            unsigned iter = 0;
            for (iter = 0; iter < serialized_tag_count; iter++) {
                Tag tag = tag_new();
                tag.type = (TagType)buffer[size++];
                if (tag.type == CUSTOM) {
                    uint16_t name_length = (uint8_t)buffer[size++];
                    array_reserve(&tag.custom_tag_name, name_length);
                    tag.custom_tag_name.size = name_length;
                    memcpy(tag.custom_tag_name.contents, &buffer[size], name_length);
                    size += name_length;
                }
                array_push(&scanner->tags, tag);
            }
            // add zero tags if we didn't read enough, this is because the
            // buffer had no more room but we held more tags.
            for (; iter < tag_count; iter++) {
                array_push(&scanner->tags, tag_new());
            }
        }
    }
}

static String scan_tag_name(TSLexer *lexer) {
    String tag_name = array_new();
    while (iswalnum(lexer->lookahead) || lexer->lookahead == '-' || lexer->lookahead == '_' || lexer->lookahead == ':') {
        array_push(&tag_name, towupper(lexer->lookahead));
        advance(lexer);
    }
    return tag_name;
}

static bool scan_comment(TSLexer *lexer) {
    if (lexer->lookahead != '-') {
        return false;
    }
    advance(lexer);
    if (lexer->lookahead != '-') {
        return false;
    }

    advance(lexer);

    unsigned dashes = 0;
    unsigned direction = -1;
    unsigned nesting = 1;

    while (lexer->lookahead) {
        switch (lexer->lookahead) {
            case '-':
                ++dashes;
                if ( direction == 1 && dashes >= 2 ) {
                    ++nesting;
                    dashes = 0;
                }
                break;
            case '>':
                if (dashes >= 2) {
                    --nesting;
                    lexer->result_symbol = CFML_COMMENT;
                    advance(lexer);
                    lexer->mark_end(lexer);
                    if ( nesting == 0 ) {
                        return true;
                    } else {
                        break;
                    }
                }
            case '<':
                direction = 0;
                break;
            case '!':
                if ( direction == 0 ) {
                    direction = 1;
                    break;
                }
            default:
                direction = -1;
                dashes = 0;
        }
        advance(lexer);
    }
    return false;
}

static WhitespaceResult scan_whitespace_and_comments(TSLexer *lexer, bool *scanned_comment, bool consume) {
    bool saw_block_newline = false;
    for (;;) {
        while (iswspace(lexer->lookahead)) {
            skip(lexer);
        }

        if (lexer->lookahead == '/') {
            skip(lexer);

            if (lexer->lookahead == '/') {
                skip(lexer);
                while (lexer->lookahead != 0 && lexer->lookahead != '\n' && lexer->lookahead != 0x2028 && lexer->lookahead != 0x2029) {
                    skip(lexer);
                }
                *scanned_comment = true;
            } else if (lexer->lookahead == '*') {
                skip(lexer);
                while (lexer->lookahead != 0) {
                    if (lexer->lookahead == '*') {
                        skip(lexer);
                        if (lexer->lookahead == '/') {
                            skip(lexer);
                            *scanned_comment = true;

                            if (lexer->lookahead != '/' && !consume) {
                                return saw_block_newline ? ACCEPT : NO_NEWLINE;
                            }

                            break;
                        }
                    } else if (lexer->lookahead == '\n' || lexer->lookahead == 0x2028 || lexer->lookahead == 0x2029) {
                        saw_block_newline = true;
                        skip(lexer);
                    } else {
                        skip(lexer);
                    }
                }
            } else {
                return REJECT;
            }
        } else {
            return ACCEPT;
        }
    }
}

static bool scan_script_comment(TSLexer *lexer) {

    for (;;) {

        if (lexer->lookahead == '/') {
            skip(lexer);
            while (lexer->lookahead != 0 && lexer->lookahead != '\n' && lexer->lookahead != 0x2028 &&
                    lexer->lookahead != 0x2029) {
                skip(lexer);
            }
            //*scanned_comment = true;
        } else if (lexer->lookahead == '*') {
            skip(lexer);
            while (lexer->lookahead != 0) {
                if (lexer->lookahead == '*') {
                    skip(lexer);
                    if (lexer->lookahead == '/') {
                        skip(lexer);
                        //*scanned_comment = true;
                        break;
                    }
                } else {
                    skip(lexer);
                }
            }
        } else {
            return false;
        }
    }
}

static bool scan_cfquery_content(Scanner *scanner, TSLexer *lexer) {
    
    lexer->mark_end(lexer);

    const char *end_delimiter = "</CFQUERY";

    unsigned delimiter_index = 0;

    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == strlen(end_delimiter)) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = CFQUERY_CONTENT;

    while (lexer->lookahead) {
        advance(lexer);
    }

    return true;
}

static bool scan_cfsavecontent_content(Scanner *scanner, TSLexer *lexer) {

    lexer->mark_end(lexer);

    const char *end_delimiter = "</CFSAVECONTENT";

    unsigned delimiter_index = 0;

    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == strlen(end_delimiter)) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = CFSAVECONTENT_CONTENT;

    while (lexer->lookahead) {
        advance(lexer);
    }

    return true;
}

static bool scan_raw_text(Scanner *scanner, TSLexer *lexer) {
    if (scanner->tags.size == 0) {
        return false;
    }

    lexer->mark_end(lexer);

    const char *end_delimiter = array_back(&scanner->tags)->type == SCRIPT ? "</SCRIPT" : "</STYLE";

    unsigned delimiter_index = 0;
    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == strlen(end_delimiter)) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = RAW_TEXT;
    return true;
}

static void pop_tag(Scanner *scanner) {
    Tag popped_tag = array_pop(&scanner->tags);
    tag_free(&popped_tag);
}

static bool scan_implicit_end_tag(Scanner *scanner, TSLexer *lexer) {
    
    Tag *parent = scanner->tags.size == 0 ? NULL : array_back(&scanner->tags);

    bool is_closing_tag = false;
    if (lexer->lookahead == '/') {
        is_closing_tag = true;
        advance(lexer);
    } else {
        if (parent && tag_is_void(parent)) {
            pop_tag(scanner);
            lexer->result_symbol = IMPLICIT_END_TAG;
            return true;
        }
    }

    String tag_name = scan_tag_name(lexer);
    if (tag_name.size == 0 && !lexer->eof(lexer)) {
        array_delete(&tag_name);
        return false;
    }

    Tag next_tag = tag_for_name(tag_name);

    if (is_closing_tag) {
        // The tag correctly closes the topmost element on the stack
        if (scanner->tags.size > 0 && tag_eq(array_back(&scanner->tags), &next_tag)) {
            tag_free(&next_tag);
            return false;
        }

        // Otherwise, dig deeper and queue implicit end tags (to be nice in
        // the case of malformed HTML)
        for (unsigned i = scanner->tags.size; i > 0; i--) {
            if (scanner->tags.contents[i - 1].type == next_tag.type) {
                pop_tag(scanner);
                lexer->result_symbol = IMPLICIT_END_TAG;
                tag_free(&next_tag);
                return true;
            }
        }
    } else if (
        parent &&
        (
            !tag_can_contain(parent, &next_tag) ||
            ((parent->type == HTML || parent->type == HEAD || parent->type == BODY) && lexer->eof(lexer))
        )
    ) {
        pop_tag(scanner);
        lexer->result_symbol = IMPLICIT_END_TAG;
        tag_free(&next_tag);
        return true;
    }

    tag_free(&next_tag);
    return false;
}

static bool scan_start_tag_name(Scanner *scanner, TSLexer *lexer) {

    String tag_name = scan_tag_name(lexer);

    if (tag_name.size == 0) {
        array_delete(&tag_name);
        return false;
    }

    Tag tag = tag_for_name(tag_name);
    array_push(&scanner->tags, tag);
    switch (tag.type) {
        case SCRIPT:
            lexer->result_symbol = SCRIPT_START_TAG_NAME;
            break;
        case STYLE:
            lexer->result_symbol = STYLE_START_TAG_NAME;
            break;
        default:
            lexer->result_symbol = START_TAG_NAME;
            break;
    }
    return true;
}

static bool scan_end_tag_name(Scanner *scanner, TSLexer *lexer) {
    
    String tag_name = scan_tag_name(lexer);

    if (tag_name.size == 0) {
        array_delete(&tag_name);
        return false;
    }

    Tag tag = tag_for_name(tag_name);
    if (scanner->tags.size > 0 && tag_eq(array_back(&scanner->tags), &tag)) {
        pop_tag(scanner);
        lexer->result_symbol = END_TAG_NAME;
    } else {
        lexer->result_symbol = ERRONEOUS_END_TAG_NAME;
    }

    tag_free(&tag);
    return true;
}


static bool scan_self_closing_tag_delimiter(Scanner *scanner, TSLexer *lexer) {
    advance(lexer);
    if (lexer->lookahead == '>') {
        advance(lexer);
        if (scanner->tags.size > 0) {
            pop_tag(scanner);
            lexer->result_symbol = SELF_CLOSING_TAG_DELIMITER;
        }
        return true;
    }
    return false;
}

static bool scan_automatic_semicolon(TSLexer *lexer, bool comment_condition, bool *scanned_comment) {
    lexer->result_symbol = AUTOMATIC_SEMICOLON;
    lexer->mark_end(lexer);

    for (;;) {
        if (lexer->lookahead == 0) {
            return true;
        }

        if (lexer->lookahead == '/') {
            WhitespaceResult result = scan_whitespace_and_comments(lexer, scanned_comment, false);
            if (result == false) {
                return false;
            }
            if (result == true && comment_condition && lexer->lookahead != ',' && lexer->lookahead != '=') {
                return true;
            }
        }

        if (lexer->lookahead == '}') {
            return true;
        }

        if (lexer->is_at_included_range_start(lexer)) {
            return true;
        }

        if (lexer->lookahead == '\n' || lexer->lookahead == 0x2028 || lexer->lookahead == 0x2029) {
            break;
        }

        if (!iswspace(lexer->lookahead)) {
            return false;
        }

        skip(lexer);
    }

    skip(lexer);

    if (scan_whitespace_and_comments(lexer, scanned_comment, true) == REJECT) {
        return false;
    }

    switch (lexer->lookahead) {
        case '`':
        case ',':
        case ':':
        case ';':
        case '*':
        case '%':
        case '>':
        case '<':
        case '=':
        case '[':
        case '(':
        case '?':
        case '^':
        case '|':
        case '&':
        case '/':
            return false;
        
        // Insert a semicolon before decimals literals but not otherwise.
        case '.':
            skip(lexer);
            return iswdigit(lexer->lookahead);

        // Insert a semicolon before `--` and `++`, but not before binary `+` or `-`.
        case '+':
            skip(lexer);
            return lexer->lookahead == '+';
        case '-':
            skip(lexer);
            return lexer->lookahead == '-';

        // Don't insert a semicolon before `!=`, but do insert one before a unary `!`.
        case '!':
            skip(lexer);
            return lexer->lookahead != '=';

        // Don't insert a semicolon before `in` or `instanceof`, but do insert one
        // before an identifier.
        case 'i':
            skip(lexer);

            if (lexer->lookahead != 'n') {
                return true;
            }
            skip(lexer);

            if (!iswalpha(lexer->lookahead)) {
                return false;
            }

            for (unsigned i = 0; i < 8; i++) {
                if (lexer->lookahead != "stanceof"[i]) {
                    return true;
                }
                skip(lexer);
            }

            if (!iswalpha(lexer->lookahead)) {
                return false;
            }
            break;

        default:
            break;
    }

    return true;
}

static bool scan_ternary_qmark(TSLexer *lexer) {
    for (;;) {
        if (!iswspace(lexer->lookahead)) {
            break;
        }
        skip(lexer);
    }

    if (lexer->lookahead == '?') {
        advance(lexer);

        if (lexer->lookahead == '?') {
            return false;
        }

        lexer->mark_end(lexer);
        lexer->result_symbol = TERNARY_QMARK;

        if (lexer->lookahead == '.') {
            advance(lexer);
            if (iswdigit(lexer->lookahead)) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

static bool scan_open_cfoutput(Scanner *scanner, TSLexer *lexer, const bool *cf_open_valid, bool *scanned_cfoutput) {
    
    if ( lexer->lookahead == 'C' || lexer->lookahead == 'c' ) {
        advance(lexer);
    }

    if ( lexer->lookahead != 'F' && lexer->lookahead != 'f' ) {
        return false;
    }

    advance(lexer);

    if ( lexer->lookahead == 'O' || lexer->lookahead == 'o' ) {
        String tag_name = scan_tag_name(lexer);
        Tag tag = tag_for_name(tag_name);
        if (tag.type == OUTPUT) {
            lexer->mark_end(lexer);
            lexer->result_symbol = CF_OUTPUT_TAG;
            *scanned_cfoutput = true;
            return true;
        }
    }

    if ( cf_open_valid ) {
        lexer->mark_end(lexer);
        lexer->result_symbol = CF_OPEN_TAG;
        return true;
    }

    return false;
}

static bool scan_open_cftag(Scanner *scanner, TSLexer *lexer) {
    
    if ( lexer->lookahead != 'F' && lexer->lookahead != 'f' ) {
        return false;
    }

    advance(lexer);
    lexer->mark_end(lexer);
    lexer->result_symbol = CF_OPEN_TAG;
    
    return true;
    
}

static bool scan_close_cftag(Scanner *scanner, TSLexer *lexer) {
    
    if ( lexer->lookahead != 'F' && lexer->lookahead != 'f' ) {
        return false;
    }

    advance(lexer);

    lexer->mark_end(lexer);
    
    lexer->result_symbol = CF_CLOSE_TAG;

    return true;
}

static bool scan_closetag_delim(Scanner *scanner, TSLexer *lexer) {

    if ( lexer->lookahead == '>' ) {
        advance(lexer);
        lexer->mark_end(lexer);
        lexer->result_symbol = CLOSE_TAG_DELIM;
        return true;
    } else {
        return false;
    }
    
}

// static bool scan_hash(Scanner *scanner, TSLexer *lexer) {

//     if ( lexer->lookahead == '#' ) {
//         advance(lexer);
//         lexer->mark_end(lexer);
//         lexer->result_symbol = HTML_HASH;
//         return true;
//     } else {
//         return false;
//     }
    
// }

static bool external_scanner_scan(Scanner *scanner, TSLexer *lexer, const bool *valid_symbols) {

    bool scanned_cfoutput = false;

    if (valid_symbols[RAW_TEXT] && !valid_symbols[START_TAG_NAME] && !valid_symbols[END_TAG_NAME]) {
        return scan_raw_text(scanner, lexer);
    }

    while (iswspace(lexer->lookahead)) {
        skip(lexer);
    }

    if (valid_symbols[CFQUERY_CONTENT]) {
        return scan_cfquery_content(scanner, lexer);
    }

    if (valid_symbols[CFSAVECONTENT_CONTENT]) {
        return scan_cfsavecontent_content(scanner, lexer);
    }

    // if ( valid_symbols[HTML_HASH] ) {
    //     return scan_hash(scanner, lexer);
    // }

    switch (lexer->lookahead) {
        case ';':
            return false;
        break;
        case '<':
            lexer->mark_end(lexer);
            advance(lexer);

            if (valid_symbols[CFML_COMMENT] && lexer->lookahead == '!') {
                advance(lexer);
                return scan_comment(lexer);
            }

            if ( lexer->lookahead == 'C' || lexer->lookahead == 'c' ) {
                if ( valid_symbols[CF_OUTPUT_TAG] ) {
                    advance(lexer);
                    return scan_open_cfoutput(scanner, lexer, &valid_symbols[CF_OPEN_TAG], &scanned_cfoutput);
                } else if ( valid_symbols[CF_OPEN_TAG] ) {
                    advance(lexer);
                    return scan_open_cftag(scanner, lexer);
                }
            }

            if ( lexer->lookahead == '/') {
                advance(lexer);
                if ( lexer->lookahead == 'C' || lexer->lookahead == 'c' ) {
                    if ( valid_symbols[CF_CLOSE_TAG] ) {
                        advance(lexer);
                        return scan_close_cftag(scanner, lexer);
                    }
                }
            }

            if (valid_symbols[IMPLICIT_END_TAG] && !valid_symbols[CF_OPEN_TAG] && !valid_symbols[CF_OUTPUT_TAG]) {
                return scan_implicit_end_tag(scanner, lexer);
            }

            break;

        case '\0':
            if (valid_symbols[IMPLICIT_END_TAG] && !valid_symbols[CF_OPEN_TAG] && !valid_symbols[CF_OUTPUT_TAG]) {
                return scan_implicit_end_tag(scanner, lexer);
            }
            break;

        case '/':
            advance(lexer);
            if (lexer->lookahead == '>') {
                if (valid_symbols[SELF_CLOSING_TAG_DELIMITER]) {
                    return scan_self_closing_tag_delimiter(scanner, lexer);
                }
                if (valid_symbols[CLOSE_TAG_DELIM] ) {
                    return scan_closetag_delim(scanner, lexer);
                }
            } else if ( lexer->lookahead == '/' || lexer->lookahead == '*' ) {
                if ( !scan_script_comment(lexer) ) {
                    return false;
                }
            } else if ( lexer->lookahead == 'C' || lexer->lookahead == 'c' ) {
                if ( valid_symbols[CF_CLOSE_TAG] ) {
                    advance(lexer);
                    return scan_close_cftag(scanner, lexer);
                } else {
                    return false;
                }
            }

            break;

        default:
            
            if ((valid_symbols[START_TAG_NAME] || valid_symbols[END_TAG_NAME]) && !valid_symbols[RAW_TEXT]) {
                return valid_symbols[START_TAG_NAME] ? scan_start_tag_name(scanner, lexer)
                                                     : scan_end_tag_name(scanner, lexer);
            }
            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer);
            }

            if (valid_symbols[CLOSE_TAG_DELIM] ) {
                if ( scan_closetag_delim(scanner, lexer) ) {
                    return true;
                }
            }
            
    }

    if (valid_symbols[AUTOMATIC_SEMICOLON]) {
        bool scanned_comment = false;
        bool ret = scan_automatic_semicolon(lexer, !valid_symbols[LOGICAL_OR], &scanned_comment);
        if (!ret && !scanned_comment && valid_symbols[TERNARY_QMARK] && lexer->lookahead == '?') {
            return scan_ternary_qmark(lexer);
        }
        return ret;
    }

    if (valid_symbols[TERNARY_QMARK]) {
        return scan_ternary_qmark(lexer);
    }

    return false;
}