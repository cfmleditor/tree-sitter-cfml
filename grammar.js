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
    $.comment,
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
    $.implicit_end_tag,
    $.raw_text,
    $.cf_comment,
    $._cfquery_content,
    $._cf_open_tag,
    $._cf_close_tag,
    $._cfsavecontent_content,
    $._close_tag_delim,
    $._cf_output_tag,
    $._html_hash,
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

    // Tag
    [$.cf_zip_tag, $.cf_selfclose_tag],
    // [$.cf_transaction_tag, $.cf_transaction_tag_standalone],

    [$.cf_elseif_tag, $.binary_expression],
    [$.cf_elseif_tag, $.call_expression],
    [$.cf_elseif_tag, $.subscript_expression],
    [$.cf_elseif_tag, $.update_expression],

    // Script
    // [$.primary_expression, $.variable_declaration],
    [$.primary_expression, $.function_expression],
    [$.primary_expression, $._property_name],
    [$.primary_expression, $._property_name, $.arrow_function],
    [$.primary_expression, $.function_expression, $.generator_function],
    [$.primary_expression, $.arrow_function],
    [$.primary_expression, $.method_definition],
    [$.primary_expression, $.rest_pattern],
    [$.primary_expression, $.pattern],
    [$.primary_expression, $._for_header],
    [$.array, $.array_pattern],
    [$.object, $.object_pattern],
    [$.expression, $.object],
    [$.assignment_expression, $.pattern],
    [$.assignment_expression, $.object_assignment_pattern],
    [$.labeled_statement, $._property_name],
    [$.computed_property_name, $.array],
    [$.binary_expression, $._initializer],
    [$.binary_expression, $.pair],
    [$.call_expression, $.pair],
    [$.subscript_expression, $.pair],
    [$.member_expression, $.pair],
    [$.update_expression, $.pair],
    [$.ternary_expression, $.pair],
    [$.member_expression, $.subscript_expression, $.pair],
    [$.attribute_name, $._node],
    [$.tag_attributes, $._node],
    [$.attribute_name, $.tag_attributes, $._node],
    // [$.component_body, $.object],
    // [$.component_body, $.object_pattern],

    // [$.object_assignment_pattern, $.assignment_expression, $._property_name],
    // [$.primary_expression, $.field_definition, $.method_definition],
    // [$.assignment_expression, $._property_name],

    [$.attribute_name, $.tag_attributes],

    // [$.cf_if_statement_tag, $._cf_tag],
    [$.self_closing_tag, $.start_tag],

    // [$.cf_if_tag],
    // [$.cf_else_tag],
    [$.cf_elseif_tag],

    [$.element, $._node],
  ],

  rules: {

    program: $ => choice(
      repeat(
        $._node,
      ),
      $.component,
    ),

    doctype: $ => seq(
      '<!',
      alias($._doctype, 'doctype'),
      /[^>]+/,
      alias($._close_tag_delim, '>'),
    ),

    xml_decl: $ => seq(
      '<?',
      keyword('xml'),
      repeat($.tag_attributes),
      '?>',
    ),

    _doctype: _ => /[Dd][Oo][Cc][Tt][Yy][Pp][Ee]/,

    _cf_tag_start: $ => '<',
    // _close_tag_delim: $ => '>',

    cf_selfclose_tag_end: $ => choice('/>', alias($._close_tag_delim, '>')),

    text: $ => /[^<>&\s#]([^<>&#]*[^<>&\s#])?/,
    // cf_tag_close: $ => /<\/cf/i,

    _node: $ => choice(
      $.doctype,
      $.entity,
      $.element,
      $._cf_tag,
      $.hash_expression,
      $.hash_empty,
      $.script_element,
      $.style_element,
      $.cf_script,
      $.tag_attributes,
      // $.attribute,
      $.text,
      $.end_tag,
      $.erroneous_end_tag,
      $.xml_decl,
    ),

    cf_script: $ => prec.right(seq(
      $._cf_open_tag,
      keyword('script'),
      alias($._close_tag_delim, '>'),
      repeat($.statement),
      $._cf_close_tag,
      keyword('script'),
      alias($._close_tag_delim, '>'),
    )),

    element: $ => choice(
      seq(
        $.start_tag,
        repeat($._node),
        choice($.end_tag, $.implicit_end_tag),
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
      repeat($.tag_attributes),
      alias($._close_tag_delim, '>'),
    ),

    tag_attributes: $ => choice(
      $.attribute,
      $.quoted_attribute_value,
      $._cf_tag,
      $.hash_expression,
      $.hash_empty,
    ),

    script_start_tag: $ => seq(
      '<',
      alias($._script_start_tag_name, $.tag_name),
      repeat(
        $.tag_attributes,
      ),
      alias($._close_tag_delim, '>'),
    ),

    style_start_tag: $ => seq(
      '<',
      alias($._style_start_tag_name, $.tag_name),
      repeat(
        $.tag_attributes,
      ),
      alias($._close_tag_delim, '>'),
    ),

    self_closing_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat(
        $.tag_attributes,
      ),
      choice(
        '/>',
        alias($._close_tag_delim, '>'),
      ),
    ),

    end_tag: $ => seq(
      '</',
      alias($._end_tag_name, $.tag_name),
      alias($._close_tag_delim, '>'),
    ),

    erroneous_end_tag: $ => seq(
      '</',
      $.erroneous_end_tag_name,
      alias($._close_tag_delim, '>'),
    ),

    style_element: $ => seq(
      alias($.style_start_tag, $.start_tag),
      optional($.raw_text),
      $.end_tag,
    ),

    hash_empty: $ => /#{2}/,

    cf_component_tag: $ => seq(
      $._cf_open_tag,
      keyword('component'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('component'),
      alias($._close_tag_delim, '>'),
    ),

    cf_function_tag: $ => seq(
      $._cf_open_tag,
      keyword('function'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('function'),
      alias($._close_tag_delim, '>'),
    ),

    cf_silent_tag: $ => seq(
      $._cf_open_tag,
      keyword('silent'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('silent'),
      alias($._close_tag_delim, '>'),
    ),

    cf_lock_tag: $ => seq(
      $._cf_open_tag,
      keyword('lock'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('lock'),
      alias($._close_tag_delim, '>'),
    ),

    cf_thread_tag: $ => seq(
      $._cf_open_tag,
      keyword('thread'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('thread'),
      alias($._close_tag_delim, '>'),
    ),

    cf_execute_tag: $ => seq(
      $._cf_open_tag,
      keyword('execute'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('execute'),
      alias($._close_tag_delim, '>'),
    ),

    cf_http_tag: $ => seq(
      $._cf_open_tag,
      keyword('http'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat(
        $._node,
      ),
      $._cf_close_tag,
      keyword('http'),
      alias($._close_tag_delim, '>'),
    ),

    cf_xml_tag: $ => seq(
      $._cf_open_tag,
      keyword('xml'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('xml'),
      alias($._close_tag_delim, '>'),
    ),

    cf_mail_tag: $ => seq(
      $._cf_open_tag,
      keyword('mail'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('mail'),
      alias($._close_tag_delim, '>'),
    ),

    cf_mailpart_tag: $ => seq(
      $._cf_open_tag,
      keyword('mailpart'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('mailpart'),
      alias($._close_tag_delim, '>'),
    ),

    cf_selfclose_tag: $ => seq(
      $._cf_open_tag,
      field('tag_name', choice(
        keyword('setting'),
        keyword('queryparam'),
        keyword('transaction'),
        keyword('argument'),
        keyword('continue'),
        keyword('httpparam'),
        keyword('zip'),
        keyword('break'),
        /[a-zA-Z_]+/,
      )),
      repeat($.cf_attribute),
      $.cf_selfclose_tag_end,
    ),

    cf_query_tag: $ => seq(
      $._cf_open_tag,
      keyword('query'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      $._cfquery_content,
      $._cf_close_tag,
      keyword('query'),
      alias($._close_tag_delim, '>'),
    ),

    cf_transaction_tag: $ => prec.right(2, seq(
      $._cf_open_tag,
      keyword('transaction'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('transaction'),
      alias($._close_tag_delim, '>'),
    )),

    cf_try_tag: $ => seq(
      $._cf_open_tag,
      keyword('try'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      repeat($.cf_catch_tag),
      $._cf_close_tag,
      keyword('try'),
      alias($._close_tag_delim, '>'),
    ),

    cf_switch_tag: $ => seq(
      $._cf_open_tag,
      keyword('switch'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      repeat($.cf_case_tag),
      optional($.cf_defaultcase_tag),
      $._cf_close_tag,
      keyword('switch'),
      alias($._close_tag_delim, '>'),
    ),

    cf_case_tag: $ => seq(
      $._cf_open_tag,
      keyword('case'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('case'),
      alias($._close_tag_delim, '>'),
    ),

    cf_defaultcase_tag: $ => seq(
      $._cf_open_tag,
      keyword('defaultcase'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('defaultcase'),
      alias($._close_tag_delim, '>'),
    ),

    cf_catch_tag: $ => seq(
      $._cf_open_tag,
      keyword('catch'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('catch'),
      alias($._close_tag_delim, '>'),
    ),

    cf_loop_tag: $ => seq(
      $._cf_open_tag,
      keyword('loop'),
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('loop'),
      alias($._close_tag_delim, '>'),
    ),

    cf_zip_tag: $ => seq(
      $._cf_open_tag,
      keyword('zip'),
      repeat($.cf_attribute),
      $.cf_selfclose_tag_end,
      repeat($._node),
      $._cf_close_tag,
      keyword('zip'),
      alias($._close_tag_delim, '>'),
    ),

    cf_savecontent_tag: $ => seq(
      $._cf_open_tag,
      keyword('savecontent'),
      repeat($.cf_attribute),
      $.cf_selfclose_tag_end,
      $._cfsavecontent_content,
      $._cf_close_tag,
      keyword('savecontent'),
      alias($._close_tag_delim, '>'),
    ),

    cf_output_tag: $ => seq(
      $._cf_output_tag,
      repeat($.cf_attribute),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      $._cf_close_tag,
      keyword('output'),
      alias($._close_tag_delim, '>'),
    ),

    cf_return_tag: $ => seq(
      $._cf_open_tag,
      keyword('return'),
      optional($.expression),
      $.cf_selfclose_tag_end,
    ),

    cf_if_tag: $ => prec.right(seq(
      $._cf_open_tag,
      keyword('if'),
      optional($._cf_tag_expression),
      alias($._close_tag_delim, '>'),
      repeat($._node),
      optional(repeat($.cf_elseif_tag)),
      optional($.cf_else_tag),
      $._cf_close_tag,
      keyword('if'),
      alias($._close_tag_delim, '>'),
    )),

    _cf_tag_expression: $ => choice(
      $.expression,
    ),

    cf_set_tag: $ => seq(
      $._cf_open_tag,
      keyword('set'),
      optional(alias('var', $.cf_var)),
      $._cf_tag_expression,
      $.cf_selfclose_tag_end,
    ),

    cf_elseif_tag: $ => seq(
      $._cf_open_tag,
      keyword('elseif'),
      repeat($.expression),
      alias($._close_tag_delim, '>'),
      repeat($._node),
    ),

    cf_else_tag: $ => seq(
      $._cf_open_tag,
      keyword('else'),
      alias($._close_tag_delim, '>'),
      repeat($._node),
    ),

    cf_if_end_tag: $ => seq(
      $._cf_close_tag,
      keyword('if'),
      alias($._close_tag_delim, '>'),
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

    attribute_name: $ => choice(
      /[^<>"'=\s#]+/,
      $.hash_expression,
    ),

    attribute_value: $ => choice(
      $._html_hash,
      /[^<>"'=\s]+/,
      $.hash_expression,
      $._cf_tag,
    ),

    cf_attribute: $ => seq(
      $.cf_attribute_name,
      optional(seq(
        '=',
        $.expression,
      )),
    ),

    cf_attribute_name: _ => /[^<>"\'/=\s]+/,

    _cf_tag: $ => choice(
      // $.cf_if_statement_tag,
      $.cf_if_tag,
      // $.cf_elseif_tag,
      // $.cf_else_tag,
      $.cf_thread_tag,
      $.cf_execute_tag,
      $.cf_silent_tag,
      $.cf_lock_tag,
      $.cf_http_tag,
      $.cf_xml_tag,
      $.cf_try_tag,
      $.cf_switch_tag,
      $.cf_mail_tag,
      $.cf_mailpart_tag,
      $.cf_transaction_tag,
      $.cf_set_tag,
      $.cf_selfclose_tag,
      $.cf_savecontent_tag,
      $.cf_output_tag,
      $.cf_zip_tag,
      alias($.cf_component_tag, $.cf_component),
      alias($.cf_function_tag, $.cf_function),
      alias($.cf_query_tag, $.cf_query),
      alias($.cf_loop_tag, $.cf_loop),
      alias($.cf_return_tag, $.cf_return),
    ),

    entity: _ => /&(([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});/,

    quoted_attribute_value: $ => choice(
      seq('\'',
        repeat(
          choice($.attribute_value,
            alias(/[^']+/,
              $.attribute_value,
            ),
          ),
        ),
        '\''),
      seq('"',
        repeat(
          choice(
            $.attribute_value,
            alias(/[^"]+/,
              $.attribute_value,
            ),
          ),
        ),
        '"'),
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
      choice(
        $.arguments,
        $.string,
      ),
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
      optional(seq('(', field('type', $.identifier), field('parameter', choice($.identifier, $._destructuring_pattern)), ')')),
      field('body', $.statement_block),
    ),

    finally_clause: $ => seq(
      'finally',
      field('body', $.statement_block),
    ),

    parenthesized_expression: $ => seq(
      '(',
      optional($._expressions),
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
      $.pair,
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
      $.meta_property,
      $.call_expression,
      $.hash_expression,
      $.hash_empty,
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
        $.assignment_expression,
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

    function_expression: $ => prec('literal', seq(
      optional('async'),
      'function',
      field('name', optional($.identifier)),
      $._call_signature,
      field('body', $.statement_block),
    )),

    function_declaration: $ => prec.right('declaration', seq(
      optional(alias(choice(
        token('private'),
        // token('package'),
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
        // token('component'),
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
    _formal_parameter: $ => choice($.pattern, $.assignment_pattern, $.pair_pattern),

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
        // token('component'),
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
      $.string,
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
        [/[mM][oO][dD]/, 'binary_times'],
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
        [/[cC][oO][nN][tT][aA][iI][nN][sS]/, 'binary_equality'],
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
      // keyword('typeof'),
      // keyword('void'),
      // keyword('delete'),
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
          $.hash_expression,
          $.hash_empty,
          '""',
          $.escape_sequence,
        )),
        '"',
      ),
      seq(
        '\'',
        repeat(choice(
          alias($.unescaped_single_string_fragment, $.string_fragment),
          $.hash_expression,
          $.hash_empty,
          '\'\'',
          $.escape_sequence,
        )),
        '\'',
      ),
    ),

    // Workaround to https://github.com/tree-sitter/tree-sitter/issues/1156
    // We give names to the token() constructs containing a regexp
    // so as to obtain a node in the CST.
    //
    unescaped_double_string_fragment: _ => token.immediate(prec(1, /[^"#]+/)),

    // same here
    unescaped_single_string_fragment: _ => token.immediate(prec(1, /[^'#]+/)),

    escape_sequence: _ => token.immediate(seq(
      '\\',
      choice(
        /[^xu0-7]/,
        /[0-7]{1,3}/,
        /x[0-9a-fA-F]{2}/,
        /u[0-9a-fA-F]{4}/,
        /u\{[0-9a-fA-F]+\}/,
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
      return token(seq('~', alpha, repeat(alphanumeric)));
    },

    meta_property: _ => seq('new', '.', 'target'),

    this: _ => 'this',
    super: _ => 'super',
    true: _ => keyword('true'),
    false: _ => keyword('false'),
    null: _ => 'null',
    // undefined: _ => 'undefined',

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

    component: $ => seq(
      keyword('component'),
      '{',
      repeat($.statement),
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

    sequence_pair: $ => prec.right(commaSep1($.pair)),

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
      $.hash_expression,
      $.hash_empty,
    ),

    hash_expression: $ => seq(
      '#',
      $.expression,
      '#',
    ),

    computed_property_name: $ => seq(
      '[',
      $.expression,
      ']',
    ),

    _reserved_identifier: _ => choice(
      // 'get',
      // 'set',
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
