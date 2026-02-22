#include "tag.h"
#include "tree_sitter/parser.h"

#include <wctype.h>
#include <stdio.h>

enum TokenType {
    AUTOMATIC_SEMICOLON,
    TERNARY_QMARK,
    ELVIS_OPERATOR,
    LOGICAL_OR,
    START_TAG_NAME,
    SCRIPT_START_TAG_NAME,
    STYLE_START_TAG_NAME,
    END_TAG_NAME,
    CF_START_TAG_NAME,
    CF_END_TAG_NAME,
    ERRONEOUS_END_TAG_NAME,
    ERRONEOUS_CF_END_TAG_NAME,
    SELF_CLOSING_TAG_DELIMITER,
    IMPLICIT_END_TAG,
    IMPLICIT_CF_END_TAG,
    RAW_TEXT,
    CFML_COMMENT,
    CFQUERY_CONTENT,
    // CF_OPEN_TAG,
    // CF_CLOSE_TAG,
    CFSAVECONTENT_CONTENT,
    CFXML_CONTENT,
    CLOSE_TAG_DELIM,
    // CF_OUTPUT_TAG,
    CFSCRIPT_CONTENT,
    // CFOUTPUT_CONTENT,
    // CFFUNCTION_CONTENT,
    // HTML_HASH,
    HTML_TEXT,
    ERROR_SENTINEL
};

typedef struct {
    Array(Tag) tags;
    Array(Tag) cf_tags;
} Scanner;

typedef enum {
    REJECT,     // Semicolon is illegal, ie a syntax error occurred
    NO_NEWLINE, // Unclear if semicolon will be legal, continue
    ACCEPT,     // Semicolon is legal, assuming a comment was encountered
} WhitespaceResult;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

#define SERIALIZE_TAGS(tags_field, buffer, size) do { \
    uint16_t _count = (tags_field).size > UINT16_MAX ? UINT16_MAX : (tags_field).size; \
    uint16_t _serialized = 0; \
    unsigned _count_offset = (size); \
    (size) += sizeof(_count); \
    (size) += sizeof(_count); \
    for (; _serialized < _count; _serialized++) { \
        Tag _tag = (tags_field).contents[_serialized]; \
        if (_tag.type == CUSTOM || _tag.type == CFML || _tag.type == CF_PAIRED) { \
            unsigned _len = _tag.tag_name.size; \
            if (_len > UINT8_MAX) _len = UINT8_MAX; \
            if ((size) + 2 + _len >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) break; \
            (buffer)[(size)++] = (char)_tag.type; \
            (buffer)[(size)++] = (char)_len; \
            strncpy(&(buffer)[(size)], _tag.tag_name.contents, _len); \
            (size) += _len; \
        } else { \
            if ((size) + 1 >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) break; \
            (buffer)[(size)++] = (char)_tag.type; \
        } \
    } \
    memcpy(&(buffer)[_count_offset], &_serialized, sizeof(_serialized)); \
    memcpy(&(buffer)[_count_offset + sizeof(_serialized)], &_count, sizeof(_count)); \
} while(0)

static unsigned serialize(Scanner *scanner, char *buffer) {
    unsigned size = 0;
    SERIALIZE_TAGS(scanner->tags, buffer, size);
    SERIALIZE_TAGS(scanner->cf_tags, buffer, size);
    return size;
}

#define DESERIALIZE_TAGS(tags_field, buffer, size) do { \
    for (unsigned _i = 0; _i < (tags_field).size; _i++) tag_free(&(tags_field).contents[_i]); \
    array_clear(&(tags_field)); \
    uint16_t _serialized = 0, _count = 0; \
    memcpy(&_serialized, &(buffer)[(size)], sizeof(_serialized)); (size) += sizeof(_serialized); \
    memcpy(&_count, &(buffer)[(size)], sizeof(_count)); (size) += sizeof(_count); \
    array_reserve(&(tags_field), _count); \
    unsigned _iter = 0; \
    for (_iter = 0; _iter < _serialized; _iter++) { \
        Tag _tag = tag_new(); \
        _tag.type = (TagType)(buffer)[(size)++]; \
        if (_tag.type == CUSTOM || _tag.type == CFML || _tag.type == CF_PAIRED) { \
            uint16_t _len = (uint8_t)(buffer)[(size)++]; \
            array_reserve(&_tag.tag_name, _len); \
            _tag.tag_name.size = _len; \
            memcpy(_tag.tag_name.contents, &(buffer)[(size)], _len); \
            (size) += _len; \
        } \
        array_push(&(tags_field), _tag); \
    } \
    for (; _iter < _count; _iter++) array_push(&(tags_field), tag_new()); \
} while(0)

