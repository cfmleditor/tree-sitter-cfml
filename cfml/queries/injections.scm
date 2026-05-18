((script_element
  (script_text) @injection.content)
 (#set! injection.language "javascript"))

;; JS content inside CF tags within script elements
((script_element
  (_
    (html_text) @injection.content))
 (#set! injection.language "javascript"))

((style_element
  (style_text) @injection.content)
 (#set! injection.language "css"))

;; CSS content inside CF tags within style elements
((style_element
  (_
    (html_text) @injection.content))
 (#set! injection.language "css"))

((cf_script_tag
  (cf_script_content) @injection.content)
 (#set! injection.language "cfscript"))

((component_file
  (cf_component_content) @injection.content)
 (#set! injection.language "cfscript"))

;; SQL inside cfquery bodies
((cf_query_tag
  (cf_query_content) @injection.content)
 (#set! injection.language "cfquery"))