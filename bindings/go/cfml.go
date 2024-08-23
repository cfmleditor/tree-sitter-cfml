package tree_sitter_cfml

// #cgo CPPFLAGS: -I../../cfml/src
// #cgo CFLAGS: -std=c11 -fPIC
// #include "../../cfml/src/parser.c"
// #include "../../cfml/src/scanner.c"
import "C"

import "unsafe"

// Get the tree-sitter Language for this grammar.
func LanguageCfml() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_cfml())
}
