# Corpus failures, file by file

Every file in the real-world corpus that still fails to parse, with the reason.

**Measured on 2026-09-19 at `b6ce191` plus the `elseif` fix: 640 error nodes
across 117 files of 15,392.** Every node is accounted for — there is no unexplained residue, which
is the difference between this document and the residual estimate it replaces
in [`FAILING-PATTERNS.md`](FAILING-PATTERNS.md).

`FAILING-PATTERNS.md` remains the place for *what a fix would cost* and for the
per-issue plans. This file answers a narrower question — **which files fail and
why** — and is derived rather than estimated, so it can be regenerated whenever
the corpus or the grammar moves.

## How this was produced, and why that matters

```bash
npm run build && npm run scan corpus > scan.txt
```

Then, for each of the 119 files, the offending **source line** was read and the
construct **reduced to a standalone case** that reproduces the failure. Labels
below are the reduced case, not a reading of the scan's `parse error near …`
text.

That distinction is not pedantic. Six first-pass labels taken from the error
text were wrong, and each was caught only by reduction:

- Preside's `DateFormatService.cfc` looked like a missing semicolon or a `<=`
  comparison. It is neither: `x = (date)` fails where `x = date` parses.
- `elseif` looked like the trigger in two files. A single `elseif` appeared to
  parse — but as a `tag_statement`, not as part of the `if`. Reducing it found a
  **wrong tree in five files where only two reported an error**, and the fix is
  now shipped; see `FAILING-PATTERNS.md`.
- Preside's `ScaffoldingService.cfc` looked like `${…}` in a string — the trap
  `FAILING-PATTERNS.md` already warns about. It is a missing comma between two
  parameters.
- Preside's `editFolder.cfm` looked like a spaced elvis `? :`, which parses
  perfectly well in cfscript. It only fails inside a `#…#` tag interpolation.
- ColdBox's `Routes.cfm` looked like a leading-dot method chain, which parses.
  It is `with( … )` specifically — `with` is a tag-statement keyword, so it
  cannot be the head of a chain.
