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
    [$.meta_property, $.import],
    [$.import_statement, $.import],
  ],

  conflicts: ($) => [
    [$.object, $.object_pattern],
    [$.primary_expression, $.pattern],
    [$.assignment_expression, $.pattern],
    [$.function_expression, $.parameter_type],
    [$.primary_expression, $.path],
    [$.primary_expression, $.parameter_type],
    [$.primary_expression, $._property_name],
    [$.primary_expression, $.method_definition],
    [$.primary_expression, $.rest_pattern],
    [$.primary_expression, $._for_header],
    [$.array, $.array_pattern],
    [$.assignment_expression, $.object_assignment_pattern],
    [$.labeled_statement, $._property_name],
    [$.computed_property_name, $.array],
    [$.binary_expression, $._initializer],
    [$.hash_expression, $.hash_empty],
    [$.method_definition, $.access_type],
    [$.expression, $._property_name],
    [$.expression, $.object],
    [$.binary_expression, $.pair],
    [$.member_expression, $.pair],
    [$.subscript_expression, $.pair],
    [$.member_expression, $.subscript_expression, $.pair],
    [$.update_expression, $.pair],
    [$.ternary_expression, $.pair],
    [$.elvis_expression, $.pair],

    [$.expression, $.parenthesized_expression],
    [$.expression, $.expression_statement],

    [$.expression, $.arguments],
    [$.expression, $.assignment_expression],
    [$.expression, $.return_statement],
    [$.expression, $.throw_statement],
    [$.expression, $.assignment_expression, $._property_name],
    [$.assignment_expression, $._property_name],
    [$.object_assignment_pattern, $._property_name],
    [$.object_assignment_pattern, $.assignment_expression, $._property_name],
    [$.switch_case, $.expression, $._property_name],
    [$.call_expression, $._property_name],
    [$._for_header, $.expression],
    [$.expression, $.for_statement],
    [$.parenthesized_expression, $.expression, $.arguments],
    [$.expression, $.template_substitution],

    [$.primary_expression, $.tag_statement],
    [$.expression, $.tag_statement],
    [$.tag_statement, $.expression],
    [$.program, $.statement],
    [$.return_type, $.tag_statement],
    [$.primary_expression, $.tag_statement, $._property_name],
    [$.expression, $.query_tag],
    [$.query_tag, $.expression],
    [$.sequence_expression, $.arguments],
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
      'for',
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
          ')',
        ),
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
      $.pair,
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
      $.function_expression,
      $.arrow_function,
      $.meta_property,
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

    nested_identifier: ($) => prec('member', seq(
      field('object', choice($.identifier, alias($.nested_identifier, $.member_expression))),
      /[.:]/,
      field('property', alias($.identifier, $.property_identifier)),
    )),

    component: ($) => prec('literal', seq(
      optional('static'),
      choice(
        'component',
        'interface',
      ),
      repeat($.component_attribute),
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
      'function',
      field('name', optional($.identifier)),
      $._call_signature,
      repeat($.assignment_expression),
      field('body', $.statement_block),
    )),

    access_type: ($) => choice(
      'public',
      'private',
      'package',
      'remote',
      'static',
      'final',
      'abstract',
    ),

    // Type names that are also Lucee/CFML built-in functions (array, struct, query, etc.)
    // are matched via $.identifier so that e.g. array(1) and structNew() parse as calls.
    return_type: ($) => choice(
      'any',
      'string',
      'numeric',
      'xml',
      'binary',
      'boolean',
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
      'binary',
      'boolean',
      'date',
      'function',
      'guid',
      'void',
      $.path,
      $.identifier,
    ),

    function_declaration: ($) => prec.right('declaration', seq(
      optional($.access_type),
      optional($.return_type),
      'function',
      field('name', $.identifier),
      $._call_signature,
      repeat($.assignment_expression),
      field('body', $.statement_block),
      optional($._automatic_semicolon),
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
    _formal_parameter: ($) => seq(
      optional('required'),
      optional($.parameter_type),
      choice($.pattern, $.assignment_pattern),
    ),

    optional_chain: (_) => '?.',
    static_chain: (_) => '::',

    call_expression: ($) => choice(
      prec('call', seq(
        field('function', choice($.primary_expression, $._hash_always_eval, $.import)),
        field('arguments', $.arguments),
      )),
      prec('member', seq(
        field('function', $.primary_expression),
        field('optional_chain', $.optional_chain),
        field('arguments', $.arguments),
      )),
    ),

    new_expression: ($) => prec.right('new', seq(
      'new',
      field('constructor', choice($.primary_expression, $.new_expression)),
      field('arguments', optional(prec.dynamic(1, $.arguments))),
    )),

    member_expression: $ => prec('member', seq(
      field('object', choice($.expression, $.primary_expression, $.import)),
      choice('.', field('optional_chain', $.optional_chain), field('static_chain', $.static_chain)),
      field('property', choice(
        $.private_property_identifier,
        // Treat common CFML scopes as a distinct kind of identifier so tooling can
        // recognize scope-qualified accesses like variables.foo or session.user.
        alias(
          choice(
            $.identifier,
            alias(
              choice(
                'variables',
                'arguments',
                'session',
                'application',
                'server',
                'cgi',
                'form',
                'url',
                'cookie',
                'client',
                'request',
                'local',
              ),
              $.cf_scope_identifier,
            ),
          ),
          $.property_identifier,
        ),
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
        ['\\\\', 'binary_times'],
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
      seq('--', /[^\r\n\u2028\u2029]*/),
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

    meta_property: (_) => choice(seq('new', '.', 'target'), seq('import', '.', 'meta')),

    this: (_) => token('this'),
    super: (_) => token('super'),
    true: (_) => token('true'),
    false: (_) => token('false'),
    null: (_) => token('null'),
    undefined: (_) => token('undefined'),

    //
    // Expression components
    //

    arguments: ($) => seq(
      '(',
      commaSep(optional(choice($.expression, $._hash_always_eval, $.spread_element))),
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

    hash_empty: ($) => seq('#', '#'),

    computed_property_name: ($) => seq(
      '[',
      $.expression,
      ']',
    ),

    _reserved_identifier: (_) => choice(
      'get',
      'set',
      'static',
      'export',
      'let',
      'component',
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

    query_expression: ($) => seq(
      'queryExecute',
      '(',
      '"',
      $.query_text,
      '"',
      repeat(seq(',', $.expression)),
      ')',
    ),

    query_tag: ($) => seq(
      'query',
      field('arguments', repeat($.assignment_expression)),
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

  },
});
