//! This crate provides TypeScript and TSX language support for the [tree-sitter][] parsing library.
//!
//! Typically, you will use the [language][language func] function to add this language to a
//! tree-sitter [Parser][], and then use the parser to parse some code:
//!
//! ```
//! use tree_sitter::Parser;
//!
//! let code = r#"
//! function double(x: number): number {
//!     return x * 2;
//! }
//! "#;
//! let mut parser = Parser::new();
//! parser
//!     .set_language(&tree_sitter_typescript::language_typescript())
//!     .expect("Error loading TypeScript grammar");
//! let tree = parser.parse(code, None).unwrap();
//! assert!(!tree.root_node().has_error());
//! ```
//!
//! [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
//! [language func]: fn.language.html
//! [Parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter::Language;

extern "C" {
    fn tree_sitter_cfml() -> Language;
    fn tree_sitter_cfhtml() -> Language;
    fn tree_sitter_cfscript() -> Language;
}

/// Get the tree-sitter [Language][] for Cfml.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language_cfml() -> Language {
    unsafe { tree_sitter_cfml() }
}

/// Get the tree-sitter [Language][] for Cfhtml.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language_cfhtml() -> Language {
    unsafe { tree_sitter_cfhtml() }
}

/// Get the tree-sitter [Language][] for Cfscript.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language_cfscript() -> Language {
    unsafe { tree_sitter_cfscript() }
}

/// The content of the [`node-types.json`][] file for Cfml.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const CFML_NODE_TYPES: &str = include_str!("../../cfml/src/node-types.json");

/// The content of the [`node-types.json`][] file for Cfhtml.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const CFHTML_NODE_TYPES: &str = include_str!("../../cfhtml/src/node-types.json");

/// The content of the [`node-types.json`][] file for Cfscript.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const CFSCRIPT_NODE_TYPES: &str = include_str!("../../cfscript/src/node-types.json");

/// The syntax highlighting query for Cfml.
pub const HIGHLIGHTS_QUERY: &str = include_str!("../../cfml/queries/highlights.scm");

/// The local-variable syntax highlighting query for Cfml.
// pub const LOCALS_QUERY: &str = include_str!("../../cfml/queries/locals.scm");

/// The symbol tagging query for Cfml.
pub const TAGS_QUERY: &str = include_str!("../../cfml/queries/tags.scm");

#[cfg(test)]
mod tests {
    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::language_cfml())
            .expect("Error loading Cfml grammar");
    }
}