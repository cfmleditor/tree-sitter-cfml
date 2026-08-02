# Known Limitations

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

#### Do not use case-insensitive regex tokens for keywords

Do **not** replace the enumerated string literals with
`token(prec(1, /[rR][eE].../))`. A regex token is not eligible for tree-sitter's
keyword extraction, and the explicit precedence overrides longest-match, so it
out-lexes a *longer* identifier wherever the keyword is valid:
`while_value = 1;` parses as `while` + `_value`, and
`<cfset x = functionalImpact>` as `function` + `alImpact`.

This does **not** apply to multi-word tokens such as `static get` or
`does not contain`, nor to the SQL keyword tables in the cfquery grammar. Those
contain mandatory whitespace, or are declared without explicit precedence, so
longest-match still wins and identifiers like `orders` or `selected_items` are
safe.

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

### `<cfsetting>` without closing tag

`<cfsetting showdebugoutput="no">` without a closing `</cfsetting>` or self-close `/>` will consume subsequent content as its body. Use `<cfsetting ... />` or `</cfsetting>` explicitly.

## cfml

### IE conditional comments

`<!--[if gt IE 8]><!-->` is parsed as a comment node. The expression inside (`gt IE 8`) is not evaluated — it's treated as comment content.

### `<cfsetting>` / `<cfprocessingdirective>` implicit close

These tags can be used with or without a body. When used without a closing tag, the grammar treats them as paired tags and consumes content until EOF or another implicit close trigger. Use self-closing syntax (`/>`) for bodyless usage.

### Dynamic tag names not fully evaluated

`<#expr#>` dynamic tag names are parsed and the hash expression is evaluated, but the scanner consumes the expression content for tag matching purposes. Open/close matching works positionally (any dynamic open matches any dynamic close).

## cfquery

### `queryExecute` with non-string first argument

`queryExecute(variable)` or `queryExecute(condition ? "sql1" : "sql2")` falls through to a regular function call (no SQL parsing). Only `queryExecute("SELECT ...")` with a string literal first argument gets SQL injection parsing.

### `+` before `<cfif>` blocks

The `+` concatenation operator allows an optional right operand to support patterns like `col1 + <cfif x>col2 + </cfif>col3`. This means a trailing `+` without a right operand won't produce a parse error.

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
