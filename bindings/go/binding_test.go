package tree_sitter_cfml_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_cfml "github.com/tree-sitter/tree-sitter-cfml/bindings/go"
)

func TestCanLoadCfmlGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCfml())
	if language == nil {
		t.Errorf("Error loading CFML grammar")
	}
}

func TestCanLoadCfhtmlGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCfhtml())
	if language == nil {
		t.Errorf("Error loading CFHTML grammar")
	}
}

func TestCanLoadCfscriptGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCfscript())
	if language == nil {
		t.Errorf("Error loading CFSCRIPT grammar")
	}
}
