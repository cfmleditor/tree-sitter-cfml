/**
 * @file CFML grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// @ts-ignore
module.exports = function defineGrammar(dialect) {
  return grammar({
    name: dialect,

    extras: $ => [
      $.cf_comment,
      $.comment,
      // @ts-ignore
      /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/,
    ],

    // @ts-ignore
    externals: $ => [
      $._automatic_semicolon,
      $._ternary_qmark,
      $._elvis_operator,
      $.logical_or,


      $._start_cf_tag_name,
      $._end_cf_tag_name,
      $.erroneous_cf_end_tag_name,
      $._cf_self_closing_tag_delimiter,
      $._cf_self_closing_void_tag_delimiter,
      $.implicit_cf_end_tag,

      $.raw_text,
      $.cf_comment,
      $._close_tag_delim,
      $._close_cf_tag_delim,
      $.html_text,
      $._start_cf_void_name,
      $._start_cf_set_name,
      $._start_cf_if_name,
      $._end_cf_if_name,
      $._start_cf_elseif_name,
      $._start_cf_else_name,

      ...(dialect !== 'cfquery' ? [

        $._script_start_tag_name,
        $._style_start_tag_name,

        $._start_tag_name,
        $._end_tag_name,
        $.erroneous_end_tag_name,
        $.self_closing_tag_delimiter,
        $.implicit_end_tag,

        $._start_hash_expression,
        $._single_hash,
        $._hash_empty_external,
        $._start_cf_return_name,
        $._start_cf_xml_name,
        $._end_cf_xml_name,
        $.cf_xml_content,
        $._start_cf_query_name,
        $._end_cf_query_name,
        $.cf_query_content,
        $._start_cf_script_name,
        $._end_cf_script_name,
        $.cf_script_content,
        $._start_cf_savecontent_name,
        $._end_cf_savecontent_name,
        $.cf_savecontent_content,
        $._start_cf_output_name,
        $.cf_component_content,
      ] : []),

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
        'binary_is',
        'binary_not',
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
      // [$.export_statement, $.primary_expression],
      // [$.lexical_declaration, $.primary_expression],
    ],

    conflicts: ($) => [
      [$.object, $.object_pattern],
      [$.primary_expression, $.pattern],
      [$.assignment_expression, $.pattern],
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
      [$._hash_expression, $._hash_empty],
      [$.assignment_expression, $._hash_always_eval],
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
      [$.expression, $.for_statement],
      [$.expression, $._cf_tag_expression],
      [$.expression, $.assignment_expression, $._property_name],
      [$.expression, $.function_expression],
      [$.assignment_expression, $._property_name],
      [$.object_assignment_pattern, $._property_name],
      [$.object_assignment_pattern, $.assignment_expression, $._property_name],

      [$.switch_case, $.expression, $._property_name],
      [$.call_expression, $._property_name],
      [$._for_header, $.expression],
    ],

    rules: {

      program: $ => choice(
        repeat($._node),
        ...(dialect !== 'cfquery' ? [
          $.component_file,
        ] : []),
      ),

      ...(dialect !== 'cfquery' ? {
        component_file: $ => $.cf_component_content,
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

      } : {}),

      cf_selfclose_void_tag_end: $ => choice(
        alias($._cf_self_closing_void_tag_delimiter, $.self_closing_tag_delimiter),
        alias($._close_cf_tag_delim, '>'),
      ),

      cf_set_tag: $ => prec.right(3, seq(
        $._cf_open_tag,
        $._start_cf_set_name,
        choice(
          seq(
            alias(choice('var', 'VAR', 'Var', 'vAR', 'vAr', 'vaR', 'VaR', 'VAr'), $.cf_var),
            $._cf_tag_expression,
          ),
          $._cf_tag_expression,
        ),
        $.cf_selfclose_void_tag_end,
      )),

      // @ts-ignore
      text: $ => token(prec(-1, /[^<>&\s#\r\n\u2028\u2029]([^<>&#]*[^<>&\s#\r\n\u2028\u2029])?/)),
      // cf_tag_close: $ => /<\/cf/i,

      _node: $ => choice(
        $._cf_tags,
        $.erroneous_cf_end_tag,
        $.text,
        ...(dialect !== 'cfquery' ? [
          $.html_text,
          $._hash_dialect_eval,
          $.erroneous_end_tag,
          $.doctype,
          $.entity,
          $.element,
          $.script_element,
          $.style_element,
          $.xml_decl,
        ] : [
          $._hash_always_eval,
          $._query_node,
        ]),
      ),

      _cf_open_tag: $ => prec.right(1, keyword('<cf')),
      _cf_close_tag: $ => prec.right(1, keyword('</cf')),

      cf_tag_attributes: $ => choice(
        $.cf_attribute,
        $.quoted_cf_attribute_value,
        $._hash_always_eval,
      ),

      ...(dialect !== 'cfquery' ? {

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

        start_tag: $ => prec.right(3, seq(
          '<',
          alias($._start_tag_name, $.tag_name),
          repeat($.tag_attributes),
          alias($._close_tag_delim, '>'),
        )),

        tag_attributes: $ => choice(
          $.attribute,
          $.quoted_attribute_value,
          $._cf_tags,
          $._hash_always_eval,
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

        self_closing_tag: $ => prec.right(2, seq(
          '<',
          alias($._start_tag_name, $.tag_name),
          repeat(
            $.tag_attributes,
          ),
          choice(
            $.self_closing_tag_delimiter,
            alias($._close_tag_delim, '>'),
          ),
        )),

        end_tag: $ => prec.right(4, seq(
          '</',
          alias($._end_tag_name, $.tag_name),
          alias($._close_tag_delim, '>'),
        )),

        erroneous_end_tag: $ => prec.right(1, seq(
          '</',
          $.erroneous_end_tag_name,
          alias($._close_tag_delim, '>'),
        )),

        style_element: $ => seq(
          alias($.style_start_tag, $.start_tag),
          optional($.raw_text),
          $.end_tag,
        ),

        entity: _ => /&(([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});/,

        quoted_attribute_value: $ => choice(
          seq('\'',
            repeat(
              choice(
                $._cf_tags,
                $._hash_dialect_eval,
                alias(token(prec(1, /[^'<\s\n\r\t#]+/)), $.attribute_value),
              ),
            ),
            '\''),
          seq('"',
            repeat(
              choice(
                $._cf_tags,
                $._hash_dialect_eval,
                alias(token(prec(1, /[^"<\s\n\r\t#]+/)), $.attribute_value),
              ),
            ),
            '"'),
        ),

        attribute: $ => seq(
          $.attribute_name,
          optional(
            seq(
              '=',
              choice(
                $.attribute_value,
                $.quoted_attribute_value,
              ),
            ),
          ),
        ),

        attribute_name: $ => choice(
          /[^<>"'=\s#]+/,
          $._hash_dialect_eval,
        ),

        attribute_value: $ => choice(
          prec.left(1, /[0-9]+/),
          prec.left(2, $._cf_tags),
          prec.left(3, $._hash_dialect_eval),
          prec.left(4, /[^"<>'=\s\n\r\t#]+/),
        ),

        _hash_dialect_eval: ($) => choice(
          $.hash_expression,
          alias($._hash_empty_external, $.hash_empty),
          alias($._single_hash, $.hash_single),
        ),

        hash_expression: ($) => seq($._start_hash_expression, $.expression, $._hash),

      } : {

        _query_node: ($) => choice(
          $.query_identifier,
          $.quoted_query_value,
          $.double_quoted_query_value,
          $.bracketed_query_value,
          $.query_star,
          $.query_alias,
          $.query_assignment_expression,
          $.parenthesized_query_node,
          $.query_number,
          $.null,
          $.query_comma,
          $.query_semicolon,
        ),

        parenthesized_query_node: ($) => seq(
          '(',
          repeat($._node),
          ')',
        ),

        query_alias: ($) => prec.right('assign', seq(
          field('left', $._node),
          '.',
          field('right', $._node),
        )),

        query_comma: ($) => /[,]/,

        query_semicolon: ($) => /[;]/,

        query_assignment_expression: ($) => prec.right('assign', seq(
          field('left', $._node),
          '=',
          field('right', $._node),
        )),

        bracketed_query_value: $ => seq('[',
          repeat(
            choice(
              $._hash_always_eval,
              alias(/[^'\s\n\r\t\[\]#]+/, $.query_value),
            ),
          ),
          ']',
        ),

        quoted_query_value: $ => seq('\'',
          repeat(
            choice(
              $._hash_always_eval,
              alias(/[^'\s\n\r\t\[\]#]+/, $.query_value),
            ),
          ),
          '\'',
        ),

        double_quoted_query_value: $ => seq('"',
          repeat(
            choice(
              $._hash_always_eval,
              alias(/[^'"\s\n\r\t\[\]#]+/, $.query_value),
            ),
          ),
          '"',
        ),

        query_star: ($) => alias(/\*/, $.star),

        query_number: ($) => alias(/[0-9]/, $.number),

        query_identifier: ($) => {
          // @ts-ignore
          // eslint-disable-next-line max-len
          const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,*\[\]|^&"'<=>+,#\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
          return choice(
            token(seq(':', alphanumeric, repeat(alphanumeric))),
            token(seq(alphanumeric, repeat(alphanumeric))),
            alias(/\?/, $.placeholder),
          );
        },

      }),

      erroneous_cf_end_tag: $ => prec.right(1, seq(
        '</',
        $.erroneous_cf_end_tag_name,
        alias($._close_cf_tag_delim, '>'),
      )),

      _cf_tag_expression: $ => choice(
        $.expression,
        $._hash_always_eval,
      ),

      cf_attribute: $ => seq(
        $.cf_attribute_name,
        optional(seq(
          '=',
          choice(
            $.quoted_cf_attribute_value,
            $.cf_attribute_value,
          ),
        )),
      ),

      cf_attribute_value: $ => choice(
        $._hash_always_eval,
        alias(/[^'"\s\n\r\t#:;<>]+/, $.attribute_value),
      ),

      cf_attribute_name: _ => /[^<>"\'/=\s\n\r\t#0-9]+/,

      cf_tag: $ => choice(
        seq(
          $.cf_start_tag,
          repeat($._node),
          choice($.cf_end_tag, $.implicit_cf_end_tag),
        ),
        $.cf_start_tag_with_selfclose,
      ),

      cf_start_tag_with_selfclose: $ => prec.right(2, seq(
        $._cf_open_tag,
        alias($._start_cf_tag_name, $.cf_tag_name),
        repeat(
          $.cf_tag_attributes,
        ),
        $._cf_self_closing_tag_delimiter,
      )),

      cf_start_tag: $ => seq(
        $._cf_open_tag,
        alias($._start_cf_tag_name, $.cf_tag_name),
        repeat($.cf_tag_attributes),
        alias($._close_cf_tag_delim, '>'),
      ),

      cf_end_tag: $ => seq(
        $._cf_close_tag,
        alias($._end_cf_tag_name, $.cf_tag_name),
        alias($._close_cf_tag_delim, '>'),
      ),

      cf_tag_name: _ => /[a-zA-Z][a-zA-Z0-9_]*/,

      ...(dialect !== 'cfquery' ? {

        cf_return_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_return_name,
          optional($.expression),
          $.cf_selfclose_void_tag_end,
        )),

        cf_query_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_query_name,
          repeat($.cf_attribute),
          alias($._close_cf_tag_delim, '>'),
          $.cf_query_content,
          $._cf_close_tag,
          $._end_cf_query_name,
          alias($._close_cf_tag_delim, '>'),
        )),

        cf_xml_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_xml_name,
          repeat($.cf_attribute),
          alias($._close_cf_tag_delim, '>'),
          $.cf_xml_content,
          $._cf_close_tag,
          $._end_cf_xml_name,
          alias($._close_cf_tag_delim, '>'),
        )),

        cf_script_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_script_name,
          repeat($.cf_attribute),
          alias($._close_cf_tag_delim, '>'),
          $.cf_script_content,
          $._cf_close_tag,
          $._end_cf_script_name,
          alias($._close_cf_tag_delim, '>'),
        )),

        cf_savecontent_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_savecontent_name,
          repeat($.cf_attribute),
          alias($._close_cf_tag_delim, '>'),
          $.cf_savecontent_content,
          $._cf_close_tag,
          $._end_cf_savecontent_name,
          alias($._close_cf_tag_delim, '>'),
        )),

        cf_output_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_output_name,
          repeat($.cf_attribute),
          alias($._close_cf_tag_delim, '>'),
          repeat($._node),
          $._cf_close_tag,
          $._end_cf_tag_name,
          alias($._close_cf_tag_delim, '>'),
        )),
      } : {}),

      _cf_tags: $ => prec.right(3, choice(
        $.cf_selfclose_tag,
        $.cf_if_tag,
        $.cf_set_tag,
        $.cf_tag,
        ...(dialect !== 'cfquery' ? [
          $.cf_return_tag,
          $.cf_query_tag,
          $.cf_xml_tag,
          $.cf_script_tag,
          $.cf_savecontent_tag,
          $.cf_output_tag,
        ] : []),
      )),

      cf_selfclose_tag: $ => prec.right(4, seq(
        $._cf_open_tag,
        $._start_cf_void_name,
        optional(repeat($.cf_attribute)),
        $.cf_selfclose_void_tag_end,
      )),

      cf_if_tag: $ => prec.right(1, seq(
        $._cf_open_tag,
        $._start_cf_if_name,
        $._cf_tag_expression,
        alias($._close_cf_tag_delim, '>'),
        repeat($._node),
        optional($.cf_if_alt),
        $._cf_close_tag,
        $._end_cf_if_name,
        alias($._close_cf_tag_delim, '>'),
      )),

      cf_elseif_tag: $ => prec.right(3, seq(
        $._start_cf_elseif_name,
        $._cf_tag_expression,
        alias($._close_cf_tag_delim, '>'),
      )),

      cf_else_tag: $ => prec.right(3, seq(
        $._start_cf_else_name,
        alias($._close_cf_tag_delim, '>'),
      )),

      cf_if_alt: $ => prec.right(3, seq(
        $._cf_open_tag,
        choice(
          $.cf_elseif_tag,
          $.cf_else_tag,
        ),
        optional(repeat($._node)),
        optional($.cf_if_alt),
      )),

      quoted_cf_attribute_value: $ => choice(
        seq('\'',
          repeat(
            choice(
              $._hash_always_eval,
              alias(/[^'\s\n\r\t#]+/, $.attribute_value),
            ),
          ),
          '\''),
        seq('"',
          repeat(
            choice(
              $._hash_always_eval,
              '""',
              alias(/[^"\s\n\r\t#]+/, $.attribute_value),
            ),
          ),
          '"'),
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

      parameter_type: ($) => choice(
        $.path,
        $.identifier,
      ),

      function_declaration: ($) => prec.right('declaration', seq(
        optional($.access_type),
        optional(choice('function', $.path, $.identifier)),
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
          alias(
            $.identifier,
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
          alias($._hash_expression, $.hash_expression),
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
      comment: (_) => choice(
        seq('//', /[^\r\n\u2028\u2029]*/),
        ...(dialect === 'cfquery' ? [
          seq('--', /[^\r\n\u2028\u2029]*/),
        ] : []),
        seq(
          '/*',
          /[^*]*\*+([^/*][^*]*\*+)*/,
          '/',
        ),
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
        // eslint-disable-next-line max-len
        const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#&?.,\[\]|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
        return token(seq('~', alpha, repeat(alphanumeric)));
      },

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
        alias($._hash_expression, $.hash_expression),
        alias($._hash_empty, $.hash_empty),
      ),

      _hash: ($) => '#',

      _hash_expression: ($) => seq(
        '#',
        $.expression,
        '#',
      ),

      _hash_empty: ($) => seq('#', '#'),

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
    },
  });

  /**
   * @param {string} word
   */
  function keyword(word) {
    return alias(reserved(caseInsensitive(word)), word);
  }

  /**
   * @param {string | RegExp} regex
   */
  function reserved(regex) {
    return token(prec(1, new RegExp(regex)));
  }

  /**
   * @param {string} word
   */
  function caseInsensitive(word) {
    return word.split('')
      .map(letter => `[${letter}${letter.toUpperCase()}]`)
      .join('');
  }

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
};
