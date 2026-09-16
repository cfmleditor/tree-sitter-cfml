# To do

Open work, with enough context to pick any item up cold. Items are ordered by
value per unit of risk, not by size.

Parse gaps are **not** listed here — [`FAILING-PATTERNS.md`](FAILING-PATTERNS.md)
already carries every failing construct with its file count, complexity and risk,
calibrated against changes that have actually landed. Duplicating it here would
guarantee the two drift apart. The two clusters worth doing next are named at the
bottom of that document.

## Audit query coverage, then write the query skill — **deferred**

**Deferred pending the `zed-cfml` audit**, which is covering the same ground from
the other end. Do not start this one in parallel; fold that audit's findings in
when it lands, then decide what is left.

Its evidence is better than what is below. Working through a real editor shows
what actually *looks* wrong — a construct rendering flat, indentation landing in
the wrong column, a fold that will not close. The static check below only shows
what is unreferenced, which is a proxy for that and an imperfect one in both
directions: it flags nodes that need no rule, and it cannot flag a rule that
exists but captures the wrong thing. It also exercises the Zed-specific variants
(`brackets-zed.scm`, `indents-zed.scm`) against the editor that consumes them,
which nothing here does.

What follows stays as the baseline to check the audit against, not as a work
list to start from.

**Why it is worth doing at all:** `.claude/skills/parse-gap/` covers grammar and
scanner work, which
is where most of the churn is (52 changes to `define-grammar.js`,
`cfscript/grammar.js` and `common/scanner.h` over 18 months, against 42 across
all 29 `.scm` files). Query files are the largest part of the repo that no skill
covers, and the only remaining candidate.

**Why it has not been done:** writing the skill first would produce a document
assembled from reading the files, and there is no way to tell that apart from one
written after doing the work — until it misleads someone. `parse-gap` is useful
because it names things that actually broke. A query skill should be written the
same way round: do the audit, fix what it finds, then write down what went wrong.

**The audit.** A crude check — every named, non-underscore node type in
`src/node-types.json` that appears nowhere in that grammar's `queries/*.scm`:

| Grammar | Named types | Unreferenced |
|---|---|---|
| `cfml` | 171 | 60 |
| `cfscript` | 120 | 50 |
| `cfquery` | 152 | 76 |

Treat those numbers as an upper bound, not a defect count. Much of it is correct
by design:

- **Supertypes** (`expression`, `statement`, `declaration`, `pattern`,
  `primary_expression`) are declared in `supertypes:` and never matched directly.
- **Statements whose colour comes from a keyword token** — `break_statement`
  carries an anonymous `"break"` that the highlights already capture, so the
  named wrapper needs no rule of its own.
- **Structural nodes** (`arguments`, `array`, `else_clause`, `catch_clause`)
  carry no colour; their children do. They may still matter to `indents.scm`,
  `folds.scm` and `textobjects.scm`, which is the part worth checking rather
  than assuming.

Separating genuine gaps from those three categories is the work. It is judgement,
not a script — though a script with a curated allowlist for structural nodes
would make the result repeatable, and is probably the right artefact to leave
behind alongside the skill.

One confirmed gap, as a worked example of what the triage is looking for: CDATA
support was added to the grammar in 0.26.24 and 0.26.25 (`<![CDATA[#expr#]]>`,
hash expressions included), but `cdata_section` and `cdata_text` appear in no
query file in any of the three grammars. The parser understands the construct
and an editor renders it as unstyled text — the grammar half shipped and the
query half did not. `xml_decl`, `slice_expression` and `statement_identifier`
look like the same story and are unconfirmed.

**Scope note:** 29 files — ten query types per grammar, nine for `cfquery`,
which has no `injections.scm`. That count includes the Zed-specific variants
(`brackets-zed.scm`, `indents-zed.scm`). `npm test` validates every
`.scm` against its grammar, so a query referring to a node type that does not
exist fails the suite — that check is already in place and does not need
building.

**Not evidence of neglect:** grammar changes ship alongside query changes in 7 of
26 commits. The other 19 are mostly correct, because new rules usually reuse
existing node types — `[=]` reused `ordered_struct`, and the bitwise SQL
operators reused `query_math_expression`. Neither needed a query change.

## Housekeeping

