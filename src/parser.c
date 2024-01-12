#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 222
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 55
#define ALIAS_COUNT 0
#define TOKEN_COUNT 27
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 1

enum {
  aux_sym_cf_condition_token1 = 1,
  sym__cf_tag_start = 2,
  sym_cf_tag_end = 3,
  aux_sym_text_token1 = 4,
  sym_cf_tag_close = 5,
  sym_cf_operator = 6,
  anon_sym_POUND = 7,
  anon_sym_LBRACK = 8,
  anon_sym_RBRACK = 9,
  sym_cf_period = 10,
  sym_cf_comma = 11,
  anon_sym_EQ = 12,
  anon_sym_DQUOTE = 13,
  anon_sym_LPAREN = 14,
  anon_sym_RPAREN = 15,
  anon_sym_set = 16,
  anon_sym_GT = 17,
  anon_sym_RBRACE = 18,
  sym_attribute_name = 19,
  sym_cf_var = 20,
  sym_cf_if_keyword = 21,
  sym_cf_elseif_keyword = 22,
  sym_cf_else_keyword = 23,
  sym_cf_function_keyword = 24,
  sym_cf_argument_keyword = 25,
  sym_cf_return_keyword = 26,
  sym_fragment = 27,
  sym_cf_condition = 28,
  sym_text = 29,
  sym_cf_variable = 30,
  sym__node = 31,
  sym_cf_hash = 32,
  sym_cf_associative = 33,
  sym__cf_expression = 34,
  sym_cf_assignment = 35,
  sym_cf_dblquotes = 36,
  sym_cf_dblquotes_empty = 37,
  sym_cf_parens = 38,
  sym_cf_parens_empty = 39,
  sym_cf_function = 40,
  sym_cf_argument = 41,
  sym_cf_return = 42,
  sym_cf_ifstatement = 43,
  sym_cf_if = 44,
  sym_cf_set = 45,
  sym_cf_elseif = 46,
  sym_cf_else = 47,
  sym_cf_if_end = 48,
  sym_attribute = 49,
  sym_cf_tag = 50,
  sym__cf_statement = 51,
  aux_sym_fragment_repeat1 = 52,
  aux_sym_cf_function_repeat1 = 53,
  aux_sym_cf_ifstatement_repeat1 = 54,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_cf_condition_token1] = "cf_condition_token1",
  [sym__cf_tag_start] = "_cf_tag_start",
  [sym_cf_tag_end] = "cf_tag_end",
  [aux_sym_text_token1] = "text_token1",
  [sym_cf_tag_close] = "cf_tag_close",
  [sym_cf_operator] = "cf_operator",
  [anon_sym_POUND] = "#",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_cf_period] = "cf_period",
  [sym_cf_comma] = "cf_comma",
  [anon_sym_EQ] = "=",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_set] = "set",
  [anon_sym_GT] = ">",
  [anon_sym_RBRACE] = "}",
  [sym_attribute_name] = "attribute_name",
  [sym_cf_var] = "cf_var",
  [sym_cf_if_keyword] = "cf_if_keyword",
  [sym_cf_elseif_keyword] = "cf_elseif_keyword",
  [sym_cf_else_keyword] = "cf_else_keyword",
  [sym_cf_function_keyword] = "cf_function_keyword",
  [sym_cf_argument_keyword] = "cf_argument_keyword",
  [sym_cf_return_keyword] = "cf_return_keyword",
  [sym_fragment] = "fragment",
  [sym_cf_condition] = "cf_condition",
  [sym_text] = "text",
  [sym_cf_variable] = "cf_variable",
  [sym__node] = "_node",
  [sym_cf_hash] = "cf_hash",
  [sym_cf_associative] = "cf_associative",
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
  [sym_cf_tag] = "cf_tag",
  [sym__cf_statement] = "_cf_statement",
  [aux_sym_fragment_repeat1] = "fragment_repeat1",
  [aux_sym_cf_function_repeat1] = "cf_function_repeat1",
  [aux_sym_cf_ifstatement_repeat1] = "cf_ifstatement_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_cf_condition_token1] = aux_sym_cf_condition_token1,
  [sym__cf_tag_start] = sym__cf_tag_start,
  [sym_cf_tag_end] = sym_cf_tag_end,
  [aux_sym_text_token1] = aux_sym_text_token1,
  [sym_cf_tag_close] = sym_cf_tag_close,
  [sym_cf_operator] = sym_cf_operator,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_cf_period] = sym_cf_period,
  [sym_cf_comma] = sym_cf_comma,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_set] = anon_sym_set,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_attribute_name] = sym_attribute_name,
  [sym_cf_var] = sym_cf_var,
  [sym_cf_if_keyword] = sym_cf_if_keyword,
  [sym_cf_elseif_keyword] = sym_cf_elseif_keyword,
  [sym_cf_else_keyword] = sym_cf_else_keyword,
  [sym_cf_function_keyword] = sym_cf_function_keyword,
  [sym_cf_argument_keyword] = sym_cf_argument_keyword,
  [sym_cf_return_keyword] = sym_cf_return_keyword,
  [sym_fragment] = sym_fragment,
  [sym_cf_condition] = sym_cf_condition,
  [sym_text] = sym_text,
  [sym_cf_variable] = sym_cf_variable,
  [sym__node] = sym__node,
  [sym_cf_hash] = sym_cf_hash,
  [sym_cf_associative] = sym_cf_associative,
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
  [sym_cf_tag] = sym_cf_tag,
  [sym__cf_statement] = sym__cf_statement,
  [aux_sym_fragment_repeat1] = aux_sym_fragment_repeat1,
  [aux_sym_cf_function_repeat1] = aux_sym_cf_function_repeat1,
  [aux_sym_cf_ifstatement_repeat1] = aux_sym_cf_ifstatement_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_cf_condition_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__cf_tag_start] = {
    .visible = false,
    .named = true,
  },
  [sym_cf_tag_end] = {
    .visible = true,
    .named = true,
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
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_name] = {
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
  [sym_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_condition] = {
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
  [sym_cf_hash] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_associative] = {
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
  [sym_cf_tag] = {
    .visible = true,
    .named = true,
  },
  [sym__cf_statement] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_fragment_repeat1] = {
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
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 27,
  [31] = 12,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 26,
  [39] = 35,
  [40] = 40,
  [41] = 33,
  [42] = 19,
  [43] = 43,
  [44] = 44,
  [45] = 19,
  [46] = 19,
  [47] = 18,
  [48] = 19,
  [49] = 15,
  [50] = 16,
  [51] = 17,
  [52] = 19,
  [53] = 15,
  [54] = 16,
  [55] = 17,
  [56] = 56,
  [57] = 18,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 59,
  [65] = 62,
  [66] = 63,
  [67] = 59,
  [68] = 18,
  [69] = 69,
  [70] = 17,
  [71] = 60,
  [72] = 16,
  [73] = 59,
  [74] = 63,
  [75] = 19,
  [76] = 61,
  [77] = 63,
  [78] = 62,
  [79] = 62,
  [80] = 80,
  [81] = 58,
  [82] = 15,
  [83] = 18,
  [84] = 17,
  [85] = 80,
  [86] = 16,
  [87] = 15,
  [88] = 88,
  [89] = 89,
  [90] = 32,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 36,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 34,
  [108] = 108,
  [109] = 109,
  [110] = 108,
  [111] = 109,
  [112] = 40,
  [113] = 28,
  [114] = 36,
  [115] = 34,
  [116] = 29,
  [117] = 32,
  [118] = 98,
  [119] = 100,
  [120] = 102,
  [121] = 93,
  [122] = 89,
  [123] = 123,
  [124] = 106,
  [125] = 125,
  [126] = 94,
  [127] = 95,
  [128] = 99,
  [129] = 104,
  [130] = 91,
  [131] = 105,
  [132] = 36,
  [133] = 123,
  [134] = 34,
  [135] = 88,
  [136] = 96,
  [137] = 137,
  [138] = 92,
  [139] = 97,
  [140] = 103,
  [141] = 32,
  [142] = 125,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 144,
  [152] = 143,
  [153] = 148,
  [154] = 154,
  [155] = 149,
  [156] = 144,
  [157] = 144,
  [158] = 158,
  [159] = 143,
  [160] = 158,
  [161] = 143,
  [162] = 158,
  [163] = 147,
  [164] = 149,
  [165] = 149,
  [166] = 143,
  [167] = 158,
  [168] = 147,
  [169] = 169,
  [170] = 148,
  [171] = 149,
  [172] = 144,
  [173] = 158,
  [174] = 148,
  [175] = 169,
  [176] = 150,
  [177] = 147,
  [178] = 148,
  [179] = 148,
  [180] = 148,
  [181] = 145,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 184,
  [189] = 189,
  [190] = 182,
  [191] = 185,
  [192] = 187,
  [193] = 183,
  [194] = 189,
  [195] = 195,
  [196] = 196,
  [197] = 196,
  [198] = 195,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 207,
  [209] = 209,
  [210] = 209,
  [211] = 206,
  [212] = 212,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 214,
  [217] = 204,
  [218] = 205,
  [219] = 219,
  [220] = 212,
  [221] = 219,
};

static inline bool aux_sym_text_token1_character_set_1(int32_t c) {
  return (c < '<'
    ? (c < '\''
      ? (c < '#'
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

static inline bool aux_sym_text_token1_character_set_2(int32_t c) {
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
        : (c <= '=' || c == '['))
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
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
      if (eof) ADVANCE(68);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == ',') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(128);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(116);
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'e') ADVANCE(41);
      if (lookahead == 'f') ADVANCE(60);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == 'r') ADVANCE(28);
      if (lookahead == 's') ADVANCE(31);
      if (lookahead == '}') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == ',') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(128);
      if (lookahead == 'A') ADVANCE(19);
      if (lookahead == 'E') ADVANCE(21);
      if (lookahead == 'G') ADVANCE(24);
      if (lookahead == 'N') ADVANCE(20);
      if (lookahead == 'O') ADVANCE(22);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(116);
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'e') ADVANCE(41);
      if (lookahead == 'f') ADVANCE(60);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == 'r') ADVANCE(28);
      if (lookahead == 's') ADVANCE(31);
      if (lookahead == 'v') ADVANCE(25);
      if (lookahead == '}') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == ',') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == 'A') ADVANCE(86);
      if (lookahead == 'E') ADVANCE(88);
      if (lookahead == 'G') ADVANCE(91);
      if (lookahead == 'N') ADVANCE(87);
      if (lookahead == 'O') ADVANCE(89);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(116);
      if (lookahead == 'e') ADVANCE(101);
      if (lookahead == '}') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '{') ADVANCE(110);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == ',') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(116);
      if (lookahead == 'e') ADVANCE(101);
      if (lookahead == '}') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '{') ADVANCE(110);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == ',') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == 'A') ADVANCE(86);
      if (lookahead == 'E') ADVANCE(88);
      if (lookahead == 'G') ADVANCE(91);
      if (lookahead == 'N') ADVANCE(87);
      if (lookahead == 'O') ADVANCE(89);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(110);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == ',') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(110);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(101);
      if (lookahead == '}') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != '.' &&
          lookahead != '=' &&
          lookahead != ']' &&
          lookahead != '{') ADVANCE(110);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '(') ADVANCE(125);
      if (lookahead == ',') ADVANCE(120);
      if (lookahead == '.') ADVANCE(118);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == 'A') ADVANCE(75);
      if (lookahead == 'E') ADVANCE(77);
      if (lookahead == 'G') ADVANCE(80);
      if (lookahead == 'N') ADVANCE(76);
      if (lookahead == 'O') ADVANCE(78);
      if (lookahead == '[') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead == '#' ||
          lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(82);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '(') ADVANCE(125);
      if (lookahead == ',') ADVANCE(120);
      if (lookahead == '.') ADVANCE(118);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '[') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead == '#' ||
          lookahead == ')' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(82);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == 'v') ADVANCE(92);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(9);
      if (!aux_sym_text_token1_character_set_1(lookahead)) ADVANCE(110);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(9);
      if (!aux_sym_text_token1_character_set_1(lookahead)) ADVANCE(110);
      END_STATE();
    case 11:
      if (lookahead == '(') ADVANCE(125);
      if (lookahead == ',') ADVANCE(120);
      if (lookahead == '.') ADVANCE(118);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == 'A') ADVANCE(132);
      if (lookahead == 'E') ADVANCE(134);
      if (lookahead == 'G') ADVANCE(137);
      if (lookahead == 'N') ADVANCE(133);
      if (lookahead == 'O') ADVANCE(135);
      if (lookahead == '[') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(139);
      END_STATE();
    case 12:
      if (lookahead == '(') ADVANCE(125);
      if (lookahead == ',') ADVANCE(120);
      if (lookahead == '.') ADVANCE(118);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '[') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(139);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '=') ADVANCE(121);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(139);
      END_STATE();
    case 14:
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == 'c') ADVANCE(35);
      END_STATE();
    case 15:
      if (lookahead == '=') ADVANCE(112);
      END_STATE();
    case 16:
      if (lookahead == '>') ADVANCE(72);
      END_STATE();
    case 17:
      if (lookahead == 'D') ADVANCE(64);
      END_STATE();
    case 18:
      if (lookahead == 'E') ADVANCE(64);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      END_STATE();
    case 19:
      if (lookahead == 'N') ADVANCE(17);
      END_STATE();
    case 20:
      if (lookahead == 'O') ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == 'Q') ADVANCE(64);
      END_STATE();
    case 22:
      if (lookahead == 'R') ADVANCE(64);
      END_STATE();
    case 23:
      if (lookahead == 'T') ADVANCE(64);
      END_STATE();
    case 24:
      if (lookahead == 'T') ADVANCE(18);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == 'c') ADVANCE(57);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 34:
      if (lookahead == 'f') ADVANCE(141);
      END_STATE();
    case 35:
      if (lookahead == 'f') ADVANCE(71);
      END_STATE();
    case 36:
      if (lookahead == 'f') ADVANCE(111);
      END_STATE();
    case 37:
      if (lookahead == 'f') ADVANCE(142);
      END_STATE();
    case 38:
      if (lookahead == 'g') ADVANCE(61);
      END_STATE();
    case 39:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 40:
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 41:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 42:
      if (lookahead == 'l') ADVANCE(54);
      END_STATE();
    case 43:
      if (lookahead == 'l') ADVANCE(55);
      END_STATE();
    case 44:
      if (lookahead == 'm') ADVANCE(33);
      END_STATE();
    case 45:
      if (lookahead == 'n') ADVANCE(147);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(145);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(46);
      END_STATE();
    case 50:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 53:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 54:
      if (lookahead == 's') ADVANCE(30);
      END_STATE();
    case 55:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(146);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(62);
      END_STATE();
    case 60:
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 61:
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 62:
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 63:
      if (lookahead == 'v') ADVANCE(25);
      END_STATE();
    case 64:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      END_STATE();
    case 65:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(140);
      END_STATE();
    case 66:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(70);
      END_STATE();
    case 67:
      if (eof) ADVANCE(68);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(113);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ')') ADVANCE(126);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '>') ADVANCE(128);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(101);
      if (lookahead == '}') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(67)
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != ',' &&
          lookahead != '.' &&
          lookahead != '=' &&
          lookahead != ']' &&
          lookahead != '{') ADVANCE(110);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym__cf_tag_start);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_cf_tag_end);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'D') ADVANCE(81);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'E') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'N') ADVANCE(73);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'O') ADVANCE(79);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'Q') ADVANCE(81);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'R') ADVANCE(81);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'T') ADVANCE(81);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == 'T') ADVANCE(74);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '/') ADVANCE(110);
      if (lookahead == '#' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ',' ||
          lookahead == '.' ||
          lookahead == '[' ||
          lookahead == ']' ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '>') ADVANCE(72);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(110);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'D') ADVANCE(108);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'E') ADVANCE(108);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (!aux_sym_text_token1_character_set_4(lookahead)) ADVANCE(110);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'N') ADVANCE(84);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'O') ADVANCE(90);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'Q') ADVANCE(108);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'R') ADVANCE(108);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(108);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(85);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'a') ADVANCE(104);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(95);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(100);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(99);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(102);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(103);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(96);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'f') ADVANCE(97);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'i') ADVANCE(99);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(105);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(106);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(107);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'r') ADVANCE(109);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(93);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(98);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(94);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (!aux_sym_text_token1_character_set_4(lookahead)) ADVANCE(110);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(140);
      if (!aux_sym_text_token1_character_set_4(lookahead)) ADVANCE(110);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_cf_tag_close);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_cf_operator);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_cf_period);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_cf_period);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_cf_comma);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_cf_comma);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(15);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_set);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'D') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'E') ADVANCE(138);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'N') ADVANCE(130);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'O') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'Q') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'R') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'T') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == 'T') ADVANCE(131);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_cf_var);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(63);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_cf_if_keyword);
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_cf_elseif_keyword);
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(42);
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_cf_function_keyword);
      if (lookahead == 'f') ADVANCE(60);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_cf_argument_keyword);
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_cf_return_keyword);
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 67},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 67},
  [6] = {.lex_state = 67},
  [7] = {.lex_state = 67},
  [8] = {.lex_state = 67},
  [9] = {.lex_state = 67},
  [10] = {.lex_state = 67},
  [11] = {.lex_state = 67},
  [12] = {.lex_state = 67},
  [13] = {.lex_state = 67},
  [14] = {.lex_state = 6},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 3},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 6},
  [21] = {.lex_state = 67},
  [22] = {.lex_state = 67},
  [23] = {.lex_state = 67},
  [24] = {.lex_state = 67},
  [25] = {.lex_state = 67},
  [26] = {.lex_state = 67},
  [27] = {.lex_state = 67},
  [28] = {.lex_state = 3},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 67},
  [31] = {.lex_state = 67},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 67},
  [34] = {.lex_state = 3},
  [35] = {.lex_state = 67},
  [36] = {.lex_state = 3},
  [37] = {.lex_state = 67},
  [38] = {.lex_state = 67},
  [39] = {.lex_state = 67},
  [40] = {.lex_state = 3},
  [41] = {.lex_state = 67},
  [42] = {.lex_state = 5},
  [43] = {.lex_state = 3},
  [44] = {.lex_state = 3},
  [45] = {.lex_state = 67},
  [46] = {.lex_state = 8},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 5},
  [53] = {.lex_state = 12},
  [54] = {.lex_state = 12},
  [55] = {.lex_state = 12},
  [56] = {.lex_state = 12},
  [57] = {.lex_state = 12},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 3},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 6},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 3},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 67},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 3},
  [84] = {.lex_state = 3},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 3},
  [88] = {.lex_state = 67},
  [89] = {.lex_state = 67},
  [90] = {.lex_state = 67},
  [91] = {.lex_state = 67},
  [92] = {.lex_state = 67},
  [93] = {.lex_state = 67},
  [94] = {.lex_state = 67},
  [95] = {.lex_state = 67},
  [96] = {.lex_state = 67},
  [97] = {.lex_state = 67},
  [98] = {.lex_state = 67},
  [99] = {.lex_state = 67},
  [100] = {.lex_state = 67},
  [101] = {.lex_state = 67},
  [102] = {.lex_state = 67},
  [103] = {.lex_state = 67},
  [104] = {.lex_state = 67},
  [105] = {.lex_state = 67},
  [106] = {.lex_state = 67},
  [107] = {.lex_state = 67},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 12},
  [113] = {.lex_state = 12},
  [114] = {.lex_state = 12},
  [115] = {.lex_state = 12},
  [116] = {.lex_state = 12},
  [117] = {.lex_state = 12},
  [118] = {.lex_state = 67},
  [119] = {.lex_state = 67},
  [120] = {.lex_state = 67},
  [121] = {.lex_state = 67},
  [122] = {.lex_state = 67},
  [123] = {.lex_state = 67},
  [124] = {.lex_state = 67},
  [125] = {.lex_state = 10},
  [126] = {.lex_state = 67},
  [127] = {.lex_state = 67},
  [128] = {.lex_state = 67},
  [129] = {.lex_state = 67},
  [130] = {.lex_state = 67},
  [131] = {.lex_state = 67},
  [132] = {.lex_state = 67},
  [133] = {.lex_state = 67},
  [134] = {.lex_state = 67},
  [135] = {.lex_state = 67},
  [136] = {.lex_state = 67},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 67},
  [139] = {.lex_state = 67},
  [140] = {.lex_state = 67},
  [141] = {.lex_state = 67},
  [142] = {.lex_state = 10},
  [143] = {.lex_state = 67},
  [144] = {.lex_state = 67},
  [145] = {.lex_state = 67},
  [146] = {.lex_state = 67},
  [147] = {.lex_state = 67},
  [148] = {.lex_state = 67},
  [149] = {.lex_state = 67},
  [150] = {.lex_state = 67},
  [151] = {.lex_state = 67},
  [152] = {.lex_state = 67},
  [153] = {.lex_state = 67},
  [154] = {.lex_state = 67},
  [155] = {.lex_state = 67},
  [156] = {.lex_state = 67},
  [157] = {.lex_state = 67},
  [158] = {.lex_state = 67},
  [159] = {.lex_state = 67},
  [160] = {.lex_state = 67},
  [161] = {.lex_state = 67},
  [162] = {.lex_state = 67},
  [163] = {.lex_state = 67},
  [164] = {.lex_state = 67},
  [165] = {.lex_state = 67},
  [166] = {.lex_state = 67},
  [167] = {.lex_state = 67},
  [168] = {.lex_state = 67},
  [169] = {.lex_state = 67},
  [170] = {.lex_state = 67},
  [171] = {.lex_state = 67},
  [172] = {.lex_state = 67},
  [173] = {.lex_state = 67},
  [174] = {.lex_state = 67},
  [175] = {.lex_state = 67},
  [176] = {.lex_state = 67},
  [177] = {.lex_state = 67},
  [178] = {.lex_state = 67},
  [179] = {.lex_state = 67},
  [180] = {.lex_state = 67},
  [181] = {.lex_state = 67},
  [182] = {.lex_state = 13},
  [183] = {.lex_state = 13},
  [184] = {.lex_state = 13},
  [185] = {.lex_state = 13},
  [186] = {.lex_state = 13},
  [187] = {.lex_state = 13},
  [188] = {.lex_state = 13},
  [189] = {.lex_state = 13},
  [190] = {.lex_state = 13},
  [191] = {.lex_state = 13},
  [192] = {.lex_state = 13},
  [193] = {.lex_state = 13},
  [194] = {.lex_state = 13},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 13},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 67},
  [202] = {.lex_state = 66},
  [203] = {.lex_state = 66},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 3},
  [206] = {.lex_state = 3},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 3},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 67},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 67},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 3},
  [219] = {.lex_state = 3},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 3},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__cf_tag_start] = ACTIONS(1),
    [sym_cf_tag_end] = ACTIONS(1),
    [sym_cf_tag_close] = ACTIONS(1),
    [sym_cf_operator] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_cf_period] = ACTIONS(1),
    [sym_cf_comma] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_set] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_cf_var] = ACTIONS(1),
    [sym_cf_if_keyword] = ACTIONS(1),
    [sym_cf_elseif_keyword] = ACTIONS(1),
    [sym_cf_else_keyword] = ACTIONS(1),
    [sym_cf_function_keyword] = ACTIONS(1),
    [sym_cf_argument_keyword] = ACTIONS(1),
    [sym_cf_return_keyword] = ACTIONS(1),
  },
  [1] = {
    [sym_fragment] = STATE(215),
    [sym_text] = STATE(37),
    [sym__node] = STATE(37),
    [sym_cf_hash] = STATE(37),
    [sym_cf_associative] = STATE(37),
    [sym_cf_dblquotes] = STATE(37),
    [sym_cf_dblquotes_empty] = STATE(37),
    [sym_cf_parens] = STATE(37),
    [sym_cf_tag] = STATE(37),
    [sym__cf_statement] = STATE(37),
    [aux_sym_fragment_repeat1] = STATE(37),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__cf_tag_start] = ACTIONS(5),
    [aux_sym_text_token1] = ACTIONS(7),
    [anon_sym_POUND] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_LPAREN] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 18,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(19), 1,
      sym_cf_tag_end,
    ACTIONS(21), 1,
      aux_sym_text_token1,
    ACTIONS(25), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(31), 1,
      sym_cf_period,
    ACTIONS(33), 1,
      sym_cf_comma,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    STATE(40), 1,
      sym_cf_parens_empty,
    STATE(43), 1,
      sym_cf_parens,
    STATE(44), 1,
      sym_cf_associative,
    STATE(155), 1,
      sym_cf_assignment,
    ACTIONS(23), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(41), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [64] = 10,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(21), 1,
      aux_sym_text_token1,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(43), 1,
      sym_cf_tag_end,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(51), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(6), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [106] = 10,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(21), 1,
      aux_sym_text_token1,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      sym_cf_tag_end,
    ACTIONS(55), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(57), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(11), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [148] = 8,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(63), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(59), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [185] = 8,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(67), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(65), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [222] = 9,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(45), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(51), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(6), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [261] = 9,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(65), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(67), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(10), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [300] = 8,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(71), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(69), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [337] = 8,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(75), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(73), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [374] = 8,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(51), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(45), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [411] = 9,
    ACTIONS(77), 1,
      sym__cf_tag_start,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(85), 1,
      anon_sym_POUND,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(91), 1,
      anon_sym_DQUOTE,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(83), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(97), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [450] = 9,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(69), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(71), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(5), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [489] = 9,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(21), 1,
      aux_sym_text_token1,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(99), 1,
      sym_cf_tag_end,
    ACTIONS(101), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(21), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [527] = 10,
    ACTIONS(25), 1,
      sym_cf_operator,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(31), 1,
      sym_cf_period,
    ACTIONS(33), 1,
      sym_cf_comma,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    STATE(155), 1,
      sym_cf_assignment,
    ACTIONS(105), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 6,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
  [567] = 6,
    ACTIONS(25), 1,
      sym_cf_operator,
    ACTIONS(33), 1,
      sym_cf_comma,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(105), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(103), 9,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [599] = 7,
    ACTIONS(25), 1,
      sym_cf_operator,
    ACTIONS(31), 1,
      sym_cf_period,
    ACTIONS(33), 1,
      sym_cf_comma,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(105), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(103), 8,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [633] = 5,
    ACTIONS(25), 1,
      sym_cf_operator,
    STATE(155), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(105), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(103), 10,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [663] = 5,
    ACTIONS(109), 1,
      aux_sym_text_token1,
    ACTIONS(114), 1,
      anon_sym_DQUOTE,
    ACTIONS(112), 3,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(107), 10,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [693] = 9,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(21), 1,
      aux_sym_text_token1,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(117), 1,
      sym_cf_tag_end,
    ACTIONS(119), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(23), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [731] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(119), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [766] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(121), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [801] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(123), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [836] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(119), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(23), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [871] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(123), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(22), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [906] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(125), 1,
      sym_cf_tag_close,
    STATE(35), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [940] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(127), 1,
      sym_cf_tag_close,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [974] = 2,
    ACTIONS(131), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(129), 13,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [996] = 2,
    ACTIONS(135), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(133), 13,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1018] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(137), 1,
      sym_cf_tag_close,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1052] = 8,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
    ACTIONS(139), 1,
      sym__cf_tag_start,
    ACTIONS(142), 1,
      aux_sym_text_token1,
    ACTIONS(145), 1,
      anon_sym_POUND,
    ACTIONS(148), 1,
      anon_sym_LBRACK,
    ACTIONS(151), 1,
      anon_sym_DQUOTE,
    ACTIONS(154), 1,
      anon_sym_LPAREN,
    STATE(31), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1086] = 2,
    ACTIONS(159), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(157), 13,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1108] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(161), 1,
      sym_cf_tag_close,
    STATE(30), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1142] = 2,
    ACTIONS(165), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(163), 13,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1164] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(161), 1,
      sym_cf_tag_close,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1198] = 2,
    ACTIONS(169), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(167), 13,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1220] = 8,
    ACTIONS(5), 1,
      sym__cf_tag_start,
    ACTIONS(7), 1,
      aux_sym_text_token1,
    ACTIONS(9), 1,
      anon_sym_POUND,
    ACTIONS(11), 1,
      anon_sym_LBRACK,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      anon_sym_LPAREN,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    STATE(31), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1254] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(173), 1,
      sym_cf_tag_close,
    STATE(39), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1288] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(175), 1,
      sym_cf_tag_close,
    STATE(12), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1322] = 2,
    ACTIONS(179), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(177), 13,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1344] = 8,
    ACTIONS(17), 1,
      sym__cf_tag_start,
    ACTIONS(27), 1,
      anon_sym_POUND,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    ACTIONS(175), 1,
      sym_cf_tag_close,
    STATE(27), 10,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1378] = 5,
    ACTIONS(112), 1,
      anon_sym_EQ,
    ACTIONS(181), 1,
      aux_sym_text_token1,
    ACTIONS(183), 1,
      anon_sym_DQUOTE,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(107), 8,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1404] = 4,
    ACTIONS(179), 1,
      anon_sym_EQ,
    ACTIONS(187), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(177), 4,
      sym_cf_tag_end,
      sym_cf_operator,
      sym_cf_period,
      sym_cf_comma,
    ACTIONS(185), 7,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1428] = 4,
    ACTIONS(179), 1,
      anon_sym_EQ,
    ACTIONS(187), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(177), 4,
      sym_cf_tag_end,
      sym_cf_operator,
      sym_cf_period,
      sym_cf_comma,
    ACTIONS(185), 7,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1452] = 5,
    ACTIONS(114), 1,
      anon_sym_DQUOTE,
    ACTIONS(189), 1,
      aux_sym_text_token1,
    ACTIONS(112), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(107), 6,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1477] = 5,
    ACTIONS(181), 1,
      aux_sym_text_token1,
    ACTIONS(183), 1,
      anon_sym_DQUOTE,
    ACTIONS(107), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(112), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [1502] = 5,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(192), 1,
      sym_cf_operator,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 7,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1526] = 5,
    ACTIONS(112), 1,
      anon_sym_EQ,
    ACTIONS(181), 1,
      aux_sym_text_token1,
    ACTIONS(183), 1,
      anon_sym_DQUOTE,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(107), 6,
      sym_cf_tag_end,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [1550] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    STATE(149), 1,
      sym_cf_assignment,
    ACTIONS(103), 3,
      anon_sym_POUND,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1582] = 6,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(196), 1,
      sym_cf_comma,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 6,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1608] = 7,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 5,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1636] = 5,
    ACTIONS(112), 1,
      anon_sym_EQ,
    ACTIONS(114), 1,
      anon_sym_DQUOTE,
    ACTIONS(181), 1,
      aux_sym_text_token1,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(107), 5,
      sym_cf_operator,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [1659] = 10,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(103), 1,
      sym_cf_tag_end,
    ACTIONS(105), 1,
      sym_attribute_name,
    ACTIONS(198), 1,
      sym_cf_operator,
    ACTIONS(200), 1,
      anon_sym_LBRACK,
    ACTIONS(202), 1,
      sym_cf_period,
    ACTIONS(204), 1,
      sym_cf_comma,
    ACTIONS(206), 1,
      anon_sym_LPAREN,
    STATE(165), 1,
      sym_cf_assignment,
    STATE(112), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1692] = 6,
    ACTIONS(103), 1,
      sym_cf_tag_end,
    ACTIONS(198), 1,
      sym_cf_operator,
    ACTIONS(204), 1,
      sym_cf_comma,
    STATE(165), 1,
      sym_cf_assignment,
    STATE(112), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(105), 5,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [1717] = 7,
    ACTIONS(103), 1,
      sym_cf_tag_end,
    ACTIONS(198), 1,
      sym_cf_operator,
    ACTIONS(202), 1,
      sym_cf_period,
    ACTIONS(204), 1,
      sym_cf_comma,
    STATE(165), 1,
      sym_cf_assignment,
    STATE(112), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(105), 4,
      anon_sym_LBRACK,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [1744] = 10,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(198), 1,
      sym_cf_operator,
    ACTIONS(200), 1,
      anon_sym_LBRACK,
    ACTIONS(202), 1,
      sym_cf_period,
    ACTIONS(204), 1,
      sym_cf_comma,
    ACTIONS(206), 1,
      anon_sym_LPAREN,
    ACTIONS(208), 1,
      sym_cf_tag_end,
    ACTIONS(210), 1,
      sym_attribute_name,
    STATE(165), 1,
      sym_cf_assignment,
    STATE(112), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1777] = 5,
    ACTIONS(103), 1,
      sym_cf_tag_end,
    ACTIONS(198), 1,
      sym_cf_operator,
    STATE(165), 1,
      sym_cf_assignment,
    STATE(112), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(105), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [1800] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(212), 1,
      anon_sym_POUND,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1830] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(214), 1,
      anon_sym_RPAREN,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1860] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(216), 1,
      sym_cf_tag_end,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(220), 1,
      sym_cf_period,
    ACTIONS(222), 1,
      sym_cf_comma,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1890] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(220), 1,
      sym_cf_period,
    ACTIONS(222), 1,
      sym_cf_comma,
    ACTIONS(224), 1,
      sym_cf_tag_end,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1920] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(226), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1950] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(230), 1,
      sym_cf_period,
    ACTIONS(232), 1,
      sym_cf_comma,
    ACTIONS(234), 1,
      anon_sym_DQUOTE,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [1980] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(236), 1,
      anon_sym_RPAREN,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2010] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(238), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2040] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(230), 1,
      sym_cf_period,
    ACTIONS(232), 1,
      sym_cf_comma,
    ACTIONS(240), 1,
      anon_sym_DQUOTE,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2070] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(242), 1,
      anon_sym_RPAREN,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2100] = 5,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(228), 1,
      sym_cf_operator,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 5,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [2122] = 2,
    ACTIONS(246), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(244), 8,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2138] = 7,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(230), 1,
      sym_cf_period,
    ACTIONS(232), 1,
      sym_cf_comma,
    STATE(171), 1,
      sym_cf_assignment,
    ACTIONS(103), 3,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2164] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(220), 1,
      sym_cf_period,
    ACTIONS(222), 1,
      sym_cf_comma,
    ACTIONS(248), 1,
      sym_cf_tag_end,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2194] = 6,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(232), 1,
      sym_cf_comma,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 4,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [2218] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(250), 1,
      anon_sym_RPAREN,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2248] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(230), 1,
      sym_cf_period,
    ACTIONS(232), 1,
      sym_cf_comma,
    ACTIONS(252), 1,
      anon_sym_DQUOTE,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2278] = 4,
    ACTIONS(114), 1,
      anon_sym_DQUOTE,
    ACTIONS(189), 1,
      aux_sym_text_token1,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
    ACTIONS(107), 5,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2298] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(220), 1,
      sym_cf_period,
    ACTIONS(222), 1,
      sym_cf_comma,
    ACTIONS(254), 1,
      sym_cf_tag_end,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2328] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(230), 1,
      sym_cf_period,
    ACTIONS(232), 1,
      sym_cf_comma,
    ACTIONS(256), 1,
      anon_sym_DQUOTE,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2358] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(258), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2388] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(260), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2418] = 7,
    ACTIONS(262), 1,
      anon_sym_set,
    ACTIONS(264), 1,
      sym_cf_if_keyword,
    ACTIONS(266), 1,
      sym_cf_function_keyword,
    ACTIONS(268), 1,
      sym_cf_argument_keyword,
    ACTIONS(270), 1,
      sym_cf_return_keyword,
    STATE(109), 1,
      sym_cf_if,
    STATE(140), 5,
      sym_cf_function,
      sym_cf_argument,
      sym_cf_return,
      sym_cf_ifstatement,
      sym_cf_set,
  [2444] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_cf_operator,
    ACTIONS(194), 1,
      sym_cf_period,
    ACTIONS(196), 1,
      sym_cf_comma,
    ACTIONS(272), 1,
      anon_sym_POUND,
    STATE(149), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2474] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(103), 1,
      anon_sym_DQUOTE,
    ACTIONS(228), 1,
      sym_cf_operator,
    ACTIONS(230), 1,
      sym_cf_period,
    ACTIONS(232), 1,
      sym_cf_comma,
    STATE(171), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2504] = 5,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(218), 1,
      sym_cf_operator,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 5,
      sym_cf_tag_end,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
  [2526] = 7,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(220), 1,
      sym_cf_period,
    ACTIONS(222), 1,
      sym_cf_comma,
    STATE(164), 1,
      sym_cf_assignment,
    ACTIONS(103), 3,
      sym_cf_tag_end,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2552] = 7,
    ACTIONS(264), 1,
      sym_cf_if_keyword,
    ACTIONS(274), 1,
      anon_sym_set,
    ACTIONS(276), 1,
      sym_cf_function_keyword,
    ACTIONS(278), 1,
      sym_cf_argument_keyword,
    ACTIONS(280), 1,
      sym_cf_return_keyword,
    STATE(111), 1,
      sym_cf_if,
    STATE(103), 5,
      sym_cf_function,
      sym_cf_argument,
      sym_cf_return,
      sym_cf_ifstatement,
      sym_cf_set,
  [2578] = 6,
    ACTIONS(105), 1,
      anon_sym_EQ,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(222), 1,
      sym_cf_comma,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
    ACTIONS(103), 4,
      sym_cf_tag_end,
      anon_sym_LBRACK,
      sym_cf_period,
      anon_sym_LPAREN,
  [2602] = 9,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      anon_sym_EQ,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(103), 1,
      sym_cf_tag_end,
    ACTIONS(218), 1,
      sym_cf_operator,
    ACTIONS(220), 1,
      sym_cf_period,
    ACTIONS(222), 1,
      sym_cf_comma,
    STATE(164), 1,
      sym_cf_assignment,
    STATE(40), 3,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_parens_empty,
  [2632] = 2,
    ACTIONS(284), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(282), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2647] = 2,
    ACTIONS(288), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(286), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2662] = 2,
    ACTIONS(159), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(157), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2677] = 2,
    ACTIONS(292), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(290), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2692] = 2,
    ACTIONS(296), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(294), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2707] = 2,
    ACTIONS(300), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(298), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2722] = 2,
    ACTIONS(304), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(302), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2737] = 2,
    ACTIONS(308), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(306), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2752] = 2,
    ACTIONS(312), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(310), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2767] = 2,
    ACTIONS(316), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(314), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2782] = 2,
    ACTIONS(320), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(318), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2797] = 2,
    ACTIONS(324), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(322), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2812] = 2,
    ACTIONS(328), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(326), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2827] = 2,
    ACTIONS(169), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(167), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2842] = 2,
    ACTIONS(332), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(330), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2857] = 2,
    ACTIONS(336), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(334), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2872] = 2,
    ACTIONS(340), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(338), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2887] = 2,
    ACTIONS(344), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(342), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2902] = 2,
    ACTIONS(348), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(346), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2917] = 2,
    ACTIONS(165), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(163), 8,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [2932] = 8,
    ACTIONS(350), 1,
      sym__cf_tag_start,
    ACTIONS(352), 1,
      sym_cf_tag_close,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    ACTIONS(356), 1,
      sym_cf_elseif_keyword,
    ACTIONS(358), 1,
      sym_cf_else_keyword,
    STATE(97), 1,
      sym_cf_if_end,
    STATE(197), 1,
      sym_cf_else,
    STATE(137), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [2958] = 8,
    ACTIONS(350), 1,
      sym__cf_tag_start,
    ACTIONS(356), 1,
      sym_cf_elseif_keyword,
    ACTIONS(358), 1,
      sym_cf_else_keyword,
    ACTIONS(360), 1,
      sym_cf_tag_close,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    STATE(129), 1,
      sym_cf_if_end,
    STATE(198), 1,
      sym_cf_else,
    STATE(110), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [2984] = 8,
    ACTIONS(350), 1,
      sym__cf_tag_start,
    ACTIONS(356), 1,
      sym_cf_elseif_keyword,
    ACTIONS(358), 1,
      sym_cf_else_keyword,
    ACTIONS(360), 1,
      sym_cf_tag_close,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    STATE(139), 1,
      sym_cf_if_end,
    STATE(196), 1,
      sym_cf_else,
    STATE(137), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [3010] = 8,
    ACTIONS(350), 1,
      sym__cf_tag_start,
    ACTIONS(352), 1,
      sym_cf_tag_close,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    ACTIONS(356), 1,
      sym_cf_elseif_keyword,
    ACTIONS(358), 1,
      sym_cf_else_keyword,
    STATE(104), 1,
      sym_cf_if_end,
    STATE(195), 1,
      sym_cf_else,
    STATE(108), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [3036] = 2,
    ACTIONS(177), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    ACTIONS(179), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [3049] = 2,
    ACTIONS(129), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    ACTIONS(131), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [3062] = 2,
    ACTIONS(167), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    ACTIONS(169), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [3075] = 2,
    ACTIONS(163), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    ACTIONS(165), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [3088] = 2,
    ACTIONS(133), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    ACTIONS(135), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [3101] = 2,
    ACTIONS(157), 2,
      sym_cf_tag_end,
      sym_cf_operator,
    ACTIONS(159), 6,
      anon_sym_LBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_EQ,
      anon_sym_LPAREN,
      sym_attribute_name,
  [3114] = 1,
    ACTIONS(318), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3124] = 1,
    ACTIONS(326), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3134] = 1,
    ACTIONS(330), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3144] = 1,
    ACTIONS(298), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3154] = 1,
    ACTIONS(286), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3164] = 4,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    ACTIONS(368), 1,
      anon_sym_RPAREN,
    STATE(73), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3180] = 1,
    ACTIONS(346), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3190] = 4,
    ACTIONS(181), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    ACTIONS(372), 1,
      sym_cf_var,
    STATE(60), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3206] = 1,
    ACTIONS(302), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3216] = 1,
    ACTIONS(306), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3226] = 1,
    ACTIONS(322), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3236] = 1,
    ACTIONS(338), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3246] = 1,
    ACTIONS(290), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3256] = 1,
    ACTIONS(342), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3266] = 1,
    ACTIONS(167), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3276] = 4,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    ACTIONS(374), 1,
      anon_sym_RPAREN,
    STATE(67), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3292] = 1,
    ACTIONS(163), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3302] = 1,
    ACTIONS(282), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3312] = 1,
    ACTIONS(310), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3322] = 5,
    ACTIONS(376), 1,
      sym__cf_tag_start,
    ACTIONS(381), 1,
      sym_cf_elseif_keyword,
    ACTIONS(384), 1,
      sym_cf_else_keyword,
    ACTIONS(379), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(137), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [3340] = 1,
    ACTIONS(294), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3350] = 1,
    ACTIONS(314), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3360] = 1,
    ACTIONS(334), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3370] = 1,
    ACTIONS(157), 7,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
  [3380] = 4,
    ACTIONS(181), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    ACTIONS(386), 1,
      sym_cf_var,
    STATE(71), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3396] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(388), 1,
      anon_sym_DQUOTE,
    STATE(70), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3409] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(86), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3422] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(81), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3435] = 3,
    ACTIONS(390), 1,
      aux_sym_text_token1,
    ACTIONS(392), 1,
      anon_sym_DQUOTE,
    STATE(56), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3448] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(79), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3461] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(394), 1,
      anon_sym_DQUOTE,
    STATE(74), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3474] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(49), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3487] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(59), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3500] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(50), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3513] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(51), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3526] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(396), 1,
      anon_sym_DQUOTE,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3539] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(398), 1,
      anon_sym_DQUOTE,
    STATE(2), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3552] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(398), 1,
      anon_sym_DQUOTE,
    STATE(15), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3565] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(398), 1,
      anon_sym_DQUOTE,
    STATE(16), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3578] = 3,
    ACTIONS(390), 1,
      aux_sym_text_token1,
    ACTIONS(392), 1,
      anon_sym_DQUOTE,
    STATE(54), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3591] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(47), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3604] = 3,
    ACTIONS(390), 1,
      aux_sym_text_token1,
    ACTIONS(392), 1,
      anon_sym_DQUOTE,
    STATE(55), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3617] = 3,
    ACTIONS(390), 1,
      aux_sym_text_token1,
    ACTIONS(392), 1,
      anon_sym_DQUOTE,
    STATE(57), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3630] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(398), 1,
      anon_sym_DQUOTE,
    STATE(17), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3643] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(398), 1,
      anon_sym_DQUOTE,
    STATE(18), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3656] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(65), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3669] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(87), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3682] = 3,
    ACTIONS(390), 1,
      aux_sym_text_token1,
    ACTIONS(392), 1,
      anon_sym_DQUOTE,
    STATE(53), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3695] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(84), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3708] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(83), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3721] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(62), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3734] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(76), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3747] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(400), 1,
      anon_sym_DQUOTE,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3760] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(388), 1,
      anon_sym_DQUOTE,
    STATE(82), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3773] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(388), 1,
      anon_sym_DQUOTE,
    STATE(72), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3786] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(388), 1,
      anon_sym_DQUOTE,
    STATE(68), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3799] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(402), 1,
      anon_sym_DQUOTE,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3812] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(61), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3825] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(64), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3838] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(78), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3851] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(404), 1,
      anon_sym_DQUOTE,
    STATE(63), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3864] = 3,
    ACTIONS(183), 1,
      anon_sym_DQUOTE,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    STATE(77), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3877] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(406), 1,
      anon_sym_DQUOTE,
    STATE(66), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3890] = 3,
    ACTIONS(364), 1,
      aux_sym_text_token1,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(58), 4,
      sym_cf_variable,
      sym__cf_expression,
      sym_cf_dblquotes,
      sym_cf_dblquotes_empty,
  [3903] = 3,
    ACTIONS(408), 1,
      sym_cf_tag_end,
    ACTIONS(410), 1,
      sym_attribute_name,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3914] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(412), 1,
      sym_cf_tag_end,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3925] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(414), 1,
      sym_cf_tag_end,
    STATE(183), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3936] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(416), 1,
      sym_cf_tag_end,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3947] = 3,
    ACTIONS(418), 1,
      sym_cf_tag_end,
    ACTIONS(420), 1,
      sym_attribute_name,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3958] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(423), 1,
      sym_cf_tag_end,
    STATE(190), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3969] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(425), 1,
      sym_cf_tag_end,
    STATE(193), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3980] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(427), 1,
      sym_cf_tag_end,
    STATE(191), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [3991] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(429), 1,
      sym_cf_tag_end,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [4002] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(431), 1,
      sym_cf_tag_end,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [4013] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(433), 1,
      sym_cf_tag_end,
    STATE(182), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [4024] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(435), 1,
      sym_cf_tag_end,
    STATE(186), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [4035] = 3,
    ACTIONS(410), 1,
      sym_attribute_name,
    ACTIONS(437), 1,
      sym_cf_tag_end,
    STATE(185), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [4046] = 3,
    ACTIONS(352), 1,
      sym_cf_tag_close,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    STATE(97), 1,
      sym_cf_if_end,
  [4056] = 3,
    ACTIONS(360), 1,
      sym_cf_tag_close,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    STATE(126), 1,
      sym_cf_if_end,
  [4066] = 3,
    ACTIONS(352), 1,
      sym_cf_tag_close,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    STATE(94), 1,
      sym_cf_if_end,
  [4076] = 3,
    ACTIONS(360), 1,
      sym_cf_tag_close,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    STATE(139), 1,
      sym_cf_if_end,
  [4086] = 2,
    ACTIONS(441), 1,
      anon_sym_EQ,
    ACTIONS(439), 2,
      sym_cf_tag_end,
      sym_attribute_name,
  [4094] = 2,
    ACTIONS(443), 1,
      sym_cf_elseif_keyword,
    ACTIONS(445), 1,
      sym_cf_else_keyword,
  [4101] = 1,
    ACTIONS(447), 2,
      aux_sym_text_token1,
      anon_sym_DQUOTE,
  [4106] = 2,
    ACTIONS(449), 1,
      aux_sym_cf_condition_token1,
    STATE(3), 1,
      sym_cf_condition,
  [4113] = 2,
    ACTIONS(449), 1,
      aux_sym_cf_condition_token1,
    STATE(4), 1,
      sym_cf_condition,
  [4120] = 1,
    ACTIONS(451), 1,
      sym_cf_function_keyword,
  [4124] = 1,
    ACTIONS(453), 1,
      sym_cf_tag_end,
  [4128] = 1,
    ACTIONS(455), 1,
      sym_cf_tag_end,
  [4132] = 1,
    ACTIONS(457), 1,
      sym_cf_function_keyword,
  [4136] = 1,
    ACTIONS(459), 1,
      sym_cf_function_keyword,
  [4140] = 1,
    ACTIONS(461), 1,
      sym_cf_function_keyword,
  [4144] = 1,
    ACTIONS(463), 1,
      sym_cf_function_keyword,
  [4148] = 1,
    ACTIONS(465), 1,
      sym_cf_tag_end,
  [4152] = 1,
    ACTIONS(467), 1,
      sym_cf_if_keyword,
  [4156] = 1,
    ACTIONS(443), 1,
      sym_cf_elseif_keyword,
  [4160] = 1,
    ACTIONS(469), 1,
      anon_sym_GT,
  [4164] = 1,
    ACTIONS(471), 1,
      ts_builtin_sym_end,
  [4168] = 1,
    ACTIONS(473), 1,
      anon_sym_GT,
  [4172] = 1,
    ACTIONS(475), 1,
      sym_cf_function_keyword,
  [4176] = 1,
    ACTIONS(477), 1,
      sym_cf_tag_end,
  [4180] = 1,
    ACTIONS(479), 1,
      sym_cf_tag_end,
  [4184] = 1,
    ACTIONS(481), 1,
      sym_cf_if_keyword,
  [4188] = 1,
    ACTIONS(483), 1,
      sym_cf_tag_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 64,
  [SMALL_STATE(4)] = 106,
  [SMALL_STATE(5)] = 148,
  [SMALL_STATE(6)] = 185,
  [SMALL_STATE(7)] = 222,
  [SMALL_STATE(8)] = 261,
  [SMALL_STATE(9)] = 300,
  [SMALL_STATE(10)] = 337,
  [SMALL_STATE(11)] = 374,
  [SMALL_STATE(12)] = 411,
  [SMALL_STATE(13)] = 450,
  [SMALL_STATE(14)] = 489,
  [SMALL_STATE(15)] = 527,
  [SMALL_STATE(16)] = 567,
  [SMALL_STATE(17)] = 599,
  [SMALL_STATE(18)] = 633,
  [SMALL_STATE(19)] = 663,
  [SMALL_STATE(20)] = 693,
  [SMALL_STATE(21)] = 731,
  [SMALL_STATE(22)] = 766,
  [SMALL_STATE(23)] = 801,
  [SMALL_STATE(24)] = 836,
  [SMALL_STATE(25)] = 871,
  [SMALL_STATE(26)] = 906,
  [SMALL_STATE(27)] = 940,
  [SMALL_STATE(28)] = 974,
  [SMALL_STATE(29)] = 996,
  [SMALL_STATE(30)] = 1018,
  [SMALL_STATE(31)] = 1052,
  [SMALL_STATE(32)] = 1086,
  [SMALL_STATE(33)] = 1108,
  [SMALL_STATE(34)] = 1142,
  [SMALL_STATE(35)] = 1164,
  [SMALL_STATE(36)] = 1198,
  [SMALL_STATE(37)] = 1220,
  [SMALL_STATE(38)] = 1254,
  [SMALL_STATE(39)] = 1288,
  [SMALL_STATE(40)] = 1322,
  [SMALL_STATE(41)] = 1344,
  [SMALL_STATE(42)] = 1378,
  [SMALL_STATE(43)] = 1404,
  [SMALL_STATE(44)] = 1428,
  [SMALL_STATE(45)] = 1452,
  [SMALL_STATE(46)] = 1477,
  [SMALL_STATE(47)] = 1502,
  [SMALL_STATE(48)] = 1526,
  [SMALL_STATE(49)] = 1550,
  [SMALL_STATE(50)] = 1582,
  [SMALL_STATE(51)] = 1608,
  [SMALL_STATE(52)] = 1636,
  [SMALL_STATE(53)] = 1659,
  [SMALL_STATE(54)] = 1692,
  [SMALL_STATE(55)] = 1717,
  [SMALL_STATE(56)] = 1744,
  [SMALL_STATE(57)] = 1777,
  [SMALL_STATE(58)] = 1800,
  [SMALL_STATE(59)] = 1830,
  [SMALL_STATE(60)] = 1860,
  [SMALL_STATE(61)] = 1890,
  [SMALL_STATE(62)] = 1920,
  [SMALL_STATE(63)] = 1950,
  [SMALL_STATE(64)] = 1980,
  [SMALL_STATE(65)] = 2010,
  [SMALL_STATE(66)] = 2040,
  [SMALL_STATE(67)] = 2070,
  [SMALL_STATE(68)] = 2100,
  [SMALL_STATE(69)] = 2122,
  [SMALL_STATE(70)] = 2138,
  [SMALL_STATE(71)] = 2164,
  [SMALL_STATE(72)] = 2194,
  [SMALL_STATE(73)] = 2218,
  [SMALL_STATE(74)] = 2248,
  [SMALL_STATE(75)] = 2278,
  [SMALL_STATE(76)] = 2298,
  [SMALL_STATE(77)] = 2328,
  [SMALL_STATE(78)] = 2358,
  [SMALL_STATE(79)] = 2388,
  [SMALL_STATE(80)] = 2418,
  [SMALL_STATE(81)] = 2444,
  [SMALL_STATE(82)] = 2474,
  [SMALL_STATE(83)] = 2504,
  [SMALL_STATE(84)] = 2526,
  [SMALL_STATE(85)] = 2552,
  [SMALL_STATE(86)] = 2578,
  [SMALL_STATE(87)] = 2602,
  [SMALL_STATE(88)] = 2632,
  [SMALL_STATE(89)] = 2647,
  [SMALL_STATE(90)] = 2662,
  [SMALL_STATE(91)] = 2677,
  [SMALL_STATE(92)] = 2692,
  [SMALL_STATE(93)] = 2707,
  [SMALL_STATE(94)] = 2722,
  [SMALL_STATE(95)] = 2737,
  [SMALL_STATE(96)] = 2752,
  [SMALL_STATE(97)] = 2767,
  [SMALL_STATE(98)] = 2782,
  [SMALL_STATE(99)] = 2797,
  [SMALL_STATE(100)] = 2812,
  [SMALL_STATE(101)] = 2827,
  [SMALL_STATE(102)] = 2842,
  [SMALL_STATE(103)] = 2857,
  [SMALL_STATE(104)] = 2872,
  [SMALL_STATE(105)] = 2887,
  [SMALL_STATE(106)] = 2902,
  [SMALL_STATE(107)] = 2917,
  [SMALL_STATE(108)] = 2932,
  [SMALL_STATE(109)] = 2958,
  [SMALL_STATE(110)] = 2984,
  [SMALL_STATE(111)] = 3010,
  [SMALL_STATE(112)] = 3036,
  [SMALL_STATE(113)] = 3049,
  [SMALL_STATE(114)] = 3062,
  [SMALL_STATE(115)] = 3075,
  [SMALL_STATE(116)] = 3088,
  [SMALL_STATE(117)] = 3101,
  [SMALL_STATE(118)] = 3114,
  [SMALL_STATE(119)] = 3124,
  [SMALL_STATE(120)] = 3134,
  [SMALL_STATE(121)] = 3144,
  [SMALL_STATE(122)] = 3154,
  [SMALL_STATE(123)] = 3164,
  [SMALL_STATE(124)] = 3180,
  [SMALL_STATE(125)] = 3190,
  [SMALL_STATE(126)] = 3206,
  [SMALL_STATE(127)] = 3216,
  [SMALL_STATE(128)] = 3226,
  [SMALL_STATE(129)] = 3236,
  [SMALL_STATE(130)] = 3246,
  [SMALL_STATE(131)] = 3256,
  [SMALL_STATE(132)] = 3266,
  [SMALL_STATE(133)] = 3276,
  [SMALL_STATE(134)] = 3292,
  [SMALL_STATE(135)] = 3302,
  [SMALL_STATE(136)] = 3312,
  [SMALL_STATE(137)] = 3322,
  [SMALL_STATE(138)] = 3340,
  [SMALL_STATE(139)] = 3350,
  [SMALL_STATE(140)] = 3360,
  [SMALL_STATE(141)] = 3370,
  [SMALL_STATE(142)] = 3380,
  [SMALL_STATE(143)] = 3396,
  [SMALL_STATE(144)] = 3409,
  [SMALL_STATE(145)] = 3422,
  [SMALL_STATE(146)] = 3435,
  [SMALL_STATE(147)] = 3448,
  [SMALL_STATE(148)] = 3461,
  [SMALL_STATE(149)] = 3474,
  [SMALL_STATE(150)] = 3487,
  [SMALL_STATE(151)] = 3500,
  [SMALL_STATE(152)] = 3513,
  [SMALL_STATE(153)] = 3526,
  [SMALL_STATE(154)] = 3539,
  [SMALL_STATE(155)] = 3552,
  [SMALL_STATE(156)] = 3565,
  [SMALL_STATE(157)] = 3578,
  [SMALL_STATE(158)] = 3591,
  [SMALL_STATE(159)] = 3604,
  [SMALL_STATE(160)] = 3617,
  [SMALL_STATE(161)] = 3630,
  [SMALL_STATE(162)] = 3643,
  [SMALL_STATE(163)] = 3656,
  [SMALL_STATE(164)] = 3669,
  [SMALL_STATE(165)] = 3682,
  [SMALL_STATE(166)] = 3695,
  [SMALL_STATE(167)] = 3708,
  [SMALL_STATE(168)] = 3721,
  [SMALL_STATE(169)] = 3734,
  [SMALL_STATE(170)] = 3747,
  [SMALL_STATE(171)] = 3760,
  [SMALL_STATE(172)] = 3773,
  [SMALL_STATE(173)] = 3786,
  [SMALL_STATE(174)] = 3799,
  [SMALL_STATE(175)] = 3812,
  [SMALL_STATE(176)] = 3825,
  [SMALL_STATE(177)] = 3838,
  [SMALL_STATE(178)] = 3851,
  [SMALL_STATE(179)] = 3864,
  [SMALL_STATE(180)] = 3877,
  [SMALL_STATE(181)] = 3890,
  [SMALL_STATE(182)] = 3903,
  [SMALL_STATE(183)] = 3914,
  [SMALL_STATE(184)] = 3925,
  [SMALL_STATE(185)] = 3936,
  [SMALL_STATE(186)] = 3947,
  [SMALL_STATE(187)] = 3958,
  [SMALL_STATE(188)] = 3969,
  [SMALL_STATE(189)] = 3980,
  [SMALL_STATE(190)] = 3991,
  [SMALL_STATE(191)] = 4002,
  [SMALL_STATE(192)] = 4013,
  [SMALL_STATE(193)] = 4024,
  [SMALL_STATE(194)] = 4035,
  [SMALL_STATE(195)] = 4046,
  [SMALL_STATE(196)] = 4056,
  [SMALL_STATE(197)] = 4066,
  [SMALL_STATE(198)] = 4076,
  [SMALL_STATE(199)] = 4086,
  [SMALL_STATE(200)] = 4094,
  [SMALL_STATE(201)] = 4101,
  [SMALL_STATE(202)] = 4106,
  [SMALL_STATE(203)] = 4113,
  [SMALL_STATE(204)] = 4120,
  [SMALL_STATE(205)] = 4124,
  [SMALL_STATE(206)] = 4128,
  [SMALL_STATE(207)] = 4132,
  [SMALL_STATE(208)] = 4136,
  [SMALL_STATE(209)] = 4140,
  [SMALL_STATE(210)] = 4144,
  [SMALL_STATE(211)] = 4148,
  [SMALL_STATE(212)] = 4152,
  [SMALL_STATE(213)] = 4156,
  [SMALL_STATE(214)] = 4160,
  [SMALL_STATE(215)] = 4164,
  [SMALL_STATE(216)] = 4168,
  [SMALL_STATE(217)] = 4172,
  [SMALL_STATE(218)] = 4176,
  [SMALL_STATE(219)] = 4180,
  [SMALL_STATE(220)] = 4184,
  [SMALL_STATE(221)] = 4188,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(201),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 3),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 3),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 2),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 4),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 4),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 4),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 4),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 3),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 3),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 5),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 5),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(85),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(89),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(181),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(168),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(178),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(176),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 1),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 3),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 3),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2),
  [109] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(29),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_dblquotes_empty, 2),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(52),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 4),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens_empty, 2),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens_empty, 2),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_variable, 1),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_variable, 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(80),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(122),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(145),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(147),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(148),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(150),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_associative, 3),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_associative, 3),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_dblquotes, 3),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_dblquotes, 3),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens, 3),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens, 3),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 1),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 2),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 2),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_statement, 1),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_statement, 1),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_cf_dblquotes_empty, 2), SHIFT(29),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_condition, 1),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_condition, 1),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_argument, 2),
  [284] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_argument, 2),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1),
  [288] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text, 1),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 7),
  [292] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 7),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 6),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 6),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 5),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 5),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 4),
  [304] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 4),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 3),
  [308] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 3),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 4),
  [312] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 4),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 3),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 3),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_return, 3),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_return, 3),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_argument, 3),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_argument, 3),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 3),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 3),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_hash, 3),
  [332] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_hash, 3),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag, 2),
  [336] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag, 2),
  [338] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 2),
  [340] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 2),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_return, 2),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_return, 2),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 1),
  [348] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 1),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [358] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [376] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(213),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [381] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(203),
  [384] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [418] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2),
  [420] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2), SHIFT_REPEAT(199),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [445] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_assignment, 1),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [471] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
