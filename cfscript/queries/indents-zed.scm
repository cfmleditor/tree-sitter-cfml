; Indentation for CFScript

; Curly braces
(statement_block "}" @end) @indent
(component_body "}" @end) @indent
(switch_body "}" @end) @indent
(object "}" @end) @indent
(object_pattern "}" @end) @indent
(named_imports "}" @end) @indent

; Parentheses
(formal_parameters ")" @end) @indent
(arguments ")" @end) @indent
(parenthesized_expression ")" @end) @indent
(for_statement ")" @end) @indent
(for_in_statement ")" @end) @indent
(catch_clause ")" @end) @indent
(query_expression ")" @end) @indent

; Square brackets
(array "]" @end) @indent
(array_pattern "]" @end) @indent
(subscript_expression "]" @end) @indent
(computed_property_name "]" @end) @indent
