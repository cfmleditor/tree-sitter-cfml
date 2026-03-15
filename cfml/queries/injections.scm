((script_element
  (raw_text) @injection.content)
 (#set! injection.language "javascript"))

((style_element
  (raw_text) @injection.content)
 (#set! injection.language "css"))

((cf_script_tag
  (cf_script_content) @injection.content)
 (#set! injection.language "cfscript"))
((cf_script_content) @injection.content (#set! injection.language "cfscript")) 