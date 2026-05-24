; Indentation for cfquery (embedded SQL)
; See https://tree-sitter.github.io/tree-sitter/syntax-highlighting#indentation

; Parentheses (subqueries, IN lists, function args)
(parenthesized_query_node "(" @indent)
(parenthesized_query_node ")" @dedent)
