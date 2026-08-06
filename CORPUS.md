# Real-world corpus testing

The corpus tests in `cf*/test/corpus/` are hand-written. This document covers the
complementary exercise: pointing the three grammars at a large body of CFML
written by other people, and recording what breaks.

## Running it yourself

```bash
npm run corpus:fetch     # shallow-clone the curated repo list into ./corpus (~100 MB)
npm run scan corpus      # one line per ERROR / MISSING node
npm run corpus:report    # the same scan, clustered into distinct failure sites
npm run probe            # minimal reductions of every construct found below
```

`corpus/` is gitignored — it is third-party code under a mix of licences and is
never committed. `npm run corpus:fetch -- --list` prints the repository list;
extra repositories can be passed as arguments.

## The corpus

25 public repositories, **12,549 CFML files** (`.cfc`, `.cfm`, `.cfml`, `.cfs`),
spanning tag-based templates, script components, and embedded SQL:

| Area | Repositories |
|------|--------------|
| Engine + test suites | `lucee/Lucee` (3,776 files), `lucee/lucee-docs`, `lucee/script-runner`, `lucee/extension-mongodb`, `ortus-boxlang/BoxLang` |
| Frameworks | `ColdBox/coldbox-platform`, `cfwheels/cfwheels`, `framework-one/fw1`, `atuttle/Taffy`, `Ortus-Solutions/TestBox`, `Ortus-Solutions/DocBox` |
| Applications / CMS | `pixl8/preside-cms`, `MSU-NatSci/MuraCMS`, `Ortus-Solutions/ContentBox`, `valtech-cfml/Slatwall`, `ColdBox/coldbox-samples` |
| Tooling / modules | `Ortus-Solutions/commandbox`, `coldbox-modules/{qb,cborm,cbfs,cbsecurity,cbi18n}`, `cfsimplicity/spreadsheet-cfml`, `foundeo/cfdocs`, `cfmleditor/cfmleditor` |

Files are scanned with the `cfml` grammar (or `cfscript` for `.cfs`), then every
`cf_script_content`, `cf_component_content` and `cf_query_content` region is
re-parsed with the injected grammar, exactly as `injections.scm` describes.

## Results

Scanned on `master` (v0.26.30), on `claude/keyword-casing-and-test-harness` (the
branch that makes keywords case-insensitive), and on this branch, which merges
that work and fixes the regressions it introduced:

| | `master` | casing branch | this branch |
|---|---|---|---|
| Files scanned | 12,549 | 12,549 | 12,549 |
| Files with at least one error | 96 (0.8%) | 96 (0.8%) | 95 (0.8%) |
| ERROR / MISSING nodes | 7,367 | 2,104 | 1,743 |

All three parse **over 99% of real-world files cleanly**. Raw error counts
overstate the number of distinct problems, because one early ERROR derails the
rest of a file; `npm run corpus:report` clusters on the *first* error per file
and reduces the 7,367 nodes to a few dozen distinct sites.

The `cfquery` grammar came out strongest: of **2,247 `<cfquery>` bodies** in the
corpus, only one construct fails (bitwise `&`, below).

### What the casing branch changed, and what this branch fixes

The casing branch fixes mixed-case keywords wholesale (`Try`/`}Catch(Any e){`/
`For`/`If`), which is what removes ~5,200 error nodes. It also introduced three
regressions, each caught by a probe in `test/probes/` and each fixed here:

| Construct | `master` | casing branch | this branch | Found in |
|---|---|---|---|---|
| `mystring[4:13]`, `[4:13:2]`, `[-10:-4]` — string/array slicing | parses | **ERROR** | parses | Lucee `test/tickets/LDEV4374`, `LDEV1813` |
| `function instanceOf( required classPath ){}` — user function named like a keyword | parses | **ERROR** | parses | ColdBox `system/aop/Matcher.cfc`, TestBox `system/Assertion.cfc`, WireBox, cfwheels, BoxLang |
| `function init( string id, Struct config, Component listener )` — parameter typed `Component` | parses | **ERROR** | parses | Lucee `context/gateway/AsynchronousEvents.cfc`, `DummyGateway.cfc`, `TaskGateway.cfc` |

