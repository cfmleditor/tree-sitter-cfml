/**
 * @file CFSCRIPT grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

/**
 * @param {Rule} rule
 * @returns {SeqRule}
 */
function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

/**
 * @param {Rule} rule
 * @returns {ChoiceRule}
 */
function commaSep(rule) {
  return optional(commaSep1(rule));
}

module.exports = grammar({
  name: 'cfscript',

  externals: ($) => [
    $._automatic_semicolon,
    $._template_chars,
    $._ternary_qmark,
    $._elvis_operator,
    $.logical_or,
    // Scanner tracks string/template context so HTML comments are not parsed inside them.
    $.regex_pattern,
    $.query_text,
    $.tag_linefeed,
    $.cfml_template_content,
  ],

  extras: ($) => [
    $.comment,
    // @ts-ignore
    /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/,
  ],

  supertypes: $ => [
    $.statement,
    $.declaration,
    $.expression,
    $.primary_expression,
    $.pattern,
  ],

  inline: ($) => [
    $._kw_abstract,
    $._kw_break,
    $._kw_case,
    $._kw_catch,
    $._kw_component,
    $._kw_continue,
    $._kw_debugger,
    $._kw_default,
    $._kw_do,
    $._kw_else,
    $._kw_final,
    $._kw_finally,
    $._kw_for,
    $._kw_function,
    $._kw_if,
    $._kw_import,
    $._kw_in,
    $._kw_include,
    $._kw_instanceof,
    $._kw_interface,
    $._kw_new,
    $._kw_of,
    $._kw_package,
    $._kw_private,
    $._kw_property,
    $._kw_public,
    $._kw_remote,
    $._kw_return,
    $._kw_static,
    $._kw_switch,
    $._kw_throw,
    $._kw_try,
    $._kw_var,
    $._kw_while,
    $._kw_with,
    $._call_signature,
    $._formal_parameter,
    $._expressions,
    $._semicolon,
    $._identifier,
    $._reserved_identifier,
    $._lhs_expression,
  ],

  precedences: ($) => [
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
      'logical_xor',
      'logical_or',
      'ternary',
      'elvis',
      $.sequence_expression,
      $.arrow_function,
    ],
    ['assign', $.primary_expression],
    ['member', 'new', 'call', $.expression],
    ['declaration', 'literal'],
    [$.primary_expression, $.statement_block, 'object'],
  ],

  conflicts: ($) => [
    [$.object, $.object_pattern],
    [$.primary_expression, $.pattern],
    [$.assignment_expression, $.pattern],
    [$.function_expression, $.function_declaration],
    [$.expression, $.function_expression, $.function_declaration],
    [$.primary_expression, $.path],
    [$.primary_expression, $.parameter_type],
    [$.primary_expression, $.parameter_type, $.pattern],
    [$.parameter_type, $.pattern],
    [$.primary_expression, $._property_name],
    [$.primary_expression, $.method_definition],
    [$.primary_expression, $.rest_pattern],
    [$.primary_expression, $._for_header],
    [$.array, $.array_pattern],
    [$.assignment_expression, $.object_assignment_pattern],
    [$.labeled_statement, $._property_name],
    [$.computed_property_name, $.array],
    [$.binary_expression, $._initializer],
    [$.method_definition, $.access_type],
    // `pair` (expression ':' expression) is reachable from `arguments` and
    // `array`, so `case <expr> :` is ambiguous with the start of a pair.
    [$.switch_case, $.expression],
    [$.primary_expression, $.new_expression],
    [$.primary_expression, $.query_tag],
    [$._for_header, $.primary_expression, $.new_expression],
    [$.primary_expression, $.new_expression, $.rest_pattern],
    [$.new_expression, $.pattern],
    [$.primary_expression, $.new_expression, $.pattern],
    [$.primary_expression, $.new_expression, $._property_name],
    [$.function_expression, $.pattern],
    [$.function_expression, $.parameter_type, $.pattern],
    [$.primary_expression, $.function_expression, $.parameter_type],
    [$.primary_expression, $.function_expression, $._property_name],
    [$.primary_expression, $.function_expression],
    [$._property_name, $.primary_expression, $.query_tag],
    [$.primary_expression, $.query_expression],
    [$._property_name, $.primary_expression, $.query_expression],
    [$.arguments, $.parenthesized_expression],
    [$.expression, $.parenthesized_expression],
    [$.expression, $.expression_statement],

    [$.expression, $.arguments],
    [$.expression, $.assignment_expression],
    [$.expression, $.return_statement],
    [$.expression, $.throw_statement],
    [$.assignment_expression, $._property_name],
    [$.object_assignment_pattern, $._property_name],
    [$.object_assignment_pattern, $.assignment_expression, $._property_name],
    [$.call_expression, $._property_name],
    [$._for_header, $.expression],
    [$.expression, $.for_statement],
    [$.parenthesized_expression, $.expression, $.arguments],
    [$.expression, $.template_substitution],

    [$.primary_expression, $.tag_statement],
    [$.expression, $.tag_statement],
    [$.tag_statement, $.expression],
    [$.program, $.statement],
    [$.primary_expression, $.tag_statement, $._property_name],
    [$.sequence_expression, $.arguments],
    [$.component_attribute, $.property_declaration],
    [$.parameter_attribute, $.assignment_expression, $.pattern],
    [$.primary_expression, $.parameter_attribute],
  ],

  word: ($) => $.identifier,

  rules: {

    program: ($) => seq(
      repeat(
        choice(
          $.import_statement,
          $.tag_statement,
          $.comment,
        ),
      ),
      choice(
        $.component,
        repeat($.statement),
      ),
    ),


    /*
        START SCRIPT BASE RULES
      */
    _module_export_name: ($) => choice(
      $.identifier,
      $.string,
    ),

    declaration: ($) => choice(
      $.function_declaration,
      $.variable_declaration,
    ),

    //
    // Import declarations
    //

    import_statement: ($) => seq(
      $._kw_import,
      choice(
        seq($.import_clause, $._from_clause),
        field('source', $.string),
        field('source', $.identifier),
        field('source', $.import_path),
      ),
      optional($.import_attribute),
      $._semicolon,
    ),

    import_path: ($) => seq($.identifier, repeat1(seq('.', choice($.identifier, '*')))),

    path: ($) => seq($.identifier, repeat1(seq('.', $.identifier))),

    import_clause: ($) => choice(
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

    _from_clause: ($) => seq(
      'from', field('source', $.string),
    ),

    namespace_import: ($) => seq(
      '*', 'as', $.identifier,
    ),

    named_imports: ($) => seq(
      '{',
      commaSep($.import_specifier),
      optional(','),
      '}',
    ),

    import_specifier: ($) => choice(
      field('name', $.identifier),
      seq(
        field('name', $._module_export_name),
        'as',
        field('alias', $.identifier),
      ),
    ),

    import_attribute: ($) => seq($._kw_with, $.object),

    //
    // Statements
    //

    statement: ($) => choice(
      // $.export_statement,
      $.import_statement,
      $.debugger_statement,
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
      $.include_statement,

      $.cfml_template,
      $.tag_statement,
      $.query_tag,
      $.component,
    ),

    expression_statement: ($) => seq(
      $._expressions,
      $._semicolon,
    ),

    variable_declaration: ($) => seq(
      $._kw_var,
      commaSep1($.variable_declarator),
      $._semicolon,
    ),

    variable_declarator: ($) => seq(
      field('name', choice($.identifier, $._destructuring_pattern)),
      optional($._initializer),
    ),

    statement_block: ($) => prec.right(seq(
      '{',
      repeat($.statement),
      '}',
      optional($._automatic_semicolon),
    )),

    else_clause: ($) => seq($._kw_else, $.statement),

    if_statement: ($) => prec.right(seq(
      $._kw_if,
      field('condition', $.parenthesized_expression),
      field('consequence', $.statement),
      optional(field('alternative', $.else_clause)),
    )),

    switch_statement: ($) => seq(
      $._kw_switch,
      field('value', $.parenthesized_expression),
      field('body', $.switch_body),
    ),

    for_statement: ($) => seq(
      $._kw_for,
      '(',
      choice(
        field('initializer', $.variable_declaration),
        seq(field('initializer', $._expressions), ';'),
        field('initializer', $.empty_statement),
      ),
      field('condition', choice(
        seq($._expressions, ';'),
        $.empty_statement,
      )),
      field('increment', optional($._expressions)),
      ')',
      field('body', $.statement),
    ),

    for_in_statement: ($) => seq(
      $._kw_for,
      $._for_header,
      field('body', $.statement),
    ),

    _for_header: ($) => seq(
      '(',
      choice(
        field('left', choice(
          $._lhs_expression,
          $.parenthesized_expression,
        )),
        seq(
          field('kind', $._kw_var),
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
          optional($._automatic_semicolon),
        ),
      ),
      field('operator', choice($._kw_in, $._kw_of)),
      field('right', $._expressions),
      ')',
    ),

    while_statement: ($) => seq(
      $._kw_while,
      field('condition', $.parenthesized_expression),
      field('body', $.statement),
    ),

    do_statement: ($) => prec.right(seq(
      $._kw_do,
      field('body', $.statement),
      $._kw_while,
      field('condition', $.parenthesized_expression),
      optional($._semicolon),
    )),

    try_statement: ($) => seq(
      $._kw_try,
      field('body', $.statement_block),
      repeat(field('handler', $.catch_clause)),
      optional(field('finalizer', $.finally_clause)),
    ),

    with_statement: ($) => seq(
      $._kw_with,
      field('object', $.parenthesized_expression),
      field('body', $.statement),
    ),

    break_statement: ($) => seq(
      $._kw_break,
      field('label', optional(alias($.identifier, $.statement_identifier))),
      $._semicolon,
    ),

    continue_statement: ($) => seq(
      $._kw_continue,
      field('label', optional(alias($.identifier, $.statement_identifier))),
      $._semicolon,
    ),

    debugger_statement: ($) => seq(
      $._kw_debugger,
      $._semicolon,
    ),

    return_statement: ($) => seq(
      $._kw_return,
      optional($._expressions),
      $._semicolon,
    ),

    // `throw` takes an expression (`throw "msg";`) but is also called with
    // named arguments (`throw(type="x", message="y")` / `throw(type:"x")`).
    // `pair` is only reachable from `arguments`, so accept those explicitly.
    throw_statement: ($) => seq(
      $._kw_throw,
      choice(prec.dynamic(1, $.arguments), $._expressions),
      $._semicolon,
    ),

    include_statement: ($) => prec(1, seq(
      $._kw_include,
      choice(
        seq(repeat1($.parameter_attribute), $._semicolon),
        seq($._expressions, $._semicolon),
      ),
    )),

    empty_statement: (_) => ';',

    labeled_statement: ($) => prec.dynamic(-1, seq(
      field('label', alias(choice($.identifier, $._reserved_identifier), $.statement_identifier)),
      ':',
      field('body', $.statement),
    )),

    //
    // Statement components
    //

    switch_body: ($) => seq(
      '{',
      repeat(choice($.switch_case, $.switch_default)),
      '}',
    ),

    switch_case: ($) => seq(
      $._kw_case,
      field('value', $._expressions),
      ':',
      field('body', repeat($.statement)),
    ),

    switch_default: ($) => seq(
      $._kw_default,
      ':',
      field('body', repeat($.statement)),
    ),

    catch_clause: ($) => seq(
      $._kw_catch,
      optional(
        seq(
          '(',
          optional(field('type', alias(choice($.identifier, $.nested_identifier, $.string), $.catch_type))),
          field('parameter', choice($.identifier, $.nested_identifier, $._destructuring_pattern)),
          ')',
        ),
      ),
      field('body', $.statement_block),
    ),

    finally_clause: ($) => seq(
      $._kw_finally,
      field('body', $.statement_block),
    ),

    parenthesized_expression: ($) => seq(
      '(',
      $._expressions,
      ')',
    ),

    //
    // Expressions
    //
    _expressions: ($) => choice(
      $.expression,
      $.sequence_expression,
      $._hash_always_eval,
    ),

    expression: ($) => choice(
      $.primary_expression,
      $.assignment_expression,
      $.augmented_assignment_expression,
      $.unary_expression,
      $.binary_expression,
      $.ternary_expression,
      $.elvis_expression,
      $.update_expression,
      $.new_expression,
      $._hash_always_eval,
      $.object_pattern,
      $.query_expression,
    ),

    primary_expression: ($) => choice(
      $.subscript_expression,
      $.member_expression,
      $.parenthesized_expression,
      $._identifier,
      alias($._reserved_identifier, $.identifier),
      $.this,
      $.super,
      $.number,
      $.string,
      $.template_string,
      $.regex,
      $.true,
      $.false,
      $.null,
      $.object,
      $.array,
      $.ordered_struct,
      $.function_expression,
      $.arrow_function,
      $.call_expression,
    ),

    object: ($) => prec('object', seq(
      '{',
      commaSep(optional(choice(
        $.pair,
        $.cf_pair,
        $.spread_element,
        $.method_definition,
        alias(
          choice($.identifier, $._reserved_identifier),
          $.shorthand_property_identifier,
        ),
      ))),
      '}',
    )),

    object_pattern: ($) => prec('object', seq(
      '{',
      commaSep(optional(choice(
        $.pair_pattern,
        $.cf_pair,
        $.rest_pattern,
        $.object_assignment_pattern,
        alias(
          choice($.identifier, $._reserved_identifier),
          $.shorthand_property_identifier_pattern,
        ),
      ))),
      '}',
    )),

    assignment_pattern: ($) => seq(
      field('left', $.pattern),
      '=',
      field('right', $.expression),
    ),

    object_assignment_pattern: ($) => seq(
      field('left', choice(
        alias(choice($._reserved_identifier, $.identifier), $.shorthand_property_identifier_pattern),
        $._destructuring_pattern,
      )),
      '=',
      field('right', $.expression),
    ),

    array: ($) => seq(
      '[',
      commaSep(optional(choice(
        $.expression,
        $.pair,
        $.spread_element,
      ))),
      ']',
    ),

    ordered_struct: ($) => prec(1, seq('[', ':', ']')),

    array_pattern: ($) => seq(
      '[',
      commaSep(optional(choice(
        $.pattern,
        $.assignment_pattern,
      ))),
      ']',
    ),

    nested_identifier: ($) => prec('member', seq(
      field('object', choice($.identifier, alias($.nested_identifier, $.member_expression))),
      /[.:]/,
      field('property', alias($.identifier, $.property_identifier)),
    )),

    component: ($) => prec('literal', seq(
      optional(choice($._kw_static, $._kw_abstract, $._kw_final)),
      choice(
        $._kw_component,
        $._kw_interface,
      ),
      repeat(seq(optional($.tag_linefeed), $.component_attribute)),
      field('body', $.component_body),
    )),

    component_attribute: ($) => choice(
      seq(
        alias($.identifier, $.attribute_label),
        ':',
        $.component_attribute,
      ),
      seq(
        $.identifier,
        '=',
        $.expression,
      ),
      $.identifier,
    ),

    function_expression: ($) => prec('literal', seq(
      $._kw_function,
      field('name', optional($.identifier)),
      $._call_signature,
      repeat(prec(1, $.assignment_expression)),
      field('body', $.statement_block),
    )),

    // NOTE: these overlap with `_reserved_identifier` (they must stay usable as
    // plain identifiers), so they cannot become `token(prec(1, ...))` keywords
    // without breaking `static['key']` / `query.newQuery()`. Left case-sensitive.
    access_type: ($) => choice(
      $._kw_public,
      $._kw_private,
      $._kw_package,
      $._kw_remote,
      $._kw_static,
      $._kw_final,
      $._kw_abstract,
    ),

    parameter_type: ($) => choice(
      keyword('Any'),
      keyword('String'),
      keyword('Numeric'),
      keyword('Xml'),
      keyword('Binary'),
      keyword('Boolean'),
      keyword('Date'),
      $._kw_function,
      keyword('Guid'),
      keyword('Query'),
      keyword('Void'),
      $.path,
      $.identifier,
    ),

    function_declaration: ($) => prec.right('declaration', seq(
      repeat($.access_type),
      optional(choice($._kw_function, keyword('Query'), $.path, $.identifier)),
      $._kw_function,
      field('name', $.identifier),
      $._call_signature,
      repeat(prec(1, seq(optional($.tag_linefeed), choice($.assignment_expression, $.identifier)))),
      choice(
        seq(optional($.tag_linefeed), field('body', $.statement_block), optional($._automatic_semicolon)),
        $._semicolon,
      ),
    )),

    arrow_function: ($) => seq(
      // optional('async'),
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

    _call_signature: ($) => field('parameters', $.formal_parameters),
    _formal_parameter: ($) => choice(
      seq(
        optional(keyword('Required')),
        $.parameter_type,
        optional(choice($.pattern, $.assignment_pattern)),
        repeat($.parameter_attribute),
      ),
      seq(
        optional(keyword('Required')),
        choice($.pattern, $.assignment_pattern),
        repeat($.parameter_attribute),
      ),
    ),

    parameter_attribute: ($) => prec.dynamic(-2, seq(
      $.identifier,
      '=',
      $.string,
    )),

    optional_chain: (_) => '?.',
    static_chain: (_) => '::',

    call_expression: ($) => choice(
      prec('call', seq(
        field('function', choice($.primary_expression, $._hash_always_eval)),
        field('arguments', $.arguments),
      )),
      prec('member', seq(
        field('function', $.primary_expression),
        field('optional_chain', $.optional_chain),
        field('arguments', $.arguments),
      )),
    ),

    new_expression: ($) => prec.right('new', choice(
      seq(
        $._kw_new,
        // Standalone token on purpose: inside `new <X>` the extracted keyword
        // would lex as an identifier, breaking the inline-component form.
        $._kw_component,
        repeat(seq(optional($.tag_linefeed), $.component_attribute)),
        field('body', $.component_body),
      ),
      seq(
        $._kw_new,
        optional(field('prefix', seq(choice('java', 'cfml'), ':'))),
        optional(field('constructor', choice($.primary_expression, $.new_expression))),
        field('arguments', optional(prec.dynamic(1, $.arguments))),
      ),
    )),

    member_expression: $ => prec('member', seq(
      field('object', choice($.expression, $.primary_expression)),
      choice('.', field('optional_chain', $.optional_chain), field('static_chain', $.static_chain)),
      field('property', choice(
        $.private_property_identifier,
        alias($.identifier, $.property_identifier),
        alias($._kw_new, $.property_identifier),
      )),
    )),

    subscript_expression: ($) => prec.right('member', seq(
      field('object', choice($.expression, $.primary_expression)),
      optional(field('optional_chain', $.optional_chain)),
      '[', field('index', $._expressions), ']',
    )),

    _lhs_expression: ($) => choice(
      $.string,
      $.member_expression,
      $.null,
      $.subscript_expression,
      $._identifier,
      alias($._reserved_identifier, $.identifier),
      $._destructuring_pattern,
    ),

    assignment_expression: ($) => prec.right('assign', seq(
      field('left', choice(
        $.parenthesized_expression,
        $._lhs_expression,
      )),
      '=',
      field('right', choice($.expression, $._hash_always_eval)),
    )),

    _augmented_assignment_lhs: ($) => choice(
      $.member_expression,
      $.subscript_expression,
      alias($._reserved_identifier, $.identifier),
      $.identifier,
      $.parenthesized_expression,
    ),

    augmented_assignment_expression: ($) => prec.right('assign', seq(
      field('left', $._augmented_assignment_lhs),
      field('operator', choice('+=', '-=', '*=', '/=', '%=', '^=', '&=', '|=', '>>=', '>>>=',
        '<<=', '**=', '&&=', '||=', '??=')),
      field('right', $.expression),
    )),

    _initializer: ($) => seq(
      '=',
      field('value', $.expression),
    ),

    _destructuring_pattern: ($) => choice(
      $.array_pattern,
    ),

    spread_element: ($) => seq('...', $.expression),

    ternary_expression: ($) => prec.right('ternary', seq(
      field('condition', $.expression),
      alias($._ternary_qmark, '?'),
      field('consequence', $.expression),
      ':',
      field('alternative', $.expression),
    )),

    elvis_expression: ($) => prec.right('elvis', seq(
      field('condition', $.expression),
      alias($._elvis_operator, '?:'),
      field('alternative', $.expression),
    )),

    binary_expression: ($) => choice(
      ...[
        ['&&', 'logical_and'],
        [/[aA][nN][dD]/, 'logical_and'],
        [choice($.logical_or, '||'), 'logical_or'],
        [/[oO][rR]/, 'logical_or'],
        [/[xX][oO][rR]/, 'logical_xor'],
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
        ['\\', 'binary_times'],
        [/[mM][oO][dD]/, 'binary_times'],
        ['**', 'binary_exp', 'right'],
        ['<', 'binary_relation'],
        [/[lL][tT]/, 'binary_relation'],
        ['<=', 'binary_relation'],
        [/[lL][tT][eE]/, 'binary_relation'],
        [/[lL][eE]/, 'binary_relation'],
        ['==', 'binary_equality'],
        ['===', 'binary_equality'],
        [/[eE][qQ]/, 'binary_equality'],
        [/[eE][qQ][uU][aA][lL]/, 'binary_equality'],
        [/[iI][sS]/, 'binary_equality'],
        ['<>', 'binary_equality'],
        ['!=', 'binary_equality'],
        ['!==', 'binary_equality'],
        [/[nN][eE][qQ]/, 'binary_equality'],
        [/[cC][oO][nN][tT][aA][iI][nN][sS]/, 'binary_equality'],
        [/[cC][tT]/, 'binary_equality'],
        [/[dD][oO][eE][sS]\s[nN][oO][tT]\s[cC][oO][nN][tT][aA][iI][nN]/, 'binary_equality'],
        [/[nN][cC][tT]/, 'binary_equality'],
        ['>=', 'binary_relation'],
        [/[gG][tT][eE]/, 'binary_relation'],
        [/[gG][eE]/, 'binary_relation'],
        ['>', 'binary_relation'],
        [/[gG][tT]/, 'binary_relation'],
        [/[gG][rR][eE][aA][tT][eE][rR]\s+[tT][hH][aA][nN]/, 'binary_relation'],
        [/[lL][eE][sS][sS]\s+[tT][hH][aA][nN]/, 'binary_relation'],
        [/[gG][rR][eE][aA][tT][eE][rR]\s+[tT][hH][aA][nN]\s+[oO][rR]\s+[eE][qQ][uU][aA][lL]\s+[tT][oO]/, 'binary_relation'],
        [/[lL][eE][sS][sS]\s+[tT][hH][aA][nN]\s+[oO][rR]\s+[eE][qQ][uU][aA][lL]\s+[tT][oO]/, 'binary_relation'],
        [/[nN][oO][tT]\s+[eE][qQ][uU][aA][lL]/, 'binary_equality'],
        ['??', 'ternary'],
        [$._kw_instanceof, 'binary_relation'],
        [$._kw_in, 'binary_relation'],
      ].map(([operator, precedence, associativity]) =>
        // @ts-ignore
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('left', $.expression),
          field('operator', operator),
          field('right', $.expression),
        )),
      ),
    ),

    // @ts-ignore
    unary_operator: $ => choice(
      '!',
      '~',
      '-',
      '+',
      alias(/[nN][oO][tT]/, 'not'),
    ),

    unary_expression: ($) => prec.left('unary_void', seq(
      field('operator', $.unary_operator),
      field('argument', $.expression),
    )),

    update_expression: ($) => prec.left(choice(
      seq(
        field('argument', $.expression),
        field('operator', choice('++', '--')),
      ),
      seq(
        field('operator', choice('++', '--')),
        field('argument', $.expression),
      ),
    )),

    sequence_expression: ($) => prec.right(commaSep1($.expression)),

    //
    // Primitives
    //

    string: ($) => choice(
      seq(
        '"',
        choice(
          repeat(choice(
            $._hash_always_eval,
            '""',
            alias($.unescaped_double_string_fragment, $.string_fragment),
          )),
        ),
        '"',
      ),

      seq(
        '\'',
        choice(
          repeat(choice(
            alias($.unescaped_single_string_fragment, $.string_fragment),
            $._hash_always_eval,
            '\'\'',
          )),
        ),
        '\'',
      ),
    ),

    // tree-sitter/tree-sitter#1156: named token() regexp rules so string fragments appear in the CST.
    //
    unescaped_double_string_fragment: (_) => token.immediate(prec(1, /[^"#]+/)),

    // Pair: single-quoted string fragment.
    unescaped_single_string_fragment: (_) => token.immediate(prec(1, /[^'#]+/)),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: (_) => token(choice(
      seq('//', /[^\r\n\u2028\u2029]*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    )),

    template_substitution: ($) => seq(
      '${',
      $._expressions,
      '}',
    ),

    regex: ($) => seq(
      '/',
      field('pattern', $.regex_pattern),
      token.immediate(prec(1, '/')),
      optional(field('flags', $.regex_flags)),
    ),

    regex_pattern: (_) => token.immediate(prec(-1,
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

    regex_flags: (_) => token.immediate(/[a-z]+/),

    number: (_) => {
      const hexLiteral = seq(
        choice('0x', '0X'),
        /[\da-fA-F](_?[\da-fA-F])*/,
      );

      const decimalDigits = /\d(_?\d)*/;
      const signedInteger = seq(optional(choice('-', '+')), decimalDigits);
      const exponentPart = seq(choice('e', 'E'), signedInteger);

      const binaryLiteral = seq(choice('0b', '0B'), /[0-1](_?[0-1])*/);

      const octalLiteral = seq(choice('0o', '0O'), /[0-7](_?[0-7])*/);

      const bigintLiteral = seq(choice(hexLiteral, binaryLiteral, octalLiteral, decimalDigits), 'n');

      const decimalIntegerLiteral = choice(
        '0',
        seq(optional('0'), /[1-9]/, optional(seq(optional('_'), decimalDigits))),
      );

      const decimalLiteral = choice(
        seq(decimalIntegerLiteral, '.', optional(decimalDigits), optional(exponentPart)),
        seq('.', decimalDigits, optional(exponentPart)),
        seq(decimalIntegerLiteral, exponentPart),
        decimalDigits,
      );

      return token(choice(
        hexLiteral,
        decimalLiteral,
        binaryLiteral,
        octalLiteral,
        bigintLiteral,
      ));
    },

    // 'undefined' is syntactically a regular identifier in JavaScript.
    // However, its main use is as the read-only global variable whose
    // value is [undefined], for which there's no literal representation
    // unlike 'null'. Kept as a distinct rule for highlighting and tooling.
    _identifier: ($) => choice(
      $.undefined,
      $.identifier,
    ),

    identifier: (_) => {
      // @ts-ignore
      const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,|^&<=>+#\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      return token(seq(alphanumeric, repeat(alphanumeric)));
    },

    private_property_identifier: _ => {
      // @ts-ignore
      const alpha = /[^\x00-\x1F\s\p{Zs}0-9:;`"'@#&?.,\[\]|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;

      // @ts-ignore

      const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#&?.,\[\]|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      return token(seq('~', alpha, repeat(alphanumeric)));
    },


    this: (_) => keyword('This'),
    super: (_) => keyword('Super'),
    true: (_) => keyword('True'),
    false: (_) => keyword('False'),
    null: (_) => keyword('Null'),
    undefined: (_) => keyword('Undefined'),

    //
    // Expression components
    //

    arguments: ($) => seq(
      '(',
      commaSep(optional(choice($.expression, $.pair, $._hash_always_eval, $.spread_element))),
      ')',
    ),

    decorator: ($) => seq(
      '@',
      choice(
        $.identifier,
        alias($.decorator_member_expression, $.member_expression),
        alias($.decorator_call_expression, $.call_expression),
      ),
    ),

    decorator_member_expression: ($) => prec('member', seq(
      field('object', choice(
        $.identifier,
        alias($.decorator_member_expression, $.member_expression),
      )),
      /[.:]/,
      field('property', alias($.identifier, $.property_identifier)),
    )),

    decorator_call_expression: ($) => prec('call', seq(
      field('function', choice(
        $.identifier,
        alias($.decorator_member_expression, $.member_expression),
      )),
      field('arguments', $.arguments),
    )),

    component_body: ($) => seq(
      '{',
      repeat(choice($.statement, $.property_declaration, $.static_initializer)),
      '}',
    ),

    static_initializer: ($) => seq($._kw_static, $.statement_block),

    property_declaration: ($) => seq(
      $._kw_property,
      choice(
        prec.dynamic(1, seq(
          optional(field('type', choice($.path, $.identifier))),
          field('name', $.identifier),
          repeat(seq(optional($.tag_linefeed), $.component_attribute)),
        )),
        repeat1(seq(optional($.tag_linefeed), $.component_attribute)),
      ),
      $._semicolon,
    ),

    field_definition: ($) => seq(
      repeat(field('decorator', $.decorator)),
      optional($._kw_static),
      field('property', $._property_name),
      optional($._initializer),
    ),

    formal_parameters: ($) => seq(
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
    pattern: ($) => prec.dynamic(-1, choice(
      $._lhs_expression,
      $.rest_pattern,
    )),

    rest_pattern: ($) => prec.right(seq(
      '...',
      $._lhs_expression,
    )),

    method_definition: ($) => seq(
      repeat(field('decorator', $.decorator)),
      optional(choice(
        $._kw_static,
        alias(token(seq(/[sS][tT][aA][tT][iI][cC]/, /\s+/, /[gG][eE][tT]/, /\s*\n/)), 'static get'),
      )),
      // optional('async'),
      optional(choice('get', 'set', '*')),
      field('name', $._property_name),
      field('parameters', $.formal_parameters),
      field('body', $.statement_block),
    ),

    pair: ($) => seq(
      field('key', $._property_name),
      ':',
      field('value', $.expression),
    ),

    cf_pair: ($) => seq(
      field('key', $._property_name),
      '=',
      field('value', $.expression),
    ),

    pair_pattern: ($) => seq(
      field('key', $._property_name),
      ':',
      field('value', choice($.pattern, $.assignment_pattern)),
    ),

    _property_name: ($) => choice(
      alias(
        choice($.identifier, $._reserved_identifier),
        $.property_identifier,
      ),
      // $.private_property_identifier,
      $.null,
      $.string,
      $.number,
      $.computed_property_name,
      $._hash_always_eval,
    ),

    _hash_always_eval: ($) => choice(
      $.hash_expression,
      $.hash_empty,
    ),

    _hash: ($) => '#',

    hash_expression: ($) => seq(
      '#',
      $.expression,
      '#',
    ),

    hash_empty: ($) => token.immediate('##'),

    computed_property_name: ($) => seq(
      '[',
      $.expression,
      ']',
    ),

    // NOTE: these stay case-sensitive on purpose. They must remain usable as
    // plain identifiers (`static['key']`, `query.newQuery()`), and a
    // `token(prec(1, ...))` keyword would always win in the lexer.
    _reserved_identifier: ($) => choice(
      'get',
      'set',
      $._kw_static,
      'export',
      'let',
      $._kw_component,
      $._kw_private,
      $._kw_public,
      $._kw_include,
      keyword('Query'),
      keyword('QueryExecute'),
      $._kw_new,
      $._kw_package,
      $._kw_remote,
      $._kw_abstract,
      $._kw_final,
      $._kw_function,
    ),

    _semicolon: ($) => choice($._automatic_semicolon, ';'),

    /*
        END SCRIPT BASED RULES
      */
    template_string: ($) => seq(
      '`',
      repeat(choice(
        alias($._template_chars, $.string_fragment),
        $.template_substitution,
      )),
      '`',
    ),

    cfml_template: ($) => seq('```', $.cfml_template_content, '```'),

    query_expression: ($) => seq(
      keyword('QueryExecute'),
      '(',
      choice(
        seq('"', $.query_text, '"'),
        seq('\'', $.query_text, '\''),
      ),
      repeat(
        seq(
          '&',
          choice(
            seq('"', $.query_text, '"'),
            seq('\'', $.query_text, '\''),
            $.identifier,
            $.parenthesized_expression,
          ),
        ),
      ),
      repeat(seq(',', $.expression)),
      ')',
    ),

    query_tag: ($) => seq(
      keyword('Query'),
      repeat(prec(1, seq(optional($.tag_linefeed), field('arguments', $.assignment_expression)))),
      optional($.tag_linefeed),
      field('body', $.statement_block),
    ),

    tag_statement: $ => choice(
      seq(
        field('tag', $.identifier),
        optional($.tag_linefeed),
        optional(field('arguments', $.arguments)),
        field('body', $.statement_block),
        $._semicolon,
      ),
      seq(
        field('tag', $.identifier),
        field('arguments', repeat1(seq(optional($.tag_linefeed), $.assignment_expression, optional(',')))),
        optional(field('body', $.statement_block)),
        $._semicolon,
      ),
    ),

    // Keyword tokens. Defined once here and referenced as `$._kw_<word>`
    // so a keyword can never be spelled two different ways in two rules —
    // that divergence is what previously produced two competing tokens for
    // `component`. Hidden (leading `_`) so they add no node to the tree.
    _kw_abstract: (_) => keyword('Abstract'),
    _kw_break: (_) => keyword('Break'),
    _kw_case: (_) => keyword('Case'),
    _kw_catch: (_) => keyword('Catch'),
    _kw_component: (_) => keyword('Component'),
    _kw_continue: (_) => keyword('Continue'),
    _kw_debugger: (_) => keyword('Debugger'),
    _kw_default: (_) => keyword('Default'),
    _kw_do: (_) => keyword('Do'),
    _kw_else: (_) => keyword('Else'),
    _kw_final: (_) => keyword('Final'),
    _kw_finally: (_) => keyword('Finally'),
    _kw_for: (_) => keyword('For'),
    _kw_function: (_) => keyword('Function'),
    _kw_if: (_) => keyword('If'),
    _kw_import: (_) => keyword('Import'),
    _kw_in: (_) => keyword('In'),
    _kw_include: (_) => keyword('Include'),
    _kw_instanceof: (_) => keyword('InstanceOf', 'instanceof'),
    _kw_interface: (_) => keyword('Interface'),
    _kw_new: (_) => keyword('New'),
    _kw_of: (_) => keyword('Of'),
    _kw_package: (_) => keyword('Package'),
    _kw_private: (_) => keyword('Private'),
    _kw_property: (_) => keyword('Property'),
    _kw_public: (_) => keyword('Public'),
    _kw_remote: (_) => keyword('Remote'),
    _kw_return: (_) => keyword('Return'),
    _kw_static: (_) => keyword('Static'),
    _kw_switch: (_) => keyword('Switch'),
    _kw_throw: (_) => keyword('Throw'),
    _kw_try: (_) => keyword('Try'),
    _kw_var: (_) => keyword('Var'),
    _kw_while: (_) => keyword('While'),
    _kw_with: (_) => keyword('With'),

  },
});

/**
 * CFML keywords are case-insensitive. Keywords are written in PascalCase and
 * matched in any of the accepted casings, then aliased back to a canonical node
 * name so node names and `.scm` queries stay stable.
 *
 * @param {string} word PascalCase spelling of the keyword, e.g. `Break`.
 * @param {string} [nodeName] Canonical node name. Defaults to `lowerFirst(word)`;
 *   pass it explicitly for tokens starting with punctuation, e.g. `('<Cf', '<cf')`.
 */
function keyword(word, nodeName = lowerFirst(word)) {
  return alias(choice(...casings(word)), nodeName);
}

/**
 * Casings accepted for a keyword. Keywords are written in PascalCase
 * (`Break`, `QueryExecute`, `<Cf`) so all four real-world forms fall out of the
 * one spelling: PascalCase, lowercase, UPPERCASE and camelCase.
 *
 * Interior mixed casing such as `reTURN` is deliberately not matched — it does
 * not occur in real code, and enumerating 2^n variants inflates the lexer.
 *
 * @param {string} word
 * @returns {string[]}
 */
function casings(word) {
  return [...new Set([
    word,
    word.toLowerCase(),
    word.toUpperCase(),
    lowerFirst(word),
  ])];
}

/**
 * Lowercase the first character. This is the canonical node name a keyword is
 * aliased to, which keeps `.scm` queries matching regardless of the casing in
 * the source. Tokens starting with punctuation (`<Cf`) must pass `nodeName`
 * explicitly, since lowercasing `<` is a no-op.
 *
 * @param {string} word
 * @returns {string}
 */
function lowerFirst(word) {
  return word.charAt(0).toLowerCase() + word.slice(1);
}
