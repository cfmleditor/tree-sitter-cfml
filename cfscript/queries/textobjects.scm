(function_declaration
  body: (statement_block) @function.inside) @function.around

(function_expression
  body: (statement_block) @function.inside) @function.around

(arrow_function
  body: (statement_block) @function.inside) @function.around

(method_definition
  body: (statement_block) @function.inside) @function.around

(component
  body: (component_body) @class.inside) @class.around

(comment) @comment.around
