# Failing patterns

An assessment of every ERROR / MISSING node the three grammars produce over the
real-world corpus, as of `d06ff66`. Method and corpus are described in
[`../CORPUS.md`](../CORPUS.md); reproduce with:

```bash
npm run corpus:fetch && npm run scan corpus > scan.txt
npm run corpus:report -- --from scan.txt
```

> **Since this assessment**, five of the patterns below have been fixed — bare
> `>` / `<` in template text, the empty struct literal `[=]`, the typed `param`
> statement, bitwise operators in SQL, and array return types. They are marked
> **Fixed** in the tables and are covered by `npm run probe`. The corpus now
> reports **990** error nodes; the counts in this section are the original snapshot and have not
> been rebaselined, because the relative sizes are what the priorities below are
> argued from.

## The numbers

| | |
|---|---|
| Files scanned | 12,549 |
| Files parsed with no error at all | 12,456 (**99.3%**) |
| ERROR / MISSING nodes | 1,352 |
| File + grammar pairs carrying at least one | 243 |
| …of which carry exactly one node | 128 |

Split by grammar: **cfscript 729**, **cfml 598**, **cfquery 1**. The `cfquery`
figure is the standout — 2,247 `<cfquery>` bodies in the corpus and a single
failing construct in all of them.

Two properties of this distribution matter more than the total:

**It is extremely concentrated.** Ten files hold 699 nodes — 52% of everything.
A single Mura file (`admin/assets/js/frontendtools.js.cfm`) accounts for 192,
and ColdBox's `PerformanceSuite.cfc` for 186. Fixing either construct would move
the headline number more than fixing the eight most *common* gaps combined.

**Node counts measure blast radius, not defect count.** One unparseable
construct near the top of a file leaves the rest of it unrecoverable, so a
100-node file usually means one defect, not a hundred. Judge a pattern by the
*files* it affects, not by its node count.

## Not grammar defects

Roughly a third of all nodes come from inputs no grammar could reasonably
handle. These are listed first so they do not distort the rest.

### JavaScript served from a `.cfm` template — 279 nodes, 6 files (21%)

```cfml
<cfcontent type="text/javascript"><cfheader name="Expires" value="#getHttpTimeString( now() )#">
/**
* represent a cfform
*/
function LuceeForms( form, onError ) {
	var pub = this;
	...
```

Lucee's `context/form.cfm` and Mura's `*.js.cfm` files are JavaScript delivered
through a CFML template, with no `<script>` element anywhere. Nothing in the text
marks it as JavaScript, so the grammar reads it as template markup and fails on
almost every line. JavaScript inside a real `<script>` element parses fine —
`test/probes/cfml/script_block_js.cfm` covers that.

### Input the CFML engines reject too

```cfml
md.append( "# ColdBox Performance Analysis Report" );   // bare # needs ##
struct persistStruct = structNew()                       // ColdBox Controller.cfc:
boolean ssl,                                             //   missing comma
```

`PerformanceSuite.cfc` alone is 186 nodes from unescaped `#` inside strings. A
CFML engine errors on these as well, so parsing them would mean accepting invalid
input.

## Genuine gaps

Each has a minimal reduction under `test/probes/`, with its status recorded in
`test/probes/expected.json`, so `npm run probe` reports the moment one is fixed
or regresses.

### cfscript

| Pattern | Files | Example | Probe |
|---|---|---|---|
| Script-syntax tag call with space-separated attributes | 17 | `cfdirectory( directory="#dir#" action="create" mode="777" );` | `script_tag_call.cfc` |
| ~~Array return type~~ **Fixed** | 9 | `IValidationError[] function getFieldErrors( required string field );` | `array_return_type.cfc` |
| ~~Empty struct literal~~ **Fixed** | 5 | `var uniqueList = [=];` | `empty_struct_literal.cfc` |
| Subscript as a `var` declaration name | 1 | `var loadArgs[ getPrimaryKey() ] = getValue( x );` | — |
| Dotted key in a struct literal | 1 | `var objects = { obj_a.meta = { … }, obj_b.meta = { … } };` | — |
| Function-listener callback syntax | 1 | `var t = mySuccess():function( result, error ) { … };` | — |
| Subscript index holding more than one pair | 1 | `animals = $[ Aardwolf: "…", aardvark: "…" ];` | `subscript_multiple_pairs.cfc` |

