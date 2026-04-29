# tree-sitter-cfml

[![npm](https://img.shields.io/npm/v/@cfmleditor/tree-sitter-cfml)](https://www.npmjs.com/package/@cfmleditor/tree-sitter-cfml)
[![crates.io](https://img.shields.io/crates/v/tree-sitter-cfml)](https://crates.io/crates/tree-sitter-cfml)
[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png)](https://www.buymeacoffee.com/garetheddies)

[Tree-sitter](https://tree-sitter.github.io/) grammars for [ColdFusion Markup Language (CFML)](https://en.wikipedia.org/wiki/ColdFusion_Markup_Language).

There are four grammars: three for CFML in `.cfc`, `.cfm`, and `.cfs` files, and one for SQL inside `<cfquery>` (embedded dialect).

| Grammar    | Scope             | File types   | Description                                                                                                             |
| ---------- | ----------------- | ------------ | ----------------------------------------------------------------------------------------------------------------------- |
| `cfml`     | `source.cfml`     | `.cfc`       | ColdFusion components - CFScript inside a `component {}` block or tag-based component files                             |
| `cfhtml`   | `source.cfhtml`   | `.cfm`       | CFML template files - HTML with embedded CF tags and hash expressions                                                   |
| `cfscript` | `source.cfscript` | `.cfs`       | Pure CFScript files                                                                                                     |
| `cfquery`  | `source.cfquery`  | _(embedded)_ | SQL inside `<cfquery>` bodies (including QueryExecute-style usage), with `#hash#` interpolation and CF tags in the body |

## Playground

Browser demo: [cfmleditor.github.io/tree-sitter-cfml](https://cfmleditor.github.io/tree-sitter-cfml/)

## Installation

### Node.js

```bash
npm install @cfmleditor/tree-sitter-cfml
```

```js
const {
  cfml,
  cfhtml,
  cfscript,
  cfquery,
} = require("@cfmleditor/tree-sitter-cfml");
const Parser = require("tree-sitter");

const parser = new Parser();
parser.setLanguage(cfhtml.language);

const tree = parser.parse("<cfif condition>#value#</cfif>");
console.log(tree.rootNode.toString());
```

### Rust

```toml
[dependencies]
tree-sitter = "0.25"
tree-sitter-cfml = "0.26.7"
```

The `tree-sitter` crate should be **0.25+** so the ABI matches the generated parsers (see `LANGUAGE_VERSION` in `cf*/src/parser.c`).

```rust
use tree_sitter_cfml::LANGUAGE_CFML;

let mut parser = tree_sitter::Parser::new();
parser.set_language(&LANGUAGE_CFML.into())
    .expect("Error loading CFML grammar");
// LANGUAGE_CFHTML, LANGUAGE_CFSCRIPT, LANGUAGE_CFQUERY load the same way.
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

Each dialect has `grammar.js`, generated C under `src/`, corpus tests under `test/corpus/`, and queries under `queries/`. Shared scanner code is under `common/`. The multi-grammar CLI and playground config is [`tree-sitter.json`](tree-sitter.json). Upstream docs: [Creating parsers](https://tree-sitter.github.io/tree-sitter/creating-parsers), [CLI](https://tree-sitter.github.io/tree-sitter/cli/overview.html).

### Setup

```bash
git clone https://github.com/cfmleditor/tree-sitter-cfml.git
cd tree-sitter-cfml
```

Use Node **>=18** and **<24** (`package.json` `engines`). Optional: [`.nvmrc`](.nvmrc) with [nvm](https://github.com/nvm-sh/nvm) / [fnm](https://github.com/Schniz/fnm) (`nvm use`).

```bash
npm install
```

That installs dependencies, builds the Node native addon (`node-gyp-build`), and runs `postinstall`, which downloads the tree-sitter CLI binary into `node_modules/tree-sitter-cli/` when needed. Repo `npm` scripts do not require a global `tree-sitter` on `PATH`.

```bash
npm test          # all four grammars
npm run lint      # ESLint
npm run build     # regenerate parsers + rebuild native addon (after grammar edits)
```

#### Windows

Put **GCC** from **MinGW-w64** on your `PATH` (`gcc` / `g++`). This repo uses GCC for **`npm test`** (tree-sitter compile), the **Node** native binding, **Python** extension builds, and **Go** CGO — not MSVC.

**Standalone toolchain (recommended):** install [WinLibs](https://winlibs.com/) with winget, then add the extracted **`mingw64\bin`** directory (contains `gcc.exe`) to your user **PATH**, open a new terminal, and verify:

```powershell
gcc --version
```

Example package (UCRT, POSIX threads):

```powershell
winget install BrechtSanders.WinLibs.POSIX.UCRT
```

The installer path varies by machine; locate `mingw64\bin` under the WinLibs folder (or under `%LOCALAPPDATA%\Microsoft\WinGet\Packages\` after install) and add **that `bin`** to PATH.

**Alternatively:** [MSYS2](https://www.msys2.org/) with `pacman -S mingw-w64-x86_64-gcc`, then prepend **`msys64\mingw64\bin`** to PATH (or develop from an MSYS2 MinGW64 shell).

If **`node-gyp`** still picks Visual Studio instead of MinGW, set `CC` / `CXX` to your MinGW **`gcc`** / **`g++`** for `npm install` / `npm rebuild`, or keep MinGW’s `bin` **before** MSVC entries on `PATH`.

#### macOS

Install the Xcode command-line tools:

```bash
xcode-select --install
```

##### Homebrew

```bash
brew install gcc
```

#### Linux

Install a C/C++ toolchain (for example `build-essential` on Debian/Ubuntu, `gcc` / `clang` plus development headers on other distributions).

#### CI

CI ([`.github/workflows/ci.yml`](.github/workflows/ci.yml)): `npm install`, `npm test`, `npm run lint` on Ubuntu, macOS, and Windows. It does not run `npm run build`; generated `cf*/src/` files are committed.

#### Tree-sitter CLI

Scripts use [`scripts/tree-sitter-cli.cjs`](scripts/tree-sitter-cli.cjs) (`node node_modules/tree-sitter-cli/cli.js`). A global `tree-sitter-cli` install is optional. If the binary is missing after install:

```bash
node scripts/ensure-tree-sitter-cli-binary.js
```

**From a dialect directory** (after `npm install` at repo root):

```bash
cd cfml
node ../node_modules/tree-sitter-cli/cli.js test
node ../node_modules/tree-sitter-cli/cli.js generate
node ../node_modules/tree-sitter-cli/cli.js parse path/to/file.cfc
```

### Dependency versions

Pinned in `package.json` / `tree-sitter.json`; approximate roles:

| Role                        | Package           | Version      |
| --------------------------- | ----------------- | ------------ |
| Native binding (peer / dev) | `tree-sitter`     | `0.25.0`     |
| Parser CLI                  | `tree-sitter-cli` | `0.26.7`     |
| Native addon                | `node-addon-api`  | `^8.3.0`     |
| Native addon                | `node-gyp-build`  | `^4.8.4`     |
| Prebuild                    | `prebuildify`     | `^6.0.1`     |
| Runtime                     | Node.js           | `>=18` `<24` |

### CFML engines

Corpus and behavior are checked mainly against [Lucee](https://lucee.org/). Overlapping Adobe ColdFusion syntax should still parse in a reasonable way. Avoid Adobe-only or Lucee-only assumptions in examples or grammar design where portable CFML is enough.

### Building

After changing `common/define-grammar.js` or a `grammar.js`:

```bash
npm run build
```

On Unix, `make generate` at the repo root works if `tree-sitter` is on your `PATH`; otherwise use `npm run build`.

`tree-sitter generate` may warn about “unnecessary conflicts” (expressions vs `_property_name`, **cfscript** `declaration` / `primary_expression`, **cfquery** hash rules, etc.). Those come from `common/define-grammar.js`. If `npm run build` and `npm test` succeed, the warnings can be ignored.

### Testing and helpers

See **[Setup](#setup)** for `npm test`, `npm run lint`, and `npm run build`.

```bash
npm run testbindings  # Node binding smoke test
```

One grammar only: run `test` via the CLI from that dialect’s directory ([above](#setup)), or `npm test` for all four.

**Parse a file:** from the dialect folder (e.g. `cfml` for `.cfc`), use the `parse` subcommand with the same `node ../node_modules/.../cli.js` pattern.

**Playground / WebAssembly (WASM)**

- `npm start` — playground at repo root (`tree-sitter.json`). Run `npm run prestart` first if WASM is stale.
- `npm run prestart` — `tree-sitter build --wasm`
- `npm run playground` — playground in each of `cfml/`, `cfhtml/`, `cfscript/`, `cfquery/`
- `npm run docswasm` — writes `docs/tree-sitter-{cfml,cfhtml,cfscript,cfquery}.wasm` for `docs/` (e.g. GitHub Pages)

## Grammar structure

Shared rules: `common/define-grammar.js`. External scanner: `common/scanner.h` (implicit end tags, CF tag names, hash expressions, raw text).

```
common/
  define-grammar.js
  scanner.h
  tag.h

cfml/          # .cfc
  grammar.js
  src/         # generated
  queries/

cfhtml/        # .cfm
  grammar.js
  src/
  queries/

cfscript/      # .cfs
  grammar.js
  src/
  queries/

cfquery/       # embedded SQL
  grammar.js
  src/
  queries/
```

## Queries

| Grammar    | Highlights | Indents | Injections | Tags |
| ---------- | ---------- | ------- | ---------- | ---- |
| `cfml`     | yes        | yes     | yes        | yes  |
| `cfhtml`   | yes        | yes     | yes        | yes  |
| `cfscript` | yes        | no      | no         | yes  |
| `cfquery`  | yes        | no      | no         | yes  |

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md).

## Security

See [SECURITY.md](SECURITY.md).

## Agent and AI assistant guidance

See [`AGENTS.md`](AGENTS.md).

## License

[MIT](LICENSE)
