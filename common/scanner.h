#include "tag.h"
#include "tree_sitter/parser.h"

#include <stdint.h>
#include <string.h>
#include <wctype.h>

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
    CF_SELF_CLOSING_TAG_DELIMITER,
    CF_SELF_CLOSING_VOID_TAG_DELIMITER,
    IMPLICIT_END_TAG,
    IMPLICIT_CF_END_TAG,
    RAW_TEXT,
    CFML_COMMENT,
    CLOSE_TAG_DELIM,
    CLOSE_CF_TAG_DELIM,
    HTML_TEXT,
    CF_VOID_START_TAG_NAME,
    CF_SET_START_TAG_NAME,
    CF_RETURN_START_TAG_NAME,
    CF_IF_START_TAG_NAME,
    CF_IF_END_TAG_NAME,
    CF_ELSEIF_TAG_NAME,
    CF_ELSE_TAG_NAME,
    
    CF_XML_START_TAG_NAME,
    CF_XML_END_TAG_NAME,
    CF_XML_CONTENT,

    CF_QUERY_START_TAG_NAME,
    CF_QUERY_END_TAG_NAME,
    CF_QUERY_CONTENT,

    CF_SCRIPT_START_TAG_NAME,
    CF_SCRIPT_END_TAG_NAME,
    CF_SCRIPT_CONTENT,

    CF_SAVECONTENT_START_TAG_NAME,
    CF_SAVECONTENT_END_TAG_NAME,
    CF_SAVECONTENT_CONTENT,

    CF_OUTPUT_START_TAG_NAME,

    CF_COMPONENT_CONTENT,

    START_HASH_EXPRESSION,
    SINGLE_HASH,
    HASH_EMPTY
};

typedef struct {
    Array(Tag) tags;
    Array(Tag) cf_tags;
    uint16_t cfoutput_depth;
    uint16_t cfcomponent_depth;
    uint16_t cffunction_depth;
} Scanner;

typedef enum {
    REJECT,     // Semicolon is illegal, ie a syntax error occurred
    NO_NEWLINE, // Unclear if semicolon will be legal, continue
    ACCEPT,     // Semicolon is legal, assuming a comment was encountered
} WhitespaceResult;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAX_CF_END_DELIMITER_SIZE 256

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static inline bool tag_has_name(TagType type) {
    return type == CUSTOM || type == CFML || type == CF_VOID || type == CF_SET ||
           type == CF_XML || type == CF_SCRIPT || type == CF_SAVECONTENT ||
           type == CF_QUERY || type == CF_OUTPUT || type == CF_RETURN ||
           type == CF_IF || type == CF_ELSEIF || type == CF_ELSE;
}

static inline bool valid_start_tag_name(const bool *vs) {
    return vs[START_TAG_NAME] || vs[CF_START_TAG_NAME] || vs[CF_SET_START_TAG_NAME] ||
           vs[CF_VOID_START_TAG_NAME] || vs[CF_RETURN_START_TAG_NAME] ||
           vs[CF_XML_START_TAG_NAME] || vs[CF_QUERY_START_TAG_NAME] ||
           vs[CF_SCRIPT_START_TAG_NAME] || vs[CF_SAVECONTENT_START_TAG_NAME] ||
           vs[CF_OUTPUT_START_TAG_NAME] || vs[CF_IF_START_TAG_NAME] ||
           vs[CF_ELSEIF_TAG_NAME] || vs[CF_ELSE_TAG_NAME];
}

static inline bool valid_end_tag_name(const bool *vs) {
    return vs[END_TAG_NAME] || vs[CF_END_TAG_NAME] || vs[CF_XML_END_TAG_NAME] ||
           vs[CF_QUERY_END_TAG_NAME] || vs[CF_SCRIPT_END_TAG_NAME] ||
           vs[CF_SAVECONTENT_END_TAG_NAME] || vs[CF_IF_END_TAG_NAME];
}

