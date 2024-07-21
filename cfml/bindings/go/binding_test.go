package tree_sitter_cfml_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-cfml"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.Language())
	if language == nil {
		t.Errorf("Error loading Cfml grammar")
	}
}
