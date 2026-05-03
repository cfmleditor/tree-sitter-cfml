# Changelog

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
