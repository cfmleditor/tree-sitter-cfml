; CF tags
(erroneous_cf_end_tag_name) @tag.error
(cf_attribute_name) @attribute
(attribute_value) @string
(cf_selfclose_tag) @tag
(cf_start_tag_with_selfclose) @tag
(cf_set_tag) @tag
(cf_if_tag) @tag
(cf_else_tag) @tag
(cf_elseif_tag) @tag
(cf_return_tag) @tag
(cf_output_tag) @tag
(cf_script_tag) @tag
(cf_query_tag) @tag
(cf_xml_tag) @tag
(cf_start_tag) @tag
(cf_end_tag) @tag
(cf_tag) @tag
(cf_tag_name) @tag

; Variables
(identifier) @variable
(cf_scope_identifier) @namespace

; Properties
(property_identifier) @property
(shorthand_property_identifier) @property

; Function and method definitions
(function_expression
  name: (identifier) @function)

(function_declaration
  name: (identifier) @function)

(function_declaration
  (access_type) @keyword)

(function_declaration
  (return_type) @type)

(method_definition
  name: [
    (property_identifier)
    (private_property_identifier)
  ] @function.method)

(method_definition
  name: (property_identifier) @constructor
  (#eq? @constructor "constructor"))

(pair
  key: (property_identifier) @function.method
  value: [(function_expression) (arrow_function)])

(assignment_expression
  left: (member_expression
    property: (property_identifier) @function.method)
  right: [(function_expression) (arrow_function)])

(variable_declarator
  name: (identifier) @function
  value: [(function_expression) (arrow_function)])

(assignment_expression
  left: (identifier) @function
  right: [(function_expression) (arrow_function)])

; Function and method calls
(call_expression
  function: (identifier) @function.call)

(call_expression
  function: (member_expression
    property: [
      (property_identifier)
      (private_property_identifier)
    ] @function.method.call))

; Literals
((identifier) @variable.builtin
  (#eq? @variable.builtin "self"))

(this) @variable.builtin
(super) @variable.builtin

(cf_var) @keyword

[
  (true)
  (false)
] @boolean

[
  (null)
  (undefined)
] @constant.builtin

[
  (comment)
  (cf_comment)
] @comment @spell

((comment) @comment.documentation
  (#lua-match? @comment.documentation "^/[*][*][^*].*[*]/$"))

(string) @string
(hash_empty) @punctuation.special

(regex_pattern) @string.regexp
(regex_flags) @character.special

(regex
  "/" @punctuation.bracket)

(number) @number

(hash_expression
  "#" @punctuation.special)

(unary_operator) @operator

((identifier) @number
  (#any-of? @number "NaN" "Infinity"))

; Punctuation
[
  ";"
  "."
  ","
  ":"
  (optional_chain)
  (static_chain)
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
  (logical_or)
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
  "break"
  "continue"
  "try"
  "catch"
  "finally"
  "throw"
  "of"
  "instanceof"
  "static"
  "with"
] @keyword

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

; SQL keywords
[
  "select"
  "distinct"
  "from"
  "where"
  "group"
  "by"
  "having"
  "order"
  "limit"
  "offset"
  "join"
  "inner"
  "outer"
  "left"
  "right"
  "on"
  "and"
  "not"
  "in"
  "like"
  "between"
  "exists"
  "as"
  "insert"
  "into"
  "values"
  "update"
  "set"
  "delete"
  "create"
  "table"
  "drop"
  "alter"
  "add"
  "column"
  "primary"
  "key"
  "foreign"
  "references"
  "constraint"
  "unique"
  "check"
  "default"
  "index"
  "fulltext"
  "spatial"
] @keyword

; SQL data types
[
  "varchar"
  "char"
  "text"
  "blob"
  "int"
  "tinyint"
  "smallint"
  "mediumint"
  "bigint"
  "float"
  "double"
  "real"
  "decimal"
  "boolean"
  "date"
  "datetime"
  "timestamp"
  "time"
  "year"
  "enum"
  "auto_increment"
  "unsigned"
  "zerofill"
  "collate"
  "charset"
  "engine"
] @type.builtin

; SQL identifiers and values
(query_identifier) @variable
(query_alias
  right: _ @variable)

(query_star
  (star) @operator)

(query_number
  (number) @number)

(quoted_query_value
  (query_value) @string)
(double_quoted_query_value
  (query_value) @string)

(query_comma) @punctuation.delimiter
(query_semicolon) @punctuation.delimiter

(bracketed_query_value
  ["[" "]"] @punctuation.bracket)

(parenthesized_query_node
  ["(" ")"] @punctuation.bracket)

(query_assignment_expression
  "=" @operator)
