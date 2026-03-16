; Script function definitions
(function_declaration
  name: (identifier) @name) @definition.function

(function_expression
  name: (identifier) @name) @definition.function

(method_definition
  name: (property_identifier) @name) @definition.method

; Component definitions (tag-based)
(cf_tag
  (cf_start_tag
    (cf_tag_name) @_cfcomponent
    (tag_attributes
      (attribute
        (attribute_name) @_name
        (_ (attribute_value) @name))))
  (#match? @_cfcomponent "(?i)^component$")
  (#eq? @_name "name")) @definition.class

; CFML tags as definition points (Lucee-style; for outline/symbol list)
(cf_tag
  (cf_start_tag
    (cf_tag_name) @name)) @definition.tag

; CFML self-closing tags with name (e.g. <cffunction name="x" />)
(cf_tag
  (cf_start_tag_with_selfclose
    (cf_tag_name) @name)) @definition.tag

; HTML self-closing tags (e.g. <br />)
(self_closing_tag
  (tag_name) @name) @definition.tag

; cffunction tag
(cf_tag
  (cf_start_tag
    (cf_tag_name) @_cffunction
    (tag_attributes
      (attribute
        (attribute_name) @_name
        (_ (attribute_value) @name))))
  (#match? @_cffunction "(?i)^function$")
  (#eq? @_name "name")) @definition.function

; Function calls (script)
(call_expression
  function: (identifier) @name) @reference.call

(call_expression
  function: (member_expression
    property: (property_identifier) @name)) @reference.call
