# Changelog

## [Unreleased]

### Bindings

- Add a Java binding (`bindings/java/`, `pom.xml`): `TreeSitterCfml`, `TreeSitterCfscript` and `TreeSitterCfquery` under `io.github.cfmleditor.jtreesitter.*`, built on [jtreesitter](https://github.com/tree-sitter/java-tree-sitter) and the Foreign Function & Memory API. Needs JDK 23+. Unlike the other bindings it does not compile the C: it resolves `tree_sitter_*` out of shared libraries at runtime
- Add `npm run build:native`, which builds the three grammars *and* the tree-sitter runtime (from the copy vendored by the `tree-sitter` npm package, so the version is pinned by `package-lock.json`) into `build/native/` — the libraries the Java binding loads
- Fix `make -C cfscript` and `make -C cfquery` building a library named `libtree-sitter-cfml`: `common/common.mak` reassigned `LANGUAGE_NAME` after the including Makefile had set it, so both dialects produced a `libtree-sitter-cfml.{a,so}` and a `tree-sitter-cfml.pc` holding the wrong parser. The last dialect to be installed won
- Fix `make install` failing to find the C header: it looked for `bindings/c/…` relative to the dialect directory rather than the repository root. Add the missing `tree_sitter/tree-sitter-cfquery.h`, and move `tree-sitter-cfscript.h` alongside the other two in `bindings/c/tree_sitter/`
- Fix the hardcoded `VERSION` in `common/common.mak`, stale at 0.26.17, which was written into every generated `.pc` file. It now comes from `tree-sitter.json`, and `.pc` descriptions are no longer empty for cfscript and cfquery

### Corpus

- Add `RustCFML/RustCFML` to the corpus repository list — a CFML interpreter written in Rust whose `tests/` tree is 1,188 files of deliberately edge-case CFML. It scans at 40 error nodes across 15 files (98.7% of files clean) and turned up eight constructs no earlier scan had shown, recorded in [`CORPUS.md`](CORPUS.md), [`LIMITATIONS.md`](LIMITATIONS.md) and [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md) with a probe each. No grammar changes — five of the eight already parse in the embedded CFScript of `common/define-grammar.js` and fail only in the standalone `cfscript/grammar.js`, which `injections.scm` is what makes user-visible

### Tooling

- Ignore `corpus/**` in `eslint.config.mjs`. The directory is gitignored but was still linted, so `npm run lint` reported errors in third-party JavaScript pulled in by `npm run corpus:fetch` — 53 of them from one repository in the list
- Fix the file count in `npm run scan`: a file whose only parse errors came from an injected `<cfscript>` or `<cfquery>` region had them printed but was never counted, so the summary under-reported affected files (62 against a true 161 on the reference corpus). Node counts were unaffected

### cfml & cfscript

- Support array return types on function declarations (`User[] function getUsers()`)
- Support the `new java:` / `new cfml:` type prefix in the shared grammar as well as `cfscript`, so `<cfset x = new java:java.io.File(p)>` parses
- Allow `debugger` as an ordinary identifier (`debugger.log( … )`, `debugger = 1`), which previously failed at statement start because the keyword out-lexed the identifier. The bare `debugger;` statement still parses as `debugger_statement`
- Support the thin-arrow lambda (`t -> t.b()`, `( x, y ) -> x + y`) alongside the existing `=>` closure. Both produce an `arrow_function`; `->` is added to the operator list in each `highlights.scm`

### cfscript

- Support script-syntax tag calls with space-separated attributes (`cfdirectory( directory="#dir#" action="create" mode="777" )`), including calls that switch to commas after the first attribute
- Support a subscript as a `var` declaration name (`var mappings[ key ] = value`)
- Fix `new` with a dotted Java path (`new java.util.Properties()`): `java` and `cfml` are also the `new java:` type prefixes, and their bare tokens out-lexed the identifier straight after `new`

## [0.26.31]

### cfml & cfscript

- Support the empty struct literal `[=]`, alongside the existing `[:]`

### cfml

- Treat a bare `>` or `<` in template text as text (`<p>a > b</p>`, `#ratio#%  ==>`) instead of an error

### cfscript

- Support the typed `param` statement (`param string url.id default="0";`), used in `.cfm` templates via `<cfscript>`
- Fix an infinite loop on an unterminated query string: `queryExecute("` hung the parser, because `scan_query_text` looped to the closing quote with no EOF check

### cfquery

- Support the bitwise operators `&`, `|` and `^` in SQL (`WHERE status & 2048 = 2048`)

## [0.26.30]

- Publish Python bindings to PyPI as part of the release workflow (wheels built via `cibuildwheel`, sdist via `build`, upload via trusted publishing)
- Fix Python sdist/wheel builds: bundle `common/*.h`, per-dialect `tree_sitter/*.h`, and `cfml/queries/*.scm` so `pip install tree-sitter-cfml` succeeds from source and query constants resolve

## [0.26.29]

### cfml & cfscript

- Add `[:]` ordered struct literal syntax
- Add `EQUAL` as a binary equality operator (synonym for `EQ`)
- Support wildcard imports (e.g. `import component.*`)
- Allow `cfhtmlhead`, `cfhtmlbody`, and `cfcache` as paired tags with closing tags

### cfscript

- Support multiple attributes on `include` statement (e.g. `include template="file.cfm" runonce="true"`)
- Support multiline `query` tag with attributes on separate lines
- Add triple-backtick cfml template blocks (` ``` `) with cfml injection
- Support dotted variable names in catch clause parameter (e.g. `catch (any local.e)`)
- Support `new component` inline component expressions with attributes and body
- Support case-insensitive `Component` in `new component` expressions
- Support `java:` and `cfml:` type prefixes in `new` expressions (e.g. `new java:java.io.File(path)`)
- Allow whitespace between `?` and `:` in elvis operator
- Fix `hash_empty` (`##`) to use `token.immediate`, preventing GLR state explosion in large files

## [0.26.28]

- Add .scm files as a source of truth for other projects
- Add validation for .scm files against the respective grammars

## [0.26.27]

- Support `final` as a component modifier
- Support multiple access modifiers on functions (e.g. `public static string function`)
- Support multi-line property declarations and function attributes (using `tag_linefeed`)
- Support dotted catch types (e.g. `catch (App.CustomException e)`)
- Support multiple catch clauses in try/catch
- Support parameter metadata attributes (e.g. `string name = "" taffy_minlength="1"`)
- Fix automatic semicolon insertion before CFML word operators (`and`, `or`, `eq`, `neq`, `not`, `gt`, `gte`, `ge`, `lt`, `lte`, `le`, `mod`)

## [0.26.26]

### cfscript

- Support string literal as catch type (e.g. `catch("any" ex)`)
- Support case-insensitive `IN` / `OF` keywords in for-in loops
- Remove `--` as a comment (was conflicting with decrement operator)
- Add `include` statement support (e.g. `include "file.cfm";`)
- Add `private`, `public` to reserved identifiers (usable as variable names)
- Allow `component` as an inline statement (not just top-level)
- Support abstract function declarations in interfaces (`function name();`)

### cfquery

- Allow square brackets inside single-quoted and double-quoted SQL strings (e.g. `' [' + code + ']'`)
- Support `<cfreturn>` inside cfquery bodies
- Support `<cfoutput>` inside cfquery bodies
- Support backtick-quoted identifiers for MySQL-style quoting (`` `column_name` ``)
- Support T-SQL `@variable` and `@@system_variable` identifiers
- Add `BEGIN`, `WHILE`, `GO`, `EOF` to SQL keywords
- Fix `--` inside quoted strings being incorrectly parsed as a line comment
- Fix single quotes inside double-quoted values causing parse errors
- Fix SQL `CASE WHEN...END` inside `<cfcase>` tags triggering erroneous implicit tag close
- Split `+` concatenation into `query_concat_expression` (with optional right operand) to support `+` before `<cfif>` blocks

## [0.26.25]

- Add CDATA section support with CFML hash expressions (`<![CDATA[#expr#]]>`)

## [0.26.24]

- Add cfsavecontent content-type directive (`<!--- @content TYPE --->`) supporting cfml, html, script, css, xml, sql, and raw
- Add CDATA section support with CFML hash expressions (`<![CDATA[#expr#]]>`)
- Remove cfprocessingdirective and cfsetting from void tags (they can have bodies)
- Allow digits in cf_attribute_name (e.g. `show3d`)
- Fix & handling in html_text (don't stop at non-entity ampersands)
- Fix numeric entities (&#9654;) not conflicting with CFML hash expressions

## [0.26.22]

- Fix versioning

## [0.26.21]

- Fix for property definitions in cfscript components

## [0.26.20]

- Fix for abstract keyword for script component definitions #30

## [0.26.19]

- Add `target/` to eslint ignores
- Add JSDoc comments to `scripts/release.js`

## [0.26.18]

- Fixes for standaone query parens
- Security fix for scanner

## [0.26.17]

- Fixes for standalone query operators

## [0.26.16]

- SQL types should be classed as functions
- Add additional SQL functions

## [0.26.15]

- Further Updates to cfquery grammar and associated highlights.scm
- Removal of CFHTML grammar ( covered by CFML grammar )

## [0.26.14]

- Updates to cfquery grammar and associated highlights.scm
- highlights.scm replace `lua-match` with `match`, fixes #27 thanks @chapmandu

## [0.26.12]

- Fix `SYMBOL_COUNT` conflict

## [0.26.11]

- `cfcomponent` tags are now optional siblings ( not parents )
- `cffunction` tags are now specific tag definitions
- Support `script` tags inside `cfcontent` tags

## [0.26.10]

- Fix for erroneous end tags crossing boundary
- Fix escaped hashes

## [0.26.9]

- Fixes for Go bindings

## [0.26.8]

- Fixes for nested comments
- Fixes for # expressions on the left side of an assignment
- Fixes for implicit self close tags within <cfelse> / <cfelseif> tags

## [0.26.7]

- Scanner code improvements

## [0.26.6]

- Fix for script based cfc's

## [0.26.5]

- CFHTML / CFML grammars become one — cfhtml still exists for now, but tools and parsers only need to use cfml, cfscript, and cfquery dialects
- Cut down the cfquery grammar — implements a reduced version of the cfquery grammar that shares common rules, to be built back up over time (the full grammar caused WASM builds to exceed 10 minutes, blocking zed.dev extension builds)

## [0.26.4]

- Fixes for various regressions in 0.26.3
- Fixes for cfscript component cfc's

## [0.26.3]

- Various fixes for CFQuery grammar
- Other repo tidy ups and fixes ( thanks @gavinbaumanis )

## [0.26.0]

- Introduce CFQuery grammar
- Rename private node `_cf_tag` to `_cf_tags`
