#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 344
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 94
#define ALIAS_COUNT 0
#define TOKEN_COUNT 51
#define EXTERNAL_TOKEN_COUNT 9
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_LT_BANG = 1,
  aux_sym_doctype_token1 = 2,
  anon_sym_GT = 3,
  sym__doctype = 4,
  aux_sym_cf_condition_token1 = 5,
  sym__cf_tag_start = 6,
  anon_sym_SLASH = 7,
  aux_sym_text_token1 = 8,
  sym_cf_tag_close = 9,
  sym_cf_true = 10,
  sym_cf_false = 11,
  sym_cf_operator = 12,
  anon_sym_LT = 13,
  anon_sym_SLASH_GT = 14,
  anon_sym_LT_SLASH = 15,
  anon_sym_POUND = 16,
  anon_sym_LBRACK = 17,
  anon_sym_RBRACK = 18,
  anon_sym_LBRACE = 19,
  anon_sym_RBRACE = 20,
  sym_cf_period = 21,
  sym_cf_comma = 22,
  anon_sym_EQ = 23,
  sym_cf_objectkeyassign = 24,
  anon_sym_DQUOTE = 25,
  anon_sym_LPAREN = 26,
  anon_sym_RPAREN = 27,
  anon_sym_set = 28,
  sym_attribute_name = 29,
  sym_attribute_value = 30,
  sym_cf_attribute_name = 31,
  sym_entity = 32,
  anon_sym_SQUOTE = 33,
  aux_sym_quoted_attribute_value_token1 = 34,
  aux_sym_quoted_attribute_value_token2 = 35,
  sym_cf_var = 36,
  sym_cf_if_keyword = 37,
  sym_cf_elseif_keyword = 38,
  sym_cf_else_keyword = 39,
  sym_cf_function_keyword = 40,
  sym_cf_argument_keyword = 41,
  sym_cf_return_keyword = 42,
  sym__start_tag_name = 43,
  sym__script_start_tag_name = 44,
  sym__style_start_tag_name = 45,
  sym__end_tag_name = 46,
  sym_erroneous_end_tag_name = 47,
  sym__implicit_end_tag = 48,
  sym_raw_text = 49,
  sym_comment = 50,
  sym_fragment = 51,
  sym_doctype = 52,
  sym_cf_condition = 53,
  sym_cf_tag_end = 54,
  sym_cf_tag_selfclose_end = 55,
  sym_text = 56,
  sym_cf_variable = 57,
  sym__node = 58,
  sym_element = 59,
  sym_script_element = 60,
  sym_start_tag = 61,
  sym_script_start_tag = 62,
  sym_style_start_tag = 63,
  sym_self_closing_tag = 64,
  sym_end_tag = 65,
  sym_style_element = 66,
  sym_cf_hash = 67,
  sym_cf_associative = 68,
  sym_cf_bracket = 69,
  sym__cf_expression = 70,
  sym_cf_function_call = 71,
  sym_cf_assignment = 72,
  sym_cf_dblquotes = 73,
  sym_cf_dblquotes_empty = 74,
  sym_cf_parens = 75,
  sym_cf_parens_empty = 76,
  sym_cf_function = 77,
  sym_cf_argument = 78,
  sym_cf_return = 79,
  sym_cf_ifstatement = 80,
  sym_cf_if = 81,
  sym_cf_set = 82,
  sym_cf_elseif = 83,
  sym_cf_else = 84,
  sym_cf_if_end = 85,
  sym_attribute = 86,
  sym_cf_attribute = 87,
  sym_cf_tag = 88,
  sym_quoted_attribute_value = 89,
  aux_sym_fragment_repeat1 = 90,
  aux_sym_start_tag_repeat1 = 91,
  aux_sym_cf_function_repeat1 = 92,
  aux_sym_cf_ifstatement_repeat1 = 93,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LT_BANG] = "<!",
  [aux_sym_doctype_token1] = "doctype_token1",
  [anon_sym_GT] = ">",
  [sym__doctype] = "doctype",
  [aux_sym_cf_condition_token1] = "cf_condition_token1",
  [sym__cf_tag_start] = "_cf_tag_start",
  [anon_sym_SLASH] = "/",
  [aux_sym_text_token1] = "text_token1",
  [sym_cf_tag_close] = "cf_tag_close",
  [sym_cf_true] = "cf_true",
  [sym_cf_false] = "cf_false",
  [sym_cf_operator] = "cf_operator",
  [anon_sym_LT] = "<",
  [anon_sym_SLASH_GT] = "/>",
  [anon_sym_LT_SLASH] = "</",
  [anon_sym_POUND] = "#",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_cf_period] = "cf_period",
  [sym_cf_comma] = "cf_comma",
  [anon_sym_EQ] = "=",
  [sym_cf_objectkeyassign] = "cf_objectkeyassign",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_set] = "set",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [sym_cf_attribute_name] = "cf_attribute_name",
  [sym_entity] = "entity",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [sym_cf_var] = "cf_var",
  [sym_cf_if_keyword] = "cf_if_keyword",
  [sym_cf_elseif_keyword] = "cf_elseif_keyword",
  [sym_cf_else_keyword] = "cf_else_keyword",
  [sym_cf_function_keyword] = "cf_function_keyword",
  [sym_cf_argument_keyword] = "cf_argument_keyword",
  [sym_cf_return_keyword] = "cf_return_keyword",
  [sym__start_tag_name] = "tag_name",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
  [sym__end_tag_name] = "tag_name",
  [sym_erroneous_end_tag_name] = "erroneous_end_tag_name",
  [sym__implicit_end_tag] = "_implicit_end_tag",
  [sym_raw_text] = "raw_text",
  [sym_comment] = "comment",
  [sym_fragment] = "fragment",
  [sym_doctype] = "doctype",
  [sym_cf_condition] = "cf_condition",
  [sym_cf_tag_end] = "cf_tag_end",
  [sym_cf_tag_selfclose_end] = "cf_tag_selfclose_end",
  [sym_text] = "text",
  [sym_cf_variable] = "cf_variable",
  [sym__node] = "_node",
  [sym_element] = "element",
  [sym_script_element] = "script_element",
  [sym_start_tag] = "start_tag",
  [sym_script_start_tag] = "start_tag",
  [sym_style_start_tag] = "start_tag",
  [sym_self_closing_tag] = "self_closing_tag",
  [sym_end_tag] = "end_tag",
  [sym_style_element] = "style_element",
  [sym_cf_hash] = "cf_hash",
  [sym_cf_associative] = "cf_associative",
  [sym_cf_bracket] = "cf_bracket",
  [sym__cf_expression] = "_cf_expression",
  [sym_cf_function_call] = "cf_function_call",
  [sym_cf_assignment] = "cf_assignment",
  [sym_cf_dblquotes] = "cf_dblquotes",
  [sym_cf_dblquotes_empty] = "cf_dblquotes_empty",
  [sym_cf_parens] = "cf_parens",
  [sym_cf_parens_empty] = "cf_parens_empty",
  [sym_cf_function] = "cf_function",
  [sym_cf_argument] = "cf_argument",
  [sym_cf_return] = "cf_return",
  [sym_cf_ifstatement] = "cf_ifstatement",
  [sym_cf_if] = "cf_if",
  [sym_cf_set] = "cf_set",
  [sym_cf_elseif] = "cf_elseif",
  [sym_cf_else] = "cf_else",
  [sym_cf_if_end] = "cf_if_end",
  [sym_attribute] = "attribute",
  [sym_cf_attribute] = "cf_attribute",
  [sym_cf_tag] = "cf_tag",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [aux_sym_fragment_repeat1] = "fragment_repeat1",
  [aux_sym_start_tag_repeat1] = "start_tag_repeat1",
  [aux_sym_cf_function_repeat1] = "cf_function_repeat1",
  [aux_sym_cf_ifstatement_repeat1] = "cf_ifstatement_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LT_BANG] = anon_sym_LT_BANG,
  [aux_sym_doctype_token1] = aux_sym_doctype_token1,
  [anon_sym_GT] = anon_sym_GT,
  [sym__doctype] = sym__doctype,
  [aux_sym_cf_condition_token1] = aux_sym_cf_condition_token1,
  [sym__cf_tag_start] = sym__cf_tag_start,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [aux_sym_text_token1] = aux_sym_text_token1,
  [sym_cf_tag_close] = sym_cf_tag_close,
  [sym_cf_true] = sym_cf_true,
  [sym_cf_false] = sym_cf_false,
  [sym_cf_operator] = sym_cf_operator,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [anon_sym_LT_SLASH] = anon_sym_LT_SLASH,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_cf_period] = sym_cf_period,
  [sym_cf_comma] = sym_cf_comma,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_cf_objectkeyassign] = sym_cf_objectkeyassign,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_set] = anon_sym_set,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [sym_cf_attribute_name] = sym_cf_attribute_name,
  [sym_entity] = sym_entity,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [sym_cf_var] = sym_cf_var,
  [sym_cf_if_keyword] = sym_cf_if_keyword,
  [sym_cf_elseif_keyword] = sym_cf_elseif_keyword,
  [sym_cf_else_keyword] = sym_cf_else_keyword,
  [sym_cf_function_keyword] = sym_cf_function_keyword,
  [sym_cf_argument_keyword] = sym_cf_argument_keyword,
  [sym_cf_return_keyword] = sym_cf_return_keyword,
  [sym__start_tag_name] = sym__start_tag_name,
  [sym__script_start_tag_name] = sym__start_tag_name,
  [sym__style_start_tag_name] = sym__start_tag_name,
  [sym__end_tag_name] = sym__start_tag_name,
  [sym_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [sym__implicit_end_tag] = sym__implicit_end_tag,
  [sym_raw_text] = sym_raw_text,
  [sym_comment] = sym_comment,
  [sym_fragment] = sym_fragment,
  [sym_doctype] = sym_doctype,
  [sym_cf_condition] = sym_cf_condition,
  [sym_cf_tag_end] = sym_cf_tag_end,
  [sym_cf_tag_selfclose_end] = sym_cf_tag_selfclose_end,
  [sym_text] = sym_text,
  [sym_cf_variable] = sym_cf_variable,
  [sym__node] = sym__node,
  [sym_element] = sym_element,
  [sym_script_element] = sym_script_element,
  [sym_start_tag] = sym_start_tag,
  [sym_script_start_tag] = sym_start_tag,
  [sym_style_start_tag] = sym_start_tag,
  [sym_self_closing_tag] = sym_self_closing_tag,
  [sym_end_tag] = sym_end_tag,
  [sym_style_element] = sym_style_element,
  [sym_cf_hash] = sym_cf_hash,
  [sym_cf_associative] = sym_cf_associative,
  [sym_cf_bracket] = sym_cf_bracket,
  [sym__cf_expression] = sym__cf_expression,
  [sym_cf_function_call] = sym_cf_function_call,
  [sym_cf_assignment] = sym_cf_assignment,
  [sym_cf_dblquotes] = sym_cf_dblquotes,
  [sym_cf_dblquotes_empty] = sym_cf_dblquotes_empty,
  [sym_cf_parens] = sym_cf_parens,
  [sym_cf_parens_empty] = sym_cf_parens_empty,
  [sym_cf_function] = sym_cf_function,
  [sym_cf_argument] = sym_cf_argument,
  [sym_cf_return] = sym_cf_return,
  [sym_cf_ifstatement] = sym_cf_ifstatement,
  [sym_cf_if] = sym_cf_if,
  [sym_cf_set] = sym_cf_set,
  [sym_cf_elseif] = sym_cf_elseif,
  [sym_cf_else] = sym_cf_else,
  [sym_cf_if_end] = sym_cf_if_end,
  [sym_attribute] = sym_attribute,
  [sym_cf_attribute] = sym_cf_attribute,
  [sym_cf_tag] = sym_cf_tag,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [aux_sym_fragment_repeat1] = aux_sym_fragment_repeat1,
  [aux_sym_start_tag_repeat1] = aux_sym_start_tag_repeat1,
  [aux_sym_cf_function_repeat1] = aux_sym_cf_function_repeat1,
  [aux_sym_cf_ifstatement_repeat1] = aux_sym_cf_ifstatement_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LT_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_doctype_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym__doctype] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_cf_condition_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__cf_tag_start] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_text_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_cf_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_true] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_false] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_operator] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_cf_period] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_comma] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_cf_objectkeyassign] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_set] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token1] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_quoted_attribute_value_token2] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_var] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_if_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_elseif_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_else_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_function_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_argument_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_return_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym__start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__script_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__style_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_erroneous_end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__implicit_end_tag] = {
    .visible = false,
    .named = true,
  },
  [sym_raw_text] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_doctype] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_tag_end] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_tag_selfclose_end] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_variable] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_element] = {
    .visible = true,
    .named = true,
  },
  [sym_script_element] = {
    .visible = true,
    .named = true,
  },
  [sym_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_script_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_self_closing_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_element] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_hash] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_associative] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_bracket] = {
    .visible = true,
    .named = true,
  },
  [sym__cf_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_cf_function_call] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_dblquotes] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_dblquotes_empty] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_parens] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_parens_empty] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_function] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_argument] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_return] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_ifstatement] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_if] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_set] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_elseif] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_else] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_if_end] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_fragment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_start_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_cf_function_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_cf_ifstatement_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 3,
  [6] = 3,
  [7] = 7,
  [8] = 8,
  [9] = 3,
  [10] = 3,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 23,
  [25] = 25,
  [26] = 26,
  [27] = 3,
  [28] = 21,
  [29] = 29,
  [30] = 3,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 8,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 37,
  [40] = 38,
  [41] = 41,
  [42] = 41,
  [43] = 43,
  [44] = 44,
  [45] = 44,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 55,
  [57] = 57,
  [58] = 57,
  [59] = 57,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 61,
  [67] = 67,
  [68] = 64,
  [69] = 63,
  [70] = 65,
  [71] = 61,
  [72] = 60,
  [73] = 61,
  [74] = 67,
  [75] = 67,
  [76] = 76,
  [77] = 61,
  [78] = 65,
  [79] = 64,
  [80] = 61,
  [81] = 65,
  [82] = 82,
  [83] = 64,
  [84] = 76,
  [85] = 85,
  [86] = 64,
  [87] = 65,
  [88] = 65,
  [89] = 64,
  [90] = 67,
  [91] = 67,
  [92] = 92,
  [93] = 82,
  [94] = 63,
  [95] = 64,
  [96] = 65,
  [97] = 61,
  [98] = 67,
  [99] = 67,
  [100] = 82,
  [101] = 76,
  [102] = 63,
  [103] = 63,
  [104] = 82,
  [105] = 82,
  [106] = 82,
  [107] = 62,
  [108] = 92,
  [109] = 92,
  [110] = 82,
  [111] = 111,
  [112] = 25,
  [113] = 29,
  [114] = 50,
  [115] = 53,
  [116] = 48,
  [117] = 25,
  [118] = 22,
  [119] = 26,
  [120] = 120,
  [121] = 111,
  [122] = 120,
  [123] = 22,
  [124] = 124,
  [125] = 29,
  [126] = 54,
  [127] = 26,
  [128] = 49,
  [129] = 46,
  [130] = 47,
  [131] = 52,
  [132] = 51,
  [133] = 22,
  [134] = 26,
  [135] = 29,
  [136] = 25,
  [137] = 25,
  [138] = 29,
  [139] = 22,
  [140] = 26,
  [141] = 124,
  [142] = 142,
  [143] = 29,
  [144] = 26,
  [145] = 25,
  [146] = 22,
  [147] = 22,
  [148] = 26,
  [149] = 149,
  [150] = 29,
  [151] = 25,
  [152] = 152,
  [153] = 152,
  [154] = 154,
  [155] = 152,
  [156] = 142,
  [157] = 157,
  [158] = 149,
  [159] = 152,
  [160] = 154,
  [161] = 157,
  [162] = 154,
  [163] = 142,
  [164] = 157,
  [165] = 149,
  [166] = 152,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 46,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 169,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 48,
  [202] = 49,
  [203] = 46,
  [204] = 52,
  [205] = 47,
  [206] = 51,
  [207] = 50,
  [208] = 53,
  [209] = 54,
  [210] = 210,
  [211] = 210,
  [212] = 212,
  [213] = 212,
  [214] = 172,
  [215] = 184,
  [216] = 197,
  [217] = 190,
  [218] = 198,
  [219] = 193,
  [220] = 194,
  [221] = 196,
  [222] = 200,
  [223] = 195,
  [224] = 191,
  [225] = 199,
  [226] = 185,
  [227] = 171,
  [228] = 228,
  [229] = 189,
  [230] = 174,
  [231] = 46,
  [232] = 168,
  [233] = 188,
  [234] = 170,
  [235] = 183,
  [236] = 173,
  [237] = 167,
  [238] = 175,
  [239] = 176,
  [240] = 182,
  [241] = 181,
  [242] = 180,
  [243] = 177,
  [244] = 186,
  [245] = 245,
  [246] = 178,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 249,
  [254] = 252,
  [255] = 251,
  [256] = 250,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 259,
  [262] = 262,
  [263] = 263,
  [264] = 260,
  [265] = 258,
  [266] = 262,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 263,
  [271] = 267,
  [272] = 272,
  [273] = 257,
  [274] = 274,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 280,
  [281] = 281,
  [282] = 282,
  [283] = 276,
  [284] = 280,
  [285] = 281,
  [286] = 279,
  [287] = 287,
  [288] = 288,
  [289] = 278,
  [290] = 268,
  [291] = 277,
  [292] = 292,
  [293] = 292,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 282,
  [299] = 299,
  [300] = 300,
  [301] = 287,
  [302] = 302,
  [303] = 294,
  [304] = 288,
  [305] = 300,
  [306] = 296,
  [307] = 295,
  [308] = 308,
  [309] = 297,
  [310] = 310,
  [311] = 311,
  [312] = 312,
  [313] = 313,
  [314] = 312,
  [315] = 315,
  [316] = 316,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 320,
  [321] = 317,
  [322] = 322,
  [323] = 320,
  [324] = 324,
  [325] = 325,
  [326] = 318,
  [327] = 327,
  [328] = 328,
  [329] = 325,
  [330] = 330,
  [331] = 331,
  [332] = 331,
  [333] = 333,
  [334] = 316,
  [335] = 335,
  [336] = 330,
  [337] = 322,
  [338] = 327,
  [339] = 324,
  [340] = 340,
  [341] = 319,
  [342] = 333,
  [343] = 340,
};

