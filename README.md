# tree-sitter-cfml

[![npm](https://img.shields.io/npm/v/@cfmleditor/tree-sitter-cfml)](https://www.npmjs.com/package/@cfmleditor/tree-sitter-cfml)
[![crates.io](https://img.shields.io/crates/v/tree-sitter-cfml)](https://crates.io/crates/tree-sitter-cfml)
[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png)](https://www.buymeacoffee.com/garetheddies)

[Tree-sitter](https://tree-sitter.github.io/) grammars for [ColdFusion Markup Language (CFML)](https://en.wikipedia.org/wiki/ColdFusion_Markup_Language).

Three grammars are provided to cover the different ways CFML is written, plus an embedded SQL dialect for `cfquery`:

| Grammar  | Scope          | File types | Description |
|----------|----------------|------------|-------------|
| `cfml`   | `source.cfml`  | `.cfc`     | ColdFusion components — CFScript inside a `component {}` block or tag-based component files |
| `cfhtml` | `source.cfhtml`| `.cfm`     | CFML template files — HTML with embedded CF tags and hash expressions |
| `cfscript` | `source.cfscript` | `.cfs` | Pure CFScript files |
| `cfquery`  | `source.cfquery`  | *(embedded)* | SQL dialect used inside `<cfquery>` bodies (and compatible with QueryExecute-style usage) with CF-style `#hash#` interpolation and CF tags in the body |

## Playground

Try the grammars in the browser: [cfmleditor.github.io/tree-sitter-cfml](https://cfmleditor.github.io/tree-sitter-cfml/)

## Installation

### Node.js

```bash
npm install @cfmleditor/tree-sitter-cfml
```

```js
const { cfml, cfhtml, cfscript, cfquery } = require('@cfmleditor/tree-sitter-cfml');
const Parser = require('tree-sitter');

const parser = new Parser();
parser.setLanguage(cfhtml.language);

const tree = parser.parse('<cfif condition>#value#</cfif>');
console.log(tree.rootNode.toString());
```

### Rust

Add to your `Cargo.toml`:

```toml
[dependencies]
tree-sitter = "0.25"
tree-sitter-cfml = "0.26"
```

```rust
use tree_sitter_cfml::{LANGUAGE_CFML, LANGUAGE_CFHTML, LANGUAGE_CFSCRIPT, LANGUAGE_CFQUERY};

// cfml for .cfc component files
let mut parser = tree_sitter::Parser::new();
parser.set_language(&LANGUAGE_CFML.into())
    .expect("Error loading CFML grammar");

// cfhtml for .cfm template files
parser.set_language(&LANGUAGE_CFHTML.into())
    .expect("Error loading CFHTML grammar");

// cfscript for .cfs pure script files
parser.set_language(&LANGUAGE_CFSCRIPT.into())
    .expect("Error loading CFSCRIPT grammar");
```

### Python

```bash
pip install tree-sitter-cfml
```

```python
import tree_sitter_cfml as ts_cfml
from tree_sitter import Language, Parser

# cfhtml for .cfm template files
parser = Parser(Language(ts_cfml.language_cfhtml()))
tree = parser.parse(b'<cfif x GT 0>#x#</cfif>')

# cfml for .cfc component files
parser = Parser(Language(ts_cfml.language_cfml()))

# cfscript for .cfs pure script files
parser = Parser(Language(ts_cfml.language_cfscript()))

# cfquery SQL dialect (embedded)
parser = Parser(Language(ts_cfml.language_cfquery()))
```

### Go

```go
import (
    tree_sitter_cfml "github.com/cfmleditor/tree-sitter-cfml/bindings/go"
    sitter "github.com/tree-sitter/go-tree-sitter"
)

// cfml for .cfc component files
parser := sitter.NewParser()
parser.SetLanguage(sitter.NewLanguage(tree_sitter_cfml.LanguageCfml()))

// cfhtml for .cfm template files
parser.SetLanguage(sitter.NewLanguage(tree_sitter_cfml.LanguageCfhtml()))

// cfscript for .cfs pure script files
parser.SetLanguage(sitter.NewLanguage(tree_sitter_cfml.LanguageCfscript()))

// cfquery SQL dialect (embedded)
parser.SetLanguage(sitter.NewLanguage(tree_sitter_cfml.LanguageCfquery()))
```

## Development

### Requirements

- [tree-sitter CLI](https://tree-sitter.github.io/tree-sitter/creating-parsers#installation) (`npm install -g tree-sitter-cli`)
- A C compiler

### Building

Each grammar is built independently from its subdirectory:

```bash
cd cfml && make
cd cfhtml && make
cd cfscript && make
```

Or build all three plus the Node.js bindings:

```bash
npm run build
```

**Note on build warnings**
When running `npm run build`, you may see tree-sitter warnings about “unnecessary conflicts” such as `binary_expression`, `call_expression`, `switch_case`, or `assignment_expression` versus `_property_name`, and hash-related conflicts for the cfquery dialect.
These conflicts are **intentionally declared** in `common/define-grammar.js` to resolve real ambiguities in CFML/CFHTML/cfquery syntax; attempts to remove them cause `tree-sitter generate` to fail with unresolved conflicts. It is safe to **ignore** these warnings as long as the build and tests succeed.

### Generating the parser

After editing `common/define-grammar.js`:

```bash
cd cfml && tree-sitter generate
cd cfhtml && tree-sitter generate
cd cfscript && tree-sitter generate
```

### Testing

```bash
# Test a single grammar
cd cfml && tree-sitter test

# Test all grammars
npm test
```

### Parsing a file

```bash
cd cfml && tree-sitter parse path/to/file.cfc
```

### Playground

```bash
npm run playground
```

## Grammar structure

All four grammars share a common base defined in `common/define-grammar.js`, with an external scanner in `common/scanner.h` that handles context-sensitive tokenisation (implicit end tags, CF tag names, hash expressions, raw text, etc.).

```
common/
  define-grammar.js   # shared grammar rules for all three dialects
  scanner.h           # external scanner (C)
  tag.h               # HTML/CF tag type definitions

cfml/                 # .cfc grammar
cfhtml/               # .cfm grammar
cfscript/             # .cfs grammar
cfquery/              # cfquery SQL dialect (embedded)
  grammar.js          # entry point (calls defineGrammar with dialect name)
  src/                # generated parser (do not edit)
  queries/
    highlights.scm    # syntax highlighting
    indents.scm       # indentation
    injections.scm    # language injections
    tags.scm          # symbol navigation
```

## Queries

Each grammar ships with query files for editor integration:

- `highlights.scm` — syntax highlighting captures
- `indents.scm` — indentation rules
- `injections.scm` — embedded language injections (e.g. SQL inside `<cfquery>`)
- `tags.scm` — function/method definitions and call references for go-to-definition and symbol search

## License

MIT