- Lucee's `LDEV3133/test.cfm` looked like a generic struct-literal problem. It
  is the `$[ … ]` bracket spelling holding multiple pairs, deliberately declined
  in [#80](https://github.com/cfmleditor/tree-sitter-cfml/issues/80).

**A scan line names the position where recovery gave up, which is frequently not
the construct.** Reduce before you label.

The counts in each row are error *nodes*, not files, and a single trigger can
cascade: `PerformanceSuite.cfc` is 185 nodes from one unescaped `#` on line 474.
Node counts measure what people happened to write, not what the language
defines — see the function-listener case in `FAILING-PATTERNS.md` for how badly
that can mislead.

## Not parser defects — 308 nodes, 34 files (48%)

Listed first so they do not distort the rest. Invalid CFML, files that are not
CFML, and one construct the parser rejects **on purpose**.

| Nodes | Files | Cause |
|---|---|---|
| 185 | 1 | bare `#` in a cfscript string (needs `##`) — cascades from line 1 |
| 50 | 6 | bare JavaScript served from a `.cfm`, no `<script>` element |
| 50 | 4 | generator template, not CFML (`{{…}}` / `${…}` placeholders) |
| 14 | 14 | deliberately-invalid vendor fixture |
| 4 | 4 | unbalanced braces / typo — deliberately broken fixture |
| 2 | 2 | source typo: misspelled `required` → 3-word parameter |
| 2 | 2 | `<cfscript>` never closed before EOF |
| 1 | 1 | unquoted struct as a tag attribute — correctly rejected (#115) |

## Gaps already on record — 211 nodes, 34 files (33%)

Each of these is described in [`FAILING-PATTERNS.md`](FAILING-PATTERNS.md) or
[`LIMITATIONS.md`](../LIMITATIONS.md), with cost estimates where they exist. Two
rows are already fixed in open pull requests and will disappear when those land.

| Nodes | Files | Cause |
|---|---|---|
| 71 | 1 | CSS in `<style>` with many `#` tokens |
| 53 | 11 | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| 45 | 3 | dotted key in a struct literal — `{ a.b = 1 }` |
| 13 | 9 | dynamic close tag opened in a different block — `</#expr#>` |
| 12 | 5 | start tag whose `>` sits inside a `<cfif>` branch |
| 9 | 1 | backtick tag-island fences nested in one line |
| 4 | 2 | `</cfscript>` inside a string — fixed by PR #126 |
| 3 | 1 | `$[ … ]` subscript holding multiple pairs — declined in #80 |
| 1 | 1 | `savecontent` as an expression — fixed by PR #125 |

## Gaps not previously recorded — 121 nodes, 49 files (19%)

This is the part worth acting on. Every row here reduces to a one- or two-line
case, and most are a single file.

| Nodes | Files | Construct |
|---|---|---|
| 17 | 5 | space-separated attributes in a script-syntax tag call |
| 17 | 1 | type keyword parenthesised as an expression — `x = (date)` |
| 13 | 1 | space-separated attrs + `var x &= …` compound assignment |
| 7 | 1 | not reducible — only fails in whole-file context |
| 7 | 1 | `<!--- --->` tag comment inside an argument list |
| 6 | 1 | regex literal with escaped quotes and `>` in a string |
| 4 | 2 | stray `<` inside tag text — `cl<ass=`, `<#context#/…?` |
| 4 | 2 | missing comma between parameters |
| 4 | 4 | `var` declaration inside a `while` condition |
| 4 | 4 | arrow function with a statement body — `=> return x` |
| 4 | 3 | compound assignment in a `var` declaration — `var x &= …` |
| 4 | 2 | `<cffunction>` body with unbalanced inner markup |
| 3 | 3 | `</div` / `</p` — close tag split across lines |
| 3 | 2 | `#…#` interpolation inside a JS string in `<script>` |
| 3 | 1 | `component` as a function return type |
| 3 | 1 | `<cfsavecontent>` body holding an unbalanced `</cfoutput>` |
| 2 | 2 | `<nav id="#…#">` dynamic attribute in a `<cfif>` body |
| 2 | 1 | `if ( … );` with an empty body before `else` |
| 2 | 1 | `<cfbreak "outer">` / `<cfcontinue "outer">` label argument |
| 2 | 1 | `<!ENTITY … >` raw markup inside `<cfoutput>` |
| 2 | 2 | `static foo = 9000;` field declaration |
| 1 | 1 | `with( … )` followed by a `.method()` chain |
| 1 | 1 | elvis `?:` split across a newline |
| 1 | 1 | unquoted attribute value containing `?a=` then `>` |
| 1 | 1 | `<cfadmin` multi-line tag with a computed attribute |
| 1 | 1 | newline-separated attrs on an `admin` tag statement |
| 1 | 1 | `silent false { … }` — tag statement with a bare boolean |
| 1 | 1 | `final` on a parameter |
| 1 | 1 | spaced elvis `? :` inside a `#…#` tag interpolation |

## Two findings worth pulling out

### `x = (date)` does not parse, and `x = date` does

A type keyword is fine bare, fine as a call argument and fine in an array
literal, but not as the first token of a parenthesised expression:

```cfml
x = date;            // parses
x = f( date );       // parses
x = [ date ];        // parses
if ( date ) { }      // parses
x = (date);          // ERROR
x = (date + 1);      // ERROR
x = (date[1]);       // ERROR
return (date);       // ERROR
```

`date`, `string`, `numeric`, `boolean`, `any`, `void` and `function` all fail
this way; `struct`, `array`, `query`, `component` and `time` do not. The split
follows which words are extracted keywords, so this is the keyword-extraction
hazard `CLAUDE.md` warns about, seen from the other side.

It is one file in the corpus today. That is not a reason to rank it low: the
construct is ordinary CFML and the corpus only shows what people happened to
write. The function-listener case in `FAILING-PATTERNS.md` is the precedent —
a form with zero corpus occurrences turned out to be real, and reading the
vendor documentation found it where no scan could.

### Space-separated tag-call attributes is now the largest open gap

**30 nodes across 6 files** — the 17/5 row plus Lucee's `Jira.cfc`, which is
booked separately only because it also carries a `var x &= …`. That puts it
ahead of the dotted struct key by spread, if not by node count: the struct key's
45 nodes sit in three files, 44 of them in two that use the construct
repetitively.

```cfml
cffile( file="#dir#/a.txt", action="write" output="hello" );   // no comma
```

It also has the clearest fix shape of anything in the third table: the
`_parameter_separator` external token already exists and already handles this,
but requires a line terminator, deliberately — the same-line form was left out
to keep `f( a b )` unambiguous. Re-opening it means finding what distinguishes
an attribute run from a mis-typed argument list, which is a real design question
rather than a mechanical change.

## Regenerating this document

```bash
npm run corpus:fetch                     # if ~/corpus or ./corpus is absent
npm run build && npm run scan corpus > scan.txt
npm run corpus:report -- --from scan.txt # clusters by source-line shape
```

`corpus:report` gets you the clusters. It cannot produce the third table on its
own — the labels there come from reducing each construct by hand, and as the six
corrections above show, that step is where the value is. When you re-derive
this, re-reduce anything whose file set changed rather than carrying a label
forward.

## Appendix — every failing file

All 117, alphabetical. **Cat** is the section above: **A** not a parser defect,
**B** already on record, **C** newly recorded here.

| File (under `corpus/`) | Nodes | Cat | Why |
|---|---|---|---|
| `atuttle_Taffy/examples/api_anythingtoxml/anythingtoxml/ArrayToXML.cfc` | 1 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_anythingtoxml/anythingtoxml/ObjectToXML.cfc` | 1 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_anythingtoxml/anythingtoxml/QueryToXML.cfc` | 2 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_anythingtoxml/anythingtoxml/StructToXML.cfc` | 1 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_twoFormats/resources/AnythingToXML/ArrayToXML.cfc` | 1 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_twoFormats/resources/AnythingToXML/ObjectToXML.cfc` | 1 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_twoFormats/resources/AnythingToXML/QueryToXML.cfc` | 2 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `atuttle_Taffy/examples/api_twoFormats/resources/AnythingToXML/StructToXML.cfc` | 1 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `cfwheels_cfwheels/examples/tweet/.claude/skills/wheels-model-generator/templates/basic-model.cfc` | 29 | A | generator template, not CFML (`{{…}}` / `${…}` placeholders) |
| `cfwheels_cfwheels/tools/vscode-ext/assets/templates/controller.cfc` | 18 | A | generator template, not CFML (`{{…}}` / `${…}` placeholders) |
| `cfwheels_cfwheels/tools/vscode-ext/assets/templates/view-index.cfm` | 1 | A | generator template, not CFML (`{{…}}` / `${…}` placeholders) |
| `ColdBox_coldbox-platform/tests/perf-harness/PerformanceSuite.cfc` | 185 | A | bare `#` in a cfscript string (needs `##`) — cascades from line 1 |
| `ColdBox_coldbox-samples/applications/feedGenerator/modules/cbfeeds/models/util/SharedGenerator.cfc` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `ColdBox_coldbox-samples/applications/feedReader/modules/cbfeeds/models/util/SharedGenerator.cfc` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `ColdBox_coldbox-samples/applications/sampleloginapp/models/securityInterceptor.cfc` | 1 | A | source typo: misspelled `required` → 3-word parameter |
| `ColdBox_coldbox-samples/applications/SimpleBlog/modules/cbfeeds/models/util/SharedGenerator.cfc` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `ColdBox_coldbox-samples/applications/SimpleCrudWithREST/config/Routes.cfm` | 1 | C | `with( … )` followed by a `.method()` chain |
| `ColdBox_coldbox-samples/applications/TaskManager/modules/cbfeeds/models/util/SharedGenerator.cfc` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `coldbox-modules_cbfeeds/models/util/SharedGenerator.cfc` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `coldbox-modules_cbi18n/models/i18n.cfc` | 1 | A | source typo: misspelled `required` → 3-word parameter |
| `lucee_Lucee/core/src/main/cfml/context/admin/debugging.templates.create.cfm` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `lucee_Lucee/core/src/main/cfml/context/admin/Jira.cfc` | 13 | C | space-separated attrs + `var x &= …` compound assignment |
| `lucee_Lucee/core/src/main/cfml/context/admin/server.logging.create.cfm` | 7 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `lucee_Lucee/core/src/main/cfml/context/admin/services.ai.create.cfm` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `lucee_Lucee/core/src/main/cfml/context/admin/services.cache.create.cfm` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `lucee_Lucee/core/src/main/cfml/context/admin/services.gateway.create.cfm` | 5 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `lucee_Lucee/core/src/main/cfml/context/form.cfm` | 6 | A | bare JavaScript served from a `.cfm`, no `<script>` element |
| `lucee_Lucee/core/src/main/cfml/context/formtag-form.cfm` | 6 | A | bare JavaScript served from a `.cfm`, no `<script>` element |
| `lucee_Lucee/core/src/main/cfml/context/gateway/MailWatcher.cfc` | 1 | C | space-separated attributes in a script-syntax tag call |
| `lucee_Lucee/core/src/main/cfml/context/wddx.cfm` | 9 | A | bare JavaScript served from a `.cfm`, no `<script>` element |
| `lucee_Lucee/core/src/main/java/resource/context/admin/debug/Classic.cfc` | 2 | C | `<cffunction>` body with unbalanced inner markup |
| `lucee_Lucee/core/src/main/java/resource/context/admin/debug/Modern.cfc` | 1 | C | `</div` / `</p` — close tag split across lines |
| `lucee_Lucee/core/src/main/java/resource/context/admin/debug/Simple.cfc` | 71 | B | CSS in `<style>` with many `#` tokens |
| `lucee_Lucee/core/src/main/java/resource/context/admin/logging/appender/DatasourceAppender.cfc` | 1 | C | `<cfadmin` multi-line tag with a computed attribute |
| `lucee_Lucee/test/_setupTestServices.cfc` | 1 | C | newline-separated attrs on an `admin` tag statement |
| `lucee_Lucee/test/functions/DirectoryCopy.cfc` | 3 | C | space-separated attributes in a script-syntax tag call |
| `lucee_Lucee/test/functions/DirectoryCreate.cfc` | 7 | C | `<!--- --->` tag comment inside an argument list |
| `lucee_Lucee/test/functions/FileDelete.cfc` | 2 | C | `if ( … );` with an empty body before `else` |
| `lucee_Lucee/test/general/CodeIsland.cfc` | 9 | B | backtick tag-island fences nested in one line |
| `lucee_Lucee/test/general/Struct/invalid1.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/general/Struct/invalid2.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/general/Struct/invalid3.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/jira/Jira2659.cfc` | 2 | C | `<cfbreak "outer">` / `<cfcontinue "outer">` label argument |
| `lucee_Lucee/test/tags/Imap.cfc` | 3 | C | space-separated attributes in a script-syntax tag call |
| `lucee_Lucee/test/tags/Zip.cfc` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/tickets/_LDEV0219.cfc` | 1 | A | unbalanced braces / typo — deliberately broken fixture |
| `lucee_Lucee/test/tickets/_LDEV3623.cfc` | 1 | B | `savecontent` as an expression — fixed by PR #125 |
| `lucee_Lucee/test/tickets/LDEV0533.cfc` | 1 | C | `silent false { … }` — tag statement with a bare boolean |
| `lucee_Lucee/test/tickets/LDEV0869.cfc` | 2 | B | `</cfscript>` inside a string — fixed by PR #126 |
| `lucee_Lucee/test/tickets/LDEV1123/lib/Redden.cfc` | 1 | A | unbalanced braces / typo — deliberately broken fixture |
| `lucee_Lucee/test/tickets/LDEV1606.cfc` | 9 | C | space-separated attributes in a script-syntax tag call |
| `lucee_Lucee/test/tickets/LDEV1676/LDEV1676.cfm` | 2 | C | `<!ENTITY … >` raw markup inside `<cfoutput>` |
| `lucee_Lucee/test/tickets/LDEV1750.cfc` | 2 | C | `<cffunction>` body with unbalanced inner markup |
| `lucee_Lucee/test/tickets/LDEV1819/test2.cfm` | 1 | C | arrow function with a statement body — `=> return x` |
| `lucee_Lucee/test/tickets/LDEV2629/LDEV2629.cfm` | 1 | C | space-separated attributes in a script-syntax tag call |
| `lucee_Lucee/test/tickets/LDEV3060/invalidcomponent.cfc` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/tickets/LDEV3060/invalidcomponent1.cfc` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/tickets/LDEV3113.cfc` | 1 | B | dotted key in a struct literal — `{ a.b = 1 }` |
| `lucee_Lucee/test/tickets/LDEV3133/test.cfm` | 3 | B | `$[ … ]` subscript holding multiple pairs — declined in #80 |
| `lucee_Lucee/test/tickets/LDEV3671/test3671.cfc` | 1 | C | `final` on a parameter |
| `lucee_Lucee/test/tickets/LDEV4895/ldev4895.cfs` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/tickets/LDEV5184_2.cfc` | 1 | C | arrow function with a statement body — `=> return x` |
| `lucee_Lucee/test/tickets/LDEV5389.cfc` | 1 | A | unbalanced braces / typo — deliberately broken fixture |
| `lucee_Lucee/test/tickets/LDEV5763/LDEV5763_tag_unquoted_struct.cfc` | 1 | A | unquoted struct as a tag attribute — correctly rejected (#115) |
| `lucee_Lucee/test/tickets/LDEV5900/bad1.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/tickets/LDEV5900/bad2.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `lucee_Lucee/test/tickets/LDEV6377_regression.cfm` | 1 | A | `<cfscript>` never closed before EOF |
| `lucee_script-runner/sampleBad/index.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `MSU-NatSci_MuraCMS/admin/assets/js/frontendtools.js.cfm` | 26 | A | bare JavaScript served from a `.cfm`, no `<script>` element |
| `MSU-NatSci_MuraCMS/admin/core/views/carch/loadsiteflat.cfm` | 1 | C | `</div` / `</p` — close tag split across lines |
| `MSU-NatSci_MuraCMS/admin/core/views/carch/objectclass/legacy/dsp_adzones.cfm` | 1 | C | `<nav id="#…#">` dynamic attribute in a `<cfif>` body |
| `MSU-NatSci_MuraCMS/admin/core/views/carch/search.cfm` | 5 | B | start tag whose `>` sits inside a `<cfif>` branch |
| `MSU-NatSci_MuraCMS/admin/core/views/carch/statusmodal.cfm` | 1 | C | `</div` / `</p` — close tag split across lines |
| `MSU-NatSci_MuraCMS/admin/core/views/ccategory/dsp_tab_usage.cfm` | 2 | C | stray `<` inside tag text — `cl<ass=`, `<#context#/…?` |
| `MSU-NatSci_MuraCMS/admin/core/views/csettings/deploybundle.cfm` | 2 | C | `#…#` interpolation inside a JS string in `<script>` |
| `MSU-NatSci_MuraCMS/core/modules/v1/collection/includes/dsp_content_list.cfm` | 3 | B | dynamic close tag opened in a different block — `</#expr#>` |
| `MSU-NatSci_MuraCMS/core/modules/v1/comments/index.cfm` | 2 | B | start tag whose `>` sits inside a `<cfif>` branch |
| `MSU-NatSci_MuraCMS/core/modules/v1/nav/dsp_archive.cfm` | 1 | C | `<nav id="#…#">` dynamic attribute in a `<cfif>` body |
| `MSU-NatSci_MuraCMS/core/mura/client/api/resource/variation.js.cfm` | 2 | A | bare JavaScript served from a `.cfm`, no `<script>` element |
| `MSU-NatSci_MuraCMS/core/setup/inc/_form.cfm` | 2 | C | stray `<` inside tag text — `cl<ass=`, `<#context#/…?` |
| `MSU-NatSci_MuraCMS/core/templates/web.config.template.cfm` | 2 | A | generator template, not CFML (`{{…}}` / `${…}` placeholders) |
| `MSU-NatSci_MuraCMS/core/vendor/ckeditor/config.js.cfm` | 1 | A | bare JavaScript served from a `.cfm`, no `<script>` element |
| `ortus-boxlang_BoxLang/src/test/java/ortus/boxlang/compiler/LargeMethod.cfc` | 1 | C | arrow function with a statement body — `=> return x` |
| `ortus-boxlang_BoxLang/src/test/java/TestCases/phase3/StaticTestCF.cfc` | 1 | C | `static foo = 9000;` field declaration |
| `ortus-boxlang_BoxLang/src/test/java/TestCases/phase3/StaticTestCF2.cfc` | 1 | C | `static foo = 9000;` field declaration |
| `Ortus-Solutions_commandbox/src/cfml/system/modules_app/system-commands/commands/run.cfc` | 1 | C | `var` declaration inside a `while` condition |
| `Ortus-Solutions_commandbox/src/cfml/system/services/ServerService.cfc` | 1 | C | arrow function with a statement body — `=> return x` |
| `Ortus-Solutions_commandbox/src/cfml/system/util/FileSystem.cfc` | 1 | C | `var` declaration inside a `while` condition |
| `Ortus-Solutions_commandbox/src/cfml/system/util/MultiSelect.cfc` | 1 | C | `var` declaration inside a `while` condition |
| `Ortus-Solutions_commandbox/src/cfml/system/util/Print.cfc` | 1 | C | compound assignment in a `var` declaration — `var x &= …` |
| `Ortus-Solutions_commandbox/src/cfml/system/util/ProgressableDownloader.cfc` | 1 | C | `var` declaration inside a `while` condition |
| `Ortus-Solutions_commandbox/src/cfml/system/util/TablePrinter.cfc` | 7 | C | not reducible — only fails in whole-file context |
| `Ortus-Solutions_ContentBox/modules/contentbox/models/system/CBHelper.cfc` | 2 | C | missing comma between parameters |
| `Ortus-Solutions_ContentBox/modules/contentbox/modules/contentbox-admin/views/authors/editor.cfm` | 1 | B | start tag whose `>` sits inside a `<cfif>` branch |
| `Ortus-Solutions_ContentBox/modules/contentbox/modules/contentbox-admin/views/settings/rawSettingsTable.cfm` | 3 | B | start tag whose `>` sits inside a `<cfif>` branch |
| `Ortus-Solutions_DocBox/strategy/json/JSONAPIStrategy.cfc` | 3 | C | `component` as a function return type |
| `pixl8_preside-cms/system/services/devtools/ScaffoldingService.cfc` | 2 | C | missing comma between parameters |
| `pixl8_preside-cms/system/services/l10n/DateFormatService.cfc` | 17 | C | type keyword parenthesised as an expression — `x = (date)` |
| `pixl8_preside-cms/system/views/admin/assetmanager/editFolder.cfm` | 1 | C | spaced elvis `? :` inside a `#…#` tag interpolation |
| `pixl8_preside-cms/system/views/webflow/default/stepTitle.cfm` | 1 | B | dynamic tag name with a static prefix — `<h#n#>`, `<dc:#t#>` |
| `pixl8_preside-cms/tests/unit/api/presideObjects/RelationshipGuidanceTest.cfc` | 30 | B | dotted key in a struct literal — `{ a.b = 1 }` |
| `pixl8_preside-ext-saml2-sso/views/page-types/saml_slo_page/index.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `RustCFML_RustCFML/tests/core/test_parser_lucee_shapes.cfm` | 1 | C | elvis `?:` split across a newline |
| `RustCFML_RustCFML/tests/java_shims/test_minimal.cfm` | 1 | A | `<cfscript>` never closed before EOF |
| `RustCFML_RustCFML/tests/oop/test_include_rewrite_freshness.cfm` | 2 | B | `</cfscript>` inside a string — fixed by PR #126 |
| `RustCFML_RustCFML/tests/oop/test_preside_serve_fixes.cfm` | 1 | A | unbalanced braces / typo — deliberately broken fixture |
| `RustCFML_RustCFML/tests/tags/test_tag_unquoted_attr_literal.cfm` | 1 | C | unquoted attribute value containing `?a=` then `>` |
| `RustCFML_RustCFML/tests/tags/unclosed/cfoutput.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `RustCFML_RustCFML/tests/tags/unclosed/cfquery.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `RustCFML_RustCFML/tests/tags/unclosed/cfsavecontent.cfm` | 1 | A | deliberately-invalid vendor fixture |
| `RustCFML_RustCFML/tests/types/test_dotted_key_struct_literals.cfm` | 14 | B | dotted key in a struct literal — `{ a.b = 1 }` |
| `valtech-cfml_Slatwall/com/entity/Product.cfc` | 1 | C | compound assignment in a `var` declaration — `var x &= …` |
| `valtech-cfml_Slatwall/org/entitySmartList/SmartList.cfc` | 2 | C | compound assignment in a `var` declaration — `var x &= …` |
| `valtech-cfml_Slatwall/org/ValidateThis/client/jQuery/ClientRuleScripter_FutureDate.cfc` | 1 | B | start tag whose `>` sits inside a `<cfif>` branch |
| `valtech-cfml_Slatwall/org/ValidateThis/client/jQuery/ClientRuleScripter_noHTML.cfc` | 6 | C | regex literal with escaped quotes and `>` in a string |
| `valtech-cfml_Slatwall/org/ValidateThis/client/jQuery/ClientScriptWriter_jQuery.cfc` | 3 | C | `<cfsavecontent>` body holding an unbalanced `</cfoutput>` |
| `valtech-cfml_Slatwall/org/ValidateThis/client/qForms/ClientScriptWriter_qForms.cfc` | 1 | C | `#…#` interpolation inside a JS string in `<script>` |
