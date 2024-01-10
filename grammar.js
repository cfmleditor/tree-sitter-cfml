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

  rules: {

    fragment: $ => repeat($._node),
    cf_condition: ($) => /([^<>]+)/,
    cf_tag_start: $ => /<cf/i,
    cf_tag_end: $ => />/,
    text: _ => /[^\s<>}{()]/,
    cf_tag_close: $ => /<\/cf/i,

    _node: $ => choice(
      $.text,
      seq(
        optional($.cf_tag_start),
        $.cf_statement,
      ),
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

    cf_ifstatement: $ => seq(
      $.cf_if,
      repeat($.cf_elseif),
      optional($.cf_else),
      $.cf_if_end,
    ),

    cf_if: $ => prec.right(1, seq(
      $.cf_if_keyword,
      $.cf_condition,
      optional($.cf_tag_end),
      repeat($._node),
    )),

    cf_elseif: $ => prec.right(2, seq(
      optional($.cf_tag_start),
      $.cf_elseif_keyword,
      $.cf_condition,
      optional($.cf_tag_end),
      repeat($._node),
    )),

    cf_else: $ => prec.right(3, seq(
      optional($.cf_tag_start),
      $.cf_else_keyword,
      optional($.cf_tag_end),
      repeat($._node),
    )),

    cf_if_end: $ => seq(
      choice(seq($.cf_tag_close, $.cf_if_keyword, '>'), '}'),
    ),

    quoted_attribute_value: $ => choice(
      seq('\'', optional(alias(/[^']+/, $.attribute_value)), '\''),
      seq('"', optional(alias(/[^"]+/, $.attribute_value)), '"'),
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

    cf_statement: $ => choice(
      $.cf_function,
      $.cf_ifstatement,
    ),

    cf_if_keyword: $ => /(if)+/i,
    cf_elseif_keyword: $ => /(elseif)+/i,
    cf_else_keyword: $ => /(else)+/i,
    cf_function_keyword: $ => /(function)+/i,

  },
});
