# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Commands

```bash
npm install        # install deps, build native addon, download tree-sitter CLI binary
npm run build      # regenerate parsers (tree-sitter generate) + rebuild native addon
npm test           # run corpus tests for all three grammars
npm run probe      # parse test/probes/* and fail on any drift from expected.json
npm run fuzz       # tree-sitter's own fuzzer over the corpus tests
npm run lint       # ESLint
npm run lint:fix   # ESLint with auto-fix
npm run testbindings  # Node binding smoke test
npm run build:native  # build/native/: the three grammars + the tree-sitter runtime, as shared libraries
mvn test              # Java binding smoke test (needs JDK 23+ and build:native first)
```

Build or test a single grammar only:

```bash
DIALECT=cfml npm run build
DIALECT=cfml npm test
```

`DIALECT=… npm run build` runs `tree-sitter generate` **without** rebuilding the
native addon, so anything that goes through the Node bindings — `npm run probe`,
`npm run scan`, `npm run testbindings` — keeps using the previous parser. Run a
full `npm run build` before trusting those.

Run tests / generate from inside a dialect directory:

```bash
cd cfml
node ../node_modules/tree-sitter-cli/cli.js test
node ../node_modules/tree-sitter-cli/cli.js test -i "cfif"   # regex over test names (not --filter)
node ../node_modules/tree-sitter-cli/cli.js generate
node ../node_modules/tree-sitter-cli/cli.js parse path/to/file.cfc
```

Scan real-world CFML for parse errors, and cluster what comes back:

```bash
npm run corpus:fetch                    # clone 47 public CFML repos into ~/corpus, or ./corpus (gitignored)
npm run scan corpus > scan.txt          # or any directory of .cfm/.cfc/.cfs files
npm run corpus:report -- --from scan.txt  # group failures by source-line shape
```

Check a grammar or scanner change for a throughput regression:

```bash
npm run bench -- corpus --out before.json   # on the base commit
npm run bench -- corpus --baseline before.json   # after the change
```

Do not time `npm run scan` for this. It walks every tree collecting ERROR nodes
and locates injections *by parsing*, so both costs move with the error count —
a change that fixes parse errors will look wildly faster or slower for reasons
unrelated to parser speed. `bench.js` selects its input by regex, reads it up
front, and times only `parser.parse()`.

Playground (browser):

```bash
npm start                      # build the cfml WASM, then serve the playground
DIALECT=cfscript npm start     # or one of the other two
```

One dialect at a time — `tree-sitter playground` serves and blocks, and it must
run from the dialect's own directory: from the repo root the CLI cannot find a
`grammar.js` and panics with "Failed to get Wasm filename". `prestart` builds
the WASM beside that grammar, which is a *different* output from
`npm run docswasm`, which writes to `docs/` for the published static page.

Release (requires a `## [version]` or `## [Unreleased]` entry in `CHANGELOG.md`):

```bash
npm run release -- 0.26.x   # bumps versions, builds, tests, commits, tags, pushes
```

## Architecture

Three grammars, but **not** three of a kind — `cfml` and `cfquery` share a
grammar definition and a scanner; `cfscript` has its own of each. Knowing which
you are editing is the difference between a one-line change and a change that
lands in two grammars at once:

| Directory  | Grammar   | File types       | Grammar rules              | External scanner        |
|------------|-----------|------------------|----------------------------|-------------------------|
| `cfml/`    | `cfml`    | `.cfc`, `.cfm`   | `common/define-grammar.js` | `common/scanner.h`      |
| `cfquery/` | `cfquery` | _(embedded)_     | `common/define-grammar.js` | `common/scanner.h`      |
| `cfscript/`| `cfscript`| `.cfs`           | `cfscript/grammar.js`      | `cfscript/src/scanner.c` |

`cfml` covers tags plus embedded CFScript and HTML; `cfquery` covers SQL inside
`<cfquery>` with `#hash#` interpolation; `cfscript` is pure CFScript.

A construct that exists in both CFScript-in-a-tag and standalone `.cfs` has to
be added **twice** — once in `common/define-grammar.js`, once in
`cfscript/grammar.js`. They have drifted; do not assume a rule present in one is
present in the other.

Each dialect directory has:
- `grammar.js` — for `cfml`/`cfquery`, a one-liner calling `require('../common/define-grammar')(dialect)`; for `cfscript`, the whole grammar
- `src/parser.c`, `src/grammar.json`, `src/node-types.json` — **generated** by `tree-sitter generate`; committed, never hand-edited
- `src/scanner.c` — **hand-written**. For `cfml`/`cfquery` it is a thin wrapper that `#include`s `common/scanner.h`; for `cfscript` it is the real 500-line scanner
- `queries/` — `.scm` query files (highlights, indents, injections, tags, etc.)
- `test/corpus/` — plain-text corpus tests: `===title===` / CFML input / `---` / expected S-expression

