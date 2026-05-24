; Indentation for CFScript
; See https://tree-sitter.github.io/tree-sitter/syntax-highlighting#indentation

; Curly braces
(statement_block "{" @indent)
(statement_block "}" @dedent)
(component_body "{" @indent)
(component_body "}" @dedent)
(switch_body "{" @indent)
(switch_body "}" @dedent)
(object "{" @indent)
(object "}" @dedent)
(object_pattern "{" @indent)
(object_pattern "}" @dedent)
(named_imports "{" @indent)
(named_imports "}" @dedent)

; Parentheses
(formal_parameters "(" @indent)
(formal_parameters ")" @dedent)
(arguments "(" @indent)
(arguments ")" @dedent)
(parenthesized_expression "(" @indent)
(parenthesized_expression ")" @dedent)
(for_statement "(" @indent)
(for_statement ")" @dedent)
(for_in_statement "(" @indent)
(for_in_statement ")" @dedent)
(catch_clause "(" @indent)
(catch_clause ")" @dedent)
(query_expression "(" @indent)
(query_expression ")" @dedent)

; Square brackets
(array "[" @indent)
(array "]" @dedent)
(array_pattern "[" @indent)
(array_pattern "]" @dedent)
(subscript_expression "[" @indent)
(subscript_expression "]" @dedent)
(computed_property_name "[" @indent)
(computed_property_name "]" @dedent)
