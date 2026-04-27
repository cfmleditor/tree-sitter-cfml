/**
 * @file CFML cfquery SQL dialect grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-nocheck

const defineGrammar = require('../common/define-grammar');

const SQL_PREC = {
  OR: 1,
  AND: 2,
  NOT: 3,
  COMPARE: 4,
  ADD: 5,
  MULTIPLY: 6,
};

/**
 * Case-insensitive regex for a word.
 *
 * @param {string} word
 */
function ci(word) {
  return new RegExp(
    word.split('').map((ch) => `[${ch.toLowerCase()}${ch.toUpperCase()}]`).join(''),
  );
}

/**
 * Reserved SQL keyword — case-insensitive, always wins over identifier.
 *
 * @param {string} word
 */
function kw(word) {
  return token(prec(1, ci(word)));
}

module.exports = defineGrammar('cfquery', () => ({
  program: $ => repeat($._node),

  _node: $ => choice(
    $._cf_tags,
    $._hash_always_eval,
    $.erroneous_cf_end_tag,
    $.cfquery_segment,
  ),

  query_operator: $ => choice(
    field('operator', '>='),
    field('operator', '>'),
    field('operator', '<='),
    field('operator', '<'),
    field('operator', '<>'),
    field('operator', 'IN'),
    field('operator', '='),
    field('operator', 'BETWEEN'),
    field('operator', 'EXISTS'),
  ),

  _cfquery_sql_statement: $ => choice(
    $.cfquery_union_statement,
    $.cfquery_select_statement,
    $.cfquery_insert_statement,
    $.cfquery_update_statement,
    $.cfquery_delete_statement,
    $.cfquery_truncate_statement,
    $.cfquery_merge_statement,
    $.cfquery_exec_statement,
    $.cfquery_clause,
  ),

  cfquery_select_core: $ =>
    seq(
      alias(kw('select'), $.keyword_select),
      optional(alias(kw('distinct'), $.keyword_distinct)),
      optional($.cfquery_top_clause),
      field('columns', $.cfquery_select_list),
      optional($.cfquery_from_clause),
      optional($.cfquery_clause),
      optional($.cfquery_group_by_clause),
      optional($.cfquery_window_clause),
      optional($.cfquery_order_by_clause),
      optional($.cfquery_offset_fetch_clause),
      optional($.cfquery_limit_clause),
      optional($.cfquery_for_update_clause),
    ),

  cfquery_offset_fetch_clause: $ =>
    seq(
      alias(kw('offset'), $.keyword_offset),
      choice($.number, $.parameter),
      optional(alias(kw('rows'), $.keyword_rows)),
      alias(kw('fetch'), $.keyword_fetch),
      alias(kw('next'), $.keyword_next),
      choice($.number, $.parameter),
      optional(alias(kw('rows'), $.keyword_rows)),
      alias(kw('only'), $.keyword_only),
    ),

  cfquery_select_statement: $ =>
    seq(
      optional($.cfquery_with_clause),
      $.cfquery_select_core,
    ),

  cfquery_union_statement: $ =>
    seq(
      optional($.cfquery_with_clause),
      $.cfquery_select_core,
      repeat1(
        seq(
          alias(kw('union'), $.keyword_union),
          optional(alias(kw('all'), $.keyword_all)),
          $.cfquery_select_core,
        ),
      ),
    ),

  cfquery_with_clause: $ =>
    seq(
      alias(kw('with'), $.keyword_with),
      $.cfquery_cte_list,
    ),

  cfquery_cte_list: $ =>
    seq(
      field('first', $.cfquery_cte),
      repeat(seq(',', field('rest', $.cfquery_cte))),
    ),

  cfquery_cte: $ =>
    seq(
      field('name', $.identifier),
      optional($.cfquery_column_list),
      alias(kw('as'), $.keyword_as),
      '(',
      field('query', $.cfquery_cte_query),
      ')',
    ),

  cfquery_cte_query: $ =>
    choice(
      $.cfquery_cte_union_inner,
      $.cfquery_select_core,
    ),

  cfquery_cte_union_inner: $ =>
    seq(
      $.cfquery_select_core,
      repeat1(
        seq(
          alias(kw('union'), $.keyword_union),
          optional(alias(kw('all'), $.keyword_all)),
          $.cfquery_select_core,
        ),
      ),
    ),

  cfquery_truncate_statement: $ =>
    seq(
      alias(kw('truncate'), $.keyword_truncate),
      alias(kw('table'), $.keyword_table),
      field('table', choice($.identifier, $.cfquery_bracket_identifier)),
    ),

  cfquery_merge_statement: $ =>
    seq(
      alias(kw('merge'), $.keyword_merge),
      alias(kw('into'), $.keyword_into),
      field('target', $.cfquery_table_reference),
      alias(kw('using'), $.keyword_using),
      field('source', $.cfquery_table_reference),
      alias(kw('on'), $.keyword_on),
      field('condition', $.cfquery_expression),
      alias(kw('when'), $.keyword_when),
      alias(kw('matched'), $.keyword_matched),
      alias(kw('then'), $.keyword_then),
      alias(kw('update'), $.keyword_update),
      alias(kw('set'), $.keyword_set),
      $.cfquery_assignment_list,
      optional(
        seq(
          alias(kw('when'), $.keyword_when),
          alias(kw('not'), $.keyword_not),
          alias(kw('matched'), $.keyword_matched),
          alias(kw('then'), $.keyword_then),
          alias(kw('insert'), $.keyword_insert),
          field('columns', $.cfquery_column_list),
          alias(kw('values'), $.keyword_values),
          field('values', $.cfquery_value_list),
        ),
      ),
    ),

  cfquery_exec_statement: $ =>
    seq(
      choice(
        alias(kw('exec'), $.keyword_exec),
        alias(kw('execute'), $.keyword_execute),
        alias(kw('call'), $.keyword_call),
      ),
      field('name', $.cfquery_qualified_name),
      optional(
        seq(
          '(',
          optional($.cfquery_function_call_args),
          ')',
        ),
      ),
    ),

  cfquery_top_clause: $ =>
    seq(
      alias(kw('top'), $.keyword_top),
      choice($.number, $.parameter),
    ),

  cfquery_star: _ => '*',

  cfquery_select_item: $ =>
    choice(
      $.cfquery_star,
      field('expression', $.cfquery_expression),
      seq(
        field('expression', $.cfquery_expression),
        alias(kw('as'), $.keyword_as),
        field('alias', $.identifier),
      ),
    ),

  cfquery_select_list: $ =>
    seq(
      field('first', $.cfquery_select_item),
      repeat(seq(',', field('rest', $.cfquery_select_item))),
    ),

  cfquery_from_clause: $ =>
    seq(
      alias(kw('from'), $.keyword_from),
      field('tables', $.cfquery_from_table_list),
    ),

  cfquery_from_table_list: $ =>
    seq(
      field('first', $.cfquery_table_reference),
      repeat(seq(',', field('rest', $.cfquery_table_reference))),
    ),

  cfquery_table_reference: $ =>
    seq(
      field('name', choice($.identifier, $.cfquery_bracket_identifier)),
      optional(
        prec.dynamic(-1, seq(
          optional(alias(kw('as'), $.keyword_as)),
          field('alias', $.identifier),
        )),
      ),
      repeat($.cfquery_join_clause),
      optional($.cfquery_pivot_clause),
      optional($.cfquery_unpivot_clause),
    ),

  cfquery_pivot_clause: $ =>
    seq(
      alias(kw('pivot'), $.keyword_pivot),
      '(',
      field('aggregate', $.cfquery_expression),
      alias(kw('for'), $.keyword_for),
      field('pivot_column', $.identifier),
      alias(kw('in'), $.keyword_in),
      '(',
      $.cfquery_in_list_body,
      ')',
      ')',
      optional(alias(kw('as'), $.keyword_as)),
      field('alias', $.identifier),
    ),

  cfquery_unpivot_clause: $ =>
    seq(
      alias(kw('unpivot'), $.keyword_unpivot),
      '(',
      field('value', $.cfquery_expression),
      alias(kw('for'), $.keyword_for),
      field('name', $.identifier),
      alias(kw('in'), $.keyword_in),
      '(',
      $.cfquery_in_list_body,
      ')',
      ')',
      optional(alias(kw('as'), $.keyword_as)),
      field('alias', $.identifier),
    ),

  cfquery_join_clause: $ =>
    seq(
      field(
        'join_type',
        optional(
          choice(
            alias(kw('inner'), $.keyword_inner),
            alias(kw('left'), $.keyword_left),
            alias(kw('right'), $.keyword_right),
            alias(kw('full'), $.keyword_full),
          ),
        ),
      ),
      optional(alias(kw('outer'), $.keyword_outer)),
      alias(kw('join'), $.keyword_join),
      field('table', $.cfquery_table_reference),
      alias(kw('on'), $.keyword_on),
      field('condition', $.cfquery_expression),
    ),

  cfquery_clause: $ =>
    seq(
      choice(
        alias(kw('where'), $.keyword_where),
        alias(kw('and'), $.keyword_and),
        alias($._hash_always_eval, $.keyword_and),
      ),
      field('condition', $.cfquery_expression),
    ),

  cfquery_group_by_clause: $ =>
    seq(
      alias(token(prec(1, seq(ci('group'), /\s+/, ci('by')))), $.keyword_group_by),
      $.cfquery_group_by_expression_list,
      optional($.cfquery_having_clause),
    ),

  cfquery_group_by_expression_list: $ =>
    seq(
      field('first', $.cfquery_expression),
      repeat(seq(',', field('rest', $.cfquery_expression))),
    ),

  cfquery_having_clause: $ =>
    seq(
      alias(kw('having'), $.keyword_having),
      $.cfquery_expression,
    ),

  cfquery_order_by_clause: $ =>
    seq(
      alias(token(prec(1, seq(ci('order'), /\s+/, ci('by')))), $.keyword_order_by),
      $.cfquery_order_by_expression_list,
    ),

  cfquery_order_by_expression_list: $ =>
    seq(
      field('first', $.cfquery_order_by_expression),
      repeat(seq(',', field('rest', $.cfquery_order_by_expression))),
    ),

  cfquery_order_by_expression: $ =>
    seq(
      $.cfquery_expression,
      optional(choice(alias(kw('asc'), $.keyword_asc), alias(kw('desc'), $.keyword_desc))),
    ),

  cfquery_window_clause: $ =>
    seq(
      alias(kw('window'), $.keyword_window),
      $.cfquery_window_definition_list,
    ),

  cfquery_window_definition_list: $ =>
    seq(
      field('first', $.cfquery_window_definition),
      repeat(seq(',', field('rest', $.cfquery_window_definition))),
    ),

  cfquery_window_definition: $ =>
    seq(
      field('name', $.identifier),
      alias(kw('as'), $.keyword_as),
      '(',
      optional(
        seq(
          alias(token(prec(1, seq(ci('partition'), /\s+/, ci('by')))), $.keyword_partition_by),
          $.cfquery_group_by_expression_list,
        ),
      ),
      optional($.cfquery_order_by_clause),
      ')',
    ),

  cfquery_limit_clause: $ =>
    seq(
      alias(kw('limit'), $.keyword_limit),
      choice($.number, $.parameter),
      optional(
        seq(
          alias(kw('offset'), $.keyword_offset),
          choice($.number, $.parameter),
        ),
      ),
    ),

  cfquery_for_update_clause: $ =>
    seq(
      alias(kw('for'), $.keyword_for),
      alias(kw('update'), $.keyword_update),
      optional(
        seq(
          alias(kw('of'), $.keyword_of),
          choice($.cfquery_column_list, $.identifier),
        ),
      ),
      optional(
        seq(
          alias(kw('skip'), $.keyword_skip),
          alias(kw('locked'), $.keyword_locked),
        ),
      ),
    ),

  cfquery_insert_statement: $ =>
    seq(
      alias(kw('insert'), $.keyword_insert),
      alias(kw('into'), $.keyword_into),
      field('table', choice($.identifier, $.cfquery_bracket_identifier)),
      optional(field('columns', $.cfquery_column_list)),
      alias(kw('values'), $.keyword_values),
      field('values', $.cfquery_value_list),
    ),

  cfquery_column_list: $ => seq('(', $.cfquery_column_list_body, ')'),

  cfquery_column_list_body: $ =>
    seq(
      field('first', $.identifier),
      repeat(seq(',', field('rest', $.identifier))),
    ),

  cfquery_value_list: $ => seq('(', $.cfquery_value_list_body, ')'),

  cfquery_value_list_body: $ =>
    seq(
      field('first', $.cfquery_expression),
      repeat(seq(',', field('rest', $.cfquery_expression))),
    ),

  cfquery_update_statement: $ =>
    seq(
      alias(kw('update'), $.keyword_update),
      field('table', choice($.identifier, $.cfquery_bracket_identifier)),
      alias(kw('set'), $.keyword_set),
      $.cfquery_assignment_list,
      optional($.cfquery_clause),
    ),

  cfquery_assignment_list: $ =>
    seq(
      field('first', $.cfquery_assignment),
      repeat(seq(',', field('rest', $.cfquery_assignment))),
    ),

  cfquery_assignment: $ =>
    seq(field('column', $.identifier), '=', field('value', $.cfquery_expression)),

  cfquery_delete_statement: $ =>
    seq(
      alias(kw('delete'), $.keyword_delete),
      optional(
        seq(
          alias(kw('from'), $.keyword_from),
          field('table', choice($.identifier, $.cfquery_bracket_identifier)),
        ),
      ),
      optional($.cfquery_clause),
    ),

  cfquery_expression: $ =>
    choice(
      $.cfquery_exists_expression,
      $.cfquery_case_expression,
      $.cfquery_is_null_expression,
      $.cfquery_between_expression,
      $.cfquery_in_expression,
      $.cfquery_binary_expression,
      $.cfquery_unary_expression,
      $.cfquery_primary_expression,
    ),

  cfquery_is_null_expression: $ =>
    prec(
      SQL_PREC.COMPARE,
      seq(
        field('value', $.cfquery_primary_expression),
        alias(kw('is'), $.keyword_is),
        choice(
          alias(kw('null'), $.keyword_null),
          seq(
            alias(kw('not'), $.keyword_not),
            alias(kw('null'), $.keyword_null),
          ),
        ),
      ),
    ),

  cfquery_between_expression: $ =>
    prec(
      SQL_PREC.COMPARE,
      seq(
        field('value', $.cfquery_primary_expression),
        alias(kw('between'), $.keyword_between),
        field('lower', $.cfquery_primary_expression),
        alias(kw('and'), $.keyword_and),
        field('upper', $.cfquery_primary_expression),
      ),
    ),

  cfquery_in_expression: $ =>
    prec(
      SQL_PREC.COMPARE,
      seq(
        field('value', $.cfquery_primary_expression),
        alias(kw('in'), $.keyword_in),
        field('set', $.cfquery_in_list),
      ),
    ),

  cfquery_in_list: $ =>
    choice(
      seq('(', $.cfquery_in_list_body, ')'),
      $.cfquery_subquery,
    ),

  cfquery_in_list_body: $ =>
    seq(
      field('first', $.cfquery_expression),
      repeat(seq(',', field('rest', $.cfquery_expression))),
    ),

  cfquery_subquery: $ => seq('(', $.cfquery_select_statement, ')'),

  cfquery_exists_expression: $ =>
    prec(
      SQL_PREC.COMPARE,
      seq(
        alias(kw('exists'), $.keyword_exists),
        $.cfquery_subquery,
      ),
    ),

  cfquery_case_expression: $ =>
    seq(
      alias(kw('case'), $.keyword_case),
      repeat1($.cfquery_when_clause),
      optional($.cfquery_else_clause),
      alias(kw('end'), $.keyword_end),
    ),

  cfquery_when_clause: $ =>
    seq(
      alias(kw('when'), $.keyword_when),
      field('condition', $.cfquery_expression),
      alias(kw('then'), $.keyword_then),
      field('result', $.cfquery_expression),
    ),

  cfquery_else_clause: $ =>
    seq(
      alias(kw('else'), $.keyword_else),
      field('result', $.cfquery_expression),
    ),

  cfquery_binary_expression: $ =>
    choice(
      prec.left(
        SQL_PREC.OR,
        seq(field('left', $.cfquery_expression), alias(kw('or'), $.keyword_or), field('right', $.cfquery_expression)),
      ),
      prec.left(
        SQL_PREC.AND,
        seq(field('left', $.cfquery_expression), alias(kw('and'), $.keyword_and), field('right', $.cfquery_expression)),
      ),
      prec.left(
        SQL_PREC.COMPARE,
        seq(
          field('left', $.cfquery_primary_expression),
          field(
            'operator',
            choice(
              '=',
              '<>',
              '<',
              '>',
              '<=',
              '>=',
              alias(kw('like'), $.keyword_like),
              alias(kw('ilike'), $.keyword_ilike),
            ),
          ),
          field('right', $.cfquery_primary_expression),
        ),
      ),
      prec.left(
        SQL_PREC.ADD,
        seq(
          field('left', $.cfquery_primary_expression),
          field('operator', choice('+', '-')),
          field('right', $.cfquery_primary_expression),
        ),
      ),
      prec.left(
        SQL_PREC.MULTIPLY,
        seq(
          field('left', $.cfquery_primary_expression),
          field('operator', choice('*', '/', alias(kw('mod'), $.keyword_mod))),
          field('right', $.cfquery_primary_expression),
        ),
      ),
    ),

  cfquery_unary_expression: $ =>
    prec.right(
      SQL_PREC.NOT,
      seq(alias(kw('not'), $.keyword_not), field('operand', $.cfquery_expression)),
    ),

  cfquery_primary_expression: $ =>
    choice(
      $.cf_selfclose_tag,
      $.cf_if_tag,
      $.cf_set_tag,
      $.cf_tag,
      $.cfquery_cast_expression,
      $.cfquery_parenthesized_expression,
      $.cfquery_window_invocation,
      $.cfquery_function_call,
      $.cfquery_qualified_name,
      $.cfquery_bracket_identifier,
      $.cfquery_boolean_literal,
      $.cfquery_double_quoted_identifier,
      $.cfquery_single_quoted_string,
      $.identifier,
      $.number,
      $.parameter,
      $.hash_param,
    ),

  cfquery_boolean_literal: $ =>
    choice(
      alias(kw('true'), $.keyword_true),
      alias(kw('false'), $.keyword_false),
      alias(kw('unknown'), $.keyword_unknown),
    ),

  cfquery_double_quoted_identifier: $ =>
    seq(
      '"',
      field(
        'name',
        alias(
          repeat1(choice(token.immediate(/[^"]/), '""')),
          $.identifier,
        ),
      ),
      '"',
    ),

  cfquery_single_quoted_string: $ =>
    seq(
      '\'',
      repeat(choice(
        '\'\'',
        alias($.unescaped_single_string_fragment, $.string_fragment),
        $._hash_always_eval,
      )),
      '\'',
    ),

  cfquery_cast_expression: $ =>
    seq(
      alias(kw('cast'), $.keyword_cast),
      '(',
      field('value', $.cfquery_expression),
      alias(kw('as'), $.keyword_as),
      field('type', $.cfquery_type_name),
      ')',
    ),

  cfquery_type_name: $ =>
    choice(
      $.identifier,
      seq($.identifier, '(', optional($.number), ')'),
      seq($.identifier, '(', $.number, ',', $.number, ')'),
    ),

  cfquery_bracket_identifier: $ =>
    seq(
      '[',
      field('name', alias(token(/[^\]]+/), $.identifier)),
      ']',
    ),

  cfquery_parenthesized_expression: $ => seq('(', $.cfquery_expression, ')'),

  parameter: $ =>
    choice(
      '?',
      seq(':', $.identifier),
    ),

  hash_param: $ => seq('#', $.cf_identifier_path, '#'),

  cf_identifier_path: $ =>
    seq(
      $.identifier,
      repeat(
        choice(
          seq('.', $.identifier),
          seq('[', choice($.number, $.identifier), ']'),
        ),
      ),
    ),

  cfquery_qualified_name: $ =>
    seq(
      field('first', choice($.identifier, $._hash_always_eval)),
      repeat1(seq('.', field('rest', choice($.identifier, $._hash_always_eval)))),
    ),

  cfquery_window_invocation: $ =>
    seq(
      field('function', $.identifier),
      '(',
      optional($.cfquery_function_call_args),
      ')',
      alias(kw('over'), $.keyword_over),
      '(',
      optional(
        seq(
          alias(token(prec(1, seq(ci('partition'), /\s+/, ci('by')))), $.keyword_partition_by),
          $.cfquery_group_by_expression_list,
        ),
      ),
      optional($.cfquery_order_by_clause),
      ')',
    ),

  cfquery_function_call: $ =>
    seq(
      field('function', $.identifier),
      '(',
      optional($.cfquery_function_call_args),
      ')',
    ),

  cfquery_function_call_args: $ =>
    seq(
      field('first', choice($.cfquery_expression, '*')),
      repeat(seq(',', field('rest', choice($.cfquery_expression, '*')))),
    ),

  cfquery_segment: $ =>
    prec.right(
      0,
      seq(
        $._cfquery_sql_statement,
        repeat(seq(';', $._cfquery_sql_statement)),
        optional(';'),
      ),
    ),
}));