The last two are the classic cost of `word: $.identifier` plus keyword tokens:
once a word is lexed as a keyword it stops being usable as an ordinary
identifier, and CFML code uses these words as names.

#### The fixes

1. **Slicing** is now a rule of its own, `slice_expression`, instead of falling
   out of `pair` being reachable inside a subscript through the expression
   conflicts the casing branch removed. Bounds are optional, so Lucee's `s[:6]`
   and `s[4:13:2]` parse too — `LDEV1813` fails on *both* earlier branches and
   parses here.
2. **`function` is no longer a `_reserved_identifier`.** Listing it there made
   `function` a valid expression start, which made every binary operator valid
   immediately after it; keyword extraction then lexed the name in
   `function instanceOf( … )` as the `instanceof` operator. It is still accepted
   as an assignable name via `_lhs_expression`, which is what Lucee's script-
   syntax `admin … function="" …` tag calls need. This fixes not just
   `instanceOf` but every keyword-shaped function name — `contains`, `eq`, `mod`,
   `is`, `in`, `not`, `and`, `component`, `static`, `default`, `new`, `query`.
3. **`parameter_type` accepts `component`**, which lexes as a keyword at the
   start of a parameter because `_reserved_identifier` makes it valid there.
4. **`new` is a `_reserved_identifier` in the tag grammar too.** The casing
   branch made `new` usable as an identifier in `cfscript/grammar.js` but not in
   `common/define-grammar.js`, so `<cfset var new = "">` (Mura's
   `core/mura/fileWriter.cfc`) cascaded into **305** ERROR nodes for the rest of
   the file, against 7 on `master`. It now parses cleanly, and that file parses
   in 3.1 ms instead of 13 ms — error recovery was the entire cost.

Net effect against the casing branch: **16 files fixed, 0 newly broken.**

### Performance

Measured over the corpus with each grammar fed byte-identical inputs (whole
files for `cfml`, extracted script regions for `cfscript`, query regions for
`cfquery`), best of three repetitions, two samples per build:

| | `master` | casing branch | this branch |
|---|---|---|---|
| `cfml` (54.4 MB) | 3,118–3,212 ms | 3,148 ms | 3,152–3,199 ms |
| `cfscript` (39.7 MB) | 14,128–14,604 ms | 15,395 ms | 13,459–13,599 ms |
| `cfquery` (0.8 MB) | 648–692 ms | 607 ms | 638–771 ms |

Run-to-run spread on one build is 3–7% (20% for the much smaller `cfquery`
input), so **no parse-time regression is measurable** — the differences are
inside the noise.

What does grow is the generated tables: `parser.c` totals 34.5 MB on `master`
against 41.5 MB here (+20%), and the compiled Node addon 7.14 MB against
8.82 MB (+23%). Resident memory after loading all three languages was 55 MB on
every build.

#### WASM size

The playground WASM is the only place this growth reaches users. What they
actually download is the *compressed* file, and the playground loads exactly one
grammar, lazily, on selection:

| `docs/…` | `master` raw | here raw | `master` gzip | here gzip |
|---|---|---|---|---|
| `tree-sitter-cfml.wasm` (the default) | 2,637 K | 2,940 K | 176 K | **170 K** |
| `tree-sitter-cfscript.wasm` | 2,112 K | 3,067 K | 150 K | 174 K |
| `tree-sitter-cfquery.wasm` | 2,354 K | 2,554 K | 165 K | **159 K** |

So the default download is slightly *smaller* than `master`, and the worst case
(`cfscript`, only fetched if you switch language) is +24 K compressed. Raw size
is the wrong number to optimise; parse tables compress ~18:1.

Two things that do **not** help, both measured rather than assumed:

- `wasm-opt -Oz --strip-debug --strip-producers` shrinks `tree-sitter-cfscript.wasm`
  by 1.1% and makes it *2 K larger* after gzip. 95% of the file is the data
  section (parse tables) — 2,907 K of 3,068 K. There is no code to optimise.
