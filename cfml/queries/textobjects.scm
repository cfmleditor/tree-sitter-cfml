(cf_function_tag) @function.around

(function_declaration
  body: (statement_block) @function.inside) @function.around

(function_expression
  body: (statement_block) @function.inside) @function.around

(arrow_function
  body: (statement_block) @function.inside) @function.around

(element) @class.around

(cf_comment) @comment.around
(comment) @comment.around
