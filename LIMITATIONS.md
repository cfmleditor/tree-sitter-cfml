# Known Limitations

Each limitation below that was found by scanning public CFML code has a minimal
reproduction in `test/probes/`; see [CORPUS.md](CORPUS.md) for how that corpus is
fetched and what it turned up. `npm run probe` reports the current status of all
of them.

## cfscript

### Keyword casing coverage

CFML keywords are case-insensitive. Keywords are written in **PascalCase** in
the grammar (`Break`, `QueryExecute`, `<Cf`) and go through the `keyword()`
helper, which enumerates the accepted casings as plain string literals and
aliases them back to a canonical node name.

The one PascalCase spelling yields every real-world form:

| form | `Break` | `QueryExecute` |
|------|---------|----------------|
| PascalCase (as written) | `Break` | `QueryExecute` |
| lowercase | `break` | `queryexecute` |
| UPPERCASE | `BREAK` | `QUERYEXECUTE` |
| camelCase | `break` | `queryExecute` |

Interior mixed casing (`reTURN`, `vAr`) is **not** matched and parses as an
identifier. This is deliberate — it does not occur in real code, and
enumerating 2^n variants inflates the lexer for no benefit.

The node name is `lowerFirst(word)`, so `.scm` queries keep matching
(`"break"`, `"queryExecute"`) regardless of the casing in the source.

#### `<Cf` needs an explicit node name

`lowerFirst` is `word.charAt(0).toLowerCase() + word.slice(1)`, so for a token
starting with punctuation it is a no-op: `'<Cf'` would stay `<Cf` and rename the
node, breaking `brackets-zed.scm` and `indents-zed.scm` which match `"<cf"`.
Those two tokens therefore pass the node name explicitly:

```js
_cf_open_tag:  $ => prec.right(1, keyword('<Cf', '<cf')),
_cf_close_tag: $ => prec.right(1, keyword('</Cf', '</cf')),
```

This is a known, deliberate decision. Any future keyword whose first character
is not a letter needs the same treatment.

#### `keyword()` vs. case-insensitive regex — which to use

Both mechanisms exist on purpose and are **not** interchangeable. Do not
"consistency-fix" one into the other; each is a regression in the other's
territory.

| | `keyword('Word')` | regex char class `/[wW][oO].../` |
|---|---|---|
| **use when** | the token competes with `identifier` in the same position, **or** a `.scm` query matches its literal | operator or SQL token that cannot collide with an identifier, or whose node name is uniform anyway |
| **gives you** | eligible for keyword extraction; stable node name via the alias | full 2^n casing coverage; one compact DFA |
| **costs you** | only 4 casings (see above) | no keyword extraction; node name varies with the matched text |

**Never** write a keyword as `token(prec(1, /[rR][eE].../))`. Such a token is
not eligible for keyword extraction, and the explicit precedence overrides
longest-match, so it out-lexes a *longer* identifier wherever the keyword is
valid: `while_value = 1;` parses as `while` + `_value`, and
`<cfset x = functionalImpact>` as `function` + `alImpact`.

The regexes currently in the grammar are all correctly on the regex side:

- **word operators** (`eq`, `is`, `neq`, `ct`, `gt`, `gte`, `contains`,
  `does not contain`, …) — bare regexes with no explicit precedence, so
  longest-match protects identifiers. Verified: `containsKey`, `eqValue`,
  `isValue`, `gteLimit`, `notFlag`, `modValue`, `greaterThanY` all parse
  correctly. No query matches an operator literal, so the alias would buy
  nothing, and converting would *lose* casings that work today such as `eQ`
  and `DoEs NoT cOnTaIn`.
- **SQL tables** (`query_keyword`, `query_function_name`) — `token(choice(...))`
  with no precedence, and every alternative collapses into the single
  `query_keyword` node, so the node name does not vary by which alternative
  matched. Identifiers like `orders` and `selected_items` are safe.
- **multi-word tokens** (`static get`, `does not contain`) — contain mandatory
  `\s+`, so they can never be a subset of the identifier token and the
  collision hazard does not exist.

Two entries sit deliberately on the other side: `$._kw_instanceof` and
`$._kw_in` are `keyword()` rules *inside* the operator table, because unlike
`eq` or `ct` they are real keywords that also appear in identifier position
elsewhere and are matched by the highlight queries.

