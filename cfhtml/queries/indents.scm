; Indentation for CFHTML (Lucee-style rules)
; See https://tree-sitter.github.io/tree-sitter/syntax-highlighting#indentation

(element
  (start_tag) @indent)

(element
  (end_tag) @dedent)

(script_element
  (start_tag) @indent)

(style_element
  (start_tag) @indent)
