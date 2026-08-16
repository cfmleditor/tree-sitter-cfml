# Changelog

## [Unreleased]

### cfml & cfscript

- Support a `var`-scoped **dotted** loop variable in a for-in header — `for ( var local.package in items )` ([#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53)). A dotted name parsed without `var` and a plain name parsed with it; only the combination failed. `_for_header`'s `var` branch accepted `identifier`, `_reserved_identifier` and a destructuring pattern, but never got the `member_expression` that `variable_declarator` was widened with for `var local.x = 1`, so the two rules had drifted. One `$.member_expression` in each of `cfscript/grammar.js` and `common/define-grammar.js`, no new conflicts, parse tables up 0.5–0.9% with no new symbols or productions. The case worth knowing is the one that made this cheap rather than Med-risk: widening `variable_declarator` the same way is what once made `var new = 1` lex `new` as a keyword, and the fix then was to spell out `alias($._reserved_identifier, $.identifier)` — which this rule already carried, so `for ( var export in … )` and `for ( var new in … )` still parse and the corpus test pins them alongside the new form. A subscript loop variable (`for ( var pkg[1] in items )`) is deliberately still unsupported: `variable_declarator` accepts it for `var mappings[ key ] = value`, but nothing in the corpus writes it in a for-in header. Corpus 789 → 787 error nodes across 170 → 169 files, the scan diff being two deleted lines from the one affected file
- Support an array type in **parameter** position — `function f( string[] v )`, and the nested `string[][] w` ([#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51)). The mirror of the array *return* type, which has parsed since 0.26.x. `repeat($.array_return_suffix)` after `parameter_type` in both CFScript grammars, reusing the return type's single `token(seq('[', ']'))` for the same reason it exists there: as two tokens the `[` is reachable from `array_pattern` in this state and the parser cannot choose until it has read the `]`, so lexing the pair together moves the decision one character of lookahead earlier. No new conflicts. The node keeps its `array_return_suffix` name, so the existing `@punctuation.bracket` highlight covers both positions. Corpus 801 → 789 error nodes across 173 → 170 files, every affected file to zero — 3 files, not the 1 the estimate assumed, and two of them Lucee rather than the RustCFML test that reported it. An empty array default (`function f( a = [] )`) still parses as an `array`, and `function f( [a, b] )` still as an `array_pattern`

### Documentation

- **Correct the recorded scope of [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50)**, which `LIMITATIONS.md` and `docs/FAILING-PATTERNS.md` both carried as "only `in` is affected" and costed as the cheapest of the four remaining CFScript gaps. It is neither. `eq`, `is`, `mod`, `contains`, `neq` and `lt` fail the same way, and the deciding factor is the **type** rather than the name: `string in` and `any in` parse because `parameter_type` spells those as `keyword()` tokens, while `array`, `query`, `struct` and `component` reach the slot through `$.identifier` and leave a `primary_expression` stack live, where a binary operator is valid and out-lexes the identifier — `--debug` shows the lexer emitting `sym:in`. A fix therefore needs the whole word-operator set in the parameter-name slot, ~25 tokens of which most are anonymous case-insensitive regexes rather than named rules, so it is re-rated Med-High/Med and is now the most expensive of the group. Recorded in the predictions table as its own miss: a scope claim in an issue is not evidence, and the matrix that disproves this one took two minutes to run
- **Correct a wrong claim about five CFScript constructs** ([#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49), [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50), [#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51), [#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52), [#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53)). `CORPUS.md`, `LIMITATIONS.md` and `docs/FAILING-PATTERNS.md` all recorded these as already parsing in the embedded CFScript of `common/define-grammar.js` and failing only in the standalone `cfscript/grammar.js`, costed as "a port of rules that already exist". There is nothing to port: the `cfml` grammar does not parse CFScript bodies at all — `<cfscript>` is `cf_script_content`, a component body is `cf_component_content`, both raw text for `injections.scm` — so the evidence for "the embedded grammar already has it" was a body that had never been parsed. The copy of the CFScript rules in `common/define-grammar.js` is real and reachable through `<cfset f = function( … ) { … }>`, and reached that way all five fail there too; `_formal_parameter` and `formal_parameters` are byte-identical between the two files. The four still open are re-rated Med/Med and each needs the change in both files. The general form, now recorded in `CORPUS.md`: a claim that something already parses somewhere has to name the input that reaches the rule

### cfml & cfquery

- Support the `''` doubled-quote escape inside a **single**-quoted tag attribute value (`<cfparam name="sq" default='x ''y'' z'>`), which previously collapsed the tag to an ERROR ([#54](https://github.com/cfmleditor/tree-sitter-cfml/issues/54)). The escape has always worked in a double-quoted value; `quoted_cf_attribute_value` carried `'""'` in its double-quoted branch and had no `"''"` counterpart in the other. One `choice` arm, no new conflicts, and `cfscript/src/parser.c` is byte-identical since the rule lives in the shared `common/define-grammar.js`. The corpus scan goes 802 → 801 error nodes across 174 → 173 files, the whole diff being one deleted line in the RustCFML test the probe was reduced from. The case worth knowing about is the one *not* in the issue: a `''` token could in principle out-lex the closing quote and break the empty value `default=''`, so the new corpus test pins both escapes and both empty forms rather than just the reported construct

### Tooling

- Keep the real-world corpus in `~/corpus` when that directory exists, falling back to the gitignored in-repo `corpus/` when it does not (`scripts/corpus-dir.js`, printed at the top of every fetch). The in-repo default is per-clone, so a second clone or a `git worktree` re-fetched all 97 MB, and `git clean -xdf` deleted it precisely because it is gitignored. Creating `~/corpus` opts in; deleting it opts out; nothing creates it for you. `npm run scan corpus` follows the same resolution, so every documented command works unchanged in either layout — only the bare word `corpus` is redirected, and only when it does not exist relative to the current directory
- Fix `scripts/release.js` silently skipping the commit, tag and push when its prompts are answered from a pipe rather than a terminal. It opened a `readline` interface per prompt, but readline emits a `line` event for every line of a chunk as soon as the chunk arrives while `question` only captures the line emitted *after* it is called — so with `printf 'y\ny\ny\n' | npm run release …` the answers to prompts 2 and 3 were emitted during prompt 1 and discarded, and every later prompt read EOF. An unanswered `question` never fires its callback, so the promise stayed pending, the event loop emptied and the script **exited 0** having bumped every version, built, linted, tested and rebuilt the WASM but committed nothing. A non-TTY stdin is now drained up front and the answers consumed one per prompt; running out is a hard error rather than a silent success. The interactive path is unchanged. Sharing one interface across the prompts does *not* fix this, which is the obvious-looking fix to avoid
- Report a failed release step as a one-line error and a non-zero exit rather than an unhandled promise rejection and a stack trace; `run` already inherits stdio, so the failing command's own output is directly above

## [0.26.32]

### Bindings

- Add a Java binding (`bindings/java/`, `pom.xml`): `TreeSitterCfml`, `TreeSitterCfscript` and `TreeSitterCfquery` under `io.github.cfmleditor.jtreesitter.*`, built on [jtreesitter](https://github.com/tree-sitter/java-tree-sitter) and the Foreign Function & Memory API. Needs JDK 23+. Unlike the other bindings it does not compile the C: it resolves `tree_sitter_*` out of shared libraries at runtime
- Add `npm run build:native`, which builds the three grammars *and* the tree-sitter runtime (from the copy vendored by the `tree-sitter` npm package, so the version is pinned by `package-lock.json`) into `build/native/` — the libraries the Java binding loads
- Fix `make -C cfscript` and `make -C cfquery` building a library named `libtree-sitter-cfml`: `common/common.mak` reassigned `LANGUAGE_NAME` after the including Makefile had set it, so both dialects produced a `libtree-sitter-cfml.{a,so}` and a `tree-sitter-cfml.pc` holding the wrong parser. The last dialect to be installed won
- Fix `make install` failing to find the C header: it looked for `bindings/c/…` relative to the dialect directory rather than the repository root. Add the missing `tree_sitter/tree-sitter-cfquery.h`, and move `tree-sitter-cfscript.h` alongside the other two in `bindings/c/tree_sitter/`
- Fix the hardcoded `VERSION` in `common/common.mak`, stale at 0.26.17, which was written into every generated `.pc` file. It now comes from `tree-sitter.json`, and `.pc` descriptions are no longer empty for cfscript and cfquery

### Performance

- **`cfscript` is ~1.95× faster.** The scanner was scanning to end-of-file on every error-recovery step. `cfml_template_content` is only reachable straight after a ``` fence, but tree-sitter marks every external token valid during recovery, so the scanner went looking for a closing fence that ordinary CFML does not contain — consuming the rest of the file and then returning false. Over 400 corpus script components (2.2 MB) that was 25.1M of the scanner's 25.13M character advances, and 52% of every instruction the parse retired. `TEMPLATE_CHARS` already stood down the same way. Parsing the corpus's 8,285 script components goes 9.6s → 4.9s; `npm run bench` reports 19.2s → 12.1s across all 42.2 MB of script inputs, and a fixed 400-file subset retires 2.4× fewer instructions
- **`cfml` is 5–8% faster**, from three changes to the shared scanner. Parsing the corpus's 4,260 templates retires 8.1% fewer instructions (25.80G → 23.72G) and takes 2.62s → 2.50s wall-clock; the external scanner's share of a parse drops from 26% to 17%:
  - Rebuild the tag stack in place on deserialize rather than freeing and re-allocating every tag name on every call. Deserialize runs once per external-token lex — 85,213 times over 300 corpus templates — and was 8.5% of a parse; it is now 3.9%. Tag name buffers are reused, so only a change in stack depth reaches the allocator
  - Drop the `strlen` per entry from the tag-name lookups. `tag_type_for_name` walked 126 entries calling `strlen` on each, which alone was 2.2% of every instruction a corpus parse retired; the name tables are fixed-width and NUL-padded, so the length is a byte read. Same for the `cfcomponent`-style void-tag list, and for the `</script>`/`</style>` delimiter length that was being recomputed per matching character
  - Answer the ASCII cases of `iswspace`, `iswalpha`, `iswalnum`, `towupper` and `towlower` inline in both scanners rather than paying an out-of-line locale-aware library call per character, keeping the library call for the non-ASCII tail
- No change to what parses. Output is byte-identical across the corpus for `cfml` (13,756 templates) and `cfquery` (2,381 embedded queries). Under `cfscript` six of 9,521 files change, all of them error-recovery shapes; the one that uses the ``` fence recovers better than before, an `ERROR` around the preceding statement becoming a `MISSING ";"` (recorded as `test/probes/cfscript/cfml_template_after_bare_statement.cfc`). The corpus scan went 769 → 768 error lines with no file regressing

### cfml & cfquery

- **Fix a heap over-read in the shared scanner that segfaulted the parser** ([#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57)). `serialize` writes two tag arrays into a 1,024-byte buffer; deep nesting filled it on the first, so the second found no room for even its 4-byte header and — `break` inside `do { … } while(0)` leaving the whole block — wrote nothing at all. `deserialize` then read its counts unconditionally at that offset, one past the end of the heap block, and followed the resulting garbage until it hit an unmapped page. Both halves are fixed: `serialize` reserves room so every section is always written and only *entries* are ever dropped, and `deserialize` bounds-checks every read against `length`, so a truncated or foreign buffer now costs scanner state rather than memory safety. The crash was probabilistic — `<xyz>` × 400 died 20/20, × 119 died 4/20 — and is now 0 across 260 runs, with Valgrind reporting no invalid reads. No grammar change: `cf*/src/parser.c` is byte-identical, the corpus scan is unchanged at 803 error nodes across 174 of 14,975 files, and `npm run bench` reports no change

### Corpus

- Add `RustCFML/RustCFML` to the corpus repository list — a CFML interpreter written in Rust, 1,188 CFML files of which the `tests/` tree is 1,108, each file written to pin one edge-case language behaviour. It scans at 40 error nodes across 15 of 1,188 files (98.7% of files clean), all 40 in `tests/`, and turned up eight constructs no earlier scan had shown, recorded in [`CORPUS.md`](CORPUS.md), [`LIMITATIONS.md`](LIMITATIONS.md) and [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md) with a probe each. No grammar changes — five of the eight already parse in the embedded CFScript of `common/define-grammar.js` and fail only in the standalone `cfscript/grammar.js`, which `injections.scm` is what makes user-visible

### Tooling

- Scan `examples/` in CI (`npm run scan:examples`). Nothing scanned it before — no script, no workflow, and ESLint ignored it — which is why nobody had noticed that **both** its files segfault the parser, through the heap over-read in the shared scanner's `deserialize` reported as [#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57). The crash is probabilistic: it needs the serialized tag state to overflow its 1,024-byte buffer, and whether the resulting out-of-bounds read faults depends on the heap layout of that particular process
- Add `--isolate` to `npm run scan`, which parses each file in a child process so a crash is reported instead of ending the scan, and `--expect <file>`, which compares the result against a committed baseline and fails on drift in either direction — the same contract `npm run probe` has. `--retries <n>` classifies a file that only crashes some of the time. A baseline entry of `flaky` covers the case retrying cannot pin down, asserting only that the file has not become ordinary parse errors. Re-baseline with `npm run scan:examples -- --update`
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