- **Three failing probes have no issue behind them.** `cfml/hash_in_script_string.cfm`
  appears in no document at all; `cfml/prefixed_dynamic_tag.cfm` and
  `cfscript/subscript_multiple_pairs.cfc` are rows in
  [`FAILING-PATTERNS.md`](FAILING-PATTERNS.md) with no tracking issue. This is the
  gap [#118](https://github.com/cfmleditor/tree-sitter-cfml/issues/118) was filed
  to close for its own construct; the same argument applies to these.
- **Split the `cf_selfclose_void_tag_end` naming out of
  [#115](https://github.com/cfmleditor/tree-sitter-cfml/issues/115).** That node is
  the tag-end of *every* `<cfcomponent …>` and `<cfargument …>`, including a bare
  `<cfcomponent>`; a real `/>` is recorded as a `(self_closing_tag_delimiter)`
  child inside it. The tree is right and the name is wrong, which made it look
  like a symptom of that issue's misparse when it is not. A rename touches the
  `.scm` queries and is breaking for consumers, so it needs its own issue.
- **Re-derive the carried-forward counts in `FAILING-PATTERNS.md`.** Two
  dynamic-tag rows are marked "carried forward unverified" because their counts
  came from signature-matching the source rather than from a scan.

## In flight — open issues with a solution not yet merged

**Transient: delete each entry as its pull request lands.** It exists so the
state of a half-finished round is not carried only in someone's head, and so the
corpus and probe numbers quoted elsewhere can be read against the right baseline.

Merged in this round and needing nothing further:
[#118](https://github.com/cfmleditor/tree-sitter-cfml/issues/118) (tag island
after a statement, PR #120) and
[#114](https://github.com/cfmleditor/tree-sitter-cfml/issues/114) (a `<` opening
a run of template text, PR #121).

### [#116](https://github.com/cfmleditor/tree-sitter-cfml/issues/116) — fixed in cfscript, PR pending

An arrow function with an empty body, through an external zero-width marker
offered only before a terminator. +21 states, corpus 640 → 639, zero changed
trees. `common/define-grammar.js` is left alone, so the `<cfset f = function(){
x = () => ; }>` spelling still fails — no corpus occurrence, and the shared
externals list is dialect-conditional.

### [#115](https://github.com/cfmleditor/tree-sitter-cfml/issues/115) — PR #122, open

An unquoted struct as a tag attribute value. **Fixed, not parked:** `{}` joins the
excluded set of the unquoted `cf_attribute_value` token, so
`<cfcomponent javasettings={ … }>` reports an ERROR at the `{` instead of parsing
clean and wrong. Lucee rejects the syntax — `test/tickets/LDEV5763.cfc` asserts
`toThrow` — so refusing is the correct tree, not a gap left open.

No `STATE_COUNT` movement in either grammar; zero changed trees in `treediff`.
**The corpus baseline moves the wrong way on purpose: 640 → 641 error nodes
across 121 → 122 files**, the one new file being the Lucee test that exercises
the construct. Anyone quoting a corpus number after this merges should use 641,
and anyone seeing 641 where they expected 640 is looking at this change.

Pinned by the corpus test `an unquoted struct as a tag attribute value is
rejected (#115)` rather than a probe: `tree-sitter test --update` will not write
an expectation containing an ERROR, so that tree is maintained by hand, and a
probe keyed on error nodes would file the intended answer under "known gap".

Not included, deliberately: the `cf_selfclose_void_tag_end` naming, which that
issue reported as a third symptom and is not one. It is in Housekeeping above.

### [#119](https://github.com/cfmleditor/tree-sitter-cfml/issues/119) — PR #123, open

A start tag whose `>` sits inside a `<cfif>` branch. **Not fixed and not
fixable as specified** — the write-up, the two failing probes and the cost table
are the deliverable, and the issue stays open. The measurements are in
[`FAILING-PATTERNS.md`](FAILING-PATTERNS.md) and `LIMITATIONS.md`; the short
version is that every rule shape that makes the construct parse breaks the
spelling that parses today, because the two diverge in the *lexer* rather than
the parser.

### Merge-order note for these two

Both touch the same list in `LIMITATIONS.md`, and their entries were written as
neighbours before the branches were split. They were separated by keeping each
entry only on its own branch, so either order merges cleanly and no paragraph is
duplicated. If a future split of this kind is needed, do the same thing rather
than letting both branches carry the same text.

## Considered and deliberately not doing

Recorded so they do not get re-proposed and re-argued.

- **A release skill.** `scripts/release.js` already performs the whole sequence —
  build, lint, test, docs WASM, native addon rebuild, commit, tag, push, with npm
  and crates.io handled by the GitHub Release workflow. A skill would restate the
  script and then rot when it changes. The one thing worth knowing is already in
  `CLAUDE.md`: the release needs a `## [version]` or `## [Unreleased]` heading in
  `CHANGELOG.md`.
- **The real-world corpus scan in CI.** It needs ~100 MB of shallow clones and
  about 150 s, and its value is the *diff* between two builds, which a single CI
  run cannot produce. It stays a manual gate, described in
  [`../CORPUS.md`](../CORPUS.md) and in the `parse-gap` skill.