static inline bool aux_sym_text_token1_character_set_1(int32_t c) {
  return (c < '='
    ? (c < '\''
      ? (c < '"'
        ? c == 0
        : c <= '"')
      : (c <= ')' || (c < '.'
        ? c == ','
        : c <= '.')))
    : (c <= '>' || (c < '{'
      ? (c < ']'
        ? c == '['
        : c <= ']')
      : (c <= '{' || c == '}'))));
}

static inline bool aux_sym_text_token1_character_set_2(int32_t c) {
  return (c < '.'
    ? (c < '\''
      ? (c < '"'
        ? c == 0
        : c <= '"')
      : (c <= ')' || c == ','))
    : (c <= '.' || (c < ']'
      ? (c < '['
        ? c == '='
        : c <= '[')
      : (c <= ']' || c == '{'))));
}

static inline bool aux_sym_text_token1_character_set_3(int32_t c) {
  return (c < ','
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '\''
        ? (c >= '"' && c <= '#')
        : c <= ')')))
    : (c <= ',' || (c < ']'
      ? (c < '<'
        ? c == '.'
        : (c <= '>' || c == '['))
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool aux_sym_text_token1_character_set_4(int32_t c) {
  return (c < ','
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '\''
        ? c == '"'
        : c <= ')')))
    : (c <= ',' || (c < ']'
      ? (c < '<'
        ? c == '.'
        : (c <= '>' || c == '['))
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool aux_sym_text_token1_character_set_5(int32_t c) {
  return (c < '<'
    ? (c < '\''
      ? (c < '"'
        ? c == 0
        : c <= '#')
      : (c <= ')' || (c < '.'
        ? c == ','
        : c <= '.')))
    : (c <= '>' || (c < '{'
      ? (c < ']'
        ? c == '['
        : c <= ']')
      : (c <= '{' || c == '}'))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(137);
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(20);
      if (lookahead == '\'') ADVANCE(280);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ')') ADVANCE(265);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == '/') ADVANCE(146);
      if (lookahead == ':') ADVANCE(258);
      if (lookahead == '<') ADVANCE(238);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == ']') ADVANCE(248);
      if (lookahead == 'a') ADVANCE(107);
      if (lookahead == 'e') ADVANCE(97);
      if (lookahead == 'f') ADVANCE(79);
      if (lookahead == 'i') ADVANCE(90);
      if (lookahead == 'r') ADVANCE(82);
      if (lookahead == 's') ADVANCE(87);
      if (lookahead == 't') ADVANCE(108);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(20);
      if (lookahead == '\'') ADVANCE(280);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ')') ADVANCE(265);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == '/') ADVANCE(146);
      if (lookahead == ':') ADVANCE(258);
      if (lookahead == '<') ADVANCE(238);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(72);
      if (lookahead == 'E') ADVANCE(74);
      if (lookahead == 'G') ADVANCE(77);
      if (lookahead == 'N') ADVANCE(73);
      if (lookahead == 'O') ADVANCE(75);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == ']') ADVANCE(248);
      if (lookahead == 'a') ADVANCE(107);
      if (lookahead == 'e') ADVANCE(97);
      if (lookahead == 'f') ADVANCE(79);
      if (lookahead == 'i') ADVANCE(90);
      if (lookahead == 'r') ADVANCE(82);
      if (lookahead == 's') ADVANCE(87);
      if (lookahead == 't') ADVANCE(108);
      if (lookahead == 'v') ADVANCE(78);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(148);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '<') ADVANCE(240);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(198);
      if (lookahead == 'E') ADVANCE(200);
      if (lookahead == 'G') ADVANCE(203);
      if (lookahead == 'N') ADVANCE(199);
      if (lookahead == 'O') ADVANCE(201);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ']') ADVANCE(229);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(148);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '<') ADVANCE(240);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ']') ADVANCE(229);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ')') ADVANCE(265);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '<') ADVANCE(25);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == 'A') ADVANCE(198);
      if (lookahead == 'E') ADVANCE(200);
      if (lookahead == 'G') ADVANCE(203);
      if (lookahead == 'N') ADVANCE(199);
      if (lookahead == 'O') ADVANCE(201);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == ']') ADVANCE(248);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '>') ADVANCE(229);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ')') ADVANCE(265);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '<') ADVANCE(25);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == ']') ADVANCE(248);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '>') ADVANCE(229);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ')') ADVANCE(265);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != ',' &&
          lookahead != '.' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(229);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == '/') ADVANCE(147);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(198);
      if (lookahead == 'E') ADVANCE(200);
      if (lookahead == 'G') ADVANCE(203);
      if (lookahead == 'N') ADVANCE(199);
      if (lookahead == 'O') ADVANCE(201);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '<' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(229);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == '/') ADVANCE(147);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '<' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(229);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == 'v') ADVANCE(204);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != '.' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(229);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == 'f') ADVANCE(205);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == '{') ADVANCE(249);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != '.' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(229);
      END_STATE();
    case 11:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '(') ADVANCE(264);
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == ':') ADVANCE(259);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(151);
      if (lookahead == 'E') ADVANCE(153);
      if (lookahead == 'G') ADVANCE(156);
      if (lookahead == 'N') ADVANCE(152);
      if (lookahead == 'O') ADVANCE(154);
      if (lookahead == '[') ADVANCE(247);
      if (lookahead == 'f') ADVANCE(157);
      if (lookahead == 't') ADVANCE(161);
      if (lookahead == '{') ADVANCE(250);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(165);
      END_STATE();
    case 12:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '(') ADVANCE(264);
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == ':') ADVANCE(259);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(247);
      if (lookahead == 'f') ADVANCE(157);
      if (lookahead == 't') ADVANCE(161);
      if (lookahead == '{') ADVANCE(250);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(165);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '(') ADVANCE(264);
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '/') ADVANCE(147);
      if (lookahead == ':') ADVANCE(259);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(151);
      if (lookahead == 'E') ADVANCE(153);
      if (lookahead == 'G') ADVANCE(156);
      if (lookahead == 'N') ADVANCE(152);
      if (lookahead == 'O') ADVANCE(154);
      if (lookahead == '[') ADVANCE(247);
      if (lookahead == 'f') ADVANCE(157);
      if (lookahead == 't') ADVANCE(161);
      if (lookahead == '{') ADVANCE(250);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(165);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '(') ADVANCE(264);
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '/') ADVANCE(147);
      if (lookahead == ':') ADVANCE(259);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(247);
      if (lookahead == 'f') ADVANCE(157);
      if (lookahead == 't') ADVANCE(161);
      if (lookahead == '{') ADVANCE(250);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(165);
      END_STATE();
    case 15:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '\'') ADVANCE(280);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(268);
      END_STATE();
    case 16:
      if (lookahead == '"') ADVANCE(262);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(283);
      if (lookahead != 0) ADVANCE(284);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(148);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '<') ADVANCE(240);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(198);
      if (lookahead == 'E') ADVANCE(200);
      if (lookahead == 'G') ADVANCE(203);
      if (lookahead == 'N') ADVANCE(199);
      if (lookahead == 'O') ADVANCE(201);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '"' &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ']' &&
          lookahead != '{') ADVANCE(229);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(148);
      if (lookahead == '(') ADVANCE(263);
      if (lookahead == ',') ADVANCE(254);
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == ':') ADVANCE(260);
      if (lookahead == '<') ADVANCE(240);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(246);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '"' &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ']' &&
          lookahead != '{') ADVANCE(229);
      END_STATE();
    case 19:
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(148);
      if (lookahead == '<') ADVANCE(239);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(19)
      if (!aux_sym_text_token1_character_set_1(lookahead)) ADVANCE(229);
      END_STATE();
    case 20:
      if (lookahead == '#') ADVANCE(129);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 21:
      if (lookahead == '\'') ADVANCE(280);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(281);
      if (lookahead != 0) ADVANCE(282);
      END_STATE();
    case 22:
      if (lookahead == '(') ADVANCE(264);
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '/') ADVANCE(146);
      if (lookahead == ':') ADVANCE(261);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'A') ADVANCE(271);
      if (lookahead == 'E') ADVANCE(273);
      if (lookahead == 'G') ADVANCE(276);
      if (lookahead == 'N') ADVANCE(272);
      if (lookahead == 'O') ADVANCE(274);
      if (lookahead == '[') ADVANCE(247);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(278);
      END_STATE();
    case 23:
      if (lookahead == '(') ADVANCE(264);
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '/') ADVANCE(146);
      if (lookahead == ':') ADVANCE(261);
      if (lookahead == '=') ADVANCE(257);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '[') ADVANCE(247);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(278);
      END_STATE();
    case 24:
      if (lookahead == '/') ADVANCE(146);
      if (lookahead == '=') ADVANCE(256);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(24)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(278);
      END_STATE();
    case 25:
      if (lookahead == '/') ADVANCE(242);
      END_STATE();
    case 26:
      if (lookahead == '/') ADVANCE(69);
      if (lookahead == '=') ADVANCE(256);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(26)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(267);
      END_STATE();
    case 27:
      if (lookahead == '/') ADVANCE(80);
      if (lookahead == 'c') ADVANCE(91);
      END_STATE();
    case 28:
      if (lookahead == ';') ADVANCE(279);
      END_STATE();
    case 29:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 30:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 31:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 33:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 34:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 37:
      if (lookahead == ';') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(28);
      END_STATE();
    case 39:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(38);
      END_STATE();
    case 40:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 41:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 43:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 44:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 45:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 46:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 47:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 48:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 49:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(48);
      END_STATE();
    case 50:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 51:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(50);
      END_STATE();
    case 52:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 53:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 54:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 55:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 56:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 57:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 58:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 59:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 60:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 61:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(60);
      END_STATE();
    case 62:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 63:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(62);
      END_STATE();
    case 64:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 65:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 66:
      if (lookahead == ';') ADVANCE(279);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(65);
      END_STATE();
    case 67:
      if (lookahead == '<') ADVANCE(27);
      if (lookahead == 'e') ADVANCE(97);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(67)
      END_STATE();
    case 68:
      if (lookahead == '=') ADVANCE(237);
      END_STATE();
    case 69:
      if (lookahead == '>') ADVANCE(241);
      END_STATE();
    case 70:
      if (lookahead == 'D') ADVANCE(131);
      END_STATE();
    case 71:
      if (lookahead == 'E') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      END_STATE();
    case 72:
      if (lookahead == 'N') ADVANCE(70);
      END_STATE();
    case 73:
      if (lookahead == 'O') ADVANCE(76);
      END_STATE();
    case 74:
      if (lookahead == 'Q') ADVANCE(131);
      END_STATE();
    case 75:
      if (lookahead == 'R') ADVANCE(131);
      END_STATE();
    case 76:
      if (lookahead == 'T') ADVANCE(131);
      END_STATE();
    case 77:
      if (lookahead == 'T') ADVANCE(71);
      END_STATE();
    case 78:
      if (lookahead == 'a') ADVANCE(110);
      END_STATE();
    case 79:
      if (lookahead == 'a') ADVANCE(98);
      if (lookahead == 'u') ADVANCE(102);
      END_STATE();
    case 80:
      if (lookahead == 'c') ADVANCE(92);
      END_STATE();
    case 81:
      if (lookahead == 'c') ADVANCE(116);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(289);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(231);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(234);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(288);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(115);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(105);
      END_STATE();
    case 90:
      if (lookahead == 'f') ADVANCE(286);
      END_STATE();
    case 91:
      if (lookahead == 'f') ADVANCE(145);
      END_STATE();
    case 92:
      if (lookahead == 'f') ADVANCE(230);
      END_STATE();
    case 93:
      if (lookahead == 'f') ADVANCE(287);
      END_STATE();
    case 94:
      if (lookahead == 'g') ADVANCE(120);
      END_STATE();
    case 95:
      if (lookahead == 'i') ADVANCE(106);
      END_STATE();
    case 96:
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 97:
      if (lookahead == 'l') ADVANCE(111);
      END_STATE();
    case 98:
      if (lookahead == 'l') ADVANCE(112);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(113);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(114);
      END_STATE();
    case 101:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 102:
      if (lookahead == 'n') ADVANCE(81);
      END_STATE();
    case 103:
      if (lookahead == 'n') ADVANCE(292);
      END_STATE();
    case 104:
      if (lookahead == 'n') ADVANCE(290);
      END_STATE();
    case 105:
      if (lookahead == 'n') ADVANCE(117);
      END_STATE();
    case 106:
      if (lookahead == 'o') ADVANCE(104);
      END_STATE();
    case 107:
      if (lookahead == 'r') ADVANCE(94);
      END_STATE();
    case 108:
      if (lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 109:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 110:
      if (lookahead == 'r') ADVANCE(132);
      END_STATE();
    case 111:
      if (lookahead == 's') ADVANCE(83);
      END_STATE();
    case 112:
      if (lookahead == 's') ADVANCE(85);
      END_STATE();
    case 113:
      if (lookahead == 's') ADVANCE(86);
      END_STATE();
    case 114:
      if (lookahead == 's') ADVANCE(88);
      END_STATE();
    case 115:
      if (lookahead == 't') ADVANCE(266);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(95);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(291);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 119:
      if (lookahead == 'u') ADVANCE(102);
      END_STATE();
    case 120:
      if (lookahead == 'u') ADVANCE(101);
      END_STATE();
    case 121:
      if (lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 122:
      if (lookahead == 'u') ADVANCE(109);
      END_STATE();
    case 123:
      if (lookahead == 'v') ADVANCE(78);
      END_STATE();
    case 124:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(128);
      END_STATE();
    case 125:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(142);
      END_STATE();
    case 126:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(124);
      END_STATE();
    case 127:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(125);
      END_STATE();
    case 128:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(130);
      END_STATE();
    case 129:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 130:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(127);
      END_STATE();
    case 131:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      END_STATE();
    case 132:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(285);
      END_STATE();
    case 133:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(144);
      END_STATE();
    case 134:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(140);
      END_STATE();
    case 135:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 136:
      if (eof) ADVANCE(137);
      if (lookahead == '#') ADVANCE(244);
      if (lookahead == '&') ADVANCE(148);
      if (lookahead == '<') ADVANCE(240);
      if (lookahead == '>') ADVANCE(141);
      if (lookahead == 'e') ADVANCE(216);
      if (lookahead == '}') ADVANCE(251);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(136)
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(229);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(140);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(144);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym__cf_tag_start);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '#') ADVANCE(129);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(194);
      if (!aux_sym_text_token1_character_set_4(lookahead)) ADVANCE(229);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'D') ADVANCE(164);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'E') ADVANCE(164);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'N') ADVANCE(149);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'O') ADVANCE(155);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'Q') ADVANCE(164);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'R') ADVANCE(164);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'T') ADVANCE(164);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'T') ADVANCE(150);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'a') ADVANCE(160);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'e') ADVANCE(232);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'e') ADVANCE(235);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'l') ADVANCE(162);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'r') ADVANCE(163);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 's') ADVANCE(159);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'u') ADVANCE(158);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(195);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(166);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(167);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(169);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(170);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(171);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(172);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(173);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(179);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(180);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(181);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(182);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(183);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(184);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(185);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(186);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(187);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(188);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(189);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(190);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(191);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(192);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(193);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(229);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'D') ADVANCE(227);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'E') ADVANCE(227);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      if (!aux_sym_text_token1_character_set_5(lookahead)) ADVANCE(229);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'N') ADVANCE(196);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'O') ADVANCE(202);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'Q') ADVANCE(227);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'R') ADVANCE(227);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(227);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(197);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'a') ADVANCE(221);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'a') ADVANCE(219);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(210);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(215);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(233);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(236);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(217);
      if (lookahead == 'i') ADVANCE(214);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(217);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(218);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(211);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'f') ADVANCE(212);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'i') ADVANCE(214);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(222);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(223);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(224);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(225);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'r') ADVANCE(226);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'r') ADVANCE(228);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(206);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(213);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(207);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(209);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'u') ADVANCE(208);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      if (!aux_sym_text_token1_character_set_5(lookahead)) ADVANCE(229);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(285);
      if (!aux_sym_text_token1_character_set_5(lookahead)) ADVANCE(229);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_cf_tag_close);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_cf_true);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_cf_true);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_cf_true);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_cf_false);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_cf_false);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_cf_false);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_cf_operator);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(138);
      if (lookahead == '/') ADVANCE(243);
      if (lookahead == 'c') ADVANCE(91);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(138);
      if (lookahead == '/') ADVANCE(242);
      if (lookahead == 'c') ADVANCE(91);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(138);
      if (lookahead == '/') ADVANCE(80);
      if (lookahead == 'c') ADVANCE(91);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      if (lookahead == 'c') ADVANCE(92);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_cf_period);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_cf_period);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_cf_comma);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_cf_comma);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(68);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(278);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(165);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(229);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_set);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(267);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(268);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'D') ADVANCE(277);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'E') ADVANCE(277);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'N') ADVANCE(269);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'O') ADVANCE(275);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'Q') ADVANCE(277);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'R') ADVANCE(277);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'T') ADVANCE(277);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'T') ADVANCE(270);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(278);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(281);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(282);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(282);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(283);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(284);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(284);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_cf_var);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(123);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_cf_if_keyword);
      if (lookahead == 'i') ADVANCE(90);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_cf_elseif_keyword);
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_cf_function_keyword);
      if (lookahead == 'f') ADVANCE(119);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_cf_argument_keyword);
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_cf_return_keyword);
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 136, .external_lex_state = 2},
  [2] = {.lex_state = 18, .external_lex_state = 2},
  [3] = {.lex_state = 3, .external_lex_state = 2},
  [4] = {.lex_state = 136, .external_lex_state = 2},
  [5] = {.lex_state = 5, .external_lex_state = 2},
  [6] = {.lex_state = 14, .external_lex_state = 2},
  [7] = {.lex_state = 136, .external_lex_state = 2},
  [8] = {.lex_state = 136, .external_lex_state = 2},
  [9] = {.lex_state = 12, .external_lex_state = 2},
  [10] = {.lex_state = 8, .external_lex_state = 2},
  [11] = {.lex_state = 136, .external_lex_state = 2},
  [12] = {.lex_state = 136, .external_lex_state = 2},
  [13] = {.lex_state = 136, .external_lex_state = 2},
  [14] = {.lex_state = 136, .external_lex_state = 2},
  [15] = {.lex_state = 136, .external_lex_state = 2},
  [16] = {.lex_state = 136, .external_lex_state = 2},
  [17] = {.lex_state = 136, .external_lex_state = 2},
  [18] = {.lex_state = 136, .external_lex_state = 2},
  [19] = {.lex_state = 136, .external_lex_state = 2},
  [20] = {.lex_state = 136, .external_lex_state = 2},
  [21] = {.lex_state = 19, .external_lex_state = 3},
  [22] = {.lex_state = 18, .external_lex_state = 2},
  [23] = {.lex_state = 19, .external_lex_state = 3},
  [24] = {.lex_state = 19, .external_lex_state = 3},
  [25] = {.lex_state = 18, .external_lex_state = 2},
  [26] = {.lex_state = 18, .external_lex_state = 2},
  [27] = {.lex_state = 5, .external_lex_state = 2},
  [28] = {.lex_state = 19, .external_lex_state = 3},
  [29] = {.lex_state = 18, .external_lex_state = 2},
  [30] = {.lex_state = 5, .external_lex_state = 2},
  [31] = {.lex_state = 136, .external_lex_state = 2},
  [32] = {.lex_state = 136, .external_lex_state = 2},
  [33] = {.lex_state = 136, .external_lex_state = 2},
  [34] = {.lex_state = 136, .external_lex_state = 2},
  [35] = {.lex_state = 19, .external_lex_state = 3},
  [36] = {.lex_state = 136, .external_lex_state = 2},
  [37] = {.lex_state = 136, .external_lex_state = 2},
  [38] = {.lex_state = 136, .external_lex_state = 2},
  [39] = {.lex_state = 136, .external_lex_state = 2},
  [40] = {.lex_state = 136, .external_lex_state = 2},
  [41] = {.lex_state = 136, .external_lex_state = 2},
  [42] = {.lex_state = 136, .external_lex_state = 2},
  [43] = {.lex_state = 136, .external_lex_state = 2},
  [44] = {.lex_state = 136, .external_lex_state = 2},
  [45] = {.lex_state = 136, .external_lex_state = 2},
  [46] = {.lex_state = 18, .external_lex_state = 2},
  [47] = {.lex_state = 18, .external_lex_state = 2},
  [48] = {.lex_state = 18, .external_lex_state = 2},
  [49] = {.lex_state = 18, .external_lex_state = 2},
  [50] = {.lex_state = 18, .external_lex_state = 2},
  [51] = {.lex_state = 18, .external_lex_state = 2},
  [52] = {.lex_state = 18, .external_lex_state = 2},
  [53] = {.lex_state = 18, .external_lex_state = 2},
  [54] = {.lex_state = 18, .external_lex_state = 2},
  [55] = {.lex_state = 10, .external_lex_state = 2},
  [56] = {.lex_state = 10, .external_lex_state = 2},
  [57] = {.lex_state = 6, .external_lex_state = 2},
  [58] = {.lex_state = 6, .external_lex_state = 2},
  [59] = {.lex_state = 6, .external_lex_state = 2},
  [60] = {.lex_state = 6, .external_lex_state = 2},
  [61] = {.lex_state = 6, .external_lex_state = 2},
  [62] = {.lex_state = 6, .external_lex_state = 2},
  [63] = {.lex_state = 6, .external_lex_state = 2},
  [64] = {.lex_state = 6, .external_lex_state = 2},
  [65] = {.lex_state = 6, .external_lex_state = 2},
  [66] = {.lex_state = 6, .external_lex_state = 2},
  [67] = {.lex_state = 6, .external_lex_state = 2},
  [68] = {.lex_state = 6, .external_lex_state = 2},
  [69] = {.lex_state = 6, .external_lex_state = 2},
  [70] = {.lex_state = 6, .external_lex_state = 2},
  [71] = {.lex_state = 6, .external_lex_state = 2},
  [72] = {.lex_state = 6, .external_lex_state = 2},
  [73] = {.lex_state = 6, .external_lex_state = 2},
  [74] = {.lex_state = 6, .external_lex_state = 2},
  [75] = {.lex_state = 6, .external_lex_state = 2},
  [76] = {.lex_state = 6, .external_lex_state = 2},
  [77] = {.lex_state = 6, .external_lex_state = 2},
  [78] = {.lex_state = 6, .external_lex_state = 2},
  [79] = {.lex_state = 6, .external_lex_state = 2},
  [80] = {.lex_state = 6, .external_lex_state = 2},
  [81] = {.lex_state = 6, .external_lex_state = 2},
  [82] = {.lex_state = 6, .external_lex_state = 2},
  [83] = {.lex_state = 6, .external_lex_state = 2},
  [84] = {.lex_state = 6, .external_lex_state = 2},
  [85] = {.lex_state = 6, .external_lex_state = 2},
  [86] = {.lex_state = 6, .external_lex_state = 2},
  [87] = {.lex_state = 6, .external_lex_state = 2},
  [88] = {.lex_state = 6, .external_lex_state = 2},
  [89] = {.lex_state = 6, .external_lex_state = 2},
  [90] = {.lex_state = 6, .external_lex_state = 2},
  [91] = {.lex_state = 6, .external_lex_state = 2},
  [92] = {.lex_state = 6, .external_lex_state = 2},
  [93] = {.lex_state = 6, .external_lex_state = 2},
  [94] = {.lex_state = 6, .external_lex_state = 2},
  [95] = {.lex_state = 6, .external_lex_state = 2},
  [96] = {.lex_state = 6, .external_lex_state = 2},
  [97] = {.lex_state = 6, .external_lex_state = 2},
  [98] = {.lex_state = 6, .external_lex_state = 2},
  [99] = {.lex_state = 6, .external_lex_state = 2},
  [100] = {.lex_state = 6, .external_lex_state = 2},
  [101] = {.lex_state = 6, .external_lex_state = 2},
  [102] = {.lex_state = 6, .external_lex_state = 2},
  [103] = {.lex_state = 6, .external_lex_state = 2},
  [104] = {.lex_state = 6, .external_lex_state = 2},
  [105] = {.lex_state = 6, .external_lex_state = 2},
  [106] = {.lex_state = 6, .external_lex_state = 2},
  [107] = {.lex_state = 6, .external_lex_state = 2},
  [108] = {.lex_state = 6, .external_lex_state = 2},
  [109] = {.lex_state = 6, .external_lex_state = 2},
  [110] = {.lex_state = 6, .external_lex_state = 2},
  [111] = {.lex_state = 0, .external_lex_state = 2},
  [112] = {.lex_state = 0, .external_lex_state = 2},
  [113] = {.lex_state = 23, .external_lex_state = 2},
  [114] = {.lex_state = 0, .external_lex_state = 2},
  [115] = {.lex_state = 0, .external_lex_state = 2},
  [116] = {.lex_state = 0, .external_lex_state = 2},
  [117] = {.lex_state = 23, .external_lex_state = 2},
  [118] = {.lex_state = 23, .external_lex_state = 2},
  [119] = {.lex_state = 23, .external_lex_state = 2},
  [120] = {.lex_state = 0, .external_lex_state = 2},
  [121] = {.lex_state = 0, .external_lex_state = 2},
  [122] = {.lex_state = 0, .external_lex_state = 2},
  [123] = {.lex_state = 0, .external_lex_state = 2},
  [124] = {.lex_state = 23, .external_lex_state = 2},
  [125] = {.lex_state = 0, .external_lex_state = 2},
  [126] = {.lex_state = 0, .external_lex_state = 2},
  [127] = {.lex_state = 0, .external_lex_state = 2},
  [128] = {.lex_state = 0, .external_lex_state = 2},
  [129] = {.lex_state = 0, .external_lex_state = 2},
  [130] = {.lex_state = 0, .external_lex_state = 2},
  [131] = {.lex_state = 0, .external_lex_state = 2},
  [132] = {.lex_state = 0, .external_lex_state = 2},
  [133] = {.lex_state = 0, .external_lex_state = 2},
  [134] = {.lex_state = 23, .external_lex_state = 2},
  [135] = {.lex_state = 23, .external_lex_state = 2},
  [136] = {.lex_state = 23, .external_lex_state = 2},
  [137] = {.lex_state = 0, .external_lex_state = 2},
  [138] = {.lex_state = 0, .external_lex_state = 2},
  [139] = {.lex_state = 23, .external_lex_state = 2},
  [140] = {.lex_state = 0, .external_lex_state = 2},
  [141] = {.lex_state = 23, .external_lex_state = 2},
  [142] = {.lex_state = 0, .external_lex_state = 2},
  [143] = {.lex_state = 0, .external_lex_state = 2},
  [144] = {.lex_state = 0, .external_lex_state = 2},
  [145] = {.lex_state = 0, .external_lex_state = 2},
  [146] = {.lex_state = 0, .external_lex_state = 2},
  [147] = {.lex_state = 0, .external_lex_state = 2},
  [148] = {.lex_state = 0, .external_lex_state = 2},
  [149] = {.lex_state = 0, .external_lex_state = 2},
  [150] = {.lex_state = 0, .external_lex_state = 2},
  [151] = {.lex_state = 0, .external_lex_state = 2},
  [152] = {.lex_state = 0, .external_lex_state = 2},
  [153] = {.lex_state = 0, .external_lex_state = 2},
  [154] = {.lex_state = 0, .external_lex_state = 2},
  [155] = {.lex_state = 0, .external_lex_state = 2},
  [156] = {.lex_state = 0, .external_lex_state = 2},
  [157] = {.lex_state = 0, .external_lex_state = 2},
  [158] = {.lex_state = 0, .external_lex_state = 2},
  [159] = {.lex_state = 0, .external_lex_state = 2},
  [160] = {.lex_state = 0, .external_lex_state = 2},
  [161] = {.lex_state = 0, .external_lex_state = 2},
  [162] = {.lex_state = 0, .external_lex_state = 2},
  [163] = {.lex_state = 0, .external_lex_state = 2},
  [164] = {.lex_state = 0, .external_lex_state = 2},
  [165] = {.lex_state = 0, .external_lex_state = 2},
  [166] = {.lex_state = 0, .external_lex_state = 2},
  [167] = {.lex_state = 136, .external_lex_state = 2},
  [168] = {.lex_state = 136, .external_lex_state = 2},
  [169] = {.lex_state = 0, .external_lex_state = 2},
  [170] = {.lex_state = 136, .external_lex_state = 2},
  [171] = {.lex_state = 136, .external_lex_state = 2},
  [172] = {.lex_state = 136, .external_lex_state = 2},
  [173] = {.lex_state = 136, .external_lex_state = 2},
  [174] = {.lex_state = 136, .external_lex_state = 2},
  [175] = {.lex_state = 136, .external_lex_state = 2},
  [176] = {.lex_state = 136, .external_lex_state = 2},
  [177] = {.lex_state = 136, .external_lex_state = 2},
  [178] = {.lex_state = 136, .external_lex_state = 2},
  [179] = {.lex_state = 136, .external_lex_state = 2},
  [180] = {.lex_state = 136, .external_lex_state = 2},
  [181] = {.lex_state = 136, .external_lex_state = 2},
  [182] = {.lex_state = 136, .external_lex_state = 2},
  [183] = {.lex_state = 136, .external_lex_state = 2},
  [184] = {.lex_state = 136, .external_lex_state = 2},
  [185] = {.lex_state = 136, .external_lex_state = 2},
  [186] = {.lex_state = 136, .external_lex_state = 2},
  [187] = {.lex_state = 136, .external_lex_state = 2},
  [188] = {.lex_state = 136, .external_lex_state = 2},
  [189] = {.lex_state = 136, .external_lex_state = 2},
  [190] = {.lex_state = 136, .external_lex_state = 2},
  [191] = {.lex_state = 136, .external_lex_state = 2},
  [192] = {.lex_state = 0, .external_lex_state = 2},
  [193] = {.lex_state = 136, .external_lex_state = 2},
  [194] = {.lex_state = 136, .external_lex_state = 2},
  [195] = {.lex_state = 136, .external_lex_state = 2},
  [196] = {.lex_state = 136, .external_lex_state = 2},
  [197] = {.lex_state = 136, .external_lex_state = 2},
  [198] = {.lex_state = 136, .external_lex_state = 2},
  [199] = {.lex_state = 136, .external_lex_state = 2},
  [200] = {.lex_state = 136, .external_lex_state = 2},
  [201] = {.lex_state = 23, .external_lex_state = 2},
  [202] = {.lex_state = 23, .external_lex_state = 2},
  [203] = {.lex_state = 23, .external_lex_state = 2},
  [204] = {.lex_state = 23, .external_lex_state = 2},
  [205] = {.lex_state = 23, .external_lex_state = 2},
  [206] = {.lex_state = 23, .external_lex_state = 2},
  [207] = {.lex_state = 23, .external_lex_state = 2},
  [208] = {.lex_state = 23, .external_lex_state = 2},
  [209] = {.lex_state = 23, .external_lex_state = 2},
  [210] = {.lex_state = 67, .external_lex_state = 2},
  [211] = {.lex_state = 67, .external_lex_state = 2},
  [212] = {.lex_state = 67, .external_lex_state = 2},
  [213] = {.lex_state = 67, .external_lex_state = 2},
  [214] = {.lex_state = 19, .external_lex_state = 3},
  [215] = {.lex_state = 19, .external_lex_state = 3},
  [216] = {.lex_state = 19, .external_lex_state = 3},
  [217] = {.lex_state = 19, .external_lex_state = 3},
  [218] = {.lex_state = 19, .external_lex_state = 3},
  [219] = {.lex_state = 19, .external_lex_state = 3},
  [220] = {.lex_state = 19, .external_lex_state = 3},
  [221] = {.lex_state = 19, .external_lex_state = 3},
  [222] = {.lex_state = 19, .external_lex_state = 3},
  [223] = {.lex_state = 19, .external_lex_state = 3},
  [224] = {.lex_state = 19, .external_lex_state = 3},
  [225] = {.lex_state = 19, .external_lex_state = 3},
  [226] = {.lex_state = 19, .external_lex_state = 3},
  [227] = {.lex_state = 19, .external_lex_state = 3},
  [228] = {.lex_state = 19, .external_lex_state = 3},
  [229] = {.lex_state = 19, .external_lex_state = 3},
  [230] = {.lex_state = 19, .external_lex_state = 3},
  [231] = {.lex_state = 19, .external_lex_state = 3},
  [232] = {.lex_state = 19, .external_lex_state = 3},
  [233] = {.lex_state = 19, .external_lex_state = 3},
  [234] = {.lex_state = 19, .external_lex_state = 3},
  [235] = {.lex_state = 19, .external_lex_state = 3},
  [236] = {.lex_state = 19, .external_lex_state = 3},
  [237] = {.lex_state = 19, .external_lex_state = 3},
  [238] = {.lex_state = 19, .external_lex_state = 3},
  [239] = {.lex_state = 19, .external_lex_state = 3},
  [240] = {.lex_state = 19, .external_lex_state = 3},
  [241] = {.lex_state = 19, .external_lex_state = 3},
  [242] = {.lex_state = 19, .external_lex_state = 3},
  [243] = {.lex_state = 19, .external_lex_state = 3},
  [244] = {.lex_state = 19, .external_lex_state = 3},
  [245] = {.lex_state = 19, .external_lex_state = 3},
  [246] = {.lex_state = 19, .external_lex_state = 3},
  [247] = {.lex_state = 6, .external_lex_state = 2},
  [248] = {.lex_state = 67, .external_lex_state = 2},
  [249] = {.lex_state = 24, .external_lex_state = 2},
  [250] = {.lex_state = 24, .external_lex_state = 2},
  [251] = {.lex_state = 24, .external_lex_state = 2},
  [252] = {.lex_state = 24, .external_lex_state = 2},
  [253] = {.lex_state = 24, .external_lex_state = 2},
  [254] = {.lex_state = 24, .external_lex_state = 2},
  [255] = {.lex_state = 24, .external_lex_state = 2},
  [256] = {.lex_state = 24, .external_lex_state = 2},
  [257] = {.lex_state = 24, .external_lex_state = 2},
  [258] = {.lex_state = 26, .external_lex_state = 4},
  [259] = {.lex_state = 26, .external_lex_state = 4},
  [260] = {.lex_state = 24, .external_lex_state = 2},
  [261] = {.lex_state = 26, .external_lex_state = 4},
  [262] = {.lex_state = 24, .external_lex_state = 2},
  [263] = {.lex_state = 26, .external_lex_state = 4},
  [264] = {.lex_state = 24, .external_lex_state = 2},
  [265] = {.lex_state = 26, .external_lex_state = 4},
  [266] = {.lex_state = 24, .external_lex_state = 2},
  [267] = {.lex_state = 15, .external_lex_state = 2},
  [268] = {.lex_state = 24, .external_lex_state = 2},
  [269] = {.lex_state = 26, .external_lex_state = 2},
  [270] = {.lex_state = 26, .external_lex_state = 2},
  [271] = {.lex_state = 15, .external_lex_state = 2},
  [272] = {.lex_state = 26, .external_lex_state = 2},
  [273] = {.lex_state = 24, .external_lex_state = 2},
  [274] = {.lex_state = 26, .external_lex_state = 2},
  [275] = {.lex_state = 26, .external_lex_state = 2},
  [276] = {.lex_state = 26, .external_lex_state = 4},
  [277] = {.lex_state = 136, .external_lex_state = 2},
  [278] = {.lex_state = 5, .external_lex_state = 5},
  [279] = {.lex_state = 5, .external_lex_state = 5},
  [280] = {.lex_state = 0, .external_lex_state = 6},
  [281] = {.lex_state = 136, .external_lex_state = 2},
  [282] = {.lex_state = 26, .external_lex_state = 4},
  [283] = {.lex_state = 26, .external_lex_state = 2},
  [284] = {.lex_state = 0, .external_lex_state = 6},
  [285] = {.lex_state = 136, .external_lex_state = 2},
  [286] = {.lex_state = 5, .external_lex_state = 5},
  [287] = {.lex_state = 26, .external_lex_state = 4},
  [288] = {.lex_state = 26, .external_lex_state = 4},
  [289] = {.lex_state = 5, .external_lex_state = 5},
  [290] = {.lex_state = 24, .external_lex_state = 2},
  [291] = {.lex_state = 136, .external_lex_state = 2},
  [292] = {.lex_state = 5, .external_lex_state = 2},
  [293] = {.lex_state = 5, .external_lex_state = 2},
  [294] = {.lex_state = 0, .external_lex_state = 2},
  [295] = {.lex_state = 16, .external_lex_state = 2},
  [296] = {.lex_state = 21, .external_lex_state = 2},
  [297] = {.lex_state = 0, .external_lex_state = 2},
  [298] = {.lex_state = 26, .external_lex_state = 2},
  [299] = {.lex_state = 133, .external_lex_state = 2},
  [300] = {.lex_state = 0, .external_lex_state = 2},
  [301] = {.lex_state = 26, .external_lex_state = 2},
  [302] = {.lex_state = 0, .external_lex_state = 2},
  [303] = {.lex_state = 0, .external_lex_state = 2},
  [304] = {.lex_state = 26, .external_lex_state = 2},
  [305] = {.lex_state = 0, .external_lex_state = 2},
  [306] = {.lex_state = 21, .external_lex_state = 2},
  [307] = {.lex_state = 16, .external_lex_state = 2},
  [308] = {.lex_state = 133, .external_lex_state = 2},
  [309] = {.lex_state = 0, .external_lex_state = 2},
  [310] = {.lex_state = 5, .external_lex_state = 5},
  [311] = {.lex_state = 5, .external_lex_state = 5},
  [312] = {.lex_state = 5, .external_lex_state = 2},
  [313] = {.lex_state = 5, .external_lex_state = 5},
  [314] = {.lex_state = 5, .external_lex_state = 2},
  [315] = {.lex_state = 5, .external_lex_state = 5},
  [316] = {.lex_state = 0, .external_lex_state = 2},
  [317] = {.lex_state = 0, .external_lex_state = 7},
  [318] = {.lex_state = 0, .external_lex_state = 2},
  [319] = {.lex_state = 0, .external_lex_state = 2},
  [320] = {.lex_state = 0, .external_lex_state = 2},
  [321] = {.lex_state = 0, .external_lex_state = 7},
  [322] = {.lex_state = 0, .external_lex_state = 2},
  [323] = {.lex_state = 0, .external_lex_state = 2},
  [324] = {.lex_state = 0, .external_lex_state = 2},
  [325] = {.lex_state = 0, .external_lex_state = 2},
  [326] = {.lex_state = 0, .external_lex_state = 2},
  [327] = {.lex_state = 0, .external_lex_state = 2},
  [328] = {.lex_state = 0, .external_lex_state = 2},
  [329] = {.lex_state = 0, .external_lex_state = 2},
  [330] = {.lex_state = 0, .external_lex_state = 2},
  [331] = {.lex_state = 134, .external_lex_state = 2},
  [332] = {.lex_state = 134, .external_lex_state = 2},
  [333] = {.lex_state = 0, .external_lex_state = 2},
  [334] = {.lex_state = 0, .external_lex_state = 2},
  [335] = {.lex_state = 0, .external_lex_state = 2},
  [336] = {.lex_state = 0, .external_lex_state = 2},
  [337] = {.lex_state = 0, .external_lex_state = 2},
  [338] = {.lex_state = 0, .external_lex_state = 2},
  [339] = {.lex_state = 0, .external_lex_state = 2},
  [340] = {.lex_state = 0, .external_lex_state = 2},
  [341] = {.lex_state = 0, .external_lex_state = 2},
  [342] = {.lex_state = 0, .external_lex_state = 2},
  [343] = {.lex_state = 0, .external_lex_state = 2},
};

