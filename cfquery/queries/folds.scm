; Fold CF tags inside queries
(cf_if_tag) @fold
(cf_tag (cf_end_tag)) @fold

; Fold functions
(function_declaration) @fold

; Fold control flow
(if_statement) @fold
(for_statement) @fold
(while_statement) @fold
(switch_statement) @fold
(try_statement) @fold

; Fold comments
(cf_comment) @fold
(comment) @fold