- Trimming unused casings. Across the corpus, lowercase appears for 53/53
  keywords, PascalCase for 50/53, UPPERCASE for 47/53; camelCase differs from
  lowercase only for the two multi-word keywords (`queryExecute`, `instanceOf`)
  and `casings()` already dedupes the rest. Dropping the nine unobserved
  variants would save ~4% of the enumeration and rest on a single corpus.

What would help is changing *how* case-insensitivity is spelled. Regenerating
`cfscript` with `casings()` returning lowercase only gives a 11.79 MB
`parser.c`, against 16.25 MB as enumerated here and 12.86 MB on `master`. In
other words the enumeration costs **4.5 MB of tables (+38%)**, while the rest of
the branch's restructuring (keyword extraction via `word: $.identifier`, dropped
JS residue, fewer conflicts) is worth **−1.1 MB on its own**. Classifying
keywords case-insensitively in the external scanner — which already does exactly
this for CF tag names in `common/tag.h` — would collapse the four tokens per
keyword back to one and should land the tables below `master`. That is a
substantial change, not a tweak: 53 keywords would become external tokens.

`docs/tree-sitter-cfhtml.wasm` (1.78 MB) was removed here; it is left over from a
grammar the repo no longer builds, and the playground never referenced it.

Beware of measuring this by timing `scripts/scan.js`: it interleaves parsing
with tree walking and text extraction, and error recovery dominates, so a build
that produces *fewer* errors can look slower. Feed fixed inputs to each grammar
instead.

### The 14 files that are worse than `master`

87 files improve by 5,735 error nodes; 14 get worse by 115. Every one of those
14 was reduced to a standalone repro and run against both builds:

**Twelve are recovery cascades, not new gaps.** The construct fails on `master`
too; what differs is how far the damage spreads. In isolation this branch is
usually *better* — a dynamic tag inside a `<cfloop>` gives 4 errors on `master`
and 2 here; add a custom CF tag around it and it is 4 against 1. But nest the
same failure inside `<cffunction>` / `<cfsavecontent>` and the branch's ERROR
node can swallow the enclosing tag, so every later `</cfif>`, `</cfloop>` and
`</cffunction>` becomes an error too (2 errors on `master`, 3 here, and in the
real files 1 against 7). Error recovery is table-driven and heuristic, so this
moved when the tables did; it is not something the grammar states directly.

The constructs behind those cascades, none of which parse on either branch:

| Construct | Files | Example |
|---|---|---|
| Dynamic tag name with a static prefix or namespace | 9 | `<h#field.getLevel()#>`, `<dc:#container#>` |
| Bare `#` in a cfscript string (invalid CFML — needs `##`) | 1 | `md.append( "# ColdBox Performance Analysis Report" )` |
| `#` inside a CFML comment inside `<script>` | 1 | `<!--- see https://gist.github.com/…/#comment-592093 --->` |
| `<script>` opened in one `<cfsavecontent>` and closed in another | 1 | Slatwall `ClientScriptWriter_jQuery.cfc` |

The plain `<#expr#>` dynamic tag form does parse — it is only the prefixed and
namespaced variants that do not, and `_start_tag_name` is an external token, so
supporting them means scanner work rather than a grammar rule.

**One is a genuine gap:** a subscript index holding more than one pair,
`a[ b: "c", d: "e" ]` — which is how Lucee's `$[ … ]` ordered-struct syntax
reaches the parser in `test/tickets/LDEV3133`. `master` parsed it as a sequence
of pairs; the explicit `slice_expression` covers the single-colon form only.
Three error nodes in one file, on syntax Lucee itself only uses in a parser
ticket, so it is recorded as a probe rather than chased.

Making `script_element`'s end tag optional — the obvious fix for the unclosed
`<script>` — produces unresolvable grammar conflicts, so that one stays a known
limitation as well.

## Known gaps

Every item below still fails on this branch, and is reduced to a minimal file in
`test/probes/` with its status recorded in `test/probes/expected.json`.
`npm run probe` fails if any of them changes status, so a fix or a regression is
impossible to miss.

### cfscript

