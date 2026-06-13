# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Commands

```bash
npm install        # install deps, build native addon, download tree-sitter CLI binary
npm run build      # regenerate parsers (tree-sitter generate) + rebuild native addon
npm test           # run corpus tests for all three grammars
npm run lint       # ESLint
npm run testbindings  # Node binding smoke test
```

Build a single grammar only:

```bash
DIALECT=cfml npm run build
```

Run tests / generate from inside a dialect directory:

```bash
cd cfml
node ../node_modules/tree-sitter-cli/cli.js test
node ../node_modules/tree-sitter-cli/cli.js generate
node ../node_modules/tree-sitter-cli/cli.js parse path/to/file.cfc
```

Playground (browser):

```bash
npm run prestart   # build WASM (only needed when parsers change)
npm start          # launch playground at repo root
```

Release:

```bash
npm run release -- 0.26.x   # bumps versions, builds, tests, commits, tags, pushes
```

## Architecture

Three grammars share a single scanner and grammar base:

| Directory  | Grammar   | File types       | Purpose                              |
|------------|-----------|------------------|--------------------------------------|
| `cfml/`    | `cfml`    | `.cfc`, `.cfm`   | Tags + embedded CFScript + HTML      |
| `cfscript/`| `cfscript`| `.cfs`           | Pure CFScript                        |
| `cfquery/` | `cfquery` | _(embedded)_     | SQL inside `<cfquery>` with `#hash#` |

Each dialect directory has:
- `grammar.js` — one-liner that calls `require('../common/define-grammar')('cfml'|'cfscript'|'cfquery')`
- `src/` — **generated** C files (`parser.c`, `scanner.c`); committed, not hand-edited
- `queries/` — `.scm` query files (highlights, indents, injections, tags, etc.)
- `test/corpus/` — plain-text corpus tests

### Shared code (`common/`)

- `define-grammar.js` — the full grammar definition, parameterised by `dialect`. All grammar rules live here; the per-dialect `grammar.js` files are thin wrappers.
- `scanner.h` — external C scanner (implicit end tags, CF tag name matching, `#hash#` expressions, raw text). Dialect-specific behaviour is `#ifdef`-gated on the `dialect` token.
- `tag.h` — CF tag name tables used by the scanner.

Changes to `define-grammar.js` or `scanner.h` affect all three grammars; always run `npm run build` and `npm test` after editing either.

### Bindings (`bindings/`)

Multi-language bindings (Node, Rust, Python, Go, Swift, C) are under `bindings/`. The `tree-sitter.json` at the repo root is the multi-grammar CLI config and declares which query files each grammar exposes.

### Query files

Beyond the standard `highlights.scm`, `indents.scm`, `injections.scm`, `tags.scm`, each grammar also ships Zed-specific variants (`brackets-zed.scm`, `indents-zed.scm`), `folds.scm`, `outline.scm`, `overrides.scm`, and `textobjects.scm`.

## Key constraints

- **Grammar conflicts:** `tree-sitter generate` may warn about "unnecessary conflicts" from `define-grammar.js`. Ignore them if `npm run build` and `npm test` succeed.
- **Generated files are committed** — `cf*/src/` must be up to date at release time; interim work does not need them regenerated.
- **CFML engine target:** Use [Lucee](https://lucee.org/) as the reference runtime. Avoid Adobe-only or Lucee-only constructs; prefer portable CFML.
- **Node version:** `>=18 <=24` (`.nvmrc` in repo root).
- **`tree-sitter` CLI:** Scripts use the locally installed binary (`node_modules/tree-sitter-cli/`); a global install is not required.
