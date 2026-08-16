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
| Five CFScript constructs the embedded grammar already has | **Low** | **Med** | Not new features — a port of rules that already exist and are already tested in `common/define-grammar.js`, so the shape of each answer is known before starting. The Med is because four of the five touch parameter lists and `param`, where keyword extraction is lexical and the blast radius is the whole of statement position. Do them one at a time against `npm run bench`, not as one change. See the RustCFML section of [CORPUS.md](../CORPUS.md), and [#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49), [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50), [#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51), [#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52), [#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53) |
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
| `''` in a single-quoted tag attribute | Low / Low | **Accurate, and the first estimate on this page to be exactly right.** One `choice` arm mirroring `'""'`, no conflicts, `cfscript/src/parser.c` byte-identical. The one non-obvious risk was not in the estimate: a `''` token could out-lex the closing quote and break the *empty* value `default=''`. It does not — the double-quoted branch has faced the same longest-match question since it was written — but that is the case the new corpus test pins, not the one from the issue |
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
