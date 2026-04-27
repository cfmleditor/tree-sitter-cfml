/**
 * @file CFSCRIPT grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const scriptMixin = require('../common/script-mixin');

// @ts-ignore
const mixin = scriptMixin(commaSep1, commaSep, 'cfscript', keyword);

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

  supertypes: ($) => [
    ...mixin.supertypes($),
  ],

  inline: ($) => [
    ...mixin.inline($),
  ],

  precedences: ($) => [
    ...mixin.precedences($),
  ],

  conflicts: ($) => [
    ...mixin.conflicts($),
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
          $.comment
        )
      ),
      choice(
        $.component,
        repeat($.statement)
      ),
    ),

    ...mixin.rules,

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
