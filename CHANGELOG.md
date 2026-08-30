# Changelog

## [Unreleased]

### cfscript
- **Fix a systematic misparse of `x[ i ].prop = value`**, found by diffing tree *shapes* against master across the corpus rather than counting errors. `tag_statement`'s bare-attribute branch matched a subscript assignment too — reading `interceptors` as a tag and `[ x ]` as an array literal — and it won the tie. A `prec.dynamic(-1)` on that branch lets the ordinary expression statement win. This is the most widely-felt change on the branch: **332 statements across 104 files**, every one in the same direction (−332 `tag_statement`/`array`, +332 `expression_statement`/`subscript_expression`, plus 9 `object_pattern` → `object`), with no file moving the other way and no new ERROR anywhere. It also fixes [#83](https://github.com/cfmleditor/tree-sitter-cfml/issues/83) — `query name="q" listener=new Foo();` — for free, and takes the corpus to 741 error nodes across 143 files. Genuine tag statements (`location url="/home" addtoken="false";`, `http …`, `param numeric x default="0";`) are unaffected and pinned by the corpus test alongside the assignments. Worth recording *how* this surfaced: the branch's own scan showed nothing, because both readings are error-free — an error count cannot see a wrong tree, only a missing one
- Support Lucee's **inline `java { … }` class block** — `classInstance = java{ public class class1{ … } }` ([#74](https://github.com/cfmleditor/tree-sitter-cfml/issues/74), Lucee `LDEV4001`). The body is kept opaque, which is what the issue asks for: recognising the block is enough for a consumer, and parsing Java is not this grammar's job. The `<cfjava>` *tag* in the same file already parsed as an ordinary CF tag and needed nothing. Split deliberately across the two mechanisms. The opener is an **external** token, not a keyword: `java` must stay an ordinary identifier — `new java.util.Properties()` and `x = java.lang.System` both depend on it, and a `keyword('Java')` valid at expression start is exactly the out-lexing bug `new java.…` already suffered once. The brace is part of the token, so `java.util`, `javaCast` and `javascript` are never touched. That much an internal token also gave, and it was the first attempt — what it could not give is the second check: a variable that happens to be named `java` can also sit immediately before a brace, as in `loop array=java { x = 1; }`, where the brace opens the tag's *body*. The internal token swallowed that body as `java_class_content` with **no ERROR node** — a silently wrong tree, the failure mode #77 in this same release is about, and one the corpus scan cannot see. The external opener therefore also looks past the brace and claims the block only when what follows actually starts a Java class body (an access modifier, `class`, `interface`, `enum`, `record`, an annotation, …), skipping comments on the way, since a class body may open with one. Only the balanced-brace *body* is external, and it is entered after the opener has committed, so it never has to give characters back. It knows the three places a brace can appear without nesting — a string literal, a character literal and a comment — and all three are pinned by the corpus test. Same-line whitespace only in the opener: allowing a newline would capture `java` as a bare statement followed by an ordinary block on the next line, which is a different program. The scan stands down in error recovery the way `CFML_TEMPLATE_CONTENT` does, so the balanced-brace walk cannot run at every recovery step. **+28 parse states**, `cfscript` only. Corpus 747 → 744 error nodes across 147 → 146 files, `LDEV4001.cfm` to zero and nothing else moving
- Support a **colon assignment to a dotted name** — `msSQL.class: 'net.sourceforge.jtds.jdbc.Driver';` ([#90](https://github.com/cfmleditor/tree-sitter-cfml/issues/90)). Lucee accepts `:` in place of `=`, and Lucee's `LDEV3030/Application.cfc` mixes the two in adjacent lines. Only the *dotted* form is spelled: a bare `foo: bar;` already parses, though as a `labeled_statement` rather than an assignment, and rewriting that reading would change existing trees for a construct this issue is not about — so the narrower rule is also the honest one. A `member_expression` can never be a label, so the two cannot collide, and no conflict is needed. **+12 parse states**, and every other `:` reading is pinned by the corpus test: the ternary, a `pair`, a `slice_expression`, a `switch_case`, a `default:` and a labelled `while` with `break outer`. Corpus 755 → 747 error nodes across 148 → 147 files, `Application.cfc` going 8 → 0 — the one file that had been moving the *wrong* way through this whole branch, because every earlier fix improved its recovery without reaching its actual defect
- Accept a **`static { … }` initialiser at the top level** of a parsed region, not only inside `component_body` ([#78](https://github.com/cfmleditor/tree-sitter-cfml/issues/78)). `injections.scm` hands the body of a tag-based component's `<cfscript>` island to this grammar as a bare region, and that region is a *component body* rather than a statement list — so a `.cfc` that is perfectly valid CFML, and that the `cfml` grammar parses without error, reported an error inside an editor using the injection queries. Narrower than filed: the issue supposed `property` declarations "would presumably behave the same way", and they do not — `property name="x";` already parsed standalone, and `static { … }` was the only component-level construct that did not. One `choice` arm in `program`, no new conflicts, and `static["key"]`, `static;` and `static.foo = 1` are pinned by the corpus test
- **A statement as an arrow-function body ([#75](https://github.com/cfmleditor/tree-sitter-cfml/issues/75)) was implemented, measured and reverted.** It worked, and it cost too much. Two changes were needed: `$.if_statement` in the body `choice`, which alone fixed only the assignment-position form (`x = (v) => if (v) y = 1;`), and an automatic semicolon before `)` in `scan_automatic_semicolon`, without which the *reported* argument-position form still failed because the body statement ends at the call's closing paren. Together they parsed `list.each( (v) => if ( … ) throw( … ) )`, the whole gate was green and the fuzzer passed. The cost only shows in the generated table: **STATE_COUNT 4984 → 10005, and `cfscript/src/parser.c` 17.9 MB → 35.7 MB** — a 2× parse table and +17.7 MB of committed C that every binding compiles, for **one corpus file carrying one error node**. Parse time did not move measurably, but on this machine the benchmark could not have seen it either. Reverted on that basis, the same call this repo already made for the dotted struct key. Recorded in `LIMITATIONS.md` and in the cost table
- Corpus for these two: 757 → 755 error nodes across 149 → 148 files, from #78 alone (`TestStaticTag.cfc` to zero); #78 costs **1** parse state

- Support the **untyped `param` shorthand** — `param x;` and `param url.number;` ([#70](https://github.com/cfmleditor/tree-sitter-cfml/issues/70)). The typed shorthand (`param numeric x;`) and the attribute form (`param name="x" type="numeric";`) both parsed; only the form with no type at all had no reading. Written as its own branch of `tag_statement` rather than by making the existing `type` field `optional()`, and the difference matters: optional there lets the `default` alternative be reached with nothing in front of it, so `tag assignment_expression • {` becomes both a default followed by a body and a first attribute, and the only resolution `generate` offers is a conflict of `tag_statement` with itself — which cannot be declared, since conflicts need two distinct rules. The new branch also deliberately carries **no trailing attributes**: `param foo bar="1";` would then be genuinely ambiguous between it (name `foo`, one attribute) and the typed branch (type `foo`, `bar="1"` as the default). Nothing is lost, because the typed branch already accepts every attribute-carrying spelling — `param x default="0";` reads `x` as the type. No new conflicts
- Support an access modifier **combined with `final`** in a member declaration — `public final MEMBER = "v";` ([#69](https://github.com/cfmleditor/tree-sitter-cfml/issues/69)). `final MEMBER = "v";` and `public prop = "p";` each parsed; only the pair failed, inside a `static` block as well as at component level. One `optional(alias($._kw_final, $.access_type))` after the access modifier in `variable_declaration`'s member branch, kept there rather than added to the `choice` above it so `final` stays reachable exactly once. No new conflicts
- Support a return type written **before** the access modifiers — `struct public static function f()`, Lucee's `StaticFunctions.cfc` ([#88](https://github.com/cfmleditor/tree-sitter-cfml/issues/88)). The reverse order (`public static struct function f()`) and the bare `struct function f()` both parsed. Spelled as two alternatives in `function_declaration` rather than as one optional type with a `repeat($.access_type)` on either side, which would make `public function f()` ambiguous over which repeat takes the modifier; `repeat1` in the type-first alternative keeps the two disjoint. Two words are deliberately excluded from the *leading* type slot, and both were found by generating rather than guessed. `Query` collides with the head of `query_tag`, making `query • Abstract` ambiguous. `Function` is the one that actually bit: offering it as a leading return type makes an access modifier valid immediately after the word `function`, so in `function static( … )` — a function *named* `static`, from Mura's `MuraScope.cfc` — `static` stopped lexing as an identifier and became `_kw_static`. That file parsed cleanly before the change, produced one error after it, and **the corpus scan is the only step that caught it**: tests, probes and lint were all green. Both words still reach the type slot in the modifiers-first alternative, so `public query function f()` is unaffected. No new conflicts
- Support a **subscripted static access** — `Test::["f"]()` and `Test::[m]()`, alongside the bare `Test::f()` that already parsed ([#79](https://github.com/cfmleditor/tree-sitter-cfml/issues/79)). `member_expression` accepted `::` before a property name but `subscript_expression` only ever accepted an optional `?.` before its `[`, so the static chain had no subscript spelling. One `choice` arm there. `::` is its own token rather than a keyword, so unlike most additions in this grammar it cannot change how anything else lexes; slicing (`s[4:13]`), optional chaining (`b?.c`) and a plain `b[1]` are pinned by the same corpus test
- Support the **`default` modifier** on an interface method — `public default any function returnsany( any obj )` ([#73](https://github.com/cfmleditor/tree-sitter-cfml/issues/73)). `Default` is reachable only *after* another modifier, never as the first one, and that restriction is the fix rather than an approximation of it: adding `$._kw_default` to `access_type` outright makes `default` able to start a declaration, and since a `switch_default` body is an ordinary statement list, `switch { default: default any function f(){} }` is then ambiguous between continuing the first default's body and opening a second label. `generate` offers only a conflict of `switch_default` with itself, which cannot be declared. Lucee writes the modifier after `public`, and no corpus file puts it first. The two `switch` shapes are pinned by the corpus tests
- Support the **bodyless tag-statement form of `throw` and `query`** — `throw message="x" type="y";` and `query name="q" dbtype="query";` ([#71](https://github.com/cfmleditor/tree-sitter-cfml/issues/71)). Every other tag reaches this shape through `tag_statement`; these two cannot, and for two different reasons the issue guessed correctly. `throw` has its own dedicated statement rule and `_kw_throw` out-lexes the identifier `tag_statement` needs in its `tag` slot; `Query` is in `_reserved_identifier` and lexes as a keyword there for the same reason. Each is fixed in its own rule: `throw_statement` gains `repeat1($.parameter_attribute)`, the spelling `include_statement` already uses for exactly this shape — a single `assignment_expression` would not do, since what fails is the *space*-separated pair rather than the first attribute — and `query_tag` gains a second alternative ending in `$._semicolon`. That alternative takes `repeat1` rather than `repeat` so a bare `query;` keeps its existing reading as an expression statement, which `LIMITATIONS.md` records as deliberate. `throw(message = "x")`, `throw "boom"`, `query name="q" { }` and `query.newQuery()` are all pinned by the new corpus test
- Support a **bare string argument** in a tag statement — `exit "exitTemplate";` ([#81](https://github.com/cfmleditor/tree-sitter-cfml/issues/81)) and `pageencoding "utf-8";` ([#89](https://github.com/cfmleditor/tree-sitter-cfml/issues/89)). One `$.string` added to the `name` slot of the untyped `tag_statement` branch introduced above, which is the same `tag <argument>;` shape; both issues turned out to be one gap. `exit;` and `exit method="template";` already parsed and still do
- Support a **brace-less `try` body** — `try x = nonExistantVariable; catch( any e ){ … }` ([#85](https://github.com/cfmleditor/tree-sitter-cfml/issues/85)). The unbraced alternative is an `expression_statement` rather than a general `$.statement`, which is both what the construct needs and the only spelling that generates: a `statement_block` *is* reachable as a `$.statement`, so the general form makes the braced body match both alternatives and `try { } { }` ambiguous over which brace pair is the body. A precedence on the `statement_block` arm does not settle that either — the competing reduction is `statement_block` → `statement`, outside the rule — and every other resolution offered touches `statement` itself, which is live at every statement in the language. The braced form's tree is unchanged
- Support a **parenthesised component attribute list** — `component( javasettings = { } ) { … }`, alongside the bare `component javasettings = { }` that already parsed ([#72](https://github.com/cfmleditor/tree-sitter-cfml/issues/72)). This is the one change in this batch that **declares conflicts**, three of them, because `component (` is genuinely ambiguous between the attribute list and a call of the reserved identifier `component`, and only the `{` after the `)` settles it. The set had to grow to three (`[$.component, $._property_name]`, `[$.component, $.primary_expression]`, `[$.component, $.primary_expression, $._property_name]`) as `generate` reported one state at a time, and it converged there. Unlike the `[$.primary_expression, $.call_expression]` conflict the cost table warns about — prefix `identifier (`, live at every call in the language — this one's prefix is the `Component` *keyword* followed by `(`, so it is live only where that word is actually called. **Benchmarked as the workflow requires:** cfscript 12880 → 12576 ms, −2.4%, inside a 5.4–6.6% run-to-run spread, so no measurable cost. `cfquery` moved +3.6% in the same run with a byte-identical `parser.c`, which is a useful reading of the noise floor rather than a result
- Support **colon-separated attributes** in a script tag call — `cfparam (name:"local.d" default:"DDD")` ([#84](https://github.com/cfmleditor/tree-sitter-cfml/issues/84), the colon half). The comma-separated colon form already parsed, but as ordinary `arguments` full of `pair`s rather than through `tag_call_attribute`; only the space-separated one had no reading. One `choice('=', ':')`, and both separators produce the same tree, for the reason the rule's existing alias gives. It declares one conflict, `[$._property_name, $.tag_call_attribute]`, because `f( name : …` is genuinely ambiguous between a `pair` and a tag-call attribute until what follows settles it. **Cheap by the deterministic measure: 4979 → 4983 parse states, +0.08%.** The benchmark could not resolve it — cfscript read +9.1% and then +3.9% across two runs, while `cfquery`, whose `parser.c` this branch never touches, read +25.9% in the same session, so the machine was the dominant term. The state count is the number to trust here
- **The mixed-separator half of [#84](https://github.com/cfmleditor/tree-sitter-cfml/issues/84) is not fixed, and is the design already rejected in 0.26.x**, not a new gap. `cfimap( a = "1", b = "2" c = "3" )` puts a comma at the *first* junction, and `tag_call_arguments` requires a space there on purpose: a rule allowing a leading comma-run is ambiguous with ordinary `arguments` from the opening paren until the first space, so every comma-separated named call in the language would carry two live GLR stacks. `LIMITATIONS.md` already records this with the corpus counts that justified it (74 calls across 32 files put a space at the first junction; 11 across 4 put a comma). Noted here because the issue presents it as a separator bug rather than a known trade
- Support **`name:value` annotations** on components and functions — `component displayname:"X" { }`, `function f( String x ) access:remote { … }`, `secured:api` ([#68](https://github.com/cfmleditor/tree-sitter-cfml/issues/68)). Much cheaper than the issue makes it look, and the matrix is why: `component_attribute` already had a recursive colon arm, so `component foo:bar { }` parsed before this change. What it could not take was a *quoted* value, because a string is not itself a `component_attribute` — one `choice` on the value fixes the whole component half. Spelled there rather than by adding `$.string` to the arms, which would also make a bare `component "X" { }` parse. The function half genuinely had no spelling and gets a small `function_annotation` rule in the declaration's attribute repeat, whose value is a word or a string rather than a general expression — that restriction is what keeps this `:` away from the ternary and from `pair`, the two readings `hazards.md` warns a new `:` tends to disturb. **No new conflicts**, and the corpus test pins the ternary, a `pair`, a `switch_case` and a `slice_expression` alongside the new forms. Corpus 760 → 757 error nodes across 152 → 149 files, all three `LDEV3963` files to zero
- Corpus for these two: 765 → 760 error nodes across 155 → 152 files, four files improving and none regressing
- Corpus for these four: 777 → 765 error nodes across 161 → 155 files. Seven files move, all of them downward and six to zero, including `queryExecute.cfm` at 3 → 0 and `ldev5406.cfm` at 4 → 0
- Corpus for these two: 780 → 777 error nodes across 163 → 161 files, both affected files (`LDEV0255.cfc`, `LDEV1835/interface.cfc`) to zero, no other file moving
- Corpus across the three fixes: 781 → 780 error nodes across 167 → **163** files, five files to zero (`PackageService.cfc`, `All.cfc`, `StaticFunctions.cfc`, `Jira2605/index.cfm`, `LDEV0600/comp2.cfc`). One file moves the other way, `LDEV3030/Application.cfc` at 4 → 8, and it is the recovery-shape case the workflow describes rather than a regression: its only failing construct is the `msSQL.class: 'x';` colon assignment of [#90](https://github.com/cfmleditor/tree-sitter-cfml/issues/90), still open, and every other line in it parses in isolation. No declared conflicts were added by any of the three, so no benchmark was required

### cfml & cfquery

- Recognise a `.cfc` whose declaration is preceded by **`final`** as a component file ([#77](https://github.com/cfmleditor/tree-sitter-cfml/issues/77)). The shared scanner's `scan_cf_component_content` skipped a leading `abstract` or `static` before looking for `component` / `interface` / `property` / `import`, and `final` was simply missing from that set, so `final component { … }` matched nothing and the whole file fell through to `html_text`. That is the part worth fixing rather than the construct itself: there was **no ERROR node**, so highlighting, structural queries and the formatter all believed they had a valid parse of a text file — the issue reports such a file being scored as formatted cleanly when its body had never been formatted at all. The modifier skip is now a loop as well as a wider set, and it terminates because each pass either consumes a word or reads none. Six corpus files start `final component`. Scanner change, so `npm run fuzz` was run alongside the usual gate
- One corpus file moves **up**, 0 → 1, and that is the fix working: `LDEV3671/test3671.cfc` starts `final component`, so it used to degrade to text and its real content was never parsed. Now recognised, it surfaces a genuine gap the degradation had been hiding — `function testFunc( final required s )`, a `final` modifier on a *parameter*. That one is **not** fixed here: `( final (` is ambiguous between the modifier and `final` as a reserved-identifier expression, live at every parameter list in the language, which is the prefix shape the cost table warns about, and one file does not pay for it. Recorded in `LIMITATIONS.md`
- A **multi-modifier** component header (`final abstract component`) is likewise still unsupported in `cfscript`, though the scanner now skips a run of them. Widening `component`'s modifier slot from `optional` to `repeat` makes `abstract` at the head of a component-body member ambiguous between an `access_type` and a nested component's modifier list, and the conflict then pulls in `variable_declaration` too (`final MEMBER = "v"`). No corpus file writes two modifiers there

### Tooling
- Give `scripts/build.js`'s multi-dialect path a `.catch()`, matching `release.js`. `spawnTreeSitterAsync` *resolves* with the exit code when a `generate` ran and failed, and that path was already handled — `npm run build` has always exited 1 there. It *rejects* only when the child process could not be started at all (`child.on('error')`, e.g. `ENOENT` or `EAGAIN`), and that rejection was unhandled: Node still exited non-zero, but printed a nine-line `ErrnoException` stack trace instead of naming the step. Now one line, as the generate-failure path already gave. Verified by forcing the reject path with a bad executable — before, a stack trace; after, `Error: spawn … ENOENT` — and by re-checking that a real generate failure still prints `cfscript: generate failed (exit 1)` and exits 1 with no stack trace, and that the success path still exits 0

- Push the release commit and its tag as **one atomic push** rather than two commands. `scripts/release.js` ran `git push` and then `git push origin v<version>`, so the branch landed first and anything that rejected the tag left the version bump on the default branch with nothing tagged and nothing published — the registries still serving the previous version while the repository claims the new one, a state that has to be unpicked by hand. This is not hypothetical: it happened cutting 0.26.33, where the tag push returned HTTP 403 from a credential scoped to `refs/heads/*`, after `master` had already moved. `git push --atomic <remote> HEAD:refs/heads/<branch> refs/tags/v<version>` makes the server take both refs or neither, so a rejected tag leaves the branch untouched and the release is simply retryable. The remote and branch are derived from the upstream the script already requires to exist, so a release cut from a branch whose name differs from its remote's still pushes to the right place. Verified both ways against a local bare repository with a `pre-receive` hook that rejects `refs/tags/*`: non-atomic advances the branch and loses the tag, atomic leaves the branch exactly where it was, and both refs land once the hook is removed

## [0.26.33]

### cfml & cfscript

- Support a word-shaped binary operator as a **parameter name** behind a type — `function f( array in )`, and equally `query contains`, `struct eq`, `component gt` ([#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50)). The issue recorded this as specific to `in`; it is not, and the deciding factor is the type rather than the name. `parameter_type` reaches the slot through `$.identifier`, and `member_expression`'s object is a full `$.expression`, so an expression reading is live at the start of every parameter — which makes a binary operator valid straight after the type, and keyword extraction then hands the word to the operator token (`--debug` shows the lexer emitting `sym:in`). `string in` and `any in` always parsed because `parameter_type` spells those types as `keyword()` tokens and no expression reading survives them. A new `_operator_shaped_name` rule, aliased to `identifier` in the parameter-name slot of both grammars, restores the identifier reading — the same move `_reserved_identifier` makes for keyword-shaped names. Its patterns are duplicated from the `binary_expression` operator table rather than shared, because that table pairs each operator with its own precedence and cannot be factored into one rule; they are the same tokens, since identical patterns unify, which is what keeps `a eq b` a `binary_expression` rather than two identifiers. **No new conflicts, and one extra parse state in each of the three grammars** — cheaper than the Med-High rating, because a shared rule collapses states that spelling the operators out one at a time does not (`in` alone cost 88 states; all nineteen together cost 1). Corpus 786 → 784 error nodes across 168 → 167 files, every affected file to zero
- Two neighbours are deliberately still unsupported, both recorded in `LIMITATIONS.md`. `function f( array not )`: `not` is the one word in the set that is a *unary* operator, so `function f( array not x )` is genuinely ambiguous and the only resolutions offered are a conflict or a precedence against `unary_operator`, live at every `!`, `-` and `+`. And `function f( array in = [] )`: giving an operator-shaped name a default means aliasing a `seq` to `assignment_pattern`, which generates cleanly but yields a malformed tree and adds 5% to the state table

### cfscript

- Support the `=` spelling of the default in a typed `param` statement — `param numeric shortBad = "abc";`, alongside the `param numeric shortBad default="abc";` that has parsed since 0.26.31 ([#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52)). The name and its value are spelled as an ordinary `assignment_expression` in a second branch of `tag_statement`'s shorthand form, rather than as a fresh `'=' $.expression` position. That choice is the whole change: a new expression position there reopens where the value ends against the automatic semicolon, so `param numeric x = a + { … }` gets two readings — a binary `+` continuing the value, or a unary `+` opening the next statement — and `tree-sitter generate` offers only a conflict or a precedence on `binary_expression`/`unary_operator`, both live at every `+` and `-` in the language. `assignment_expression` has already settled that boundary everywhere else, so reusing it costs nothing; `prec.right` on the new position does not help, because the competing reduction is not inside the rule. Corpus 787 → 786 error nodes across 169 → 168 files, the whole diff being one deleted line
- **This is a `cfscript`-only change**, which the previous note about [#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49)–[#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53) needing the same edit in both grammars did not anticipate. `common/define-grammar.js` has no `tag_statement` rule at all, so its copy of CFScript has no `param` statement in *any* spelling — `param name="x" default="0";` fails there too, not just the shorthand. The correction stands for #49 and #50, whose rules exist in both files; it does not for #52, where the shared grammar is missing the whole construct. Reaching it needs the script-syntax tag call feature ported to `common/define-grammar.js`, which is its own piece of work and is not attempted here

### cfml & cfscript

- Support a `var`-scoped **dotted** loop variable in a for-in header — `for ( var local.package in items )` ([#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53)). A dotted name parsed without `var` and a plain name parsed with it; only the combination failed. `_for_header`'s `var` branch accepted `identifier`, `_reserved_identifier` and a destructuring pattern, but never got the `member_expression` that `variable_declarator` was widened with for `var local.x = 1`, so the two rules had drifted. One `$.member_expression` in each of `cfscript/grammar.js` and `common/define-grammar.js`, no new conflicts, parse tables up 0.5–0.9% with no new symbols or productions. The case worth knowing is the one that made this cheap rather than Med-risk: widening `variable_declarator` the same way is what once made `var new = 1` lex `new` as a keyword, and the fix then was to spell out `alias($._reserved_identifier, $.identifier)` — which this rule already carried, so `for ( var export in … )` and `for ( var new in … )` still parse and the corpus test pins them alongside the new form. A subscript loop variable (`for ( var pkg[1] in items )`) is deliberately still unsupported: `variable_declarator` accepts it for `var mappings[ key ] = value`, but nothing in the corpus writes it in a for-in header. Corpus 789 → 787 error nodes across 170 → 169 files, the scan diff being two deleted lines from the one affected file
- Support an array type in **parameter** position — `function f( string[] v )`, and the nested `string[][] w` ([#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51)). The mirror of the array *return* type, which has parsed since 0.26.x. `repeat($.array_return_suffix)` after `parameter_type` in both CFScript grammars, reusing the return type's single `token(seq('[', ']'))` for the same reason it exists there: as two tokens the `[` is reachable from `array_pattern` in this state and the parser cannot choose until it has read the `]`, so lexing the pair together moves the decision one character of lookahead earlier. No new conflicts. The node keeps its `array_return_suffix` name, so the existing `@punctuation.bracket` highlight covers both positions. Corpus 801 → 789 error nodes across 173 → 170 files, every affected file to zero — 3 files, not the 1 the estimate assumed, and two of them Lucee rather than the RustCFML test that reported it. An empty array default (`function f( a = [] )`) still parses as an `array`, and `function f( [a, b] )` still as an `array_pattern`

### Documentation

- **Correct the recorded cause of [#55](https://github.com/cfmleditor/tree-sitter-cfml/issues/55)**, the serialized-state overflow behind a deep run of unpaired custom tags. The per-tag cost in `SERIALIZE_TAGS` is real, but the claim that the threshold satisfies `depth × (name + 4) ≈ 1,014` "in every case" was generalised from three samples, two of which were 4 and 10 characters. Swept across every name length from 4 to 64 the product runs 938 to 4,080, and the 28-character sample the note itself cited works out at 1,184. The missing variable: overflow is survivable by design, since `SERIALIZE_TAGS` records `_serialized` alongside `_count` and deserialize pads the difference with empty tags, so truncation costs tag *names* rather than tag *count* and only turns fatal when a later construct needs a dropped name. Past the budget, plain text, `<div>`, an explicit close tag and EOF all parse at any depth, while `<cfscript>` and `<cfoutput>` do not. Failure is monotonic in depth and depends on name length but not content. A per-tag saving therefore moves the threshold without removing the cliff, so "a fix means making the state cheaper per tag rather than hunting a limit" was concluded too early. No parser change
- **Re-rate [#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49) from Med/Med to High/High**, after running the same scope matrix that caught #50. Two things the issue says are wrong. The newline is not a soft separator the grammar could be taught to honour: a *space* fails identically to a newline in every shape tested, so the comma is simply required by `commaSep1` and there is no newline sensitivity to exploit. And the one shape that appears to work already — untyped `function f( a b )` — is a misparse rather than support, producing a single parameter of type `a` named `b`; `function f( a b c )` errors, which is what gives it away. So nothing about comma-less lists works today. The cost follows from that misparse: making the comma optional makes `f( a b )` genuinely ambiguous between one typed parameter and two untyped ones, an ambiguity inherent to CFML's `<type> <name>` parameter syntax and live at every parameter list in the language. That is the shape the cost table warns about after the two 6× regressions, so this one cannot be accepted without a benchmark. Both grammars fail identically, so it does need the change in both files
- **Correct the recorded scope of [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50)**, which `LIMITATIONS.md` and `docs/FAILING-PATTERNS.md` both carried as "only `in` is affected" and costed as the cheapest of the four remaining CFScript gaps. It is neither. `eq`, `is`, `mod`, `contains`, `neq` and `lt` fail the same way, and the deciding factor is the **type** rather than the name: `string in` and `any in` parse because `parameter_type` spells those as `keyword()` tokens, while `array`, `query`, `struct` and `component` reach the slot through `$.identifier` and leave a `primary_expression` stack live, where a binary operator is valid and out-lexes the identifier — `--debug` shows the lexer emitting `sym:in`. A fix therefore needs the whole word-operator set in the parameter-name slot, ~25 tokens of which most are anonymous case-insensitive regexes rather than named rules, so it is re-rated Med-High/Med and is now the most expensive of the group. Recorded in the predictions table as its own miss: a scope claim in an issue is not evidence, and the matrix that disproves this one took two minutes to run
- **Correct a wrong claim about five CFScript constructs** ([#49](https://github.com/cfmleditor/tree-sitter-cfml/issues/49), [#50](https://github.com/cfmleditor/tree-sitter-cfml/issues/50), [#51](https://github.com/cfmleditor/tree-sitter-cfml/issues/51), [#52](https://github.com/cfmleditor/tree-sitter-cfml/issues/52), [#53](https://github.com/cfmleditor/tree-sitter-cfml/issues/53)). `CORPUS.md`, `LIMITATIONS.md` and `docs/FAILING-PATTERNS.md` all recorded these as already parsing in the embedded CFScript of `common/define-grammar.js` and failing only in the standalone `cfscript/grammar.js`, costed as "a port of rules that already exist". There is nothing to port: the `cfml` grammar does not parse CFScript bodies at all — `<cfscript>` is `cf_script_content`, a component body is `cf_component_content`, both raw text for `injections.scm` — so the evidence for "the embedded grammar already has it" was a body that had never been parsed. The copy of the CFScript rules in `common/define-grammar.js` is real and reachable through `<cfset f = function( … ) { … }>`, and reached that way all five fail there too; `_formal_parameter` and `formal_parameters` are byte-identical between the two files. The four still open are re-rated Med/Med and each needs the change in both files. The general form, now recorded in `CORPUS.md`: a claim that something already parses somewhere has to name the input that reaches the rule

### cfml & cfquery

- Support the `''` doubled-quote escape inside a **single**-quoted tag attribute value (`<cfparam name="sq" default='x ''y'' z'>`), which previously collapsed the tag to an ERROR ([#54](https://github.com/cfmleditor/tree-sitter-cfml/issues/54)). The escape has always worked in a double-quoted value; `quoted_cf_attribute_value` carried `'""'` in its double-quoted branch and had no `"''"` counterpart in the other. One `choice` arm, no new conflicts, and `cfscript/src/parser.c` is byte-identical since the rule lives in the shared `common/define-grammar.js`. The corpus scan goes 802 → 801 error nodes across 174 → 173 files, the whole diff being one deleted line in the RustCFML test the probe was reduced from. The case worth knowing about is the one *not* in the issue: a `''` token could in principle out-lex the closing quote and break the empty value `default=''`, so the new corpus test pins both escapes and both empty forms rather than just the reported construct

### Tooling

- Keep the real-world corpus in `~/corpus` when that directory exists, falling back to the gitignored in-repo `corpus/` when it does not (`scripts/corpus-dir.js`, printed at the top of every fetch). The in-repo default is per-clone, so a second clone or a `git worktree` re-fetched all 97 MB, and `git clean -xdf` deleted it precisely because it is gitignored. Creating `~/corpus` opts in; deleting it opts out; nothing creates it for you. `npm run scan corpus` follows the same resolution, so every documented command works unchanged in either layout — only the bare word `corpus` is redirected, and only when it does not exist relative to the current directory
- Fix `scripts/release.js` silently skipping the commit, tag and push when its prompts are answered from a pipe rather than a terminal. It opened a `readline` interface per prompt, but readline emits a `line` event for every line of a chunk as soon as the chunk arrives while `question` only captures the line emitted *after* it is called — so with `printf 'y\ny\ny\n' | npm run release …` the answers to prompts 2 and 3 were emitted during prompt 1 and discarded, and every later prompt read EOF. An unanswered `question` never fires its callback, so the promise stayed pending, the event loop emptied and the script **exited 0** having bumped every version, built, linted, tested and rebuilt the WASM but committed nothing. A non-TTY stdin is now drained up front and the answers consumed one per prompt; running out is a hard error rather than a silent success. The interactive path is unchanged. Sharing one interface across the prompts does *not* fix this, which is the obvious-looking fix to avoid
- Report a failed release step as a one-line error and a non-zero exit rather than an unhandled promise rejection and a stack trace; `run` already inherits stdio, so the failing command's own output is directly above

## [0.26.32]

### Bindings

- Add a Java binding (`bindings/java/`, `pom.xml`): `TreeSitterCfml`, `TreeSitterCfscript` and `TreeSitterCfquery` under `io.github.cfmleditor.jtreesitter.*`, built on [jtreesitter](https://github.com/tree-sitter/java-tree-sitter) and the Foreign Function & Memory API. Needs JDK 23+. Unlike the other bindings it does not compile the C: it resolves `tree_sitter_*` out of shared libraries at runtime
- Add `npm run build:native`, which builds the three grammars *and* the tree-sitter runtime (from the copy vendored by the `tree-sitter` npm package, so the version is pinned by `package-lock.json`) into `build/native/` — the libraries the Java binding loads
- Fix `make -C cfscript` and `make -C cfquery` building a library named `libtree-sitter-cfml`: `common/common.mak` reassigned `LANGUAGE_NAME` after the including Makefile had set it, so both dialects produced a `libtree-sitter-cfml.{a,so}` and a `tree-sitter-cfml.pc` holding the wrong parser. The last dialect to be installed won
- Fix `make install` failing to find the C header: it looked for `bindings/c/…` relative to the dialect directory rather than the repository root. Add the missing `tree_sitter/tree-sitter-cfquery.h`, and move `tree-sitter-cfscript.h` alongside the other two in `bindings/c/tree_sitter/`
- Fix the hardcoded `VERSION` in `common/common.mak`, stale at 0.26.17, which was written into every generated `.pc` file. It now comes from `tree-sitter.json`, and `.pc` descriptions are no longer empty for cfscript and cfquery

### Performance

- **`cfscript` is ~1.95× faster.** The scanner was scanning to end-of-file on every error-recovery step. `cfml_template_content` is only reachable straight after a ``` fence, but tree-sitter marks every external token valid during recovery, so the scanner went looking for a closing fence that ordinary CFML does not contain — consuming the rest of the file and then returning false. Over 400 corpus script components (2.2 MB) that was 25.1M of the scanner's 25.13M character advances, and 52% of every instruction the parse retired. `TEMPLATE_CHARS` already stood down the same way. Parsing the corpus's 8,285 script components goes 9.6s → 4.9s; `npm run bench` reports 19.2s → 12.1s across all 42.2 MB of script inputs, and a fixed 400-file subset retires 2.4× fewer instructions
- **`cfml` is 5–8% faster**, from three changes to the shared scanner. Parsing the corpus's 4,260 templates retires 8.1% fewer instructions (25.80G → 23.72G) and takes 2.62s → 2.50s wall-clock; the external scanner's share of a parse drops from 26% to 17%:
  - Rebuild the tag stack in place on deserialize rather than freeing and re-allocating every tag name on every call. Deserialize runs once per external-token lex — 85,213 times over 300 corpus templates — and was 8.5% of a parse; it is now 3.9%. Tag name buffers are reused, so only a change in stack depth reaches the allocator
  - Drop the `strlen` per entry from the tag-name lookups. `tag_type_for_name` walked 126 entries calling `strlen` on each, which alone was 2.2% of every instruction a corpus parse retired; the name tables are fixed-width and NUL-padded, so the length is a byte read. Same for the `cfcomponent`-style void-tag list, and for the `</script>`/`</style>` delimiter length that was being recomputed per matching character
  - Answer the ASCII cases of `iswspace`, `iswalpha`, `iswalnum`, `towupper` and `towlower` inline in both scanners rather than paying an out-of-line locale-aware library call per character, keeping the library call for the non-ASCII tail
- No change to what parses. Output is byte-identical across the corpus for `cfml` (13,756 templates) and `cfquery` (2,381 embedded queries). Under `cfscript` six of 9,521 files change, all of them error-recovery shapes; the one that uses the ``` fence recovers better than before, an `ERROR` around the preceding statement becoming a `MISSING ";"` (recorded as `test/probes/cfscript/cfml_template_after_bare_statement.cfc`). The corpus scan went 769 → 768 error lines with no file regressing

### cfml & cfquery

- **Fix a heap over-read in the shared scanner that segfaulted the parser** ([#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57)). `serialize` writes two tag arrays into a 1,024-byte buffer; deep nesting filled it on the first, so the second found no room for even its 4-byte header and — `break` inside `do { … } while(0)` leaving the whole block — wrote nothing at all. `deserialize` then read its counts unconditionally at that offset, one past the end of the heap block, and followed the resulting garbage until it hit an unmapped page. Both halves are fixed: `serialize` reserves room so every section is always written and only *entries* are ever dropped, and `deserialize` bounds-checks every read against `length`, so a truncated or foreign buffer now costs scanner state rather than memory safety. The crash was probabilistic — `<xyz>` × 400 died 20/20, × 119 died 4/20 — and is now 0 across 260 runs, with Valgrind reporting no invalid reads. No grammar change: `cf*/src/parser.c` is byte-identical, the corpus scan is unchanged at 803 error nodes across 174 of 14,975 files, and `npm run bench` reports no change

### Corpus

- Add `RustCFML/RustCFML` to the corpus repository list — a CFML interpreter written in Rust, 1,188 CFML files of which the `tests/` tree is 1,108, each file written to pin one edge-case language behaviour. It scans at 40 error nodes across 15 of 1,188 files (98.7% of files clean), all 40 in `tests/`, and turned up eight constructs no earlier scan had shown, recorded in [`CORPUS.md`](CORPUS.md), [`LIMITATIONS.md`](LIMITATIONS.md) and [`docs/FAILING-PATTERNS.md`](docs/FAILING-PATTERNS.md) with a probe each. No grammar changes — five of the eight already parse in the embedded CFScript of `common/define-grammar.js` and fail only in the standalone `cfscript/grammar.js`, which `injections.scm` is what makes user-visible

### Tooling

- Scan `examples/` in CI (`npm run scan:examples`). Nothing scanned it before — no script, no workflow, and ESLint ignored it — which is why nobody had noticed that **both** its files segfault the parser, through the heap over-read in the shared scanner's `deserialize` reported as [#57](https://github.com/cfmleditor/tree-sitter-cfml/issues/57). The crash is probabilistic: it needs the serialized tag state to overflow its 1,024-byte buffer, and whether the resulting out-of-bounds read faults depends on the heap layout of that particular process
- Add `--isolate` to `npm run scan`, which parses each file in a child process so a crash is reported instead of ending the scan, and `--expect <file>`, which compares the result against a committed baseline and fails on drift in either direction — the same contract `npm run probe` has. `--retries <n>` classifies a file that only crashes some of the time. A baseline entry of `flaky` covers the case retrying cannot pin down, asserting only that the file has not become ordinary parse errors. Re-baseline with `npm run scan:examples -- --update`
- Ignore `corpus/**` in `eslint.config.mjs`. The directory is gitignored but was still linted, so `npm run lint` reported errors in third-party JavaScript pulled in by `npm run corpus:fetch` — 53 of them from one repository in the list
- Fix the file count in `npm run scan`: a file whose only parse errors came from an injected `<cfscript>` or `<cfquery>` region had them printed but was never counted, so the summary under-reported affected files (62 against a true 161 on the reference corpus). Node counts were unaffected

### cfml & cfscript

- Support array return types on function declarations (`User[] function getUsers()`)
- Support the `new java:` / `new cfml:` type prefix in the shared grammar as well as `cfscript`, so `<cfset x = new java:java.io.File(p)>` parses
- Allow `debugger` as an ordinary identifier (`debugger.log( … )`, `debugger = 1`), which previously failed at statement start because the keyword out-lexed the identifier. The bare `debugger;` statement still parses as `debugger_statement`
- Support the thin-arrow lambda (`t -> t.b()`, `( x, y ) -> x + y`) alongside the existing `=>` closure. Both produce an `arrow_function`; `->` is added to the operator list in each `highlights.scm`

### cfscript

- Support script-syntax tag calls with space-separated attributes (`cfdirectory( directory="#dir#" action="create" mode="777" )`), including calls that switch to commas after the first attribute
- Support a subscript as a `var` declaration name (`var mappings[ key ] = value`)
- Fix `new` with a dotted Java path (`new java.util.Properties()`): `java` and `cfml` are also the `new java:` type prefixes, and their bare tokens out-lexed the identifier straight after `new`

## [0.26.31]

### cfml & cfscript

- Support the empty struct literal `[=]`, alongside the existing `[:]`

### cfml

- Treat a bare `>` or `<` in template text as text (`<p>a > b</p>`, `#ratio#%  ==>`) instead of an error

### cfscript

- Support the typed `param` statement (`param string url.id default="0";`), used in `.cfm` templates via `<cfscript>`
- Fix an infinite loop on an unterminated query string: `queryExecute("` hung the parser, because `scan_query_text` looped to the closing quote with no EOF check

### cfquery

- Support the bitwise operators `&`, `|` and `^` in SQL (`WHERE status & 2048 = 2048`)

## [0.26.30]

- Publish Python bindings to PyPI as part of the release workflow (wheels built via `cibuildwheel`, sdist via `build`, upload via trusted publishing)
- Fix Python sdist/wheel builds: bundle `common/*.h`, per-dialect `tree_sitter/*.h`, and `cfml/queries/*.scm` so `pip install tree-sitter-cfml` succeeds from source and query constants resolve

## [0.26.29]

### cfml & cfscript

- Add `[:]` ordered struct literal syntax
- Add `EQUAL` as a binary equality operator (synonym for `EQ`)
- Support wildcard imports (e.g. `import component.*`)
- Allow `cfhtmlhead`, `cfhtmlbody`, and `cfcache` as paired tags with closing tags

### cfscript

- Support multiple attributes on `include` statement (e.g. `include template="file.cfm" runonce="true"`)
- Support multiline `query` tag with attributes on separate lines
- Add triple-backtick cfml template blocks (` ``` `) with cfml injection
- Support dotted variable names in catch clause parameter (e.g. `catch (any local.e)`)
- Support `new component` inline component expressions with attributes and body
- Support case-insensitive `Component` in `new component` expressions
- Support `java:` and `cfml:` type prefixes in `new` expressions (e.g. `new java:java.io.File(path)`)
- Allow whitespace between `?` and `:` in elvis operator
- Fix `hash_empty` (`##`) to use `token.immediate`, preventing GLR state explosion in large files

## [0.26.28]

- Add .scm files as a source of truth for other projects
- Add validation for .scm files against the respective grammars

## [0.26.27]

- Support `final` as a component modifier
- Support multiple access modifiers on functions (e.g. `public static string function`)
- Support multi-line property declarations and function attributes (using `tag_linefeed`)
- Support dotted catch types (e.g. `catch (App.CustomException e)`)
- Support multiple catch clauses in try/catch
- Support parameter metadata attributes (e.g. `string name = "" taffy_minlength="1"`)
- Fix automatic semicolon insertion before CFML word operators (`and`, `or`, `eq`, `neq`, `not`, `gt`, `gte`, `ge`, `lt`, `lte`, `le`, `mod`)

## [0.26.26]

### cfscript

- Support string literal as catch type (e.g. `catch("any" ex)`)
- Support case-insensitive `IN` / `OF` keywords in for-in loops
- Remove `--` as a comment (was conflicting with decrement operator)
- Add `include` statement support (e.g. `include "file.cfm";`)
- Add `private`, `public` to reserved identifiers (usable as variable names)
- Allow `component` as an inline statement (not just top-level)
- Support abstract function declarations in interfaces (`function name();`)

### cfquery

- Allow square brackets inside single-quoted and double-quoted SQL strings (e.g. `' [' + code + ']'`)
- Support `<cfreturn>` inside cfquery bodies
- Support `<cfoutput>` inside cfquery bodies
- Support backtick-quoted identifiers for MySQL-style quoting (`` `column_name` ``)
- Support T-SQL `@variable` and `@@system_variable` identifiers
- Add `BEGIN`, `WHILE`, `GO`, `EOF` to SQL keywords
- Fix `--` inside quoted strings being incorrectly parsed as a line comment
- Fix single quotes inside double-quoted values causing parse errors
- Fix SQL `CASE WHEN...END` inside `<cfcase>` tags triggering erroneous implicit tag close
- Split `+` concatenation into `query_concat_expression` (with optional right operand) to support `+` before `<cfif>` blocks

## [0.26.25]

- Add CDATA section support with CFML hash expressions (`<![CDATA[#expr#]]>`)

## [0.26.24]

- Add cfsavecontent content-type directive (`<!--- @content TYPE --->`) supporting cfml, html, script, css, xml, sql, and raw
- Add CDATA section support with CFML hash expressions (`<![CDATA[#expr#]]>`)
- Remove cfprocessingdirective and cfsetting from void tags (they can have bodies)
- Allow digits in cf_attribute_name (e.g. `show3d`)
- Fix & handling in html_text (don't stop at non-entity ampersands)
- Fix numeric entities (&#9654;) not conflicting with CFML hash expressions

## [0.26.22]

- Fix versioning

## [0.26.21]

- Fix for property definitions in cfscript components

## [0.26.20]

- Fix for abstract keyword for script component definitions #30

## [0.26.19]

- Add `target/` to eslint ignores
- Add JSDoc comments to `scripts/release.js`

## [0.26.18]

- Fixes for standaone query parens
- Security fix for scanner

## [0.26.17]

- Fixes for standalone query operators

## [0.26.16]

- SQL types should be classed as functions
- Add additional SQL functions

## [0.26.15]

- Further Updates to cfquery grammar and associated highlights.scm
- Removal of CFHTML grammar ( covered by CFML grammar )

## [0.26.14]

- Updates to cfquery grammar and associated highlights.scm
- highlights.scm replace `lua-match` with `match`, fixes #27 thanks @chapmandu

## [0.26.12]

- Fix `SYMBOL_COUNT` conflict

## [0.26.11]

- `cfcomponent` tags are now optional siblings ( not parents )
- `cffunction` tags are now specific tag definitions
- Support `script` tags inside `cfcontent` tags

## [0.26.10]

- Fix for erroneous end tags crossing boundary
- Fix escaped hashes

## [0.26.9]

- Fixes for Go bindings

## [0.26.8]

- Fixes for nested comments
- Fixes for # expressions on the left side of an assignment
- Fixes for implicit self close tags within <cfelse> / <cfelseif> tags

## [0.26.7]

- Scanner code improvements

## [0.26.6]

- Fix for script based cfc's

## [0.26.5]

- CFHTML / CFML grammars become one — cfhtml still exists for now, but tools and parsers only need to use cfml, cfscript, and cfquery dialects
- Cut down the cfquery grammar — implements a reduced version of the cfquery grammar that shares common rules, to be built back up over time (the full grammar caused WASM builds to exceed 10 minutes, blocking zed.dev extension builds)

## [0.26.4]

- Fixes for various regressions in 0.26.3
- Fixes for cfscript component cfc's

## [0.26.3]

- Various fixes for CFQuery grammar
- Other repo tidy ups and fixes ( thanks @gavinbaumanis )

## [0.26.0]

- Introduce CFQuery grammar
- Rename private node `_cf_tag` to `_cf_tags`