The last four are single-file patterns. The subscript-name case is the largest of
them at 71 nodes (Mura's `beanORM.cfc`) and is the same family as the scoped
`var local.x` support added in `d06ff66` — a `var` declarator accepts a dotted
name but not a bracket subscript.

### cfml

| Pattern | Files | Example | Probe |
|---|---|---|---|
| Dynamic tag name with a static prefix or namespace | 10 | `<h#field.getLevel()#>…</h#field.getLevel()#>`, `<dc:#container#>` | `prefixed_dynamic_tag.cfm` |
| ~~Bare `>` or `<` in template text~~ **Fixed** | — | `<p>a > b</p>`, `#ratio#%  ==>` | `gt_in_text.cfm`, `lt_in_text.cfm` |
| ~~Typed `param` statement~~ **Fixed** | — | `param string url.id default="0";` | `param_typed.cfm` |
| `<script>` opened in one `<cfsavecontent>`, closed in another | 1 | Slatwall `ClientScriptWriter_jQuery.cfc` | — |

The plain `<#expr#>` dynamic tag form parses; only the prefixed and namespaced
variants fail. `_start_tag_name` is an external token and open/close matching
happens in the scanner, so supporting them is scanner work rather than a grammar
rule — which is also why this is the largest remaining real cluster.

### cfquery

| Pattern | Files | Example | Probe |
|---|---|---|---|
| ~~Bitwise `&` in SQL~~ **Fixed** | 1 | `AND status & 2048 = 2048` | `bitwise_and.cfm` |

## What is left over

Signal-matching the failing files by root cause leaves roughly 750 nodes across
188 files unattributed. Spot-checking those shows they are overwhelmingly
*cascades* — the first error is reported at line 1 spanning the whole document,
because an unparseable construct further down cost the parser its tag nesting.
Their real triggers are the patterns already listed above. They are not a
separate population of unknown defects, but neither has every one been traced,
and that should not be implied.

## Cost and risk of fixing each one

Estimates below come from this repository's own history, not from general
intuition. Two of these were attempted during the corpus work and backed out;
several others are close relatives of changes that did land, and those landings
needed follow-up fixes that the corpus scan caught. That record is the best
available guide.

Three properties of this grammar drive most of the risk:

- **Keyword extraction is lexical.** With `word: $.identifier`, a rule that makes
  a keyword valid in a new position changes how that word *lexes* everywhere in
  that state. Adding `member_expression` to `variable_declarator` made
  keyword-led expressions valid after `var`, which silently broke `var new = 1`
  and `for ( var export in … )` until `_reserved_identifier` was named
  explicitly. Any change touching declarations or parameters should expect this.
- **`:` is heavily contested.** It already serves `pair`, `switch_case`,
  `slice_expression` and the ternary. The casing branch removed conflicts around
  it deliberately, and restoring them reintroduces the `case <expr> :` ambiguity.
- **The scanner is shared, except where it is not.** `common/scanner.h` backs
  `cfml` and `cfquery`; `cfscript` has its own hand-written `src/scanner.c`. A
  scanner change means editing one or both, with no generator to check the
  result — the corpus scan is the only safety net.

| Pattern | Complexity | Risk | Basis |
|---|---|---|---|
| Empty struct literal `[=]` — **fixed** | **Low** | **Low** | `ordered_struct` already spells out the sibling form `[ : ]` as a fixed token sequence; `[ = ]` is the same shape. Landed as estimated: one `choice` arm, no conflicts |
| Typed `param` statement — **fixed** | **Low** | **Low** | The untyped form already parses; this adds a type slot to an existing statement rule. Cost the estimate twice over: spelling the type as keyword tokens made `array` lex as a keyword wherever the branch was live, breaking `loop array=data`. A plain identifier in the type slot, distinguished by what follows it, works |
| Bitwise `&` in SQL — **fixed** | **Low-Med** | **Med** | A query-side operator addition, but `&` is CFML's string concatenation, so the two readings meet inside `<cfquery>`. The two never actually met: concatenation only occurs inside `#...#`, which the hash expression grammar handles. `&`, `\|` and `^` joined `query_math_expression` with no fallout |
| Array return type `X[] function` — **fixed** | **Med** | **Med** | Touches the function return-type slot, which already competes with `parameter_type` and `primary_expression`; expect new conflicts, of the kind that took three iterations for member declarations. **Over-estimated**: no conflicts, no iterations. Lexing `[]` as one `token(seq('[', ']'))` rather than two settles subscript-versus-suffix in the lexer, so the ambiguity the estimate feared never reaches the parser |
| Subscript as a `var` name | **Med** | **Med-High** | Directly extends the change that broke `var new = 1`. Same rule, same lexing hazard, and subscripts add `[` ambiguity on top |
| Dotted key in a struct literal | **Med** | **Med-High** | `_property_name` is already in five conflict declarations; widening it to accept paths touches every struct literal and named-argument site |
| Bare `>` or `<` in template text — **fixed** | **Med-High** | **High** | The character that would become text is the one the tag scanner uses to close tags. Getting it wrong destabilises all tag parsing, which is the grammar's core. It did: peeking past `<` consumes it and the scanner cannot rewind, so the first attempt broke every CFML comment. Guarding the peek behind "some text already collected" fixed it, and the corpus scan is what caught it |
| Function-listener `f():callback` | **Med-High** | **High** | Adds another `:` reading to the most contested character in the grammar, for a single-file Lucee feature |
| Script-syntax tag call | **High** | **Med** | **Attempted and backed out.** `f( a=1 [x] )` is ambiguous between a subscript and a second argument; tree-sitter's suggested resolution is a single-rule conflict on `expression`, which cannot be declared. Needs a restricted attribute-value rule instead |
| Subscript with more than one pair | **High** | **High** | Requires re-admitting `pair` inside subscripts, which is exactly the ambiguity the casing branch removed. One file, non-idiomatic syntax |
| Prefixed / namespaced dynamic tag | **High** | **High** | `_start_tag_name` is an external token and open/close matching lives in the scanner's tag stack. Scanner work on the shared header, with no generator check |
| `<script>` unclosed across CF blocks | **High** | **Low value** | **Attempted and backed out.** Making `script_element`'s end tag optional produces unresolvable conflicts. One file, and genuinely unbalanced HTML |

Worth noting what "Low risk" does *not* mean here: every change in this session
that looked self-contained still needed a corpus re-scan to confirm, and three of
them were only saved by that scan. Budget for the scan, not just the edit.

## What this suggests about priorities

1. **Prefixed and namespaced dynamic tag names** — 10 files, the largest genuine
   cluster, and the one that produces the worst cascades in Lucee's admin
   templates. Scanner work.
2. **Script-syntax tag calls** — 17 files, the widest spread. Attempted once and
   backed out: space-separated arguments are ambiguous with subscripts
   (`f( a=1 [x] )`), and tree-sitter's suggested resolution is a single-rule
   conflict that cannot be declared. Needs a restricted attribute-value rule.
3. ~~**Bare `>` in template text**~~ — **done.** No corpus file failed on this
   alone, but it is ordinary HTML and was the likeliest of these to bite an
   editor user. It also turned out to be the single largest win in the corpus:
   329 nodes and 31 files, because a stray `>` derails the rest of a template.
4. Everything else is single-file or nearly so, and worth fixing only if the
   construct is cheap to express.

Work that is not a parse gap — tooling, queries, docs — is tracked separately in
[`TODO.md`](TODO.md).

Crossing that list with the cost table gave a different order for anyone wanting
value per unit of risk, and that is the order actually taken: `[=]`, typed
`param` and bitwise `&` were cheap and safe but affect few files; bare `>` was
riskier and paid for itself many times over; array return types were the best of
what was left, at 9 files for a two-line change. What remains is the
script-syntax tag call — the widest-reaching fix still tractable with
grammar-only changes — and prefixed dynamic tag names, the largest cluster but
the most dangerous, because they mean editing the shared scanner.
