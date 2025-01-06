from unittest import TestCase

import tree_sitter, tree_sitter_cfml


class TestLanguage(TestCase):
    def test_can_load_cfml_grammar(self):
        try:
            tree_sitter.Language(tree_sitter_cfml.language_cfml())
        except Exception:
            self.fail("Error loading CFML grammar")

    def test_can_load_cfhtml_grammar(self):
        try:
            tree_sitter.Language(tree_sitter_cfml.language_cfhtml())
        except Exception:
            self.fail("Error loading CFHTML grammar")

    def test_can_load_cfscript_grammar(self):
        try:
            tree_sitter.Language(tree_sitter_cfml.language_cfscript())
        except Exception:
            self.fail("Error loading CFSCRIPT grammar")
