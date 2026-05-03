package tree_sitter_cfml

// #cgo CPPFLAGS: -I../../cfscript/src
// #cgo CFLAGS: -std=c11 -fPIC
// #include "../../cfscript/src/parser.c"
// #include "../../cfscript/src/scanner.c"
import "C"

import "unsafe"

// Get the tree-sitter Language for this grammar.
func LanguageCfscript() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_cfscript())
}