static inline bool valid_cf_start_tag_name(const bool *vs) {
    return vs[CF_START_TAG_NAME] || vs[CF_SET_START_TAG_NAME] ||
           vs[CF_VOID_START_TAG_NAME] || vs[CF_RETURN_START_TAG_NAME] ||
           vs[CF_XML_START_TAG_NAME] || vs[CF_QUERY_START_TAG_NAME] ||
           vs[CF_SCRIPT_START_TAG_NAME] || vs[CF_SAVECONTENT_START_TAG_NAME] ||
           vs[CF_OUTPUT_START_TAG_NAME] || vs[CF_IF_START_TAG_NAME] ||
           vs[CF_ELSEIF_TAG_NAME] || vs[CF_ELSE_TAG_NAME];
}

static inline bool valid_cf_end_tag_name(const bool *vs) {
    return vs[CF_END_TAG_NAME] || vs[CF_XML_END_TAG_NAME] ||
           vs[CF_QUERY_END_TAG_NAME] || vs[CF_SCRIPT_END_TAG_NAME] ||
           vs[CF_SAVECONTENT_END_TAG_NAME] || vs[CF_IF_END_TAG_NAME];
}

static inline bool no_content_symbols(const bool *vs) {
    return !vs[RAW_TEXT] && !vs[CF_XML_CONTENT] && !vs[CF_QUERY_CONTENT]
        && !vs[CF_SCRIPT_CONTENT] && !vs[CF_SAVECONTENT_CONTENT];
}

static inline bool implicit_cf_end_tag_valid(const bool *vs) {
    return vs[IMPLICIT_CF_END_TAG] && !vs[CF_XML_END_TAG_NAME] &&
           !vs[CF_QUERY_END_TAG_NAME] && !vs[CF_SCRIPT_END_TAG_NAME] &&
           !vs[CF_SAVECONTENT_END_TAG_NAME] && !vs[CF_IF_END_TAG_NAME] &&
           !vs[CF_ELSEIF_TAG_NAME] && !vs[CF_ELSE_TAG_NAME];
}

#define SERIALIZE_TAGS(tags_field, buffer, size) do { \
    uint16_t _count = (tags_field).size > UINT16_MAX ? UINT16_MAX : (tags_field).size; \
    uint16_t _serialized = 0; \
    unsigned _count_offset = (size); \
    (size) += sizeof(_count); \
    (size) += sizeof(_count); \
    for (; _serialized < _count; _serialized++) { \
        Tag _tag = (tags_field).contents[_serialized]; \
        if (tag_has_name(_tag.type)) { \
            unsigned _len = _tag.tag_name.size; \
            if (_len > UINT8_MAX) _len = UINT8_MAX; \
            if ((size) + 2 + _len + sizeof(_tag.html_depth) >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) break; \
            (buffer)[(size)++] = (char)_tag.type; \
            (buffer)[(size)++] = (char)_len; \
            strncpy(&(buffer)[(size)], _tag.tag_name.contents, _len); \
            (size) += _len; \
            memcpy(&(buffer)[(size)], &_tag.html_depth, sizeof(_tag.html_depth)); \
            (size) += sizeof(_tag.html_depth); \
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
    if (size + sizeof(scanner->cfoutput_depth) + sizeof(scanner->cfcomponent_depth) + sizeof(scanner->cffunction_depth) < TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
        memcpy(&buffer[size], &scanner->cfoutput_depth, sizeof(scanner->cfoutput_depth));
        size += sizeof(scanner->cfoutput_depth);
        memcpy(&buffer[size], &scanner->cfcomponent_depth, sizeof(scanner->cfcomponent_depth));
        size += sizeof(scanner->cfcomponent_depth);
        memcpy(&buffer[size], &scanner->cffunction_depth, sizeof(scanner->cffunction_depth));
        size += sizeof(scanner->cffunction_depth);
    }
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
        _tag.type = (TagType)(unsigned char)(buffer)[(size)++]; \
        if (tag_has_name(_tag.type)) { \
            uint16_t _len = (uint8_t)(buffer)[(size)++]; \
            array_reserve(&_tag.tag_name, _len); \
            _tag.tag_name.size = _len; \
            memcpy(_tag.tag_name.contents, &(buffer)[(size)], _len); \
            (size) += _len; \
            memcpy(&_tag.html_depth, &(buffer)[(size)], sizeof(_tag.html_depth)); \
            (size) += sizeof(_tag.html_depth); \
        } \
        array_push(&(tags_field), _tag); \
    } \
    for (; _iter < _count; _iter++) array_push(&(tags_field), tag_new()); \
} while(0)