### Shared code (`common/`)

- `define-grammar.js` — the `cfml` + `cfquery` grammar, parameterised by `dialect`. Rules unique to one appear inside `dialect === 'cfquery' ? … : …` branches.
- `scanner.h` — the `cfml` + `cfquery` external scanner (implicit end tags, CF tag name matching, `#hash#` expressions, raw text). Dialect-specific behaviour is `#ifdef`-gated.
- `tag.h` — CF tag name tables used by the scanner (void tags, raw-text tags).

Editing either file changes two grammars at once, so run a full `npm run build`
and `npm test` afterwards, never a single-dialect build.

### Tests, probes and the corpus

Three layers, each catching what the one above misses:

- `cf*/test/corpus/` — the committed expectations. `npm test` runs them.
- `test/probes/` — minimal reductions of constructs found in real code, with their current pass/fail status in `test/probes/expected.json`. `npm run probe` fails on drift **in either direction**, so a gap closing is as visible as a regression.
- the real-world corpus (`npm run corpus:fetch`) — 15,083 files from public CFML projects, kept in `~/corpus` when that exists. Not in CI; run it by hand before and after a grammar change and diff the two scans. Three changes in the last round looked self-contained, passed the test suite, and were only caught here.

### Bindings (`bindings/`)

Multi-language bindings (Node, Rust, Python, Go, Swift, C, Java) are under `bindings/`. The `tree-sitter.json` at the repo root is the multi-grammar CLI config and declares which query files each grammar exposes.

The Java binding is the odd one out: every other binding compiles `cf*/src/parser.c` as part of its own build, so a grammar change reaches it automatically. Java resolves `tree_sitter_*` out of shared libraries at runtime instead, so it only sees a change once those are rebuilt (`npm run build:native`, or `make`). Its version lives in `pom.xml` — a fifth place `scripts/release.js` has to bump.

### Query files

Beyond the standard `highlights.scm`, `indents.scm`, `injections.scm`, `tags.scm`, each grammar also ships Zed-specific variants (`brackets-zed.scm`, `indents-zed.scm`), `folds.scm`, `outline.scm`, `overrides.scm`, and `textobjects.scm`.

## Key constraints

- **Grammar conflicts:** `tree-sitter generate` warns about "unnecessary conflicts" when a declared conflict is no longer reachable. Prune them rather than living with them — a stale declaration hides a real ambiguity behind a warning nobody reads. Removing one is safe exactly when `npm run build`, `npm test` and `npm run probe` all stay green.
- **A declared conflict has a runtime cost proportional to how common its prefix is.** Two GLR stacks are carried until something disambiguates, so a conflict on `identifier` followed by `(` or `.` is live across the whole language — one such conflict cost 2.8× on cfscript before it was narrowed to statement position. `npm test`, `npm run probe` and the corpus scan cannot see this. Run `npm run bench` (baseline first) on any change that adds a conflict.
- **Keyword extraction is lexical.** With `word: $.identifier`, making a keyword token valid in a new position changes how that word *lexes* in that state — including in rules you did not touch. This is the single most common way a change here breaks something unrelated. See the skill below before editing declarations, parameters or statement heads.
- **Generated files are committed** — `cf*/src/` must be up to date at release time; interim work does not need them regenerated.
- **CFML engine target:** Use [Lucee](https://lucee.org/) as the reference runtime. Avoid Adobe-only or Lucee-only constructs; prefer portable CFML.
- **Node version:** `>=18 <=24` (`.nvmrc` in repo root).
- **`tree-sitter` CLI:** Scripts use the locally installed binary (`node_modules/tree-sitter-cli/`); a global install is not required.
- **Known parser limitations** are documented in [`LIMITATIONS.md`](LIMITATIONS.md) — check there before investigating a surprising parse result. [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md) has the longer version: every construct in the real-world corpus that still fails, how many files it affects, and an estimate of what fixing it would cost, calibrated against changes that have actually landed here.
- **Open non-parser work** lives in [`docs/TODO.md`](docs/TODO.md), including a section on what was considered and deliberately left undone, so those decisions do not get re-argued.

## Skills

`.claude/skills/parse-gap/` covers the workflow for making a CFML construct
parse that currently does not: reproducing it, deciding which grammar and
scanner own it, the hazards specific to this repo, and the verification gate to
run before committing. Its `references/scanner.md` also covers diagnosing a
parser that hangs or crashes. Reach for it whenever the task is "this CFML
doesn't parse" or "the parser hangs on X".
