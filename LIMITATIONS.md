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
- **Subscript index holding more than one pair** — `animals = $[ Aardwolf: "…", aardvark: "…" ];` (Lucee tests).
- **`function` as a bare value** — `h = function.foo;`. `function` is accepted as
  an assignable name (`admin ... function="" ...`) and as a property
  (`x.function`), but not as the object of a member expression. Making it a
  general expression start is what previously broke `function instanceOf( ... )`.

### cfml

- **Dynamic tag name with a static prefix or namespace** — `<h#field.getLevel()#>…</h#field.getLevel()#>`, `<dc:#container#>` (Lucee admin). The plain `<#expr#>` form parses. 10 files.

The following were gaps and now parse: typed `catch` with `var`, `var` with a
scoped or dotted name, tag comments in a script body, `final` and
access-modifier member declarations, the empty struct literal `[=]`, bare `>` or
`<` in template text, the typed `param` statement, array return types
(`User[] function getUsers()`), script-syntax tag calls with space-separated
attributes, and a subscript as a `var` declaration name
(`var mappings[ key ] = value`).

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
