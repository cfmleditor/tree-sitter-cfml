# Known Limitations

## cfscript

### `new` as a variable name

`new` cannot be used as an identifier (e.g. `var new = ""`). It conflicts with `new_expression` (`new Component()`).

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