enum {
  ts_external_token__start_tag_name = 0,
  ts_external_token__script_start_tag_name = 1,
  ts_external_token__style_start_tag_name = 2,
  ts_external_token__end_tag_name = 3,
  ts_external_token_erroneous_end_tag_name = 4,
  ts_external_token_SLASH_GT = 5,
  ts_external_token__implicit_end_tag = 6,
  ts_external_token_raw_text = 7,
  ts_external_token_comment = 8,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__start_tag_name] = sym__start_tag_name,
  [ts_external_token__script_start_tag_name] = sym__script_start_tag_name,
  [ts_external_token__style_start_tag_name] = sym__style_start_tag_name,
  [ts_external_token__end_tag_name] = sym__end_tag_name,
  [ts_external_token_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [ts_external_token_SLASH_GT] = anon_sym_SLASH_GT,
  [ts_external_token__implicit_end_tag] = sym__implicit_end_tag,
  [ts_external_token_raw_text] = sym_raw_text,
  [ts_external_token_comment] = sym_comment,
};

static const bool ts_external_scanner_states[8][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token__implicit_end_tag] = true,
    [ts_external_token_raw_text] = true,
    [ts_external_token_comment] = true,
  },
  [2] = {
    [ts_external_token_comment] = true,
  },
  [3] = {
    [ts_external_token__implicit_end_tag] = true,
    [ts_external_token_comment] = true,
  },
  [4] = {
    [ts_external_token_SLASH_GT] = true,
    [ts_external_token_comment] = true,
  },
  [5] = {
    [ts_external_token_raw_text] = true,
    [ts_external_token_comment] = true,
  },
  [6] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [7] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LT_BANG] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym__doctype] = ACTIONS(1),
    [sym__cf_tag_start] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_cf_tag_close] = ACTIONS(1),
    [sym_cf_true] = ACTIONS(1),
    [sym_cf_false] = ACTIONS(1),
    [sym_cf_operator] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_SLASH] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_cf_period] = ACTIONS(1),
    [sym_cf_comma] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_cf_objectkeyassign] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_set] = ACTIONS(1),
    [sym_entity] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_cf_var] = ACTIONS(1),
    [sym_cf_if_keyword] = ACTIONS(1),
    [sym_cf_elseif_keyword] = ACTIONS(1),
    [sym_cf_else_keyword] = ACTIONS(1),
    [sym_cf_function_keyword] = ACTIONS(1),
    [sym_cf_argument_keyword] = ACTIONS(1),
    [sym_cf_return_keyword] = ACTIONS(1),
    [sym__start_tag_name] = ACTIONS(1),
    [sym__script_start_tag_name] = ACTIONS(1),
    [sym__style_start_tag_name] = ACTIONS(1),
    [sym__end_tag_name] = ACTIONS(1),
    [sym_erroneous_end_tag_name] = ACTIONS(1),
    [sym__implicit_end_tag] = ACTIONS(1),
    [sym_raw_text] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_fragment] = STATE(335),
    [sym_doctype] = STATE(43),
    [sym_text] = STATE(43),
    [sym__node] = STATE(43),
    [sym_element] = STATE(43),
    [sym_script_element] = STATE(43),
    [sym_start_tag] = STATE(24),
    [sym_script_start_tag] = STATE(279),
    [sym_style_start_tag] = STATE(278),
    [sym_self_closing_tag] = STATE(198),
    [sym_style_element] = STATE(43),
    [sym_cf_hash] = STATE(43),
    [sym_cf_tag] = STATE(43),
    [aux_sym_fragment_repeat1] = STATE(43),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LT_BANG] = ACTIONS(7),
    [sym__cf_tag_start] = ACTIONS(9),
    [aux_sym_text_token1] = ACTIONS(11),
    [anon_sym_LT] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_entity] = ACTIONS(17),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 26,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(25), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      sym_cf_period,
    ACTIONS(29), 1,
      sym_cf_comma,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(33), 1,
      sym_cf_objectkeyassign,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(37), 1,
      sym_entity,
    STATE(18), 1,
      sym_cf_tag_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(47), 1,
      sym_cf_associative,
    STATE(68), 1,
      sym_cf_assignment,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(21), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(39), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(51), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    STATE(20), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [90] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(43), 1,
      aux_sym_text_token1,
    ACTIONS(50), 1,
      anon_sym_POUND,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 6,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(41), 9,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [143] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(62), 1,
      sym_entity,
    STATE(16), 1,
      sym_cf_tag_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(60), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(64), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(11), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [202] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 2,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 7,
      sym_cf_operator,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_RPAREN,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [249] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(70), 1,
      anon_sym_POUND,
    ACTIONS(72), 1,
      anon_sym_LBRACE,
    ACTIONS(74), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 2,
      anon_sym_GT,
      sym_cf_operator,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 7,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_cf_attribute_name,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [296] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(79), 1,
      sym_entity,
    STATE(15), 1,
      sym_cf_tag_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(77), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(81), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(14), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [355] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(85), 1,
      anon_sym_LT_BANG,
    ACTIONS(88), 1,
      sym__cf_tag_start,
    ACTIONS(91), 1,
      aux_sym_text_token1,
    ACTIONS(94), 1,
      anon_sym_LT,
    ACTIONS(97), 1,
      anon_sym_POUND,
    ACTIONS(100), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(103), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(83), 3,
      ts_builtin_sym_end,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [409] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(70), 1,
      anon_sym_POUND,
    ACTIONS(72), 1,
      anon_sym_LBRACE,
    ACTIONS(74), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 2,
      anon_sym_GT,
      sym_cf_operator,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_cf_attribute_name,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [455] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 3,
      anon_sym_SLASH,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 5,
      anon_sym_GT,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [501] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(81), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(77), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [552] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(109), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(34), 1,
      sym_cf_tag_end,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(107), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(36), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [607] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(113), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(111), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [658] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(117), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(115), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [709] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(119), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(115), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(117), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(13), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [762] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(79), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(77), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(81), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(14), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [815] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(123), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(32), 1,
      sym_cf_tag_end,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(121), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(31), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [870] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(127), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(125), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(129), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(19), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [923] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(133), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(131), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [974] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(129), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(125), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1025] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 1,
      anon_sym_LT_BANG,
    ACTIONS(137), 1,
      sym__cf_tag_start,
    ACTIONS(139), 1,
      aux_sym_text_token1,
    ACTIONS(141), 1,
      anon_sym_LT,
    ACTIONS(143), 1,
      anon_sym_LT_SLASH,
    ACTIONS(145), 1,
      anon_sym_POUND,
    ACTIONS(147), 1,
      sym_entity,
    ACTIONS(149), 1,
      sym__implicit_end_tag,
    STATE(23), 1,
      sym_start_tag,
    STATE(218), 1,
      sym_self_closing_tag,
    STATE(242), 1,
      sym_end_tag,
    STATE(286), 1,
      sym_script_start_tag,
    STATE(289), 1,
      sym_style_start_tag,
    STATE(35), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1079] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(25), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      sym_cf_period,
    ACTIONS(29), 1,
      sym_cf_comma,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(33), 1,
      sym_cf_objectkeyassign,
    STATE(47), 1,
      sym_cf_associative,
    STATE(68), 1,
      sym_cf_assignment,
    STATE(51), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(151), 7,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
  [1127] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 1,
      anon_sym_LT_BANG,
    ACTIONS(137), 1,
      sym__cf_tag_start,
    ACTIONS(139), 1,
      aux_sym_text_token1,
    ACTIONS(141), 1,
      anon_sym_LT,
    ACTIONS(143), 1,
      anon_sym_LT_SLASH,
    ACTIONS(145), 1,
      anon_sym_POUND,
    ACTIONS(155), 1,
      sym_entity,
    ACTIONS(157), 1,
      sym__implicit_end_tag,
    STATE(23), 1,
      sym_start_tag,
    STATE(218), 1,
      sym_self_closing_tag,
    STATE(224), 1,
      sym_end_tag,
    STATE(286), 1,
      sym_script_start_tag,
    STATE(289), 1,
      sym_style_start_tag,
    STATE(21), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1181] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 1,
      anon_sym_LT_BANG,
    ACTIONS(137), 1,
      sym__cf_tag_start,
    ACTIONS(139), 1,
      aux_sym_text_token1,
    ACTIONS(141), 1,
      anon_sym_LT,
    ACTIONS(145), 1,
      anon_sym_POUND,
    ACTIONS(159), 1,
      anon_sym_LT_SLASH,
    ACTIONS(161), 1,
      sym_entity,
    ACTIONS(163), 1,
      sym__implicit_end_tag,
    STATE(23), 1,
      sym_start_tag,
    STATE(191), 1,
      sym_end_tag,
    STATE(218), 1,
      sym_self_closing_tag,
    STATE(286), 1,
      sym_script_start_tag,
    STATE(289), 1,
      sym_style_start_tag,
    STATE(28), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1235] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(29), 1,
      sym_cf_comma,
    STATE(47), 1,
      sym_cf_associative,
    STATE(68), 1,
      sym_cf_assignment,
    STATE(51), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(151), 9,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      anon_sym_LPAREN,
  [1275] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    STATE(47), 1,
      sym_cf_associative,
    STATE(68), 1,
      sym_cf_assignment,
    STATE(51), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(151), 10,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [1313] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(165), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 2,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 4,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1357] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 1,
      anon_sym_LT_BANG,
    ACTIONS(137), 1,
      sym__cf_tag_start,
    ACTIONS(139), 1,
      aux_sym_text_token1,
    ACTIONS(141), 1,
      anon_sym_LT,
    ACTIONS(145), 1,
      anon_sym_POUND,
    ACTIONS(147), 1,
      sym_entity,
    ACTIONS(159), 1,
      anon_sym_LT_SLASH,
    ACTIONS(168), 1,
      sym__implicit_end_tag,
    STATE(23), 1,
      sym_start_tag,
    STATE(180), 1,
      sym_end_tag,
    STATE(218), 1,
      sym_self_closing_tag,
    STATE(286), 1,
      sym_script_start_tag,
    STATE(289), 1,
      sym_style_start_tag,
    STATE(35), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1411] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      sym_cf_period,
    ACTIONS(29), 1,
      sym_cf_comma,
    STATE(47), 1,
      sym_cf_associative,
    STATE(68), 1,
      sym_cf_assignment,
    STATE(51), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(151), 8,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
  [1453] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_POUND,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(57), 1,
      anon_sym_LPAREN,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(48), 2,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 4,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1497] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(107), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1546] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(109), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(107), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(36), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1595] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(170), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1644] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(174), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(172), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(33), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1693] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(176), 1,
      anon_sym_LT_BANG,
    ACTIONS(179), 1,
      sym__cf_tag_start,
    ACTIONS(182), 1,
      aux_sym_text_token1,
    ACTIONS(185), 1,
      anon_sym_LT,
    ACTIONS(188), 1,
      anon_sym_POUND,
    ACTIONS(191), 1,
      sym_entity,
    STATE(23), 1,
      sym_start_tag,
    STATE(218), 1,
      sym_self_closing_tag,
    STATE(286), 1,
      sym_script_start_tag,
    STATE(289), 1,
      sym_style_start_tag,
    ACTIONS(83), 2,
      sym__implicit_end_tag,
      anon_sym_LT_SLASH,
    STATE(35), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1742] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    ACTIONS(172), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1791] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    ACTIONS(194), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1839] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    ACTIONS(196), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1887] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    ACTIONS(198), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1935] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    ACTIONS(200), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1983] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(194), 1,
      sym_cf_tag_close,
    ACTIONS(202), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(40), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [2031] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(198), 1,
      sym_cf_tag_close,
    ACTIONS(204), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(38), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [2079] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(105), 1,
      sym_entity,
    ACTIONS(206), 1,
      ts_builtin_sym_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(8), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [2127] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(208), 1,
      sym_cf_tag_close,
    ACTIONS(210), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(37), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [2175] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      sym__cf_tag_start,
    ACTIONS(11), 1,
      aux_sym_text_token1,
    ACTIONS(13), 1,
      anon_sym_LT,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(212), 1,
      sym_cf_tag_close,
    ACTIONS(214), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(198), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_style_start_tag,
    STATE(279), 1,
      sym_script_start_tag,
    STATE(39), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [2223] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(216), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2249] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(220), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2275] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(224), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2301] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(228), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2327] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(232), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2353] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(238), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(236), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2379] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(242), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(240), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2405] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(246), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(244), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2431] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(248), 11,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2457] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(258), 1,
      sym_cf_var,
    ACTIONS(252), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(122), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2494] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(262), 1,
      sym_cf_var,
    ACTIONS(260), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(120), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2531] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(268), 1,
      anon_sym_RPAREN,
    ACTIONS(264), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(157), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2568] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(272), 1,
      anon_sym_RPAREN,
    ACTIONS(270), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(161), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2605] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(276), 1,
      anon_sym_RPAREN,
    ACTIONS(274), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(164), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2642] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(280), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(141), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2676] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_DQUOTE,
    ACTIONS(290), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(143), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2710] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(294), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(111), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2744] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(296), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(159), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2778] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(300), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(123), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2812] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(302), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(112), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2846] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(304), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(125), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2880] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(306), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(127), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2914] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      aux_sym_text_token1,
    ACTIONS(312), 1,
      anon_sym_POUND,
    ACTIONS(314), 1,
      anon_sym_LBRACE,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    ACTIONS(310), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(22), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2948] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(318), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(166), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2982] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      aux_sym_text_token1,
    ACTIONS(312), 1,
      anon_sym_POUND,
    ACTIONS(314), 1,
      anon_sym_LBRACE,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    ACTIONS(320), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(25), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3016] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(324), 1,
      anon_sym_DQUOTE,
    ACTIONS(322), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(113), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3050] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(324), 1,
      anon_sym_DQUOTE,
    ACTIONS(326), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(124), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3084] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      aux_sym_text_token1,
    ACTIONS(312), 1,
      anon_sym_POUND,
    ACTIONS(314), 1,
      anon_sym_LBRACE,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    ACTIONS(328), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(29), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3118] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(330), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(148), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3152] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(332), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(134), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3186] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(334), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(149), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3220] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(336), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(150), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3254] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(338), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(151), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3288] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(340), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(147), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3322] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(342), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(135), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3356] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(344), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(136), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3390] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(348), 1,
      anon_sym_DQUOTE,
    ACTIONS(346), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(156), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3424] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(350), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(139), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3458] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(352), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(158), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3492] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      aux_sym_text_token1,
    ACTIONS(312), 1,
      anon_sym_POUND,
    ACTIONS(314), 1,
      anon_sym_LBRACE,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    ACTIONS(354), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(2), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3526] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(146), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3560] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_DQUOTE,
    ACTIONS(358), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(145), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3594] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(324), 1,
      anon_sym_DQUOTE,
    ACTIONS(360), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(117), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3628] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(324), 1,
      anon_sym_DQUOTE,
    ACTIONS(362), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(118), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3662] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 1,
      aux_sym_text_token1,
    ACTIONS(282), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LBRACE,
    ACTIONS(288), 1,
      anon_sym_LPAREN,
    ACTIONS(324), 1,
      anon_sym_DQUOTE,
    ACTIONS(364), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(119), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3696] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      aux_sym_text_token1,
    ACTIONS(312), 1,
      anon_sym_POUND,
    ACTIONS(314), 1,
      anon_sym_LBRACE,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    ACTIONS(366), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(26), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3730] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(368), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(154), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3764] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3798] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(372), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(153), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3832] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(374), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(133), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3866] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(376), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(137), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3900] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(378), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(138), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3934] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(380), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(140), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3968] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_DQUOTE,
    ACTIONS(382), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(144), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4002] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(386), 1,
      anon_sym_DQUOTE,
    ACTIONS(384), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(163), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4036] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(388), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(165), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4070] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(390), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(155), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4104] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(298), 1,
      anon_sym_DQUOTE,
    ACTIONS(392), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(152), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4138] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(394), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4172] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(396), 1,
      anon_sym_DQUOTE,
    ACTIONS(384), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(163), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4206] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(398), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4240] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(254), 1,
      anon_sym_DQUOTE,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(400), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(121), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4274] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(402), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(162), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4308] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(266), 1,
      anon_sym_DQUOTE,
    ACTIONS(404), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(160), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4342] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(66), 1,
      aux_sym_text_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(46), 2,
      sym_cf_true,
      sym_cf_false,
    STATE(142), 9,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_function_call,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4376] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(406), 1,
      anon_sym_GT,
    ACTIONS(408), 1,
      anon_sym_SLASH,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(414), 1,
      sym_cf_period,
    ACTIONS(416), 1,
      sym_cf_comma,
    ACTIONS(418), 1,
      sym_cf_objectkeyassign,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(194), 1,
      sym_cf_tag_selfclose_end,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4420] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 7,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4452] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(424), 1,
      sym_cf_operator,
    ACTIONS(426), 1,
      sym_cf_period,
    ACTIONS(428), 1,
      sym_cf_comma,
    STATE(89), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    ACTIONS(151), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 5,
      anon_sym_LBRACK,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [4486] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_EQ,
    ACTIONS(232), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4508] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(246), 1,
      anon_sym_EQ,
    ACTIONS(244), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4530] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 1,
      anon_sym_EQ,
    ACTIONS(224), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4552] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(424), 1,
      sym_cf_operator,
    ACTIONS(428), 1,
      sym_cf_comma,
    STATE(89), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    ACTIONS(151), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [4584] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(424), 1,
      sym_cf_operator,
    ACTIONS(426), 1,
      sym_cf_period,
    ACTIONS(428), 1,
      sym_cf_comma,
    ACTIONS(430), 1,
      anon_sym_LBRACK,
    ACTIONS(432), 1,
      sym_cf_objectkeyassign,
    STATE(89), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    ACTIONS(151), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    ACTIONS(153), 2,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4624] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(424), 1,
      sym_cf_operator,
    STATE(89), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    ACTIONS(151), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [4654] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(414), 1,
      sym_cf_period,
    ACTIONS(416), 1,
      sym_cf_comma,
    ACTIONS(418), 1,
      sym_cf_objectkeyassign,
    ACTIONS(434), 1,
      anon_sym_GT,
    ACTIONS(436), 1,
      anon_sym_SLASH,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(235), 1,
      sym_cf_tag_selfclose_end,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4698] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(414), 1,
      sym_cf_period,
    ACTIONS(416), 1,
      sym_cf_comma,
    ACTIONS(418), 1,
      sym_cf_objectkeyassign,
    ACTIONS(434), 1,
      anon_sym_GT,
    ACTIONS(436), 1,
      anon_sym_SLASH,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(220), 1,
      sym_cf_tag_selfclose_end,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4742] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(406), 1,
      anon_sym_GT,
    ACTIONS(408), 1,
      anon_sym_SLASH,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(414), 1,
      sym_cf_period,
    ACTIONS(416), 1,
      sym_cf_comma,
    ACTIONS(418), 1,
      sym_cf_objectkeyassign,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(183), 1,
      sym_cf_tag_selfclose_end,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4786] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 4,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4824] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(424), 1,
      sym_cf_operator,
    ACTIONS(426), 1,
      sym_cf_period,
    ACTIONS(428), 1,
      sym_cf_comma,
    ACTIONS(430), 1,
      anon_sym_LBRACK,
    ACTIONS(432), 1,
      sym_cf_objectkeyassign,
    ACTIONS(444), 1,
      anon_sym_LPAREN,
    ACTIONS(446), 1,
      sym_cf_attribute_name,
    STATE(89), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    ACTIONS(442), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4866] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 6,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4900] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 1,
      anon_sym_EQ,
    ACTIONS(248), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4922] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(420), 1,
      sym_cf_operator,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 8,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4952] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      anon_sym_EQ,
    ACTIONS(228), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4974] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 1,
      anon_sym_EQ,
    ACTIONS(216), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [4996] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 1,
      anon_sym_EQ,
    ACTIONS(220), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [5018] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(242), 1,
      anon_sym_EQ,
    ACTIONS(240), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [5040] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(238), 1,
      anon_sym_EQ,
    ACTIONS(236), 13,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [5062] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(414), 1,
      sym_cf_period,
    ACTIONS(416), 1,
      sym_cf_comma,
    ACTIONS(418), 1,
      sym_cf_objectkeyassign,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LPAREN,
  [5099] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      anon_sym_GT,
    ACTIONS(448), 1,
      sym_cf_operator,
    STATE(83), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5128] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      anon_sym_GT,
    ACTIONS(448), 1,
      sym_cf_operator,
    ACTIONS(450), 1,
      sym_cf_period,
    ACTIONS(452), 1,
      sym_cf_comma,
    STATE(83), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 5,
      anon_sym_LBRACK,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5161] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      anon_sym_GT,
    ACTIONS(448), 1,
      sym_cf_operator,
    ACTIONS(452), 1,
      sym_cf_comma,
    STATE(83), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(153), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5192] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(416), 1,
      sym_cf_comma,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 6,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [5223] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(410), 1,
      sym_cf_operator,
    ACTIONS(414), 1,
      sym_cf_period,
    ACTIONS(416), 1,
      sym_cf_comma,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 5,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [5256] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(151), 1,
      anon_sym_GT,
    ACTIONS(430), 1,
      anon_sym_LBRACK,
    ACTIONS(448), 1,
      sym_cf_operator,
    ACTIONS(450), 1,
      sym_cf_period,
    ACTIONS(452), 1,
      sym_cf_comma,
    ACTIONS(454), 1,
      sym_cf_objectkeyassign,
    STATE(83), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    ACTIONS(153), 2,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5295] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(410), 1,
      sym_cf_operator,
    STATE(95), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 7,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [5324] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(430), 1,
      anon_sym_LBRACK,
    ACTIONS(442), 1,
      anon_sym_GT,
    ACTIONS(444), 1,
      anon_sym_LPAREN,
    ACTIONS(446), 1,
      sym_cf_attribute_name,
    ACTIONS(448), 1,
      sym_cf_operator,
    ACTIONS(450), 1,
      sym_cf_period,
    ACTIONS(452), 1,
      sym_cf_comma,
    ACTIONS(454), 1,
      sym_cf_objectkeyassign,
    STATE(83), 1,
      sym_cf_assignment,
    STATE(205), 1,
      sym_cf_associative,
    STATE(206), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5365] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(456), 1,
      sym_cf_operator,
    ACTIONS(458), 1,
      sym_cf_period,
    ACTIONS(460), 1,
      sym_cf_comma,
    ACTIONS(462), 1,
      sym_cf_objectkeyassign,
    ACTIONS(464), 1,
      anon_sym_DQUOTE,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5403] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(456), 1,
      sym_cf_operator,
    ACTIONS(458), 1,
      sym_cf_period,
    ACTIONS(460), 1,
      sym_cf_comma,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 4,
      anon_sym_LBRACK,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [5435] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(456), 1,
      sym_cf_operator,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [5463] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(456), 1,
      sym_cf_operator,
    ACTIONS(460), 1,
      sym_cf_comma,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 5,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [5493] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(456), 1,
      sym_cf_operator,
    ACTIONS(458), 1,
      sym_cf_period,
    ACTIONS(460), 1,
      sym_cf_comma,
    ACTIONS(462), 1,
      sym_cf_objectkeyassign,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    ACTIONS(151), 2,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5529] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    ACTIONS(472), 1,
      sym_cf_objectkeyassign,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    ACTIONS(151), 2,
      anon_sym_POUND,
      anon_sym_LPAREN,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5565] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(466), 1,
      sym_cf_operator,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 6,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [5593] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(474), 1,
      anon_sym_RBRACK,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5631] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 4,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [5663] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_EQ,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(470), 1,
      sym_cf_comma,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(151), 5,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [5693] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    ACTIONS(472), 1,
      sym_cf_objectkeyassign,
    ACTIONS(476), 1,
      anon_sym_POUND,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5731] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    ACTIONS(472), 1,
      sym_cf_objectkeyassign,
    ACTIONS(478), 1,
      anon_sym_POUND,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5769] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(480), 1,
      anon_sym_RBRACE,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5807] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    ACTIONS(472), 1,
      sym_cf_objectkeyassign,
    ACTIONS(482), 1,
      anon_sym_POUND,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5845] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(456), 1,
      sym_cf_operator,
    ACTIONS(458), 1,
      sym_cf_period,
    ACTIONS(460), 1,
      sym_cf_comma,
    ACTIONS(462), 1,
      sym_cf_objectkeyassign,
    ACTIONS(484), 1,
      anon_sym_DQUOTE,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5883] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(486), 1,
      anon_sym_RPAREN,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5921] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(488), 1,
      anon_sym_RBRACK,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5959] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    ACTIONS(472), 1,
      sym_cf_objectkeyassign,
    ACTIONS(490), 1,
      anon_sym_POUND,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [5997] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(492), 1,
      anon_sym_RBRACE,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6035] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(494), 1,
      anon_sym_RPAREN,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6073] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(496), 1,
      anon_sym_RBRACE,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6111] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(456), 1,
      sym_cf_operator,
    ACTIONS(458), 1,
      sym_cf_period,
    ACTIONS(460), 1,
      sym_cf_comma,
    ACTIONS(462), 1,
      sym_cf_objectkeyassign,
    ACTIONS(498), 1,
      anon_sym_DQUOTE,
    STATE(86), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6149] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(500), 1,
      anon_sym_RPAREN,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6187] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(420), 1,
      sym_cf_operator,
    ACTIONS(422), 1,
      sym_cf_comma,
    ACTIONS(438), 1,
      sym_cf_period,
    ACTIONS(440), 1,
      sym_cf_objectkeyassign,
    ACTIONS(502), 1,
      anon_sym_RBRACK,
    STATE(64), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6225] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    ACTIONS(466), 1,
      sym_cf_operator,
    ACTIONS(468), 1,
      sym_cf_period,
    ACTIONS(470), 1,
      sym_cf_comma,
    ACTIONS(472), 1,
      sym_cf_objectkeyassign,
    ACTIONS(504), 1,
      anon_sym_POUND,
    STATE(79), 1,
      sym_cf_assignment,
    STATE(130), 1,
      sym_cf_associative,
    STATE(132), 2,
      sym_cf_parens,
      sym_cf_parens_empty,
  [6263] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(508), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(506), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6282] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(510), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6301] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(514), 1,
      anon_sym_set,
    ACTIONS(516), 1,
      sym_cf_if_keyword,
    ACTIONS(518), 1,
      sym_cf_function_keyword,
    ACTIONS(520), 1,
      sym_cf_argument_keyword,
    ACTIONS(522), 1,
      sym_cf_return_keyword,
    STATE(213), 1,
      sym_cf_if,
    STATE(196), 5,
      sym_cf_function,
      sym_cf_argument,
      sym_cf_return,
      sym_cf_ifstatement,
      sym_cf_set,
  [6330] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(526), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(524), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6349] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(530), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(528), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6368] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(534), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(532), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6387] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(538), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(536), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6406] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(542), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(540), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6425] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(546), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(544), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6444] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(550), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(548), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6463] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(554), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(552), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6482] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(558), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(556), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6501] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(216), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6520] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(562), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(560), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6539] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(566), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(564), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6558] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(570), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(568), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6577] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(574), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(572), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6596] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(578), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(576), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6615] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(582), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(580), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6634] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(586), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(584), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6653] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(590), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(588), 6,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6672] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(594), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(592), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6691] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(598), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(596), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6710] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(602), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(600), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6729] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(606), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(604), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6748] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(516), 1,
      sym_cf_if_keyword,
    ACTIONS(608), 1,
      anon_sym_set,
    ACTIONS(610), 1,
      sym_cf_function_keyword,
    ACTIONS(612), 1,
      sym_cf_argument_keyword,
    ACTIONS(614), 1,
      sym_cf_return_keyword,
    STATE(212), 1,
      sym_cf_if,
    STATE(221), 5,
      sym_cf_function,
      sym_cf_argument,
      sym_cf_return,
      sym_cf_ifstatement,
      sym_cf_set,
  [6777] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(618), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(616), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6796] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(622), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(620), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6815] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(626), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(624), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6834] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(630), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(628), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6853] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(634), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(632), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6872] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(638), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(636), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6891] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(642), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(640), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6910] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(646), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(644), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [6929] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(226), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [6947] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(230), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [6965] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(216), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(218), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [6983] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(242), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [7001] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(220), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(222), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [7019] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(236), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(238), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [7037] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(232), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(234), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [7055] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(246), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [7073] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(248), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(250), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [7091] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(648), 1,
      sym__cf_tag_start,
    ACTIONS(650), 1,
      sym_cf_tag_close,
    ACTIONS(652), 1,
      anon_sym_RBRACE,
    ACTIONS(654), 1,
      sym_cf_elseif_keyword,
    ACTIONS(656), 1,
      sym_cf_else_keyword,
    STATE(188), 1,
      sym_cf_if_end,
    STATE(277), 1,
      sym_cf_else,
    STATE(248), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [7120] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(648), 1,
      sym__cf_tag_start,
    ACTIONS(654), 1,
      sym_cf_elseif_keyword,
    ACTIONS(656), 1,
      sym_cf_else_keyword,
    ACTIONS(658), 1,
      sym_cf_tag_close,
    ACTIONS(660), 1,
      anon_sym_RBRACE,
    STATE(233), 1,
      sym_cf_if_end,
    STATE(291), 1,
      sym_cf_else,
    STATE(248), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [7149] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(648), 1,
      sym__cf_tag_start,
    ACTIONS(654), 1,
      sym_cf_elseif_keyword,
    ACTIONS(656), 1,
      sym_cf_else_keyword,
    ACTIONS(658), 1,
      sym_cf_tag_close,
    ACTIONS(660), 1,
      anon_sym_RBRACE,
    STATE(243), 1,
      sym_cf_if_end,
    STATE(285), 1,
      sym_cf_else,
    STATE(211), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [7178] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(648), 1,
      sym__cf_tag_start,
    ACTIONS(650), 1,
      sym_cf_tag_close,
    ACTIONS(652), 1,
      anon_sym_RBRACE,
    ACTIONS(654), 1,
      sym_cf_elseif_keyword,
    ACTIONS(656), 1,
      sym_cf_else_keyword,
    STATE(177), 1,
      sym_cf_if_end,
    STATE(281), 1,
      sym_cf_else,
    STATE(210), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [7207] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(534), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(532), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7223] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(578), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(576), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7239] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(634), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(632), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7255] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(602), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(600), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7271] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(638), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(636), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7287] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(618), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(616), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7303] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(622), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(620), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7319] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(630), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(628), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7335] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(646), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(644), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7351] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(626), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(624), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7367] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(606), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(604), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7383] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(642), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(640), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7399] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(582), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(580), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7415] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(530), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(528), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7431] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(664), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(662), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7447] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(598), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(596), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7463] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(542), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(540), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7479] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(216), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7495] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(510), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7511] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(594), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(592), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7527] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(526), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(524), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7543] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(574), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(572), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7559] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(538), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(536), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7575] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(508), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(506), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7591] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(546), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(544), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7607] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(550), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(548), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7623] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(570), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(568), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7639] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(566), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(564), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7655] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(562), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(560), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7671] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(554), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(552), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7687] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(586), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(584), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7703] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(668), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(666), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7719] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(558), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(556), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [7735] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(670), 3,
      aux_sym_text_token1,
      sym_cf_true,
      sym_cf_false,
    ACTIONS(672), 4,
      anon_sym_POUND,
      anon_sym_LBRACE,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [7750] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(674), 1,
      sym__cf_tag_start,
    ACTIONS(679), 1,
      sym_cf_elseif_keyword,
    ACTIONS(682), 1,
      sym_cf_else_keyword,
    ACTIONS(677), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(248), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [7771] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_GT,
    ACTIONS(408), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(173), 1,
      sym_cf_tag_selfclose_end,
    STATE(255), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7791] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_GT,
    ACTIONS(408), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(175), 1,
      sym_cf_tag_selfclose_end,
    STATE(254), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7811] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 1,
      anon_sym_GT,
    ACTIONS(436), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(226), 1,
      sym_cf_tag_selfclose_end,
    STATE(257), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7831] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 1,
      anon_sym_GT,
    ACTIONS(436), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(244), 1,
      sym_cf_tag_selfclose_end,
    STATE(257), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7851] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 1,
      anon_sym_GT,
    ACTIONS(436), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(236), 1,
      sym_cf_tag_selfclose_end,
    STATE(251), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7871] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_GT,
    ACTIONS(408), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(186), 1,
      sym_cf_tag_selfclose_end,
    STATE(257), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7891] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_GT,
    ACTIONS(408), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(185), 1,
      sym_cf_tag_selfclose_end,
    STATE(257), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7911] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 1,
      anon_sym_GT,
    ACTIONS(436), 1,
      anon_sym_SLASH,
    ACTIONS(684), 1,
      sym_cf_attribute_name,
    STATE(238), 1,
      sym_cf_tag_selfclose_end,
    STATE(252), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7931] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(688), 1,
      sym_cf_attribute_name,
    ACTIONS(686), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(257), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7946] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(691), 1,
      anon_sym_GT,
    ACTIONS(693), 1,
      anon_sym_SLASH_GT,
    ACTIONS(695), 1,
      sym_attribute_name,
    STATE(263), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7963] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(695), 1,
      sym_attribute_name,
    ACTIONS(697), 1,
      anon_sym_GT,
    ACTIONS(699), 1,
      anon_sym_SLASH_GT,
    STATE(258), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7980] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(701), 1,
      sym_cf_attribute_name,
    STATE(42), 1,
      sym_cf_tag_end,
    STATE(273), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7997] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(695), 1,
      sym_attribute_name,
    ACTIONS(697), 1,
      anon_sym_GT,
    ACTIONS(703), 1,
      anon_sym_SLASH_GT,
    STATE(265), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8014] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(701), 1,
      sym_cf_attribute_name,
    STATE(44), 1,
      sym_cf_tag_end,
    STATE(264), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [8031] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(707), 1,
      sym_attribute_name,
    ACTIONS(705), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(263), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8046] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(701), 1,
      sym_cf_attribute_name,
    STATE(41), 1,
      sym_cf_tag_end,
    STATE(273), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [8063] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(691), 1,
      anon_sym_GT,
    ACTIONS(695), 1,
      sym_attribute_name,
    ACTIONS(710), 1,
      anon_sym_SLASH_GT,
    STATE(263), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8080] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(701), 1,
      sym_cf_attribute_name,
    STATE(45), 1,
      sym_cf_tag_end,
    STATE(260), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [8097] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(712), 1,
      anon_sym_DQUOTE,
    ACTIONS(714), 1,
      sym_attribute_value,
    ACTIONS(716), 1,
      anon_sym_SQUOTE,
    STATE(282), 1,
      sym_quoted_attribute_value,
  [8113] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(720), 1,
      anon_sym_EQ,
    ACTIONS(718), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_attribute_name,
  [8125] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(722), 1,
      anon_sym_GT,
    ACTIONS(724), 1,
      sym_attribute_name,
    STATE(274), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8139] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(705), 1,
      anon_sym_GT,
    ACTIONS(726), 1,
      sym_attribute_name,
    STATE(270), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8153] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(729), 1,
      anon_sym_DQUOTE,
    ACTIONS(731), 1,
      sym_attribute_value,
    ACTIONS(733), 1,
      anon_sym_SQUOTE,
    STATE(298), 1,
      sym_quoted_attribute_value,
  [8169] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(724), 1,
      sym_attribute_name,
    ACTIONS(735), 1,
      anon_sym_GT,
    STATE(275), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8183] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(686), 1,
      anon_sym_GT,
    ACTIONS(737), 1,
      sym_cf_attribute_name,
    STATE(273), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [8197] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(724), 1,
      sym_attribute_name,
    ACTIONS(740), 1,
      anon_sym_GT,
    STATE(270), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8211] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(724), 1,
      sym_attribute_name,
    ACTIONS(742), 1,
      anon_sym_GT,
    STATE(270), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [8225] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(746), 1,
      anon_sym_EQ,
    ACTIONS(744), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [8237] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(650), 1,
      sym_cf_tag_close,
    ACTIONS(652), 1,
      anon_sym_RBRACE,
    STATE(195), 1,
      sym_cf_if_end,
  [8250] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_LT_SLASH,
    ACTIONS(748), 1,
      sym_raw_text,
    STATE(168), 1,
      sym_end_tag,
  [8263] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_LT_SLASH,
    ACTIONS(750), 1,
      sym_raw_text,
    STATE(189), 1,
      sym_end_tag,
  [8276] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(752), 1,
      sym__start_tag_name,
    ACTIONS(754), 1,
      sym__script_start_tag_name,
    ACTIONS(756), 1,
      sym__style_start_tag_name,
  [8289] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(650), 1,
      sym_cf_tag_close,
    ACTIONS(652), 1,
      anon_sym_RBRACE,
    STATE(188), 1,
      sym_cf_if_end,
  [8302] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(758), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [8311] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(760), 1,
      anon_sym_EQ,
    ACTIONS(744), 2,
      anon_sym_GT,
      sym_attribute_name,
  [8322] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(754), 1,
      sym__script_start_tag_name,
    ACTIONS(756), 1,
      sym__style_start_tag_name,
    ACTIONS(762), 1,
      sym__start_tag_name,
  [8335] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(658), 1,
      sym_cf_tag_close,
    ACTIONS(660), 1,
      anon_sym_RBRACE,
    STATE(233), 1,
      sym_cf_if_end,
  [8348] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_LT_SLASH,
    ACTIONS(764), 1,
      sym_raw_text,
    STATE(229), 1,
      sym_end_tag,
  [8361] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(766), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [8370] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(768), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [8379] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_LT_SLASH,
    ACTIONS(770), 1,
      sym_raw_text,
    STATE(232), 1,
      sym_end_tag,
  [8392] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(772), 1,
      anon_sym_EQ,
    ACTIONS(718), 2,
      anon_sym_GT,
      sym_cf_attribute_name,
  [8403] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(658), 1,
      sym_cf_tag_close,
    ACTIONS(660), 1,
      anon_sym_RBRACE,
    STATE(223), 1,
      sym_cf_if_end,
  [8416] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_LT_SLASH,
    STATE(240), 1,
      sym_end_tag,
  [8426] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_LT_SLASH,
    STATE(182), 1,
      sym_end_tag,
  [8436] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    STATE(174), 1,
      sym_cf_tag_end,
  [8446] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(774), 1,
      anon_sym_DQUOTE,
    ACTIONS(776), 1,
      aux_sym_quoted_attribute_value_token2,
  [8456] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(774), 1,
      anon_sym_SQUOTE,
    ACTIONS(778), 1,
      aux_sym_quoted_attribute_value_token1,
  [8466] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(780), 1,
      anon_sym_GT,
    STATE(225), 1,
      sym_cf_tag_end,
  [8476] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(758), 2,
      anon_sym_GT,
      sym_attribute_name,
  [8484] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(782), 1,
      aux_sym_cf_condition_token1,
    STATE(4), 1,
      sym_cf_condition,
  [8494] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(780), 1,
      anon_sym_GT,
    STATE(227), 1,
      sym_cf_tag_end,
  [8504] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(766), 2,
      anon_sym_GT,
      sym_attribute_name,
  [8512] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(784), 1,
      sym_cf_elseif_keyword,
    ACTIONS(786), 1,
      sym_cf_else_keyword,
  [8522] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(780), 1,
      anon_sym_GT,
    STATE(230), 1,
      sym_cf_tag_end,
  [8532] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(768), 2,
      anon_sym_GT,
      sym_attribute_name,
  [8540] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    STATE(171), 1,
      sym_cf_tag_end,
  [8550] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(788), 1,
      anon_sym_SQUOTE,
    ACTIONS(790), 1,
      aux_sym_quoted_attribute_value_token1,
  [8560] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(788), 1,
      anon_sym_DQUOTE,
    ACTIONS(792), 1,
      aux_sym_quoted_attribute_value_token2,
  [8570] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(782), 1,
      aux_sym_cf_condition_token1,
    STATE(7), 1,
      sym_cf_condition,
  [8580] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    STATE(199), 1,
      sym_cf_tag_end,
  [8590] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(794), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [8598] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(796), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [8606] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_LT_SLASH,
    STATE(241), 1,
      sym_end_tag,
  [8616] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(798), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [8624] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_LT_SLASH,
    STATE(181), 1,
      sym_end_tag,
  [8634] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(800), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [8642] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(802), 1,
      anon_sym_GT,
  [8649] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(804), 1,
      sym__end_tag_name,
  [8656] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(806), 1,
      sym_cf_function_keyword,
  [8663] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(808), 1,
      anon_sym_DQUOTE,
  [8670] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(810), 1,
      anon_sym_GT,
  [8677] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(812), 1,
      sym__end_tag_name,
  [8684] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(814), 1,
      sym_cf_function_keyword,
  [8691] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(816), 1,
      anon_sym_GT,
  [8698] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(818), 1,
      sym_cf_if_keyword,
  [8705] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(820), 1,
      anon_sym_GT,
  [8712] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(822), 1,
      sym_cf_function_keyword,
  [8719] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(824), 1,
      sym__doctype,
  [8726] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(784), 1,
      sym_cf_elseif_keyword,
  [8733] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(826), 1,
      anon_sym_GT,
  [8740] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(828), 1,
      anon_sym_GT,
  [8747] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(830), 1,
      aux_sym_doctype_token1,
  [8754] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(832), 1,
      aux_sym_doctype_token1,
  [8761] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(834), 1,
      sym_cf_function_keyword,
  [8768] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(836), 1,
      anon_sym_GT,
  [8775] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(838), 1,
      ts_builtin_sym_end,
  [8782] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(840), 1,
      anon_sym_GT,
  [8789] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(842), 1,
      sym_cf_function_keyword,
  [8796] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(844), 1,
      sym__doctype,
  [8803] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(846), 1,
      sym_cf_if_keyword,
  [8810] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(848), 1,
      anon_sym_SQUOTE,
  [8817] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(848), 1,
      anon_sym_DQUOTE,
  [8824] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(850), 1,
      sym_cf_function_keyword,
  [8831] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(808), 1,
      anon_sym_SQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 90,
  [SMALL_STATE(4)] = 143,
  [SMALL_STATE(5)] = 202,
  [SMALL_STATE(6)] = 249,
  [SMALL_STATE(7)] = 296,
  [SMALL_STATE(8)] = 355,
  [SMALL_STATE(9)] = 409,
  [SMALL_STATE(10)] = 455,
  [SMALL_STATE(11)] = 501,
  [SMALL_STATE(12)] = 552,
  [SMALL_STATE(13)] = 607,
  [SMALL_STATE(14)] = 658,
  [SMALL_STATE(15)] = 709,
  [SMALL_STATE(16)] = 762,
  [SMALL_STATE(17)] = 815,
  [SMALL_STATE(18)] = 870,
  [SMALL_STATE(19)] = 923,
  [SMALL_STATE(20)] = 974,
  [SMALL_STATE(21)] = 1025,
  [SMALL_STATE(22)] = 1079,
  [SMALL_STATE(23)] = 1127,
  [SMALL_STATE(24)] = 1181,
  [SMALL_STATE(25)] = 1235,
  [SMALL_STATE(26)] = 1275,
  [SMALL_STATE(27)] = 1313,
  [SMALL_STATE(28)] = 1357,
  [SMALL_STATE(29)] = 1411,
  [SMALL_STATE(30)] = 1453,
  [SMALL_STATE(31)] = 1497,
  [SMALL_STATE(32)] = 1546,
  [SMALL_STATE(33)] = 1595,
  [SMALL_STATE(34)] = 1644,
  [SMALL_STATE(35)] = 1693,
  [SMALL_STATE(36)] = 1742,
  [SMALL_STATE(37)] = 1791,
  [SMALL_STATE(38)] = 1839,
  [SMALL_STATE(39)] = 1887,
  [SMALL_STATE(40)] = 1935,
  [SMALL_STATE(41)] = 1983,
  [SMALL_STATE(42)] = 2031,
  [SMALL_STATE(43)] = 2079,
  [SMALL_STATE(44)] = 2127,
  [SMALL_STATE(45)] = 2175,
  [SMALL_STATE(46)] = 2223,
  [SMALL_STATE(47)] = 2249,
  [SMALL_STATE(48)] = 2275,
  [SMALL_STATE(49)] = 2301,
  [SMALL_STATE(50)] = 2327,
  [SMALL_STATE(51)] = 2353,
  [SMALL_STATE(52)] = 2379,
  [SMALL_STATE(53)] = 2405,
  [SMALL_STATE(54)] = 2431,
  [SMALL_STATE(55)] = 2457,
  [SMALL_STATE(56)] = 2494,
  [SMALL_STATE(57)] = 2531,
  [SMALL_STATE(58)] = 2568,
  [SMALL_STATE(59)] = 2605,
  [SMALL_STATE(60)] = 2642,
  [SMALL_STATE(61)] = 2676,
  [SMALL_STATE(62)] = 2710,
  [SMALL_STATE(63)] = 2744,
  [SMALL_STATE(64)] = 2778,
  [SMALL_STATE(65)] = 2812,
  [SMALL_STATE(66)] = 2846,
  [SMALL_STATE(67)] = 2880,
  [SMALL_STATE(68)] = 2914,
  [SMALL_STATE(69)] = 2948,
  [SMALL_STATE(70)] = 2982,
  [SMALL_STATE(71)] = 3016,
  [SMALL_STATE(72)] = 3050,
  [SMALL_STATE(73)] = 3084,
  [SMALL_STATE(74)] = 3118,
  [SMALL_STATE(75)] = 3152,
  [SMALL_STATE(76)] = 3186,
  [SMALL_STATE(77)] = 3220,
  [SMALL_STATE(78)] = 3254,
  [SMALL_STATE(79)] = 3288,
  [SMALL_STATE(80)] = 3322,
  [SMALL_STATE(81)] = 3356,
  [SMALL_STATE(82)] = 3390,
  [SMALL_STATE(83)] = 3424,
  [SMALL_STATE(84)] = 3458,
  [SMALL_STATE(85)] = 3492,
  [SMALL_STATE(86)] = 3526,
  [SMALL_STATE(87)] = 3560,
  [SMALL_STATE(88)] = 3594,
  [SMALL_STATE(89)] = 3628,
  [SMALL_STATE(90)] = 3662,
  [SMALL_STATE(91)] = 3696,
  [SMALL_STATE(92)] = 3730,
  [SMALL_STATE(93)] = 3764,
  [SMALL_STATE(94)] = 3798,
  [SMALL_STATE(95)] = 3832,
  [SMALL_STATE(96)] = 3866,
  [SMALL_STATE(97)] = 3900,
  [SMALL_STATE(98)] = 3934,
  [SMALL_STATE(99)] = 3968,
  [SMALL_STATE(100)] = 4002,
  [SMALL_STATE(101)] = 4036,
  [SMALL_STATE(102)] = 4070,
  [SMALL_STATE(103)] = 4104,
  [SMALL_STATE(104)] = 4138,
  [SMALL_STATE(105)] = 4172,
  [SMALL_STATE(106)] = 4206,
  [SMALL_STATE(107)] = 4240,
  [SMALL_STATE(108)] = 4274,
  [SMALL_STATE(109)] = 4308,
  [SMALL_STATE(110)] = 4342,
  [SMALL_STATE(111)] = 4376,
  [SMALL_STATE(112)] = 4420,
  [SMALL_STATE(113)] = 4452,
  [SMALL_STATE(114)] = 4486,
  [SMALL_STATE(115)] = 4508,
  [SMALL_STATE(116)] = 4530,
  [SMALL_STATE(117)] = 4552,
  [SMALL_STATE(118)] = 4584,
  [SMALL_STATE(119)] = 4624,
  [SMALL_STATE(120)] = 4654,
  [SMALL_STATE(121)] = 4698,
  [SMALL_STATE(122)] = 4742,
  [SMALL_STATE(123)] = 4786,
  [SMALL_STATE(124)] = 4824,
  [SMALL_STATE(125)] = 4866,
  [SMALL_STATE(126)] = 4900,
  [SMALL_STATE(127)] = 4922,
  [SMALL_STATE(128)] = 4952,
  [SMALL_STATE(129)] = 4974,
  [SMALL_STATE(130)] = 4996,
  [SMALL_STATE(131)] = 5018,
  [SMALL_STATE(132)] = 5040,
  [SMALL_STATE(133)] = 5062,
  [SMALL_STATE(134)] = 5099,
  [SMALL_STATE(135)] = 5128,
  [SMALL_STATE(136)] = 5161,
  [SMALL_STATE(137)] = 5192,
  [SMALL_STATE(138)] = 5223,
  [SMALL_STATE(139)] = 5256,
  [SMALL_STATE(140)] = 5295,
  [SMALL_STATE(141)] = 5324,
  [SMALL_STATE(142)] = 5365,
  [SMALL_STATE(143)] = 5403,
  [SMALL_STATE(144)] = 5435,
  [SMALL_STATE(145)] = 5463,
  [SMALL_STATE(146)] = 5493,
  [SMALL_STATE(147)] = 5529,
  [SMALL_STATE(148)] = 5565,
  [SMALL_STATE(149)] = 5593,
  [SMALL_STATE(150)] = 5631,
  [SMALL_STATE(151)] = 5663,
  [SMALL_STATE(152)] = 5693,
  [SMALL_STATE(153)] = 5731,
  [SMALL_STATE(154)] = 5769,
  [SMALL_STATE(155)] = 5807,
  [SMALL_STATE(156)] = 5845,
  [SMALL_STATE(157)] = 5883,
  [SMALL_STATE(158)] = 5921,
  [SMALL_STATE(159)] = 5959,
  [SMALL_STATE(160)] = 5997,
  [SMALL_STATE(161)] = 6035,
  [SMALL_STATE(162)] = 6073,
  [SMALL_STATE(163)] = 6111,
  [SMALL_STATE(164)] = 6149,
  [SMALL_STATE(165)] = 6187,
  [SMALL_STATE(166)] = 6225,
  [SMALL_STATE(167)] = 6263,
  [SMALL_STATE(168)] = 6282,
  [SMALL_STATE(169)] = 6301,
  [SMALL_STATE(170)] = 6330,
  [SMALL_STATE(171)] = 6349,
  [SMALL_STATE(172)] = 6368,
  [SMALL_STATE(173)] = 6387,
  [SMALL_STATE(174)] = 6406,
  [SMALL_STATE(175)] = 6425,
  [SMALL_STATE(176)] = 6444,
  [SMALL_STATE(177)] = 6463,
  [SMALL_STATE(178)] = 6482,
  [SMALL_STATE(179)] = 6501,
  [SMALL_STATE(180)] = 6520,
  [SMALL_STATE(181)] = 6539,
  [SMALL_STATE(182)] = 6558,
  [SMALL_STATE(183)] = 6577,
  [SMALL_STATE(184)] = 6596,
  [SMALL_STATE(185)] = 6615,
  [SMALL_STATE(186)] = 6634,
  [SMALL_STATE(187)] = 6653,
  [SMALL_STATE(188)] = 6672,
  [SMALL_STATE(189)] = 6691,
  [SMALL_STATE(190)] = 6710,
  [SMALL_STATE(191)] = 6729,
  [SMALL_STATE(192)] = 6748,
  [SMALL_STATE(193)] = 6777,
  [SMALL_STATE(194)] = 6796,
  [SMALL_STATE(195)] = 6815,
  [SMALL_STATE(196)] = 6834,
  [SMALL_STATE(197)] = 6853,
  [SMALL_STATE(198)] = 6872,
  [SMALL_STATE(199)] = 6891,
  [SMALL_STATE(200)] = 6910,
  [SMALL_STATE(201)] = 6929,
  [SMALL_STATE(202)] = 6947,
  [SMALL_STATE(203)] = 6965,
  [SMALL_STATE(204)] = 6983,
  [SMALL_STATE(205)] = 7001,
  [SMALL_STATE(206)] = 7019,
  [SMALL_STATE(207)] = 7037,
  [SMALL_STATE(208)] = 7055,
  [SMALL_STATE(209)] = 7073,
  [SMALL_STATE(210)] = 7091,
  [SMALL_STATE(211)] = 7120,
  [SMALL_STATE(212)] = 7149,
  [SMALL_STATE(213)] = 7178,
  [SMALL_STATE(214)] = 7207,
  [SMALL_STATE(215)] = 7223,
  [SMALL_STATE(216)] = 7239,
  [SMALL_STATE(217)] = 7255,
  [SMALL_STATE(218)] = 7271,
  [SMALL_STATE(219)] = 7287,
  [SMALL_STATE(220)] = 7303,
  [SMALL_STATE(221)] = 7319,
  [SMALL_STATE(222)] = 7335,
  [SMALL_STATE(223)] = 7351,
  [SMALL_STATE(224)] = 7367,
  [SMALL_STATE(225)] = 7383,
  [SMALL_STATE(226)] = 7399,
  [SMALL_STATE(227)] = 7415,
  [SMALL_STATE(228)] = 7431,
  [SMALL_STATE(229)] = 7447,
  [SMALL_STATE(230)] = 7463,
  [SMALL_STATE(231)] = 7479,
  [SMALL_STATE(232)] = 7495,
  [SMALL_STATE(233)] = 7511,
  [SMALL_STATE(234)] = 7527,
  [SMALL_STATE(235)] = 7543,
  [SMALL_STATE(236)] = 7559,
  [SMALL_STATE(237)] = 7575,
  [SMALL_STATE(238)] = 7591,
  [SMALL_STATE(239)] = 7607,
  [SMALL_STATE(240)] = 7623,
  [SMALL_STATE(241)] = 7639,
  [SMALL_STATE(242)] = 7655,
  [SMALL_STATE(243)] = 7671,
  [SMALL_STATE(244)] = 7687,
  [SMALL_STATE(245)] = 7703,
  [SMALL_STATE(246)] = 7719,
  [SMALL_STATE(247)] = 7735,
  [SMALL_STATE(248)] = 7750,
  [SMALL_STATE(249)] = 7771,
  [SMALL_STATE(250)] = 7791,
  [SMALL_STATE(251)] = 7811,
  [SMALL_STATE(252)] = 7831,
  [SMALL_STATE(253)] = 7851,
  [SMALL_STATE(254)] = 7871,
  [SMALL_STATE(255)] = 7891,
  [SMALL_STATE(256)] = 7911,
  [SMALL_STATE(257)] = 7931,
  [SMALL_STATE(258)] = 7946,
  [SMALL_STATE(259)] = 7963,
  [SMALL_STATE(260)] = 7980,
  [SMALL_STATE(261)] = 7997,
  [SMALL_STATE(262)] = 8014,
  [SMALL_STATE(263)] = 8031,
  [SMALL_STATE(264)] = 8046,
  [SMALL_STATE(265)] = 8063,
  [SMALL_STATE(266)] = 8080,
  [SMALL_STATE(267)] = 8097,
  [SMALL_STATE(268)] = 8113,
  [SMALL_STATE(269)] = 8125,
  [SMALL_STATE(270)] = 8139,
  [SMALL_STATE(271)] = 8153,
  [SMALL_STATE(272)] = 8169,
  [SMALL_STATE(273)] = 8183,
  [SMALL_STATE(274)] = 8197,
  [SMALL_STATE(275)] = 8211,
  [SMALL_STATE(276)] = 8225,
  [SMALL_STATE(277)] = 8237,
  [SMALL_STATE(278)] = 8250,
  [SMALL_STATE(279)] = 8263,
  [SMALL_STATE(280)] = 8276,
  [SMALL_STATE(281)] = 8289,
  [SMALL_STATE(282)] = 8302,
  [SMALL_STATE(283)] = 8311,
  [SMALL_STATE(284)] = 8322,
  [SMALL_STATE(285)] = 8335,
  [SMALL_STATE(286)] = 8348,
  [SMALL_STATE(287)] = 8361,
  [SMALL_STATE(288)] = 8370,
  [SMALL_STATE(289)] = 8379,
  [SMALL_STATE(290)] = 8392,
  [SMALL_STATE(291)] = 8403,
  [SMALL_STATE(292)] = 8416,
  [SMALL_STATE(293)] = 8426,
  [SMALL_STATE(294)] = 8436,
  [SMALL_STATE(295)] = 8446,
  [SMALL_STATE(296)] = 8456,
  [SMALL_STATE(297)] = 8466,
  [SMALL_STATE(298)] = 8476,
  [SMALL_STATE(299)] = 8484,
  [SMALL_STATE(300)] = 8494,
  [SMALL_STATE(301)] = 8504,
  [SMALL_STATE(302)] = 8512,
  [SMALL_STATE(303)] = 8522,
  [SMALL_STATE(304)] = 8532,
  [SMALL_STATE(305)] = 8540,
  [SMALL_STATE(306)] = 8550,
  [SMALL_STATE(307)] = 8560,
  [SMALL_STATE(308)] = 8570,
  [SMALL_STATE(309)] = 8580,
  [SMALL_STATE(310)] = 8590,
  [SMALL_STATE(311)] = 8598,
  [SMALL_STATE(312)] = 8606,
  [SMALL_STATE(313)] = 8616,
  [SMALL_STATE(314)] = 8624,
  [SMALL_STATE(315)] = 8634,
  [SMALL_STATE(316)] = 8642,
  [SMALL_STATE(317)] = 8649,
  [SMALL_STATE(318)] = 8656,
  [SMALL_STATE(319)] = 8663,
  [SMALL_STATE(320)] = 8670,
  [SMALL_STATE(321)] = 8677,
  [SMALL_STATE(322)] = 8684,
  [SMALL_STATE(323)] = 8691,
  [SMALL_STATE(324)] = 8698,
  [SMALL_STATE(325)] = 8705,
  [SMALL_STATE(326)] = 8712,
  [SMALL_STATE(327)] = 8719,
  [SMALL_STATE(328)] = 8726,
  [SMALL_STATE(329)] = 8733,
  [SMALL_STATE(330)] = 8740,
  [SMALL_STATE(331)] = 8747,
  [SMALL_STATE(332)] = 8754,
  [SMALL_STATE(333)] = 8761,
  [SMALL_STATE(334)] = 8768,
  [SMALL_STATE(335)] = 8775,
  [SMALL_STATE(336)] = 8782,
  [SMALL_STATE(337)] = 8789,
  [SMALL_STATE(338)] = 8796,
  [SMALL_STATE(339)] = 8803,
  [SMALL_STATE(340)] = 8810,
  [SMALL_STATE(341)] = 8817,
  [SMALL_STATE(342)] = 8824,
  [SMALL_STATE(343)] = 8831,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(280),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 2),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(247),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(126),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(94),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(58),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 2),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 2),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(58),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 3),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 3),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(327),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(169),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(197),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(280),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(102),
  [100] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(8),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 2),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 5),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 5),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 4),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 4),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 1),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 3),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 3),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 4),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 4),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(216),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(284),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 3),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 3),
  [155] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [161] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(27),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 4),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 3),
  [174] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(338),
  [179] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(192),
  [182] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(216),
  [185] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(284),
  [188] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(63),
  [191] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(35),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 1),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_hash, 3),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_hash, 3),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 2),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 2),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens, 3),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens, 3),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens_empty, 2),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens_empty, 2),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_bracket, 3),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_bracket, 3),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function_call, 2),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function_call, 2),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_associative, 3),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_associative, 3),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_dblquotes, 3),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_dblquotes, 3),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_variable, 1),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_variable, 1),
  [252] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(161),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [304] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [308] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [310] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(166),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [322] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [326] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [328] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [332] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [334] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [336] = {.entry = {.count = 1, .reusable = false}}, SHIFT(150),
  [338] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [340] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [342] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [346] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [350] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [356] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [358] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [360] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [364] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [366] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [368] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [372] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [374] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [378] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [380] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [382] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [384] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [388] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [390] = {.entry = {.count = 1, .reusable = false}}, SHIFT(155),
  [392] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [400] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [402] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [404] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [426] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [428] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [430] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [432] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_attribute, 3),
  [444] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_attribute, 3),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [450] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [452] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [454] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2),
  [512] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [524] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag_end, 1),
  [526] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag_end, 1),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 6),
  [530] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 6),
  [532] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag_selfclose_end, 1),
  [534] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag_selfclose_end, 1),
  [536] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_argument, 2),
  [538] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_argument, 2),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 7),
  [542] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 7),
  [544] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_return, 2),
  [546] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_return, 2),
  [548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 1),
  [550] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 1),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 2),
  [554] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 2),
  [556] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3),
  [558] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3),
  [560] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [562] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [564] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3),
  [566] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3),
  [570] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3),
  [572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 3),
  [574] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 3),
  [576] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag_selfclose_end, 2),
  [578] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag_selfclose_end, 2),
  [580] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_argument, 3),
  [582] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_argument, 3),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_return, 3),
  [586] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_return, 3),
  [588] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_condition, 1),
  [590] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_condition, 1),
  [592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 3),
  [594] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 3),
  [596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2),
  [598] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4),
  [602] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4),
  [604] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [606] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [616] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3),
  [618] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3),
  [620] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 4),
  [622] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 4),
  [624] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 4),
  [626] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 4),
  [628] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag, 2),
  [630] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag, 2),
  [632] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1),
  [634] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text, 1),
  [636] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1),
  [638] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1),
  [640] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 5),
  [642] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 5),
  [644] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 3),
  [646] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 3),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [656] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [662] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3),
  [664] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3),
  [666] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4),
  [668] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4),
  [670] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_assignment, 1),
  [672] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_assignment, 1),
  [674] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(328),
  [677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [679] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(299),
  [682] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [686] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2),
  [688] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2), SHIFT_REPEAT(268),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [705] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2),
  [707] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(276),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_attribute, 1),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [724] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [726] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(283),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [737] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2), SHIFT_REPEAT(290),
  [740] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [744] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [756] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [758] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [760] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [764] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [766] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [768] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [774] = {.entry = {.count = 1, .reusable = false}}, SHIFT(301),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [778] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [786] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [788] = {.entry = {.count = 1, .reusable = false}}, SHIFT(287),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [792] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [794] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4),
  [796] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4),
  [798] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3),
  [800] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3),
  [802] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [804] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [806] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [808] = {.entry = {.count = 1, .reusable = true}}, SHIFT(288),
  [810] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [812] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [814] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [816] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [818] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [820] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [824] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [832] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [834] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [838] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_cfml_external_scanner_create(void);
void tree_sitter_cfml_external_scanner_destroy(void *);
bool tree_sitter_cfml_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_cfml_external_scanner_serialize(void *, char *);
void tree_sitter_cfml_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_cfml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_cfml_external_scanner_create,
      tree_sitter_cfml_external_scanner_destroy,
      tree_sitter_cfml_external_scanner_scan,
      tree_sitter_cfml_external_scanner_serialize,
      tree_sitter_cfml_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
