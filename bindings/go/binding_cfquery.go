package tree_sitter_cfml

// #cgo CPPFLAGS: -I../../cfquery/src
// #cgo CFLAGS: -std=c11 -fPIC
// #include "../../cfquery/src/parser.c"
// #include "../../cfquery/src/scanner.c"
import "C"

import "unsafe"

// Get the tree-sitter Language for this grammar.
func LanguageCfquery() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_cfquery())
}
