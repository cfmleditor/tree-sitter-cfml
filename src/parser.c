#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 143
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 52
#define ALIAS_COUNT 0
#define TOKEN_COUNT 28
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
  anon_sym_LPAREN = 13,
  anon_sym_RPAREN = 14,
  anon_sym_set = 15,
  anon_sym_GT = 16,
  anon_sym_RBRACE = 17,
  anon_sym_SQUOTE = 18,
  aux_sym_quoted_attribute_value_token1 = 19,
  anon_sym_DQUOTE = 20,
  aux_sym_quoted_attribute_value_token2 = 21,
  sym_attribute_name = 22,
  sym_attribute_value = 23,
  sym_cf_if_keyword = 24,
  sym_cf_elseif_keyword = 25,
  sym_cf_else_keyword = 26,
  sym_cf_function_keyword = 27,
  sym_fragment = 28,
  sym_cf_condition = 29,
  sym_text = 30,
  sym_cf_variable = 31,
  sym__node = 32,
  sym_cf_hash = 33,
  sym_cf_associative = 34,
  sym__cf_expression = 35,
  sym_cf_assignment = 36,
  sym_cf_parens = 37,
  sym_cf_function = 38,
  sym_cf_ifstatement = 39,
  sym_cf_if = 40,
  sym_cf_set = 41,
  sym_cf_elseif = 42,
  sym_cf_else = 43,
  sym_cf_if_end = 44,
  sym_quoted_attribute_value = 45,
  sym_attribute = 46,
  sym_cf_tag = 47,
  sym__cf_statement = 48,
  aux_sym_fragment_repeat1 = 49,
  aux_sym_cf_function_repeat1 = 50,
  aux_sym_cf_ifstatement_repeat1 = 51,
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
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_set] = "set",
  [anon_sym_GT] = ">",
  [anon_sym_RBRACE] = "}",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [sym_cf_if_keyword] = "cf_if_keyword",
  [sym_cf_elseif_keyword] = "cf_elseif_keyword",
  [sym_cf_else_keyword] = "cf_else_keyword",
  [sym_cf_function_keyword] = "cf_function_keyword",
  [sym_fragment] = "fragment",
  [sym_cf_condition] = "cf_condition",
  [sym_text] = "text",
  [sym_cf_variable] = "cf_variable",
  [sym__node] = "_node",
  [sym_cf_hash] = "cf_hash",
  [sym_cf_associative] = "cf_associative",
  [sym__cf_expression] = "_cf_expression",
  [sym_cf_assignment] = "cf_assignment",
  [sym_cf_parens] = "cf_parens",
  [sym_cf_function] = "cf_function",
  [sym_cf_ifstatement] = "cf_ifstatement",
  [sym_cf_if] = "cf_if",
  [sym_cf_set] = "cf_set",
  [sym_cf_elseif] = "cf_elseif",
  [sym_cf_else] = "cf_else",
  [sym_cf_if_end] = "cf_if_end",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
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
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_set] = anon_sym_set,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [sym_cf_if_keyword] = sym_cf_if_keyword,
  [sym_cf_elseif_keyword] = sym_cf_elseif_keyword,
  [sym_cf_else_keyword] = sym_cf_else_keyword,
  [sym_cf_function_keyword] = sym_cf_function_keyword,
  [sym_fragment] = sym_fragment,
  [sym_cf_condition] = sym_cf_condition,
  [sym_text] = sym_text,
  [sym_cf_variable] = sym_cf_variable,
  [sym__node] = sym__node,
  [sym_cf_hash] = sym_cf_hash,
  [sym_cf_associative] = sym_cf_associative,
  [sym__cf_expression] = sym__cf_expression,
  [sym_cf_assignment] = sym_cf_assignment,
  [sym_cf_parens] = sym_cf_parens,
  [sym_cf_function] = sym_cf_function,
  [sym_cf_ifstatement] = sym_cf_ifstatement,
  [sym_cf_if] = sym_cf_if,
  [sym_cf_set] = sym_cf_set,
  [sym_cf_elseif] = sym_cf_elseif,
  [sym_cf_else] = sym_cf_else,
  [sym_cf_if_end] = sym_cf_if_end,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
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
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token2] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_value] = {
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
  [sym_cf_parens] = {
    .visible = true,
    .named = true,
  },
  [sym_cf_function] = {
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
  [sym_quoted_attribute_value] = {
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
  [30] = 30,
  [31] = 31,
  [32] = 9,
  [33] = 33,
  [34] = 34,
  [35] = 30,
  [36] = 36,
  [37] = 36,
  [38] = 38,
  [39] = 34,
  [40] = 31,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 42,
  [46] = 46,
  [47] = 47,
  [48] = 46,
  [49] = 47,
  [50] = 46,
  [51] = 42,
  [52] = 44,
  [53] = 53,
  [54] = 24,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 58,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 55,
  [71] = 65,
  [72] = 22,
  [73] = 73,
  [74] = 56,
  [75] = 57,
  [76] = 67,
  [77] = 69,
  [78] = 53,
  [79] = 60,
  [80] = 63,
  [81] = 66,
  [82] = 24,
  [83] = 62,
  [84] = 64,
  [85] = 22,
  [86] = 61,
  [87] = 68,
  [88] = 88,
  [89] = 89,
  [90] = 89,
  [91] = 91,
  [92] = 91,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 95,
  [100] = 100,
  [101] = 101,
  [102] = 97,
  [103] = 96,
  [104] = 104,
  [105] = 98,
  [106] = 97,
  [107] = 107,
  [108] = 96,
  [109] = 104,
  [110] = 110,
  [111] = 107,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
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
  [131] = 127,
  [132] = 123,
  [133] = 128,
  [134] = 134,
  [135] = 134,
  [136] = 136,
  [137] = 126,
  [138] = 124,
  [139] = 139,
  [140] = 140,
  [141] = 122,
  [142] = 125,
};

static inline bool aux_sym_text_token1_character_set_1(int32_t c) {
  return (c < ','
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '('
        ? c == '#'
        : c <= ')')))
    : (c <= ',' || (c < ']'
      ? (c < '<'
        ? c == '.'
        : (c <= '=' || c == '['))
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool aux_sym_text_token1_character_set_2(int32_t c) {
  return (c < ','
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '('
        ? c == '#'
        : c <= ')')))
    : (c <= ',' || (c < ']'
      ? (c < '<'
        ? c == '.'
        : (c <= '>' || c == '['))
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool aux_sym_text_token1_character_set_3(int32_t c) {
  return (c < '<'
    ? (c < '('
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

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(47);
      if (lookahead == '"') ADVANCE(94);
      if (lookahead == '#') ADVANCE(79);
      if (lookahead == '\'') ADVANCE(91);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == ')') ADVANCE(87);
      if (lookahead == ',') ADVANCE(83);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '=') ADVANCE(85);
      if (lookahead == '>') ADVANCE(89);
      if (lookahead == '[') ADVANCE(80);
      if (lookahead == ']') ADVANCE(81);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead == 'f') ADVANCE(43);
      if (lookahead == 'i') ADVANCE(26);
      if (lookahead == 's') ADVANCE(22);
      if (lookahead == '}') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(94);
      if (lookahead == '#') ADVANCE(79);
      if (lookahead == '\'') ADVANCE(91);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == ')') ADVANCE(87);
      if (lookahead == ',') ADVANCE(83);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '=') ADVANCE(85);
      if (lookahead == '>') ADVANCE(89);
      if (lookahead == 'A') ADVANCE(14);
      if (lookahead == 'E') ADVANCE(16);
      if (lookahead == 'G') ADVANCE(19);
      if (lookahead == 'N') ADVANCE(15);
      if (lookahead == 'O') ADVANCE(17);
      if (lookahead == '[') ADVANCE(80);
      if (lookahead == ']') ADVANCE(81);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead == 'f') ADVANCE(43);
      if (lookahead == 'i') ADVANCE(26);
      if (lookahead == 's') ADVANCE(22);
      if (lookahead == '}') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(94);
      if (lookahead == '\'') ADVANCE(91);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(98);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(95);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(79);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == ')') ADVANCE(87);
      if (lookahead == ',') ADVANCE(83);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '=') ADVANCE(85);
      if (lookahead == '>') ADVANCE(51);
      if (lookahead == 'A') ADVANCE(55);
      if (lookahead == 'E') ADVANCE(57);
      if (lookahead == 'G') ADVANCE(60);
      if (lookahead == 'N') ADVANCE(56);
      if (lookahead == 'O') ADVANCE(58);
      if (lookahead == '[') ADVANCE(80);
      if (lookahead == ']') ADVANCE(81);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == '}') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(76);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(79);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == ')') ADVANCE(87);
      if (lookahead == ',') ADVANCE(83);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '=') ADVANCE(85);
      if (lookahead == '>') ADVANCE(51);
      if (lookahead == '[') ADVANCE(80);
      if (lookahead == ']') ADVANCE(81);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == '}') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(76);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(79);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '>') ADVANCE(51);
      if (lookahead == '[') ADVANCE(80);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == '}') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != ',' &&
          lookahead != '.' &&
          lookahead != '=' &&
          lookahead != ']' &&
          lookahead != '{') ADVANCE(76);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(91);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(92);
      if (lookahead != 0) ADVANCE(93);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '=') ADVANCE(84);
      if (lookahead == '>') ADVANCE(51);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(97);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(21);
      if (lookahead == 'c') ADVANCE(27);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(78);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(51);
      END_STATE();
    case 12:
      if (lookahead == 'D') ADVANCE(44);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(78);
      END_STATE();
    case 14:
      if (lookahead == 'N') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'O') ADVANCE(18);
      END_STATE();
    case 16:
      if (lookahead == 'Q') ADVANCE(44);
      END_STATE();
    case 17:
      if (lookahead == 'R') ADVANCE(44);
      END_STATE();
    case 18:
      if (lookahead == 'T') ADVANCE(44);
      END_STATE();
    case 19:
      if (lookahead == 'T') ADVANCE(13);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(28);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(102);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 26:
      if (lookahead == 'f') ADVANCE(99);
      END_STATE();
    case 27:
      if (lookahead == 'f') ADVANCE(50);
      END_STATE();
    case 28:
      if (lookahead == 'f') ADVANCE(77);
      END_STATE();
    case 29:
      if (lookahead == 'f') ADVANCE(100);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(38);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(39);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(103);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 37:
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 38:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 39:
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 40:
      if (lookahead == 's') ADVANCE(25);
      END_STATE();
    case 41:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 42:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 43:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 44:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(78);
      END_STATE();
    case 45:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(48);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(49);
      END_STATE();
    case 46:
      if (eof) ADVANCE(47);
      if (lookahead == '#') ADVANCE(79);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == '<') ADVANCE(9);
      if (lookahead == '>') ADVANCE(89);
      if (lookahead == '[') ADVANCE(80);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == '}') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (lookahead != 0 &&
          lookahead != ')' &&
          lookahead != ',' &&
          lookahead != '.' &&
          lookahead != '=' &&
          lookahead != ']' &&
          lookahead != '{') ADVANCE(76);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(48);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(49);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_cf_condition_token1);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead) &&
          lookahead != '[' &&
          lookahead != ']') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__cf_tag_start);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_cf_tag_end);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '>') ADVANCE(51);
      if (!aux_sym_text_token1_character_set_1(lookahead)) ADVANCE(76);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'D') ADVANCE(75);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'E') ADVANCE(75);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(78);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(76);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'N') ADVANCE(53);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'O') ADVANCE(59);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'Q') ADVANCE(75);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'R') ADVANCE(75);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(75);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'T') ADVANCE(54);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(63);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(68);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(70);
      if (lookahead == 'i') ADVANCE(67);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(70);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(71);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'e') ADVANCE(64);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'f') ADVANCE(65);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'i') ADVANCE(67);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(72);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(73);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 'l') ADVANCE(74);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(61);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(66);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == 's') ADVANCE(62);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(78);
      if (!aux_sym_text_token1_character_set_3(lookahead)) ADVANCE(76);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (!aux_sym_text_token1_character_set_2(lookahead)) ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_cf_tag_close);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_cf_operator);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_cf_period);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_cf_comma);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(10);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_set);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(93);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(96);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(98);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_cf_if_keyword);
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_cf_elseif_keyword);
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(33);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_cf_else_keyword);
      if (lookahead == 'e') ADVANCE(33);
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_cf_function_keyword);
      if (lookahead == 'f') ADVANCE(43);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 46},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 46},
  [10] = {.lex_state = 46},
  [11] = {.lex_state = 46},
  [12] = {.lex_state = 46},
  [13] = {.lex_state = 46},
  [14] = {.lex_state = 46},
  [15] = {.lex_state = 46},
  [16] = {.lex_state = 46},
  [17] = {.lex_state = 46},
  [18] = {.lex_state = 5},
  [19] = {.lex_state = 6},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 5},
  [25] = {.lex_state = 46},
  [26] = {.lex_state = 46},
  [27] = {.lex_state = 46},
  [28] = {.lex_state = 46},
  [29] = {.lex_state = 46},
  [30] = {.lex_state = 46},
  [31] = {.lex_state = 46},
  [32] = {.lex_state = 46},
  [33] = {.lex_state = 5},
  [34] = {.lex_state = 46},
  [35] = {.lex_state = 46},
  [36] = {.lex_state = 46},
  [37] = {.lex_state = 46},
  [38] = {.lex_state = 46},
  [39] = {.lex_state = 46},
  [40] = {.lex_state = 46},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 6},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 5},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 46},
  [54] = {.lex_state = 46},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 46},
  [57] = {.lex_state = 46},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 46},
  [61] = {.lex_state = 46},
  [62] = {.lex_state = 46},
  [63] = {.lex_state = 46},
  [64] = {.lex_state = 46},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 46},
  [67] = {.lex_state = 46},
  [68] = {.lex_state = 46},
  [69] = {.lex_state = 46},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 46},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 46},
  [75] = {.lex_state = 46},
  [76] = {.lex_state = 46},
  [77] = {.lex_state = 46},
  [78] = {.lex_state = 46},
  [79] = {.lex_state = 46},
  [80] = {.lex_state = 46},
  [81] = {.lex_state = 46},
  [82] = {.lex_state = 46},
  [83] = {.lex_state = 46},
  [84] = {.lex_state = 46},
  [85] = {.lex_state = 46},
  [86] = {.lex_state = 46},
  [87] = {.lex_state = 46},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 8},
  [90] = {.lex_state = 8},
  [91] = {.lex_state = 8},
  [92] = {.lex_state = 8},
  [93] = {.lex_state = 8},
  [94] = {.lex_state = 46},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 46},
  [97] = {.lex_state = 46},
  [98] = {.lex_state = 46},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 46},
  [101] = {.lex_state = 8},
  [102] = {.lex_state = 46},
  [103] = {.lex_state = 46},
  [104] = {.lex_state = 46},
  [105] = {.lex_state = 46},
  [106] = {.lex_state = 46},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 46},
  [109] = {.lex_state = 46},
  [110] = {.lex_state = 46},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 46},
  [113] = {.lex_state = 46},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 45},
  [116] = {.lex_state = 8},
  [117] = {.lex_state = 8},
  [118] = {.lex_state = 8},
  [119] = {.lex_state = 3},
  [120] = {.lex_state = 45},
  [121] = {.lex_state = 7},
  [122] = {.lex_state = 46},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 5},
  [125] = {.lex_state = 5},
  [126] = {.lex_state = 5},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 46},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 5},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 46},
  [142] = {.lex_state = 5},
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
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_set] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_cf_if_keyword] = ACTIONS(1),
    [sym_cf_elseif_keyword] = ACTIONS(1),
    [sym_cf_else_keyword] = ACTIONS(1),
    [sym_cf_function_keyword] = ACTIONS(1),
  },
  [1] = {
    [sym_fragment] = STATE(140),
    [sym_text] = STATE(38),
    [sym__node] = STATE(38),
    [sym_cf_hash] = STATE(38),
    [sym_cf_associative] = STATE(38),
    [sym_cf_parens] = STATE(38),
    [sym_cf_tag] = STATE(38),
    [sym__cf_statement] = STATE(38),
    [aux_sym_fragment_repeat1] = STATE(38),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__cf_tag_start] = ACTIONS(5),
    [aux_sym_text_token1] = ACTIONS(7),
    [anon_sym_POUND] = ACTIONS(9),
    [anon_sym_LBRACK] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(17), 1,
      sym_cf_tag_end,
    ACTIONS(19), 1,
      aux_sym_text_token1,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    STATE(33), 1,
      sym_cf_parens,
    STATE(41), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
    ACTIONS(21), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(37), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(13), 6,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [56] = 8,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
    ACTIONS(41), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(39), 9,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [92] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
    ACTIONS(41), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(39), 8,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_RBRACK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [132] = 7,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(31), 1,
      sym_cf_comma,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
    ACTIONS(41), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(39), 10,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [166] = 6,
    ACTIONS(23), 1,
      sym_cf_operator,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
    ACTIONS(41), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(39), 11,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [198] = 9,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(19), 1,
      aux_sym_text_token1,
    ACTIONS(25), 1,
      anon_sym_POUND,
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
    STATE(16), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [235] = 9,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(19), 1,
      aux_sym_text_token1,
    ACTIONS(25), 1,
      anon_sym_POUND,
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
    STATE(12), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [272] = 8,
    ACTIONS(59), 1,
      sym__cf_tag_start,
    ACTIONS(62), 1,
      aux_sym_text_token1,
    ACTIONS(67), 1,
      anon_sym_POUND,
    ACTIONS(70), 1,
      anon_sym_LBRACK,
    ACTIONS(73), 1,
      anon_sym_LPAREN,
    ACTIONS(65), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(76), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [306] = 7,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(82), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(78), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [338] = 8,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(84), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(86), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(14), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [372] = 7,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(90), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(88), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [404] = 7,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(86), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(84), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [436] = 7,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(94), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(92), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [468] = 8,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(88), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(90), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(10), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [502] = 7,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(57), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(55), 3,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [534] = 8,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(55), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    ACTIONS(57), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    STATE(12), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [568] = 2,
    ACTIONS(98), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(96), 12,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [589] = 8,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(19), 1,
      aux_sym_text_token1,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(100), 1,
      sym_cf_tag_end,
    ACTIONS(102), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(25), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [622] = 2,
    ACTIONS(98), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(96), 12,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [643] = 2,
    ACTIONS(106), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(104), 12,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [664] = 2,
    ACTIONS(110), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(108), 12,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [685] = 8,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(19), 1,
      aux_sym_text_token1,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(112), 1,
      sym_cf_tag_end,
    ACTIONS(114), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(29), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [718] = 2,
    ACTIONS(118), 4,
      aux_sym_text_token1,
      anon_sym_EQ,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(116), 12,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      sym_cf_operator,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_cf_period,
      sym_cf_comma,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [739] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(114), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [769] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(120), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [799] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(114), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(29), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [829] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(122), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(26), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [859] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(122), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [889] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(124), 1,
      sym_cf_tag_close,
    STATE(36), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [918] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(126), 1,
      sym_cf_tag_close,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [947] = 7,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
    ACTIONS(128), 1,
      sym__cf_tag_start,
    ACTIONS(131), 1,
      aux_sym_text_token1,
    ACTIONS(134), 1,
      anon_sym_POUND,
    ACTIONS(137), 1,
      anon_sym_LBRACK,
    ACTIONS(140), 1,
      anon_sym_LPAREN,
    STATE(32), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [976] = 4,
    ACTIONS(98), 1,
      anon_sym_EQ,
    ACTIONS(145), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(96), 4,
      sym_cf_tag_end,
      sym_cf_operator,
      sym_cf_period,
      sym_cf_comma,
    ACTIONS(143), 6,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [999] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(147), 1,
      sym_cf_tag_close,
    STATE(31), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1028] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(149), 1,
      sym_cf_tag_close,
    STATE(37), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1057] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(147), 1,
      sym_cf_tag_close,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1086] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(151), 1,
      sym_cf_tag_close,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1115] = 7,
    ACTIONS(5), 1,
      sym__cf_tag_start,
    ACTIONS(7), 1,
      aux_sym_text_token1,
    ACTIONS(9), 1,
      anon_sym_POUND,
    ACTIONS(11), 1,
      anon_sym_LBRACK,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(153), 1,
      ts_builtin_sym_end,
    STATE(32), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1144] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(151), 1,
      sym_cf_tag_close,
    STATE(40), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1173] = 7,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_LBRACK,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      aux_sym_text_token1,
    ACTIONS(155), 1,
      sym_cf_tag_close,
    STATE(9), 8,
      sym_text,
      sym__node,
      sym_cf_hash,
      sym_cf_associative,
      sym_cf_parens,
      sym_cf_tag,
      sym__cf_statement,
      aux_sym_fragment_repeat1,
  [1202] = 4,
    ACTIONS(98), 1,
      anon_sym_EQ,
    ACTIONS(145), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(96), 4,
      sym_cf_tag_end,
      sym_cf_operator,
      sym_cf_period,
      sym_cf_comma,
    ACTIONS(143), 6,
      sym__cf_tag_start,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1225] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(157), 1,
      anon_sym_RBRACK,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1256] = 2,
    ACTIONS(161), 3,
      aux_sym_text_token1,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(159), 7,
      sym__cf_tag_start,
      sym_cf_tag_end,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1271] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(163), 1,
      anon_sym_POUND,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1302] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(165), 1,
      anon_sym_RBRACK,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1333] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(167), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1364] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(169), 1,
      sym_cf_tag_end,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1395] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(171), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1426] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(173), 1,
      sym_cf_tag_end,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1457] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1488] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1519] = 10,
    ACTIONS(23), 1,
      sym_cf_operator,
    ACTIONS(27), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      sym_cf_period,
    ACTIONS(31), 1,
      sym_cf_comma,
    ACTIONS(33), 1,
      anon_sym_EQ,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(179), 1,
      anon_sym_POUND,
    STATE(18), 1,
      sym_cf_parens,
    STATE(20), 1,
      sym_cf_associative,
    STATE(113), 1,
      sym_cf_assignment,
  [1550] = 2,
    ACTIONS(183), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(181), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1564] = 2,
    ACTIONS(118), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(116), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1578] = 8,
    ACTIONS(185), 1,
      sym__cf_tag_start,
    ACTIONS(187), 1,
      sym_cf_tag_close,
    ACTIONS(189), 1,
      anon_sym_RBRACE,
    ACTIONS(191), 1,
      sym_cf_elseif_keyword,
    ACTIONS(193), 1,
      sym_cf_else_keyword,
    STATE(61), 1,
      sym_cf_if_end,
    STATE(99), 1,
      sym_cf_else,
    STATE(59), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [1604] = 2,
    ACTIONS(197), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(195), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1618] = 2,
    ACTIONS(201), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(199), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1632] = 8,
    ACTIONS(185), 1,
      sym__cf_tag_start,
    ACTIONS(191), 1,
      sym_cf_elseif_keyword,
    ACTIONS(193), 1,
      sym_cf_else_keyword,
    ACTIONS(203), 1,
      sym_cf_tag_close,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
    STATE(87), 1,
      sym_cf_if_end,
    STATE(111), 1,
      sym_cf_else,
    STATE(73), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [1658] = 8,
    ACTIONS(185), 1,
      sym__cf_tag_start,
    ACTIONS(187), 1,
      sym_cf_tag_close,
    ACTIONS(189), 1,
      anon_sym_RBRACE,
    ACTIONS(191), 1,
      sym_cf_elseif_keyword,
    ACTIONS(193), 1,
      sym_cf_else_keyword,
    STATE(68), 1,
      sym_cf_if_end,
    STATE(107), 1,
      sym_cf_else,
    STATE(73), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [1684] = 2,
    ACTIONS(209), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(207), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1698] = 2,
    ACTIONS(213), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(211), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1712] = 2,
    ACTIONS(217), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(215), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1726] = 2,
    ACTIONS(221), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(219), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1740] = 2,
    ACTIONS(225), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(223), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1754] = 6,
    ACTIONS(15), 1,
      sym__cf_tag_start,
    ACTIONS(227), 1,
      anon_sym_set,
    ACTIONS(229), 1,
      sym_cf_if_keyword,
    ACTIONS(231), 1,
      sym_cf_function_keyword,
    STATE(55), 1,
      sym_cf_if,
    STATE(63), 4,
      sym_cf_function,
      sym_cf_ifstatement,
      sym_cf_set,
      sym_cf_tag,
  [1776] = 2,
    ACTIONS(235), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(233), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1790] = 2,
    ACTIONS(239), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(237), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1804] = 2,
    ACTIONS(243), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(241), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1818] = 2,
    ACTIONS(247), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(245), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1832] = 8,
    ACTIONS(185), 1,
      sym__cf_tag_start,
    ACTIONS(191), 1,
      sym_cf_elseif_keyword,
    ACTIONS(193), 1,
      sym_cf_else_keyword,
    ACTIONS(203), 1,
      sym_cf_tag_close,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
    STATE(86), 1,
      sym_cf_if_end,
    STATE(95), 1,
      sym_cf_else,
    STATE(58), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [1858] = 6,
    ACTIONS(5), 1,
      sym__cf_tag_start,
    ACTIONS(229), 1,
      sym_cf_if_keyword,
    ACTIONS(249), 1,
      anon_sym_set,
    ACTIONS(251), 1,
      sym_cf_function_keyword,
    STATE(70), 1,
      sym_cf_if,
    STATE(80), 4,
      sym_cf_function,
      sym_cf_ifstatement,
      sym_cf_set,
      sym_cf_tag,
  [1880] = 2,
    ACTIONS(110), 2,
      sym_cf_elseif_keyword,
      sym_cf_else_keyword,
    ACTIONS(108), 7,
      sym__cf_tag_start,
      aux_sym_text_token1,
      sym_cf_tag_close,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACE,
  [1894] = 5,
    ACTIONS(253), 1,
      sym__cf_tag_start,
    ACTIONS(258), 1,
      sym_cf_elseif_keyword,
    ACTIONS(261), 1,
      sym_cf_else_keyword,
    ACTIONS(256), 2,
      sym_cf_tag_close,
      anon_sym_RBRACE,
    STATE(73), 2,
      sym_cf_elseif,
      aux_sym_cf_ifstatement_repeat1,
  [1912] = 1,
    ACTIONS(195), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1921] = 1,
    ACTIONS(199), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1930] = 1,
    ACTIONS(237), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1939] = 1,
    ACTIONS(245), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1948] = 1,
    ACTIONS(181), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1957] = 1,
    ACTIONS(207), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1966] = 1,
    ACTIONS(219), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1975] = 1,
    ACTIONS(233), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1984] = 1,
    ACTIONS(116), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1993] = 1,
    ACTIONS(215), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2002] = 1,
    ACTIONS(223), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2011] = 1,
    ACTIONS(108), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2020] = 1,
    ACTIONS(211), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2029] = 1,
    ACTIONS(241), 6,
      ts_builtin_sym_end,
      sym__cf_tag_start,
      aux_sym_text_token1,
      anon_sym_POUND,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2038] = 4,
    ACTIONS(263), 1,
      anon_sym_SQUOTE,
    ACTIONS(265), 1,
      anon_sym_DQUOTE,
    ACTIONS(267), 1,
      sym_attribute_value,
    STATE(118), 1,
      sym_quoted_attribute_value,
  [2051] = 3,
    ACTIONS(269), 1,
      sym_cf_tag_end,
    ACTIONS(271), 1,
      sym_attribute_name,
    STATE(91), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [2062] = 3,
    ACTIONS(271), 1,
      sym_attribute_name,
    ACTIONS(273), 1,
      sym_cf_tag_end,
    STATE(92), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [2073] = 3,
    ACTIONS(271), 1,
      sym_attribute_name,
    ACTIONS(275), 1,
      sym_cf_tag_end,
    STATE(93), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [2084] = 3,
    ACTIONS(271), 1,
      sym_attribute_name,
    ACTIONS(277), 1,
      sym_cf_tag_end,
    STATE(93), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [2095] = 3,
    ACTIONS(279), 1,
      sym_cf_tag_end,
    ACTIONS(281), 1,
      sym_attribute_name,
    STATE(93), 2,
      sym_attribute,
      aux_sym_cf_function_repeat1,
  [2106] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(5), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2114] = 3,
    ACTIONS(203), 1,
      sym_cf_tag_close,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
    STATE(87), 1,
      sym_cf_if_end,
  [2124] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(45), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2132] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(46), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2140] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(47), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2148] = 3,
    ACTIONS(187), 1,
      sym_cf_tag_close,
    ACTIONS(189), 1,
      anon_sym_RBRACE,
    STATE(68), 1,
      sym_cf_if_end,
  [2158] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(2), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2166] = 2,
    ACTIONS(288), 1,
      anon_sym_EQ,
    ACTIONS(286), 2,
      sym_cf_tag_end,
      sym_attribute_name,
  [2174] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(48), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2182] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(42), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2190] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(44), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2198] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(49), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2206] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(50), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2214] = 3,
    ACTIONS(187), 1,
      sym_cf_tag_close,
    ACTIONS(189), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      sym_cf_if_end,
  [2224] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(51), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2232] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(52), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2240] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(6), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2248] = 3,
    ACTIONS(203), 1,
      sym_cf_tag_close,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
    STATE(78), 1,
      sym_cf_if_end,
  [2258] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(3), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2266] = 2,
    ACTIONS(284), 1,
      aux_sym_text_token1,
    STATE(4), 2,
      sym_cf_variable,
      sym__cf_expression,
  [2274] = 2,
    ACTIONS(290), 1,
      sym_cf_elseif_keyword,
    ACTIONS(292), 1,
      sym_cf_else_keyword,
  [2281] = 2,
    ACTIONS(294), 1,
      aux_sym_cf_condition_token1,
    STATE(8), 1,
      sym_cf_condition,
  [2288] = 1,
    ACTIONS(296), 2,
      sym_cf_tag_end,
      sym_attribute_name,
  [2293] = 1,
    ACTIONS(298), 2,
      sym_cf_tag_end,
      sym_attribute_name,
  [2298] = 1,
    ACTIONS(300), 2,
      sym_cf_tag_end,
      sym_attribute_name,
  [2303] = 2,
    ACTIONS(302), 1,
      anon_sym_DQUOTE,
    ACTIONS(304), 1,
      aux_sym_quoted_attribute_value_token2,
  [2310] = 2,
    ACTIONS(294), 1,
      aux_sym_cf_condition_token1,
    STATE(7), 1,
      sym_cf_condition,
  [2317] = 2,
    ACTIONS(302), 1,
      anon_sym_SQUOTE,
    ACTIONS(306), 1,
      aux_sym_quoted_attribute_value_token1,
  [2324] = 1,
    ACTIONS(308), 1,
      anon_sym_GT,
  [2328] = 1,
    ACTIONS(310), 1,
      sym_cf_function_keyword,
  [2332] = 1,
    ACTIONS(312), 1,
      sym_cf_tag_end,
  [2336] = 1,
    ACTIONS(314), 1,
      sym_cf_tag_end,
  [2340] = 1,
    ACTIONS(316), 1,
      sym_cf_tag_end,
  [2344] = 1,
    ACTIONS(318), 1,
      sym_cf_if_keyword,
  [2348] = 1,
    ACTIONS(320), 1,
      sym_cf_function_keyword,
  [2352] = 1,
    ACTIONS(322), 1,
      aux_sym_text_token1,
  [2356] = 1,
    ACTIONS(290), 1,
      sym_cf_elseif_keyword,
  [2360] = 1,
    ACTIONS(324), 1,
      sym_cf_if_keyword,
  [2364] = 1,
    ACTIONS(326), 1,
      sym_cf_function_keyword,
  [2368] = 1,
    ACTIONS(328), 1,
      sym_cf_function_keyword,
  [2372] = 1,
    ACTIONS(330), 1,
      sym_cf_function_keyword,
  [2376] = 1,
    ACTIONS(332), 1,
      sym_cf_function_keyword,
  [2380] = 1,
    ACTIONS(334), 1,
      anon_sym_DQUOTE,
  [2384] = 1,
    ACTIONS(336), 1,
      sym_cf_tag_end,
  [2388] = 1,
    ACTIONS(338), 1,
      sym_cf_tag_end,
  [2392] = 1,
    ACTIONS(334), 1,
      anon_sym_SQUOTE,
  [2396] = 1,
    ACTIONS(340), 1,
      ts_builtin_sym_end,
  [2400] = 1,
    ACTIONS(342), 1,
      anon_sym_GT,
  [2404] = 1,
    ACTIONS(344), 1,
      sym_cf_tag_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 56,
  [SMALL_STATE(4)] = 92,
  [SMALL_STATE(5)] = 132,
  [SMALL_STATE(6)] = 166,
  [SMALL_STATE(7)] = 198,
  [SMALL_STATE(8)] = 235,
  [SMALL_STATE(9)] = 272,
  [SMALL_STATE(10)] = 306,
  [SMALL_STATE(11)] = 338,
  [SMALL_STATE(12)] = 372,
  [SMALL_STATE(13)] = 404,
  [SMALL_STATE(14)] = 436,
  [SMALL_STATE(15)] = 468,
  [SMALL_STATE(16)] = 502,
  [SMALL_STATE(17)] = 534,
  [SMALL_STATE(18)] = 568,
  [SMALL_STATE(19)] = 589,
  [SMALL_STATE(20)] = 622,
  [SMALL_STATE(21)] = 643,
  [SMALL_STATE(22)] = 664,
  [SMALL_STATE(23)] = 685,
  [SMALL_STATE(24)] = 718,
  [SMALL_STATE(25)] = 739,
  [SMALL_STATE(26)] = 769,
  [SMALL_STATE(27)] = 799,
  [SMALL_STATE(28)] = 829,
  [SMALL_STATE(29)] = 859,
  [SMALL_STATE(30)] = 889,
  [SMALL_STATE(31)] = 918,
  [SMALL_STATE(32)] = 947,
  [SMALL_STATE(33)] = 976,
  [SMALL_STATE(34)] = 999,
  [SMALL_STATE(35)] = 1028,
  [SMALL_STATE(36)] = 1057,
  [SMALL_STATE(37)] = 1086,
  [SMALL_STATE(38)] = 1115,
  [SMALL_STATE(39)] = 1144,
  [SMALL_STATE(40)] = 1173,
  [SMALL_STATE(41)] = 1202,
  [SMALL_STATE(42)] = 1225,
  [SMALL_STATE(43)] = 1256,
  [SMALL_STATE(44)] = 1271,
  [SMALL_STATE(45)] = 1302,
  [SMALL_STATE(46)] = 1333,
  [SMALL_STATE(47)] = 1364,
  [SMALL_STATE(48)] = 1395,
  [SMALL_STATE(49)] = 1426,
  [SMALL_STATE(50)] = 1457,
  [SMALL_STATE(51)] = 1488,
  [SMALL_STATE(52)] = 1519,
  [SMALL_STATE(53)] = 1550,
  [SMALL_STATE(54)] = 1564,
  [SMALL_STATE(55)] = 1578,
  [SMALL_STATE(56)] = 1604,
  [SMALL_STATE(57)] = 1618,
  [SMALL_STATE(58)] = 1632,
  [SMALL_STATE(59)] = 1658,
  [SMALL_STATE(60)] = 1684,
  [SMALL_STATE(61)] = 1698,
  [SMALL_STATE(62)] = 1712,
  [SMALL_STATE(63)] = 1726,
  [SMALL_STATE(64)] = 1740,
  [SMALL_STATE(65)] = 1754,
  [SMALL_STATE(66)] = 1776,
  [SMALL_STATE(67)] = 1790,
  [SMALL_STATE(68)] = 1804,
  [SMALL_STATE(69)] = 1818,
  [SMALL_STATE(70)] = 1832,
  [SMALL_STATE(71)] = 1858,
  [SMALL_STATE(72)] = 1880,
  [SMALL_STATE(73)] = 1894,
  [SMALL_STATE(74)] = 1912,
  [SMALL_STATE(75)] = 1921,
  [SMALL_STATE(76)] = 1930,
  [SMALL_STATE(77)] = 1939,
  [SMALL_STATE(78)] = 1948,
  [SMALL_STATE(79)] = 1957,
  [SMALL_STATE(80)] = 1966,
  [SMALL_STATE(81)] = 1975,
  [SMALL_STATE(82)] = 1984,
  [SMALL_STATE(83)] = 1993,
  [SMALL_STATE(84)] = 2002,
  [SMALL_STATE(85)] = 2011,
  [SMALL_STATE(86)] = 2020,
  [SMALL_STATE(87)] = 2029,
  [SMALL_STATE(88)] = 2038,
  [SMALL_STATE(89)] = 2051,
  [SMALL_STATE(90)] = 2062,
  [SMALL_STATE(91)] = 2073,
  [SMALL_STATE(92)] = 2084,
  [SMALL_STATE(93)] = 2095,
  [SMALL_STATE(94)] = 2106,
  [SMALL_STATE(95)] = 2114,
  [SMALL_STATE(96)] = 2124,
  [SMALL_STATE(97)] = 2132,
  [SMALL_STATE(98)] = 2140,
  [SMALL_STATE(99)] = 2148,
  [SMALL_STATE(100)] = 2158,
  [SMALL_STATE(101)] = 2166,
  [SMALL_STATE(102)] = 2174,
  [SMALL_STATE(103)] = 2182,
  [SMALL_STATE(104)] = 2190,
  [SMALL_STATE(105)] = 2198,
  [SMALL_STATE(106)] = 2206,
  [SMALL_STATE(107)] = 2214,
  [SMALL_STATE(108)] = 2224,
  [SMALL_STATE(109)] = 2232,
  [SMALL_STATE(110)] = 2240,
  [SMALL_STATE(111)] = 2248,
  [SMALL_STATE(112)] = 2258,
  [SMALL_STATE(113)] = 2266,
  [SMALL_STATE(114)] = 2274,
  [SMALL_STATE(115)] = 2281,
  [SMALL_STATE(116)] = 2288,
  [SMALL_STATE(117)] = 2293,
  [SMALL_STATE(118)] = 2298,
  [SMALL_STATE(119)] = 2303,
  [SMALL_STATE(120)] = 2310,
  [SMALL_STATE(121)] = 2317,
  [SMALL_STATE(122)] = 2324,
  [SMALL_STATE(123)] = 2328,
  [SMALL_STATE(124)] = 2332,
  [SMALL_STATE(125)] = 2336,
  [SMALL_STATE(126)] = 2340,
  [SMALL_STATE(127)] = 2344,
  [SMALL_STATE(128)] = 2348,
  [SMALL_STATE(129)] = 2352,
  [SMALL_STATE(130)] = 2356,
  [SMALL_STATE(131)] = 2360,
  [SMALL_STATE(132)] = 2364,
  [SMALL_STATE(133)] = 2368,
  [SMALL_STATE(134)] = 2372,
  [SMALL_STATE(135)] = 2376,
  [SMALL_STATE(136)] = 2380,
  [SMALL_STATE(137)] = 2384,
  [SMALL_STATE(138)] = 2388,
  [SMALL_STATE(139)] = 2392,
  [SMALL_STATE(140)] = 2396,
  [SMALL_STATE(141)] = 2400,
  [SMALL_STATE(142)] = 2404,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 2),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 3),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 2),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 3),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 3),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(65),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(64),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(109),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(103),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(102),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fragment_repeat1, 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 5),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 5),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 3),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 3),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_elseif, 4),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_elseif, 4),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if, 4),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if, 4),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_expression, 2),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_expression, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_variable, 1),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_variable, 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_parens, 3),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_parens, 3),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 2),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_associative, 3),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_associative, 3),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 4),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_else, 3),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(71),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(84),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(104),
  [137] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(96),
  [140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fragment_repeat1, 2), SHIFT_REPEAT(97),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cf_statement, 1),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cf_statement, 1),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fragment, 1),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_condition, 1),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_condition, 1),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 4),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 4),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 6),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 6),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_hash, 3),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_hash, 3),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 5),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 5),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 2),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 2),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 1),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 1),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_tag, 2),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_tag, 2),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text, 1),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_function, 7),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_function, 7),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_if_end, 3),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_if_end, 3),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_ifstatement, 3),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_ifstatement, 3),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_set, 3),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_cf_set, 3),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(130),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [258] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2), SHIFT_REPEAT(120),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_cf_ifstatement_repeat1, 2),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2),
  [281] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_cf_function_repeat1, 2), SHIFT_REPEAT(101),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [292] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cf_assignment, 1),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [340] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
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