Covered by `cfml/test/corpus/case_insensitivity.txt`,
`cfscript/test/corpus/case_insensitivity.txt` and the keyword-prefix tests in
`cfquery/test/corpus/cfquery.txt`.

### `function` as an identifier

`f(function=1)` and `x = function.foo` do not parse — `function` is not in
`_reserved_identifier`.

It was deliberately left out. Adding it does make those forms parse, but it also
makes the bare statement `function;` parse, which is not valid CFML, and it
costs a further 8 GLR conflicts and ~4% parser size. A variable named `function`
is rare enough that the trade is not worth it.

`import` needs no such entry: keyword extraction already lets it fall back to an
identifier wherever the `import` statement is not valid, so `x = import.foo`
parses as an ordinary member expression.

### Bare reserved words parse as expressions

`new;`, `static;`, `public;`, `final;` and the other `_reserved_identifier`
words parse as a bare expression statement even though CFML does not accept
them. The grammar is deliberately permissive here: these words must stay usable
as ordinary identifiers (`static['key']`, `query.newQuery()`), and the parser
does not distinguish the standalone case.

### Space-separated arguments are accepted on any call

`f( a=1 b=2 )` parses even though `f` is not a CF tag, and a CFML engine would
reject it. Restricting the form to `cf`-prefixed callees would need a token
matching `cf\w+`, which is a subset of `identifier` and would out-lex ordinary
identifiers wherever it is valid — the hazard described above under
`keyword()` vs. regex. The grammar is deliberately permissive here, as it is
with bare reserved words.

## cfml

### IE conditional comments

`<!--[if gt IE 8]><!-->` is parsed as a comment node. The expression inside (`gt IE 8`) is not evaluated — it's treated as comment content.

### `<cfprocessingdirective>` implicit close

`<cfprocessingdirective>` can be used with or without a body. When used without a closing tag, the grammar treats it as a paired tag and consumes content until EOF or another implicit close trigger. Use self-closing syntax (`/>`) for bodyless usage.

`<cfsetting>` is now a void tag — `</cfsetting>` never appears in the 12,549-file corpus, while `<cfsetting …>` appears 336 times — so it no longer swallows the rest of the template.

### Dynamic tag names not fully evaluated

`<#expr#>` dynamic tag names are parsed and the hash expression is evaluated, but the scanner consumes the expression content for tag matching purposes. Open/close matching works positionally (any dynamic open matches any dynamic close).

## cfquery

### `queryExecute` with non-string first argument

`queryExecute(variable)` or `queryExecute(condition ? "sql1" : "sql2")` falls through to a regular function call (no SQL parsing). Only `queryExecute("SELECT ...")` with a string literal first argument gets SQL injection parsing.

### `+` before `<cfif>` blocks

The `+` concatenation operator allows an optional right operand to support patterns like `col1 + <cfif x>col2 + </cfif>col3`. This means a trailing `+` without a right operand won't produce a parse error.

## Constructs found in public CFML that do not parse

These come from the corpus scan described in [CORPUS.md](CORPUS.md). Each has a
probe under `test/probes/`, and `npm run probe` reports the moment one is fixed
or regresses. [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md) has the full
assessment, including how many files each affects and what fixing it would cost.

### cfscript

