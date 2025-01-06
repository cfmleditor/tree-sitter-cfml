package tree_sitter_cfml

// #cgo CPPFLAGS: -I../../cfhtml/src
// #cgo CFLAGS: -std=c11 -fPIC
// #include "../../cfhtml/src/parser.c"
// #include "../../cfhtml/src/scanner.c"
import "C"

import "unsafe"

// Get the tree-sitter Language for this grammar.
func LanguageCfhtml() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_cfhtml())
}
