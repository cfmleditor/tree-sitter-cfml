#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 341
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 91
#define ALIAS_COUNT 0
#define TOKEN_COUNT 49
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
  sym_cf_operator = 10,
  anon_sym_LT = 11,
  anon_sym_SLASH_GT = 12,
  anon_sym_LT_SLASH = 13,
  anon_sym_POUND = 14,
  anon_sym_LBRACK = 15,
  anon_sym_RBRACK = 16,
  anon_sym_LBRACE = 17,
  anon_sym_RBRACE = 18,
  sym_cf_period = 19,
  sym_cf_comma = 20,
  anon_sym_EQ = 21,
  sym_cf_objectkeyassign = 22,
  anon_sym_DQUOTE = 23,
  anon_sym_LPAREN = 24,
  anon_sym_RPAREN = 25,
  anon_sym_set = 26,
  sym_attribute_name = 27,
  sym_attribute_value = 28,
  sym_cf_attribute_name = 29,
  sym_entity = 30,
  anon_sym_SQUOTE = 31,
  aux_sym_quoted_attribute_value_token1 = 32,
  aux_sym_quoted_attribute_value_token2 = 33,
  sym_cf_var = 34,
  sym_cf_if_keyword = 35,
  sym_cf_elseif_keyword = 36,
  sym_cf_else_keyword = 37,
  sym_cf_function_keyword = 38,
  sym_cf_argument_keyword = 39,
  sym_cf_return_keyword = 40,
  sym__start_tag_name = 41,
  sym__script_start_tag_name = 42,
  sym__style_start_tag_name = 43,
  sym__end_tag_name = 44,
  sym_erroneous_end_tag_name = 45,
  sym__implicit_end_tag = 46,
  sym_raw_text = 47,
  sym_comment = 48,
  sym_fragment = 49,
  sym_doctype = 50,
  sym_cf_condition = 51,
  sym_cf_tag_end = 52,
  sym_cf_tag_selfclose_end = 53,
  sym_text = 54,
  sym_cf_variable = 55,
  sym__node = 56,
  sym_element = 57,
  sym_script_element = 58,
  sym_start_tag = 59,
  sym_script_start_tag = 60,
  sym_style_start_tag = 61,
  sym_self_closing_tag = 62,
  sym_end_tag = 63,
  sym_style_element = 64,
  sym_cf_hash = 65,
  sym_cf_associative = 66,
  sym_cf_bracket = 67,
  sym__cf_expression = 68,
  sym_cf_assignment = 69,
  sym_cf_dblquotes = 70,
  sym_cf_dblquotes_empty = 71,
  sym_cf_parens = 72,
  sym_cf_parens_empty = 73,
  sym_cf_function = 74,
  sym_cf_argument = 75,
  sym_cf_return = 76,
  sym_cf_ifstatement = 77,
  sym_cf_if = 78,
  sym_cf_set = 79,
  sym_cf_elseif = 80,
  sym_cf_else = 81,
  sym_cf_if_end = 82,
  sym_attribute = 83,
  sym_cf_attribute = 84,
  sym_cf_tag = 85,
  sym_quoted_attribute_value = 86,
  aux_sym_fragment_repeat1 = 87,
  aux_sym_start_tag_repeat1 = 88,
  aux_sym_cf_function_repeat1 = 89,
  aux_sym_cf_ifstatement_repeat1 = 90,
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
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
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
  [23] = 18,
  [24] = 22,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 6,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 33,
  [35] = 35,
  [36] = 31,
  [37] = 35,
  [38] = 3,
  [39] = 3,
  [40] = 32,
  [41] = 41,
  [42] = 3,
  [43] = 3,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 3,
  [53] = 3,
  [54] = 19,
  [55] = 48,
  [56] = 21,
  [57] = 20,
  [58] = 20,
  [59] = 21,
  [60] = 45,
  [61] = 17,
  [62] = 62,
  [63] = 44,
  [64] = 49,
  [65] = 65,
  [66] = 50,
  [67] = 67,
  [68] = 62,
  [69] = 47,
  [70] = 67,
  [71] = 19,
  [72] = 17,
  [73] = 51,
  [74] = 46,
  [75] = 65,
  [76] = 20,
  [77] = 21,
  [78] = 19,
  [79] = 21,
  [80] = 19,
  [81] = 17,
  [82] = 17,
  [83] = 20,
  [84] = 84,
  [85] = 20,
  [86] = 84,
  [87] = 84,
  [88] = 88,
  [89] = 89,
  [90] = 89,
  [91] = 88,
  [92] = 88,
  [93] = 20,
  [94] = 21,
  [95] = 84,
  [96] = 19,
  [97] = 84,
  [98] = 98,
  [99] = 21,
  [100] = 100,
  [101] = 19,
  [102] = 17,
  [103] = 17,
  [104] = 89,
  [105] = 100,
  [106] = 98,
  [107] = 100,
  [108] = 98,
  [109] = 109,
  [110] = 110,
  [111] = 109,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 110,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 110,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 121,
  [144] = 144,
  [145] = 145,
  [146] = 50,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 149,
  [156] = 150,
  [157] = 154,
  [158] = 151,
  [159] = 153,
  [160] = 160,
  [161] = 161,
  [162] = 154,
  [163] = 161,
  [164] = 164,
  [165] = 152,
  [166] = 153,
  [167] = 154,
  [168] = 154,
  [169] = 150,
  [170] = 149,
  [171] = 153,
  [172] = 154,
  [173] = 160,
  [174] = 47,
  [175] = 153,
  [176] = 148,
  [177] = 151,
  [178] = 150,
  [179] = 151,
  [180] = 154,
  [181] = 149,
  [182] = 50,
  [183] = 153,
  [184] = 153,
  [185] = 151,
  [186] = 186,
  [187] = 48,
  [188] = 46,
  [189] = 45,
  [190] = 164,
  [191] = 150,
  [192] = 151,
  [193] = 149,
  [194] = 150,
  [195] = 148,
  [196] = 149,
  [197] = 161,
  [198] = 152,
  [199] = 148,
  [200] = 148,
  [201] = 44,
  [202] = 49,
  [203] = 51,
  [204] = 149,
  [205] = 150,
  [206] = 151,
  [207] = 207,
  [208] = 208,
  [209] = 207,
  [210] = 208,
  [211] = 134,
  [212] = 119,
  [213] = 125,
  [214] = 214,
  [215] = 147,
  [216] = 144,
  [217] = 217,
  [218] = 115,
  [219] = 50,
  [220] = 140,
  [221] = 118,
  [222] = 133,
  [223] = 130,
  [224] = 139,
  [225] = 123,
  [226] = 122,
  [227] = 145,
  [228] = 127,
  [229] = 132,
  [230] = 117,
  [231] = 114,
  [232] = 113,
  [233] = 112,
  [234] = 128,
  [235] = 131,
  [236] = 135,
  [237] = 136,
  [238] = 137,
  [239] = 129,
  [240] = 142,
  [241] = 141,
  [242] = 126,
  [243] = 124,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 247,
  [250] = 245,
  [251] = 246,
  [252] = 248,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 253,
  [258] = 258,
  [259] = 254,
  [260] = 260,
  [261] = 258,
  [262] = 256,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 255,
  [271] = 271,
  [272] = 260,
  [273] = 267,
  [274] = 271,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 263,
  [281] = 281,
  [282] = 276,
  [283] = 279,
  [284] = 284,
  [285] = 284,
  [286] = 286,
  [287] = 278,
  [288] = 275,
  [289] = 289,
  [290] = 290,
  [291] = 286,
  [292] = 281,
  [293] = 293,
  [294] = 289,
  [295] = 293,
  [296] = 296,
  [297] = 277,
  [298] = 298,
  [299] = 299,
  [300] = 300,
  [301] = 301,
  [302] = 299,
  [303] = 301,
  [304] = 304,
  [305] = 298,
  [306] = 306,
  [307] = 307,
  [308] = 308,
  [309] = 309,
  [310] = 310,
  [311] = 306,
  [312] = 300,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 313,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 319,
  [321] = 321,
  [322] = 322,
  [323] = 323,
  [324] = 322,
  [325] = 325,
  [326] = 315,
  [327] = 327,
  [328] = 318,
  [329] = 321,
  [330] = 317,
  [331] = 323,
  [332] = 332,
  [333] = 327,
  [334] = 334,
  [335] = 332,
  [336] = 314,
  [337] = 337,
  [338] = 325,
  [339] = 339,
  [340] = 337,
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
      if (eof) ADVANCE(127);
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '&') ADVANCE(18);
      if (lookahead == '\'') ADVANCE(250);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ')') ADVANCE(235);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == '/') ADVANCE(136);
      if (lookahead == ':') ADVANCE(228);
      if (lookahead == '<') ADVANCE(208);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == ']') ADVANCE(218);
      if (lookahead == 'a') ADVANCE(100);
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead == 'f') ADVANCE(110);
      if (lookahead == 'i') ADVANCE(84);
      if (lookahead == 'r') ADVANCE(78);
      if (lookahead == 's') ADVANCE(81);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '&') ADVANCE(18);
      if (lookahead == '\'') ADVANCE(250);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ')') ADVANCE(235);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == '/') ADVANCE(136);
      if (lookahead == ':') ADVANCE(228);
      if (lookahead == '<') ADVANCE(208);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'A') ADVANCE(69);
      if (lookahead == 'E') ADVANCE(71);
      if (lookahead == 'G') ADVANCE(74);
      if (lookahead == 'N') ADVANCE(70);
      if (lookahead == 'O') ADVANCE(72);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == ']') ADVANCE(218);
      if (lookahead == 'a') ADVANCE(100);
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead == 'f') ADVANCE(110);
      if (lookahead == 'i') ADVANCE(84);
      if (lookahead == 'r') ADVANCE(78);
      if (lookahead == 's') ADVANCE(81);
      if (lookahead == 'v') ADVANCE(75);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '&') ADVANCE(138);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == ':') ADVANCE(230);
      if (lookahead == '<') ADVANCE(210);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'A') ADVANCE(181);
      if (lookahead == 'E') ADVANCE(183);
      if (lookahead == 'G') ADVANCE(186);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'O') ADVANCE(184);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == 'e') ADVANCE(196);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ']') ADVANCE(205);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '&') ADVANCE(138);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == ':') ADVANCE(230);
      if (lookahead == '<') ADVANCE(210);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == 'e') ADVANCE(196);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ']') ADVANCE(205);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ')') ADVANCE(235);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == ':') ADVANCE(230);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == 'A') ADVANCE(181);
      if (lookahead == 'E') ADVANCE(183);
      if (lookahead == 'G') ADVANCE(186);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'O') ADVANCE(184);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == ']') ADVANCE(218);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(205);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ')') ADVANCE(235);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == ':') ADVANCE(230);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == ']') ADVANCE(218);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(205);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == '/') ADVANCE(137);
      if (lookahead == ':') ADVANCE(230);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'A') ADVANCE(181);
      if (lookahead == 'E') ADVANCE(183);
      if (lookahead == 'G') ADVANCE(186);
      if (lookahead == 'N') ADVANCE(182);
      if (lookahead == 'O') ADVANCE(184);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '<' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(205);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '(') ADVANCE(233);
      if (lookahead == ',') ADVANCE(224);
      if (lookahead == '.') ADVANCE(222);
      if (lookahead == '/') ADVANCE(137);
      if (lookahead == ':') ADVANCE(230);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '[') ADVANCE(216);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '<' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(205);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == ')') ADVANCE(235);
      if (lookahead == '{') ADVANCE(219);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '(' &&
          lookahead != ',' &&
          lookahead != '.' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(205);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == 'v') ADVANCE(187);
      if (lookahead == '{') ADVANCE(219);
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
          lookahead != '}') ADVANCE(205);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '{') ADVANCE(219);
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
          lookahead != '}') ADVANCE(205);
      END_STATE();
    case 11:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(215);
      if (lookahead == '(') ADVANCE(234);
      if (lookahead == ',') ADVANCE(225);
      if (lookahead == '.') ADVANCE(223);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == ':') ADVANCE(229);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'A') ADVANCE(141);
      if (lookahead == 'E') ADVANCE(143);
      if (lookahead == 'G') ADVANCE(146);
      if (lookahead == 'N') ADVANCE(142);
      if (lookahead == 'O') ADVANCE(144);
      if (lookahead == '[') ADVANCE(217);
      if (lookahead == '{') ADVANCE(220);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(148);
      END_STATE();
    case 12:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(215);
      if (lookahead == '(') ADVANCE(234);
      if (lookahead == ',') ADVANCE(225);
      if (lookahead == '.') ADVANCE(223);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == ':') ADVANCE(229);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '[') ADVANCE(217);
      if (lookahead == '{') ADVANCE(220);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(148);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(215);
      if (lookahead == '(') ADVANCE(234);
      if (lookahead == ',') ADVANCE(225);
      if (lookahead == '.') ADVANCE(223);
      if (lookahead == '/') ADVANCE(137);
      if (lookahead == ':') ADVANCE(229);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'A') ADVANCE(141);
      if (lookahead == 'E') ADVANCE(143);
      if (lookahead == 'G') ADVANCE(146);
      if (lookahead == 'N') ADVANCE(142);
      if (lookahead == 'O') ADVANCE(144);
      if (lookahead == '[') ADVANCE(217);
      if (lookahead == '{') ADVANCE(220);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(148);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '#') ADVANCE(215);
      if (lookahead == '(') ADVANCE(234);
      if (lookahead == ',') ADVANCE(225);
      if (lookahead == '.') ADVANCE(223);
      if (lookahead == '/') ADVANCE(137);
      if (lookahead == ':') ADVANCE(229);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '[') ADVANCE(217);
      if (lookahead == '{') ADVANCE(220);
      if (lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(148);
      END_STATE();
    case 15:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '\'') ADVANCE(250);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(238);
      END_STATE();
    case 16:
      if (lookahead == '"') ADVANCE(232);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(253);
      if (lookahead != 0) ADVANCE(254);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '&') ADVANCE(138);
      if (lookahead == '<') ADVANCE(209);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (!aux_sym_text_token1_character_set_1(lookahead)) ADVANCE(205);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(119);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 19:
      if (lookahead == '\'') ADVANCE(250);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(251);
      if (lookahead != 0) ADVANCE(252);
      END_STATE();
    case 20:
      if (lookahead == '(') ADVANCE(234);
      if (lookahead == ',') ADVANCE(225);
      if (lookahead == '.') ADVANCE(223);
      if (lookahead == '/') ADVANCE(136);
      if (lookahead == ':') ADVANCE(231);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'A') ADVANCE(241);
      if (lookahead == 'E') ADVANCE(243);
      if (lookahead == 'G') ADVANCE(246);
      if (lookahead == 'N') ADVANCE(242);
      if (lookahead == 'O') ADVANCE(244);
      if (lookahead == '[') ADVANCE(217);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(248);
      END_STATE();
    case 21:
      if (lookahead == '(') ADVANCE(234);
      if (lookahead == ',') ADVANCE(225);
      if (lookahead == '.') ADVANCE(223);
      if (lookahead == '/') ADVANCE(136);
      if (lookahead == ':') ADVANCE(231);
      if (lookahead == '=') ADVANCE(227);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '[') ADVANCE(217);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(248);
      END_STATE();
    case 22:
      if (lookahead == '/') ADVANCE(136);
      if (lookahead == '=') ADVANCE(226);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(22)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(248);
      END_STATE();
    case 23:
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '=') ADVANCE(226);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(23)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(237);
      END_STATE();
    case 24:
      if (lookahead == '/') ADVANCE(76);
      if (lookahead == 'c') ADVANCE(85);
      END_STATE();
    case 25:
      if (lookahead == ';') ADVANCE(249);
      END_STATE();
    case 26:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 29:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 30:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 31:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 33:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (lookahead == ';') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 36:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 37:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(37);
      END_STATE();
    case 39:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(38);
      END_STATE();
    case 40:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 41:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 43:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 44:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 45:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 46:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 47:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 48:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 49:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(48);
      END_STATE();
    case 50:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 51:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(50);
      END_STATE();
    case 52:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 53:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 54:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 55:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 56:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 57:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 58:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 59:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 60:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 61:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(60);
      END_STATE();
    case 62:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 63:
      if (lookahead == ';') ADVANCE(249);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(62);
      END_STATE();
    case 64:
      if (lookahead == '<') ADVANCE(24);
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(64)
      END_STATE();
    case 65:
      if (lookahead == '=') ADVANCE(207);
      END_STATE();
    case 66:
      if (lookahead == '>') ADVANCE(211);
      END_STATE();
    case 67:
      if (lookahead == 'D') ADVANCE(121);
      END_STATE();
    case 68:
      if (lookahead == 'E') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      END_STATE();
    case 69:
      if (lookahead == 'N') ADVANCE(67);
      END_STATE();
    case 70:
      if (lookahead == 'O') ADVANCE(73);
      END_STATE();
    case 71:
      if (lookahead == 'Q') ADVANCE(121);
      END_STATE();
    case 72:
      if (lookahead == 'R') ADVANCE(121);
      END_STATE();
    case 73:
      if (lookahead == 'T') ADVANCE(121);
      END_STATE();
    case 74:
      if (lookahead == 'T') ADVANCE(68);
      END_STATE();
    case 75:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 76:
      if (lookahead == 'c') ADVANCE(86);
      END_STATE();
    case 77:
      if (lookahead == 'c') ADVANCE(107);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(259);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(258);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 84:
      if (lookahead == 'f') ADVANCE(256);
      END_STATE();
    case 85:
      if (lookahead == 'f') ADVANCE(135);
      END_STATE();
    case 86:
      if (lookahead == 'f') ADVANCE(206);
      END_STATE();
    case 87:
      if (lookahead == 'f') ADVANCE(257);
      END_STATE();
    case 88:
      if (lookahead == 'g') ADVANCE(111);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(99);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(87);
      END_STATE();
    case 91:
      if (lookahead == 'l') ADVANCE(103);
      END_STATE();
    case 92:
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 93:
      if (lookahead == 'l') ADVANCE(105);
      END_STATE();
    case 94:
      if (lookahead == 'm') ADVANCE(83);
      END_STATE();
    case 95:
      if (lookahead == 'n') ADVANCE(77);
      END_STATE();
    case 96:
      if (lookahead == 'n') ADVANCE(262);
      END_STATE();
    case 97:
      if (lookahead == 'n') ADVANCE(260);
      END_STATE();
    case 98:
      if (lookahead == 'n') ADVANCE(108);
      END_STATE();
    case 99:
      if (lookahead == 'o') ADVANCE(97);
      END_STATE();
    case 100:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 101:
      if (lookahead == 'r') ADVANCE(96);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 103:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 104:
      if (lookahead == 's') ADVANCE(80);
      END_STATE();
    case 105:
      if (lookahead == 's') ADVANCE(82);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(236);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(261);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 110:
      if (lookahead == 'u') ADVANCE(95);
      END_STATE();
    case 111:
      if (lookahead == 'u') ADVANCE(94);
      END_STATE();
    case 112:
      if (lookahead == 'u') ADVANCE(101);
      END_STATE();
    case 113:
      if (lookahead == 'v') ADVANCE(75);
      END_STATE();
    case 114:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(118);
      END_STATE();
    case 115:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 116:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(114);
      END_STATE();
    case 117:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(115);
      END_STATE();
    case 118:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(120);
      END_STATE();
    case 119:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 120:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(117);
      END_STATE();
    case 121:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      END_STATE();
    case 122:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(255);
      END_STATE();
    case 123:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(134);
      END_STATE();
    case 124:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(129);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(130);
      END_STATE();
    case 125:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 126:
      if (eof) ADVANCE(127);
      if (lookahead == '#') ADVANCE(214);
      if (lookahead == '&') ADVANCE(138);
      if (lookahead == '<') ADVANCE(210);
      if (lookahead == '>') ADVANCE(131);
      if (lookahead == 'e') ADVANCE(196);
      if (lookahead == '}') ADVANCE(221);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(126)
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(205);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(129);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(130);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(134);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym__cf_tag_start);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '#') ADVANCE(119);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(177);
      if (!aux_sym_text_token1_character_set_4(lookahead)) ADVANCE(205);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'D') ADVANCE(147);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'E') ADVANCE(147);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'N') ADVANCE(139);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'O') ADVANCE(145);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'Q') ADVANCE(147);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'R') ADVANCE(147);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'T') ADVANCE(147);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == 'T') ADVANCE(140);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(150);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(151);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(152);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(160);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(161);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(163);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(164);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(166);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(167);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(169);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(170);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(171);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(172);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(173);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(174);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(175);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(176);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == ';') ADVANCE(205);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'D') ADVANCE(203);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'E') ADVANCE(203);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      if (!aux_sym_text_token1_character_set_5(lookahead)) ADVANCE(205);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'N') ADVANCE(179);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'O') ADVANCE(185);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'Q') ADVANCE(203);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'R') ADVANCE(203);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(203);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(180);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'a') ADVANCE(199);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(190);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(195);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(197);
      if (lookahead == 'i') ADVANCE(194);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(197);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(198);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(191);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'f') ADVANCE(192);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'i') ADVANCE(194);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(200);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(201);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(202);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'r') ADVANCE(204);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(188);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(193);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(189);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      if (!aux_sym_text_token1_character_set_5(lookahead)) ADVANCE(205);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(255);
      if (!aux_sym_text_token1_character_set_5(lookahead)) ADVANCE(205);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_cf_tag_close);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_cf_operator);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(128);
      if (lookahead == '/') ADVANCE(213);
      if (lookahead == 'c') ADVANCE(85);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(128);
      if (lookahead == '/') ADVANCE(212);
      if (lookahead == 'c') ADVANCE(85);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(128);
      if (lookahead == '/') ADVANCE(76);
      if (lookahead == 'c') ADVANCE(85);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      if (lookahead == 'c') ADVANCE(86);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_cf_period);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_cf_period);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_cf_comma);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_cf_comma);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(65);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      if (lookahead == '/') ADVANCE(205);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(148);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(205);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_cf_objectkeyassign);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_set);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(237);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'D') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'E') ADVANCE(247);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'N') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'O') ADVANCE(245);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'Q') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'R') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'T') ADVANCE(247);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == 'T') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_cf_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(251);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(252);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(252);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(254);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(254);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_cf_var);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(113);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_cf_if_keyword);
      if (lookahead == 'i') ADVANCE(84);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_cf_elseif_keyword);
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(92);
      if (lookahead == 'i') ADVANCE(87);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_cf_function_keyword);
      if (lookahead == 'f') ADVANCE(110);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_cf_argument_keyword);
      if (lookahead == 'a') ADVANCE(100);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_cf_return_keyword);
      if (lookahead == 'r') ADVANCE(78);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 126, .external_lex_state = 2},
  [2] = {.lex_state = 3, .external_lex_state = 2},
  [3] = {.lex_state = 3, .external_lex_state = 2},
  [4] = {.lex_state = 126, .external_lex_state = 2},
  [5] = {.lex_state = 126, .external_lex_state = 2},
  [6] = {.lex_state = 126, .external_lex_state = 2},
  [7] = {.lex_state = 126, .external_lex_state = 2},
  [8] = {.lex_state = 126, .external_lex_state = 2},
  [9] = {.lex_state = 126, .external_lex_state = 2},
  [10] = {.lex_state = 126, .external_lex_state = 2},
  [11] = {.lex_state = 126, .external_lex_state = 2},
  [12] = {.lex_state = 126, .external_lex_state = 2},
  [13] = {.lex_state = 126, .external_lex_state = 2},
  [14] = {.lex_state = 126, .external_lex_state = 2},
  [15] = {.lex_state = 126, .external_lex_state = 2},
  [16] = {.lex_state = 126, .external_lex_state = 2},
  [17] = {.lex_state = 3, .external_lex_state = 2},
  [18] = {.lex_state = 17, .external_lex_state = 3},
  [19] = {.lex_state = 3, .external_lex_state = 2},
  [20] = {.lex_state = 3, .external_lex_state = 2},
  [21] = {.lex_state = 3, .external_lex_state = 2},
  [22] = {.lex_state = 17, .external_lex_state = 3},
  [23] = {.lex_state = 17, .external_lex_state = 3},
  [24] = {.lex_state = 17, .external_lex_state = 3},
  [25] = {.lex_state = 126, .external_lex_state = 2},
  [26] = {.lex_state = 126, .external_lex_state = 2},
  [27] = {.lex_state = 126, .external_lex_state = 2},
  [28] = {.lex_state = 17, .external_lex_state = 3},
  [29] = {.lex_state = 126, .external_lex_state = 2},
  [30] = {.lex_state = 126, .external_lex_state = 2},
  [31] = {.lex_state = 126, .external_lex_state = 2},
  [32] = {.lex_state = 126, .external_lex_state = 2},
  [33] = {.lex_state = 126, .external_lex_state = 2},
  [34] = {.lex_state = 126, .external_lex_state = 2},
  [35] = {.lex_state = 126, .external_lex_state = 2},
  [36] = {.lex_state = 126, .external_lex_state = 2},
  [37] = {.lex_state = 126, .external_lex_state = 2},
  [38] = {.lex_state = 5, .external_lex_state = 2},
  [39] = {.lex_state = 14, .external_lex_state = 2},
  [40] = {.lex_state = 126, .external_lex_state = 2},
  [41] = {.lex_state = 126, .external_lex_state = 2},
  [42] = {.lex_state = 7, .external_lex_state = 2},
  [43] = {.lex_state = 12, .external_lex_state = 2},
  [44] = {.lex_state = 3, .external_lex_state = 2},
  [45] = {.lex_state = 3, .external_lex_state = 2},
  [46] = {.lex_state = 3, .external_lex_state = 2},
  [47] = {.lex_state = 3, .external_lex_state = 2},
  [48] = {.lex_state = 3, .external_lex_state = 2},
  [49] = {.lex_state = 3, .external_lex_state = 2},
  [50] = {.lex_state = 3, .external_lex_state = 2},
  [51] = {.lex_state = 3, .external_lex_state = 2},
  [52] = {.lex_state = 5, .external_lex_state = 2},
  [53] = {.lex_state = 5, .external_lex_state = 2},
  [54] = {.lex_state = 0, .external_lex_state = 2},
  [55] = {.lex_state = 0, .external_lex_state = 2},
  [56] = {.lex_state = 21, .external_lex_state = 2},
  [57] = {.lex_state = 21, .external_lex_state = 2},
  [58] = {.lex_state = 0, .external_lex_state = 2},
  [59] = {.lex_state = 0, .external_lex_state = 2},
  [60] = {.lex_state = 0, .external_lex_state = 2},
  [61] = {.lex_state = 0, .external_lex_state = 2},
  [62] = {.lex_state = 0, .external_lex_state = 2},
  [63] = {.lex_state = 0, .external_lex_state = 2},
  [64] = {.lex_state = 0, .external_lex_state = 2},
  [65] = {.lex_state = 21, .external_lex_state = 2},
  [66] = {.lex_state = 0, .external_lex_state = 2},
  [67] = {.lex_state = 0, .external_lex_state = 2},
  [68] = {.lex_state = 0, .external_lex_state = 2},
  [69] = {.lex_state = 0, .external_lex_state = 2},
  [70] = {.lex_state = 0, .external_lex_state = 2},
  [71] = {.lex_state = 21, .external_lex_state = 2},
  [72] = {.lex_state = 21, .external_lex_state = 2},
  [73] = {.lex_state = 0, .external_lex_state = 2},
  [74] = {.lex_state = 0, .external_lex_state = 2},
  [75] = {.lex_state = 21, .external_lex_state = 2},
  [76] = {.lex_state = 0, .external_lex_state = 2},
  [77] = {.lex_state = 21, .external_lex_state = 2},
  [78] = {.lex_state = 21, .external_lex_state = 2},
  [79] = {.lex_state = 0, .external_lex_state = 2},
  [80] = {.lex_state = 0, .external_lex_state = 2},
  [81] = {.lex_state = 0, .external_lex_state = 2},
  [82] = {.lex_state = 21, .external_lex_state = 2},
  [83] = {.lex_state = 21, .external_lex_state = 2},
  [84] = {.lex_state = 0, .external_lex_state = 2},
  [85] = {.lex_state = 0, .external_lex_state = 2},
  [86] = {.lex_state = 0, .external_lex_state = 2},
  [87] = {.lex_state = 0, .external_lex_state = 2},
  [88] = {.lex_state = 0, .external_lex_state = 2},
  [89] = {.lex_state = 0, .external_lex_state = 2},
  [90] = {.lex_state = 0, .external_lex_state = 2},
  [91] = {.lex_state = 0, .external_lex_state = 2},
  [92] = {.lex_state = 0, .external_lex_state = 2},
  [93] = {.lex_state = 0, .external_lex_state = 2},
  [94] = {.lex_state = 0, .external_lex_state = 2},
  [95] = {.lex_state = 0, .external_lex_state = 2},
  [96] = {.lex_state = 0, .external_lex_state = 2},
  [97] = {.lex_state = 0, .external_lex_state = 2},
  [98] = {.lex_state = 0, .external_lex_state = 2},
  [99] = {.lex_state = 0, .external_lex_state = 2},
  [100] = {.lex_state = 0, .external_lex_state = 2},
  [101] = {.lex_state = 0, .external_lex_state = 2},
  [102] = {.lex_state = 0, .external_lex_state = 2},
  [103] = {.lex_state = 0, .external_lex_state = 2},
  [104] = {.lex_state = 0, .external_lex_state = 2},
  [105] = {.lex_state = 0, .external_lex_state = 2},
  [106] = {.lex_state = 0, .external_lex_state = 2},
  [107] = {.lex_state = 0, .external_lex_state = 2},
  [108] = {.lex_state = 0, .external_lex_state = 2},
  [109] = {.lex_state = 0, .external_lex_state = 2},
  [110] = {.lex_state = 8, .external_lex_state = 2},
  [111] = {.lex_state = 0, .external_lex_state = 2},
  [112] = {.lex_state = 126, .external_lex_state = 2},
  [113] = {.lex_state = 126, .external_lex_state = 2},
  [114] = {.lex_state = 126, .external_lex_state = 2},
  [115] = {.lex_state = 126, .external_lex_state = 2},
  [116] = {.lex_state = 126, .external_lex_state = 2},
  [117] = {.lex_state = 126, .external_lex_state = 2},
  [118] = {.lex_state = 126, .external_lex_state = 2},
  [119] = {.lex_state = 126, .external_lex_state = 2},
  [120] = {.lex_state = 8, .external_lex_state = 2},
  [121] = {.lex_state = 10, .external_lex_state = 2},
  [122] = {.lex_state = 126, .external_lex_state = 2},
  [123] = {.lex_state = 126, .external_lex_state = 2},
  [124] = {.lex_state = 126, .external_lex_state = 2},
  [125] = {.lex_state = 126, .external_lex_state = 2},
  [126] = {.lex_state = 126, .external_lex_state = 2},
  [127] = {.lex_state = 126, .external_lex_state = 2},
  [128] = {.lex_state = 126, .external_lex_state = 2},
  [129] = {.lex_state = 126, .external_lex_state = 2},
  [130] = {.lex_state = 126, .external_lex_state = 2},
  [131] = {.lex_state = 126, .external_lex_state = 2},
  [132] = {.lex_state = 126, .external_lex_state = 2},
  [133] = {.lex_state = 126, .external_lex_state = 2},
  [134] = {.lex_state = 126, .external_lex_state = 2},
  [135] = {.lex_state = 126, .external_lex_state = 2},
  [136] = {.lex_state = 126, .external_lex_state = 2},
  [137] = {.lex_state = 126, .external_lex_state = 2},
  [138] = {.lex_state = 8, .external_lex_state = 2},
  [139] = {.lex_state = 126, .external_lex_state = 2},
  [140] = {.lex_state = 126, .external_lex_state = 2},
  [141] = {.lex_state = 126, .external_lex_state = 2},
  [142] = {.lex_state = 126, .external_lex_state = 2},
  [143] = {.lex_state = 10, .external_lex_state = 2},
  [144] = {.lex_state = 126, .external_lex_state = 2},
  [145] = {.lex_state = 126, .external_lex_state = 2},
  [146] = {.lex_state = 126, .external_lex_state = 2},
  [147] = {.lex_state = 126, .external_lex_state = 2},
  [148] = {.lex_state = 8, .external_lex_state = 2},
  [149] = {.lex_state = 8, .external_lex_state = 2},
  [150] = {.lex_state = 8, .external_lex_state = 2},
  [151] = {.lex_state = 8, .external_lex_state = 2},
  [152] = {.lex_state = 8, .external_lex_state = 2},
  [153] = {.lex_state = 8, .external_lex_state = 2},
  [154] = {.lex_state = 8, .external_lex_state = 2},
  [155] = {.lex_state = 8, .external_lex_state = 2},
  [156] = {.lex_state = 8, .external_lex_state = 2},
  [157] = {.lex_state = 8, .external_lex_state = 2},
  [158] = {.lex_state = 8, .external_lex_state = 2},
  [159] = {.lex_state = 8, .external_lex_state = 2},
  [160] = {.lex_state = 8, .external_lex_state = 2},
  [161] = {.lex_state = 8, .external_lex_state = 2},
  [162] = {.lex_state = 8, .external_lex_state = 2},
  [163] = {.lex_state = 8, .external_lex_state = 2},
  [164] = {.lex_state = 8, .external_lex_state = 2},
  [165] = {.lex_state = 8, .external_lex_state = 2},
  [166] = {.lex_state = 8, .external_lex_state = 2},
  [167] = {.lex_state = 8, .external_lex_state = 2},
  [168] = {.lex_state = 8, .external_lex_state = 2},
  [169] = {.lex_state = 8, .external_lex_state = 2},
  [170] = {.lex_state = 8, .external_lex_state = 2},
  [171] = {.lex_state = 8, .external_lex_state = 2},
  [172] = {.lex_state = 8, .external_lex_state = 2},
  [173] = {.lex_state = 8, .external_lex_state = 2},
  [174] = {.lex_state = 21, .external_lex_state = 2},
  [175] = {.lex_state = 8, .external_lex_state = 2},
  [176] = {.lex_state = 8, .external_lex_state = 2},
  [177] = {.lex_state = 8, .external_lex_state = 2},
  [178] = {.lex_state = 8, .external_lex_state = 2},
  [179] = {.lex_state = 8, .external_lex_state = 2},
  [180] = {.lex_state = 8, .external_lex_state = 2},
  [181] = {.lex_state = 8, .external_lex_state = 2},
  [182] = {.lex_state = 21, .external_lex_state = 2},
  [183] = {.lex_state = 8, .external_lex_state = 2},
  [184] = {.lex_state = 8, .external_lex_state = 2},
  [185] = {.lex_state = 8, .external_lex_state = 2},
  [186] = {.lex_state = 8, .external_lex_state = 2},
  [187] = {.lex_state = 21, .external_lex_state = 2},
  [188] = {.lex_state = 21, .external_lex_state = 2},
  [189] = {.lex_state = 21, .external_lex_state = 2},
  [190] = {.lex_state = 8, .external_lex_state = 2},
  [191] = {.lex_state = 8, .external_lex_state = 2},
  [192] = {.lex_state = 8, .external_lex_state = 2},
  [193] = {.lex_state = 8, .external_lex_state = 2},
  [194] = {.lex_state = 8, .external_lex_state = 2},
  [195] = {.lex_state = 8, .external_lex_state = 2},
  [196] = {.lex_state = 8, .external_lex_state = 2},
  [197] = {.lex_state = 8, .external_lex_state = 2},
  [198] = {.lex_state = 8, .external_lex_state = 2},
  [199] = {.lex_state = 8, .external_lex_state = 2},
  [200] = {.lex_state = 8, .external_lex_state = 2},
  [201] = {.lex_state = 21, .external_lex_state = 2},
  [202] = {.lex_state = 21, .external_lex_state = 2},
  [203] = {.lex_state = 21, .external_lex_state = 2},
  [204] = {.lex_state = 8, .external_lex_state = 2},
  [205] = {.lex_state = 8, .external_lex_state = 2},
  [206] = {.lex_state = 8, .external_lex_state = 2},
  [207] = {.lex_state = 64, .external_lex_state = 2},
  [208] = {.lex_state = 64, .external_lex_state = 2},
  [209] = {.lex_state = 64, .external_lex_state = 2},
  [210] = {.lex_state = 64, .external_lex_state = 2},
  [211] = {.lex_state = 17, .external_lex_state = 3},
  [212] = {.lex_state = 17, .external_lex_state = 3},
  [213] = {.lex_state = 17, .external_lex_state = 3},
  [214] = {.lex_state = 17, .external_lex_state = 3},
  [215] = {.lex_state = 17, .external_lex_state = 3},
  [216] = {.lex_state = 17, .external_lex_state = 3},
  [217] = {.lex_state = 17, .external_lex_state = 3},
  [218] = {.lex_state = 17, .external_lex_state = 3},
  [219] = {.lex_state = 17, .external_lex_state = 3},
  [220] = {.lex_state = 17, .external_lex_state = 3},
  [221] = {.lex_state = 17, .external_lex_state = 3},
  [222] = {.lex_state = 17, .external_lex_state = 3},
  [223] = {.lex_state = 17, .external_lex_state = 3},
  [224] = {.lex_state = 17, .external_lex_state = 3},
  [225] = {.lex_state = 17, .external_lex_state = 3},
  [226] = {.lex_state = 17, .external_lex_state = 3},
  [227] = {.lex_state = 17, .external_lex_state = 3},
  [228] = {.lex_state = 17, .external_lex_state = 3},
  [229] = {.lex_state = 17, .external_lex_state = 3},
  [230] = {.lex_state = 17, .external_lex_state = 3},
  [231] = {.lex_state = 17, .external_lex_state = 3},
  [232] = {.lex_state = 17, .external_lex_state = 3},
  [233] = {.lex_state = 17, .external_lex_state = 3},
  [234] = {.lex_state = 17, .external_lex_state = 3},
  [235] = {.lex_state = 17, .external_lex_state = 3},
  [236] = {.lex_state = 17, .external_lex_state = 3},
  [237] = {.lex_state = 17, .external_lex_state = 3},
  [238] = {.lex_state = 17, .external_lex_state = 3},
  [239] = {.lex_state = 17, .external_lex_state = 3},
  [240] = {.lex_state = 17, .external_lex_state = 3},
  [241] = {.lex_state = 17, .external_lex_state = 3},
  [242] = {.lex_state = 17, .external_lex_state = 3},
  [243] = {.lex_state = 17, .external_lex_state = 3},
  [244] = {.lex_state = 64, .external_lex_state = 2},
  [245] = {.lex_state = 22, .external_lex_state = 2},
  [246] = {.lex_state = 22, .external_lex_state = 2},
  [247] = {.lex_state = 22, .external_lex_state = 2},
  [248] = {.lex_state = 22, .external_lex_state = 2},
  [249] = {.lex_state = 22, .external_lex_state = 2},
  [250] = {.lex_state = 22, .external_lex_state = 2},
  [251] = {.lex_state = 22, .external_lex_state = 2},
  [252] = {.lex_state = 22, .external_lex_state = 2},
  [253] = {.lex_state = 22, .external_lex_state = 2},
  [254] = {.lex_state = 23, .external_lex_state = 4},
  [255] = {.lex_state = 22, .external_lex_state = 2},
  [256] = {.lex_state = 22, .external_lex_state = 2},
  [257] = {.lex_state = 22, .external_lex_state = 2},
  [258] = {.lex_state = 23, .external_lex_state = 4},
  [259] = {.lex_state = 23, .external_lex_state = 4},
  [260] = {.lex_state = 23, .external_lex_state = 4},
  [261] = {.lex_state = 23, .external_lex_state = 4},
  [262] = {.lex_state = 22, .external_lex_state = 2},
  [263] = {.lex_state = 22, .external_lex_state = 2},
  [264] = {.lex_state = 23, .external_lex_state = 2},
  [265] = {.lex_state = 23, .external_lex_state = 2},
  [266] = {.lex_state = 23, .external_lex_state = 2},
  [267] = {.lex_state = 15, .external_lex_state = 2},
  [268] = {.lex_state = 23, .external_lex_state = 2},
  [269] = {.lex_state = 8, .external_lex_state = 2},
  [270] = {.lex_state = 22, .external_lex_state = 2},
  [271] = {.lex_state = 23, .external_lex_state = 4},
  [272] = {.lex_state = 23, .external_lex_state = 2},
  [273] = {.lex_state = 15, .external_lex_state = 2},
  [274] = {.lex_state = 23, .external_lex_state = 2},
  [275] = {.lex_state = 126, .external_lex_state = 2},
  [276] = {.lex_state = 126, .external_lex_state = 2},
  [277] = {.lex_state = 23, .external_lex_state = 4},
  [278] = {.lex_state = 17, .external_lex_state = 5},
  [279] = {.lex_state = 17, .external_lex_state = 5},
  [280] = {.lex_state = 22, .external_lex_state = 2},
  [281] = {.lex_state = 23, .external_lex_state = 4},
  [282] = {.lex_state = 126, .external_lex_state = 2},
  [283] = {.lex_state = 17, .external_lex_state = 5},
  [284] = {.lex_state = 0, .external_lex_state = 6},
  [285] = {.lex_state = 0, .external_lex_state = 6},
  [286] = {.lex_state = 23, .external_lex_state = 4},
  [287] = {.lex_state = 17, .external_lex_state = 5},
  [288] = {.lex_state = 126, .external_lex_state = 2},
  [289] = {.lex_state = 19, .external_lex_state = 2},
  [290] = {.lex_state = 123, .external_lex_state = 2},
  [291] = {.lex_state = 23, .external_lex_state = 2},
  [292] = {.lex_state = 23, .external_lex_state = 2},
  [293] = {.lex_state = 0, .external_lex_state = 2},
  [294] = {.lex_state = 19, .external_lex_state = 2},
  [295] = {.lex_state = 0, .external_lex_state = 2},
  [296] = {.lex_state = 123, .external_lex_state = 2},
  [297] = {.lex_state = 23, .external_lex_state = 2},
  [298] = {.lex_state = 0, .external_lex_state = 2},
  [299] = {.lex_state = 17, .external_lex_state = 2},
  [300] = {.lex_state = 16, .external_lex_state = 2},
  [301] = {.lex_state = 17, .external_lex_state = 2},
  [302] = {.lex_state = 17, .external_lex_state = 2},
  [303] = {.lex_state = 17, .external_lex_state = 2},
  [304] = {.lex_state = 17, .external_lex_state = 5},
  [305] = {.lex_state = 0, .external_lex_state = 2},
  [306] = {.lex_state = 0, .external_lex_state = 2},
  [307] = {.lex_state = 17, .external_lex_state = 5},
  [308] = {.lex_state = 0, .external_lex_state = 2},
  [309] = {.lex_state = 17, .external_lex_state = 5},
  [310] = {.lex_state = 17, .external_lex_state = 5},
  [311] = {.lex_state = 0, .external_lex_state = 2},
  [312] = {.lex_state = 16, .external_lex_state = 2},
  [313] = {.lex_state = 0, .external_lex_state = 2},
  [314] = {.lex_state = 0, .external_lex_state = 2},
  [315] = {.lex_state = 0, .external_lex_state = 2},
  [316] = {.lex_state = 0, .external_lex_state = 2},
  [317] = {.lex_state = 0, .external_lex_state = 2},
  [318] = {.lex_state = 0, .external_lex_state = 2},
  [319] = {.lex_state = 0, .external_lex_state = 2},
  [320] = {.lex_state = 0, .external_lex_state = 2},
  [321] = {.lex_state = 0, .external_lex_state = 2},
  [322] = {.lex_state = 0, .external_lex_state = 7},
  [323] = {.lex_state = 124, .external_lex_state = 2},
  [324] = {.lex_state = 0, .external_lex_state = 7},
  [325] = {.lex_state = 0, .external_lex_state = 2},
  [326] = {.lex_state = 0, .external_lex_state = 2},
  [327] = {.lex_state = 0, .external_lex_state = 2},
  [328] = {.lex_state = 0, .external_lex_state = 2},
  [329] = {.lex_state = 0, .external_lex_state = 2},
  [330] = {.lex_state = 0, .external_lex_state = 2},
  [331] = {.lex_state = 124, .external_lex_state = 2},
  [332] = {.lex_state = 0, .external_lex_state = 2},
  [333] = {.lex_state = 0, .external_lex_state = 2},
  [334] = {.lex_state = 0, .external_lex_state = 2},
  [335] = {.lex_state = 0, .external_lex_state = 2},
  [336] = {.lex_state = 0, .external_lex_state = 2},
  [337] = {.lex_state = 0, .external_lex_state = 2},
  [338] = {.lex_state = 0, .external_lex_state = 2},
  [339] = {.lex_state = 0, .external_lex_state = 2},
  [340] = {.lex_state = 0, .external_lex_state = 2},
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
    [sym_fragment] = STATE(334),
    [sym_doctype] = STATE(41),
    [sym_text] = STATE(41),
    [sym__node] = STATE(41),
    [sym_element] = STATE(41),
    [sym_script_element] = STATE(41),
    [sym_start_tag] = STATE(24),
    [sym_script_start_tag] = STATE(287),
    [sym_style_start_tag] = STATE(283),
    [sym_self_closing_tag] = STATE(118),
    [sym_style_element] = STATE(41),
    [sym_cf_hash] = STATE(41),
    [sym_cf_tag] = STATE(41),
    [aux_sym_fragment_repeat1] = STATE(41),
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
  [0] = 25,
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
    STATE(9), 1,
      sym_cf_tag_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(21), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(39), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(51), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
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
  [88] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(43), 1,
      aux_sym_text_token1,
    ACTIONS(48), 1,
      anon_sym_POUND,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 6,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(41), 10,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [132] = 16,
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
    ACTIONS(57), 1,
      sym_entity,
    STATE(16), 1,
      sym_cf_tag_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(55), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(59), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(7), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [191] = 16,
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
    ACTIONS(63), 1,
      sym_entity,
    STATE(14), 1,
      sym_cf_tag_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(61), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(65), 2,
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
  [250] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      anon_sym_LT_BANG,
    ACTIONS(72), 1,
      sym__cf_tag_start,
    ACTIONS(75), 1,
      aux_sym_text_token1,
    ACTIONS(78), 1,
      anon_sym_LT,
    ACTIONS(81), 1,
      anon_sym_POUND,
    ACTIONS(84), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(87), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(67), 3,
      ts_builtin_sym_end,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [304] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(65), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(61), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [355] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(93), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(91), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [406] = 14,
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
    ACTIONS(95), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(91), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(93), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(15), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [459] = 15,
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
    ACTIONS(99), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(30), 1,
      sym_cf_tag_end,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(97), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(26), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [514] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(103), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(101), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [565] = 15,
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
    ACTIONS(107), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(29), 1,
      sym_cf_tag_end,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(105), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(27), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [620] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(111), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(109), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [671] = 14,
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
    ACTIONS(113), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(109), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(111), 2,
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
  [724] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(117), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(115), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [775] = 14,
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
    ACTIONS(63), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(61), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(65), 2,
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
  [828] = 12,
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
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(51), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(119), 6,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [876] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      anon_sym_LT_BANG,
    ACTIONS(125), 1,
      sym__cf_tag_start,
    ACTIONS(127), 1,
      aux_sym_text_token1,
    ACTIONS(129), 1,
      anon_sym_LT,
    ACTIONS(131), 1,
      anon_sym_LT_SLASH,
    ACTIONS(133), 1,
      anon_sym_POUND,
    ACTIONS(135), 1,
      sym_entity,
    ACTIONS(137), 1,
      sym__implicit_end_tag,
    STATE(22), 1,
      sym_start_tag,
    STATE(137), 1,
      sym_end_tag,
    STATE(221), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_script_start_tag,
    STATE(279), 1,
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
  [930] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(29), 1,
      sym_cf_comma,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(51), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(119), 9,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      anon_sym_LPAREN,
  [968] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(51), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(119), 10,
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
  [1004] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      sym_cf_period,
    ACTIONS(29), 1,
      sym_cf_comma,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(51), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(119), 8,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
  [1044] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      anon_sym_LT_BANG,
    ACTIONS(125), 1,
      sym__cf_tag_start,
    ACTIONS(127), 1,
      aux_sym_text_token1,
    ACTIONS(129), 1,
      anon_sym_LT,
    ACTIONS(133), 1,
      anon_sym_POUND,
    ACTIONS(139), 1,
      anon_sym_LT_SLASH,
    ACTIONS(141), 1,
      sym_entity,
    ACTIONS(143), 1,
      sym__implicit_end_tag,
    STATE(22), 1,
      sym_start_tag,
    STATE(221), 1,
      sym_self_closing_tag,
    STATE(227), 1,
      sym_end_tag,
    STATE(278), 1,
      sym_script_start_tag,
    STATE(279), 1,
      sym_style_start_tag,
    STATE(23), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1098] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      anon_sym_LT_BANG,
    ACTIONS(125), 1,
      sym__cf_tag_start,
    ACTIONS(127), 1,
      aux_sym_text_token1,
    ACTIONS(129), 1,
      anon_sym_LT,
    ACTIONS(133), 1,
      anon_sym_POUND,
    ACTIONS(135), 1,
      sym_entity,
    ACTIONS(139), 1,
      anon_sym_LT_SLASH,
    ACTIONS(145), 1,
      sym__implicit_end_tag,
    STATE(22), 1,
      sym_start_tag,
    STATE(221), 1,
      sym_self_closing_tag,
    STATE(238), 1,
      sym_end_tag,
    STATE(278), 1,
      sym_script_start_tag,
    STATE(279), 1,
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
  [1152] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      anon_sym_LT_BANG,
    ACTIONS(125), 1,
      sym__cf_tag_start,
    ACTIONS(127), 1,
      aux_sym_text_token1,
    ACTIONS(129), 1,
      anon_sym_LT,
    ACTIONS(131), 1,
      anon_sym_LT_SLASH,
    ACTIONS(133), 1,
      anon_sym_POUND,
    ACTIONS(147), 1,
      sym_entity,
    ACTIONS(149), 1,
      sym__implicit_end_tag,
    STATE(22), 1,
      sym_start_tag,
    STATE(145), 1,
      sym_end_tag,
    STATE(221), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_script_start_tag,
    STATE(279), 1,
      sym_style_start_tag,
    STATE(18), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1206] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(151), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1255] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(153), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1304] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(97), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1353] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      anon_sym_LT_BANG,
    ACTIONS(158), 1,
      sym__cf_tag_start,
    ACTIONS(161), 1,
      aux_sym_text_token1,
    ACTIONS(164), 1,
      anon_sym_LT,
    ACTIONS(167), 1,
      anon_sym_POUND,
    ACTIONS(170), 1,
      sym_entity,
    STATE(22), 1,
      sym_start_tag,
    STATE(221), 1,
      sym_self_closing_tag,
    STATE(278), 1,
      sym_script_start_tag,
    STATE(279), 1,
      sym_style_start_tag,
    ACTIONS(67), 2,
      sym__implicit_end_tag,
      anon_sym_LT_SLASH,
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
  [1402] = 13,
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
    ACTIONS(99), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(97), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(26), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1451] = 13,
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
    ACTIONS(173), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    ACTIONS(153), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(25), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1500] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    ACTIONS(175), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1548] = 13,
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
    ACTIONS(177), 1,
      sym_cf_tag_close,
    ACTIONS(179), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
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
  [1596] = 13,
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
    ACTIONS(175), 1,
      sym_cf_tag_close,
    ACTIONS(181), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
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
    ACTIONS(183), 1,
      sym_cf_tag_close,
    ACTIONS(185), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
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
  [1692] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    ACTIONS(187), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1740] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    ACTIONS(183), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1788] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    ACTIONS(189), 1,
      sym_cf_tag_close,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [1836] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(46), 2,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(41), 8,
      sym_cf_operator,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1874] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(195), 1,
      anon_sym_POUND,
    ACTIONS(197), 1,
      anon_sym_LBRACE,
    ACTIONS(41), 2,
      anon_sym_GT,
      sym_cf_operator,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(46), 8,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [1912] = 13,
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
    ACTIONS(199), 1,
      sym_cf_tag_close,
    ACTIONS(201), 1,
      sym_entity,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
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
  [1960] = 13,
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
    ACTIONS(89), 1,
      sym_entity,
    ACTIONS(203), 1,
      ts_builtin_sym_end,
    STATE(24), 1,
      sym_start_tag,
    STATE(118), 1,
      sym_self_closing_tag,
    STATE(283), 1,
      sym_style_start_tag,
    STATE(287), 1,
      sym_script_start_tag,
    STATE(6), 9,
      sym_doctype,
      sym_text,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_cf_hash,
      sym_cf_tag,
      aux_sym_fragment_repeat1,
  [2008] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(46), 3,
      anon_sym_SLASH,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 6,
      anon_sym_GT,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [2045] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(195), 1,
      anon_sym_POUND,
    ACTIONS(197), 1,
      anon_sym_LBRACE,
    ACTIONS(41), 2,
      anon_sym_GT,
      sym_cf_operator,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(46), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [2082] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(205), 11,
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
  [2108] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(211), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(209), 11,
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
  [2134] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(213), 11,
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
  [2160] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(217), 11,
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
  [2186] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(221), 11,
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
  [2212] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(227), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(225), 11,
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
  [2238] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(231), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(229), 11,
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
  [2264] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(235), 7,
      aux_sym_text_token1,
      anon_sym_LT,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(233), 11,
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
  [2290] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(48), 1,
      anon_sym_POUND,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(46), 2,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 5,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [2325] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(237), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 2,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
    ACTIONS(41), 5,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [2360] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 7,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2390] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 1,
      anon_sym_EQ,
    ACTIONS(221), 13,
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
  [2412] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      sym_cf_operator,
    ACTIONS(246), 1,
      sym_cf_period,
    ACTIONS(248), 1,
      sym_cf_comma,
    STATE(193), 1,
      sym_cf_assignment,
    ACTIONS(119), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 5,
      anon_sym_LBRACK,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [2444] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      sym_cf_operator,
    STATE(193), 1,
      sym_cf_assignment,
    ACTIONS(119), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [2472] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 8,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2500] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 6,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2532] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(211), 1,
      anon_sym_EQ,
    ACTIONS(209), 13,
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
  [2554] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    STATE(196), 1,
      sym_cf_assignment,
    ACTIONS(119), 3,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2592] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(258), 1,
      anon_sym_GT,
    ACTIONS(260), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(264), 1,
      sym_cf_period,
    ACTIONS(266), 1,
      sym_cf_comma,
    ACTIONS(268), 1,
      sym_cf_objectkeyassign,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(225), 1,
      sym_cf_tag_selfclose_end,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2634] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_EQ,
    ACTIONS(205), 13,
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
  [2656] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(227), 1,
      anon_sym_EQ,
    ACTIONS(225), 13,
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
  [2678] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(244), 1,
      sym_cf_operator,
    ACTIONS(246), 1,
      sym_cf_period,
    ACTIONS(248), 1,
      sym_cf_comma,
    ACTIONS(272), 1,
      anon_sym_LBRACK,
    ACTIONS(274), 1,
      sym_cf_objectkeyassign,
    ACTIONS(276), 1,
      anon_sym_LPAREN,
    ACTIONS(278), 1,
      sym_cf_attribute_name,
    STATE(193), 1,
      sym_cf_assignment,
    ACTIONS(270), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2718] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(231), 1,
      anon_sym_EQ,
    ACTIONS(229), 13,
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
  [2740] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(264), 1,
      sym_cf_period,
    ACTIONS(266), 1,
      sym_cf_comma,
    ACTIONS(268), 1,
      sym_cf_objectkeyassign,
    ACTIONS(280), 1,
      anon_sym_GT,
    ACTIONS(282), 1,
      anon_sym_SLASH,
    STATE(128), 1,
      sym_cf_tag_selfclose_end,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2782] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(264), 1,
      sym_cf_period,
    ACTIONS(266), 1,
      sym_cf_comma,
    ACTIONS(268), 1,
      sym_cf_objectkeyassign,
    ACTIONS(280), 1,
      anon_sym_GT,
    ACTIONS(282), 1,
      anon_sym_SLASH,
    STATE(123), 1,
      sym_cf_tag_selfclose_end,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2824] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_EQ,
    ACTIONS(217), 13,
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
  [2846] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(258), 1,
      anon_sym_GT,
    ACTIONS(260), 1,
      anon_sym_SLASH,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(264), 1,
      sym_cf_period,
    ACTIONS(266), 1,
      sym_cf_comma,
    ACTIONS(268), 1,
      sym_cf_objectkeyassign,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(234), 1,
      sym_cf_tag_selfclose_end,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2888] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      sym_cf_operator,
    ACTIONS(248), 1,
      sym_cf_comma,
    STATE(193), 1,
      sym_cf_assignment,
    ACTIONS(119), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [2918] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(121), 1,
      sym_cf_attribute_name,
    ACTIONS(244), 1,
      sym_cf_operator,
    ACTIONS(246), 1,
      sym_cf_period,
    ACTIONS(248), 1,
      sym_cf_comma,
    ACTIONS(272), 1,
      anon_sym_LBRACK,
    ACTIONS(274), 1,
      sym_cf_objectkeyassign,
    ACTIONS(276), 1,
      anon_sym_LPAREN,
    STATE(193), 1,
      sym_cf_assignment,
    ACTIONS(119), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2958] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(235), 1,
      anon_sym_EQ,
    ACTIONS(233), 13,
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
  [2980] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 1,
      anon_sym_EQ,
    ACTIONS(213), 13,
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
  [3002] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(270), 1,
      anon_sym_GT,
    ACTIONS(272), 1,
      anon_sym_LBRACK,
    ACTIONS(276), 1,
      anon_sym_LPAREN,
    ACTIONS(278), 1,
      sym_cf_attribute_name,
    ACTIONS(284), 1,
      sym_cf_operator,
    ACTIONS(286), 1,
      sym_cf_period,
    ACTIONS(288), 1,
      sym_cf_comma,
    ACTIONS(290), 1,
      sym_cf_objectkeyassign,
    STATE(204), 1,
      sym_cf_assignment,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3041] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(262), 1,
      sym_cf_operator,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 7,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [3068] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      anon_sym_GT,
    ACTIONS(284), 1,
      sym_cf_operator,
    ACTIONS(286), 1,
      sym_cf_period,
    ACTIONS(288), 1,
      sym_cf_comma,
    STATE(204), 1,
      sym_cf_assignment,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 5,
      anon_sym_LBRACK,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [3099] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      anon_sym_GT,
    ACTIONS(284), 1,
      sym_cf_operator,
    ACTIONS(288), 1,
      sym_cf_comma,
    STATE(204), 1,
      sym_cf_assignment,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [3128] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(264), 1,
      sym_cf_period,
    ACTIONS(266), 1,
      sym_cf_comma,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 5,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [3159] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(266), 1,
      sym_cf_comma,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 6,
      anon_sym_GT,
      anon_sym_SLASH,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [3188] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(262), 1,
      sym_cf_operator,
    ACTIONS(264), 1,
      sym_cf_period,
    ACTIONS(266), 1,
      sym_cf_comma,
    ACTIONS(268), 1,
      sym_cf_objectkeyassign,
    STATE(155), 1,
      sym_cf_assignment,
    ACTIONS(119), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3225] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(119), 1,
      anon_sym_GT,
    ACTIONS(121), 1,
      sym_cf_attribute_name,
    ACTIONS(272), 1,
      anon_sym_LBRACK,
    ACTIONS(276), 1,
      anon_sym_LPAREN,
    ACTIONS(284), 1,
      sym_cf_operator,
    ACTIONS(286), 1,
      sym_cf_period,
    ACTIONS(288), 1,
      sym_cf_comma,
    ACTIONS(290), 1,
      sym_cf_objectkeyassign,
    STATE(204), 1,
      sym_cf_assignment,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3264] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      anon_sym_GT,
    ACTIONS(284), 1,
      sym_cf_operator,
    STATE(204), 1,
      sym_cf_assignment,
    STATE(203), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(121), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [3291] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(294), 1,
      anon_sym_POUND,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    ACTIONS(300), 1,
      sym_cf_objectkeyassign,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3327] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(292), 1,
      sym_cf_operator,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 6,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [3353] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    ACTIONS(300), 1,
      sym_cf_objectkeyassign,
    ACTIONS(302), 1,
      anon_sym_POUND,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3389] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    ACTIONS(300), 1,
      sym_cf_objectkeyassign,
    ACTIONS(304), 1,
      anon_sym_POUND,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3425] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3461] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      sym_cf_operator,
    ACTIONS(310), 1,
      sym_cf_period,
    ACTIONS(312), 1,
      sym_cf_comma,
    ACTIONS(314), 1,
      sym_cf_objectkeyassign,
    ACTIONS(316), 1,
      anon_sym_DQUOTE,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3497] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      sym_cf_operator,
    ACTIONS(310), 1,
      sym_cf_period,
    ACTIONS(312), 1,
      sym_cf_comma,
    ACTIONS(314), 1,
      sym_cf_objectkeyassign,
    ACTIONS(318), 1,
      anon_sym_DQUOTE,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3533] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3569] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(322), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3605] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(308), 1,
      sym_cf_operator,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3631] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(308), 1,
      sym_cf_operator,
    ACTIONS(310), 1,
      sym_cf_period,
    ACTIONS(312), 1,
      sym_cf_comma,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 4,
      anon_sym_LBRACK,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3661] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    ACTIONS(300), 1,
      sym_cf_objectkeyassign,
    ACTIONS(324), 1,
      anon_sym_POUND,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3697] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(308), 1,
      sym_cf_operator,
    ACTIONS(312), 1,
      sym_cf_comma,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 5,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3725] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    ACTIONS(300), 1,
      sym_cf_objectkeyassign,
    ACTIONS(326), 1,
      anon_sym_POUND,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3761] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(328), 1,
      anon_sym_RBRACK,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3797] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 4,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [3827] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(330), 1,
      anon_sym_RPAREN,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3863] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_EQ,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(298), 1,
      sym_cf_comma,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(119), 5,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
  [3891] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(119), 1,
      anon_sym_POUND,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      sym_cf_operator,
    ACTIONS(296), 1,
      sym_cf_period,
    ACTIONS(298), 1,
      sym_cf_comma,
    ACTIONS(300), 1,
      sym_cf_objectkeyassign,
    STATE(181), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3927] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(119), 1,
      anon_sym_DQUOTE,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      sym_cf_operator,
    ACTIONS(310), 1,
      sym_cf_period,
    ACTIONS(312), 1,
      sym_cf_comma,
    ACTIONS(314), 1,
      sym_cf_objectkeyassign,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3963] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(308), 1,
      sym_cf_operator,
    ACTIONS(310), 1,
      sym_cf_period,
    ACTIONS(312), 1,
      sym_cf_comma,
    ACTIONS(314), 1,
      sym_cf_objectkeyassign,
    ACTIONS(332), 1,
      anon_sym_DQUOTE,
    STATE(170), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [3999] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4035] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(336), 1,
      anon_sym_RBRACK,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4071] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(338), 1,
      anon_sym_RPAREN,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4107] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_EQ,
    ACTIONS(240), 1,
      sym_cf_operator,
    ACTIONS(242), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      sym_cf_period,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      sym_cf_objectkeyassign,
    ACTIONS(256), 1,
      anon_sym_LPAREN,
    ACTIONS(340), 1,
      anon_sym_RBRACK,
    STATE(196), 1,
      sym_cf_assignment,
    STATE(73), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [4143] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(342), 1,
      anon_sym_set,
    ACTIONS(344), 1,
      sym_cf_if_keyword,
    ACTIONS(346), 1,
      sym_cf_function_keyword,
    ACTIONS(348), 1,
      sym_cf_argument_keyword,
    ACTIONS(350), 1,
      sym_cf_return_keyword,
    STATE(210), 1,
      sym_cf_if,
    STATE(224), 5,
      sym_cf_function,
      sym_cf_argument,
      sym_cf_return,
      sym_cf_ifstatement,
      sym_cf_set,
  [4172] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(356), 1,
      anon_sym_RPAREN,
    STATE(105), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4199] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(344), 1,
      sym_cf_if_keyword,
    ACTIONS(358), 1,
      anon_sym_set,
    ACTIONS(360), 1,
      sym_cf_function_keyword,
    ACTIONS(362), 1,
      sym_cf_argument_keyword,
    ACTIONS(364), 1,
      sym_cf_return_keyword,
    STATE(208), 1,
      sym_cf_if,
    STATE(139), 5,
      sym_cf_function,
      sym_cf_argument,
      sym_cf_return,
      sym_cf_ifstatement,
      sym_cf_set,
  [4228] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(368), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(366), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4247] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(372), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(370), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4266] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(376), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(374), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4285] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(380), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(378), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4304] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(384), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(382), 6,
      anon_sym_LT_BANG,
      anon_sym_GT,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4323] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(388), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(386), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4342] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(392), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(390), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4361] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(396), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(394), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4380] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(398), 1,
      anon_sym_RPAREN,
    STATE(100), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4407] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    ACTIONS(402), 1,
      sym_cf_var,
    STATE(67), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4434] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(404), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4453] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(410), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(408), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4472] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(414), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(412), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4491] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(418), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(416), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4510] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(422), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(420), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4529] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(426), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(424), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4548] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(430), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(428), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4567] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(432), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4586] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(438), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(436), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4605] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(442), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(440), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4624] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(446), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(444), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4643] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(450), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(448), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4662] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(454), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(452), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4681] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(458), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(456), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4700] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(462), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(460), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4719] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(466), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(464), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4738] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    ACTIONS(468), 1,
      anon_sym_RPAREN,
    STATE(107), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4765] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(472), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(470), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4784] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(476), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(474), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4803] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(480), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(478), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4822] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(484), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(482), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4841] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(191), 1,
      aux_sym_text_token1,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    ACTIONS(486), 1,
      sym_cf_var,
    STATE(70), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4868] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(490), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(488), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4887] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(494), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(492), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4906] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(231), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(229), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4925] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(498), 5,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(496), 6,
      ts_builtin_sym_end,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACE,
  [4944] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(84), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4968] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      aux_sym_text_token1,
    ACTIONS(504), 1,
      anon_sym_POUND,
    ACTIONS(506), 1,
      anon_sym_LBRACE,
    ACTIONS(508), 1,
      anon_sym_DQUOTE,
    STATE(17), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [4992] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(101), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5016] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(99), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5040] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(98), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5064] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(85), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5088] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(53), 1,
      anon_sym_DQUOTE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5112] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(81), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5136] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(80), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5160] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(510), 1,
      anon_sym_DQUOTE,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5184] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(79), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5208] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(76), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5232] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(518), 1,
      anon_sym_DQUOTE,
    STATE(75), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5256] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(92), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5280] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(520), 1,
      anon_sym_DQUOTE,
    STATE(89), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5304] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(91), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5328] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(62), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5352] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(108), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5376] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(522), 1,
      anon_sym_DQUOTE,
    STATE(93), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5400] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(524), 1,
      anon_sym_DQUOTE,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5424] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(526), 1,
      anon_sym_DQUOTE,
    STATE(104), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5448] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(522), 1,
      anon_sym_DQUOTE,
    STATE(96), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5472] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(522), 1,
      anon_sym_DQUOTE,
    STATE(103), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5496] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(518), 1,
      anon_sym_DQUOTE,
    STATE(83), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5520] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(528), 1,
      anon_sym_DQUOTE,
    STATE(89), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5544] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(530), 1,
      anon_sym_DQUOTE,
    STATE(65), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5568] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(219), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5586] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      aux_sym_text_token1,
    ACTIONS(504), 1,
      anon_sym_POUND,
    ACTIONS(506), 1,
      anon_sym_LBRACE,
    ACTIONS(508), 1,
      anon_sym_DQUOTE,
    STATE(20), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5610] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(87), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5634] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      aux_sym_text_token1,
    ACTIONS(504), 1,
      anon_sym_POUND,
    ACTIONS(506), 1,
      anon_sym_LBRACE,
    ACTIONS(508), 1,
      anon_sym_DQUOTE,
    STATE(21), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5658] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      aux_sym_text_token1,
    ACTIONS(504), 1,
      anon_sym_POUND,
    ACTIONS(506), 1,
      anon_sym_LBRACE,
    ACTIONS(508), 1,
      anon_sym_DQUOTE,
    STATE(19), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5682] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(522), 1,
      anon_sym_DQUOTE,
    STATE(94), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5706] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(532), 1,
      anon_sym_DQUOTE,
    STATE(90), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5730] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(102), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5754] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(229), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(231), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5772] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(58), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5796] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(530), 1,
      anon_sym_DQUOTE,
    STATE(57), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5820] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(530), 1,
      anon_sym_DQUOTE,
    STATE(56), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5844] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      aux_sym_text_token1,
    ACTIONS(504), 1,
      anon_sym_POUND,
    ACTIONS(506), 1,
      anon_sym_LBRACE,
    ACTIONS(508), 1,
      anon_sym_DQUOTE,
    STATE(2), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5868] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(223), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5886] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(213), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(215), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5904] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(209), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(211), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [5922] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(68), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5946] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(530), 1,
      anon_sym_DQUOTE,
    STATE(71), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5970] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(59), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [5994] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(530), 1,
      anon_sym_DQUOTE,
    STATE(72), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6018] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(54), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6042] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(97), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6066] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(61), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6090] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(88), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6114] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(106), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6138] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(95), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6162] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      anon_sym_LBRACE,
    ACTIONS(193), 1,
      anon_sym_POUND,
    ACTIONS(352), 1,
      aux_sym_text_token1,
    ACTIONS(500), 1,
      anon_sym_DQUOTE,
    STATE(86), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6186] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(205), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(207), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [6204] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(227), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [6222] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(233), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_operator,
    ACTIONS(235), 7,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      sym_cf_objectkeyassign,
      anon_sym_LPAREN,
      sym_cf_attribute_name,
  [6240] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(518), 1,
      anon_sym_DQUOTE,
    STATE(82), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6264] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(518), 1,
      anon_sym_DQUOTE,
    STATE(78), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6288] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      aux_sym_text_token1,
    ACTIONS(514), 1,
      anon_sym_POUND,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(518), 1,
      anon_sym_DQUOTE,
    STATE(77), 6,
      sym_cf_variable,
      sym_cf_hash,
      sym_cf_bracket,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [6312] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(534), 1,
      sym__cf_tag_start,
    ACTIONS(536), 1,
      sym_cf_tag_close,
    ACTIONS(538), 1,
      anon_sym_RBRACE,
    ACTIONS(540), 1,
      sym_cf_elseif_keyword,
    ACTIONS(542), 1,
      sym_cf_else_keyword,
    STATE(117), 1,
      sym_cf_if_end,
    STATE(282), 1,
      sym_cf_else,
    STATE(244), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [6341] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(534), 1,
      sym__cf_tag_start,
    ACTIONS(536), 1,
      sym_cf_tag_close,
    ACTIONS(538), 1,
      anon_sym_RBRACE,
    ACTIONS(540), 1,
      sym_cf_elseif_keyword,
    ACTIONS(542), 1,
      sym_cf_else_keyword,
    STATE(134), 1,
      sym_cf_if_end,
    STATE(275), 1,
      sym_cf_else,
    STATE(207), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [6370] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(534), 1,
      sym__cf_tag_start,
    ACTIONS(540), 1,
      sym_cf_elseif_keyword,
    ACTIONS(542), 1,
      sym_cf_else_keyword,
    ACTIONS(544), 1,
      sym_cf_tag_close,
    ACTIONS(546), 1,
      anon_sym_RBRACE,
    STATE(230), 1,
      sym_cf_if_end,
    STATE(276), 1,
      sym_cf_else,
    STATE(244), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [6399] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(534), 1,
      sym__cf_tag_start,
    ACTIONS(540), 1,
      sym_cf_elseif_keyword,
    ACTIONS(542), 1,
      sym_cf_else_keyword,
    ACTIONS(544), 1,
      sym_cf_tag_close,
    ACTIONS(546), 1,
      anon_sym_RBRACE,
    STATE(211), 1,
      sym_cf_if_end,
    STATE(288), 1,
      sym_cf_else,
    STATE(209), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [6428] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(454), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(452), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6444] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(396), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(394), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6460] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(418), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(416), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6476] = 3,
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
  [6492] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(498), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(496), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6508] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(490), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(488), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6524] = 3,
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
  [6540] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(380), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(378), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6556] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(231), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(229), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6572] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(476), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(474), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6588] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(392), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(390), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6604] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(450), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(448), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6620] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(438), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(436), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6636] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(472), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(470), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6652] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(410), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(408), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6668] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(404), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6684] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(494), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(492), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6700] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(426), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(424), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6716] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(446), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(444), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6732] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(388), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(386), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6748] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(376), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(374), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6764] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(372), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(370), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6780] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(368), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(366), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6796] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(430), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(428), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6812] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(442), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(440), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6828] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(458), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(456), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6844] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(462), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(460), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6860] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(466), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(464), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6876] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(432), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6892] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(484), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(482), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6908] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(480), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(478), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6924] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(422), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(420), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6940] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(414), 3,
      aux_sym_text_token1,
      anon_sym_LT,
      sym_entity,
    ACTIONS(412), 5,
      sym__implicit_end_tag,
      anon_sym_LT_BANG,
      sym__cf_tag_start,
      anon_sym_LT_SLASH,
      anon_sym_POUND,
  [6956] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(556), 1,
      sym__cf_tag_start,
    ACTIONS(561), 1,
      sym_cf_elseif_keyword,
    ACTIONS(564), 1,
      sym_cf_else_keyword,
    ACTIONS(559), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(244), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [6977] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_GT,
    ACTIONS(282), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(124), 1,
      sym_cf_tag_selfclose_end,
    STATE(252), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [6997] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_GT,
    ACTIONS(260), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(231), 1,
      sym_cf_tag_selfclose_end,
    STATE(255), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7017] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_GT,
    ACTIONS(282), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(125), 1,
      sym_cf_tag_selfclose_end,
    STATE(251), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7037] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_GT,
    ACTIONS(260), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(232), 1,
      sym_cf_tag_selfclose_end,
    STATE(255), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7057] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_GT,
    ACTIONS(260), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(213), 1,
      sym_cf_tag_selfclose_end,
    STATE(246), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7077] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_GT,
    ACTIONS(260), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(243), 1,
      sym_cf_tag_selfclose_end,
    STATE(248), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7097] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_GT,
    ACTIONS(282), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(114), 1,
      sym_cf_tag_selfclose_end,
    STATE(255), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7117] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_GT,
    ACTIONS(282), 1,
      anon_sym_SLASH,
    ACTIONS(566), 1,
      sym_cf_attribute_name,
    STATE(113), 1,
      sym_cf_tag_selfclose_end,
    STATE(255), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7137] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(568), 1,
      sym_cf_attribute_name,
    STATE(34), 1,
      sym_cf_tag_end,
    STATE(270), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7154] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(570), 1,
      anon_sym_GT,
    ACTIONS(572), 1,
      anon_sym_SLASH_GT,
    ACTIONS(574), 1,
      sym_attribute_name,
    STATE(260), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7171] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(578), 1,
      sym_cf_attribute_name,
    ACTIONS(576), 2,
      anon_sym_GT,
      anon_sym_SLASH,
    STATE(255), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7186] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(568), 1,
      sym_cf_attribute_name,
    STATE(32), 1,
      sym_cf_tag_end,
    STATE(253), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7203] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(568), 1,
      sym_cf_attribute_name,
    STATE(33), 1,
      sym_cf_tag_end,
    STATE(270), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7220] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(574), 1,
      sym_attribute_name,
    ACTIONS(581), 1,
      anon_sym_GT,
    ACTIONS(583), 1,
      anon_sym_SLASH_GT,
    STATE(254), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7237] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(570), 1,
      anon_sym_GT,
    ACTIONS(574), 1,
      sym_attribute_name,
    ACTIONS(585), 1,
      anon_sym_SLASH_GT,
    STATE(260), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7254] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(589), 1,
      sym_attribute_name,
    ACTIONS(587), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(260), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7269] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(574), 1,
      sym_attribute_name,
    ACTIONS(581), 1,
      anon_sym_GT,
    ACTIONS(592), 1,
      anon_sym_SLASH_GT,
    STATE(259), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7286] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    ACTIONS(568), 1,
      sym_cf_attribute_name,
    STATE(40), 1,
      sym_cf_tag_end,
    STATE(257), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7303] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(596), 1,
      anon_sym_EQ,
    ACTIONS(594), 3,
      anon_sym_GT,
      anon_sym_SLASH,
      sym_cf_attribute_name,
  [7315] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(598), 1,
      anon_sym_GT,
    ACTIONS(600), 1,
      sym_attribute_name,
    STATE(266), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7329] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(600), 1,
      sym_attribute_name,
    ACTIONS(602), 1,
      anon_sym_GT,
    STATE(268), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7343] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(600), 1,
      sym_attribute_name,
    ACTIONS(604), 1,
      anon_sym_GT,
    STATE(272), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7357] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(606), 1,
      anon_sym_DQUOTE,
    ACTIONS(608), 1,
      sym_attribute_value,
    ACTIONS(610), 1,
      anon_sym_SQUOTE,
    STATE(297), 1,
      sym_quoted_attribute_value,
  [7373] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(600), 1,
      sym_attribute_name,
    ACTIONS(612), 1,
      anon_sym_GT,
    STATE(272), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7387] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(614), 4,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACE,
      anon_sym_DQUOTE,
  [7397] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(576), 1,
      anon_sym_GT,
    ACTIONS(616), 1,
      sym_cf_attribute_name,
    STATE(270), 2,
      sym_cf_attribute,
      aux_sym_cf_function_repeat1,
  [7411] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(621), 1,
      anon_sym_EQ,
    ACTIONS(619), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [7423] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_GT,
    ACTIONS(623), 1,
      sym_attribute_name,
    STATE(272), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [7437] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(626), 1,
      anon_sym_DQUOTE,
    ACTIONS(628), 1,
      sym_attribute_value,
    ACTIONS(630), 1,
      anon_sym_SQUOTE,
    STATE(277), 1,
      sym_quoted_attribute_value,
  [7453] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(632), 1,
      anon_sym_EQ,
    ACTIONS(619), 2,
      anon_sym_GT,
      sym_attribute_name,
  [7464] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(536), 1,
      sym_cf_tag_close,
    ACTIONS(538), 1,
      anon_sym_RBRACE,
    STATE(117), 1,
      sym_cf_if_end,
  [7477] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(544), 1,
      sym_cf_tag_close,
    ACTIONS(546), 1,
      anon_sym_RBRACE,
    STATE(222), 1,
      sym_cf_if_end,
  [7490] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(634), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [7499] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_LT_SLASH,
    ACTIONS(636), 1,
      sym_raw_text,
    STATE(229), 1,
      sym_end_tag,
  [7512] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_LT_SLASH,
    ACTIONS(638), 1,
      sym_raw_text,
    STATE(239), 1,
      sym_end_tag,
  [7525] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(640), 1,
      anon_sym_EQ,
    ACTIONS(594), 2,
      anon_sym_GT,
      sym_cf_attribute_name,
  [7536] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(642), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [7545] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(536), 1,
      sym_cf_tag_close,
    ACTIONS(538), 1,
      anon_sym_RBRACE,
    STATE(133), 1,
      sym_cf_if_end,
  [7558] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      anon_sym_LT_SLASH,
    ACTIONS(644), 1,
      sym_raw_text,
    STATE(129), 1,
      sym_end_tag,
  [7571] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(646), 1,
      sym__start_tag_name,
    ACTIONS(648), 1,
      sym__script_start_tag_name,
    ACTIONS(650), 1,
      sym__style_start_tag_name,
  [7584] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(648), 1,
      sym__script_start_tag_name,
    ACTIONS(650), 1,
      sym__style_start_tag_name,
    ACTIONS(652), 1,
      sym__start_tag_name,
  [7597] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [7606] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      anon_sym_LT_SLASH,
    ACTIONS(656), 1,
      sym_raw_text,
    STATE(132), 1,
      sym_end_tag,
  [7619] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(544), 1,
      sym_cf_tag_close,
    ACTIONS(546), 1,
      anon_sym_RBRACE,
    STATE(230), 1,
      sym_cf_if_end,
  [7632] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(658), 1,
      anon_sym_SQUOTE,
    ACTIONS(660), 1,
      aux_sym_quoted_attribute_value_token1,
  [7642] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(662), 1,
      aux_sym_cf_condition_token1,
    STATE(4), 1,
      sym_cf_condition,
  [7652] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 2,
      anon_sym_GT,
      sym_attribute_name,
  [7660] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(642), 2,
      anon_sym_GT,
      sym_attribute_name,
  [7668] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    STATE(144), 1,
      sym_cf_tag_end,
  [7678] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(664), 1,
      anon_sym_SQUOTE,
    ACTIONS(666), 1,
      aux_sym_quoted_attribute_value_token1,
  [7688] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(668), 1,
      anon_sym_GT,
    STATE(216), 1,
      sym_cf_tag_end,
  [7698] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(662), 1,
      aux_sym_cf_condition_token1,
    STATE(5), 1,
      sym_cf_condition,
  [7708] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(634), 2,
      anon_sym_GT,
      sym_attribute_name,
  [7716] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(668), 1,
      anon_sym_GT,
    STATE(220), 1,
      sym_cf_tag_end,
  [7726] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_LT_SLASH,
    STATE(237), 1,
      sym_end_tag,
  [7736] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(664), 1,
      anon_sym_DQUOTE,
    ACTIONS(670), 1,
      aux_sym_quoted_attribute_value_token2,
  [7746] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_LT_SLASH,
    STATE(236), 1,
      sym_end_tag,
  [7756] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      anon_sym_LT_SLASH,
    STATE(136), 1,
      sym_end_tag,
  [7766] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      anon_sym_LT_SLASH,
    STATE(135), 1,
      sym_end_tag,
  [7776] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(672), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [7784] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    STATE(140), 1,
      sym_cf_tag_end,
  [7794] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(19), 1,
      anon_sym_GT,
    STATE(147), 1,
      sym_cf_tag_end,
  [7804] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(674), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [7812] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(676), 1,
      sym_cf_elseif_keyword,
    ACTIONS(678), 1,
      sym_cf_else_keyword,
  [7822] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(680), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [7830] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(682), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [7838] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(668), 1,
      anon_sym_GT,
    STATE(215), 1,
      sym_cf_tag_end,
  [7848] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(658), 1,
      anon_sym_DQUOTE,
    ACTIONS(684), 1,
      aux_sym_quoted_attribute_value_token2,
  [7858] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(686), 1,
      sym_cf_function_keyword,
  [7865] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(688), 1,
      sym_cf_function_keyword,
  [7872] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(690), 1,
      sym_cf_if_keyword,
  [7879] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(692), 1,
      sym_cf_function_keyword,
  [7886] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(694), 1,
      anon_sym_DQUOTE,
  [7893] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(696), 1,
      anon_sym_GT,
  [7900] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(694), 1,
      anon_sym_SQUOTE,
  [7907] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(698), 1,
      anon_sym_SQUOTE,
  [7914] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(700), 1,
      anon_sym_GT,
  [7921] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(702), 1,
      sym__end_tag_name,
  [7928] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(704), 1,
      aux_sym_doctype_token1,
  [7935] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(706), 1,
      sym__end_tag_name,
  [7942] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(708), 1,
      anon_sym_GT,
  [7949] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(710), 1,
      sym_cf_if_keyword,
  [7956] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(712), 1,
      anon_sym_GT,
  [7963] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(714), 1,
      anon_sym_GT,
  [7970] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(716), 1,
      anon_sym_GT,
  [7977] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(698), 1,
      anon_sym_DQUOTE,
  [7984] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(718), 1,
      aux_sym_doctype_token1,
  [7991] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(720), 1,
      sym__doctype,
  [7998] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(722), 1,
      anon_sym_GT,
  [8005] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(724), 1,
      ts_builtin_sym_end,
  [8012] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(726), 1,
      sym__doctype,
  [8019] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(728), 1,
      sym_cf_function_keyword,
  [8026] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(730), 1,
      sym_cf_function_keyword,
  [8033] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(732), 1,
      anon_sym_GT,
  [8040] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(676), 1,
      sym_cf_elseif_keyword,
  [8047] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(734), 1,
      sym_cf_function_keyword,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 88,
  [SMALL_STATE(4)] = 132,
  [SMALL_STATE(5)] = 191,
  [SMALL_STATE(6)] = 250,
  [SMALL_STATE(7)] = 304,
  [SMALL_STATE(8)] = 355,
  [SMALL_STATE(9)] = 406,
  [SMALL_STATE(10)] = 459,
  [SMALL_STATE(11)] = 514,
  [SMALL_STATE(12)] = 565,
  [SMALL_STATE(13)] = 620,
  [SMALL_STATE(14)] = 671,
  [SMALL_STATE(15)] = 724,
  [SMALL_STATE(16)] = 775,
  [SMALL_STATE(17)] = 828,
  [SMALL_STATE(18)] = 876,
  [SMALL_STATE(19)] = 930,
  [SMALL_STATE(20)] = 968,
  [SMALL_STATE(21)] = 1004,
  [SMALL_STATE(22)] = 1044,
  [SMALL_STATE(23)] = 1098,
  [SMALL_STATE(24)] = 1152,
  [SMALL_STATE(25)] = 1206,
  [SMALL_STATE(26)] = 1255,
  [SMALL_STATE(27)] = 1304,
  [SMALL_STATE(28)] = 1353,
  [SMALL_STATE(29)] = 1402,
  [SMALL_STATE(30)] = 1451,
  [SMALL_STATE(31)] = 1500,
  [SMALL_STATE(32)] = 1548,
  [SMALL_STATE(33)] = 1596,
  [SMALL_STATE(34)] = 1644,
  [SMALL_STATE(35)] = 1692,
  [SMALL_STATE(36)] = 1740,
  [SMALL_STATE(37)] = 1788,
  [SMALL_STATE(38)] = 1836,
  [SMALL_STATE(39)] = 1874,
  [SMALL_STATE(40)] = 1912,
  [SMALL_STATE(41)] = 1960,
  [SMALL_STATE(42)] = 2008,
  [SMALL_STATE(43)] = 2045,
  [SMALL_STATE(44)] = 2082,
  [SMALL_STATE(45)] = 2108,
  [SMALL_STATE(46)] = 2134,
  [SMALL_STATE(47)] = 2160,
  [SMALL_STATE(48)] = 2186,
  [SMALL_STATE(49)] = 2212,
  [SMALL_STATE(50)] = 2238,
  [SMALL_STATE(51)] = 2264,
  [SMALL_STATE(52)] = 2290,
  [SMALL_STATE(53)] = 2325,
  [SMALL_STATE(54)] = 2360,
  [SMALL_STATE(55)] = 2390,
  [SMALL_STATE(56)] = 2412,
  [SMALL_STATE(57)] = 2444,
  [SMALL_STATE(58)] = 2472,
  [SMALL_STATE(59)] = 2500,
  [SMALL_STATE(60)] = 2532,
  [SMALL_STATE(61)] = 2554,
  [SMALL_STATE(62)] = 2592,
  [SMALL_STATE(63)] = 2634,
  [SMALL_STATE(64)] = 2656,
  [SMALL_STATE(65)] = 2678,
  [SMALL_STATE(66)] = 2718,
  [SMALL_STATE(67)] = 2740,
  [SMALL_STATE(68)] = 2782,
  [SMALL_STATE(69)] = 2824,
  [SMALL_STATE(70)] = 2846,
  [SMALL_STATE(71)] = 2888,
  [SMALL_STATE(72)] = 2918,
  [SMALL_STATE(73)] = 2958,
  [SMALL_STATE(74)] = 2980,
  [SMALL_STATE(75)] = 3002,
  [SMALL_STATE(76)] = 3041,
  [SMALL_STATE(77)] = 3068,
  [SMALL_STATE(78)] = 3099,
  [SMALL_STATE(79)] = 3128,
  [SMALL_STATE(80)] = 3159,
  [SMALL_STATE(81)] = 3188,
  [SMALL_STATE(82)] = 3225,
  [SMALL_STATE(83)] = 3264,
  [SMALL_STATE(84)] = 3291,
  [SMALL_STATE(85)] = 3327,
  [SMALL_STATE(86)] = 3353,
  [SMALL_STATE(87)] = 3389,
  [SMALL_STATE(88)] = 3425,
  [SMALL_STATE(89)] = 3461,
  [SMALL_STATE(90)] = 3497,
  [SMALL_STATE(91)] = 3533,
  [SMALL_STATE(92)] = 3569,
  [SMALL_STATE(93)] = 3605,
  [SMALL_STATE(94)] = 3631,
  [SMALL_STATE(95)] = 3661,
  [SMALL_STATE(96)] = 3697,
  [SMALL_STATE(97)] = 3725,
  [SMALL_STATE(98)] = 3761,
  [SMALL_STATE(99)] = 3797,
  [SMALL_STATE(100)] = 3827,
  [SMALL_STATE(101)] = 3863,
  [SMALL_STATE(102)] = 3891,
  [SMALL_STATE(103)] = 3927,
  [SMALL_STATE(104)] = 3963,
  [SMALL_STATE(105)] = 3999,
  [SMALL_STATE(106)] = 4035,
  [SMALL_STATE(107)] = 4071,
  [SMALL_STATE(108)] = 4107,
  [SMALL_STATE(109)] = 4143,
  [SMALL_STATE(110)] = 4172,
  [SMALL_STATE(111)] = 4199,
  [SMALL_STATE(112)] = 4228,
  [SMALL_STATE(113)] = 4247,
  [SMALL_STATE(114)] = 4266,
  [SMALL_STATE(115)] = 4285,
  [SMALL_STATE(116)] = 4304,
  [SMALL_STATE(117)] = 4323,
  [SMALL_STATE(118)] = 4342,
  [SMALL_STATE(119)] = 4361,
  [SMALL_STATE(120)] = 4380,
  [SMALL_STATE(121)] = 4407,
  [SMALL_STATE(122)] = 4434,
  [SMALL_STATE(123)] = 4453,
  [SMALL_STATE(124)] = 4472,
  [SMALL_STATE(125)] = 4491,
  [SMALL_STATE(126)] = 4510,
  [SMALL_STATE(127)] = 4529,
  [SMALL_STATE(128)] = 4548,
  [SMALL_STATE(129)] = 4567,
  [SMALL_STATE(130)] = 4586,
  [SMALL_STATE(131)] = 4605,
  [SMALL_STATE(132)] = 4624,
  [SMALL_STATE(133)] = 4643,
  [SMALL_STATE(134)] = 4662,
  [SMALL_STATE(135)] = 4681,
  [SMALL_STATE(136)] = 4700,
  [SMALL_STATE(137)] = 4719,
  [SMALL_STATE(138)] = 4738,
  [SMALL_STATE(139)] = 4765,
  [SMALL_STATE(140)] = 4784,
  [SMALL_STATE(141)] = 4803,
  [SMALL_STATE(142)] = 4822,
  [SMALL_STATE(143)] = 4841,
  [SMALL_STATE(144)] = 4868,
  [SMALL_STATE(145)] = 4887,
  [SMALL_STATE(146)] = 4906,
  [SMALL_STATE(147)] = 4925,
  [SMALL_STATE(148)] = 4944,
  [SMALL_STATE(149)] = 4968,
  [SMALL_STATE(150)] = 4992,
  [SMALL_STATE(151)] = 5016,
  [SMALL_STATE(152)] = 5040,
  [SMALL_STATE(153)] = 5064,
  [SMALL_STATE(154)] = 5088,
  [SMALL_STATE(155)] = 5112,
  [SMALL_STATE(156)] = 5136,
  [SMALL_STATE(157)] = 5160,
  [SMALL_STATE(158)] = 5184,
  [SMALL_STATE(159)] = 5208,
  [SMALL_STATE(160)] = 5232,
  [SMALL_STATE(161)] = 5256,
  [SMALL_STATE(162)] = 5280,
  [SMALL_STATE(163)] = 5304,
  [SMALL_STATE(164)] = 5328,
  [SMALL_STATE(165)] = 5352,
  [SMALL_STATE(166)] = 5376,
  [SMALL_STATE(167)] = 5400,
  [SMALL_STATE(168)] = 5424,
  [SMALL_STATE(169)] = 5448,
  [SMALL_STATE(170)] = 5472,
  [SMALL_STATE(171)] = 5496,
  [SMALL_STATE(172)] = 5520,
  [SMALL_STATE(173)] = 5544,
  [SMALL_STATE(174)] = 5568,
  [SMALL_STATE(175)] = 5586,
  [SMALL_STATE(176)] = 5610,
  [SMALL_STATE(177)] = 5634,
  [SMALL_STATE(178)] = 5658,
  [SMALL_STATE(179)] = 5682,
  [SMALL_STATE(180)] = 5706,
  [SMALL_STATE(181)] = 5730,
  [SMALL_STATE(182)] = 5754,
  [SMALL_STATE(183)] = 5772,
  [SMALL_STATE(184)] = 5796,
  [SMALL_STATE(185)] = 5820,
  [SMALL_STATE(186)] = 5844,
  [SMALL_STATE(187)] = 5868,
  [SMALL_STATE(188)] = 5886,
  [SMALL_STATE(189)] = 5904,
  [SMALL_STATE(190)] = 5922,
  [SMALL_STATE(191)] = 5946,
  [SMALL_STATE(192)] = 5970,
  [SMALL_STATE(193)] = 5994,
  [SMALL_STATE(194)] = 6018,
  [SMALL_STATE(195)] = 6042,
  [SMALL_STATE(196)] = 6066,
  [SMALL_STATE(197)] = 6090,
  [SMALL_STATE(198)] = 6114,
  [SMALL_STATE(199)] = 6138,
  [SMALL_STATE(200)] = 6162,
  [SMALL_STATE(201)] = 6186,
  [SMALL_STATE(202)] = 6204,
  [SMALL_STATE(203)] = 6222,
  [SMALL_STATE(204)] = 6240,
  [SMALL_STATE(205)] = 6264,
  [SMALL_STATE(206)] = 6288,
  [SMALL_STATE(207)] = 6312,
  [SMALL_STATE(208)] = 6341,
  [SMALL_STATE(209)] = 6370,
  [SMALL_STATE(210)] = 6399,
  [SMALL_STATE(211)] = 6428,
  [SMALL_STATE(212)] = 6444,
  [SMALL_STATE(213)] = 6460,
  [SMALL_STATE(214)] = 6476,
  [SMALL_STATE(215)] = 6492,
  [SMALL_STATE(216)] = 6508,
  [SMALL_STATE(217)] = 6524,
  [SMALL_STATE(218)] = 6540,
  [SMALL_STATE(219)] = 6556,
  [SMALL_STATE(220)] = 6572,
  [SMALL_STATE(221)] = 6588,
  [SMALL_STATE(222)] = 6604,
  [SMALL_STATE(223)] = 6620,
  [SMALL_STATE(224)] = 6636,
  [SMALL_STATE(225)] = 6652,
  [SMALL_STATE(226)] = 6668,
  [SMALL_STATE(227)] = 6684,
  [SMALL_STATE(228)] = 6700,
  [SMALL_STATE(229)] = 6716,
  [SMALL_STATE(230)] = 6732,
  [SMALL_STATE(231)] = 6748,
  [SMALL_STATE(232)] = 6764,
  [SMALL_STATE(233)] = 6780,
  [SMALL_STATE(234)] = 6796,
  [SMALL_STATE(235)] = 6812,
  [SMALL_STATE(236)] = 6828,
  [SMALL_STATE(237)] = 6844,
  [SMALL_STATE(238)] = 6860,
  [SMALL_STATE(239)] = 6876,
  [SMALL_STATE(240)] = 6892,
  [SMALL_STATE(241)] = 6908,
  [SMALL_STATE(242)] = 6924,
  [SMALL_STATE(243)] = 6940,
  [SMALL_STATE(244)] = 6956,
  [SMALL_STATE(245)] = 6977,
  [SMALL_STATE(246)] = 6997,
  [SMALL_STATE(247)] = 7017,
  [SMALL_STATE(248)] = 7037,
  [SMALL_STATE(249)] = 7057,
  [SMALL_STATE(250)] = 7077,
  [SMALL_STATE(251)] = 7097,
  [SMALL_STATE(252)] = 7117,
  [SMALL_STATE(253)] = 7137,
  [SMALL_STATE(254)] = 7154,
  [SMALL_STATE(255)] = 7171,
  [SMALL_STATE(256)] = 7186,
  [SMALL_STATE(257)] = 7203,
  [SMALL_STATE(258)] = 7220,
  [SMALL_STATE(259)] = 7237,
  [SMALL_STATE(260)] = 7254,
  [SMALL_STATE(261)] = 7269,
  [SMALL_STATE(262)] = 7286,
  [SMALL_STATE(263)] = 7303,
  [SMALL_STATE(264)] = 7315,
  [SMALL_STATE(265)] = 7329,
  [SMALL_STATE(266)] = 7343,
  [SMALL_STATE(267)] = 7357,
  [SMALL_STATE(268)] = 7373,
  [SMALL_STATE(269)] = 7387,
  [SMALL_STATE(270)] = 7397,
  [SMALL_STATE(271)] = 7411,
  [SMALL_STATE(272)] = 7423,
  [SMALL_STATE(273)] = 7437,
  [SMALL_STATE(274)] = 7453,
  [SMALL_STATE(275)] = 7464,
  [SMALL_STATE(276)] = 7477,
  [SMALL_STATE(277)] = 7490,
  [SMALL_STATE(278)] = 7499,
  [SMALL_STATE(279)] = 7512,
  [SMALL_STATE(280)] = 7525,
  [SMALL_STATE(281)] = 7536,
  [SMALL_STATE(282)] = 7545,
  [SMALL_STATE(283)] = 7558,
  [SMALL_STATE(284)] = 7571,
  [SMALL_STATE(285)] = 7584,
  [SMALL_STATE(286)] = 7597,
  [SMALL_STATE(287)] = 7606,
  [SMALL_STATE(288)] = 7619,
  [SMALL_STATE(289)] = 7632,
  [SMALL_STATE(290)] = 7642,
  [SMALL_STATE(291)] = 7652,
  [SMALL_STATE(292)] = 7660,
  [SMALL_STATE(293)] = 7668,
  [SMALL_STATE(294)] = 7678,
  [SMALL_STATE(295)] = 7688,
  [SMALL_STATE(296)] = 7698,
  [SMALL_STATE(297)] = 7708,
  [SMALL_STATE(298)] = 7716,
  [SMALL_STATE(299)] = 7726,
  [SMALL_STATE(300)] = 7736,
  [SMALL_STATE(301)] = 7746,
  [SMALL_STATE(302)] = 7756,
  [SMALL_STATE(303)] = 7766,
  [SMALL_STATE(304)] = 7776,
  [SMALL_STATE(305)] = 7784,
  [SMALL_STATE(306)] = 7794,
  [SMALL_STATE(307)] = 7804,
  [SMALL_STATE(308)] = 7812,
  [SMALL_STATE(309)] = 7822,
  [SMALL_STATE(310)] = 7830,
  [SMALL_STATE(311)] = 7838,
  [SMALL_STATE(312)] = 7848,
  [SMALL_STATE(313)] = 7858,
  [SMALL_STATE(314)] = 7865,
  [SMALL_STATE(315)] = 7872,
  [SMALL_STATE(316)] = 7879,
  [SMALL_STATE(317)] = 7886,
  [SMALL_STATE(318)] = 7893,
  [SMALL_STATE(319)] = 7900,
  [SMALL_STATE(320)] = 7907,
  [SMALL_STATE(321)] = 7914,
  [SMALL_STATE(322)] = 7921,
  [SMALL_STATE(323)] = 7928,
  [SMALL_STATE(324)] = 7935,
  [SMALL_STATE(325)] = 7942,
  [SMALL_STATE(326)] = 7949,
  [SMALL_STATE(327)] = 7956,
  [SMALL_STATE(328)] = 7963,
  [SMALL_STATE(329)] = 7970,
  [SMALL_STATE(330)] = 7977,
  [SMALL_STATE(331)] = 7984,
  [SMALL_STATE(332)] = 7991,
  [SMALL_STATE(333)] = 7998,
  [SMALL_STATE(334)] = 8005,
  [SMALL_STATE(335)] = 8012,
  [SMALL_STATE(336)] = 8019,
  [SMALL_STATE(337)] = 8026,
  [SMALL_STATE(338)] = 8033,
  [SMALL_STATE(339)] = 8040,
  [SMALL_STATE(340)] = 8047,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(284),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 2),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(269),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(69),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(148),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 2),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 2),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 3),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 3),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(332),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(111),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(115),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(284),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(200),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(6),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 3),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 3),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 2),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 5),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 5),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 1),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 4),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 4),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 4),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 4),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 3),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 3),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(218),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(285),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 4),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 3),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(335),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(109),
  [161] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(218),
  [164] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(285),
  [167] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(195),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(28),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(161),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 1),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_dblquotes, 3),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_dblquotes, 3),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens_empty, 2),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens_empty, 2),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_associative, 3),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_associative, 3),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_variable, 1),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_variable, 1),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens, 3),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens, 3),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_bracket, 3),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_bracket, 3),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_hash, 3),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_hash, 3),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 2),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 2),
  [237] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(53),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(185),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(191),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_attribute, 3),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [276] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_attribute, 3),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(206),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [290] = {.entry = {.count = 1, .reusable = false}}, SHIFT(204),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag_selfclose_end, 2),
  [368] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag_selfclose_end, 2),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_argument, 3),
  [372] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_argument, 3),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_return, 3),
  [376] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_return, 3),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text, 1),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_condition, 1),
  [384] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_condition, 1),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 3),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 3),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1),
  [392] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4),
  [396] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3),
  [406] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 4),
  [410] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 4),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_argument, 2),
  [414] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_argument, 2),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_return, 2),
  [418] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_return, 2),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag_selfclose_end, 1),
  [422] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag_selfclose_end, 1),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 1),
  [426] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 1),
  [428] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 3),
  [430] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 3),
  [432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2),
  [434] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 3),
  [438] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 3),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4),
  [442] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 4),
  [450] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 4),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 2),
  [454] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 2),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3),
  [458] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3),
  [462] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [466] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag, 2),
  [472] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag, 2),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 5),
  [476] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 5),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag_end, 1),
  [480] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag_end, 1),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 6),
  [490] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 6),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [494] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 7),
  [498] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 7),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [542] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4),
  [550] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3),
  [554] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3),
  [556] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(339),
  [559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [561] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(290),
  [564] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [576] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2),
  [578] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2), SHIFT_REPEAT(263),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2),
  [589] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(271),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [594] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_attribute, 1),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [614] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_assignment, 1),
  [616] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2), SHIFT_REPEAT(280),
  [619] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [623] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(274),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [634] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [658] = {.entry = {.count = 1, .reusable = false}}, SHIFT(292),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [664] = {.entry = {.count = 1, .reusable = false}}, SHIFT(281),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [668] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [672] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [678] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4),
  [682] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [688] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [718] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [724] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [728] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
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
