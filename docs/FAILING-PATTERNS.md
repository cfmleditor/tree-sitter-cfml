# Failing patterns

An assessment of every ERROR / MISSING node the three grammars produce over the
real-world corpus, as of `82cc7dc`. Method and corpus are described in
[`../CORPUS.md`](../CORPUS.md); reproduce with:

```bash
npm run corpus:fetch && npm run scan corpus > scan.txt
npm run corpus:report -- --from scan.txt
```

This is the second baseline. The first, at `d06ff66`, is what the fixes under
[What has been fixed](#what-has-been-fixed) were argued from. Two things about
that document turned out to be wrong in ways worth carrying forward; both are
described under [How to read these numbers](#how-to-read-these-numbers) rather
than quietly corrected.

## The numbers

| | |
|---|---|
| Files scanned | 12,549 |
| Files parsed with no error at all | 12,388 (**98.7%**) |
| ERROR / MISSING nodes | 766 |
| Files carrying at least one | 161 |
| …of which carry exactly one | 92 |

Split by grammar: **cfscript 484**, **cfml 281**, **cfquery 1**. The `cfquery`
figure has been 1 or 0 since bitwise operators landed — 2,247 `<cfquery>` bodies
and a single failing construct in all of them.

Still concentrated, though less than before: the top 10 files hold 445 nodes,
58% of the total.

## How to read these numbers

**A file's first error usually is not its cause.** Where the first ERROR is
reported at `1:1`, the parser lost the document early and the position tells you
nothing. Clustering on first errors is what made the previous baseline record
the subscript-`var` pattern as **one file with 71 nodes** when it was **nine
files with 111** — eight of the nine cascaded from line 1, so their real trigger
was never counted. The file counts below come from signature-matching the
*source* rather than the error position.

**The file count in `scan.js` was wrong until `82cc7dc`.** `hadErrors` was set
by the three top-level parse branches but never by `parseInjection`, so a file
whose only errors came from an injected `<cfscript>` or `<cfquery>` region had
its lines printed and was never counted. Every "N files" figure quoted during
the first round of fixes was too low — the previous baseline's 62 was really
161. Node counts were never affected.

**Node counts measure blast radius, not defect count.** One unparseable
construct near the top of a file leaves the rest unrecoverable, so a 100-node
file usually means one defect. The inverse also happens: a fix that improves
recovery can *raise* a file's count by replacing one document-wide ERROR with
several small ones. `DirectoryCreate.cfc` went 5 → 6 that way, while its first
error moved from `1:1` to `13:11`. Judge a change by per-file totals, and reduce
any suspect line to a one-liner before concluding anything.

## Not grammar defects — 271 nodes, 8 files (35%)

Listed first so they do not distort the rest.

| Nodes | Files | Cause | Example |
|---|---|---|---|
| 199 | 2 | Bare `#` inside a cfscript string | `md.append( "# ColdBox Performance Analysis Report" )` — CFML needs `##`, and the engines reject this too |
| 43 | 5 | JavaScript served from a `.cfm` template | Lucee's `context/form.cfm`, Mura's `*.js.cfm` — no `<script>` element anywhere, and nothing marks the content as JavaScript |
| 29 | 1 | Generator template with placeholders | cfwheels' `basic-model.cfc`, containing `{{ModelName}}` and `{{#associations}}` |

`PerformanceSuite.cfc` alone is 198 of the 199. JavaScript inside a real
`<script>` element parses fine — `test/probes/cfml/script_block_js.cfm` covers
that.

## Genuine gaps — 191 nodes, 27 files

| Nodes | Files | Pattern | Example | Probe |
|---|---|---|---|---|
| 71 | 1 | CSS in `<style>` with many `#` tokens | Lucee's `debug/Simple.cfc`: 42 `#` across ID selectors and hex colours | — |
| 48 | 10 | Dynamic tag name with a static prefix or namespace | `<h#field.getLevel()#>…</h#field.getLevel()#>`, `<dc:#container#>` | `prefixed_dynamic_tag.cfm` |
| 30 | 1 | Dotted key in a struct literal — **tractable, rejected on cost** | `var objects = { obj_a.meta = { … }, obj_b.meta = { … } };` | — |
| 19 | 13 | Dynamic tag opened and closed in different blocks | `<cfoutput>#t()#</#g(n)#></cfoutput>`, the open tag being in an earlier `<cfoutput>` | — |
| 19 | 1 | Function-listener callback syntax | `var t = mySuccess():function( result, error ) { … };` | — |
| 4 | 1 | Subscript index holding more than one pair | `animals = $[ Aardwolf: "…", aardvark: "…" ];` | `subscript_multiple_pairs.cfc` |
| 2 | 1 | `thread { … }` followed by a tag island | a ` ``` ` block after `thread name="x" { … }`; each parses alone | — |

The plain `<#expr#>` dynamic tag form parses when open and close sit in the same
block; the prefixed, namespaced and split-across-blocks variants do not.
`_start_tag_name` is an external token and open/close matching happens in the
scanner's tag stack, so all three are scanner work rather than grammar rules.

`Simple.cfc` resists reduction. Hex colours, ID selectors and `<cfif>` inside
`<style>` all parse individually, and the shortest failing extract is 20 lines
of its stylesheet — whatever the trigger is, it emerges from accumulation.

## What is left over — 304 nodes, 126 files

The remainder resists signature-matching, and 81 of those 126 files carry a
single node. Spot-checking finds no further cluster: they are individually odd
constructs, plus cascades whose triggers are already listed above.

One worked example of a false lead, because it is the shape these take:
Slatwall's `menu.cfm` (36 nodes) is full of `<cf_SlatwallActionCaller …>` custom
tags, which look like an obvious cause and are not — they parse correctly in
paired, unpaired and self-closing forms, and several other files merely contain
them incidentally.

This is the honest shape of the tail: long, thin, and not worth attacking as a
group.

## What has been fixed

Since the `d06ff66` baseline, in rough order of value delivered:

| Pattern | Files | Effect |
|---|---|---|
| Bare `>` or `<` in template text | 31 | 329 nodes — the largest single improvement |
| `new` with a dotted Java path | 5 | 5 nodes; `java` and `cfml` were out-lexing the identifier after `new` |
| Subscript as a `var` declaration name | 9 | 111 nodes; every affected file to zero |
| Script-syntax tag call with space-separated attributes | 40 | 113 nodes, including the with-a-body form |
| Array return type `X[] function` | 9 | 16 nodes |
| Empty struct `[=]`, typed `param`, bitwise `&` in SQL | 6+ | 17 nodes |
| `debugger` as an ordinary identifier | 2 | 15 nodes across the second corpus wave |
| Thin-arrow lambda `t -> t.b()` | 1 | 1 node; free — no new states, no new conflicts |
| `''` in a single-quoted tag attribute ([#54](https://github.com/cfmleditor/tree-sitter-cfml/issues/54)) | 1 | 1 node; one `choice` arm, no new conflicts. 802 → 801 nodes, 174 → 173 files, and the scan diff is a single deleted line |
| Array type in parameter position ([#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51)) | 3 | 12 nodes, every affected file to zero. `repeat($.array_return_suffix)` after `parameter_type` in both grammars, reusing the return type's single `[]` token; no new conflicts |
| `var`-scoped dotted loop variable ([#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53)) | 1 | 2 nodes, the affected file to zero. One `$.member_expression` added to the `var` branch of `_for_header` in both grammars — the widening `variable_declarator` already had, in a rule that already carried the `_reserved_identifier` guard that widening needs. No new conflicts |
| `=` spelling of a typed `param` default ([#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52)) | 1 | 1 node, the affected file to zero. A second branch in `tag_statement`'s shorthand form spelling the name and value as an existing `assignment_expression`, rather than a fresh `'=' $.expression` position that reopens the automatic-semicolon boundary. `cfscript` only: the shared grammar has no `tag_statement` at all |
| Word-shaped operator as a parameter name ([#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50)) | 1 | 2 nodes, the affected file to zero. A shared `_operator_shaped_name` rule aliased to `identifier` in the parameter-name slot of both grammars. No new conflicts and **one** extra state per grammar |
| `queryExecute("` infinite loop | — | not a node count: the parser hung forever |
| Heap over-read in the scanner's `deserialize` ([#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57)) | — | not a node count either: the parser **segfaulted**. Zero corpus movement (803 nodes before and after, byte-identical), because every input that reached it died rather than reporting errors |

## Cost and risk of what remains

Estimates come from this repository's own history. That history now includes
eight predictions with known outcomes, and the calibration is mixed — see
[Predictions checked against outcomes](#predictions-checked-against-outcomes).

Three properties of this grammar drive most of the risk:

- **Keyword extraction is lexical.** With `word: $.identifier`, a rule that makes
  a keyword valid in a new position changes how that word *lexes* everywhere in
  that state. This has bitten twice — but note that each time, the fix (naming
  `_reserved_identifier` explicitly) then protected every later change to the
  same rule.
- **`:` is heavily contested.** It already serves `pair`, `switch_case`,
  `slice_expression` and the ternary.
- **The scanner is shared, except where it is not.** `common/scanner.h` backs
  `cfml` and `cfquery`; `cfscript` has its own hand-written `src/scanner.c`. No
  generator checks scanner work — the corpus scan is the only safety net.

| Pattern | Complexity | Risk | Basis |
|---|---|---|---|
| Dotted key in a struct literal | **Low** | **Low** to write, **rejected on runtime cost** | Cheap to implement — one conflict, not the five the estimate assumed, by putting the dotted form in `pair` and `cf_pair` instead of widening `_property_name`. Rejected anyway: that one conflict is live at **every member access in the language**, and measured a 1.8× slowdown on cfscript for 30 nodes in one file. Lexing the key as a single token, the trick that made array return types free, is five times worse again and breaks `f( a.b )`. See [#42](https://github.com/cfmleditor/tree-sitter-cfml/pull/42) |
| CSS in `<style>` with many `#` | **Med-High** | **Med** | Does not reduce below 20 lines, so the mechanism is not yet understood — understand it before estimating again. One file, but a whole stylesheet is a plausible shape for any CFML admin template |
| Dynamic tag opened and closed in different blocks | **High** | **High** | Scanner tag-stack work on the shared header. 13 files but only 19 nodes: the surrounding markup still recovers, so the errors stay small |
| Prefixed / namespaced dynamic tag | **High** | **High** | Same tag stack, same shared header. Called the largest cluster at the last baseline; now 48 nodes |
| Function-listener `f():callback` | **Med-High** | **High** | Another `:` reading in the most contested character in the grammar, for a single-file Lucee feature |
| Subscript with more than one pair | **High** | **High** | Re-admits `pair` inside subscripts — the ambiguity the casing branch removed. One file, non-idiomatic syntax |
| Comma-less function parameters ([#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49)) | **High** | **High** | **Re-rated from Med/Med by matrix.** The newline is not a soft separator the grammar could honour: a *space* fails identically, so the comma is simply required by `commaSep1`. The shape that looks supported is a misparse — `f( a b )` is one parameter of type `a` named `b`, and `f( a b c )` errors. Making the comma optional therefore makes `f( a b )` ambiguous between one typed parameter and two untyped ones, an ambiguity inherent to CFML's `<type> <name>` syntax and live at every parameter list in the language. Needs a benchmark before it can be accepted, and the change is needed in both grammars |
| ~~Four~~ CFScript constructs that fail in **both** grammars | — | — | **Group dissolved; kept for the correction it carries.** [#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51), [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50), [#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52) and [#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53) are fixed; only [#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49) remains and has its own row above, re-rated High/High. The single Med/Med rating never fitted any of them: three came in at or under one line of real cost, and the fourth went up. #52 also broke the "both grammars" half of this entry: `common/define-grammar.js` has no `tag_statement` rule at all, so it carries no `param` statement in any spelling and the fix was `cfscript`-only. The correction below stands for #49 and #50, whose rules do exist in both files. It said: "Not new features — a port of rules that already exist and are already tested in `common/define-grammar.js`". There is nothing to port. The `cfml` grammar never parses CFScript — `<cfscript>` is `cf_script_content` and a component body is `cf_component_content`, both raw text for `injections.scm` — so "the embedded grammar already has it" was measuring a body that had not been parsed. Reached through `<cfset f = function( … ) { … }>`, where the copy in `common/define-grammar.js` genuinely is live, all of them fail there too, and `_formal_parameter` is byte-identical between the two files. So each is a real change in both files, not a copy. The Med risk stands and is the reason: all four touch parameter lists or `param`, where keyword extraction is lexical. One at a time. [#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49), [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50) |
| Unpaired custom tags past ~1,014 bytes of tag names | **Med** | **Med** | **Cause now known, so the estimate below is no longer a guess.** Not a GLR or table bound as first supposed: each nested tag costs `name + 4` bytes of the scanner's 1,024-byte serialized state, and once that is full the deepest tags are silently dropped. Confirmed by the threshold tracking name length — `depth × (name + 4) ≈ 1,014` across names from 4 to 28 characters. A fix means making the state cheaper per tag (interning names, or storing a hash) rather than hunting a limit; the buffer size is fixed by tree-sitter and cannot be raised. Found while fixing [#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57), which is the same overflow's memory-safety half. [#55](https://github.com/cfmleditor/tree-sitter-cfml/issues/55) |
| Heap over-read in the scanner's `deserialize` | — | — | **Fixed.** The serialized-state overflow above also had a memory-safety half: the second tag array's header was skipped when the buffer was full, and `deserialize` read past the end of the heap block and segfaulted. `serialize` now reserves room so every section is written, and `deserialize` bounds-checks every read. See [#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57) |
| `</cfscript>` inside a string literal | **Med** | **High** | Shared-scanner work on `common/scanner.h`, so it lands in `cfml` and `cfquery` together. The raw-text scan would have to track string state, and a bug there breaks every `<cfscript>` block rather than an edge case. Confirm against Lucee first: the engines may also end the block here, in which case the current behaviour is correct and this row should be deleted. [#56](https://github.com/cfmleditor/tree-sitter-cfml/issues/56) |

### Implementation risk is not runtime cost

The table above rates how likely a change is to *break* something. It says
nothing about what the change costs at parse time, and those are independent —
which is how two changes shipped green while carrying a combined 6× penalty on
the most-used grammar before anyone measured.

The mechanism in both cases was a **conflict declared on a construct that occurs
everywhere**. A conflict makes the parser carry two live GLR stacks until
something disambiguates, so its cost is proportional to how often the ambiguous
prefix appears:

| Conflict | Ambiguous prefix | Live at | Measured |
|---|---|---|---|
| `[$.primary_expression, $.call_expression]` | `identifier (` | every call | 144 → 401 ms on one file |
| `[$.path, $.primary_expression]` | `identifier .` | every member access | 471 → 861 ms |

Both were fixable without giving up the feature or accepting the cost — the tag
call was confined to statement position, where its conflicts are live only where
tag calls actually occur, which took the file back to 110 ms. The dotted key had
no such escape and was dropped.

So: **run `npm run bench` on any change that declares a conflict**, baseline
first. A conflict on `identifier` followed by a common character is the shape to
watch for.

### Predictions checked against outcomes

| Pattern | Predicted | Actual |
|---|---|---|
| Empty struct `[=]` | Low / Low | Accurate — one `choice` arm |
| Typed `param` | Low / Low | **Cost doubled.** Keyword tokens in the type slot broke `loop array=data` |
| Bitwise `&` in SQL | Low-Med / Med | **Over-estimated.** Concatenation only occurs inside `#...#`, so the two readings never meet |
| Array return type | Med / Med | **Over-estimated.** Lexing `[]` as one token moved the decision into the lexer; no conflicts |
| Bare `>` / `<` in text | Med-High / High | Accurate — the first attempt broke every CFML comment |
| Script-syntax tag call | High / Med | Accurate — seven conflicts and one design reversal |
| Subscript as a `var` name | Med / Med-High | **Over-estimated risk, under-counted scale 9×.** One line, no conflicts; 9 files, not 1 |
| Dotted key in a struct literal | Med / Med-High | **Over-estimated the cost of writing it, and missed the cost of running it.** One conflict, not five — but that conflict is live at every member access, and the table had no column for that. The reason the section above exists |
| Array type in parameter position | Low / Med, as one of "five constructs the embedded grammar already has" | **Right answer, wrong reasoning — and the reasoning was load-bearing for four other issues.** The fix is as cheap as billed: `repeat($.array_return_suffix)` after `parameter_type`, reusing the `[]` token that made the *return* type free, no new conflicts. But it was not the port the estimate described, because the `cfml` grammar never parses CFScript bodies and so had never accepted any of the five. Scale was also under-counted: 3 files and 12 nodes, not the single RustCFML test that prompted it — two of the three are Lucee. The lesson is narrower than "estimates drift": **a claim that something already parses somewhere else has to name the input that reaches it**, or it measures raw text |
| `''` in a single-quoted tag attribute | Low / Low | **Accurate, and the first estimate on this page to be exactly right.** One `choice` arm mirroring `'""'`, no conflicts, `cfscript/src/parser.c` byte-identical. The one non-obvious risk was not in the estimate: a `''` token could out-lex the closing quote and break the *empty* value `default=''`. It does not — the double-quoted branch has faced the same longest-match question since it was written — but that is the case the new corpus test pins, not the one from the issue |
| `var`-scoped dotted loop variable | Med / Med, as one of four constructs "in the area where keyword extraction is lexical" | **Over-estimated, for the reason this table keeps finding.** One line — `$.member_expression` in the `var` branch of `_for_header` — in each of the two grammars, no new conflicts, table up 0.5–0.9% with no new symbols or productions. The rule already spelled out `alias($._reserved_identifier, $.identifier)`, installed when `variable_declarator` was widened for `var local.x = 1` and `var new = 1`; that is exactly the guard this widening needed, so the hazard the Med rating was pricing had already been paid for. `for ( var export in … )` and `for ( var new in … )` still parse. Scale was right for once: 1 file, 2 nodes |
| `=` spelling of a typed `param` default | Med / Med, as one of four constructs needing the change in **both** grammars | **Over-estimated, and wrong about where it lands.** One `choice` arm in `tag_statement`, no new conflicts, 1 file and 1 node. It is `cfscript`-only: `common/define-grammar.js` has no `tag_statement` at all, so the shared grammar has no `param` statement in any spelling and there was no second edit to make. The non-obvious part was not the rule but its *shape* — spelling the default as `'=' $.expression` opens a fresh expression position whose end competes with the automatic semicolon, and `param numeric x = a + { … }` then reads as either a binary `+` continuing the value or a unary `+` opening the next statement. `generate` offers only a conflict or a precedence on `binary_expression`/`unary_operator`, both live at every `+` and `-`; `prec.right` on the new position does not help, because the competing reduction is outside the rule. Reusing `assignment_expression`, which already settles that boundary, generates clean. **When a new rule needs an expression, prefer an existing rule that already ends one** |
| Comma-less function parameters | Med / Med, and listed first of the four | **Under-estimated, and the issue's mechanism was wrong.** The newline is not a separator the grammar could honour — a space fails identically — and the shape that appears to work is a misparse: `f( a b )` is one parameter of type `a` named `b`, `f( a b c )` errors. Making the comma optional makes that input genuinely ambiguous between one typed parameter and two untyped ones, live at every parameter list in the language. Re-rated High/High and now gated on a benchmark. Both this and the row below were re-scoped by the same two-minute matrix, which is now the first thing to run on an issue rather than the last |
| A type in front of the parameter name `in` | Med / Med, and picked as the cheapest of the four | **Scope wrong, so the estimate was meaningless.** Not `in` and not a reserved-word problem: `eq`, `is`, `mod`, `contains`, `neq` and `lt` all fail identically, and the deciding factor is the *type* — `string in` and `any in` parse, `array in`, `query in`, `struct in` and `component in` do not. Any type reaching `parameter_type` through `$.identifier` leaves a `primary_expression` stack live, where a binary operator is valid and out-lexes the identifier. Fixing it means the whole word-operator set in the name slot, most of them anonymous case-insensitive regexes. **A scope claim in an issue is not evidence; run the matrix before costing from it** |
| The same, re-rated Med-High/Med after the matrix | Med-High / Med, "~25 tokens, most of them anonymous regexes" | **Over-estimated again, and by the one factor neither estimate had a column for: how the tokens are *grouped*.** The token count was right and the risk was not. Aliasing `in` alone into the parameter-name slot cost **88 states**; putting all nineteen behind a single `_operator_shaped_name` rule cost **1**, because one rule reachable from one slot collapses the states that nineteen separate alternatives would each fork. No new conflicts, and the anonymous regexes were never the obstacle — duplicating a pattern is free, since identical patterns unify to the same token and `a eq b` stays a `binary_expression`. What the estimate should have priced is the *shape* of the addition rather than its size. Two neighbours genuinely resisted and are recorded as limitations: `not`, the only unary operator in the set, and a default on an operator-shaped name. 1 file, 2 nodes |
| Thin-arrow lambda | not rated; recorded as "genuinely rare", implicitly not worth doing | **Wrong axis.** Prevalence was right — one real use in 13,777 files — but it was treated as the deciding factor. The change is `choice('=>', '->')` in two files: identical state counts, identical conflict counts, no measurable throughput change. Prevalence tells you what a fix is *worth*, not what it *costs*, and a one-line fix needs almost no worth to clear the bar |

The pattern in the misses: risk is over-estimated when an earlier fix has
already installed the guard the new change needs, and file counts are too low
wherever the affected files cascade from line 1.

One further miss has a different shape. Low prevalence was allowed to stand in
for low value on the thin arrow, and the cost was never estimated at all. Cheap
constructs deserve a cost estimate even when they look not worth doing —
prevalence and cost are independent, and this grammar's cheapest fixes have been
one-line `choice` arms with no measurable effect.

## What this suggests about priorities

1. **Nothing here is now clearly worth the risk.** The largest genuine gap is 71
   nodes in one file, and the two scanner clusters are 67 nodes between them.
   Against 12,549 files at 98.7% clean, what remains is maintenance rather than
   a backlog.
2. **Dotted keys in struct literals is no longer the recommendation** it was at
   the start of this baseline. It is cheap to write and was written, but the one
   conflict it needs is live at every member access and costs 1.8× on cfscript
   parse time for 30 nodes in one file. Implemented, measured, reverted.
3. **The two dynamic-tag clusters share a mechanism** — the scanner's tag stack —
   and would sensibly be done together or not at all. 67 nodes across 23 files
   for the riskiest change available is a poor trade on its own.
4. The 304-node tail is not a project. It is 126 files of individually odd code,
   81 of them carrying a single error node.
