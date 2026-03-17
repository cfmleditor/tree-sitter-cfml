#include "tree_sitter/parser.h"
#include <stdbool.h>
#include <stdint.h>

// The cfquery dialect reuses the common CFML grammar but does not currently
// rely on any external tokens. We provide a stub external scanner that never
// produces any tokens, in order to satisfy the symbols that the generated
// parser expects.

void *tree_sitter_cfquery_external_scanner_create(void) {
  return NULL;
}

void tree_sitter_cfquery_external_scanner_destroy(void *payload) {
  (void)payload;
}

unsigned tree_sitter_cfquery_external_scanner_serialize(void *payload, char *buffer) {
  (void)payload;
  (void)buffer;
  return 0;
}

void tree_sitter_cfquery_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  (void)payload;
  (void)buffer;
  (void)length;
}

bool tree_sitter_cfquery_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  (void)payload;
  (void)lexer;
  (void)valid_symbols;
  return false;
}

