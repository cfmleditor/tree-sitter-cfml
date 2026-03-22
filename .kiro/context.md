# tree-sitter-cfml ΓÇö project context

[Tree-sitter](https://tree-sitter.github.io/) grammars for [ColdFusion Markup Language (CFML)](https://en.wikipedia.org/wiki/ColdFusion_Markup_Language).

The repo ships **four** grammars: three for how CFML is written in files, plus an embedded SQL dialect for `<cfquery>` bodies.

| Grammar    | Scope               | File types   | Description |
|------------|---------------------|--------------|-------------|
| `cfml`     | `source.cfml`       | `.cfc`       | Components ΓÇö CFScript in `component {}` or tag-based components |
| `cfhtml`   | `source.cfhtml`     | `.cfm`       | Templates ΓÇö HTML with CF tags and hash expressions |
| `cfscript` | `source.cfscript`   | `.cfs`       | Pure CFScript |
| `cfquery`  | `source.cfquery`    | *(embedded)* | SQL inside `<cfquery>` (and similar), with `#hash#` and CF tags in the body |

Public browser playground: [cfmleditor.github.io/tree-sitter-cfml](https://cfmleditor.github.io/tree-sitter-cfml/)

---

## Development

### Requirements

- [tree-sitter CLI](https://tree-sitter.github.io/tree-sitter/creating-parsers#installation) ΓÇö the `tree-sitter-cli` npm package installs a native binary via `install.js` (e.g. `tree-sitter.exe` on Windows). If `npm run build` cannot find it, run `node scripts/ensure-tree-sitter-cli-binary.js` once or reinstall. Repo scripts run the CLI through `node node_modules/tree-sitter-cli/cli.js`, so a global `tree-sitter` install is optional.
- A C compiler (for native bindings / `node-gyp`).

### Dependency versions (tree-sitter ecosystem)

Versions align with the published [`tree-sitter`](https://www.npmjs.com/package/tree-sitter) npm package and the **0.26.x** CLI used to generate parsers. Dependencies are taken from npm as published (no vendored patches to `tree-sitter` or the CLI).

| Role | Package | Version |
|------|---------|---------|
| Native binding (peer / dev) | `tree-sitter` | `0.25.0` (`^0.25.0` peer) |
| Parser generation CLI | `tree-sitter-cli` | `0.26.7` (see `tree-sitter.json`) |
| Native addon | `node-addon-api` | `^8.3.0` |
| Native addon | `node-gyp-build` | `^4.8.4` |
| Prebuild tooling | `prebuildify` | `^6.0.1` |
| Runtime | Node.js | `>=18` and `<24` (`package.json` `engines`). Prefer **Node 22 LTS** (`.nvmrc`) ΓÇö `tree-sitter@0.25.0` native addon uses C++17; Node 24+ can mismatch headers until upstream supports it. |

### Vendor alignment

- **Engines:** Tests target **Lucee** as the primary reference; valid **Adobe ColdFusion** syntax that overlaps the shared language should still parse sensibly (generic tags or text rather than hard failures for well-formed markup).
- **Tags:** Void or self-closing tags (e.g. `cfqueryparam`) follow engine docs; CFML attribute names are case-insensitive.

### Building

From the repository root, generate all four parsers and refresh generated sources:

```bash
npm run build
```

On Unix, `make generate` runs `tree-sitter generate` in `cfml`, `cfhtml`, `cfscript`, and `cfquery`. Individual directories with a `Makefile` (`cfml`, `cfhtml`, `cfscript`) also support `make` targets there.

**Build warnings:** `tree-sitter generate` may report ΓÇ£unnecessary conflictsΓÇ¥ (e.g. expressions vs `_property_name`, hash rules in cfquery). Those conflicts are **declared on purpose** in `common/define-grammar.js`; removing them often breaks generation. Safe to ignore if the build and `npm test` succeed.

### Generating after grammar edits

After changing `common/define-grammar.js` or a dialect `grammar.js`:

```bash
cd cfml && tree-sitter generate
cd cfhtml && tree-sitter generate
cd cfscript && tree-sitter generate
cd cfquery && tree-sitter generate
```

Or use `npm run build` or `make generate`.

### Testing

```bash
cd cfml && tree-sitter test    # one grammar
npm test                       # all grammars (cfml, cfhtml, cfscript, cfquery)
npm run testbindings           # Node binding tests
```

### Parse a file (CLI)

```bash
cd cfml && tree-sitter parse path/to/file.cfc
```

### npm scripts (reference)

| Script | What it does |
|--------|----------------|
| `npm run build` | `scripts/build.js` ΓÇö generate all grammars |
| `npm run test` | Corpus tests for all grammars |
| `npm run parse` | CLI parse helper (`scripts/parse.js`) |
| `npm run docswasm` | Emit `docs/tree-sitter-{cfml,cfhtml,cfscript,cfquery}.wasm` for static `docs/` |
| `npm run prestart` | `tree-sitter build --wasm` at repo root |
| `npm start` | `tree-sitter playground` at repo root (`tree-sitter.json`) |
| `npm run playground` | `tree-sitter playground` in each of `cfml/`, `cfhtml/`, `cfscript/`, `cfquery/` |
| `postinstall` | `scripts/ensure-tree-sitter-cli-binary.js` |

Static site: after `docswasm`, open `docs/index.html` or serve `docs/` over HTTP (e.g. GitHub Pages).

---

## Repository layout

```
common/
  define-grammar.js   # shared rules for all dialects
  scanner.h           # external scanner (C)
  tag.h               # HTML/CF tag definitions

cfml/                 # .cfc
cfhtml/               # .cfm
cfscript/             # .cfs
cfquery/              # embedded SQL dialect
  grammar.js          # entry (defineGrammar + dialect)
  src/                # generated parser (do not hand-edit)
  queries/
    highlights.scm
    indents.scm
    injections.scm
    tags.scm

scripts/              # build, test, parse, CLI helpers, playground
bindings/             # Node, Python, Rust, Go, Swift, etc.
docs/                 # HTML playground + WASM artifacts (from docswasm)
metadata/
```

---

## Queries (per grammar)

- `highlights.scm` ΓÇö highlighting captures  
- `indents.scm` ΓÇö indentation  
- `injections.scm` ΓÇö embedded languages (e.g. SQL in `<cfquery>`)  
- `tags.scm` ΓÇö symbols / navigation  

---

## License

MIT