| Construct | Example | Seen in |
|---|---|---|
| Typed `catch` with `var` | `} catch( any var e ) {` | CommandBox endpoints |
| `var` with a scoped/dotted name | `var local.thisPerm = ...;`, `var a.b.c.d = 1;` | ContentBox patches, CommandBox, Lucee tests |
| Tag comment in a script body | `<!--- viewlets --->` inside `component { }` | Preside handlers, Lucee tests |
| Script-syntax tag calls | `cfdirectory( directory="#dir#" action="create" );` | Lucee test suite and admin |
| Array return type | `IValidationError[] function getFieldErrors( ... )` | cbvalidation |
| `final` / access-modifier member declarations | `final MEMBER = "value";`, `public prop = "prop";` | Lucee tests |
| Empty struct literal | `var uniqueList = [=];` | CommandBox jmespath, lucee-docs |

Mixed-case keywords (`}Catch(Any e){`, cbfeeds and the Lucee test suite) were a
gap on `master` and are fixed here by the merged casing work.

### cfml

| Construct | Example | Seen in |
|---|---|---|
| Bare `>` or `<` in template text | `<p>a > b</p>`, `#ratio#%  ==>` | ColdBox `CacheReport.cfm` and ordinary HTML everywhere |
| `<cfsetting>` inside a tag-based component | `<cfsetting showdebugoutput="false">` in `<cfcomponent>` | ColdBox test apps, Mura — related to the `<cfsetting>` note in [LIMITATIONS.md](LIMITATIONS.md) |
| Typed `param` statement | `param string url.id default="0";` | common CFML idiom (the untyped `param name="x" default="";` parses) |
| Dynamic tag name with a prefix or namespace | `<h#field.getLevel()#>`, `<dc:#container#>` | Lucee admin, cbfeeds — the plain `<#expr#>` form parses |
| Bare `#` in a cfscript string | `"# ColdBox Performance Analysis Report"` | ColdBox perf harness — invalid CFML too, probe pins the blast radius |

### cfquery

| Construct | Example | Seen in |
|---|---|---|
| Bitwise `&` in SQL | `AND status & 2048 = 2048` | Mura `core/mura/dbUpdates/*.cfm` (SQL Server DDL) |

### Not grammar bugs

Two large error clusters are not defects:

- **JavaScript served from `.cfm`.** `lucee/core/.../context/form.cfm` and Mura's
  `*.js.cfm` files are JavaScript emitted through `<cfcontent type="text/javascript">`,
  with no `<script>` element. Nothing in the text identifies it as JavaScript, so
  the grammar reads it as template markup. These few files account for roughly
  three quarters of all error nodes in the corpus. (JavaScript inside a real
  `<script>` element parses fine — see `test/probes/cfml/script_block_js.cfm`.)
- **Upstream syntax errors.** e.g. ColdBox `system/web/Controller.cfc` is missing a
  comma in an argument list.

## Regression tests added from this exercise

Constructs that *do* parse today, and that real code depends on, are now pinned in
the corpus tests so they cannot regress silently:

- `cfscript/test/corpus/real_world.txt` — string slicing, a function named
  `instanceOf`, `Struct`/`Component` parameter types, `static { }` blocks, padded
  parameter defaults, a javadoc block before `component`.
- `cfml/test/corpus/real_world.txt` — dynamic closing tag names (`</#expr#>`),
  JavaScript in a `<script>` element, `param name=` inside `<cfscript>`,
  `<cfcontinue>` inside `<cfloop>`, a function call in a `<cfif>` condition, and a
  `<cfquery>` with `<cfqueryparam>` and conditional SQL.
- `cfquery/test/corpus/real_world.txt` — bracket identifiers, `N'...'` literals,
  T-SQL `IF NOT EXISTS` DDL guards, CTEs, `CASE` expressions, hash expressions in
  join predicates.

The first three of those cfscript cases are exactly the ones the casing branch
broke, which is how the regressions were caught in the first place.

Slicing now has a dedicated `slice_expression` node with `start` / `end` / `step`
fields. On `master` it parsed as a `pair` inside the subscript, and negative
bounds produced an odd `unary_expression` wrapping that pair; the corpus test
pins the new shape.
