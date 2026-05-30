# Changelog

## [Unreleased]

### cfscript

- Support string literal as catch type (e.g. `catch("any" ex)`)
- Support case-insensitive `IN` / `OF` keywords in for-in loops

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
