# Grammar and scanner review — September 2026

A review of the three grammars (`common/define-grammar.js`, `cfscript/grammar.js`)
and both external scanners (`common/scanner.h`, `cfscript/src/scanner.c`) at
`639d4e2` (v0.26.36), looking for improvements in grammar support and in
performance.

Everything here that carries a number was **measured**, not estimated: each
recommendation was prototyped in a scratch worktree and put through the gate the
`parse-gap` skill describes — `npm run build`, `npm test`, `npm run probe`, a
full corpus scan diffed against the baseline, `npm run treediff` against the
committed parser, and `STATE_COUNT` / `parser.c` size. Performance was measured
with `npm run bench`, interleaved ABCCBA. None of the prototypes is committed;
this document is the deliverable. The corpus was a fresh `npm run corpus:fetch`
(47 repositories, 15,530 files); the baseline scan reports 422 error lines
across 112 files.

The docs already carry an unusually complete record of what fails and why, so
this review deliberately does not re-cost anything in
[`FAILING-PATTERNS.md`](FAILING-PATTERNS.md) or re-open anything in the
"considered and deliberately not doing" list in [`TODO.md`](TODO.md). Where a
finding here changes the explanation of an existing entry, it says so.

## Summary

| # | Recommendation | Kind | Measured effect | Cost | Risk |
|---|---|---|---|---|---|
| 1 | One case-insensitive regex per keyword, hoisted above `identifier`, and drop the JS `\uXXXX` escape from `identifier` | size, perf, support | `parser.c` **−27%** across the three grammars (48.4 → 35.3 MB), `STATE_COUNT` −10.5% / −8.7% / −4.2%, addon 10.1 → 6.8 MB; **zero** tree changes over 14,177 files; `reTURN` now a keyword | ~130 lines, mostly moved | Low, with one guard (below) |
| 2 | CFML operator precedence: `&`, `^`, `NOT`/`!`, `XOR`, `IS NOT`, `EQV`/`IMP` | support (wrong trees) | 81 corpus files carry a mis-nested expression today; +154 / +154 / +176 states | ~40 lines | Med: published tree-shape change |
| 3 | Automatic semicolon before a line-leading `IS`, `CONTAINS`, `XOR`, `IN`, … | support (wrong trees) | silent split into a `tag_statement` today | scanner only | Low |
| 4 | Give the `cfml` scanner an explicit error-recovery policy | recovery quality, perf | naive version: ERROR-covered bytes **−22%**, error lines 422 → 365, `debug/Simple.cfc` 40,907 bytes of ERROR → 0 | scanner only | Med: 7 files regress in the naive version |
| 5 | `#` in template text is only an expression inside `<cfoutput>` | support | the real cause of `debug/Simple.cfc`'s residual errors | scanner | Med: semantic |
| 6 | Stop carrying a full CFScript statement grammar in `cfml` and `cfquery` | size | trimming it to the six statement kinds the corpus uses: **−16% / −19%** states | design choice | Med |
| 7 | Smaller scanner fixes | support, robustness | see section | a few lines each | Low |
| 8 | CI: state-count budget and a keyword-extraction check | process | automates the #75 lesson | small script | None |

Performance figures for #1 and #4 are in [Benchmark](#benchmark).

---

## 1. Keyword tokens: one case-insensitive regex each

### What is there

`keyword('Break')` expands to `alias(choice('Break', 'break', 'BREAK'), 'break')`
— three or four **separate terminal symbols** per keyword, each carrying its own
column in the parse table and its own action in every state where the keyword is
valid. With 45 keywords that is about a third of the token set (the change below
takes `cfscript` from 268 tokens to 175):

| | `TOKEN_COUNT` | `LARGE_STATE_COUNT` / `STATE_COUNT` |
|---|---|---|
| `cfml` | 327 | 2,814 / 5,494 (51%) |
| `cfquery` | 284 | 2,770 / 4,152 (67%) |
| `cfscript` | 268 | 3,954 / 5,511 (**72%**) |

