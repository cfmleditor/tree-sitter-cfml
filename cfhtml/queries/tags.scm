; Function definitions
(function_declaration
  name: (identifier) @name) @definition.function

(function_expression
  name: (identifier) @name) @definition.function

(method_definition
  name: (property_identifier) @name) @definition.method

; cffunction tag
(cf_tag
  (cf_start_tag
    (cf_tag_name) @_cffunction
    (tag_attributes
      (attribute
        (attribute_name) @_name
        (_ (attribute_value) @name))))
  (#eq? @_cffunction "function")
  (#eq? @_name "name")) @definition.function

; Function calls
(call_expression
  function: (identifier) @name) @reference.call

(call_expression
  function: (member_expression
    property: (property_identifier) @name)) @reference.call
