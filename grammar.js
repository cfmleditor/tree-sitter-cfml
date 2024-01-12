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
    /\s+/,
  ],

  externals: $ => [

  ],

  conflicts: $ => [
    [$.cf_dblquotes_empty, $.cf_dblquotes],
  ],

  rules: {

    fragment: $ => repeat($._node),

    cf_condition: ($) => choice(
        /([^<>\[\]="\']+)/,
    ),

    _cf_tag_start: $ => /<cf/i,
    cf_tag_end: $ => /\/?>/,
    text: _ => /[^\s<>}{\(\)#\[\]=,."\']+/,
    cf_variable: _ => /[^\s<>}{\(\)#\[\]=,."\']+/,
    cf_tag_close: $ => /<\/cf/i,
    cf_operator: $ => /(\sAND\s|\sOR\s|\sEQ\s|\sGTE\s|\sGT\s|\sNOT\s|===)/i,

    _node: $ => choice(
      $.text,
      $._cf_statement,
    ),

    cf_hash: $ => seq(
      '#',
      $._cf_expression,
      '#',
    ),

    cf_associative: $ => seq(
      '[',
      $._cf_expression,
      ']',
    ),

    _cf_expression: $ => choice(
      prec.right(1,seq($.cf_dblquotes)),
      prec.right(2,seq($.cf_dblquotes_empty)),
      prec.right(2,seq($._cf_expression,$.cf_parens)),
      prec.right(2,seq($._cf_expression,$.cf_parens_empty)),
      prec.right(2,seq($._cf_expression,$.cf_associative)),
      prec.right(2,seq($._cf_expression,$.cf_assignment,$._cf_expression)),
      prec.right(3,seq($._cf_expression,$.cf_period,$._cf_expression)),
      prec.right(4,seq($._cf_expression,$.cf_comma,$._cf_expression)),
      prec.right(5,seq($._cf_expression,$.cf_operator,$._cf_expression)),
      
      prec.right(6,$.cf_variable),
    ),

    cf_period: $ => /\./,
    cf_comma: $ => ',',
    cf_assignment: $ => '=',

      
    cf_dblquotes: $ => seq(
      '"',
      $._cf_expression,
      '"',
    ),

    cf_dblquotes_empty: $ => seq(
      '"',
      '"',
    ),


    cf_parens: $ => seq(
      '(',
      $._cf_expression,
      ')',
    ),

    cf_parens_empty: $ => seq(
      '(',
      ')',
    ),

    cf_function: $ => seq(
      $.cf_function_keyword,
      repeat($.attribute),
      $.cf_tag_end,
      repeat($._node),
      $.cf_tag_close,
      $.cf_function_keyword,
      $.cf_tag_end,
    ),

    cf_argument: $ => seq(
      $.cf_argument_keyword,
      repeat($.attribute),
      $.cf_tag_end,
    ),

    cf_return: $ => seq(
      $.cf_return_keyword,
      repeat($.attribute),
      $.cf_tag_end,
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
      'set',
      optional($.cf_var),
      $._cf_expression,
      $.cf_tag_end
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
          $._cf_expression,
        ),
      )),
    ),

    attribute_name: _ => /[^<>"\'/=\s]+/,

    //attribute_value: _ => /[^<>"'=\s]+/,

    cf_tag: $ => seq(
      $._cf_tag_start,
      choice(
        $.cf_function,
        $.cf_argument,
        $.cf_return,
        $.cf_ifstatement,
        $.cf_set
      ),
    ),

    _cf_statement: $ => choice(
      prec.right(1,$.cf_dblquotes),
      prec.right(2,$.cf_dblquotes_empty),
      prec.right(2,$.cf_tag),
      prec.right(2,$.cf_hash),
      prec.right(3,$.cf_parens),
      prec.right(4,$.cf_associative),
    ),

    cf_var: $ => /(\svar\s)+/i,
    cf_if_keyword: $ => /(if)+/i,
    cf_elseif_keyword: $ => /(elseif)+/i,
    cf_else_keyword: $ => /(else)+/i,
    cf_function_keyword: $ => /(function)+/i,
    cf_argument_keyword: $ => /(argument)+/i,
    cf_return_keyword: $ => /(return)+/i,

  },
});
