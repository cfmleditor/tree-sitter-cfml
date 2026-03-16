; Identifiers
(identifier) @variable

; Literals
(number) @number
(string) @string
(comment) @comment

; Parameters and CF hash interpolation inside SQL
(parameter) @variable.parameter
(hash_param
  "#" @punctuation.special
  (cf_identifier_path) @variable
  "#" @punctuation.special)

; Keywords
[
  (keyword_select)
  (keyword_from)
  (keyword_where)
  (keyword_group_by)
  (keyword_order_by)
  (keyword_insert)
  (keyword_into)
  (keyword_values)
  (keyword_update)
  (keyword_set)
  (keyword_delete)
  (keyword_between)
  (keyword_in)
  (keyword_and)
  (keyword_or)
  (keyword_not)
  (keyword_like)
  (keyword_ilike)
  (keyword_union)
  (keyword_all)
  (keyword_top)
  (keyword_inner)
  (keyword_left)
  (keyword_right)
  (keyword_full)
  (keyword_outer)
  (keyword_join)
  (keyword_on)
  (keyword_having)
  (keyword_limit)
  (keyword_offset)
] @keyword

; Operators and punctuation
[
  "="
  "<>"
  "<"
  ">"
  "<="
  ">="
  "+"
  "-"
  "*"
  "/"
] @operator

[
  ","
] @punctuation.delimiter

[
  "("
  ")"
] @punctuation.bracket

