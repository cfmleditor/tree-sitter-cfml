# Failing patterns

An assessment of every ERROR / MISSING node the three grammars produce over the
real-world corpus, as of `d06ff66`. Method and corpus are described in
[`../CORPUS.md`](../CORPUS.md); reproduce with:

```bash
npm run corpus:fetch && npm run scan corpus > scan.txt
npm run corpus:report -- --from scan.txt
```

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
| Array return type | 9 | `IValidationError[] function getFieldErrors( required string field );` | `array_return_type.cfc` |
| Empty struct literal | 5 | `var uniqueList = [=];` | `empty_struct_literal.cfc` |
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
| Bare `>` or `<` in template text | — | `<p>a > b</p>`, `#ratio#%  ==>` | `gt_in_text.cfm`, `lt_in_text.cfm` |
| Typed `param` statement | — | `param string url.id default="0";` | `param_typed.cfm` |
| `<script>` opened in one `<cfsavecontent>`, closed in another | 1 | Slatwall `ClientScriptWriter_jQuery.cfc` | — |

The plain `<#expr#>` dynamic tag form parses; only the prefixed and namespaced
variants fail. `_start_tag_name` is an external token and open/close matching
happens in the scanner, so supporting them is scanner work rather than a grammar
rule — which is also why this is the largest remaining real cluster.

### cfquery

| Pattern | Files | Example | Probe |
|---|---|---|---|
| Bitwise `&` in SQL | 1 | `AND status & 2048 = 2048` | `bitwise_and.cfm` |

## What is left over

Signal-matching the failing files by root cause leaves roughly 750 nodes across
188 files unattributed. Spot-checking those shows they are overwhelmingly
*cascades* — the first error is reported at line 1 spanning the whole document,
because an unparseable construct further down cost the parser its tag nesting.
Their real triggers are the patterns already listed above. They are not a
separate population of unknown defects, but neither has every one been traced,
and that should not be implied.

## What this suggests about priorities

1. **Prefixed and namespaced dynamic tag names** — 10 files, the largest genuine
   cluster, and the one that produces the worst cascades in Lucee's admin
   templates. Scanner work.
2. **Script-syntax tag calls** — 17 files, the widest spread. Attempted once and
   backed out: space-separated arguments are ambiguous with subscripts
   (`f( a=1 [x] )`), and tree-sitter's suggested resolution is a single-rule
   conflict that cannot be declared. Needs a restricted attribute-value rule.
3. **Bare `>` in template text** — no corpus file fails on this alone, but it is
   ordinary HTML and the most likely of these to bite an editor user.
4. Everything else is single-file or nearly so, and worth fixing only if the
   construct is cheap to express.
