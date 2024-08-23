((script_element
  (raw_text) @injection.content)
 (#set! injection.language "javascript"))

((style_element
  (raw_text) @injection.content)
 (#set! injection.language "css"))

((cfscript_content) @injection.content (#set! injection.language "cfscript")) 

((cfoutput_content) @injection.content (#set! injection.language "cfml")) 

((cf_tag) @injection.content (#set! injection.language "cfml") (#set! injection.include-children) (#set! injection.combined))