static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
    scanner->cfoutput_depth = 0;
    scanner->cfcomponent_depth = 0;
    scanner->cffunction_depth = 0;
    if (length > 0) {
        unsigned size = 0;
        DESERIALIZE_TAGS(scanner->tags, buffer, size);
        DESERIALIZE_TAGS(scanner->cf_tags, buffer, size);
        if (size + sizeof(scanner->cfoutput_depth) <= length) {
            memcpy(&scanner->cfoutput_depth, &buffer[size], sizeof(scanner->cfoutput_depth));
            size += sizeof(scanner->cfoutput_depth);
        }
        if (size + sizeof(scanner->cfcomponent_depth) <= length) {
            memcpy(&scanner->cfcomponent_depth, &buffer[size], sizeof(scanner->cfcomponent_depth));
            size += sizeof(scanner->cfcomponent_depth);
        }
        if (size + sizeof(scanner->cffunction_depth) <= length) {
            memcpy(&scanner->cffunction_depth, &buffer[size], sizeof(scanner->cffunction_depth));
            size += sizeof(scanner->cffunction_depth);
        }
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

    // ColdFusion tags might start with 'C', ie. <cfcomponent or <cfcontinue
    if ( lexer->lookahead == 'c' || lexer->lookahead == 'C' ) {
        array_push(&tag_name, towupper(lexer->lookahead));
        advance(lexer);
        if (lexer->lookahead == 'f' || lexer->lookahead == 'F') {
            is_cf_tag = true;
            array_delete(&tag_name);
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

    bool saw_any = false;
    while (lexer->lookahead != 0 && lexer->lookahead != '<' && lexer->lookahead != '>' && lexer->lookahead != '{' &&
           lexer->lookahead != '}' && lexer->lookahead != '&' && lexer->lookahead != '#') {
        bool is_wspace = iswspace(lexer->lookahead);
        if (lexer->lookahead == '\n') {
            at_newline = true;
        } else {
            at_newline &= is_wspace;
            if (!at_newline) {
                saw_text = true;
            }
        }
        saw_any = true;
        advance(lexer);
    }

    lexer->result_symbol = HTML_TEXT;
    // Emit whitespace-only content when the next char is '#' so the parser
    // advances to a state where hash tokens become valid.
    return saw_text || (saw_any && lexer->lookahead == '#');
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

    if (scanner->cf_tags.size == 0) {
        return false;
    }

    Tag *cf_tag = array_back(&scanner->cf_tags);
    if (cf_tag->type != CF_QUERY) {
        return false;
    }
    
    lexer->mark_end(lexer);

    size_t tag_len = cf_tag->tag_name.size;
    if (tag_len > MAX_CF_END_DELIMITER_SIZE - 5) return false;

    char end_delimiter[MAX_CF_END_DELIMITER_SIZE];
    memcpy(end_delimiter, "</CF", 4);
    memcpy(&end_delimiter[4], cf_tag->tag_name.contents, tag_len);
    end_delimiter[4 + tag_len] = '\0';

    size_t delimiter_index = 0;
    size_t end_delim_len = 4 + tag_len;

    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == end_delim_len) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = CF_QUERY_CONTENT;
    return true;
}

static bool scan_cfxml_content(Scanner *scanner, TSLexer *lexer) {

    if (scanner->cf_tags.size == 0) {
        return false;
    }

    Tag *cf_tag = array_back(&scanner->cf_tags);
    if (cf_tag->type != CF_XML) {
        return false;
    }
    
    lexer->mark_end(lexer);

    size_t tag_len = cf_tag->tag_name.size;
    if (tag_len > MAX_CF_END_DELIMITER_SIZE - 5) return false;

    char end_delimiter[MAX_CF_END_DELIMITER_SIZE];
    memcpy(end_delimiter, "</CF", 4);
    memcpy(&end_delimiter[4], cf_tag->tag_name.contents, tag_len);
    end_delimiter[4 + tag_len] = '\0';

    size_t delimiter_index = 0;
    size_t end_delim_len = 4 + tag_len;

    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == end_delim_len) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = CF_XML_CONTENT;
    return true;
}