- **Script-syntax tag calls where the *first* separator is a comma** — `cfdirectory(action="list", directory=trg, name="x" recurse=true)` (Lucee tests). The space-separated form parses, including calls that switch to commas after the first junction (`cflog(file="#n#" text="t", type="error")`). Requiring the space at the first junction is what keeps the rule unambiguous with an ordinary comma-separated call; 11 calls across 4 files put a comma there instead.
- **Dotted key in a struct literal** — `var objects = { obj_a.meta = { … }, obj_b.meta = { … } };` (Preside tests). Cheap to implement and implemented once, but the conflict it needs is live at every member access and cost 1.8× on cfscript parse time for 30 nodes in one file, so it was reverted. See the cost table in [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md).
- **Subscript index holding more than one pair** — `animals = $[ Aardwolf: "…", aardvark: "…" ];` (Lucee tests). Note that the single-pair form is **not** support but a misparse, which matters for [#80](https://github.com/cfmleditor/tree-sitter-cfml/issues/80) below: `$[ b: "x" ]` yields a `subscript_expression` whose object is the identifier `$` and whose index is a `slice_expression`. There is no ordered-struct literal rule at all.
- **The `${ … }` ordered-struct literal** — `animals = ${ Aardwolf: "…", aardvark: "…" };` ([#80](https://github.com/cfmleditor/tree-sitter-cfml/issues/80)). Filed as "the bracket form parses, the brace form does not", but the bracket form only appears to: see the misparse above. Supporting `${ … }` properly means introducing a real ordered-struct rule and deciding what `$[ … ]` should produce at the same time, since a `$` that is currently an ordinary identifier would have to stop being one. That is a design decision rather than a missing `choice` arm, which is why it was left.
- **A numeric struct key by dot notation in write position** — `myNumb.4 = "4";` ([#86](https://github.com/cfmleditor/tree-sitter-cfml/issues/86)). The issue's framing that a numeric key reads but does not assign is too narrow: `myNumb.4b = "4";` fails the same way, so the deciding factor is that the property is not a valid identifier rather than that it is a number. The read position works because `x = myNumb.4` produces a `member_expression` with a `property_identifier`.
- **A `thread { … }` statement followed by a tag island** — a ` ``` ` block after `thread name="x" { … }` (Lucee LDEV4157). Each parses on its own; only the combination fails.
- **Function-listener callback** — `var t = mySuccess():function( result, error ) { … };` (Lucee `FunctionListener.cfc`, [#87](https://github.com/cfmleditor/tree-sitter-cfml/issues/87)). Attempted; the High/High rating in [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md) is confirmed, and the mechanism is now named rather than guessed. A `function_listener` rule spelled `call_expression ':' function_expression` fails to generate against **the ternary**: `cond ? f() : g` and `f():function(){ }` share the prefix `call_expression :`, so the only resolutions offered put a conflict or a precedence between `function_listener` and `primary_expression`, live at every ternary containing a call. One file, 19 nodes.
- **`savecontent` as an expression** — `greeting = savecontent { writeOutput("hi") };` ([#82](https://github.com/cfmleditor/tree-sitter-cfml/issues/82), 3 Lucee files). Attempted. The statement form has no `savecontent` rule at all — it goes through the generic `tag_statement` as an ordinary identifier — so an expression form needs a `keyword('Savecontent')`, and that is the trap this file's own "keyword extraction is lexical" section describes. Adding it generates cleanly and costs only 31 states, then breaks the *working* statement form and every ordinary use of the word: `savecontent = 1`, `x = savecontent`, `x = savecontent.foo` and `savecontent()` all become ERRORs, and `npm test` fails. A `_reserved_identifier` entry does not rescue it, because the keyword out-lexes the identifier before the parser can reach the fallback. The non-keyword alternative — admitting `identifier statement_block` as an expression — is far too broad, since it is live at every identifier followed by `{`.
- **`function` as a bare value** — `h = function.foo;`. `function` is accepted as
  an assignable name (`admin ... function="" ...`) and as a property
  (`x.function`), but not as the object of a member expression. Making it a
  general expression start is what previously broke `function instanceOf( ... )`.

#### Constructs that fail in both CFScript grammars

These came from the RustCFML engine test suite; see [CORPUS.md](CORPUS.md).

**Correction.** This section previously said the constructs below "parse in the
embedded CFScript of `common/define-grammar.js` and fail only in
`cfscript/grammar.js`", and `docs/FAILING-PATTERNS.md` costed them as a port of
rules that already existed. That was wrong, and it under-rated all of them.

The `cfml` grammar does not parse CFScript bodies at all: `<cfscript>` becomes
`cf_script_content` and a component body becomes `cf_component_content`, both
raw text handed to the standalone grammar by `injections.scm`. So "the `cfml`
grammar accepted the same source" only ever meant it had not looked at it.
`common/define-grammar.js` *does* carry a copy of the CFScript rules, reachable
through an expression context such as `<cfset f = function( … ) { … }>` — and
reached that way, every construct below fails there too. `_formal_parameter` and
`formal_parameters` are byte-identical between the two files, which is the
direct confirmation that there was nothing to port.

Each is therefore a real grammar change, needed in **both** files, in the area
where keyword extraction is lexical. Verify a fix in both — a `.cfs` file for
`cfscript/grammar.js`, and a `<cfset>` closure for `common/define-grammar.js`.

**Second correction, narrower.** "Needed in both files" held for every construct
here that was checked, and then did not hold for [#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52).
`common/define-grammar.js` has no `tag_statement` rule at all, so its copy of
CFScript carries no `param` statement in any spelling — the attribute form
`param name="x" default="0";` fails there too, not just the shorthand. #52 was
therefore a `cfscript`-only fix. The rule to carry forward is that the two files
have to be *checked* rather than assumed symmetric in either direction: they had
drifted apart on `_for_header` (a missing alternative) and on `tag_statement` (a
missing rule).

- **Comma-less function parameters** — `function f( boolean a = false ⏎ boolean b = true )`. TestBox's `BaseSpec.cfc` `createMock` is written this way. The issue frames this as the newline acting as a soft separator, and that is not the mechanism: a **space** fails identically to a newline in every shape tested, so there is no newline sensitivity to honour and the comma is simply required by `commaSep1`. The one shape that looks supported is a misparse — untyped `function f( a b )` yields a *single* parameter of type `a` named `b`, and `function f( a b c )` errors. That misparse is also the cost: making the comma optional makes `f( a b )` ambiguous between one typed parameter and two untyped ones, an ambiguity inherent to CFML's `<type> <name>` parameter syntax and live at **every parameter list in the language**. Re-rated **High/High**, and not acceptable without `npm run bench`. [#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49).
- **`not` as a parameter name behind a type** — `function f( array not )`. The rest of the word-operator set parses since [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50) was fixed, and `not` is the one word that cannot join them: every other entry in `_operator_shaped_name` is a *binary* operator, competing only with a reading that needs a left operand the name slot has not got, while `not` is `unary_operator`, so `function f( array not x )` is genuinely ambiguous. The only resolutions `generate` offers are a conflict or a precedence between `_operator_shaped_name` and `unary_operator`, both live at every `!`, `-` and `+` in the language. Not worth that for the least plausible name in the set.
- **A default on an operator-shaped parameter name** — `function f( array in = [] )`. The bare `array in` parses; giving it a default means aliasing a `seq` to `assignment_pattern`, because that rule's left is a `pattern` and no pattern can reach these words. That spelling generates without conflicts but produces a malformed tree — the name outside a nested, duplicated `assignment_pattern` — and adds 5% to the state table. No corpus file writes it.
- **A statement as an arrow-function body** — `list.each( (v) => if ( v < 0 ) throw( … ) )` ([#75](https://github.com/cfmleditor/tree-sitter-cfml/issues/75), Lucee `LDEV1819/test2.cfm`). **Implemented, measured and reverted**, like the dotted struct key before it. It needs two things: `$.if_statement` in the arrow body `choice`, and an automatic semicolon before `)` in `scan_automatic_semicolon` — without the second, only the assignment-position form (`x = (v) => if (v) y = 1;`) parses, and the reported argument-position form does not, because the body statement ends at the call's closing paren. Both together work, generate without conflicts and pass the fuzzer. The cost is invisible everywhere except the generated table: **STATE_COUNT 4984 → 10005 and `parser.c` 17.9 MB → 35.7 MB**, a 2× table and +17.7 MB of committed C compiled by every binding, for one file with one error node. Admitting a general `$.statement` instead of `if_statement` is worse, not better: a `statement_block` is itself a `$.statement`, so `(v) => { }` becomes ambiguous, the same collision the brace-less `try` body hit.
- **A `final` modifier on a parameter** — `function testFunc( final required s )` (Lucee `LDEV3671/test3671.cfc`). Surfaced by fixing [#77](https://github.com/cfmleditor/tree-sitter-cfml/issues/77): that file starts `final component`, so it used to degrade to plain text and this gap was never reachable. Adding `optional($._kw_final)` beside `optional(keyword('Required'))` in `_formal_parameter` fails to generate in all three grammars — `( final (` is ambiguous between the modifier and `final` as a `_reserved_identifier` expression, and that prefix is live at **every parameter list in the language**, the shape the cost table warns about. One file does not pay for it.
- **A multi-modifier component header** — `final abstract component { … }`. The shared scanner skips a *run* of modifiers when deciding a file is a component file, but `cfscript`'s `component` rule takes only one. Widening it to `repeat` makes `abstract` at the head of a component-body member ambiguous between an `access_type` and a nested component's modifier list, and the conflict then pulls in `variable_declaration` as well (`final MEMBER = "v"`). No corpus file writes two modifiers there; six write the single-modifier `final component`, which parses.
- **A `param` type spelled with a `_reserved_identifier` word** — `param query x;` and `param component x;` fail in *every* spelling, including `param query x default=1;`. Found while fixing #52 and unrelated to it: `tag_statement` takes its type through `$.identifier`, and `query` and `component` are in `_reserved_identifier`, so they lex as keywords in that slot. Every other type name tested parses (`string numeric any boolean date array struct xml binary guid void`). Narrow, and no corpus file writes it. Not yet filed.

### cfml

- **Dynamic tag name with a static prefix or namespace** — `<h#field.getLevel()#>…</h#field.getLevel()#>`, `<dc:#container#>` (Lucee admin). 10 files.
- **Dynamic tag opened and closed in different blocks** — `<cfoutput>#t()#</#g(n)#></cfoutput>` where the matching open tag is in an earlier `<cfoutput>` (Taffy examples). The plain `<#expr#>` form parses when open and close sit together. 13 files.
- **A `<style>` block with many `#` tokens** — Lucee's `debug/Simple.cfc`, 42 `#` across CSS ID selectors and hex colours. Each of those constructs parses on its own; the failure only appears in accumulation, and the shortest failing extract is 20 lines.
- **A deep run of unpaired custom tags followed by a CF tag** — an unpaired `<cf_foo>` opens a block the next one nests inside, so N in a row is N levels deep, and each level costs `1 + 1 + name + sizeof(html_depth)` bytes in `SERIALIZE_TAGS` against the fixed `TREE_SITTER_SERIALIZATION_BUFFER_SIZE`. Once that is full the deepest tags lose their names, and a *following* CF tag then collapses the whole document to one ERROR at `1:1`. `<cf_a>` survives 124, `<cf_runtest>` 71, `<cf_abcdefghijklmnopqrstuvwxy>` 37. RustCFML's `runner.cfm` is ~700 unpaired `<cf_runtest>` tags followed by a `<cfscript>` block. **Two things previously recorded here are wrong** and are corrected on the issue. The threshold does *not* satisfy `depth × (name + 4) ≈ 1,014` "in every case": swept across every name length from 4 to 64 the product runs from 938 to 4,080, tight at 938–996 for some lengths and far above it for others, including the 28-character sample quoted above at 1,184. And overflow is survivable by design — `SERIALIZE_TAGS` records both `_serialized` and `_count`, and deserialize pads the difference with empty tags — so truncation costs tag *names*, not tag *count*. It turns fatal only when something later needs a dropped name: past the budget, plain text, `<div>`, an explicit `</cf_runtest>` and EOF all still parse at any depth, while `<cfscript>` and `<cfoutput>` do not. Failure is monotonic in depth and depends on name length but not content. [#55](https://github.com/cfmleditor/tree-sitter-cfml/issues/55).
- **`</cfscript>` inside a string literal** — `FileWrite( p, "<cfscript>…</cfscript>" )` closes the script block early; the remainder parses as template text and the real closing tag becomes a stray end tag. The scanner scans raw script text for the close tag without tracking string literals. **Confirmed a real divergence from Lucee**, which was the open question: Lucee gives `cfscript` a `tagdependent` body handled by `CFMLScriptTransformer`, and that ends the body through `isFinish()` (`isCurrent("</", data.tagName)`) called only between complete statements — so the string literal is consumed by the expression parser long before the tag inside it could be noticed, and there is no raw-text search for `</cfscript>` in that file at all. Read from Lucee's source rather than by running it; Adobe CF was not checked. [#56](https://github.com/cfmleditor/tree-sitter-cfml/issues/56).

The following were gaps and now parse: typed `catch` with `var`, `var` with a
scoped or dotted name, tag comments in a script body, `final` and
access-modifier member declarations, the empty struct literal `[=]`, bare `>` or
`<` in template text, the typed `param` statement, array return types
(`User[] function getUsers()`), script-syntax tag calls with space-separated
attributes, a subscript as a `var` declaration name
(`var mappings[ key ] = value`), `new` with a dotted Java path
(`new java.util.Properties()`), `debugger` as an ordinary identifier, the
thin-arrow lambda (`t -> t.b()`), the `''` escape inside a single-quoted tag
attribute value (`default='x ''y'' z'`), an array type in parameter position
(`function f( string[] v )`, nested `string[][]`), a `var`-scoped dotted
loop variable in a for-in header (`for ( var local.package in items )`), the
`=` spelling of a typed `param` default (`param numeric shortBad = "abc";`,
`cfscript` only), and a word-shaped binary operator as a parameter name behind
any type (`function f( array in )`, `query contains`, `struct eq`), the untyped
`param` shorthand (`param x;`, `param url.number;`, `cfscript` only), an access
modifier combined with `final` in a member declaration
(`public final MEMBER = "v";`), and a return type written before the access
modifiers (`struct public static function f()`), a subscripted static access
(`Test::["f"]()`, `Test::[m]()`), and the `default` modifier on an interface
method (`public default any function f()`, reachable after another modifier but
not as the first one), the bodyless tag-statement form of `throw` and `query`
(`throw message="x" type="y";`, `query name="q" dbtype="query";`), and a bare
string argument in a tag statement (`exit "exitTemplate";`,
`pageencoding "utf-8";`), a brace-less `try` body
(`try x = y; catch( any e ){ }`, an expression statement only), and a
parenthesised component attribute list (`component( javasettings = { } ) { }`),
and `name:value` annotations on components and functions
(`component displayname:"X" { }`, `function f() access:remote { }`), and
colon-separated attributes in a script tag call
(`cfparam (name:"local.d" default:"DDD")`). A `.cfc` beginning
`final component` is now recognised as a component file rather than silently
degrading to `html_text`, a `static { … }` initialiser parses at the top level
of an injected region as well as inside a component body, and a colon
assignment to a dotted name (`msSQL.class: 'x';`), and Lucee's inline
`java { … }` class block, whose body is recognised but deliberately left opaque
(`<cfjava>` as a *tag* already parsed). A bare `foo: bar;` still
parses as a `labeled_statement` rather than an assignment; the two spellings are
indistinguishable without a semantic pass, and no corpus file depends on it. The
`new java:` / `new cfml:`
type prefix now works in both CFScript grammars, where it had been
`cfscript`-only.

Two words are deliberately not accepted in the *leading* return-type slot, only
in the modifiers-first spelling: `query`, which collides with the head of
`query_tag`, and `function`, which if allowed there makes an access modifier
valid straight after the word `function` and so breaks a function *named*
`static` (`function static( … )`, Mura's `MuraScope.cfc`). `public query
function f()` and `public function function f()` are unaffected.

### `=>` and `->` produce the same node

Lucee distinguishes them at runtime — `=>` is a closure, `->` is a lambda, and
they capture scope differently — but they are syntactically identical, so both
produce an `arrow_function`. A consumer that needs to tell them apart can read
the operator token itself; `highlights.scm` matches both.

### cfquery

No known gaps. Bitwise `&`, `|` and `^` were the last failing construct across
the corpus's 2,247 `<cfquery>` bodies and now parse as `query_math_expression`.

## Removed JavaScript constructs

This grammar is a fork of `tree-sitter-javascript`, and some JS-only rules were
carried over. The following were removed because CFML has no equivalent:

- the `import` **rule** (a named `(import)` node used as an expression operand,
  so that JS `import("mod")` dynamic imports parsed). CFML's `import` is only
  ever the statement `import foo.Bar;`, which uses the bare keyword token — that
  is what `highlights.scm` matches as `"import"`.
- `meta_property` — JS `new.target` and `import.meta`.

Removing them dropped 5 conflict declarations and let `x = import.foo` parse as
an ordinary member expression. `"target"` was dropped from
`cfscript/queries/highlights.scm` at the same time.

Other JS leftovers still present and *not* valid CFML: `debugger_statement`,
`with_statement`, `template_string`, `regex`, `namespace_import`,
`_from_clause`, `export`.

`debugger_statement` is the one that had a cost. Because keyword extraction is
lexical, the `debugger` token out-lexed `identifier` at statement start, so
`debugger.log( … )` and `debugger = 1` failed — while `x = debugger.foo`, which
is not statement position, parsed. Preside's SAML module uses `debugger` as an
ordinary scope. The fix is to put `debugger` in `_reserved_identifier` like
`new`, `static` and `final`, which makes `debugger;` ambiguous between the
statement and a bare expression statement; `debugger_statement` carries a
`prec(1, …)` so the statement still wins. This costs no declared conflict.
Covered by `test/probes/cfscript/debugger_identifier.cfc` and the
`debugger as an ordinary identifier` corpus tests in both grammars.
