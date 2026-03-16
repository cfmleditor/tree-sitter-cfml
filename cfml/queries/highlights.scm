; Document and structure (from Lucee-style rules)
(program) @document
(doctype) @doctype
(entity) @constant
(html_text) @text

(erroneous_end_tag_name) @tag.error
(erroneous_cf_end_tag_name) @tag.error
(attribute_name) @attribute
(cf_attribute_name) @attribute
(attribute_value) @string
(raw_text) @embedded
(start_tag) @tag
(end_tag) @tag
(self_closing_tag) @tag
(cf_selfclose_tag) @tag
(cf_start_tag_with_selfclose) @tag
(cf_output_tag) @tag
(cf_script_tag) @tag
(cf_start_tag) @tag
(cf_end_tag) @tag
(cf_if_tag) @tag
(cf_query_tag) @tag
(cf_else_tag) @tag
(cf_elseif_tag) @tag
(cf_return_tag) @tag

; Variables
;----------

(identifier) @variable

; CFML scopes (variables, session, etc.)
(cf_scope_identifier) @namespace

; Properties
;-----------

(property_identifier) @property

; Function and method definitions
;--------------------------------

(function_expression
  name: (identifier) @function) @definition.function

(function_declaration
  name: (identifier) @function)

(function_declaration
  (access_type) @keyword)

(function_declaration
  (return_type) @type)

(generator_function
  name: (identifier) @function)

(generator_function_declaration
  name: (identifier) @function)

(method_definition
  name: [
    (property_identifier)
    (private_property_identifier)
  ] @function.method)

(method_definition
  name: (property_identifier) @constructor
  (#eq? @constructor "constructor"))

(formal_parameters
  (type) @type)

(formal_parameters
  (required) @keyword)

(pair
  key: (property_identifier) @function.method
  value: (function_expression))

(pair
  key: (property_identifier) @function.method
  value: (arrow_function))

(array) @expression

(cf_set_tag) @tag

(assignment_expression
  left: (member_expression
    property: (property_identifier) @function.method)
  right: (arrow_function))

(assignment_expression
  left: (member_expression
    property: (property_identifier) @function.method)
  right: (function_expression))

(variable_declarator
  name: (identifier) @function
  value: (arrow_function))

(variable_declarator
  name: (identifier) @function
  value: (function_expression))

(assignment_expression
  left: (identifier) @function
  right: (arrow_function))

(assignment_expression
  left: (identifier) @function
  right: (function_expression))

; Function and method calls
;--------------------------

(call_expression
  function: (identifier) @function.call)

(call_expression
  function: (member_expression
    property: [
      (property_identifier)
      (private_property_identifier)
    ] @function.method.call))

; Literals
;---------
((identifier) @variable.builtin
  (#eq? @variable.builtin "self"))

(cf_var) @keyword

[
  (true)
  (false)
] @boolean

[
  (null)
] @constant.builtin

[
  (comment)
  (cf_comment)
] @comment @spell

((comment) @comment.documentation
  (#lua-match? @comment.documentation "^/[*][*][^*].*[*]/$"))

((string_fragment) @keyword.directive
  (#eq? @keyword.directive "use strict"))

(string) @string
(text) @string
(hash_empty) @punctuation.special

(regex_pattern) @string.regexp
(regex_flags) @character.special

(regex
  "/" @punctuation.bracket) ; Regex delimiters

(number) @number

(hash_expression
  "#" @punctuation.special)

(unary_operator) @operator

((identifier) @number
  (#any-of? @number "NaN" "Infinity"))

; Punctuation
;------------
[
  ";"
  "."
  ","
  ":"
] @punctuation.delimiter

(binary_expression
  "/" @operator)

(ternary_expression
  [
    "?"
    ":"
  ] @keyword.conditional.ternary)

(elvis_expression
  "?:" @keyword.conditional.ternary)

[
  "-"
  "--"
  "-="
  "+"
  "++"
  "+="
  "*"
  "*="
  "**"
  "**="
  "/"
  "/="
  "%"
  "%="
  "<"
  "<<="
  "="
  "=="
  "==="
  "!"
  "!="
  "!=="
  "=>"
  ">"
  ">>="
  ">>>="
  "~"
  "^"
  "&"
  "|"
  "^="
  "&="
  "|="
  "&&"
  "||"
  "??"
  "&&="
  "||="
  "??="
] @operator

[
  "var"
  "let"
  "const"
  "function"
  "new"
  "return"
  "if"
  "else"
  "for"
  "while"
  "do"
  "switch"
  "case"
  "default"
  "break"
  "continue"
  "try"
  "catch"
  "finally"
  "throw"
  "in"
  "of"
  "instanceof"
  "async"
  "static"
  "export"
  "yield"
  "with"
] @keyword

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
  "<"
  ">"
  "</"
  "/>"
] @punctuation.bracket
