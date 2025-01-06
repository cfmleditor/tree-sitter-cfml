package tree_sitter_cfml_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_cfml "github.com/tree-sitter/tree-sitter-cfml/bindings/go"
)

func TestCanLoadCFMLGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCFML())
	if language == nil {
		t.Errorf("Error loading CFML grammar")
	}
}

func TestCanLoadCFHTMLGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCFHTML())
	if language == nil {
		t.Errorf("Error loading CFHTML grammar")
	}
}

func TestCanLoadCfscriptGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCFSCRIPT())
	if language == nil {
		t.Errorf("Error loading CFSCRIPT grammar")
	}
}
