package tree_sitter_cfml_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-cfml"
)

func TestCanLoadCfmlkGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfml.LanguageCfml())
	if language == nil {
		t.Errorf("Error loading Cfml grammar")
	}
}

func TestCanLoadCfhtmlGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfhtml.LanguageCfhtml())
	if language == nil {
		t.Errorf("Error loading Cfhtml grammar")
	}
}

func TestCanLoadCfscriptGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cfscript.LanguageCfscript())
	if language == nil {
		t.Errorf("Error loading Cfscript grammar")
	}
}
