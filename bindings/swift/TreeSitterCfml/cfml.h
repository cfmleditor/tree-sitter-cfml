#ifndef TREE_SITTER_CFML_H_
#define TREE_SITTER_CFML_H_

typedef struct TSLanguage TSLanguage;

#ifdef __cplusplus
extern "C" {
#endif

const TSLanguage *tree_sitter_cfml();
const TSLanguage *tree_sitter_cfhtml();
const TSLanguage *tree_sitter_cfscript();

#ifdef __cplusplus
}
#endif

#endif // TREE_SITTER_CFML_H_
