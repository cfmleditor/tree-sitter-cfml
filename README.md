# tree-sitter-cfml

[![npm](https://img.shields.io/npm/v/@cfmleditor/tree-sitter-cfml)](https://www.npmjs.com/package/@cfmleditor/tree-sitter-cfml)
[![crates.io](https://img.shields.io/crates/v/tree-sitter-cfml)](https://crates.io/crates/tree-sitter-cfml)
[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png)](https://www.buymeacoffee.com/garetheddies)

[Tree-sitter](https://tree-sitter.github.io/) grammars for [ColdFusion Markup Language (CFML)](https://en.wikipedia.org/wiki/ColdFusion_Markup_Language).

Three grammars are provided to cover the different ways CFML is written, plus an embedded SQL dialect for `cfquery`:

| Grammar | Scope | File types | Description |
|---------|-------|------------|-------------|
| `cfml` | `source.cfml` | `.cfc` | ColdFusion components — CFScript inside a `component {}` block or tag-based component files |
| `cfhtml` | `source.cfhtml` | `.cfm` | CFML template files — HTML with embedded CF tags and hash expressions |
| `cfscript` | `source.cfscript` | `.cfs` | Pure CFScript files |
| `cfquery` | `source.cfquery` | *(embedded)* | SQL dialect used inside `<cfquery>` bodies and `QueryExecute(...)` calls (joins, unions, parameters, CF-style `#hash#` interpolation) |

## Playground

Try the grammars in the browser: [cfmleditor.github.io/tree-sitter-cfml](https://cfmleditor.github.io/tree-sitter-cfml/)

## Installation

### Node.js

```bash
npm install @cfmleditor/tree-sitter-cfml
```

```js
const { cfml, cfhtml, cfscript } = require('@cfmleditor/tree-sitter-cfml');
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
use tree_sitter_cfml::{LANGUAGE_CFML, LANGUAGE_CFHTML, LANGUAGE_CFSCRIPT};

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
cd cfquery && make   # cfquery SQL dialect
```

Or build all grammars plus the Node.js bindings:

```bash
npm run build
```

### Generating the parser

After editing `common/define-grammar.js` or any of the `grammar.js` entry points:

```bash
cd cfml && tree-sitter generate
cd cfhtml && tree-sitter generate
cd cfscript && tree-sitter generate
cd cfquery && tree-sitter generate
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

All CFML grammars share a common base defined in `common/define-grammar.js`, with an external scanner in `common/scanner.h` that handles context-sensitive tokenisation (implicit end tags, CF tag names, hash expressions, raw text, etc.).

```
common/
  define-grammar.js   # shared grammar rules for all dialects (cfml, cfhtml, cfscript, cfquery)
  scanner.h           # external scanner (C)
  tag.h               # HTML/CF tag type definitions

cfml/                 # .cfc grammar
cfhtml/               # .cfm grammar
cfscript/             # .cfs grammar
  grammar.js          # entry point (calls defineGrammar with dialect name)
  src/                # generated parser (do not edit)
  queries/
    highlights.scm    # syntax highlighting
    indents.scm       # indentation
    injections.scm    # language injections
    tags.scm          # symbol navigation

cfquery/              # SQL dialect used inside cfquery / QueryExecute
  grammar.js          # SQL grammar with CF-style parameters and #hash# interpolation
  src/                # generated parser (do not edit)
  queries/
    highlights.scm    # SQL + CF parameter highlighting
    tags.scm          # table/column aliases, CF variables in hashes
```

## Queries

Each grammar (including the `cfquery` SQL dialect) ships with query files for editor integration:

- `highlights.scm` — syntax highlighting captures
- `indents.scm` — indentation rules (where applicable)
- `injections.scm` — embedded language injections (e.g. `cfquery` SQL inside `<cfquery>` / `QueryExecute(...)`)
- `tags.scm` — function/method definitions, call references, and query-related symbols (e.g. table/column aliases, CF variables used in SQL)

## cfquery SQL dialect

The `cfquery` grammar (`source.cfquery`) is a SQL dialect tailored for CFML:

- **Where it is used**:
  - `<cfquery>` tag bodies in CFML/CFHTML templates.
  - The first string argument to `QueryExecute(...)` in CFML/CFScript.
  - Conceptually reused for Query-of-Queries (`dbtype="query"`) and HQL/ORM queries (`dbtype="hql"`), which are distinguished in `metadata/vendor_support.json` via the `cfqoq-sql` and `cfhql-sql` dialect entries.

- **Major SQL constructs recognised** (fault-tolerant, not a full SQL engine):
  - Statements: `SELECT`, `INSERT INTO ... VALUES (...)`, `UPDATE ... SET ...`, `DELETE [FROM ...]`.
  - Clauses: `FROM`, `WHERE`, `GROUP BY`, `HAVING`, `ORDER BY`, `LIMIT [OFFSET ...]`, `TOP`.
  - Joins: `INNER|LEFT|RIGHT|FULL [OUTER] JOIN ... ON ...`.
  - Set ops: `UNION [ALL]`.
  - Expressions: `CASE ... WHEN ... THEN ... ELSE ... END`, `EXISTS (subquery)`, `IN (...)` / `IN (subquery)`, `BETWEEN ... AND ...`, comparison and arithmetic operators, `LIKE` / `ILIKE`.

- **CF-style parameters and hashes**:
  - Positional and named SQL parameters: `?` and `:name` appear as `parameter` nodes.
  - CF hash parameters: `#scope.var#`, `#ARGUMENTS.userIds[1]#`, etc. appear as `hash_param` containing a `cf_identifier_path` that encodes scope and member access.
  - In tag-based CFML, `<cfqueryparam>` tags inside `<cfquery>` bodies are parsed by the CFML grammar and can be used alongside `?` / `:name` / `#hash#` parameters.

This structure is intended to give downstream tools (linters, refactorings, security scanners) a stable, vendor-neutral view of CFML SQL while remaining friendly to common PostgreSQL/MySQL/SQL Server constructs.

## License

MIT
