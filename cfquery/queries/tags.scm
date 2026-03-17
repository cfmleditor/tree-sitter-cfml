; Expose CF variables used inside SQL as symbols
(hash_param
  (cf_identifier_path) @variable.parameter)

; Capture the root scope of CF variables inside hashes (e.g. VARIABLES, ARGUMENTS, SESSION)
((hash_param
   (cf_identifier_path
     (identifier) @scope.root))
 (#set! role "cf-scope"))

; Capture table aliases from FROM clause in cfquery SQL
((cfquery_table_reference
   name: (identifier) @type
   alias: (identifier) @variable)
 (#set! role "table"))

; Capture column-like expressions in SELECT list (very loose)
((cfquery_select_list
   (cfquery_expression
     (_) @variable)
   (cfquery_expression
     (_) @variable))
 (#set! role "column"))

; NOTE: cfquery dialect trees do not currently contain full CF tag nodes,
; so we do not attempt to tag cfqueryparam-style tags here.
