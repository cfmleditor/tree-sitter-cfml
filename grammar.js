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
    $.comment,
    ';',
    /\s+/,
  ],

  externals: $ => [
    $._start_tag_name,
    $._script_start_tag_name,
    $._style_start_tag_name,
    $._end_tag_name,
    $.erroneous_end_tag_name,
    '/>',
    $._implicit_end_tag,
    $.raw_text,
    $.comment,
  ],

  conflicts: $ => [
    [$.cf_dblquotes_empty, $.cf_dblquotes],
    [$.cf_singlequotes_empty, $.cf_singlequotes],
    [$.cf_bracket_expression, $.cf_function_call],
    [$.cf_return, $.cf_function_call],
    [$._node, $.cf_function],
    [$.text, $.cf_variable],
    [$.cf_associative, $.cf_function_call],
    [$._cf_expression, $.cf_function_call],
  ],

  rules: {

    fragment: $ => repeat($._node),

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

    _cf_tag_start: $ => /<cf/i,
    cf_tag_end: $ => '>',
    cf_tag_selfclose_end: $ => seq(optional('/'),'>'),
    text: _ => /[^\s<>}{\(\)#\[\]=,."\'`;&]+/,
    cf_variable: _ => /[^\s<>}{\(\)#\[\]=,."\'`;&]+/,
    cf_tag_close: $ => /<\/cf/i,
    cf_true: $ => token('true'),
    cf_false: $ => token('false'),
    
    cf_operator: $ => choice(
        token('AND'),
        token('OR'),
        token('EQ'),
        token('GTE'),
        token('LTE'),
        token('IS'),
        token('GT'),
        token('==='),
    ),
    
    cf_prefix_operator: $ => token('NOT'),

    _node: $ => choice(
      $.doctype,
      $.entity,
      $.text,
      $.element,
      $.cf_tag,
      $.cf_hash,
      $.cf_function,
      $.script_element,
      $.style_element,
      $._cf_assignment_expression,
    ),

    element: $ => choice(
      seq(
        $.start_tag,
        repeat($._node),
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

    cf_hash: $ => seq(
      '#',
      $._cf_expression,
      '#',
    ),

    cf_associative: $ => seq(
      '[',
      optional($._cf_expression),
      ']',
    ),
    
    cf_bracket_function: $ => seq(
      '{',
      repeat($._cf_function_statement),
      '}',
    ),

    cf_bracket_expression: $ => seq(
      '{',
      repeat($._cf_expression),
      '}',
    ),

    _cf_function_statement: $ => choice(
      // Maybe nested functions in the future ?? $.cf_function, 
      $.expression_statement,
      $.cf_return,
    ),

    expression_statement: $ => seq(
      $._cf_expression,
      $._semicolon,
    ),

    _cf_assignment_expression: $ => prec.right(3,seq(
      $.cf_variable,
      $.cf_assignment,
      $._cf_expression,
    )),
    
    _cf_expression: $ => choice(
      $._cf_member_expression,
      prec.right(1,$.cf_hash),
      prec.right(2,$.cf_function),
      prec.right(2,seq(optional($._cf_expression),$.cf_period,$._cf_expression)),
      prec.right(2,seq($._cf_expression,$.cf_objectkeyassign,$._cf_expression)),
      prec.right(4,seq($.cf_period,$._cf_expression)),
      prec.right(4,seq($.cf_comma,$._cf_expression)),
      prec.right(5,seq($.cf_prefix_operator,$._cf_expression)),
      prec.right(5,seq($._cf_expression,$.cf_operator,$._cf_expression)),
      prec.right(6,seq($.cf_function_call,optional($._cf_expression))),
      prec.right(6,$.cf_expression_parens),
      prec.right(6,$.cf_true),
      prec.right(6,$.cf_false),
    ),

    _cf_member_expression: $ => choice(
      $._cf_assignment_expression,
      prec.right(1,$.cf_dblquotes),
      prec.right(2,$.cf_dblquotes_empty),
      prec.right(1,$.cf_singlequotes),
      prec.right(2,$.cf_singlequotes_empty),
      prec.right(2,seq(optional($._cf_expression),$.cf_associative)),
      prec.right(6,$.cf_bracket_expression),
      prec.right(6,$.cf_variable),
    ),

    cf_component_tag: $ => seq(
      $.cf_component_keyword,
      repeat($.cf_attribute),
      $.cf_tag_end,
      repeat($._node),
      $.cf_tag_close,
      $.cf_component_keyword,
      $.cf_tag_end,
    ),

    cf_function: $ => seq(
      optional(alias($.cf_variable,$.cf_function_access)),
      optional($.cf_function_returntype),
      $.cf_function_keyword,
      optional($.cf_function_name),
      $.cf_function_arguments,
      $.cf_bracket_function,
    ),

    cf_return: $ => seq(
      $.cf_return_keyword,
      $._cf_expression,
    ),

    cf_function_call: $ => seq(
      $._cf_member_expression,
      $.cf_function_call_arguments
    ),

    cf_period: $ => /\./,
    cf_comma: $ => ',',
    cf_assignment: $ => '=',
    cf_objectkeyassign: $ => ':',

    cf_singlequotes: $ => seq(
      "'",
      alias(
        repeat(
          choice(
            /[^"]/,
            $.cf_hash,
          ),
        ),
        $.quoted_text,
      ),
      "'",
    ),

    cf_singlequotes_empty: $ => seq(
      "'",
      "'",
    ),

    cf_dblquotes: $ => seq(
      '"',
      alias(
        repeat(
          choice(
            /[^"]/,
            $.cf_hash,
          ),
        ),
        $.quoted_text,
      ),
      '"',
    ),

    cf_dblquotes_empty: $ => seq(
      '"',
      '"',
    ),

    cf_function_call_arguments: $ => seq(
      '(',
      repeat(
          seq(
            $._cf_expression,
            optional($.cf_comma),
          ),
      ),
      ')',
    ),

    cf_expression_parens: $ => seq(
      '(',
      optional($._cf_expression),
      ')',
    ),

    cf_function_name: $ => choice(
      $.cf_variable,
    ),

    cf_function_returntype: $ => choice(
      token('boolean'),
    ),

    cf_function_argument_required: $ => choice(
      token('required'),
    ),

    cf_function_argument_type: $ => choice(
      token('any'),
    ),

    cf_function_argument_name: $ => choice(
      $.cf_variable,
    ),

    cf_function_arguments: $ => seq(
      '(',
        repeat(seq(
          optional($.cf_function_argument_required),
          optional($.cf_function_argument_type),
          $.cf_function_argument_name,
          optional(seq(
            '=',
            $._cf_expression,
          )),
          optional(',')
        )),
      ')',
    ),

    cf_function_tag: $ => seq(
      $.cf_function_keyword,
      repeat($.cf_attribute),
      $.cf_tag_end,
      repeat($._node),
      $.cf_tag_close,
      $.cf_function_keyword,
      $.cf_tag_end,
    ),

    cf_argument_tag: $ => seq(
      $.cf_argument_keyword,
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_return_tag: $ => seq(
      $.cf_return_keyword,
      $._cf_expression,
      $.cf_tag_selfclose_end,
    ),

    cf_ifstatement: $ => seq(
      $.cf_if,
      repeat($.cf_elseif),
      optional($.cf_else),
      $.cf_if_end,
    ),

    cf_if: $ => prec.right(1, seq(
      $.cf_if_keyword,
      $._cf_expression,
      optional($.cf_tag_end),
      repeat($._node),
    )),

    cf_set: $ => prec.right(1, seq(
      token('set'),
      optional($.cf_var),
      $._cf_expression,
      $.cf_tag_selfclose_end
    )),

    cf_elseif: $ => prec.right(2, seq(
      optional($._cf_tag_start),
      $.cf_elseif_keyword,
      $.cf_condition,
      optional($.cf_tag_end),
      repeat($._node),
    )),

    cf_else: $ => prec.right(3, seq(
      optional($._cf_tag_start),
      $.cf_else_keyword,
      optional($.cf_tag_end),
      repeat($._node),
    )),

    cf_if_end: $ => seq(
      choice(seq($.cf_tag_close, $.cf_if_keyword, '>'), '}'),
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
        choice(
          $._cf_expression,
        ),
      )),
    ),

    cf_attribute_name: _ => /[^<>"\'/=\s]+/,

    //attribute_value: _ => /[^<>"'=\s]+/,

    cf_tag: $ => seq(
      $._cf_tag_start,
      choice(
        $.cf_component_tag,
        $.cf_function_tag,
        $.cf_argument_tag,
        $.cf_return_tag,
        $.cf_ifstatement,
        $.cf_set
      ),
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

    cf_var: $ => token('var'),
    cf_if_keyword: $ => token('if'),
    cf_elseif_keyword: $ => token('elseif'),
    cf_else_keyword: $ => token('else'),
    cf_function_keyword: $ => token('function'),
    cf_component_keyword: $ => token('component'),
    cf_argument_keyword: $ => token('argument'),
    cf_return_keyword: $ => token('return'),
    _semicolon: $ => ';',
  },
});