A "large" state is one with more than 64 actions, stored as a dense row of
`SYMBOL_COUNT` entries. Every expression-start state has ~20 keyword-led
alternatives (`new`, `function`, `this`, `true`, the reserved identifiers, …), and
at 3–4 casings each those alone come close to the threshold. Measured below, the
casings account for a little over a quarter of every grammar's `parser.c`.

### What to do

Three changes, all needed together — each of the first two on its own is worse
than doing nothing:

1. **`keyword()` returns one token**: a character-class regex such as
   `/[bB][rR][eE][aA][kK]/`, wrapped in `token(prec(1, …))` and aliased to the
   same node name as today.
2. **Every `keyword()` rule is defined before `identifier`** — the `_kw_*` block,
   `this`/`super`/`true`/`false`/`null`/`undefined`, and new `_kw_query`,
   `_kw_queryexecute` and `_kw_required` rules replacing the inline
   `keyword('Query')` etc.
3. **`identifier` loses its JavaScript `\uXXXX` / `\u{…}` escape alternatives**,
   which CFML does not have.

And one consistency fix the change exposes in `common/define-grammar.js`:
`method_definition` spells `'get'`/`'set'` and `_for_header` spells `'let'` as
plain strings while `_reserved_identifier` uses `keyword('Get')` etc. With string
casings those unified into one token; with a regex they are two tokens matching
the same text, and `<cfset x = { get=false }>` (Taffy's dashboard) stops parsing.
Spelling them `$._kw_get`, `$._kw_set`, `$._kw_let` fixes it — the same
"never spell a keyword two ways" rule the `_kw_*` block's own comment states.

### Why each piece is needed

This was found the slow way and is worth recording, because the obvious version
fails badly and the reasons are not in the tree-sitter docs.
`tree-sitter generate --log` prints every keyword-extraction decision
(`grep Keywords`), which is how each step below was diagnosed.

| attempt (cfscript) | `keyword()` words extracted, of 45 | `STATE_COUNT` | tests |
|---|---|---|---|
| base (string casings) | 29 (as 88 casing tokens) | 5,511 | pass |
| plain regex, rules where they are today | 0 | 4,877 | **149 fail** |
| + hoisted above `identifier` | 0 | 7,765 | pass |
| + `token(prec(1, …))` | 29 | not built | — |
| + no `\u` escape in `identifier` | **45** | **5,281** | pass |

The 4,877 in the second row is not a saving: with nothing extracted, every
keyword is a plain regex competing with `identifier` in the main lexer, and 149
corpus tests fail. The 7,765 in the third row is what that costs once the tests
pass — states that cannot merge because their keyword tokens now conflict.

- **A regex only becomes a keyword candidate if it beats `identifier` on a
  same-length match.** Strings win that tie by specificity; two regexes tie on
  *rule order*, and the `_kw_*` block sits at the end of the grammar, after
  `identifier`. Hence the hoist.
- **Hoisted, they are candidates but are all excluded as "matching the same
  string as `regex_flags`"** — the `/[a-z]+/` flags token of the JavaScript regex
  literal that [#94](https://github.com/cfmleditor/tree-sitter-cfml/issues/94)
  keeps. An explicit `prec(1)` wins that tie outright.
- **Sixteen keywords were never extracted, even in the base grammar**: `else`,
  `elseif`, `catch`, `finally`, `in`, `instanceof`, `of`, `while`, `function`,
  `static`, `final`, `abstract`, `public`, `private`, `package`, `remote` (in
  every casing). The log says "because of conflict with `\`". `identifier`
  accepts `A`, so it can start with a backslash, which collides with the
  `\` integer-division operator in exactly the states that follow an
  expression — where those sixteen live. Today they survive as plain strings in
  the main lexer. After the change they would be `prec(1)` regexes in the main
  lexer, which is **the out-lexing hazard `LIMITATIONS.md` warns about**
  (`while_value` → `while` + `_value`). Removing the escape makes all sixteen
  extractable, and the hazard cannot occur for an extracted keyword: the keyword
  lexer only runs after `identifier` has matched the whole word.

That last point is the one to hold on to, and it is also the correction to
`LIMITATIONS.md`'s "never write a keyword as `token(prec(1, /…/))`": the rule is
right for a token that fails extraction, and wrong for one that is extracted.
The recommendation is safe **exactly as long as every keyword is extracted** —
which is why [#8](#8-ci-checks) proposes a check for it.

### Result

| | base | after | Δ |
|---|---|---|---|
| `cfml` states | 5,494 | 4,918 | −10.5% |
| `cfquery` states | 4,152 | 3,792 | −8.7% |
| `cfscript` states | 5,511 | 5,281 | −4.2% |
| `cfml` / `cfquery` / `cfscript` large states | 2,814 / 2,770 / 3,954 | 2,167 / 2,191 / 2,923 | −23% / −21% / −26% |
| `cfml/src/parser.c` | 14.8 MB | 10.6 MB | −28% |
| `cfquery/src/parser.c` | 13.4 MB | 9.9 MB | −26% |
| `cfscript/src/parser.c` | 20.3 MB | 14.8 MB | −27% |
| Node addon (all three) | 10.1 MB | 6.8 MB | −33% |

- `npm test` 353/353, `npm run probe` no drift, corpus scan identical except one
  recovery-position shift inside `debug/Simple.cfc` (a known-bad file).
- `npm run treediff`: **no tree shape changed** in 5,235 `cfml` and 8,942
  `cfscript` files.
- Every hazard spelling in `LIMITATIONS.md` and `hazards.md` parses as before —
  `while_value = 1;`, `x = functionalImpact;`, `function f(array inStock)`,
  `elsewhere = 1` after an `if`.
- **Support gain, free:** keywords become fully case-insensitive, as CFML is.
  `reTURN x;` was a `tag_statement` and is now a `return_statement`; the
  "Keyword casing coverage" limitation goes away.

Every binding compiles `parser.c`, so the size cut reaches every consumer —
including the WASM build an editor downloads — and roughly 13 MB comes out of
the committed tree.

**Stop rule:** if any `_kw_*` token shows up in an `exclude` line of
`generate --log`, do not ship until it is extracted again.

---

## 2. CFML operator precedence

### What is there

The binary-operator table is `tree-sitter-javascript`'s, with CFML's word
operators slotted into it. Several CFML operators land at JavaScript's
precedence for the same character, which is not CFML's. Lucee 6.2's
`AbstrCFMLExprTransformer` fixes the order, lowest to highest:

```
ternary, elvis  →  IMP  →  EQV  →  XOR  →  OR ||  →  AND &&  →  NOT !
                →  comparisons (EQ … IS, IS NOT, CONTAINS, ==, <, …)
                →  &  →  + -  →  MOD %  →  * / \  →  ^  →  unary
```

This matches Adobe's documented precedence table. Every word operator there is
matched with `forwardIfCurrentAndNoWordAfter` — a word-boundary check, which is
what the grammar's multi-word regexes lack (see `IS NOT` below). The grammar differs in five
places, each an error-free wrong tree today:

| input | today | CFML |
|---|---|---|
| `a & b EQ c` | `a & (b EQ c)` — `&` is JS bitwise AND, below comparison | `(a & b) EQ c` |
| `2 ^ 3 * 2` | `2 ^ (3 * 2)` — `^` is JS XOR | `(2 ^ 3) * 2`, exponentiation |
| `NOT a EQ b` | `(NOT a) EQ b` | `NOT (a EQ b)` — `notOp` sits *below* `decsionOp`, for `!` too |
| `a XOR b OR c` | `(a XOR b) OR c` | `a XOR (b OR c)` |
| `a IS NOT b` | `a IS (NOT b)`, i.e. `a == !b` | `a NEQ b` (`decsionOp`, `is` then `not`) |

And two operators are missing: `a EQV b` and `a IMP b` produce an ERROR and a
silent `MISSING ";"` split respectively (no corpus file uses either).

The `!` row is the surprising one: in Lucee, `!a == b` is `!(a == b)`. The
corpus test `common: word operators in a cfif` currently pins
`AND NOT f GTE g` as `(NOT f) GTE g`, so the suite asserts the wrong tree.

### What to do

A prototype that re-orders the ladder to Lucee's, moves `&` to a new
`binary_concat` level, `^` to `binary_exp`, `MOD`/`%` to `binary_mod`, splits
`unary_expression` so `!`/`NOT` sit at a `logical_not` level between comparison
and `AND`, and adds `EQV`, `IMP` and `IS NOT` rows, generates with **no new
conflicts** and costs **+154 / +154 / +176 states** (≈3%). It changes the tree of
**81 corpus files** (21 `cfml`, 60 `cfscript`) — each one a silent misparse
today — introduces no new ERROR, and updates exactly two corpus tests (the one
above, and `cfif elseif with incomplete operator fragments`).

**`IS NOT` must not be a multi-word regex.** The prototype's
`/[iI][sS]\s+[nN][oO][tT]/` lexes `x is nothing` as `x IS NOT hing`. The same
latent hazard already sits in `does not contain` and `not equal`. Either spell it
as two tokens in the rule (`IS` then `NOT` inside one `binary_expression` arm,
with a precedence to beat the unary reading), or give it an external token with
the word-boundary check `scan_java_or_cfml_word` already does.

This is a published tree-shape change of the same kind as the
`parameter_type` unification — mechanical, one direction, and it corrects the
tree — so it wants a changelog note rather than a major version.

---

## 3. Automatic semicolon before a line-leading word operator

Both scanners suppress ASI before a line that starts with a CFML word operator,
so a multi-line condition stays one expression. The list is short, and one case
is lowercase only:

```c
case 'i':            // no 'I'
case 'a': case 'A': case 'o': case 'O': case 'e': case 'E':
case 'n': case 'N': case 'g': case 'G': case 'l': case 'L': case 'm': case 'M':
    return !scan_cfml_word_operator(lexer);   // and, or, eq, neq, not, gt, gte, ge, lt, lte, le, mod, in, instanceof
```

So these all parse **cleanly and wrong** — the continuation line becomes a
`tag_statement`:

```cfml
x = a
  IS b;          // (expression_statement …) (tag_statement tag: IS name: b)
x = a
  CONTAINS b;    // same
x = a
  XOR b;         // same
x = a
  IN b;          // same — uppercase I is not in the switch
```

Missing: `is`, `xor`, `eqv`, `imp`, `contains`, `ct`, `nct`, `equal`, `does not
contain`, `greater than`, `less than`, `not equal`, and uppercase `I`.
`scan_parameter_separator` in the same file already carries most of this list
for the same reason (`"is", "isnot", "contains", "xor", "imp", "does",
"greater", "less", "equal"`), so the two lists should be one table. Line-leading
operators are uncommon in the corpus, but the failure is silent. Scanner only, no
state change.

---

## 4. Error recovery in the shared scanner

### What is there

In error recovery tree-sitter marks every external token valid (the
`[1] = { … }` row of `ts_external_scanner_states` in `cfml/src/parser.c` lists
all 57). The `cfml` dispatcher then reaches this before any tag, text or
implicit-end-tag branch:

```c
if (VS(valid_symbols, CF_XML_CONTENT, count)) {
    return scan_cfxml_content(scanner, lexer, is_cfquery_context);
}
```

`scan_cfxml_content` returns `false` at once unless the innermost CF tag is
`<cfxml>`, and the `return` makes that the scanner's answer. So **in recovery the
`cfml` scanner never produces a tag name, a close delimiter, `html_text` or an
implicit end tag**. It is an accidental recovery policy — nothing documents it,
and the `CF_QUERY_CONTENT`, `CF_SCRIPT_CONTENT` and `CF_SAVECONTENT_CONTENT`
branches below it are shaped the same way. Recovery has to resynchronise on
internal tokens alone, which is why a single local error so often turns into a
file-wide ERROR from `1:1`.

### Measured

Changing the four branches to `if (VS(…) && scan_…(…)) return true;` —
falling through when the scan declines. Outside recovery that is inert: the
generated table makes each content token valid only beside the `cf_comment`
extra (external states 30, 40, 41, 42), in a state the parser reaches only after
the matching open tag, where the scan succeeds. The one corpus test that moves is
#115's, whose expected tree is an error-recovery tree.

| | base | fall-through |
|---|---|---|
| corpus error lines | 422 in 112 files | 365 in 112 files |
| bytes inside ERROR nodes, over the 65 failing `cfml` files | 491,801 | **382,738 (−22%)** |
| files better / worse / same (by ERROR bytes) | | 25 / 7 (two of them by one byte) / 33 |
| `lucee/…/admin/debug/Simple.cfc` | 71 errors, **40,907 of 40,907 bytes** in ERROR | 2 `MISSING "#"`, 0 bytes |
| `lucee/…/context/form.cfm` | 18,824 bytes | 297 |
| `MuraCMS/…/comments/index.cfm` | 17,675 bytes | 4,740 |

The seven that get worse are the reason not to ship the naive version:
Slatwall's `ClientScriptWriter_qForms.cfc` (107 → 3,535 bytes, the whole file),
Mura's `frontendtools.js.cfm` (20 → 838), `variation.js.cfm` (1 → 129),
`dsp_tab_usage.cfm` (1 → 17), and Lucee's `LDEV5763_tag_unquoted_struct.cfc`
(10 → 42, and the #115 corpus test, whose error tree is hand-maintained).

### What to do

Make the policy explicit. Detect recovery the way `references/scanner.md`
recommends (count the valid symbols), and decide per branch what recovery may
use. The natural first cut is: tag names, close delimiters and implicit end tags
yes — they are what lets recovery re-find the document structure — and the
to-delimiter content scans no, since those are the ones that run to EOF. Then
compare against the seven regressions above. `npm run bench`'s error-recovery
split is the other gate; see [Benchmark](#benchmark).

**This re-diagnoses a row in `FAILING-PATTERNS.md`.** "CSS in `<style>` with
many `#` tokens — 71 nodes, 1 file — does not reduce below 20 lines" is two
stray `#` characters (next section) whose errors recovery cannot contain. With
recovery able to see tags, the whole file parses except those two points. It
resisted reduction because the cascade, not the trigger, was what the reduction
was preserving.

---

## 5. `#` in template text outside `<cfoutput>`

`scanner_in_hash_eval_context` treats `#` in template text as opening an
expression whenever the scanner is inside `<cfoutput>`, **`<cfcomponent>`, or
`<cffunction>`**. CFML evaluates `#…#` in template text only inside
`<cfoutput>`; in a tag-based function body outside it, `#` is literal text. Today:

```cfml
<cfcomponent><cffunction name="f"><p>Use #hex colours</p></cffunction></cfcomponent>
    → the whole component is one ERROR
<cfcomponent><cffunction name="f"><a href="#top">x</a></cffunction></cfcomponent>
    → (hash_expression (identifier) (MISSING "#"))
```

Those are the two errors left in `debug/Simple.cfc` once recovery is fixed —
`#-lucee-debug .collapsed { … }` in a `<cfif>` inside `<style>`, in a component
with no `<cfoutput>` around it — and one in Lucee's `CodeIsland.cfc`. Visible
errors are rare because the construct is usually inside a `<cfoutput>`; the
larger effect is silent, since `<div>#x#</div>` in a function body outside
`<cfoutput>` is highlighted as an expression the engine will print literally.

Worth confirming against Lucee before changing, since it alters trees: it was
read from the language rules, not run on an engine. If it holds, dropping the
two depth conditions is the fix, and `cfcomponent_depth` / `cffunction_depth`
may then have no other reader.

---

## 6. CFScript statements inside `cfml` and `cfquery`

`common/define-grammar.js` carries a full CFScript statement grammar. `<cfscript>`
bodies and script components are opaque and injected into `cfscript`, so these
rules are reachable only through a function literal inside a tag expression —
`<cfset f = function() { … }>`, or `#…#` inside SQL for `cfquery`.

What the `cfml` grammar actually produces across every tag-based corpus file:

| node | count | files |
|---|---|---|
| `function_expression` | 18 | 13 |
| `arrow_function` | 5 | 5 |
| `return_statement` | 27 | 14 |
| `if_statement` | 6 | 1 |
| `variable_declaration` | 4 | 2 |
| `for_in_statement` | 1 | 1 |
| `for`, `while`, `do`, `switch`, `try`, `throw`, `break`, `continue`, `labeled`, `with`, `import` | **0** | 0 |

Cutting `statement` to the six kinds in the upper half of that table takes `cfml`
from 5,494 to **4,623 states (−16%)** and `cfquery` from 4,152 to **3,368
(−19%)**, and makes three declared conflicts unnecessary. That is the size of the
prize. Simply dropping the statements is not the recommendation — a `for` loop in
a `<cfset>` closure is valid CFML, and prevalence is not cost. Two better shapes:

- **Inject the closure body.** Lex the `{ … }` of a function literal in a tag
  expression as one opaque token and inject `cfscript`, exactly as `<cfscript>`
  bodies are handled. The brace walker exists: `scan_java_class_content` in
  `cfscript/src/scanner.c` already balances braces around strings and comments.
  Full support is kept, and both tables lose most of the statement grammar. The
  risk is the usual scanner one — guard it in recovery.
- **At minimum, drop function literals from `cfquery`.** A closure in a `#…#`
  inside SQL is not a real construct, and that grammar pays for the whole
  statement set to reach it.

This compounds with #1; the two were measured separately.

---

## 7. Smaller scanner fixes

- **`queryExecute('…')` never produces a `query_expression`.** `scan_query_text`
  stops only at `"`, so the single-quoted arm of `query_expression` can never
  complete and GLR falls back to a plain call — no SQL injection for 13 corpus
  calls (against 425 double-quoted). A doubled `""` inside double-quoted SQL
  falls back the same way. Two external tokens, one per quote, fix both.
- **`QUERY_TEXT` has no recovery guard** in `cfscript/src/scanner.c`, unlike the
  three to-delimiter scans above it. In recovery it runs to the next `"` and can
  return a `query_text` token from anywhere. Add the same
  `!valid_symbols[AUTOMATIC_SEMICOLON]` stand-down.
- **Close-tag matching does not restart on `<`.** `scan_cfquery_content`,
  `scan_cfxml_content`, `scan_cfscript_content` and `scan_raw_text` reset the
  match and advance past the mismatching character, so `<` immediately before
  the close tag hides it: `<cfscript>x = 1 <</cfscript><p>after</p>` is one
  ERROR to EOF. Rare, but the failure is the rest of the document. Re-test the
  current character against `end_delimiter[0]` after a reset.
- **`scan_automatic_semicolon` in `common/scanner.h` compares a
  `WhitespaceResult` with `true`/`false`.** `result == true` is `NO_NEWLINE`,
  where the `cfscript` copy tests `ACCEPT`. No observable difference was found,
  but the two copies disagree and one of them is comparing an enum to a bool.
- **`does not contain` has drifted**: `\s` between the words in `cfscript`,
  `\s+` in `common/define-grammar.js`.

---

## 8. CI checks

- **A state-count budget.** The `STATE_COUNT` check the skill asks for after the
  #75 incident is manual. `check-generated.js` already parses the table
  constants; printing `STATE_COUNT`, `LARGE_STATE_COUNT` and `parser.c` size
  against the base branch in the PR summary, and failing above a threshold
  (say +5%) without a label, makes the deterministic two-second check impossible
  to forget.
- **A keyword-extraction check**, if #1 lands: run `tree-sitter generate --log`
  and fail on any `Keywords - exclude _kw_…` line. That is the one way #1 can go
  wrong, and it is invisible to every other gate until a longer identifier gets
  split.

---

## Benchmark

`npm run bench`, `--reps 5` per run, runs interleaved A B C C B A A B C C B A
(A = base, B = #1, C = #4 naive fall-through), minimum across runs, on a 4-core
shared container. Read the spread before the deltas.

_Filled in below from the run._

---

## Not covered

- Query files (`queries/*.scm`) — deferred in `TODO.md` pending the `zed-cfml`
  audit.
- The cost and risk table in `FAILING-PATTERNS.md`, apart from the one
  re-diagnosis in #4.
- Anything requiring a running engine; the precedence order was taken from
  Lucee's source, and #5 from the language rules.
