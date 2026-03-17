((script_element
  (raw_text) @injection.content)
 (#set! injection.language "javascript"))

((style_element
  (raw_text) @injection.content)
 (#set! injection.language "css"))

((cf_script_tag
  (cf_script_content) @injection.content)
 (#set! injection.language "cfscript"))

;; SQL inside cfquery bodies
((cf_query_tag
  (cf_query_content) @injection.content)
 (#set! injection.language "cfquery"))