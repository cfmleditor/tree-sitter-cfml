#include "tree_sitter/parser.h"
#include "tag.h"

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
    COMMENT
};

typedef struct {
    uint32_t len;
    uint32_t cap;
    Tag *data;
} tags_vec;

typedef struct {
    tags_vec tags;
} Scanner;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define VEC_RESIZE(vec, _cap)                                                  \
    if ((_cap) > (vec).cap && (_cap) > 0) {                                    \
        void *tmp = realloc((vec).data, (_cap) * sizeof((vec).data[0]));       \
        assert(tmp != NULL);                                                   \
        (vec).data = tmp;                                                      \
        (vec).cap = (_cap);                                                    \
    }

#define VEC_GROW(vec, _cap)                                                    \
    if ((vec).cap < (_cap)) {                                                  \
        VEC_RESIZE((vec), (_cap));                                             \
    }

#define VEC_PUSH(vec, el)                                                      \
    if ((vec).cap == (vec).len) {                                              \
        VEC_RESIZE((vec), MAX(16, (vec).len * 2));                             \
    }                                                                          \
    (vec).data[(vec).len++] = (el);

#define VEC_POP(vec)                                                           \
    {                                                                          \
        if (VEC_BACK(vec).type == CUSTOM) {                                    \
            tag_free(&VEC_BACK(vec));                                          \
        }                                                                      \
        (vec).len--;                                                           \
    }

#define VEC_BACK(vec) ((vec).data[(vec).len - 1])

#define VEC_FREE(vec)                                                          \
    {                                                                          \
        if ((vec).data != NULL)                                                \
            free((vec).data);                                                  \
        (vec).data = NULL;                                                     \
    }

#define VEC_CLEAR(vec)                                                         \
    {                                                                          \
        for (int i = 0; i < (vec).len; i++) {                                  \
            tag_free(&(vec).data[i]);                                          \
        }                                                                      \
        (vec).len = 0;                                                         \
    }

#define STRING_RESIZE(vec, _cap)                                               \
    void *tmp = realloc((vec).data, ((_cap) + 1) * sizeof((vec).data[0]));     \
    assert(tmp != NULL);                                                       \
    (vec).data = tmp;                                                          \
    memset((vec).data + (vec).len, 0,                                          \
           (((_cap) + 1) - (vec).len) * sizeof((vec).data[0]));                \
    (vec).cap = (_cap);

#define STRING_GROW(vec, _cap)                                                 \
    if ((vec).cap < (_cap)) {                                                  \
        STRING_RESIZE((vec), (_cap));                                          \
    }

#define STRING_PUSH(vec, el)                                                   \
    if ((vec).cap == (vec).len) {                                              \
        STRING_RESIZE((vec), MAX(16, (vec).len * 2));                          \
    }                                                                          \
    (vec).data[(vec).len++] = (el);

#define STRING_INIT(vec)                                                       \
    {                                                                          \
        (vec).data = calloc(1, sizeof(char) * 17);                             \
        (vec).len = 0;                                                         \
        (vec).cap = 16;                                                        \
    }

#define STRING_FREE(vec)                                                       \
    {                                                                          \
        if ((vec).data != NULL)                                                \
            free((vec).data);                                                  \
        (vec).data = NULL;                                                     \
    }

#define STRING_CLEAR(vec)                                                      \
    {                                                                          \
        (vec).len = 0;                                                         \
        memset((vec).data, 0, (vec).cap * sizeof(char));                       \
    }