static bool scan_cfscript_content(Scanner *scanner, TSLexer *lexer) {

    if (scanner->cf_tags.size == 0) {
        return false;
    }

    Tag *cf_tag = array_back(&scanner->cf_tags);
    if (cf_tag->type != CF_SCRIPT) {
        return false;
    }
    
    lexer->mark_end(lexer);

    size_t tag_len = cf_tag->tag_name.size;
    if (tag_len > MAX_CF_END_DELIMITER_SIZE - 5) return false;

    char end_delimiter[MAX_CF_END_DELIMITER_SIZE];
    memcpy(end_delimiter, "</CF", 4);
    memcpy(&end_delimiter[4], cf_tag->tag_name.contents, tag_len);
    end_delimiter[4 + tag_len] = '\0';

    size_t delimiter_index = 0;
    size_t end_delim_len = 4 + tag_len;

    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == end_delim_len) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = CF_SCRIPT_CONTENT;
    return true;
}

static bool scan_cfsavecontent_content(Scanner *scanner, TSLexer *lexer) {

    if (scanner->cf_tags.size == 0) {
        return false;
    }

    Tag *cf_tag = array_back(&scanner->cf_tags);
    if (cf_tag->type != CF_SAVECONTENT) {
        return false;
    }
    
    lexer->mark_end(lexer);

    size_t tag_len = cf_tag->tag_name.size;
    if (tag_len > MAX_CF_END_DELIMITER_SIZE - 5) return false;

    char end_delimiter[MAX_CF_END_DELIMITER_SIZE];
    memcpy(end_delimiter, "</CF", 4);
    memcpy(&end_delimiter[4], cf_tag->tag_name.contents, tag_len);
    end_delimiter[4 + tag_len] = '\0';

    size_t delimiter_index = 0;
    size_t end_delim_len = 4 + tag_len;

    while (lexer->lookahead) {
        if (towupper(lexer->lookahead) == end_delimiter[delimiter_index]) {
            delimiter_index++;
            if (delimiter_index == end_delim_len) {
                break;
            }
            advance(lexer);
        } else {
            delimiter_index = 0;
            advance(lexer);
            lexer->mark_end(lexer);
        }
    }

    lexer->result_symbol = CF_SAVECONTENT_CONTENT;
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
    
    Tag *parent = is_cf_context
        ? (scanner->cf_tags.size == 0 ? NULL : array_back(&scanner->cf_tags))
        : (scanner->tags.size == 0 ? NULL : array_back(&scanner->tags));

    bool is_closing_tag = false;
    if (lexer->lookahead == '/') {
        is_closing_tag = true;
        lexer->mark_end(lexer);
        advance(lexer);
    } else {
        // Void tag processing
        if (!is_cf_context && parent && tag_is_void(parent)) {
            pop_tag(scanner, false);
            lexer->result_symbol = IMPLICIT_END_TAG;
            return true;
        }
        // Void tag processing
        if (is_cf_context && parent && cf_tag_is_void(parent)) {
            pop_tag(scanner, true);
            lexer->result_symbol = IMPLICIT_CF_END_TAG;
            return true;
        }
    }

    TagNameResult result = scan_tag_name(lexer);
    if (result.tag_name.size == 0 && !lexer->eof(lexer)) {
        array_delete(&result.tag_name);
        return false;
    }

    if (result.is_cf_tag && !is_cf_context && is_closing_tag) {
        // A CF closing tag in HTML context: only implicitly close HTML tags
        // that were opened inside this CF tag (i.e. tags.size > cf html_depth)
        Tag cf_next = cf_tag_for_name(result.tag_name);
        unsigned cf_html_depth = 0;
        bool found = false;
        for (unsigned i = scanner->cf_tags.size; i > 0; i--) {
            if (tag_eq(&scanner->cf_tags.contents[i - 1], &cf_next)) {
                cf_html_depth = scanner->cf_tags.contents[i - 1].html_depth;
                found = true;
                break;
            }
        }
        tag_free(&cf_next);
        if (found && scanner->tags.size > cf_html_depth) {
            pop_tag(scanner, false);
            lexer->result_symbol = IMPLICIT_END_TAG;
            return true;
        }
        return false;
    }

    if (result.is_cf_tag && !is_cf_context) {
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

    Tag next_tag = is_cf_context ? cf_tag_for_name(result.tag_name) : tag_for_name(result.tag_name); 

    if (is_closing_tag) {
        // The tag correctly closes the topmost element on the stack
        if (is_cf_context ? (scanner->cf_tags.size > 0 && tag_eq(array_back(&scanner->cf_tags), &next_tag))
                          : (scanner->tags.size > 0 && tag_eq(array_back(&scanner->tags), &next_tag))) {
            tag_free(&next_tag);
            return false;
        }

        // if (is_cf ? (scanner->cf_tags.size > 0 && !tag_eq(array_back(&scanner->cf_tags), &next_tag))
        //                   : (scanner->tags.size > 0 && !tag_eq(array_back(&scanner->tags), &next_tag))) {
        //     pop_tag(scanner, is_cf);
        //     lexer->result_symbol = is_cf ? IMPLICIT_CF_END_TAG : IMPLICIT_END_TAG;
        //     tag_free(&next_tag);
        //     return true;
        // }

        // Otherwise, dig deeper and queue implicit end tags (to be nice in
        // the case of malformed HTML)
        if (is_cf_context) {
            for (unsigned i = scanner->cf_tags.size; i > 0; i--) {
                if (tag_eq(&scanner->cf_tags.contents[i - 1], &next_tag)) {
                    pop_tag(scanner, true);
                    lexer->result_symbol = IMPLICIT_CF_END_TAG;
                    tag_free(&next_tag);
                    return true;
                }
            }
        } else {
            for (unsigned i = scanner->tags.size; i > 0; i--) {
                if (tag_eq(&scanner->tags.contents[i - 1], &next_tag)) {
                    pop_tag(scanner, false);
                    lexer->result_symbol = IMPLICIT_END_TAG;
                    tag_free(&next_tag);
                    return true;
                }
            }
        }
    } else {

        if (is_cf_context && parent && tag_eq(parent, &next_tag)) {
            pop_tag(scanner, true);
            lexer->result_symbol = IMPLICIT_CF_END_TAG;
            tag_free(&next_tag);
            return true;
        }

        if (!is_cf_context && parent && tag_eq(parent, &next_tag)) {
            pop_tag(scanner, false);
            lexer->result_symbol = IMPLICIT_END_TAG;
            tag_free(&next_tag);
            return true;
        }

        if (
            parent &&
            (
                ((parent->type == HTML || parent->type == HEAD || parent->type == BODY) && lexer->eof(lexer))
                || (is_cf_context && lexer->eof(lexer))
            )
        ) {
            pop_tag(scanner, is_cf_context);
            lexer->result_symbol = is_cf_context ? IMPLICIT_CF_END_TAG : IMPLICIT_END_TAG;
            tag_free(&next_tag);
            return true;
        }
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

    if ( result.is_cf_tag && !is_cf_context ) {
        array_delete(&result.tag_name);
        return false;
    }
    
    // bool is_cf = result.is_cf_tag || is_cf_context;
    Tag tag = is_cf_context ? cf_tag_for_name(result.tag_name) : tag_for_name(result.tag_name);

    // printf("scan_start_tag_name: tag=%.*s, is_cf_tag=%d, is_cf_context=%d, type=%d\n",
    // (int)result.tag_name.size, result.tag_name.contents, result.is_cf_tag, is_cf_context, tag.type);

    switch (tag.type) {
        case SCRIPT:
            lexer->result_symbol = SCRIPT_START_TAG_NAME;
            break;
        case STYLE:
            lexer->result_symbol = STYLE_START_TAG_NAME;
            break;
        case CF_VOID:
            lexer->result_symbol = CF_VOID_START_TAG_NAME;
            return true;
        case CF_SET:
            lexer->result_symbol = CF_SET_START_TAG_NAME;
            return true;
        case CF_RETURN:
            lexer->result_symbol = CF_RETURN_START_TAG_NAME;
            return true;
        case CF_IF:
            lexer->result_symbol = CF_IF_START_TAG_NAME;
            break;
        case CF_ELSEIF:
            lexer->result_symbol = CF_ELSEIF_TAG_NAME;
            return true;
        case CF_ELSE:
            lexer->result_symbol = CF_ELSE_TAG_NAME;
            return true;
        case CF_XML:
            lexer->result_symbol = CF_XML_START_TAG_NAME;
            break;
        case CF_QUERY:
            lexer->result_symbol = CF_QUERY_START_TAG_NAME;
            break;
        case CF_SCRIPT:
            lexer->result_symbol = CF_SCRIPT_START_TAG_NAME;
            break;
         case CF_SAVECONTENT:
            lexer->result_symbol = CF_SAVECONTENT_START_TAG_NAME;
            break;
        case CF_OUTPUT:
            lexer->result_symbol = CF_OUTPUT_START_TAG_NAME;
            if (is_cf_context) {
                scanner->cfoutput_depth++;
            }
            break;
        default:
            lexer->result_symbol = is_cf_context ? CF_START_TAG_NAME : START_TAG_NAME;
            if (is_cf_context && tag.type == CFML) {
                if (tag.tag_name.size == 9 &&
                    memcmp(tag.tag_name.contents, "COMPONENT", 9) == 0) {
                    scanner->cfcomponent_depth++;
                } else if (tag.tag_name.size == 8 &&
                    memcmp(tag.tag_name.contents, "FUNCTION", 8) == 0) {
                    scanner->cffunction_depth++;
                }
            }
            break;
    }

    if ( is_cf_context ) {
        tag.html_depth = scanner->tags.size;
        array_push(&scanner->cf_tags, tag);
    } else {
        array_push(&scanner->tags, tag);
    }
    
    return true;
}

static void set_end_tag_symbol(Scanner *scanner, TSLexer *lexer, Tag *tag, bool is_cf_context) {
    if (is_cf_context && tag->type == CF_OUTPUT) {
        if (scanner->cfoutput_depth > 0) scanner->cfoutput_depth--;
        lexer->result_symbol = CF_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CFML &&
               tag->tag_name.size == 9 &&
               memcmp(tag->tag_name.contents, "COMPONENT", 9) == 0) {
        if (scanner->cfcomponent_depth > 0) scanner->cfcomponent_depth--;
        lexer->result_symbol = CF_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CFML &&
               tag->tag_name.size == 8 &&
               memcmp(tag->tag_name.contents, "FUNCTION", 8) == 0) {
        if (scanner->cffunction_depth > 0) scanner->cffunction_depth--;
        lexer->result_symbol = CF_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CF_XML) {
        lexer->result_symbol = CF_XML_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CF_QUERY) {
        lexer->result_symbol = CF_QUERY_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CF_SCRIPT) {
        lexer->result_symbol = CF_SCRIPT_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CF_SAVECONTENT) {
        lexer->result_symbol = CF_SAVECONTENT_END_TAG_NAME;
    } else if (is_cf_context && tag->type == CF_IF) {
        lexer->result_symbol = CF_IF_END_TAG_NAME;
    } else {
        lexer->result_symbol = is_cf_context ? CF_END_TAG_NAME : END_TAG_NAME;
    }
}

static bool scan_end_tag_name(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {
    
    TagNameResult result = scan_tag_name(lexer);

    if (result.tag_name.size == 0) {
        array_delete(&result.tag_name);
        return false;
    }

    if ( result.is_cf_tag && !is_cf_context ) {
        array_delete(&result.tag_name);
        return false;
    }

    // printf("scan_end_tag_name: tag=%.*s, is_cf_context=%d, tags.size=%d, cf_tags.size=%d\n",
    // (int)result.tag_name.size, result.tag_name.contents, is_cf_context,
    // scanner->tags.size, scanner->cf_tags.size);
    
    // bool is_cf = result.is_cf_tag || is_cf_context;
    
    Tag tag = is_cf_context ? cf_tag_for_name(result.tag_name) : tag_for_name(result.tag_name);

    Tag *tag_back = (is_cf_context) ? ( scanner->cf_tags.size > 0 ? array_back(&scanner->cf_tags) : NULL )
                   : ( scanner->tags.size > 0) ? array_back(&scanner->tags) : NULL;

    if ( tag_back && tag_eq(tag_back, &tag) ) {
        pop_tag(scanner, is_cf_context);
        set_end_tag_symbol(scanner, lexer, &tag, is_cf_context);
    } else {
        // Search deeper in the stack for a matching tag
        bool found = false;
        if (is_cf_context) {
            for (unsigned i = scanner->cf_tags.size; i > 0; i--) {
                if (tag_eq(&scanner->cf_tags.contents[i - 1], &tag)) {
                    found = true;
                    break;
                }
            }
        } else {
            for (unsigned i = scanner->tags.size; i > 0; i--) {
                if (tag_eq(&scanner->tags.contents[i - 1], &tag)) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            pop_tag(scanner, is_cf_context);
            set_end_tag_symbol(scanner, lexer, &tag, is_cf_context);
        } else {
            lexer->result_symbol = is_cf_context ? ERRONEOUS_CF_END_TAG_NAME : ERRONEOUS_END_TAG_NAME;
        }
    }

    tag_free(&tag);
    return true;
}

static bool scan_cf_self_closing_tag_delimiter(Scanner *scanner, TSLexer *lexer, bool is_void) {
     if (lexer->lookahead == '>') {
        advance(lexer);
        if (is_void) {
            lexer->result_symbol = CF_SELF_CLOSING_VOID_TAG_DELIMITER;
        } else {
            lexer->result_symbol = CF_SELF_CLOSING_TAG_DELIMITER;
            if (scanner->cf_tags.size > 0) {
                pop_tag(scanner, true);
            }

        }
        return true;
    }
    return false;
}

static bool scan_self_closing_tag_delimiter(Scanner *scanner, TSLexer *lexer) {
     if (lexer->lookahead == '>') {
        advance(lexer);
        if (scanner->tags.size > 0) {
            pop_tag(scanner, false);
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

static bool scan_closetag_delim(Scanner *scanner, TSLexer *lexer, bool is_cf_context) {
    if ( lexer->lookahead == '>' ) {
        advance(lexer);
        lexer->mark_end(lexer);
        lexer->result_symbol = is_cf_context ? CLOSE_CF_TAG_DELIM : CLOSE_TAG_DELIM;
        return true;
    } else {
        return false;
    }
}

static bool scanner_in_hash_eval_context(Scanner *scanner) {
    return scanner->cfoutput_depth > 0 || scanner->cfcomponent_depth > 0 || scanner->cffunction_depth > 0;
}

static bool scan_cf_component_content(TSLexer *lexer) {
    // Skip whitespace and script-style comments (// and /* */)
    for (;;) {
        while (iswspace(lexer->lookahead)) advance(lexer);
        if (lexer->lookahead == '/') {
            advance(lexer);
            if (lexer->lookahead == '/') {
                advance(lexer);
                while (lexer->lookahead != 0 && lexer->lookahead != '\n') advance(lexer);
            } else if (lexer->lookahead == '*') {
                advance(lexer);
                while (lexer->lookahead != 0) {
                    if (lexer->lookahead == '*') { advance(lexer); if (lexer->lookahead == '/') { advance(lexer); break; } }
                    else advance(lexer);
                }
            } else {
                return false;
            }
        } else {
            break;
        }
    }

    // Read the first word
    char word[16];
    int len = 0;
    while (iswalpha(lexer->lookahead) && len < 15) {
        word[len++] = towlower(lexer->lookahead);
        advance(lexer);
    }
    word[len] = '\0';

    // Must not be followed by another identifier char (e.g. 'componentFoo')
    if (iswalnum(lexer->lookahead) || lexer->lookahead == '_') return false;

    if (strcmp(word, "component") != 0 && strcmp(word, "property") != 0 &&
            strcmp(word, "interface") != 0 && strcmp(word, "import") != 0) {
        return false;
    }

    // Consume the rest of the file
    while (lexer->lookahead != 0) advance(lexer);
    lexer->mark_end(lexer);
    lexer->result_symbol = CF_COMPONENT_CONTENT;
    return true;
}

static bool external_scanner_scan(Scanner *scanner, TSLexer *lexer, const bool *valid_symbols) {

    if (!valid_symbols[HTML_TEXT]) {
        while (iswspace(lexer->lookahead)) {
            skip(lexer);
        }
    }

    if ((valid_symbols[START_HASH_EXPRESSION] || valid_symbols[SINGLE_HASH] || valid_symbols[HASH_EMPTY])
            && !valid_symbols[AUTOMATIC_SEMICOLON] && lexer->lookahead == '#') {
        if (lexer->lookahead != '#') return false;
        advance(lexer);
        if (lexer->lookahead == '#') {
            advance(lexer);
            lexer->mark_end(lexer);
            lexer->result_symbol = HASH_EMPTY;
        } else if (scanner_in_hash_eval_context(scanner)) {
            // lexer->mark_end(lexer);
            lexer->result_symbol = START_HASH_EXPRESSION;
        } else {
            lexer->mark_end(lexer);
            lexer->result_symbol = SINGLE_HASH;
        }
        return true;
    }

    // bool scanned_cfoutput = false;
    if (valid_symbols[CF_COMPONENT_CONTENT]
            && scanner->tags.size == 0 && scanner->cf_tags.size == 0
            && scan_cf_component_content(lexer)) {
        return true;
    }

    if (valid_symbols[RAW_TEXT] && !valid_symbols[START_TAG_NAME] && !valid_symbols[END_TAG_NAME]) {
        return scan_raw_text(scanner, lexer);
    }

    if (valid_symbols[CF_XML_CONTENT]) {
        return scan_cfxml_content(scanner, lexer);
    }

    if (valid_symbols[CF_QUERY_CONTENT]) {
        return scan_cfquery_content(scanner, lexer);
    }

    if (valid_symbols[CF_SCRIPT_CONTENT]) {
        return scan_cfscript_content(scanner, lexer);
    }

    if (valid_symbols[CF_SAVECONTENT_CONTENT]) {
        return scan_cfsavecontent_content(scanner, lexer);
    }

    if (valid_symbols[HTML_TEXT] && scan_html_text(lexer)) {
        return true;
    }

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

            if (implicit_cf_end_tag_valid(valid_symbols)) {
                return scan_implicit_end_tag(scanner, lexer, true);
            }

            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, false);
            }

            break;

        case '\0':

            if (implicit_cf_end_tag_valid(valid_symbols)) {
                return scan_implicit_end_tag(scanner, lexer, true);
            }

            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, false);
            }
            break;

        case '/':
        
            advance(lexer);
            if (lexer->lookahead == '>') {
                if (valid_symbols[CF_SELF_CLOSING_TAG_DELIMITER]) {
                    return scan_cf_self_closing_tag_delimiter(scanner, lexer, false);
                }
                if (valid_symbols[CF_SELF_CLOSING_VOID_TAG_DELIMITER]) {
                    return scan_cf_self_closing_tag_delimiter(scanner, lexer, true);
                }
                if (valid_symbols[SELF_CLOSING_TAG_DELIMITER]) {
                    return scan_self_closing_tag_delimiter(scanner, lexer);
                }
                if (valid_symbols[CLOSE_CF_TAG_DELIM] ) {
                    return scan_closetag_delim(scanner, lexer, true);
                }
                if (valid_symbols[CLOSE_TAG_DELIM] ) {
                    return scan_closetag_delim(scanner, lexer, false);
                }
            } else if ( lexer->lookahead == '/' || lexer->lookahead == '*' ) {
                if ( !scan_script_comment(lexer) ) {
                    return false;
                }
            }

            break;

        default:
            if (valid_start_tag_name(valid_symbols) && no_content_symbols(valid_symbols)) {
                return scan_start_tag_name(scanner, lexer, valid_cf_start_tag_name(valid_symbols));
            }
            if (valid_end_tag_name(valid_symbols) && no_content_symbols(valid_symbols)) {
                return scan_end_tag_name(scanner, lexer, valid_cf_end_tag_name(valid_symbols));
            }

            if (valid_symbols[IMPLICIT_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, false);
            } else if (valid_symbols[IMPLICIT_CF_END_TAG]) {
                return scan_implicit_end_tag(scanner, lexer, true);
            }

            if (valid_symbols[ERRONEOUS_END_TAG_NAME]) {
                return scan_end_tag_name(scanner, lexer, false);
            } else if (valid_symbols[ERRONEOUS_CF_END_TAG_NAME]) {
                return scan_end_tag_name(scanner, lexer, true);
            }


            if (valid_symbols[CLOSE_CF_TAG_DELIM] ) {
                if ( scan_closetag_delim(scanner, lexer, true) ) {
                    return true;
                }
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