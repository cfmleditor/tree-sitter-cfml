;; SQL inside queryExecute(...) expression form
((query_expression
  (query_text) @injection.content)
 (#set! injection.language "cfquery"))

;; SQL in first string argument to QueryExecute(...)
((call_expression
  function: (identifier) @fn
  arguments: (arguments
    (string) @injection.content
    (_)*))
 (#eq? @fn "QueryExecute")
 (#set! injection.language "cfquery"))