static void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static unsigned serialize(Scanner *scanner, char *buffer) {
    uint16_t tag_count =
        scanner->tags.len > UINT16_MAX ? UINT16_MAX : scanner->tags.len;
    uint16_t serialized_tag_count = 0;

    unsigned size = sizeof(tag_count);
    memcpy(&buffer[size], &tag_count, sizeof(tag_count));
    size += sizeof(tag_count);

    for (; serialized_tag_count < tag_count; serialized_tag_count++) {
        Tag tag = scanner->tags.data[serialized_tag_count];
        if (tag.type == CUSTOM) {
            unsigned name_length = tag.custom_tag_name.len;
            if (name_length > UINT8_MAX) {
                name_length = UINT8_MAX;
            }
            if (size + 2 + name_length >=
                TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
                break;
            }
            buffer[size++] = (char)tag.type;
            buffer[size++] = (char)name_length;
            strncpy(&buffer[size], tag.custom_tag_name.data, name_length);
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
    VEC_CLEAR(scanner->tags);
    if (length > 0) {
        unsigned size = 0;
        uint16_t tag_count = 0;
        uint16_t serialized_tag_count = 0;

        memcpy(&serialized_tag_count, &buffer[size],
               sizeof(serialized_tag_count));
        size += sizeof(serialized_tag_count);

        memcpy(&tag_count, &buffer[size], sizeof(tag_count));
        size += sizeof(tag_count);

        VEC_RESIZE(scanner->tags, tag_count);
        if (tag_count > 0) {
            unsigned iter = 0;
            for (iter = 0; iter < serialized_tag_count; iter++) {
                Tag tag = scanner->tags.data[iter];
                tag.type = (TagType)buffer[size++];
                if (tag.type == CUSTOM) {
                    uint16_t name_length = (uint8_t)buffer[size++];
                    tag.custom_tag_name.len = name_length;
                    tag.custom_tag_name.cap = name_length;
                    tag.custom_tag_name.data =
                        (char *)calloc(1, sizeof(char) * (name_length + 1));
                    strncpy(tag.custom_tag_name.data, &buffer[size],
                            name_length);
                    size += name_length;
                }
                VEC_PUSH(scanner->tags, tag);
            }
            // add zero tags if we didn't read enough, this is because the
            // buffer had no more room but we held more tags.
            for (; iter < tag_count; iter++) {
                Tag tag = new_tag();
                VEC_PUSH(scanner->tags, tag);
            }
        }
    }
}

static String scan_tag_name(TSLexer *lexer) {
    String tag_name;
    STRING_INIT(tag_name);
    while (iswalnum(lexer->lookahead) || lexer->lookahead == '-' ||
           lexer->lookahead == ':') {
        STRING_PUSH(tag_name, towupper(lexer->lookahead));
        lexer->advance(lexer, false);
    }
    return tag_name;
}


static bool scan_comment(TSLexer *lexer) {
    
    if (lexer->lookahead != '-') {
        return false;
    }
    lexer->advance(lexer, false);
    if (lexer->lookahead != '-') {
        return false;
    }
    
    lexer->advance(lexer, false);

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
                    lexer->result_symbol = COMMENT;
                    lexer->advance(lexer, false);
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
        lexer->advance(lexer, false);
    }
    return false;
}

static bool scan_whitespace_and_comments(TSLexer *lexer, bool *scanned_comment) {
    for (;;) {
        while (iswspace(lexer->lookahead)) {
            skip(lexer);
        }

        if (lexer->lookahead == '/') {
            skip(lexer);

            if (lexer->lookahead == '/') {
                skip(lexer);
                while (lexer->lookahead != 0 && lexer->lookahead != '\n' && lexer->lookahead != 0x2028 &&
                       lexer->lookahead != 0x2029) {
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
                            break;
                        }
                    } else {
                        skip(lexer);
                    }
                }
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}

static bool scan_script_comment(TSLexer *lexer) {
    
    for (;;) {

        if (lexer->lookahead == '/') {
            lexer->advance(lexer, true);
            while (lexer->lookahead != 0 && lexer->lookahead != '\n' && lexer->lookahead != 0x2028 &&
                    lexer->lookahead != 0x2029) {
                lexer->advance(lexer, true);
            }
            //*scanned_comment = true;
        } else if (lexer->lookahead == '*') {
            lexer->advance(lexer, true);
            while (lexer->lookahead != 0) {
                if (lexer->lookahead == '*') {
                    lexer->advance(lexer, true);
                    if (lexer->lookahead == '/') {
                        lexer->advance(lexer, true);
                        //*scanned_comment = true;
                        break;
                    }
                } else {
                    lexer->advance(lexer, true);
                }
            }
        } else {
            return false;
        }
    }
}

static bool scan_raw_text(Scanner *scanner, TSLexer *lexer) {
    if (scanner->tags.len == 0) {
        return false;
    }

    lexer->mark_end(lexer);

    const char *end_delimiter =
        VEC_BACK(scanner->tags).type == SCRIPT ? "</SCRIPT" : "</STYLE";

    unsigned delimiter_index = 0;
    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == strlen(end_delimiter)) {
                break;
            }
            lexer->advance(lexer, false);
        } else {
            delimiter_index = 0;
            lexer->advance(lexer, false);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = RAW_TEXT;
    return true;
}

static bool scan_implicit_end_tag(Scanner *scanner, TSLexer *lexer) {
    Tag *parent = scanner->tags.len == 0 ? NULL : &VEC_BACK(scanner->tags);

    bool is_closing_tag = false;
    if (lexer->lookahead == '/') {
        is_closing_tag = true;
        lexer->advance(lexer, false);
    } else {
        if (parent && is_void(parent)) {
            VEC_POP(scanner->tags);
            lexer->result_symbol = IMPLICIT_END_TAG;
            return true;
        }
    }

    String tag_name = scan_tag_name(lexer);
    if (tag_name.len == 0) {
        STRING_FREE(tag_name);
        return false;
    }

    Tag next_tag = for_name(tag_name.data);

    if (is_closing_tag) {
        // The tag correctly closes the topmost element on the stack
        if (scanner->tags.len > 0 &&
            tagcmp(&VEC_BACK(scanner->tags), &next_tag)) {
            STRING_FREE(tag_name);
            tag_free(&next_tag);
            return false;
        }

        // Otherwise, dig deeper and queue implicit end tags (to be nice in
        // the case of malformed HTML)
        for (unsigned i = scanner->tags.len; i > 0; i--) {
            if (scanner->tags.data[i - 1].type == next_tag.type) {
                VEC_POP(scanner->tags);
                lexer->result_symbol = IMPLICIT_END_TAG;
                STRING_FREE(tag_name);
                tag_free(&next_tag);
                return true;
            }
        }
    } else if (parent && !can_contain(parent, &next_tag)) {
        VEC_POP(scanner->tags);
        lexer->result_symbol = IMPLICIT_END_TAG;
        STRING_FREE(tag_name);
        tag_free(&next_tag);
        return true;
    }

    STRING_FREE(tag_name);
    tag_free(&next_tag);
    return false;
}

static bool scan_start_tag_name(Scanner *scanner, TSLexer *lexer) {
    String tag_name = scan_tag_name(lexer);
    if (tag_name.len == 0) {
        STRING_FREE(tag_name);
        return false;
    }
    Tag tag = for_name(tag_name.data);
    VEC_PUSH(scanner->tags, tag);
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
    STRING_FREE(tag_name);
    return true;
}

static bool scan_end_tag_name(Scanner *scanner, TSLexer *lexer) {
    String tag_name = scan_tag_name(lexer);
    if (tag_name.len == 0) {
        STRING_FREE(tag_name);
        return false;
    }
    Tag tag = for_name(tag_name.data);
    if (scanner->tags.len > 0 && tagcmp(&VEC_BACK(scanner->tags), &tag)) {
        VEC_POP(scanner->tags);
        lexer->result_symbol = END_TAG_NAME;
    } else {
        lexer->result_symbol = ERRONEOUS_END_TAG_NAME;
    }
    tag_free(&tag);
    STRING_FREE(tag_name);
    return true;
}

static bool scan_self_closing_tag_delimiter(Scanner *scanner, TSLexer *lexer) {
    lexer->advance(lexer, false);
    if (scanner->tags.len > 0) {
        VEC_POP(scanner->tags);
        lexer->result_symbol = SELF_CLOSING_TAG_DELIMITER;
    } else {
        lexer->result_symbol = SELF_CLOSING_TAG_DELIMITER;   
    }
    return true;
}

static bool scan_automatic_semicolon(TSLexer *lexer, bool comment_condition, bool *scanned_comment) {
    lexer->result_symbol = AUTOMATIC_SEMICOLON;
    lexer->mark_end(lexer);

    for (;;) {
        if (lexer->lookahead == 0) {
            return true;
        }

        if (lexer->lookahead == '/') {
            if (!scan_whitespace_and_comments(lexer, scanned_comment)) {
                return false;
            }
            if (comment_condition && lexer->lookahead != ',' && lexer->lookahead != '=') {
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

    if (!scan_whitespace_and_comments(lexer, scanned_comment)) {
        return false;
    }

    switch (lexer->lookahead) {
        case ',':
        case '.':
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

static bool scan(Scanner *scanner, TSLexer *lexer, const bool *valid_symbols) {
    
    while (iswspace(lexer->lookahead)) {
        lexer->advance(lexer, true);
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

    
    if (valid_symbols[RAW_TEXT] && !valid_symbols[START_TAG_NAME] &&
        !valid_symbols[END_TAG_NAME]) {
        return scan_raw_text(scanner, lexer);
    }

    switch (lexer->lookahead) {
        case ';':
            return false;
        break;
        case '<':
            lexer->mark_end(lexer);
            lexer->advance(lexer, false);

            if (lexer->lookahead == '!') {
                lexer->advance(lexer, false);
                return scan_comment(lexer);
            }

            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer);
            }
            break;

        case '\0':
            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer);
            }
            break;

        case '/':
            if (lexer->lookahead == '/') {
                lexer->advance(lexer, false);
                if (lexer->lookahead == '>') {
                    if (valid_symbols[SELF_CLOSING_TAG_DELIMITER]) {
                        return scan_self_closing_tag_delimiter(scanner, lexer);
                    }  
                } else if ( lexer->lookahead == '/' || lexer->lookahead == '*' ) {
                   if ( !scan_script_comment(lexer) ) {
                        return false; 
                   }
                }
            }
            
            break;

        default:
            if ((valid_symbols[START_TAG_NAME] ||
                 valid_symbols[END_TAG_NAME]) &&
                !valid_symbols[RAW_TEXT]) {
                return valid_symbols[START_TAG_NAME]
                           ? scan_start_tag_name(scanner, lexer)
                           : scan_end_tag_name(scanner, lexer);
            }
    }

    return false;
}

void *tree_sitter_cfml_external_scanner_create() {
    Scanner *scanner = (Scanner *)calloc(1, sizeof(Scanner));
    return scanner;
}

bool tree_sitter_cfml_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;
    return scan(scanner, lexer, valid_symbols);
}

unsigned tree_sitter_cfml_external_scanner_serialize(void *payload,
                                                     char *buffer) {
    Scanner *scanner = (Scanner *)payload;
    return serialize(scanner, buffer);
}

void tree_sitter_cfml_external_scanner_deserialize(void *payload,
                                                   const char *buffer,
                                                   unsigned length) {
    Scanner *scanner = (Scanner *)payload;
    deserialize(scanner, buffer, length);
}

void tree_sitter_cfml_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    for (unsigned i = 0; i < scanner->tags.len; i++) {
        STRING_FREE(scanner->tags.data[i].custom_tag_name);
    }
    VEC_FREE(scanner->tags);
    free(scanner);
}
