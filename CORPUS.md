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

Scanned on `master` (v0.26.30) and on `claude/keyword-casing-and-test-harness`,
the branch that makes keywords case-insensitive:

| | `master` | casing branch |
|---|---|---|
| Files scanned | 12,549 | 12,549 |
| Files with at least one error | 96 (0.8%) | 96 (0.8%) |
| ERROR / MISSING nodes | 7,367 | 2,104 |

Both branches parse **over 99% of real-world files cleanly**. Raw error counts
overstate the number of distinct problems, because one early ERROR derails the
rest of a file; `npm run corpus:report` clusters on the *first* error per file
and reduces the 7,367 nodes to a few dozen distinct sites.

The `cfquery` grammar came out strongest: of **2,247 `<cfquery>` bodies** in the
corpus, only one construct fails (bitwise `&`, below).

### What the casing branch changes

It fixes mixed-case keywords wholesale (`Try`/`}Catch(Any e){`/`For`/`If`), which
is what removes ~5,200 error nodes. It also introduces **three regressions**,
each caught by a probe in `test/probes/`:

| Construct | `master` | casing branch | Found in |
|---|---|---|---|
| `mystring[4:13]`, `[4:13:2]`, `[-10:-4]` — string/array slicing | parses | **ERROR** | Lucee `test/tickets/LDEV4374` |
| `function instanceOf( required classPath ){}` — user function named like a keyword | parses | **ERROR** | ColdBox `system/aop/Matcher.cfc`, TestBox `system/Assertion.cfc`, WireBox, cfwheels, BoxLang |
| `function init( string id, Struct config, Component listener )` — parameter typed `Component` | parses | **ERROR** | Lucee `context/gateway/AsynchronousEvents.cfc` |

The last two are the classic cost of `word: $.identifier` plus keyword tokens:
once `instanceof` and `component` are lexed as keywords they stop being usable as
ordinary identifiers, and CFML code uses both as names.

## Known gaps (both branches)

Every item below is reduced to a minimal file in `test/probes/`, with its current
status recorded in `test/probes/expected.json`. `npm run probe` fails if any of
them changes status, so a fix or a regression is impossible to miss.

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
| Mixed-case keywords | `}Catch(Any e){` | cbfeeds, Lucee tests — **fixed on the casing branch** |

### cfml

| Construct | Example | Seen in |
|---|---|---|
| Bare `>` or `<` in template text | `<p>a > b</p>`, `#ratio#%  ==>` | ColdBox `CacheReport.cfm` and ordinary HTML everywhere |
| `<cfsetting>` inside a tag-based component | `<cfsetting showdebugoutput="false">` in `<cfcomponent>` | ColdBox test apps, Mura — related to the `<cfsetting>` note in [LIMITATIONS.md](LIMITATIONS.md) |
| Typed `param` statement | `param string url.id default="0";` | common CFML idiom (the untyped `param name="x" default="";` parses) |

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
breaks, so `npm test` on that branch now fails loudly instead of silently.

One caveat worth recording: negative slice bounds (`mystring[-10:-4]`) parse
without error but produce an odd tree — `unary_expression` wrapping a `pair`
rather than a slice with two negative bounds. The corpus test pins current
behaviour; the shape is worth revisiting if slicing ever gets a dedicated node.
