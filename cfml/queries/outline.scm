; Function definitions
(function_declaration
  name: (identifier) @name) @item

(function_expression
  name: (identifier) @name) @item

(method_definition
  name: (property_identifier) @name) @item

; cffunction tag
(cf_function_tag
  (cf_attribute
    (cf_attribute_name) @_name
    (quoted_cf_attribute_value
      (attribute_value) @name))
  (#eq? @_name "name")) @item
