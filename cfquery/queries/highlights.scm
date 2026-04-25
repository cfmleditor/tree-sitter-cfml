; Identifiers
(identifier) @variable

; Literals
(number) @number
(string) @string
(cfquery_single_quoted_string) @string
(cfquery_double_quoted_identifier
  "\"" @punctuation.bracket
  (identifier) @variable
  "\"" @punctuation.bracket)

(cfquery_bracket_identifier
  "[" @punctuation.bracket
  (identifier) @variable
  "]" @punctuation.bracket)
(cfquery_boolean_literal) @constant.builtin
(comment) @comment
(cf_comment) @comment

; Parameters and CF hash interpolation inside SQL
(parameter) @variable.parameter
(hash_param
  "#" @punctuation.special
  (cf_identifier_path) @variable
  "#" @punctuation.special)

(hash_expression
  "#" @punctuation.special)
(hash_empty) @punctuation.special

; Keywords
[
  (keyword_select)
  (keyword_distinct)
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
  (keyword_mod)
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
  (keyword_with)
  (keyword_as)
  (keyword_cast)
  (keyword_is)
  (keyword_null)
  (keyword_case)
  (keyword_when)
  (keyword_then)
  (keyword_else)
  (keyword_end)
  (keyword_exists)
  (keyword_truncate)
  (keyword_table)
  (keyword_fetch)
  (keyword_next)
  (keyword_rows)
  (keyword_only)
  (keyword_asc)
  (keyword_desc)
  (keyword_merge)
  (keyword_using)
  (keyword_matched)
  (keyword_exec)
  (keyword_execute)
  (keyword_call)
  (keyword_window)
  (keyword_partition_by)
  (keyword_for)
  (keyword_skip)
  (keyword_locked)
  (keyword_of)
  (keyword_pivot)
  (keyword_unpivot)
  (keyword_true)
  (keyword_false)
  (keyword_unknown)
  (keyword_over)
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

[
  ";"
] @punctuation.delimiter

