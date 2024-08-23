((script_element
  (raw_text) @injection.content)
 (#set! injection.language "javascript"))

((style_element
  (raw_text) @injection.content)
 (#set! injection.language "css"))

((cfscript_element
  (cfscript_content) @injection.content)
 (#set! injection.language "cfscript"))