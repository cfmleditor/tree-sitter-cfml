/**
 * @file CFSCRIPT grammar for tree-sitter
 * @author Gareth Edwards
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'cfscript',

  externals: ($) => [
    $._automatic_semicolon,
    $._template_chars,
    $._ternary_qmark,
    $._elvis_operator,
    '||',
    // We use escape sequence and regex pattern to tell the scanner if we're currently inside a string or template string, in which case
    // it should NOT parse html comments.
    // $.escape_sequence,
    $.regex_pattern,
    $.query_text,
    $.tag_linefeed,
  ],

  extras: ($) => [
    $.comment,
    // @ts-ignore
    /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/,
  ],

  supertypes: ($) => [
    $.statement,
    $.declaration,
    $.expression,
    $.primary_expression,
    $.pattern,
  ],

  inline: ($) => [
    $._call_signature,
    $._formal_parameter,
    $._expressions,
    $._semicolon,
    $._identifier,
    $._reserved_identifier,
    // $._jsx_attribute,
    // $._jsx_element_name,
    // $._jsx_child,
    // $._jsx_element,
    // $._jsx_attribute_name,
    // $._jsx_attribute_value,
    // $._jsx_identifier,
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
    [$.meta_property, $.import],
    [$.import_statement, $.import],
    [$.export_statement, $.primary_expression],
    [$.lexical_declaration, $.primary_expression],
  ],

  conflicts: ($) => [
    [$.primary_expression, $._property_name],
    // [$.primary_expression, $._property_name, $.arrow_function],
    // [$.primary_expression, $.arrow_function],
    [$.primary_expression, $.method_definition],
    [$.primary_expression, $.rest_pattern],
    [$.primary_expression, $.pattern],
    [$.primary_expression, $._for_header],
    [$.variable_declarator, $._for_header],
    [$.array, $.array_pattern],
    [$.object, $.object_pattern],
    [$.assignment_expression, $.pattern],
    [$.assignment_expression, $.object_assignment_pattern],
    [$.labeled_statement, $._property_name],
    [$.computed_property_name, $.array],
    [$.binary_expression, $._initializer],
    // [$.class_static_block, $._property_name],
    [$.hash_expression, $.hash_empty],
    [$.function_expression, $.parameter_type],
    // [$.primary_expression, $.parameter_type],
    [$.primary_expression, $.tag_statement],
    [$.primary_expression, $.path],
    [$.primary_expression, $.tag_statement, $._property_name],
    // [$.primary_expression, $.tag_expression, $.parameter_type],
    [$.component, $.parameter_type],
    // [$.component, $.return_type],
    [$.component, $.primary_expression],
    [$.query_tag, $.return_type],
    [$.query_tag, $.expression],

    // [$.component, $.call_expression],
    // [$.component, $.subscript_expression],
    // [$.component, $.update_expression],
    // [$.component, $.binary_expression],
    // [$.component_body, $.object],

    [$.expression, $._property_name],

    [$.return_type, $.tag_statement],
    [$.tag_statement, $.expression],
    [$.sequence_expression, $.arguments],

    [$.expression, $._function_options],
  ],

  word: ($) => $.identifier,

  rules: {
    program: ($) => seq(
      // optional($.hash_bang_line),
      repeat($.statement),
    ),

    // hash_bang_line: (_) => /#!.*/,

    //
    // Export declarations
    //

    export_statement: ($) => choice(
      seq(
        'export',
        choice(
          seq('*', $._from_clause),
          seq($.namespace_export, $._from_clause),
          seq($.export_clause, $._from_clause),
          $.export_clause,
        ),
        $._semicolon,
      ),
      seq(
        repeat(field('decorator', $.decorator)),
        'export',
        choice(
          field('declaration', $.declaration),
          seq(
            'default',
            choice(
              field('declaration', $.declaration),
              seq(
                field('value', $.expression),
                $._semicolon,
              ),
            ),
          ),
        ),
      ),
    ),

    namespace_export: ($) => seq(
      '*', 'as', $._module_export_name,
    ),

    export_clause: ($) => seq(
      '{',
      commaSep($.export_specifier),
      optional(','),
      '}',
    ),

    export_specifier: ($) => seq(
      field('name', $._module_export_name),
      optional(seq(
        'as',
        field('alias', $._module_export_name),
      )),
    ),

    _module_export_name: ($) => choice(
      $.identifier,
      $.string,
    ),

    declaration: ($) => choice(
      $.function_declaration,
      // $.generator_function_declaration,
      // $.class_declaration,
      $.lexical_declaration,
      $.variable_declaration,
    ),

    //
    // Import declarations
    //

    import: (_) => token('import'),

    import_statement: ($) => seq(
      'import',
      choice(
        seq($.import_clause, $._from_clause),
        field('source', $.string),
        field('source', $.identifier),
        field('source', $.path),
      ),
      optional($.import_attribute),
      $._semicolon,
    ),

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

    import_attribute: ($) => seq('with', $.object),

    //
    // Statements
    //

    statement: ($) => choice(
      $.export_statement,
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

      $.tag_statement,
      $.query_tag,
    ),

    expression_statement: ($) => seq(
      $._expressions,
      $._semicolon,
    ),

    variable_declaration: ($) => seq(
      'var',
      commaSep1($.variable_declarator),
      $._semicolon,
    ),

    lexical_declaration: ($) => seq(
      field('kind', choice('let', 'const')),
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

    else_clause: ($) => seq('else', $.statement),

    if_statement: ($) => prec.right(seq(
      'if',
      field('condition', $.parenthesized_expression),
      field('consequence', $.statement),
      optional(field('alternative', $.else_clause)),
    )),

    switch_statement: ($) => seq(
      'switch',
      field('value', $.parenthesized_expression),
      field('body', $.switch_body),
    ),

    for_statement: ($) => seq(
      'for',
      '(',
      choice(
        field('initializer', choice($.lexical_declaration, $.variable_declaration)),
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

    query_expression: ($) => seq(
      'queryExecute',
      '(',
      '"',
      $.query_text,
      '"',
      repeat(seq(',', $.expression)),
      ')'
    ),

    query_tag: ($) => seq(
      'query',
      field('arguments', repeat($.assignment_expression)),
      field('body', $.statement_block),
    ),

    for_in_statement: ($) => seq(
      'for',
      // optional('await'),
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
          optional($._automatic_semicolon),
        ),
      ),
      field('operator', choice('in', 'of')),
      field('right', $._expressions),
      ')',
    ),

    while_statement: ($) => seq(
      'while',
      field('condition', $.parenthesized_expression),
      field('body', $.statement),
    ),

    do_statement: ($) => prec.right(seq(
      'do',
      field('body', $.statement),
      'while',
      field('condition', $.parenthesized_expression),
      optional($._semicolon),
    )),

    try_statement: ($) => seq(
      'try',
      field('body', $.statement_block),
      optional(field('handler', $.catch_clause)),
      optional(field('finalizer', $.finally_clause)),
    ),

    with_statement: ($) => seq(
      'with',
      field('object', $.parenthesized_expression),
      field('body', $.statement),
    ),

    break_statement: ($) => seq(
      'break',
      field('label', optional(alias($.identifier, $.statement_identifier))),
      $._semicolon,
    ),

    continue_statement: ($) => seq(
      'continue',
      field('label', optional(alias($.identifier, $.statement_identifier))),
      $._semicolon,
    ),

    debugger_statement: ($) => seq(
      'debugger',
      $._semicolon,
    ),

    return_statement: ($) => seq(
      'return',
      optional($._expressions),
      $._semicolon,
    ),

    throw_statement: ($) => seq(
      'throw',
      $._expressions,
      $._semicolon,
    ),

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
      'case',
      field('value', $._expressions),
      ':',
      field('body', repeat($.statement)),
    ),

    switch_default: ($) => seq(
      'default',
      ':',
      field('body', repeat($.statement)),
    ),

    catch_clause: ($) => seq(
      'catch',
      optional(
        seq(
          '(',
          optional(field('type', alias($.identifier, $.catch_type))),
          field('parameter', choice($.identifier, $._destructuring_pattern)),
          ')'
        )
      ),
      field('body', $.statement_block),
    ),

    finally_clause: ($) => seq(
      'finally',
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
    ),

    expression: ($) => choice(
      $.primary_expression,
      // $.glimmer_template,
      // $._jsx_element,
      $.query_expression,
      $.assignment_expression,
      $.augmented_assignment_expression,
      // $.await_expression,
      $.unary_expression,
      $.binary_expression,
      $.ternary_expression,
      $.elvis_expression,
      $.update_expression,
      $.new_expression,
      $.yield_expression,
      $._hash,
      $.object_pattern,
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
      $.function_expression,
      $.arrow_function,
      // $.generator_function,
      // $.class,
      $.component,
      $.meta_property,
      $.call_expression,
    ),

    yield_expression: ($) => prec.right(seq(
      'yield',
      choice(
        seq('*', $.expression),
        optional($.expression),
      ))),

    object: ($) => prec('object', seq(
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

    object_pattern: ($) => prec('object', seq(
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
        $.spread_element,
      ))),
      ']',
    ),

    array_pattern: ($) => seq(
      '[',
      commaSep(optional(choice(
        $.pattern,
        $.assignment_pattern,
      ))),
      ']',
    ),

    // glimmer_template: ($) => choice(
    //   seq(
    //     field('open_tag', $.glimmer_opening_tag),
    //     field('content', repeat($._glimmer_template_content)),
    //     field('close_tag', $.glimmer_closing_tag),
    //   ),
    //   // empty template has no content
    //   // <template></template>
    //   seq(
    //     field('open_tag', $.glimmer_opening_tag),
    //     field('close_tag', $.glimmer_closing_tag),
    //   ),
    // ),

    // _glimmer_template_content: (_) => /.{1,}/,
    // glimmer_opening_tag: (_) => '<template>',
    // glimmer_closing_tag: (_) => '</template>',

    // _jsx_element: ($) => choice($.jsx_element, $.jsx_self_closing_element),

    // jsx_element: ($) => seq(
    //   field('open_tag', $.jsx_opening_element),
    //   repeat($._jsx_child),
    //   field('close_tag', $.jsx_closing_element),
    // ),

    // An entity can be named, numeric (decimal), or numeric (hexadecimal). The
    // longest entity name is 29 characters long, and the HTML spec says that
    // no more will ever be added.
    // html_character_reference: (_) => /&(#([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});/,

    // jsx_expression: ($) => seq(
    //   '{',
    //   optional(choice(
    //     $.expression,
    //     $.sequence_expression,
    //     $.spread_element,
    //   )),
    //   '}',
    // ),

    // _jsx_child: ($) => choice(
    //   $.jsx_text,
    //   // $.html_character_reference,
    //   $._jsx_element,
    //   $.jsx_expression,
    // ),

    // jsx_opening_element: ($) => prec.dynamic(-1, seq(
    //   '<',
    //   optional(seq(
    //     field('name', $._jsx_element_name),
    //     repeat(field('attribute', $._jsx_attribute)),
    //   )),
    //   '>',
    // )),

    // jsx_identifier: (_) => /[a-zA-Z_$][a-zA-Z\d_$]*-[a-zA-Z\d_$\-]*/,

    // _jsx_identifier: ($) => choice(
    //   alias($.jsx_identifier, $.identifier),
    //   $.identifier,
    // ),

    nested_identifier: ($) => prec('member', seq(
      field('object', choice($.identifier, alias($.nested_identifier, $.member_expression))),
      /[.:]/,
      field('property', alias($.identifier, $.property_identifier)),
    )),

    // jsx_namespace_name: ($) => seq($._jsx_identifier, ':', $._jsx_identifier),

    // _jsx_element_name: ($) => choice(
    //   $._jsx_identifier,
    //   alias($.nested_identifier, $.member_expression),
    //   $.jsx_namespace_name,
    // ),

    // jsx_closing_element: ($) => seq(
    //   '</',
    //   optional(field('name', $._jsx_element_name)),
    //   '>',
    // ),

    // jsx_self_closing_element: ($) => seq(
    //   '<',
    //   field('name', $._jsx_element_name),
    //   repeat(field('attribute', $._jsx_attribute)),
    //   '/>',
    // ),

    // _jsx_attribute: ($) => choice($.jsx_attribute, $.jsx_expression),

    // _jsx_attribute_name: ($) => choice(alias($._jsx_identifier, $.property_identifier), $.jsx_namespace_name),

    // jsx_attribute: ($) => seq(
    //   $._jsx_attribute_name,
    //   optional(seq(
    //     '=',
    //     $._jsx_attribute_value,
    //   )),
    // ),

    // _jsx_string: ($) => choice(
    //   seq(
    //     '"',
    //     repeat(choice(
    //       alias($.unescaped_double_jsx_string_fragment, $.string_fragment),
    //       // $.html_character_reference,
    //     )),
    //     '"',
    //   ),
    //   seq(
    //     '\'',
    //     repeat(choice(
    //       alias($.unescaped_single_jsx_string_fragment, $.string_fragment),
    //       // $.html_character_reference,
    //     )),
    //     '\'',
    //   ),
    // ),

    // Workaround to https://github.com/tree-sitter/tree-sitter/issues/1156
    // We give names to the token() constructs containing a regexp
    // so as to obtain a node in the CST.
    //
    // unescaped_double_jsx_string_fragment: (_) => token.immediate(prec(1, /([^"&#]|&[^#A-Za-z])+/)),

    // same here
    // unescaped_single_jsx_string_fragment: (_) => token.immediate(prec(1, /([^'&#]|&[^#A-Za-z])+/)),

    // _jsx_attribute_value: ($) => choice(
    //   alias($._jsx_string, $.string),
    //   $.jsx_expression,
    //   $._jsx_element,
    // ),

    // class: ($) => prec('literal', seq(
    //   repeat(field('decorator', $.decorator)),
    //   'class',
    //   field('name', optional($.identifier)),
    //   optional($.class_heritage),
    //   field('body', $.class_body),
    // )),

    component: ($) => prec('literal', seq(
      optional('static'),
      'component',
      repeat($.component_attribute),
      field('body', $.component_body),
    )),

    component_attribute: ($) => choice(
      seq(
        alias($.identifier, $.attribute_label),
        ':',
        $.component_attribute
      ),
      seq(
        $.identifier,
        '=',
        $.expression,
      ),
      $.identifier,
    ),

    // class_declaration: ($) => prec('declaration', seq(
    //   repeat(field('decorator', $.decorator)),
    //   'class',
    //   field('name', $.identifier),
    //   optional($.class_heritage),
    //   field('body', $.class_body),
    //   optional($._automatic_semicolon),
    // )),

    // class_heritage: ($) => seq('extends', $.expression),

    function_expression: ($) => prec('literal', seq(
      // optional('async'),
      'function',
      field('name', optional($.identifier)),
      $._call_signature,
      repeat($._function_options),
      field('body', $.statement_block),
    )),

    function_access: ($) => choice(
      'public',
      'private',
      'package',
    ),

    return_type: ($) => choice(
      'any',
      'string',
      'numeric',
      'xml',
      'query',
      'struct',
      'array',
      'binary',
      'boolean',
      'component',
      'date',
      'function',
      'guid',
      'void',
      $.identifier,
    ),

    parameter_type: ($) => choice(
      'any',
      'string',
      'numeric',
      'xml',
      'query',
      'struct',
      'array',
      'binary',
      'boolean',
      'component',
      'date',
      'function',
      'guid',
      'void',
      $.path,
    ),

    function_declaration: ($) => prec.right('declaration', seq(
      // optional('async'),
      optional($.function_access),
      optional($.return_type),
      'function',
      field('name', $.identifier),
      $._call_signature,
      repeat($._function_options),
      field('body', $.statement_block),
      optional($._automatic_semicolon),
    )),

    _function_options: ($) => choice(  
      $.assignment_expression,
      alias($.assignment_expression2, $.assignment_expression),
    ),

    // generator_function: ($) => prec('literal', seq(
    //   optional('async'),
    //   'function',
    //   '*',
    //   field('name', optional($.identifier)),
    //   $._call_signature,
    //   field('body', $.statement_block),
    // )),

    // generator_function_declaration: ($) => prec.right('declaration', seq(
    //   optional('async'),
    //   'function',
    //   '*',
    //   field('name', $.identifier),
    //   $._call_signature,
    //   field('body', $.statement_block),
    //   optional($._automatic_semicolon),
    // )),

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

    // Override

    // _call_signature: $ => seq(
    //   field('type_parameters', optional($.type_parameters)),
    //   field('parameters', $.formal_parameters),
    //   field('return_type', optional(
    //     choice($.type_annotation, $.asserts_annotation, $.type_predicate_annotation),
    //   )),
    // ),

    _call_signature: ($) => field('parameters', $.formal_parameters),
    _formal_parameter: ($) => seq(
      optional('required'),
      optional($.parameter_type),
      choice($.pattern, $.assignment_pattern)
    ),

    optional_chain: (_) => '?.',
    static_chain: (_) => '::',

    call_expression: ($) => choice(
      prec('call', seq(
        field('function', choice($.expression, $.import)),
        field('arguments', choice($.arguments, $.template_string)),
      )),
      prec('member', seq(
        field('function', $.primary_expression),
        field('optional_chain', $.optional_chain),
        field('arguments', $.arguments),
      )),
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

    new_expression: ($) => prec.right('new', seq(
      'new',
      field('constructor', choice($.primary_expression, $.new_expression)),
      field('arguments', optional(prec.dynamic(1, $.arguments))),
    )),

    // await_expression: ($) => prec('unary_void', seq(
    //   'await',
    //   $.expression,
    // )),

    member_expression: ($) => prec('member', seq(
      field('object', choice($.expression, $.primary_expression, $.import)),
      choice('.', field('optional_chain', $.optional_chain), field('static_chain', $.static_chain)),
      field('property', alias($.identifier, $.property_identifier)),
    )),

    subscript_expression: ($) => prec.right('member', seq(
      field('object', choice($.expression, $.primary_expression)),
      optional(field('optional_chain', $.optional_chain)),
      '[', field('index', $._expressions), ']',
    )),

    _lhs_expression: ($) => choice(
      $.member_expression,
      $.null,
      $.subscript_expression,
      $._identifier,
      alias($._reserved_identifier, $.identifier),
      $._destructuring_pattern,
    ),

    assignment_expression: ($) => prec.right('assign', seq(
      field('left', choice($.parenthesized_expression, $._lhs_expression)),
      '=',
      field('right', $.expression),
    )),

    assignment_expression2: ($) => prec.right('assign', seq(
      field('left', choice($.parenthesized_expression, $._lhs_expression)),
      ':',
      field('right', $.expression),
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
        ['<>', 'binary_equality'],
        ['!=', 'binary_equality'],
        ['!==', 'binary_equality'],
        [/[nN][eE][qQ]/, 'binary_equality'],
        [/[cC][oO][nN][tT][aA][iI][nN][sS]/, 'binary_equality'],
        [/[dD][oO][eE][sS]\s[nN][oO][tT]\s[cC][oO][nN][tT][aA][iI][nN]/, 'binary_equality'],
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
          field('left', $.expression),
          field('operator', operator),
          field('right', $.expression),
        )),
      ),
    ),

    unary_expression: ($) => prec.left('unary_void', seq(
      field('operator', choice('!', '~', '-', '+')),
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
          // $.hash_single,
          repeat(choice(
            $._hash,
            '""',
            // $.escape_sequence,
            alias($.unescaped_double_string_fragment, $.string_fragment),
          )),
        ),
        '"',
      ),

      seq(
        '\'',
        choice(
          // $.hash_single,
          repeat(choice(
            alias($.unescaped_single_string_fragment, $.string_fragment),
            $._hash,
            '\'\'',
            // $.escape_sequence,
          )),
        ),
        '\'',
      ),
    ),

    // Workaround to https://github.com/tree-sitter/tree-sitter/issues/1156
    // We give names to the token() constructs containing a regexp
    // so as to obtain a node in the CST.
    //
    unescaped_double_string_fragment: (_) => token.immediate(prec(1, /[^"#\r\n]+/)),

    // same here
    unescaped_single_string_fragment: (_) => token.immediate(prec(1, /[^'#\r\n]+/)),

    // escape_sequence: (_) => token.immediate(seq(
    //   '\\',
    //   choice(
    //     /[^xu0-7]/,
    //     /[0-7]{1,3}/,
    //     /x[0-9a-fA-F]{2}/,
    //     /u[0-9a-fA-F]{4}/,
    //     /u\{[0-9a-fA-F]+\}/,
    //     /[\r?][\n\u2028\u2029]/,
    //   ),
    // )),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: (_) => token(choice(
      seq('//', /[^\r\n\u2028\u2029]*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    )),

    template_string: ($) => seq(
      '`',
      repeat(choice(
        alias($._template_chars, $.string_fragment),
        // $.escape_sequence,
        $.template_substitution,
      )),
      '`',
    ),

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
    // unlike 'null'. We gave it its own rule so it's easy to
    // highlight in text editors and other applications.
    _identifier: ($) => choice(
      $.undefined,
      $.identifier,
    ),

    identifier: (_) => {
      // eslint-disable-next-line max-len
      // @ts-ignore
      // const alpha = /[^\x00-\x1F\s\p{Zs}0-9:;`"'@#.,|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      // eslint-disable-next-line max-len
      // @ts-ignore
      const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,|^&<=>+#\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      return token(seq(alphanumeric, repeat(alphanumeric)));
    },

    // private_property_identifier: (_) => {
    //   // eslint-disable-next-line max-len
    //   // @ts-ignore
    //   const alpha = /[^\x00-\x1F\s\p{Zs}0-9:;`"'@b.,|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
    //   // eslint-disable-next-line max-len
    //   // @ts-ignore
    //   const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
    //   return token(seq('#', alpha, repeat(alphanumeric)));
    // },

    meta_property: (_) => choice(seq('new', '.', 'target'), seq('import', '.', 'meta')),

    this: (_) => 'this',
    super: (_) => 'super',
    true: (_) => 'true',
    false: (_) => 'false',
    null: (_) => 'null',
    undefined: (_) => 'undefined',

    //
    // Expression components
    //

    arguments: ($) => seq(
      '(',
      commaSep(optional(choice($.expression, alias($.assignment_expression2, $.assignment_expression), $.spread_element))),
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
      repeat($.statement),
      '}',
    ),

    field_definition: ($) => seq(
      repeat(field('decorator', $.decorator)),
      optional('static'),
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

    // class_static_block: ($) => seq(
    //   'static',
    //   optional($._automatic_semicolon),
    //   field('body', $.statement_block),
    // ),

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
        'static',
        alias(token(seq('static', /\s+/, 'get', /\s*\n/)), 'static get'),
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
      $.string,
      $.number,
      $.computed_property_name,
      $._hash,
    ),

    _hash: ($, previous) => {
      const choices = [];
      choices.push($.hash_expression);
      choices.push($.hash_empty);
      return choice(...choices);
    },

    hash_expression: ($) => seq(
      '#',
      optional($.expression),
      '#',
    ),

    hash_empty: ($) => seq('#', '#'),

    computed_property_name: ($) => seq(
      '[',
      $.expression,
      ']',
    ),

    _reserved_identifier: (_) => choice(
      'get',
      'set',
      // 'async',
      'static',
      'export',
      'let',
    ),

    // _reserved_scope: ($) => choice(
    //   'arguments',
    //   'form',
    //   'url',
    //   'variables',
    //   'cgi',
    //   'cookies',
    //   'server',
    //   'application',
    //   'request',
    //   'session',
    //   'local',
    //   'client',
    // ),

    _semicolon: ($) => choice($._automatic_semicolon, ';'),
  },
});

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
