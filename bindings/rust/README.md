# tree-sitter-cfml (Rust)

Rust bindings for the [tree-sitter](https://tree-sitter.github.io/) grammars **cfml**, **cfhtml**, **cfscript**, and **cfquery**.

## Dependencies

```toml
[dependencies]
tree-sitter = "0.25"
tree-sitter-cfml = "0.26.6"
```

The crate exposes [`LanguageFn`](https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html) values via [`tree-sitter-language`](https://crates.io/crates/tree-sitter-language).

## Example

```rust
use tree_sitter_cfml::{LANGUAGE_CFHTML, LANGUAGE_CFML};

let mut parser = tree_sitter::Parser::new();
parser.set_language(&LANGUAGE_CFHTML.into()).expect("load language");
let tree = parser.parse(b"<cfif x>#x#</cfif>", None).expect("parse");
```

Use `LANGUAGE_CFML` for `.cfc`, `LANGUAGE_CFSCRIPT` for `.cfs`, `LANGUAGE_CFQUERY` for SQL inside `<cfquery>`.

## More documentation

Repository root [`README.md`](../../README.md): Node, Python, Go, development, playground.
