//! This crate provides CFML language support for the [tree-sitter][] parsing library.

use tree_sitter_language::LanguageFn;

extern "C" {
    fn tree_sitter_cfml() -> *const ();
    fn tree_sitter_cfhtml() -> *const ();
    fn tree_sitter_cfscript() -> *const ();
}

/// The tree-sitter [`LanguageFn`] for CFML.
///
/// [LanguageFn]: https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html
pub const LANGUAGE_CFML: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_cfml) };

/// The tree-sitter [`LanguageFn`] for CFHTML.
///
/// [LanguageFn]: https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html
pub const LANGUAGE_CFHTML: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_cfhtml) };

/// The tree-sitter [`LanguageFn`] for CFSCRIPT.
///
/// [LanguageFn]: https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html
pub const LANGUAGE_CFSCRIPT: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_cfscript) };

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const CFML_NODE_TYPES: &str = include_str!("../../cfml/src/node-types.json");
pub const CFHTML_NODE_TYPES: &str = include_str!("../../cfhtml/src/node-types.json");
pub const CFSCRIPT_NODE_TYPES: &str = include_str!("../../cfscript/src/node-types.json");

/// The syntax highlighting query for CFML.
pub const HIGHLIGHTS_QUERY: &str = include_str!("../../cfml/queries/highlights.scm");

/// The injection query for CFML.
pub const INJECTIONS_QUERY: &str = include_str!("../../cfml/queries/injections.scm");

/// The symbol tagging query for CFML.
pub const TAGS_QUERY: &str = include_str!("../../cfml/queries/tags.scm");

#[cfg(test)]
mod tests {
    #[test]
    fn test_can_load_cfml_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE_CFML.into())
            .expect("Error loading CFML parser");
    }

    #[test]
    fn test_can_load_cfhtml_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE_CFHTML.into())
            .expect("Error loading CFHTML parser");
    }

    #[test]
    fn test_can_load_cfscript_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE_CFSCRIPT.into())
            .expect("Error loading CFSCRIPT parser");
    }
}
