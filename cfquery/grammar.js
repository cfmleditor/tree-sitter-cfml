/**
 * @file CFML cfquery SQL dialect grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-nocheck

const defineGrammar = require('../common/define-grammar');

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

module.exports = defineGrammar('cfquery', () => ({
  program: $ => repeat($._node),

  _node: $ => choice(
    $.erroneous_cf_end_tag,
    $.comment,
    $._query_node,
  ),

  parenthesized_query_node: ($) => seq(
    '(',
    repeat($._query_node),
    ')',
  ),

  _query_node: ($) => choice(
    $._query_keyword,
    $.query_identifier,
    $.quoted_query_value,
    $.double_quoted_query_value,
    $.bracketed_query_value,
    $.query_star,
    $.query_alias,
    $.query_assignment_expression,
    $.parenthesized_query_node,
    $._hash_always_eval,
    $._cf_tags,
    $.query_number,
    $.null,
    $.query_comma,
    $.query_semicolon,
  ),

  query_alias: ($) => prec.right('assign', seq(
    field('left', $._query_node),
    '.',
    field('right', $._query_node),
  )),

  query_comma: ($) => /[,]/,

  query_semicolon: ($) => /[;]/,

  query_assignment_expression: ($) => prec.right('assign', seq(
    field('left', $._query_node),
    '=',
    field('right', $._query_node),
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
    const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#.,*\[\]|^&"'<=>+,#\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
    return choice(
      token(seq(':', alphanumeric, repeat(alphanumeric))),
      token(seq(alphanumeric, repeat(alphanumeric))),
      alias(/\?/, $.placeholder),
    );
  },

  _query_keyword: $ => choice(
    keyword('select'),
    keyword('and'),
    keyword('where'),
    keyword('from'),
    keyword('group'),
    keyword('order'),
    keyword('by'),
    keyword('having'),
    keyword('limit'),
    keyword('offset'),
    keyword('insert'),
    keyword('into'),
    keyword('values'),
    keyword('update'),
    keyword('set'),
    keyword('delete'),
    keyword('join'),
    keyword('inner'),
    keyword('outer'),
    keyword('left'),
    keyword('right'),
    keyword('on'),
    keyword('as'),
    keyword('distinct'),
    keyword('null'),
    keyword('not'),
    keyword('in'),
    keyword('like'),
    keyword('between'),
    keyword('exists'),
    keyword('true'),
    keyword('false'),
    keyword('create'),
    keyword('table'),
    keyword('drop'),
    keyword('alter'),
    keyword('add'),
    keyword('column'),
    keyword('primary'),
    keyword('key'),
    keyword('foreign'),
    keyword('references'),
    keyword('constraint'),
    keyword('unique'),
    keyword('check'),
    keyword('default'),
    keyword('auto_increment'),
    keyword('varchar'),
    keyword('int'),
    keyword('date'),
    keyword('datetime'),
    keyword('decimal'),
    keyword('boolean'),
    keyword('char'),
    keyword('text'),
    keyword('blob'),
    keyword('tinyint'),
    keyword('smallint'),
    keyword('mediumint'),
    keyword('bigint'),
    keyword('float'),
    keyword('double'),
    keyword('real'),
    keyword('timestamp'),
    keyword('time'),
    keyword('year'),
    keyword('enum'),
    keyword('set'),
    keyword('unsigned'),
    keyword('zerofill'),
    keyword('collate'),
    keyword('engine'),
    keyword('charset'),
    keyword('comment'),
    keyword('index'),
    keyword('fulltext'),
    keyword('spatial'),
    keyword('keyblocksize'),
    keyword('max_rows'),
    keyword('min_rows'),
    keyword('pack_keys'),
    keyword('row_format'),
    keyword('data_directory'),
    keyword('index_directory'),
    keyword('insert_method'),
    keyword('partition'),
    keyword('partitions'),
    keyword('subpartition'),
    keyword('subpartitions'),
    keyword('less'),
    keyword('than'),
    keyword('each'),
    keyword('hour'),
    keyword('day'),
    keyword('month'),
    keyword('year'),
    keyword('week'),
    keyword('minute'),
    keyword('second'),
    keyword('microsecond'),
    keyword('interval'),
  ),

}));
