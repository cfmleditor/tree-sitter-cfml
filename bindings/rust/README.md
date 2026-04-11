# tree-sitter-cfml (Rust)

Rust bindings for the [tree-sitter](https://tree-sitter.github.io/) CFML grammars: **cfml**, **cfhtml**, **cfscript**, and **cfquery**.

## Dependencies

Add this crate and [`tree-sitter`](https://crates.io/crates/tree-sitter) to your project:

```toml
[dependencies]
tree-sitter = "0.24"
tree-sitter-cfml = "0.26"
```

The grammar exposes [`LanguageFn`](https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html) values from [`tree-sitter-language`](https://crates.io/crates/tree-sitter-language) (this crate's dependency).

## Example

```rust
use tree_sitter_cfml::{LANGUAGE_CFHTML, LANGUAGE_CFML};

let mut parser = tree_sitter::Parser::new();
parser.set_language(&LANGUAGE_CFHTML.into()).expect("load CFHTML");
let tree = parser.parse(b"<cfif x>#x#</cfif>", None).expect("parse");
```

Use `LANGUAGE_CFML` for `.cfc`, `LANGUAGE_CFSCRIPT` for `.cfs`, and `LANGUAGE_CFQUERY` for embedded SQL in `<cfquery>`.

## More documentation

- Repository root [`README.md`](../../README.md): installation, Node/Python/Go bindings, development, and playground.
