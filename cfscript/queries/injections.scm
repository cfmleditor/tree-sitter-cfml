((cfml_template
  (cfml_template_content) @injection.content)
 (#set! injection.language "cfml"))

;; Inline Lucee java block, `a = java { ... }`
((java_class_block
  (java_class_content) @injection.content)
 (#set! injection.language "java"))
