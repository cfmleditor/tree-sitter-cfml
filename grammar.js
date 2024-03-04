/**
 * @file CFML grammar for tree-sitter
 * @author Gareth Edwards
 * @license MIT
 */

/* eslint-disable arrow-parens */
/* eslint-disable camelcase */
/* eslint-disable-next-line spaced-comment */
/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'cfml',

  extras: $ => [
    $.cf_comment,
    $.cf_script_comment,
    /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/,
  ],

  // @ts-ignore
  externals: $ => [
    $._automatic_semicolon,
    $._ternary_qmark,
    '||',
    $._start_tag_name,
    $._script_start_tag_name,
    $._style_start_tag_name,
    $._end_tag_name,
    $.erroneous_end_tag_name,
    '/>',
    $._implicit_end_tag,
    $.raw_text,
    $.cf_comment,
  ],

  supertypes: $ => [
    $.statement,
    $.declaration,
    $.expression,
    $.primary_expression,
    $.pattern,
  ],

  inline: $ => [
    $._call_signature,
    $._formal_parameter,
    $.statement,
    $._expressions,
    $._semicolon,
    $._identifier,
    $._reserved_identifier,
    $._lhs_expression,
  ],

  precedences: $ => [
    [
      'member',
      'call',
      $.update_expression,
      'unary_void',
      'binary_exp',
      'binary_times',
      'binary_plus',
      'binary_shift',
      'binary_compare',
      'binary_relation',
      'binary_equality',
      'bitwise_and',
      'bitwise_xor',
      'bitwise_or',
      'logical_and',
      'logical_or',
      'ternary',
      $.sequence_expression,
      $.arrow_function,
    ],
    ['assign', $.primary_expression],
    ['member', 'new', 'call', $.expression],
    ['declaration', 'literal'],
    [$.primary_expression, $.statement_block, 'object'],
    [$.import_statement, $.import],
    // [$.export_statement, $.primary_expression],
    [$.lexical_declaration, $.primary_expression],
  ],

  conflicts: $ => [
    // [$.cf_dblquotes_empty, $.cf_dblquotes],
    // [$.cf_singlequotes_empty, $.cf_singlequotes],
    [$.cf_bracket_expression, $.cf_function_call],
    // [$.cf_return, $.cf_function_call],
    // [$.cf_variable, $.text],
    [$.cf_function_call, $.cf_associative],
    [$.cf_function_call, $._cf_expression],
    // [$.cf_script_expression, $._cf_member_expression],
    // [$.cf_if_tag, $.binary_expression],
    // [$.cf_if_tag, $.call_expression],
    // [$.cf_if_tag, $.subscript_expression],
    // [$.cf_if_tag, $.update_expression],
    // [$.cf_ternary, $.cf_objectkeyassign],
    // [$.cf_function_access, $.cf_function_returntype],
    // [$.cf_function_argument_name, $.cf_function_argument_type],

    // Tag
    [$.cf_zip_tag, $.cf_zip_tag_standalone],
    [$.cf_attribute, $.binary_expression],
    [$.cf_transaction_tag, $.cf_transaction_tag_standalone],

    // Script
    [$.primary_expression, $.variable_declaration],
    [$.primary_expression, $.function_expression],
    [$.primary_expression, $._property_name],
    [$.primary_expression, $._property_name, $.arrow_function],
    [$.primary_expression, $.arrow_function],
    [$.primary_expression, $.method_definition],
    [$.primary_expression, $.rest_pattern],
    [$.primary_expression, $.pattern],
    [$.primary_expression, $._for_header],
    [$.array, $.array_pattern],
    [$.object, $.object_pattern],
    [$.assignment_expression, $.pattern],
    [$.assignment_expression, $.object_assignment_pattern],
    [$.labeled_statement, $._property_name],
    [$.computed_property_name, $.array],
    [$.binary_expression, $._initializer],

  ],

  rules: {

    program: $ => repeat(
      $.cf_node,
    ),

    doctype: $ => seq(
      '<!',
      alias($._doctype, 'doctype'),
      /[^>]+/,
      '>',
    ),

    _doctype: _ => /[Dd][Oo][Cc][Tt][Yy][Pp][Ee]/,

    cf_condition: ($) => choice(
      /([^<>\[\]="\';]+)/,
    ),

    cf_tag_start: $ => '<',
    _cf_tag_end: $ => '>',
    cf_tag_selfclose_end: $ => choice('/>', $._cf_tag_end),
    text: $ => /[^<>&\s]([^<>&]*[^<>&\s])?/,
    cf_variable: $ => /[a-zA-Z0-9_-]+/,
    cf_tag_close: $ => /<\/cf/i,
    cf_true: $ => keyword('true'),
    cf_false: $ => keyword('false'),
    cf_operator: $ => choice(
      keyword('and'),
      keyword('or'),
      keyword('eq'),
      keyword('neq'),
      keyword('gte'),
      keyword('lte'),
      keyword('lt'),
      keyword('is'),
      keyword('gt'),
      '>=',
      '===',
      '+',
      '*',
      '/',
      '-',
      '==',
      '<=',
      '&&',
      '||',
    ),

    cf_prefix_operator: $ => choice(
      keyword('NOT'),
      '!',
    ),

    cf_node: $ => choice(
      $.doctype,
      $.entity,
      $.element,
      $._cf_tag,
      $.cf_hash,
      $.cf_hash_empty,
      $.script_element,
      $.style_element,
      $.cf_script,
      $.text,
    ),

    cf_script: $ => seq(
      keyword('<cfscript>'),
      repeat(
        $.statement,
      ),
      keyword('</cfscript>'),
    ),

    // cf_script_expression: $ => choice(
    //   seq($._cf_expression, $._semicolon),
    // ),

    element: $ => choice(
      seq(
        $.start_tag,
        repeat($.cf_node),
        choice($.end_tag, $._implicit_end_tag),
      ),
      $.self_closing_tag,
    ),

    script_element: $ => seq(
      alias($.script_start_tag, $.start_tag),
      optional($.raw_text),
      $.end_tag,
    ),

    start_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat($.attribute),
      '>',
    ),

    script_start_tag: $ => seq(
      '<',
      alias($._script_start_tag_name, $.tag_name),
      repeat($.attribute),
      '>',
    ),

    style_start_tag: $ => seq(
      '<',
      alias($._style_start_tag_name, $.tag_name),
      repeat($.attribute),
      '>',
    ),

    self_closing_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat($.attribute),
      '/>',
    ),

    end_tag: $ => seq(
      '</',
      alias($._end_tag_name, $.tag_name),
      '>',
    ),

    style_element: $ => seq(
      alias($.style_start_tag, $.start_tag),
      optional($.raw_text),
      $.end_tag,
    ),

    cf_hash: $ => prec.right(2, seq(
      '#',
      $.expression,
      '#',
    )),

    cf_hash_empty: $ => prec.right(1, seq(
      token('##'),
    )),

    cf_associative: $ => seq(
      '[',
      optional($._cf_expression),
      ']',
    ),

    cf_bracket_function: $ => seq(
      '{',
      repeat($.statement),
      '}',
    ),

    cf_bracket_expression: $ => seq(
      '{',
      repeat($._cf_expression),
      '}',
    ),

    // _cf_function_statement: $ => choice(
    //   // Maybe nested functions in the future ?? $.cf_function,
    //   $.cf_expression_statement,
    //   $.cf_return,
    // ),

    cf_expression_statement: $ => seq(
      $._cf_expression,
      $._semicolon,
    ),

    _cf_assignment_expression: $ => prec.right(1, seq(
      $._cf_expression,
      $.cf_assignment,
      $._cf_expression,
    )),

    cf_concat: $ => seq(
      '&',
    ),

    _cf_expression: $ => choice(
      $._cf_member_expression,
      prec.right(1, $.cf_hash),
      prec.right(2, $.function_expression),
      // prec.right(2, $.cf_switch_statement),
      // prec.right(2, $.cf_for_statement),
      // prec.right(2, $.cf_if_statement),
      prec.right(2, seq(optional($._cf_expression), $.cf_period, $._cf_expression)),
      prec.right(2, seq(optional($._cf_expression), $.cf_concat, $._cf_expression)),
      prec.right(2, seq($._cf_expression, $.cf_objectkeyassign, $._cf_expression)),
      prec.right(4, seq($.cf_period, $._cf_expression)),
      prec.right(4, seq($.cf_comma, $._cf_expression)),
      prec.right(5, seq($.unary_operator, $._cf_expression)),
      prec.right(5, seq($._cf_expression, $.cf_operator, $._cf_expression)),
      prec.right(6, $.cf_function_call),
      prec.right(6, seq(optional($._cf_expression), $.cf_ternary)),
      prec.right(6, $.cf_expression_parens),
      prec.right(6, $.cf_true),
      prec.right(6, $.cf_false),
    ),

    // cf_switch_statement: $ => seq(
    //   $.cf_switch,
    //   repeat($.cf_case_statement),
    //   optional(
    //     $.cf_defaultcase,
    //   ),
    //   '}',
    // ),

    // cf_case_statement: $ => seq(
    //   $.cf_case,
    //   optional($._cf_expression),
    //   optional($.cf_break),
    // ),

    // cf_defaultcase: $ => seq(
    //   keyword('defaultcase:'),
    //   optional($._cf_expression),
    // ),

    // cf_switch: $ => seq(
    //   keyword('switch'),
    //   $.cf_expression_parens,
    //   '{',
    // ),

    // cf_if_statement: $ => seq(
    //   $.cf_if,
    //   repeat($.cf_script_expression),
    //   token('}'),
    //   repeat($.cf_elseif),
    //   optional(
    //     $.cf_else,
    //   ),
    // ),

    // cf_if: $ => seq(
    //   keyword('if'),
    //   $.cf_expression_parens,
    //   '{',
    // ),

    // cf_for_statement: $ => seq(
    //   keyword('for'),
    //   $.cf_expression_parens,
    //   '{',
    //   repeat($.cf_script_expression),
    //   '}',
    // ),

    // cf_elseif: $ => seq(
    //   keyword('else if'),
    //   $.cf_expression_parens,
    //   '{',
    //   repeat($.cf_script_expression),
    //   '}',
    // ),

    // cf_else: $ => seq(
    //   keyword('else'),
    //   '{',
    //   repeat($.cf_script_expression),
    //   '}',
    // ),

    // cf_case: $ => seq(
    //   keyword('case'),
    //   $._cf_expression,
    //   keyword(':'),
    // ),

    // cf_break: $ => seq(
    //   keyword('break'),
    //   optional(';'),
    // ),

    _cf_member_expression: $ => choice(
      $._cf_assignment_expression,
      // prec.right(1, $.cf_dblquotes),
      prec.right(1, $.string),
      prec.right(1, $.cf_variable),
      // prec.right(2, $.cf_dblquotes_empty),
      // prec.right(1, $.cf_singlequotes),
      // prec.right(2, $.cf_singlequotes_empty),
      prec.right(2, seq(optional($._cf_expression), $.cf_associative)),
      prec.right(6, $.cf_bracket_expression),
    ),

    cf_component_tag: $ => seq(
      keyword('<cfcomponent'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cfcomponent>'),
    ),

    // cf_function: $ => seq(
    //   $.cf_function_keyword,
    //   optional($.cf_function_name),
    //   $.cf_function_arguments,
    //   $.cf_bracket_function,
    // ),

    // cf_return: $ => seq(
    //   $.cf_return_keyword,
    //   $._cf_expression,
    // ),

    cf_function_call: $ => seq(
      $._cf_member_expression,
      $.arguments,
    ),

    cf_period: $ => /\./,
    cf_comma: $ => ',',
    cf_assignment: $ => '=',
    cf_objectkeyassign: $ => ':',

    // cf_singlequotes: $ => seq(
    //   '\'',
    //   alias(
    //     repeat(
    //       choice(
    //         alias(/[^'#]+/, $.text),
    //         $.cf_hash,
    //         $.cf_hash_empty,
    //       ),
    //     ),
    //     $.quoted_text,
    //   ),
    //   '\'',
    // ),

    // cf_singlequotes_empty: $ => seq(
    //   '\'',
    //   '\'',
    // ),

    // cf_dblquotes: $ => seq(
    //   '"',
    //   alias(
    //     repeat(
    //       choice(
    //         /[^"]/,
    //         $.cf_hash,
    //         $.cf_hash_empty,
    //       ),
    //     ),
    //     $.quoted_text,
    //   ),
    //   '"',
    // ),

    // cf_dblquotes_empty: $ => seq(
    //   '"',
    //   '"',
    // ),

    // cf_function_call_arguments: $ => seq(
    //   '(',
    //   repeat(
    //     seq(
    //       $._cf_expression,
    //       optional($.cf_comma),
    //     ),
    //   ),
    //   ')',
    // ),

    cf_expression_parens: $ => seq(
      '(',
      repeat($._cf_expression),
      ')',
    ),

    cf_ternary: $ => seq(
      keyword('?'),
      $._cf_expression,
      keyword(':'),
      $._cf_expression,
    ),

    cf_function_name: $ => choice(
      $.cf_variable,
    ),

    // cf_function_access: $ => choice(
    //   $.cf_variable,
    // ),

    // cf_function_returntype: $ => choice(
    //   $.cf_variable,
    // ),

    // cf_function_argument_required: $ => choice(
    //   keyword('required'),
    // ),

    // cf_function_argument_type: $ => choice(
    //   $.cf_variable,
    // ),

    // cf_function_argument_name: $ => choice(
    //   $.cf_variable,
    // ),

    // cf_function_arguments: $ => seq(
    //   '(',
    //   repeat(seq(
    //     optional($.cf_function_argument_required),
    //     optional($.cf_function_argument_type),
    //     $.cf_function_argument_name,
    //     optional(seq(
    //       '=',
    //       $.expression,
    //     )),
    //     optional(','),
    //   )),
    //   ')',
    // ),

    cf_function_tag: $ => seq(
      keyword('<cffunction'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cffunction>'),
    ),

    cf_query_tag: $ => seq(
      keyword('<cfquery'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cfquery>'),
    ),

    cf_transaction_tag_standalone: $ => prec.right(1, seq(
      keyword('<cftransaction'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    )),

    cf_transaction_tag: $ => prec.right(2, seq(
      keyword('<cftransaction'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cftransaction>'),
    )),

    cf_try_statement_tag: $ => seq(
      $.cf_try_tag,
      $.cf_catch_tag,
      keyword('</cftry>'),
    ),

    cf_try_tag: $ => seq(
      keyword('<cftry'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
    ),

    cf_switch_statement_tag: $ => seq(
      $.cf_switch_tag,
      repeat($.cf_case_tag),
      optional($.cf_defaultcase_tag),
      keyword('</cfswitch>'),
    ),

    cf_switch_tag: $ => seq(
      keyword('<cfswitch'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
    ),

    cf_wddx_tag: $ => seq(
      keyword('<cfwddx'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_case_tag: $ => seq(
      keyword('<cfcase'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cfcase>'),
    ),

    cf_defaultcase_tag: $ => seq(
      keyword('<cfdefaultcase'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cfdefaultcase>'),
    ),

    cf_catch_tag: $ => seq(
      keyword('<cfcatch'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cfcatch>'),
    ),

    cf_loop_tag: $ => seq(
      keyword('<cfloop'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($.cf_node),
      keyword('</cfloop>'),
    ),

    cf_argument_tag: $ => seq(
      keyword('<cfargument'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_file_tag: $ => seq(
      keyword('<cffile'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_throw_tag: $ => seq(
      keyword('<cfthrow'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_image_tag: $ => seq(
      keyword('<cfimage'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_directory_tag: $ => seq(
      keyword('<cfdirectory'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_include_tag: $ => seq(
      keyword('<cfinclude'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_continue_tag: $ => seq(
      keyword('<cfcontinue'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_zip_tag: $ => seq(
      keyword('<cfzip'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
      repeat($.cf_node),
      keyword('</cfzip>'),
    ),

    cf_zip_tag_standalone: $ => seq(
      keyword('<cfzip'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_savecontent_tag: $ => seq(
      keyword('<cfsavecontent'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
      repeat($.cf_node),
      keyword('</cfsavecontent>'),
    ),

    cf_output_tag: $ => seq(
      keyword('<cfoutput'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
      repeat($.cf_node),
      keyword('</cfoutput>'),
    ),

    cf_rethrow_tag: $ => seq(
      keyword('<cfrethrow'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_break_tag: $ => seq(
      keyword('<cfbreak'),
      $.cf_tag_selfclose_end,
    ),

    cf_return_tag: $ => seq(
      keyword('<cfreturn'),
      $._cf_expression,
      $.cf_tag_selfclose_end,
    ),

    cf_if_statement_tag: $ => seq(
      $.cf_if_tag,
      repeat($.cf_elseif_tag),
      optional($.cf_else_tag),
      $.cf_if_end_tag,
    ),

    cf_if_tag: $ => seq(
      keyword('<cfif'),
      repeat($._cf_expression),
      $._cf_tag_end,
      repeat($.cf_node),
    ),

    cf_set_tag: $ => seq(
      keyword('<cfset'),
      optional($.cf_var),
      $._cf_expression,
      $.cf_tag_selfclose_end,
    ),

    cf_elseif_tag: $ => seq(
      keyword('<cfelseif'),
      repeat($._cf_expression),
      $._cf_tag_end,
      repeat($.cf_node),
    ),

    cf_else_tag: $ => seq(
      keyword('<cfelse'),
      $._cf_tag_end,
      repeat($.cf_node),
    ),

    cf_if_end_tag: $ => seq(
      keyword('</cfif>'),
    ),

    attribute: $ => seq(
      $.attribute_name,
      optional(seq(
        '=',
        choice(
          $.attribute_value,
          $.quoted_attribute_value,
        ),
      )),
    ),

    attribute_name: _ => /[^<>"'/=\s]+/,

    attribute_value: _ => /[^<>"'=\s]+/,

    cf_attribute: $ => seq(
      $.cf_attribute_name,
      optional(seq(
        '=',
        $.expression,
      )),
    ),

    cf_attribute_name: _ => /[^<>"\'/=\s]+/,

    // attribute_value: _ => /[^<>"'=\s]+/,

    _cf_tag: $ => choice(
      $.cf_if_statement_tag,
      $.cf_try_statement_tag,
      $.cf_switch_statement_tag,
      $.cf_transaction_tag,
      $.cf_transaction_tag_standalone,
      $.cf_set_tag,
      $.cf_file_tag,
      $.cf_throw_tag,
      $.cf_image_tag,
      $.cf_include_tag,
      $.cf_continue_tag,
      $.cf_directory_tag,
      $.cf_savecontent_tag,
      $.cf_output_tag,
      $.cf_zip_tag,
      $.cf_zip_tag_standalone,
      $.cf_rethrow_tag,
      $.cf_wddx_tag,
      alias($.cf_component_tag, $.cf_component),
      alias($.cf_function_tag, $.cf_function),
      alias($.cf_query_tag, $.cf_query),
      alias($.cf_argument_tag, $.cf_argument),
      alias($.cf_loop_tag, $.cf_loop),
      alias($.cf_break_tag, $.cf_break),
      // alias($.cf_return_tag, $.cf_return),
    ),

    // _cf_statement: $ => choice(
    //   prec.right(1,$.cf_dblquotes),
    //   prec.right(2,$.cf_dblquotes_empty),
    //   prec.right(3,$.cf_parens),
    //   prec.right(4,$.cf_associative),
    //   prec.right(5,seq($._cf_expression,$.cf_assignment,$._cf_expression)),
    // ),

    entity: _ => /&(#([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});/,

    quoted_attribute_value: $ => choice(
      seq('\'', optional(alias(/[^']+/, $.attribute_value)), '\''),
      seq('"', optional(alias(/[^"]+/, $.attribute_value)), '"'),
    ),

    cf_var: $ => keyword('var'),
    cf_function_keyword: $ => keyword('function'),
    cf_component_keyword: $ => keyword('component'),
    cf_argument_keyword: $ => keyword('argument'),
    cf_return_keyword: $ => keyword('return'),

    cf_script_comment: $ => choice(
      token(choice(
        seq('//', /.*/),
        seq(
          '/*',
          /[^*]*\*+([^/*][^*]*\*+)*/,
          '/',
        ),
      )),
    ),

    namespace_export: $ => seq(
      '*', 'as', $._module_export_name,
    ),

    export_clause: $ => seq(
      '{',
      commaSep($.export_specifier),
      optional(','),
      '}',
    ),

    export_specifier: $ => seq(
      field('name', $._module_export_name),
      optional(seq(
        'as',
        field('alias', $._module_export_name),
      )),
    ),

    _module_export_name: $ => choice(
      $.identifier,
      $.string,
    ),

    declaration: $ => choice(
      $.function_declaration,
      $.generator_function_declaration,
      // $.class_declaration,
      $.lexical_declaration,
      $.variable_declaration,
    ),

    //
    // Import declarations
    //

    import: _ => token('import'),

    import_statement: $ => seq(
      'import',
      choice(
        seq($.import_clause, $._from_clause),
        field('source', $.string),
      ),
      optional($.import_attribute),
      $._semicolon,
    ),

    import_clause: $ => choice(
      $.namespace_import,
      $.named_imports,
      seq(
        $.identifier,
        optional(seq(
          ',',
          choice(
            $.namespace_import,
            $.named_imports,
          ),
        )),
      ),
    ),

    _from_clause: $ => seq(
      'from', field('source', $.string),
    ),

    namespace_import: $ => seq(
      '*', 'as', $.identifier,
    ),

    named_imports: $ => seq(
      '{',
      commaSep($.import_specifier),
      optional(','),
      '}',
    ),

    import_specifier: $ => choice(
      field('name', $.identifier),
      seq(
        field('name', $._module_export_name),
        'as',
        field('alias', $.identifier),
      ),
    ),

    import_attribute: $ => seq('with', $.object),

    statement: $ => choice(
      // $.export_statement,
      // $.import_statement,
      // $.debugger_statement,
      $.expression_statement,
      $.declaration,
      $.statement_block,

      $.if_statement,
      $.switch_statement,
      $.for_statement,
      $.for_in_statement,
      $.while_statement,
      $.do_statement,
      $.try_statement,
      $.with_statement,

      $.break_statement,
      $.continue_statement,
      $.return_statement,
      $.throw_statement,
      $.empty_statement,
      $.labeled_statement,
    ),

    expression_statement: $ => seq(
      $._expressions,
      $._semicolon,
    ),

    variable_declaration: $ => seq(
      'var',
      commaSep1($.variable_declarator),
      $._semicolon,
    ),

    lexical_declaration: $ => seq(
      field('kind', choice('let', 'const')),
      commaSep1($.variable_declarator),
      $._semicolon,
    ),

    variable_declarator: $ => seq(
      field('name', choice($.identifier, $._destructuring_pattern)),
      optional($._initializer),
    ),

    statement_block: $ => prec.right(seq(
      '{',
      repeat($.statement),
      '}',
      optional($._automatic_semicolon),
    )),

    else_clause: $ => seq('else', $.statement),

    if_statement: $ => prec.right(seq(
      'if',
      field('condition', $.parenthesized_expression),
      field('consequence', $.statement),
      optional(field('alternative', $.else_clause)),
    )),

    switch_statement: $ => seq(
      'switch',
      field('value', $.parenthesized_expression),
      field('body', $.switch_body),
    ),

    for_statement: $ => seq(
      'for',
      '(',
      field('initializer', choice(
        $.lexical_declaration,
        $.variable_declaration,
        $.expression_statement,
        $.empty_statement,
      )),
      field('condition', choice(
        $.expression_statement,
        $.empty_statement,
      )),
      field('increment', optional($._expressions)),
      ')',
      field('body', $.statement),
    ),

    for_in_statement: $ => seq(
      'for',
      optional('await'),
      $._for_header,
      field('body', $.statement),
    ),

    _for_header: $ => seq(
      '(',
      choice(
        field('left', choice(
          $._lhs_expression,
          $.parenthesized_expression,
        )),
        seq(
          field('kind', 'var'),
          field('left', choice(
            $.identifier,
            $._destructuring_pattern,
          )),
          optional($._initializer),
        ),
        seq(
          field('kind', choice('let', 'const')),
          field('left', choice(
            $.identifier,
            $._destructuring_pattern,
          )),
        ),
      ),
      field('operator', choice('in', 'of')),
      field('right', $._expressions),
      ')',
    ),

    while_statement: $ => seq(
      'while',
      field('condition', $.parenthesized_expression),
      field('body', $.statement),
    ),

    do_statement: $ => prec.right(seq(
      'do',
      field('body', $.statement),
      'while',
      field('condition', $.parenthesized_expression),
      optional($._semicolon),
    )),

    try_statement: $ => seq(
      'try',
      field('body', $.statement_block),
      optional(field('handler', $.catch_clause)),
      optional(field('finalizer', $.finally_clause)),
    ),

    with_statement: $ => seq(
      'with',
      field('object', $.parenthesized_expression),
      field('body', $.statement),
    ),

    break_statement: $ => seq(
      'break',
      field('label', optional(alias($.identifier, $.statement_identifier))),
      $._semicolon,
    ),

    continue_statement: $ => seq(
      'continue',
      field('label', optional(alias($.identifier, $.statement_identifier))),
      $._semicolon,
    ),

    debugger_statement: $ => seq(
      'debugger',
      $._semicolon,
    ),

    return_statement: $ => seq(
      'return',
      optional($._expressions),
      $._semicolon,
    ),

    throw_statement: $ => seq(
      'throw',
      $._expressions,
      $._semicolon,
    ),

    empty_statement: _ => ';',

    labeled_statement: $ => prec.dynamic(-1, seq(
      field('label', alias(choice($.identifier, $._reserved_identifier), $.statement_identifier)),
      ':',
      field('body', $.statement),
    )),

    //
    // Statement components
    //

    switch_body: $ => seq(
      '{',
      repeat(choice($.switch_case, $.switch_default)),
      '}',
    ),

    switch_case: $ => seq(
      'case',
      field('value', $._expressions),
      ':',
      field('body', repeat($.statement)),
    ),

    switch_default: $ => seq(
      'default',
      ':',
      field('body', repeat($.statement)),
    ),

    catch_clause: $ => seq(
      'catch',
      optional(seq('(', field('parameter', choice($.identifier, $._destructuring_pattern)), ')')),
      field('body', $.statement_block),
    ),

    finally_clause: $ => seq(
      'finally',
      field('body', $.statement_block),
    ),

    parenthesized_expression: $ => seq(
      '(',
      $._expressions,
      ')',
    ),

    //
    // Expressions
    //
    _expressions: $ => choice(
      $.expression,
      $.sequence_expression,
    ),

    expression: $ => choice(
      $.primary_expression,
      $.assignment_expression,
      $.augmented_assignment_expression,
      $.await_expression,
      $.unary_expression,
      $.binary_expression,
      $.ternary_expression,
      $.update_expression,
      $.new_expression,
      $.yield_expression,
    ),

    primary_expression: $ => choice(
      $.subscript_expression,
      $.member_expression,
      $.parenthesized_expression,
      $._identifier,
      alias($._reserved_identifier, $.identifier),
      $.this,
      $.super,
      $.number,
      $.string,
      // $.template_string,
      $.regex,
      $.true,
      $.false,
      $.null,
      $.object,
      $.array,
      $.function_expression,
      $.arrow_function,
      $.generator_function,
      $.class,
      $.meta_property,
      $.call_expression,
    ),

    yield_expression: $ => prec.right(seq(
      'yield',
      choice(
        seq('*', $.expression),
        optional($.expression),
      ))),

    object: $ => prec('object', seq(
      '{',
      commaSep(optional(choice(
        $.pair,
        $.spread_element,
        $.method_definition,
        alias(
          choice($.identifier, $._reserved_identifier),
          $.shorthand_property_identifier,
        ),
      ))),
      '}',
    )),

    object_pattern: $ => prec('object', seq(
      '{',
      commaSep(optional(choice(
        $.pair_pattern,
        $.rest_pattern,
        $.object_assignment_pattern,
        alias(
          choice($.identifier, $._reserved_identifier),
          $.shorthand_property_identifier_pattern,
        ),
      ))),
      '}',
    )),

    assignment_pattern: $ => seq(
      field('left', $.pattern),
      '=',
      field('right', $.expression),
    ),

    object_assignment_pattern: $ => seq(
      field('left', choice(
        alias(choice($._reserved_identifier, $.identifier), $.shorthand_property_identifier_pattern),
        $._destructuring_pattern,
      )),
      '=',
      field('right', $.expression),
    ),

    array: $ => seq(
      '[',
      commaSep(optional(choice(
        $.expression,
        $.spread_element,
      ))),
      ']',
    ),

    array_pattern: $ => seq(
      '[',
      commaSep(optional(choice(
        $.pattern,
        $.assignment_pattern,
      ))),
      ']',
    ),

    class: $ => prec('literal', seq(
      repeat(field('decorator', $.decorator)),
      'class',
      field('name', optional($.identifier)),
      optional($.class_heritage),
      field('body', $.class_body),
    )),

    class_declaration: $ => prec('declaration', seq(
      repeat(field('decorator', $.decorator)),
      'class',
      field('name', $.identifier),
      optional($.class_heritage),
      field('body', $.class_body),
      optional($._automatic_semicolon),
    )),

    class_heritage: $ => seq('extends', $.expression),

    function_expression: $ => prec('literal', seq(
      optional('async'),
      'function',
      field('name', optional($.identifier)),
      $._call_signature,
      field('body', $.statement_block),
    )),

    // ()\\s+)
    // (?i:\\b(private|package|public|remote|static|final|abstract|default)\\s+)?\n
    // ()

    function_declaration: $ => prec.right('declaration', seq(
      optional(alias(choice(
        token('private'),
        token('package'),
        token('public'),
        token('remote'),
        token('static'),
        token('final'),
        token('abstract'),
        // 'default',
      ), $.access_type)),
      optional(alias(choice(
        token('any'),
        token('array'),
        token('binary'),
        token('boolean'),
        token('component'),
        token('date'),
        token('function'),
        token('guid'),
        token('numeric'),
        token('query'),
        token('string'),
        token('struct'),
        token('uuid'),
        token('variablename'),
        token('void'),
        token('xml'),
      ), $.return_type)),
      optional('async'),
      'function',
      field('name', $.identifier),
      $._call_signature,
      field('body', $.statement_block),
      optional($._automatic_semicolon),
    )),

    generator_function: $ => prec('literal', seq(
      optional('async'),
      'function',
      '*',
      field('name', optional($.identifier)),
      $._call_signature,
      field('body', $.statement_block),
    )),

    generator_function_declaration: $ => prec.right('declaration', seq(
      optional('async'),
      'function',
      '*',
      field('name', $.identifier),
      $._call_signature,
      field('body', $.statement_block),
      optional($._automatic_semicolon),
    )),

    arrow_function: $ => seq(
      optional('async'),
      choice(
        field('parameter', choice(
          alias($._reserved_identifier, $.identifier),
          $.identifier,
        )),
        $._call_signature,
      ),
      '=>',
      field('body', choice(
        $.expression,
        $.statement_block,
      )),
    ),

    // Override
    _call_signature: $ => field('parameters', alias($.function_dec_parameters, $.formal_parameters)),
    _formal_parameter: $ => choice($.pattern, $.assignment_pattern),

    function_dec_parameters: $ => seq(
      '(',
      optional(seq(
        commaSep1($._function_dec_parameter),
        optional(','),
      )),
      ')',
    ),

    _function_dec_parameter: $ => seq(
      optional(alias(token('required'), $.required)),
      optional(alias(choice(
        token('any'),
        token('array'),
        token('binary'),
        token('boolean'),
        token('component'),
        token('date'),
        token('function'),
        token('guid'),
        token('numeric'),
        token('query'),
        token('string'),
        token('struct'),
        token('uuid'),
        token('variablename'),
        token('void'),
        token('xml'),
      ), $.type)),
      choice($.pattern, $.assignment_pattern),
    ),

    optional_chain: _ => '?.',

    call_expression: $ => choice(
      prec('call', seq(
        field('function', choice($.expression, $.import)),
        field('arguments', $.arguments),
      )),
      prec('member', seq(
        field('function', $.primary_expression),
        field('optional_chain', $.optional_chain),
        field('arguments', $.arguments),
      )),
    ),

    new_expression: $ => prec.right('new', seq(
      'new',
      field('constructor', choice($.primary_expression, $.new_expression)),
      field('arguments', optional(prec.dynamic(1, $.arguments))),
    )),

    await_expression: $ => prec('unary_void', seq(
      'await',
      $.expression,
    )),

    member_expression: $ => prec('member', seq(
      field('object', choice($.expression, $.primary_expression, $.import)),
      choice('.', field('optional_chain', $.optional_chain)),
      field('property', choice(
        $.private_property_identifier,
        alias($.identifier, $.property_identifier))),
    )),

    subscript_expression: $ => prec.right('member', seq(
      field('object', choice($.expression, $.primary_expression)),
      optional(field('optional_chain', $.optional_chain)),
      '[', field('index', $._expressions), ']',
    )),

    _lhs_expression: $ => choice(
      $.member_expression,
      $.subscript_expression,
      $._identifier,
      alias($._reserved_identifier, $.identifier),
      $._destructuring_pattern,
    ),

    assignment_expression: $ => prec.right('assign', seq(
      field('left', choice($.parenthesized_expression, $._lhs_expression)),
      '=',
      field('right', $.expression),
    )),

    _augmented_assignment_lhs: $ => choice(
      $.member_expression,
      $.subscript_expression,
      alias($._reserved_identifier, $.identifier),
      $.identifier,
      $.parenthesized_expression,
    ),

    augmented_assignment_expression: $ => prec.right('assign', seq(
      field('left', $._augmented_assignment_lhs),
      field('operator', choice('+=', '-=', '*=', '/=', '%=', '^=', '&=', '|=', '>>=', '>>>=',
        '<<=', '**=', '&&=', '||=', '??=')),
      field('right', $.expression),
    )),

    _initializer: $ => seq(
      '=',
      field('value', $.expression),
    ),

    _destructuring_pattern: $ => choice(
      $.object_pattern,
      $.array_pattern,
    ),

    spread_element: $ => seq('...', $.expression),

    ternary_expression: $ => prec.right('ternary', seq(
      field('condition', $.expression),
      alias($._ternary_qmark, '?'),
      field('consequence', $.expression),
      ':',
      field('alternative', $.expression),
    )),

    binary_expression: $ => choice(
      ...[
        ['&&', 'logical_and'],
        [/[aA][nN][dD]/, 'logical_and'],
        ['||', 'logical_or'],
        [/[oO][rR]/, 'logical_or'],
        ['>>', 'binary_shift'],
        ['>>>', 'binary_shift'],
        ['<<', 'binary_shift'],
        ['&', 'bitwise_and'],
        ['^', 'bitwise_xor'],
        ['|', 'bitwise_or'],
        ['+', 'binary_plus'],
        ['-', 'binary_plus'],
        ['*', 'binary_times'],
        ['/', 'binary_times'],
        ['%', 'binary_times'],
        ['**', 'binary_exp', 'right'],
        ['<', 'binary_relation'],
        [/[lL][tT]/, 'binary_relation'],
        ['<=', 'binary_relation'],
        [/[lL][tT][eE]/, 'binary_relation'],
        ['==', 'binary_equality'],
        ['===', 'binary_equality'],
        [/[eE][qQ]/, 'binary_equality'],
        [/[iI][sS]/, 'binary_equality'],
        ['!=', 'binary_equality'],
        ['!==', 'binary_equality'],
        [/[nN][eE][qQ]/, 'binary_equality'],
        ['>=', 'binary_relation'],
        [/[gG][tT][eE]/, 'binary_relation'],
        ['>', 'binary_relation'],
        [/[gG][tT]/, 'binary_relation'],
        ['??', 'ternary'],
        ['instanceof', 'binary_relation'],
        ['in', 'binary_relation'],
      ].map(([operator, precedence, associativity]) =>
        // @ts-ignore
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('left', operator === 'in' ? choice($.expression, $.private_property_identifier) : $.expression),
          field('operator', operator),
          field('right', $.expression),
        )),
      ),
    ),

    unary_operator: $ => choice(
      '!',
      '~',
      '-',
      '+',
      keyword('typeof'),
      keyword('void'),
      keyword('delete'),
      keyword('not'),
    ),

    unary_expression: $ => prec.left('unary_void', seq(
      field('operator', $.unary_operator),
      field('argument', $.expression),
    )),

    update_expression: $ => prec.left(choice(
      seq(
        field('argument', $.expression),
        field('operator', choice('++', '--')),
      ),
      seq(
        field('operator', choice('++', '--')),
        field('argument', $.expression),
      ),
    )),

    sequence_expression: $ => prec.right(commaSep1($.expression)),

    //
    // Primitives
    //

    string: $ => choice(
      seq(
        '"',
        repeat(choice(
          alias($.unescaped_double_string_fragment, $.string_fragment),
          $.escape_sequence,
        )),
        '"',
      ),
      seq(
        '\'',
        repeat(choice(
          alias($.unescaped_single_string_fragment, $.string_fragment),
          $.escape_sequence,
        )),
        '\'',
      ),
    ),

    // Workaround to https://github.com/tree-sitter/tree-sitter/issues/1156
    // We give names to the token() constructs containing a regexp
    // so as to obtain a node in the CST.
    //
    unescaped_double_string_fragment: _ => token.immediate(prec(1, /[^"\\\r\n]+/)),

    // same here
    unescaped_single_string_fragment: _ => token.immediate(prec(1, /[^'\\\r\n]+/)),

    escape_sequence: _ => token.immediate(seq(
      '\\',
      choice(
        /[^xu0-7]/,
        /[0-7]{1,3}/,
        /x[0-9a-fA-F]{2}/,
        /u[0-9a-fA-F]{4}/,
        /u{[0-9a-fA-F]+}/,
        /[\r?][\n\u2028\u2029]/,
      ),
    )),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: $ => choice(
      token(choice(
        seq('//', /.*/),
        seq(
          '/*',
          /[^*]*\*+([^/*][^*]*\*+)*/,
          '/',
        ),
      )),
    ),

    // template_string: $ => seq(
    //   '`',
    //   repeat(choice(
    //     alias($._template_chars, $.string_fragment),
    //     $.escape_sequence,
    //     $.template_substitution,
    //   )),
    //   '`',
    // ),

    template_substitution: $ => seq(
      '${',
      $._expressions,
      '}',
    ),

    regex: $ => seq(
      '/',
      field('pattern', $.regex_pattern),
      token.immediate(prec(1, '/')),
      optional(field('flags', $.regex_flags)),
    ),

    regex_pattern: _ => token.immediate(prec(-1,
      repeat1(choice(
        seq(
          '[',
          repeat(choice(
            seq('\\', /./), // escaped character
            /[^\]\n\\]/, // any character besides ']' or '\n'
          )),
          ']',
        ), // square-bracket-delimited character class
        seq('\\', /./), // escaped character
        /[^/\\\[\n]/, // any character besides '[', '\', '/', '\n'
      )),
    )),

    regex_flags: _ => token.immediate(/[a-z]+/),

    number: _ => {
      const hex_literal = seq(
        choice('0x', '0X'),
        /[\da-fA-F](_?[\da-fA-F])*/,
      );

      const decimal_digits = /\d(_?\d)*/;
      const signed_integer = seq(optional(choice('-', '+')), decimal_digits);
      const exponent_part = seq(choice('e', 'E'), signed_integer);

      const binary_literal = seq(choice('0b', '0B'), /[0-1](_?[0-1])*/);

      const octal_literal = seq(choice('0o', '0O'), /[0-7](_?[0-7])*/);

      const bigint_literal = seq(choice(hex_literal, binary_literal, octal_literal, decimal_digits), 'n');

      const decimal_integer_literal = choice(
        '0',
        seq(optional('0'), /[1-9]/, optional(seq(optional('_'), decimal_digits))),
      );

      const decimal_literal = choice(
        seq(decimal_integer_literal, '.', optional(decimal_digits), optional(exponent_part)),
        seq('.', decimal_digits, optional(exponent_part)),
        seq(decimal_integer_literal, exponent_part),
        seq(decimal_digits),
      );

      return token(choice(
        hex_literal,
        decimal_literal,
        binary_literal,
        octal_literal,
        bigint_literal,
      ));
    },

    // 'undefined' is syntactically a regular identifier in JavaScript.
    // However, its main use is as the read-only global variable whose
    // value is [undefined], for which there's no literal representation
    // unlike 'null'. We gave it its own rule so it's easy to
    // highlight in text editors and other applications.
    _identifier: $ => choice(
      // $.undefined,
      $.identifier,
    ),

    identifier: _ => {
      // eslint-disable-next-line max-len
      const alpha = /[^\x00-\x1F\s\p{Zs}0-9:;`"'@#.,<>\/|^&<=>+\-*/\\\/%?!~()\[\]{}\uFEFF\u2060\u200B]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      // eslint-disable-next-line max-len
      const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,<>\/|^&<=>+\-*/\\\/%?!~()\[\]{}\uFEFF\u2060\u200B]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      return token(seq(alpha, repeat(alphanumeric)));
    },

    private_property_identifier: _ => {
      // eslint-disable-next-line max-len
      const alpha = /[^\x00-\x1F\s\p{Zs}0-9:;`"'@#.,<>\/|^&<=>+\-*/\\\/%?!~()\[\]{}\uFEFF\u2060\u200B]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      // eslint-disable-next-line max-len
      const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,<>\/|^&<=>+\-*/\\\/%?!~()\[\]{}\uFEFF\u2060\u200B]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      return token(seq('#', alpha, repeat(alphanumeric)));
    },

    meta_property: _ => seq('new', '.', 'target'),

    this: _ => 'this',
    super: _ => 'super',
    true: _ => 'true',
    false: _ => 'false',
    null: _ => 'null',
    undefined: _ => 'undefined',

    //
    // Expression components
    //

    arguments: $ => seq(
      '(',
      commaSep(optional(choice($.expression, $.spread_element))),
      ')',
    ),

    decorator: $ => seq(
      '@',
      choice(
        $.identifier,
        alias($.decorator_member_expression, $.member_expression),
        alias($.decorator_call_expression, $.call_expression),
      ),
    ),

    decorator_member_expression: $ => prec('member', seq(
      field('object', choice(
        $.identifier,
        alias($.decorator_member_expression, $.member_expression),
      )),
      '.',
      field('property', alias($.identifier, $.property_identifier)),
    )),

    decorator_call_expression: $ => prec('call', seq(
      field('function', choice(
        $.identifier,
        alias($.decorator_member_expression, $.member_expression),
      )),
      field('arguments', $.arguments),
    )),

    class_body: $ => seq(
      '{',
      repeat(choice(
        seq(field('member', $.method_definition), optional(';')),
        seq(field('member', $.field_definition), $._semicolon),
        field('member', $.class_static_block),
        ';',
      )),
      '}',
    ),

    field_definition: $ => seq(
      repeat(field('decorator', $.decorator)),
      optional('static'),
      field('property', $._property_name),
      optional($._initializer),
    ),

    formal_parameters: $ => seq(
      '(',
      optional(seq(
        commaSep1($._formal_parameter),
        optional(','),
      )),
      ')',
    ),

    class_static_block: $ => seq(
      'static',
      field('body', $.statement_block),
    ),

    // This negative dynamic precedence ensures that during error recovery,
    // unfinished constructs are generally treated as literal expressions,
    // not patterns.
    pattern: $ => prec.dynamic(-1, choice(
      $._lhs_expression,
      $.rest_pattern,
    )),

    rest_pattern: $ => prec.right(seq(
      '...',
      $._lhs_expression,
    )),

    method_definition: $ => seq(
      repeat(field('decorator', $.decorator)),
      optional(choice('static', alias(token(seq('static', /\s+/, 'get', /\s*\n/)), 'static get'))),
      optional('async'),
      // optional(choice('get', 'set', '*')),
      field('name', $._property_name),
      field('parameters', $.formal_parameters),
      field('body', $.statement_block),
    ),

    pair: $ => seq(
      field('key', $._property_name),
      ':',
      field('value', $.expression),
    ),

    pair_pattern: $ => seq(
      field('key', $._property_name),
      ':',
      field('value', choice($.pattern, $.assignment_pattern)),
    ),

    _property_name: $ => choice(
      alias(choice(
        $.identifier,
        $._reserved_identifier,
      ), $.property_identifier),
      $.private_property_identifier,
      $.string,
      $.number,
      $.computed_property_name,
    ),

    computed_property_name: $ => seq(
      '[',
      $.expression,
      ']',
    ),

    _reserved_identifier: _ => choice(
      'get',
      'set',
      'async',
      'static',
      'export',
      'let',
    ),

    _semicolon: $ => choice($._automatic_semicolon, ';'),
  },
});


// eslint-disable-next-line valid-jsdoc
/**
 * @param {string} word
 */
function keyword(word) {
  // return word // when debuging
  return alias(reserved(caseInsensitive(word)), word);
}

// eslint-disable-next-line valid-jsdoc
/**
 * @param {string | RegExp} regex
 */
function reserved(regex) {
  return token(prec(1, new RegExp(regex)));
}

// eslint-disable-next-line valid-jsdoc
/**
 * @param {string} word
 */
function caseInsensitive(word) {
  return word.split('')
    .map(letter => `[${letter}${letter.toUpperCase()}]`)
    .join('');
}


/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @return {SeqRule}
 *
 */
function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

/**
 * Creates a rule to optionally match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @return {ChoiceRule}
 *
 */
function commaSep(rule) {
  return optional(commaSep1(rule));
}
