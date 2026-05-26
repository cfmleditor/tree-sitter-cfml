((script_element
  (script_text) @injection.content)
 (#set! injection.language "javascript"))

;; JS content inside CF tags within script elements (at varying nesting depths
;; to cover cfif/cfelseif/cfelse branches and nested CF tags).
;; Tree-sitter queries lack descendant matching, so explicit depths are needed.
((script_element (_                         (html_text) @injection.content)) (#set! injection.language "javascript"))
((script_element (_ (_                      (html_text) @injection.content))) (#set! injection.language "javascript"))
((script_element (_ (_ (_                   (html_text) @injection.content)))) (#set! injection.language "javascript"))
((script_element (_ (_ (_ (_                (html_text) @injection.content))))) (#set! injection.language "javascript"))
((script_element (_ (_ (_ (_ (_             (html_text) @injection.content)))))) (#set! injection.language "javascript"))
((script_element (_ (_ (_ (_ (_ (_          (html_text) @injection.content))))))) (#set! injection.language "javascript"))
((script_element (_ (_ (_ (_ (_ (_ (_       (html_text) @injection.content)))))))) (#set! injection.language "javascript"))
((script_element (_ (_ (_ (_ (_ (_ (_ (_    (html_text) @injection.content))))))))) (#set! injection.language "javascript"))

((style_element
  (style_text) @injection.content)
 (#set! injection.language "css"))

;; CSS content inside CF tags within style elements
((style_element (_                         (html_text) @injection.content)) (#set! injection.language "css"))
((style_element (_ (_                      (html_text) @injection.content))) (#set! injection.language "css"))
((style_element (_ (_ (_                   (html_text) @injection.content)))) (#set! injection.language "css"))
((style_element (_ (_ (_ (_                (html_text) @injection.content))))) (#set! injection.language "css"))
((style_element (_ (_ (_ (_ (_             (html_text) @injection.content)))))) (#set! injection.language "css"))
((style_element (_ (_ (_ (_ (_ (_          (html_text) @injection.content))))))) (#set! injection.language "css"))
((style_element (_ (_ (_ (_ (_ (_ (_       (html_text) @injection.content)))))))) (#set! injection.language "css"))
((style_element (_ (_ (_ (_ (_ (_ (_ (_    (html_text) @injection.content))))))))) (#set! injection.language "css"))

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

;; cfsavecontent body injections
((cf_savecontent_body_script
  (cf_savecontent_content) @injection.content)
 (#set! injection.language "javascript"))

((cf_savecontent_body_css
  (cf_savecontent_content) @injection.content)
 (#set! injection.language "css"))

((cf_savecontent_body_xml
  (cf_savecontent_content) @injection.content)
 (#set! injection.language "xml"))

((cf_savecontent_body_html
  (cf_savecontent_content) @injection.content)
 (#set! injection.language "html"))

((cf_savecontent_body_sql
  (cf_savecontent_content) @injection.content)
 (#set! injection.language "cfquery"))