static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
    if (length > 0) {
        unsigned size = 0;
        DESERIALIZE_TAGS(scanner->tags, buffer, size);
        DESERIALIZE_TAGS(scanner->cf_tags, buffer, size);
    } else {
        for (unsigned i = 0; i < scanner->tags.size; i++) tag_free(&scanner->tags.contents[i]);
        array_clear(&scanner->tags);
        for (unsigned i = 0; i < scanner->cf_tags.size; i++) tag_free(&scanner->cf_tags.contents[i]);
        array_clear(&scanner->cf_tags);
    }
}

typedef struct {
    String tag_name;
    bool is_cf_tag;
} TagNameResult;

static TagNameResult scan_tag_name(TSLexer *lexer) {
    TagNameResult result;
    String tag_name = array_new();
    bool is_cf_tag = false;

    if ( lexer->lookahead == 'c' || lexer->lookahead == 'C' ) {
        array_push(&tag_name, towupper(lexer->lookahead));
        advance(lexer);
        if (lexer->lookahead == 'f' || lexer->lookahead == 'F') {
            is_cf_tag = true;
            array_push(&tag_name, towupper(lexer->lookahead));
            advance(lexer);
        }
    }

    while (( iswalnum(lexer->lookahead) || lexer->lookahead == '-' || lexer->lookahead == '_' || lexer->lookahead == ':' )) {
        array_push(&tag_name, towupper(lexer->lookahead));
        advance(lexer);
    }

    result.tag_name = tag_name;
    result.is_cf_tag = is_cf_tag;
    
    return result;
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


static bool scan_html_text(TSLexer *lexer) {
    // saw_text will be true if we see any non-whitespace content, or any whitespace content that is not a newline and
    // does not immediately follow a newline.
    bool saw_text = false;
    // at_newline will be true if we are currently at a newline, or if we are at whitespace that is not a newline but
    // immediately follows a newline.
    bool at_newline = false;

    while (lexer->lookahead != 0 && lexer->lookahead != '<' && lexer->lookahead != '>' && lexer->lookahead != '{' &&
           lexer->lookahead != '}' && lexer->lookahead != '&') {
        bool is_wspace = iswspace(lexer->lookahead);
        if (lexer->lookahead == '\n') {
            at_newline = true;
        } else {
            // If at_newline is already true, and we see some whitespace, then it must stay true.
            // Otherwise, it should be false.
            //
            // See the table below to determine the logic for computing `saw_text`.
            //
            // |------------------------------------|
            // | at_newline | is_wspace | saw_text  |
            // |------------|-----------|-----------|
            // | false (0)  | false (0) | true  (1) |
            // | false (0)  | true  (1) | true  (1) |
            // | true  (1)  | false (0) | true  (1) |
            // | true  (1)  | true  (1) | false (0) |
            // |------------------------------------|

            at_newline &= is_wspace;
            if (!at_newline) {
                saw_text = true;
            }
        }

        advance(lexer);
    }

    lexer->result_symbol = HTML_TEXT;
    return saw_text;
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

static bool scan_cfxml_content(Scanner *scanner, TSLexer *lexer) {

    lexer->mark_end(lexer);

    const char *end_delimiter = "</CFXML";

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

    lexer->result_symbol = CFXML_CONTENT;

    while (lexer->lookahead) {
        advance(lexer);
    }

    return true;
}

static bool scan_cfscript_content(Scanner *scanner, TSLexer *lexer) {

    lexer->mark_end(lexer);

    const char *end_delimiter = "</CFSCRIPT";

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

    lexer->result_symbol = CFSCRIPT_CONTENT;

    while (lexer->lookahead) {
        advance(lexer);
    }

    return true;
}

// static bool scan_cfoutput_content(Scanner *scanner, TSLexer *lexer) {

//     lexer->mark_end(lexer);

//     const char *end_delimiter = "</CFOUTPUT";

//     unsigned delimiter_index = 0;

//     while (lexer->lookahead) {
//         printf("%c", towupper(lexer->lookahead));
//         if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
//             delimiter_index++;
//             if (delimiter_index == strlen(end_delimiter)) {
//                 break;
//             }
//             advance(lexer);
//         } else {
//             delimiter_index = 0;
//             advance(lexer);
//             lexer->mark_end(lexer);
//         }
//     }

//     lexer->result_symbol = CFOUTPUT_CONTENT;

//     while (lexer->lookahead) {
//         advance(lexer);
//     }

//     return true;
// }

// static bool scan_cffunction_content(Scanner *scanner, TSLexer *lexer) {

//     lexer->mark_end(lexer);

//     const char *end_delimiter = "</CFFUNCTION";

//     unsigned delimiter_index = 0;

//     while (lexer->lookahead) {
//         if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
//             delimiter_index++;
//             if (delimiter_index == strlen(end_delimiter)) {
//                 break;
//             }
//             advance(lexer);
//         } else {
//             delimiter_index = 0;
//             advance(lexer);
//             lexer->mark_end(lexer);
//         }
//     }

//     lexer->result_symbol = CFFUNCTION_CONTENT;

//     while (lexer->lookahead) {
//         advance(lexer);
//     }

//     return true;
// }

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

static void pop_tag(Scanner *scanner, bool is_cf_context) {
    if ( is_cf_context ) {
        Tag popped_tag = array_pop(&scanner->cf_tags);
        tag_free(&popped_tag);
    } else {
        Tag popped_tag = array_pop(&scanner->tags);
        tag_free(&popped_tag);
    }
}

static bool scan_implicit_end_tag(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {
    
    Tag *parent = scanner->tags.size == 0 ? NULL : ( is_cf_context ?  array_back(&scanner->cf_tags) : array_back(&scanner->tags) );

    bool is_closing_tag = false;
    if (lexer->lookahead == '/') {
        is_closing_tag = true;
        advance(lexer);
    } else {
        if (parent && tag_is_void(parent)) {
            pop_tag(scanner, is_cf_context);
            lexer->result_symbol = IMPLICIT_END_TAG;
            return true;
        }
    }

    TagNameResult result = scan_tag_name(lexer);
    if (result.tag_name.size == 0 && !lexer->eof(lexer)) {
        array_delete(&result.tag_name);
        return false;
    }

    // For CF tags scanned with full name (e.g. CFTEST), strip CF prefix to match
    // tags pushed without prefix (after _cf_open_tag consumed '<cf')
    String *name = &result.tag_name;
    if (result.is_cf_tag && name->size > 2) {
        // shift contents left by 2 to remove 'CF' prefix
        memmove(name->contents, name->contents + 2, name->size - 2);
        name->size -= 2;
    }

    Tag next_tag = result.is_cf_tag ? cf_tag_for_name(result.tag_name) : tag_for_name(result.tag_name); 

    if (is_closing_tag) {
        // The tag correctly closes the topmost element on the stack
        if (scanner->tags.size > 0 && tag_eq(is_cf_context ? array_back(&scanner->cf_tags) : array_back(&scanner->tags), &next_tag)) {
            tag_free(&next_tag);
            return false;
        }

        // Otherwise, dig deeper and queue implicit end tags (to be nice in
        // the case of malformed HTML)
        for (unsigned i = scanner->tags.size; i > 0; i--) {
            if (tag_eq(&scanner->tags.contents[i - 1], &next_tag)) {
                pop_tag(scanner, is_cf_context);
                lexer->result_symbol = IMPLICIT_END_TAG;
                tag_free(&next_tag);
                return true;
            }
        }
    } else if (
        parent && (parent->type == CFML)
    ) {
        tag_free(&next_tag);
        return false;
    } else if (
        parent &&
        (
            ((parent->type == HTML || parent->type == HEAD || parent->type == BODY) && lexer->eof(lexer))
        )
    ) {
        pop_tag(scanner, is_cf_context);
        lexer->result_symbol = IMPLICIT_END_TAG;
        tag_free(&next_tag);
        return true;
    }

    tag_free(&next_tag);
    return false;
}

static bool scan_start_tag_name(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {

    TagNameResult result = scan_tag_name(lexer);

    if (result.tag_name.size == 0) {
        array_delete(&result.tag_name);
        return false;
    }

    bool is_cf = result.is_cf_tag || is_cf_context;
    Tag tag = is_cf ? cf_tag_for_name(result.tag_name) : tag_for_name(result.tag_name);
    switch (tag.type) {
        case SCRIPT:
            lexer->result_symbol = SCRIPT_START_TAG_NAME;
            array_push(&scanner->tags, tag);
            break;
        case STYLE:
            lexer->result_symbol = STYLE_START_TAG_NAME;
            array_push(&scanner->tags, tag);
            break;
        case CF_VOID:
            return false;
        case CF_PAIRED:
            return false;
        case CF_SET:
            return false;
        default:
            lexer->result_symbol = is_cf ? CF_START_TAG_NAME : START_TAG_NAME;
            if ( is_cf ) {
                array_push(&scanner->cf_tags, tag);
            } else {
                array_push(&scanner->tags, tag);
            }
            break;
    }
    return true;
}

static bool scan_end_tag_name(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {
    
    TagNameResult result = scan_tag_name(lexer);

    if (result.tag_name.size == 0) {
        array_delete(&result.tag_name);
        return false;
    }

    bool is_cf = result.is_cf_tag || is_cf_context;
    Tag tag = is_cf ? cf_tag_for_name(result.tag_name) : tag_for_name(result.tag_name);
    if (is_cf ? (scanner->cf_tags.size > 0 && tag_eq(array_back(&scanner->cf_tags), &tag))
              : (scanner->tags.size > 0 && tag_eq(array_back(&scanner->tags), &tag))) {
        pop_tag(scanner, is_cf);
        lexer->result_symbol = is_cf ? CF_END_TAG_NAME : END_TAG_NAME;
    } else {
        lexer->result_symbol = is_cf ? ERRONEOUS_CF_END_TAG_NAME : ERRONEOUS_END_TAG_NAME;
    }

    tag_free(&tag);
    return true;
}


static bool scan_self_closing_tag_delimiter(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {
    advance(lexer);
    if (lexer->lookahead == '>') {
        advance(lexer);
        if (scanner->tags.size > 0) {
            Tag *top = array_back(&scanner->tags);
            pop_tag(scanner, is_cf_context);
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

        if (lexer->lookahead == ':') {

            advance(lexer);
            lexer->mark_end(lexer);
            lexer->result_symbol = ELVIS_OPERATOR;

            return true;
        
        } else if (lexer->lookahead == '?') {
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

// static bool scan_open_cfoutput(Scanner *scanner, TSLexer *lexer, const bool *cf_open_valid, bool *scanned_cfoutput) {
    
//     if ( lexer->lookahead == 'C' || lexer->lookahead == 'c' ) {
//         advance(lexer);
//     }

//     if ( lexer->lookahead != 'F' && lexer->lookahead != 'f' ) {
//         return false;
//     }

//     advance(lexer);

//     if ( lexer->lookahead == 'O' || lexer->lookahead == 'o' ) {
//         String tag_name = scan_tag_name(lexer);
//         Tag tag = tag_for_name(tag_name);
//         if (tag.type == OUTPUT) {
//             lexer->mark_end(lexer);
//             lexer->result_symbol = CF_OUTPUT_TAG;
//             *scanned_cfoutput = true;
//             return true;
//         }
//     }

//     if ( cf_open_valid ) {
//         lexer->mark_end(lexer);
//         lexer->result_symbol = CF_OPEN_TAG;
//         return true;
//     }

//     return false;
// }

// static bool scan_open_cftag(Scanner *scanner, TSLexer *lexer) {
    
//     if ( lexer->lookahead != 'F' && lexer->lookahead != 'f' ) {
//         return false;
//     }

//     advance(lexer);
//     lexer->mark_end(lexer);
//     lexer->result_symbol = CF_OPEN_TAG;
    
//     return true;
    
// }

// static bool scan_close_cftag(Scanner *scanner, TSLexer *lexer) {
    
//     if ( lexer->lookahead != 'F' && lexer->lookahead != 'f' ) {
//         return false;
//     }

//     advance(lexer);

//     lexer->mark_end(lexer);
    
//     lexer->result_symbol = CF_CLOSE_TAG;

//     return true;
// }

static bool scan_closetag_delim(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {

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

    // bool scanned_cfoutput = false;

    if (valid_symbols[ERROR_SENTINEL]) {
        return false;
    }

    if (valid_symbols[RAW_TEXT] && !valid_symbols[START_TAG_NAME] && !valid_symbols[END_TAG_NAME]) {
        return scan_raw_text(scanner, lexer);
    }

    if (!valid_symbols[HTML_TEXT]) {
        while (iswspace(lexer->lookahead)) {
            skip(lexer);
        }
    }

    if (valid_symbols[CFQUERY_CONTENT]) {
        return scan_cfquery_content(scanner, lexer);
    }

    if (valid_symbols[CFSAVECONTENT_CONTENT]) {
        return scan_cfsavecontent_content(scanner, lexer);
    }

    if (valid_symbols[CFXML_CONTENT]) {
        return scan_cfxml_content(scanner, lexer);
    }

    if (valid_symbols[CFSCRIPT_CONTENT]) {
        return scan_cfscript_content(scanner, lexer);
    }

    if (valid_symbols[HTML_TEXT] && scan_html_text(lexer)) {
        return true;
    }

    // if (valid_symbols[CFOUTPUT_CONTENT]) {
    //     return scan_cfoutput_content(scanner, lexer);
    // }

    // if (valid_symbols[CFFUNCTION_CONTENT]) {
    //     return scan_cffunction_content(scanner, lexer);
    // }

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

            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, false);
            } else if ( valid_symbols[IMPLICIT_CF_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, true);
            }

            break;

        case '\0':
            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, false);
             } else if ( valid_symbols[IMPLICIT_CF_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, true);
            }
            break;

        case '/':
            advance(lexer);
            if (lexer->lookahead == '>') {
                if (valid_symbols[SELF_CLOSING_TAG_DELIMITER]) {
                    return scan_self_closing_tag_delimiter(scanner, lexer, false);
                }
                if (valid_symbols[CLOSE_TAG_DELIM] ) {
                    return scan_closetag_delim(scanner, lexer, false);
                }
            } else if ( lexer->lookahead == '/' || lexer->lookahead == '*' ) {
                if ( !scan_script_comment(lexer) ) {
                    return false;
                }
            // } else if ( valid_symbols[CF_CLOSE_TAG] && ( lexer->lookahead == 'C' || lexer->lookahead == 'c' ) ) {
            //     if ( valid_symbols[CF_CLOSE_TAG] ) {
            //         advance(lexer);
            //         return scan_close_cftag(scanner, lexer);
            //     } else {
            //         return false;
            //     }
            }

            break;

        default:
            
            if ((valid_symbols[START_TAG_NAME] || valid_symbols[END_TAG_NAME] || valid_symbols[CF_START_TAG_NAME] || valid_symbols[CF_END_TAG_NAME]) && !valid_symbols[RAW_TEXT]) {
                if (valid_symbols[START_TAG_NAME] || valid_symbols[CF_START_TAG_NAME]) {
                    return scan_start_tag_name(scanner, lexer, valid_symbols[CF_START_TAG_NAME]);
                }
                if (valid_symbols[END_TAG_NAME] || valid_symbols[CF_END_TAG_NAME]) {
                    return scan_end_tag_name(scanner, lexer, valid_symbols[CF_END_TAG_NAME]);
                }
            }
            
            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, false);
            } else if (valid_symbols[IMPLICIT_CF_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, true);
            }

            if (valid_symbols[CLOSE_TAG_DELIM] ) {
                if ( scan_closetag_delim(scanner, lexer, false) ) {
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

    if (valid_symbols[TERNARY_QMARK] || valid_symbols[ELVIS_OPERATOR]) {
        return scan_ternary_qmark(lexer);
    }

    return false;
}