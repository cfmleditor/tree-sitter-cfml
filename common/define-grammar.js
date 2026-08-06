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

    word: ($) => $.identifier,

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
      $._start_cf_return_name,
      $._start_cf_output_name,

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
        $._cf_savecontent_body_cfml,
        $._cf_savecontent_body_html,
        $._cf_savecontent_body_script,
        $._cf_savecontent_body_css,
        $._cf_savecontent_body_xml,
        $._cf_savecontent_body_sql,
        $._cf_savecontent_body_raw,
        $.cf_savecontent_content,
        $._start_cf_function_name,
        $._end_cf_function_name,
        $._start_cf_component_name,
        $._end_cf_component_name,
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
      $._kw_export,
      $._kw_final,
      $._kw_finally,
      $._kw_for,
      $._kw_function,
      $._kw_get,
      $._kw_if,
      $._kw_import,
      $._kw_in,
      $._kw_instanceof,
      $._kw_let,
      $._kw_new,
      $._kw_package,
      $._kw_private,
      $._kw_public,
      $._kw_remote,
      $._kw_return,
      $._kw_set,
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
        ...(dialect === 'cfquery' ? ['query_repeat'] : []),
      ],
      ['assign', $.primary_expression, ...(dialect === 'cfquery' ? ['query_repeat'] : [])],
      ['member', 'new', 'call', $.expression],
      ['declaration', 'literal'],
      [$.primary_expression, $.statement_block, 'object'],
      // [$.export_statement, $.primary_expression],
      // [$.lexical_declaration, $.primary_expression],
    ],

    conflicts: ($) => [
      // `new` doubles as an identifier (`<cfset var new = "">`), so at `new x`
      // both the `new_expression` and the plain-identifier reading must stay
      // alive until the parser sees what follows.
      [$.primary_expression, $.new_expression],
      [$.new_expression, $.pattern],
      [$.primary_expression, $.new_expression, $._property_name],
      // `var`/`final` followed by a dotted name is a scoped declaration
      // (`var local.x = 1`), but the same prefix can also start an expression.
      [$.variable_declaration, $.primary_expression, $._property_name],
      [$.variable_declaration, $.access_type],
      [$.variable_declaration, $.primary_expression],
      [$.object, $.object_pattern],
      [$.primary_expression, $.pattern],
      [$.assignment_expression, $.pattern],
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
      // `for ( var x = y in z )` — the initializer, an assignment and a binary
      // `in` expression all fit the same prefix.
      [$.assignment_expression, $._initializer, $.binary_expression],
      [$.assignment_expression, $._hash_always_eval],
      [$.method_definition, $.access_type],
      // `pair` (expression ':' expression) is reachable from `arguments` and
      // `array`, so `case <expr> :` is ambiguous with the start of a pair.
      [$.switch_case, $.expression],
      [$.expression, $.parenthesized_expression],
      [$.function_expression, $.pattern],
      [$.expression, $.expression_statement],
      [$.expression, $.arguments],
      // `throw ( x )` is ambiguous between `arguments` and a parenthesized expression.
      [$.parenthesized_expression, $.expression, $.arguments],
      [$.parenthesized_expression, $.arguments],
      [$.sequence_expression, $.arguments],
      [$.expression, $.assignment_expression],
      [$.expression, $.return_statement],
      [$.expression, $.throw_statement],
      [$.expression, $.for_statement],
      [$.expression, $._cf_tag_expression],
      [$.expression, $.function_expression],
      [$.assignment_expression, $._property_name],
      [$.object_assignment_pattern, $._property_name],
      [$.object_assignment_pattern, $.assignment_expression, $._property_name],

      [$.call_expression, $._property_name],
      [$._for_header, $.expression],
      [$.parameter_attribute, $.assignment_expression, $.pattern],
      ...(dialect === 'cfquery' ? [
        [$.cf_output_tag, $.query_comparison_expression],
        [$.cf_output_tag, $.query_assignment_expression],
        [$.parenthesized_query_node, $.query_open_paren],
      ] : []),
    ],

    rules: {

      program: $ => choice(
        ...(dialect === 'cfquery' ?
          [repeat(prec('query_repeat', $._node))] :
          [repeat(choice($._node, $.cf_component_open_tag, $.cf_component_close_tag))]),
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
          $._kw_xml,
          repeat($.tag_attributes),
          '?>',
        ),

        cdata_section: $ => seq(
          '<![CDATA[',
          repeat(choice(
            $._hash_dialect_eval,
            $._cf_tags,
            alias(token(prec(-1, /[^\]#<]+/)), $.cdata_text),
            alias(token(prec(-2, /[\]<]/)), $.cdata_text),
          )),
          ']]>',
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
            alias($._kw_var, $.cf_var),
            $._cf_tag_expression,
          ),
          seq(
            alias($._kw_final, $.cf_var),
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
          $.cdata_section,
          $.xml_decl,
        ] : [
          $._hash_always_eval,
          $._query_node,
        ]),
      ),

      _cf_open_tag: $ => prec.right(1, keyword('<Cf', '<cf')),
      _cf_close_tag: $ => prec.right(1, keyword('</Cf', '</cf')),

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
          repeat(choice(alias($.raw_text, $.script_text), $._cf_tags, $._hash_dialect_eval)),
          $.end_tag,
        ),

        start_tag: $ => prec.right(3, seq(
          '<',
          choice(
            alias($._start_tag_name, $.tag_name),
            alias($._hash_dialect_eval, $.tag_name),
          ),
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
          choice(
            alias($._start_tag_name, $.tag_name),
            alias($._hash_dialect_eval, $.tag_name),
          ),
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
          choice(
            alias($._end_tag_name, $.tag_name),
            alias($._hash_dialect_eval, $.tag_name),
          ),
          alias($._close_tag_delim, '>'),
        )),

        erroneous_end_tag: $ => prec.right(1, seq(
          '</',
          $.erroneous_end_tag_name,
          alias($._close_tag_delim, '>'),
        )),

        style_element: $ => seq(
          alias($.style_start_tag, $.start_tag),
          repeat(choice(alias($.raw_text, $.style_text), $._cf_tags, $._hash_dialect_eval)),
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
                alias(token(prec(-1, '<')), $.attribute_value),
              ),
            ),
            '\''),
          seq('"',
            repeat(
              choice(
                $._cf_tags,
                $._hash_dialect_eval,
                alias(token(prec(1, /[^"<\s\n\r\t#]+/)), $.attribute_value),
                alias(token(prec(-1, '<')), $.attribute_value),
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
          $.query_keyword,
          $.query_identifier,
          $.quoted_query_value,
          $.double_quoted_query_value,
          $.bracketed_query_value,
          $.backtick_quoted_query_value,
          $.query_star,
          $.query_function,
          $.query_function_name,
          $.query_alias,
          $.query_math_expression,
          $.query_concat_expression,
          $.query_comparison_expression,
          $.query_assignment_expression,
          $.parenthesized_query_node,
          $.query_number,
          $.null,
          $.query_comma,
          $.query_semicolon,
          $.query_operator,
          $.query_open_paren,
          $.query_close_paren,
        ),

        parenthesized_query_node: ($) => seq(
          '(',
          repeat(prec('query_repeat', $._node)),
          ')',
        ),

        query_function: ($) => prec(1, seq(
          field('name', $.query_function_name),
          field('arguments', $.parenthesized_query_node),
        )),

        query_alias: ($) => prec.right('assign', seq(
          field('left', $._node),
          '.',
          field('right', $._node),
        )),

        query_comma: ($) => /[,]/,

        query_semicolon: ($) => /[;]/,

        query_operator: ($) => prec(-1, choice('<=', '>=', '<>', '!=', '<', '>', '=')),

        query_open_paren: ($) => '(',
        query_close_paren: ($) => prec(-1, ')'),

        query_assignment_expression: ($) => prec.right('assign', seq(
          field('left', $._node),
          '=',
          field('right', $._node),
        )),

        query_comparison_expression: ($) => prec.left('binary_compare', seq(
          field('left', $._node),
          field('operator', choice('<=', '>=', '<>', '!=', '<', '>')),
          field('right', $._node),
        )),

        // `&` is SQL Server's bitwise AND (`WHERE status & 2048 = 2048`). It is
        // only an operator here — inside `#...#` it is CFML concatenation, which
        // the hash expression grammar handles separately.
        query_math_expression: ($) => prec.left('binary_plus', seq(
          field('left', $._node),
          field('operator', choice('-', '/', '%', '&', '|', '^')),
          field('right', $._node),
        )),

        query_concat_expression: ($) => prec.left('binary_plus', seq(
          field('left', $._node),
          '+',
          optional(field('right', $._node)),
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

        backtick_quoted_query_value: $ => seq('`',
          repeat(
            choice(
              $._hash_always_eval,
              alias(/[^`\s\n\r\t#]+/, $.query_value),
            ),
          ),
          '`',
        ),

        quoted_query_value: $ => seq('\'',
          repeat(
            choice(
              $._hash_always_eval,
              alias(token(prec(1, /[^'#]+/)), $.query_value),
            ),
          ),
          '\'',
        ),

        double_quoted_query_value: $ => seq('"',
          repeat(
            choice(
              $._hash_always_eval,
              alias(token(prec(1, /[^"#]+/)), $.query_value),
            ),
          ),
          '"',
        ),

        query_star: ($) => alias(/\*/, $.star),

        query_number: ($) => alias(/-?[0-9]+/, $.number),

        query_keyword: ($) => token(choice(
          /[sS][eE][lL][eE][cC][tT]/,
          /[fF][rR][oO][mM]/,
          /[wW][hH][eE][rR][eE]/,
          /[aA][nN][dD]/,
          /[oO][rR]/,
          /[nN][oO][tT]/,
          /[iI][nN]/,
          /[iI][sS]/,
          /[aA][sS]/,
          /[oO][nN]/,
          /[bB][yY]/,
          /[jJ][oO][iI][nN]/,
          /[iI][nN][nN][eE][rR]/,
          /[lL][eE][fF][tT]/,
          /[rR][iI][gG][hH][tT]/,
          /[oO][uU][tT][eE][rR]/,
          /[cC][rR][oO][sS][sS]/,
          /[fF][uU][lL][lL]/,
          /[oO][rR][dD][eE][rR]/,
          /[gG][rR][oO][uU][pP]/,
          /[hH][aA][vV][iI][nN][gG]/,
          /[lL][iI][mM][iI][tT]/,
          /[oO][fF][fF][sS][eE][tT]/,
          /[uU][nN][iI][oO][nN]/,
          /[aA][lL][lL]/,
          /[dD][iI][sS][tT][iI][nN][cC][tT]/,
          /[iI][nN][sS][eE][rR][tT]/,
          /[iI][nN][tT][oO]/,
          /[vV][aA][lL][uU][eE][sS]/,
          /[uU][pP][dD][aA][tT][eE]/,
          /[dD][eE][lL][eE][tT][eE]/,
          /[sS][eE][tT]/,
          /[cC][aA][sS][eE]/,
          /[wW][hH][eE][nN]/,
          /[tT][hH][eE][nN]/,
          /[eE][lL][sS][eE]/,
          /[eE][nN][dD]/,
          /[bB][eE][tT][wW][eE][eE][nN]/,
          /[lL][iI][kK][eE]/,
          /[tT][oO][pP]/,
          /[dD][eE][sS][cC]/,
          /[aA][sS][cC]/,
          /[oO][vV][eE][rR]/,
          /[pP][aA][rR][tT][iI][tT][iI][oO][nN]/,
          /[wW][iI][tT][hH]/,
          /[mM][eE][rR][gG][eE]/,
          /[uU][sS][iI][nN][gG]/,
          /[mM][aA][tT][cC][hH][eE][dD]/,
          /[pP][iI][vV][oO][tT]/,
          /[uU][nN][pP][iI][vV][oO][tT]/,
          /[fF][eE][tT][cC][hH]/,
          /[nN][eE][xX][tT]/,
          /[oO][nN][lL][yY]/,
          /[rR][oO][wW][sS]/,
          /[fF][oO][rR]/,
          /[tT][rR][uU][nN][cC][aA][tT][eE]/,
          /[tT][aA][bB][lL][eE]/,
          /[eE][xX][eE][cC]/,
          /[wW][iI][nN][dD][oO][wW]/,
          /[bB][eE][gG][iI][nN]/,
          /[wW][hH][iI][lL][eE]/,
          /[gG][oO]/,
          /[eE][oO][fF]/,
        )),

        query_function_name: ($) => token(choice(
          /[cC][aA][sS][tT]/,
          /[cC][oO][uU][nN][tT]/,
          /[sS][uU][mM]/,
          /[aA][vV][gG]/,
          /[mM][iI][nN]/,
          /[mM][aA][xX]/,
          /[cC][oO][aA][lL][eE][sS][cC][eE]/,
          /[nN][uU][lL][lL][iI][fF]/,
          /[iI][fF][nN][uU][lL][lL]/,
          /[iI][sS][nN][uU][lL][lL]/,
          /[eE][xX][iI][sS][tT][sS]/,
          /[tT][rR][iI][mM]/,
          /[lL][tT][rR][iI][mM]/,
          /[rR][tT][rR][iI][mM]/,
          /[uU][pP][pP][eE][rR]/,
          /[lL][oO][wW][eE][rR]/,
          /[lL][eE][nN]/,
          /[lL][eE][nN][gG][tT][hH]/,
          /[sS][uU][bB][sS][tT][rR][iI][nN][gG]/,
          /[sS][uU][bB][sS][tT][rR]/,
          /[rR][eE][pP][lL][aA][cC][eE]/,
          /[cC][oO][nN][cC][aA][tT]/,
          /[cC][oO][nN][vV][eE][rR][tT]/,
          /[rR][oO][uU][nN][dD]/,
          /[fF][lL][oO][oO][rR]/,
          /[cC][eE][iI][lL][iI][nN][gG]/,
          /[aA][bB][sS]/,
          /[dD][aA][tT][eE][aA][dD][dD]/,
          /[dD][aA][tT][eE][dD][iI][fF][fF]/,
          /[dD][aA][tT][eE][pP][aA][rR][tT]/,
          /[gG][eE][tT][dD][aA][tT][eE]/,
          /[yY][eE][aA][rR]/,
          /[mM][oO][nN][tT][hH]/,
          /[dD][aA][yY]/,
          /[rR][oO][wW][_][nN][uU][mM][bB][eE][rR]/,
          /[rR][aA][nN][kK]/,
          /[dD][eE][nN][sS][eE][_][rR][aA][nN][kK]/,
          /[nN][tT][iI][lL][eE]/,
          /[lL][eE][aA][dD]/,
          /[lL][aA][gG]/,
          /[fF][iI][rR][sS][tT][_][vV][aA][lL][uU][eE]/,
          /[lL][aA][sS][tT][_][vV][aA][lL][uU][eE]/,
          /[sS][tT][rR][iI][nN][gG][_][aA][gG][gG]/,
          /[gG][rR][oO][uU][pP][_][cC][oO][nN][cC][aA][tT]/,
          /[jJ][sS][oO][nN][_][vV][aA][lL][uU][eE]/,
          /[jJ][sS][oO][nN][_][qQ][uU][eE][rR][yY]/,
          /[iI][iI][fF]/,
          /[sS][iI][gG][nN]/,
          /[pP][oO][wW][eE][rR]/,
          /[sS][qQ][rR][tT]/,
          /[lL][oO][gG]/,
          /[lL][oO][gG]10/,
          /[eE][xX][pP]/,
          /[mM][oO][dD]/,
          /[lL][eE][fF][tT]/,
          /[rR][iI][gG][hH][tT]/,
          /[rR][eE][vV][eE][rR][sS][eE]/,
          /[sS][tT][uU][fF][fF]/,
          /[sS][pP][aA][cC][eE]/,
          /[rR][eE][pP][lL][iI][cC][aA][tT][eE]/,
          /[cC][hH][aA][rR][iI][nN][dD][eE][xX]/,
          /[pP][aA][tT][iI][nN][dD][eE][xX]/,
          /[fF][oO][rR][mM][aA][tT]/,
          /[sS][tT][rR]/,
          /[aA][sS][cC][iI][iI]/,
          /[uU][nN][iI][cC][oO][dD][eE]/,
          /[nN][eE][wW][iI][dD]/,
          /[sS][cC][oO][pP][eE][_][iI][dD][eE][nN][tT][iI][tT][yY]/,
          /[oO][bB][jJ][eE][cC][tT][_][iI][dD]/,
          /[oO][bB][jJ][eE][cC][tT][_][nN][aA][mM][eE]/,
          /[cC][oO][lL][_][lL][eE][nN][gG][tT][hH]/,
          /[dD][aA][tT][eE][nN][aA][mM][eE]/,
          /[eE][oO][mM][oO][nN][tT][hH]/,
          /[gG][eE][tT][uU][tT][cC][dD][aA][tT][eE]/,
          /[sS][yY][sS][dD][aA][tT][eE][tT][iI][mM][eE]/,
          /[cC][uU][rR][rR][eE][nN][tT][_][tT][iI][mM][eE][sS][tT][aA][mM][pP]/,
          /[cC][uU][rR][rR][eE][nN][tT][_][dD][aA][tT][eE]/,
          /[cC][hH][eE][cC][kK][sS][uU][mM]/,
          /[hH][aA][sS][hH][bB][yY][tT][eE][sS]/,
          /[rR][oO][wW][sS]/,
          // SQL types
          /[cC][hH][aA][rR]/,
          /[vV][aA][rR][cC][hH][aA][rR]/,
          /[nN][vV][aA][rR][cC][hH][aA][rR]/,
          /[nN][cC][hH][aA][rR]/,
          /[dD][eE][cC][iI][mM][aA][lL]/,
          /[nN][uU][mM][eE][rR][iI][cC]/,
          /[vV][aA][rR][bB][iI][nN][aA][rR][yY]/,
          /[bB][iI][nN][aA][rR][yY]/,
          /[fF][lL][oO][aA][tT]/,
          /[rR][eE][aA][lL]/,
          /[dD][oO][uU][bB][lL][eE]/,
          /[iI][nN][tT][eE][gG][eE][rR]/,
          /[iI][nN][tT]/,
          /[bB][iI][gG][iI][nN][tT]/,
          /[sS][mM][aA][lL][lL][iI][nN][tT]/,
          /[tT][iI][nN][yY][iI][nN][tT]/,
          /[dD][aA][tT][eE][tT][iI][mM][eE]2/,
          /[dD][aA][tT][eE][tT][iI][mM][eE]/,
          /[sS][mM][aA][lL][lL][dD][aA][tT][eE][tT][iI][mM][eE]/,
          /[tT][iI][mM][eE]/,
          /[tT][eE][xX][tT]/,
          /[nN][tT][eE][xX][tT]/,
          /[iI][mM][aA][gG][eE]/,
          /[mM][oO][nN][eE][yY]/,
          /[sS][mM][aA][lL][lL][mM][oO][nN][eE][yY]/,
          /[bB][iI][tT]/,
          /[uU][nN][iI][qQ][uU][eE][iI][dD][eE][nN][tT][iI][fF][iI][eE][rR]/,
          /[xX][mM][lL]/,
          /[sS][qQ][lL][_][vV][aA][rR][iI][aA][nN][tT]/,
          /[cC][lL][oO][bB]/,
          /[bB][lL][oO][bB]/,
          /[nN][cC][lL][oO][bB]/,
          /[bB][oO][oO][lL][eE][aA][nN]/,
          /[nN][uU][mM][bB][eE][rR]/,
          /[vV][aA][rR][cC][hH][aA][rR]2/,
        )),

        query_identifier: ($) => {
          // @ts-ignore
          // eslint-disable-next-line max-len
          const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,*\[\]|^&"'<=>+,#\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
          return choice(
            token(seq(':', alphanumeric, repeat(alphanumeric))),
            token(seq(alphanumeric, repeat(alphanumeric))),
            token(seq('@@', alphanumeric, repeat(alphanumeric))),
            token(seq('@', alphanumeric, repeat(alphanumeric))),
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

      cf_attribute_name: _ => /[^<>"'/=\s\n\r\t#0-9][^<>"'/=\s\n\r\t#]*/,

      cf_tag: $ => choice(
        seq(
          $.cf_start_tag,
          repeat(dialect === 'cfquery' ? prec('query_repeat', $._node) : $._node),
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
          optional(choice(
            $.cf_savecontent_body,
            $.cf_savecontent_body_html,
            $.cf_savecontent_body_script,
            $.cf_savecontent_body_css,
            $.cf_savecontent_body_xml,
            $.cf_savecontent_body_sql,
            $.cf_savecontent_body_raw,
          )),
          $._cf_close_tag,
          $._end_cf_savecontent_name,
          alias($._close_cf_tag_delim, '>'),
        )),

        cf_savecontent_body: $ => seq($._cf_savecontent_body_cfml, repeat($._node)),
        cf_savecontent_body_html: $ => seq($._cf_savecontent_body_html, $.cf_savecontent_content),
        cf_savecontent_body_script: $ => seq($._cf_savecontent_body_script, $.cf_savecontent_content),
        cf_savecontent_body_css: $ => seq($._cf_savecontent_body_css, $.cf_savecontent_content),
        cf_savecontent_body_xml: $ => seq($._cf_savecontent_body_xml, $.cf_savecontent_content),
        cf_savecontent_body_sql: $ => seq($._cf_savecontent_body_sql, $.cf_savecontent_content),
        cf_savecontent_body_raw: $ => seq($._cf_savecontent_body_raw, $.cf_savecontent_content),

        cf_function_tag: $ => prec.right(3, seq(
          $._cf_open_tag,
          $._start_cf_function_name,
          repeat($.cf_attribute),
          alias($._close_cf_tag_delim, '>'),
          repeat($._node),
          $._cf_close_tag,
          $._end_cf_function_name,
          alias($._close_cf_tag_delim, '>'),
        )),

        cf_component_open_tag: $ => prec.right(4, seq(
          $._cf_open_tag,
          $._start_cf_component_name,
          repeat($.cf_tag_attributes),
          $.cf_selfclose_void_tag_end,
        )),

        cf_component_close_tag: $ => seq(
          $._cf_close_tag,
          $._end_cf_component_name,
          alias($._close_cf_tag_delim, '>'),
        ),
      } : {}),

      cf_return_tag: $ => prec.right(3, seq(
        $._cf_open_tag,
        $._start_cf_return_name,
        optional($.expression),
        $.cf_selfclose_void_tag_end,
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

      _cf_tags: $ => prec.right(3, choice(
        $.cf_selfclose_tag,
        $.cf_if_tag,
        $.cf_set_tag,
        $.cf_tag,
        $.cf_return_tag,
        $.cf_output_tag,
        ...(dialect !== 'cfquery' ? [
          $.cf_query_tag,
          $.cf_xml_tag,
          $.cf_script_tag,
          $.cf_savecontent_tag,
          $.cf_function_tag,
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
              alias(/[^'#]+/, $.attribute_value),
            ),
          ),
          '\''),
        seq('"',
          repeat(
            choice(
              $._hash_always_eval,
              '""',
              alias(/[^"#]+/, $.attribute_value),
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
      ),

      expression_statement: ($) => seq(
        $._expressions,
        $._semicolon,
      ),

      variable_declaration: ($) => seq(
        choice($._kw_var, $._kw_final, seq($._kw_final, $._kw_var), seq($._kw_var, $._kw_final)),
        commaSep1($.variable_declarator),
        $._semicolon,
      ),

      variable_declarator: ($) => seq(
        // A scoped name is legal in CFML: `var local.result = …`, `var a.b.c = 1`.
        // `_reserved_identifier` has to be spelled out because allowing a
        // `member_expression` here makes keyword-led expressions valid straight
        // after `var`, so `var new = 1` would otherwise lex `new` as a keyword.
        field('name', choice(
          $.identifier,
          alias($._reserved_identifier, $.identifier),
          $.member_expression,
          $._destructuring_pattern,
        )),
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
              // `for ( var export in … )` — a keyword-shaped loop variable. `var`
              // now makes keywords valid here (see variable_declarator), so they
              // have to be accepted rather than lexed as keywords.
              $.identifier,
              alias($._reserved_identifier, $.identifier),
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
        field('operator', choice($._kw_in, 'of')),
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
        optional(field('handler', $.catch_clause)),
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
            // `catch( any var e )` — CommandBox's endpoints scope the caught
            // variable, which Lucee and ACF both accept.
            optional($._kw_var),
            field('parameter', choice($.identifier, $._destructuring_pattern)),
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

      // `[ : ]` and `[ = ]` are both empty ordered structs; Lucee accepts either.
      ordered_struct: ($) => prec(1, choice(seq('[', ':', ']'), seq('[', '=', ']'))),

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

      // NOTE: every `function` literal in this file deliberately stays plain
      // (case-sensitive), unlike the other statement keywords and unlike
      // cfscript. `function` is also a `parameter_type`, and via
      // `function_declaration` that puts cf tag expressions in a state where
      // the `token(prec(1, ...))` keyword form out-lexes a longer identifier —
      // `<cfset x = functionalImpact>` then parses as `function` + `alImpact`.
      // Covered by cfml/test/corpus/case_insensitivity.txt.
      function_expression: ($) => prec('literal', seq(
        $._kw_function,
        field('name', optional($.identifier)),
        $._call_signature,
        repeat($.assignment_expression),
        field('body', $.statement_block),
      )),

      access_type: ($) => choice(
        $._kw_public,
        $._kw_private,
        $._kw_package,
        $._kw_remote,
        $._kw_static,
        $._kw_final,
        $._kw_abstract,
      ),

      // `Component listener` — `component` lexes as a keyword here because
      // `_reserved_identifier` makes it valid at the start of a parameter, so it
      // never reaches `$.identifier` below.
      parameter_type: ($) => choice(
        $.path,
        $.identifier,
        alias($._kw_component, $.identifier),
      ),

      function_declaration: ($) => prec.right('declaration', seq(
        optional($.access_type),
        optional(choice($._kw_function, $.path, $.identifier)),
        $._kw_function,
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

      new_expression: ($) => prec.right('new', seq(
        $._kw_new,
        field('constructor', choice($.primary_expression, $.new_expression)),
        field('arguments', optional(prec.dynamic(1, $.arguments))),
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
        '[', field('index', choice($._expressions, $.slice_expression)), ']',
      )),

      // Lucee string / array slicing: `s[4:13]`, `s[4:13:2]`, `s[-10:-4]`.
      // Bounds are optional (`s[:5]`, `s[3:]`). This used to fall out of `pair`
      // being reachable inside a subscript through the expression conflicts;
      // spelling it out keeps slicing working without that ambiguity.
      slice_expression: ($) => prec.right(seq(
        optional(field('start', $.expression)),
        ':',
        optional(field('end', $.expression)),
        optional(seq(':', optional(field('step', $.expression)))),
      )),

      _lhs_expression: ($) => choice(
        $.string,
        $.member_expression,
        $.null,
        $.subscript_expression,
        $._identifier,
        alias($._reserved_identifier, $.identifier),
        // `function` is a legal attribute / argument name in script-syntax tag
        // calls (Lucee's `admin ... function="" ...`), so it has to be assignable.
        // It is deliberately not in `_reserved_identifier`: as a general expression
        // start it would make every binary operator valid straight after
        // `function`, and keyword extraction would then lex the name in
        // `function instanceOf( ... )` as the `instanceof` operator.
        alias($._kw_function, $.identifier),
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
          [/[dD][oO][eE][sS]\s+[nN][oO][tT]\s+[cC][oO][nN][tT][aA][iI][nN]/, 'binary_equality'],
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


      this: (_) => keyword('This'),
      super: (_) => keyword('Super'),
      // SQL uses TRUE/FALSE/NULL as ordinary identifiers inside <cfquery>, so
      // only the script dialects lex them as literals in any casing.
      true: (_) => dialect === 'cfquery' ? 'true' : keyword('True'),
      false: (_) => dialect === 'cfquery' ? 'false' : keyword('False'),
      null: (_) => dialect === 'cfquery' ? 'null' : keyword('Null'),
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
        alias($._hash_expression, $.hash_expression),
        alias($._hash_empty, $.hash_empty),
      ),

      _hash: ($) => '#',

      _hash_expression: ($) => seq(
        '#',
        $.expression,
        '#',
      ),

      _hash_empty: ($) => seq('#', token.immediate('#')),

      computed_property_name: ($) => seq(
        '[',
        $.expression,
        ']',
      ),

      _reserved_identifier: ($) => choice(
        // `new` is a legal variable name in CFML — `<cfset var new = "">`
        // (Mura's fileWriter.cfc). The cfscript grammar already lists it; the
        // tag grammar did not, so one such `<cfset>` cascaded into hundreds of
        // ERROR nodes for the rest of the file.
        $._kw_new,
        $._kw_get,
        $._kw_set,
        $._kw_static,
        $._kw_export,
        $._kw_let,
        $._kw_component,
        $._kw_public,
        $._kw_private,
        $._kw_package,
        $._kw_remote,
        $._kw_abstract,
        $._kw_final,
        // `function` is deliberately absent. Listing it here made `function` a
        // valid expression start, which in turn made every binary operator —
        // including `instanceof` — valid immediately after it. Keyword
        // extraction then lexed the name in `function instanceOf( ... )` as the
        // operator instead of an identifier. See test/probes/cfscript/
        // function_named_instanceof.cfc.
      ),

      _semicolon: ($) => choice($._automatic_semicolon, ';'),

      /*
        END SCRIPT BASED RULES
      */
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
      _kw_export: (_) => keyword('Export'),
      _kw_final: (_) => keyword('Final'),
      _kw_finally: (_) => keyword('Finally'),
      _kw_for: (_) => keyword('For'),
      _kw_function: (_) => keyword('Function'),
      _kw_get: (_) => keyword('Get'),
      _kw_if: (_) => keyword('If'),
      _kw_import: (_) => keyword('Import'),
      _kw_in: (_) => keyword('In'),
      _kw_instanceof: (_) => keyword('InstanceOf', 'instanceof'),
      _kw_let: (_) => keyword('Let'),
      _kw_new: (_) => keyword('New'),
      _kw_package: (_) => keyword('Package'),
      _kw_private: (_) => keyword('Private'),
      _kw_public: (_) => keyword('Public'),
      _kw_remote: (_) => keyword('Remote'),
      _kw_return: (_) => keyword('Return'),
      _kw_set: (_) => keyword('Set'),
      _kw_static: (_) => keyword('Static'),
      _kw_switch: (_) => keyword('Switch'),
      _kw_throw: (_) => keyword('Throw'),
      _kw_try: (_) => keyword('Try'),
      _kw_var: (_) => keyword('Var'),
      _kw_while: (_) => keyword('While'),
      _kw_with: (_) => keyword('With'),
      _kw_xml: ($) => keyword('Xml'),

    },
  });

  /**
   * CFML keywords are case-insensitive. Enumerate the accepted casings as plain
   * string literals and alias back to the canonical spelling, so node names and
   * `.scm` queries stay stable regardless of the casing in the source.
   *
   * String literals (not regexes) matter here: they stay eligible for
   * tree-sitter's keyword extraction, so `while_value` still lexes as one
   * identifier. A `token(prec(1, /[wW].../))` regex would out-lex the longer
   * identifier and split it.
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
