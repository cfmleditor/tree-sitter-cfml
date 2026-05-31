; Fold block CF tags
(cf_if_tag) @fold
(cf_output_tag) @fold
(cf_function_tag) @fold
(cf_query_tag) @fold
(cf_script_tag) @fold
(cf_xml_tag) @fold
(cf_savecontent_tag) @fold
(cf_tag (cf_end_tag)) @fold

; Fold HTML elements
(element) @fold

; Fold function definitions (inside cfscript blocks)
(function_declaration) @fold
(function_expression) @fold
(arrow_function) @fold

; Fold control flow
(if_statement) @fold
(for_statement) @fold
(for_in_statement) @fold
(while_statement) @fold
(do_statement) @fold
(switch_statement) @fold
(try_statement) @fold

; Fold blocks
(statement_block) @fold

; Fold comments
(cf_comment) @fold
(comment) @fold
