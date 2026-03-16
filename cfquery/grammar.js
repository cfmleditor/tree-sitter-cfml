/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  OR: 1,
  AND: 2,
  NOT: 3,
  COMPARE: 4,
  ADD: 5,
  MULTIPLY: 6,
};

/** @type {Rule} */
const commaSep1 = (rule) => seq(rule, repeat(seq(',', rule)));

/** @type {Rule} */
const commaSep = (rule) => optional(commaSep1(rule));

/** @param {string} word */
const ci = (word) =>
  new RegExp(
    word
      .split('')
      .map((ch) => `[${ch.toLowerCase()}${ch.toUpperCase()}]`)
      .join(''),
  );

module.exports = grammar({
  name: 'cfquery',

  extras: ($) => [
    $.comment,
    // whitespace
    /[\s\uFEFF\u2028\u2029]+/,
  ],

  rules: {
    program: ($) => repeat($._statement),

    _statement: ($) =>
      choice(
        $.union_statement,
        $.select_statement,
        $.insert_statement,
        $.update_statement,
        $.delete_statement,
      ),

    //
    // Statements
    //

    select_statement: ($) =>
      seq(
        alias(ci('select'), $.keyword_select),
        optional(alias(ci('distinct'), $.keyword_distinct)),
        optional($.top_clause),
        field('columns', $.select_list),
        optional($.from_clause),
        optional($.where_clause),
        optional($.group_by_clause),
        optional($.order_by_clause),
        optional($.limit_clause),
      ),

    union_statement: ($) =>
      seq(
        $.select_statement,
        repeat1(
          seq(
            alias(ci('union'), $.keyword_union),
            optional(alias(ci('all'), $.keyword_all)),
            $.select_statement,
          ),
        ),
      ),

    top_clause: ($) =>
      seq(
        alias(ci('top'), $.keyword_top),
        choice($.number, $.parameter),
      ),

    select_list: ($) =>
      sep1(
        ',',
        choice(
          '*',
          field('column', $.expression),
          seq(field('column', $.expression), alias(ci('as'), $.keyword_as), field('alias', $.identifier)),
        ),
      ),

    from_clause: ($) =>
      seq(
        alias(ci('from'), $.keyword_from),
        field('tables', commaSep1($.table_reference)),
      ),

    table_reference: ($) =>
      seq(
        field('name', $.identifier),
        optional(
          seq(
            optional(alias(ci('as'), $.keyword_as)),
            field('alias', $.identifier),
          ),
        ),
        repeat($.join_clause),
      ),

    join_clause: ($) =>
      seq(
        field(
          'join_type',
          optional(
            choice(
              alias(ci('inner'), $.keyword_inner),
              alias(ci('left'), $.keyword_left),
              alias(ci('right'), $.keyword_right),
              alias(ci('full'), $.keyword_full),
            ),
          ),
        ),
        optional(alias(ci('outer'), $.keyword_outer)),
        alias(ci('join'), $.keyword_join),
        field('table', $.table_reference),
        alias(ci('on'), $.keyword_on),
        field('condition', $.expression),
      ),

    where_clause: ($) =>
      seq(alias(ci('where'), $.keyword_where), field('condition', $.expression)),

    group_by_clause: ($) =>
      seq(
        alias(seq(ci('group'), /\s+/, ci('by')), $.keyword_group_by),
        commaSep1($.expression),
        optional($.having_clause),
      ),

    having_clause: ($) =>
      seq(
        alias(ci('having'), $.keyword_having),
        $.expression,
      ),

    order_by_clause: ($) =>
      seq(
        alias(seq(ci('order'), /\s+/, ci('by')), $.keyword_order_by),
        commaSep1(
          seq(
            $.expression,
            optional(choice(alias(ci('asc'), $.keyword_asc), alias(ci('desc'), $.keyword_desc))),
          ),
        ),
      ),

    limit_clause: ($) =>
      seq(
        alias(ci('limit'), $.keyword_limit),
        choice($.number, $.parameter),
        optional(
          seq(
            alias(ci('offset'), $.keyword_offset),
            choice($.number, $.parameter),
          ),
        ),
      ),

    insert_statement: ($) =>
      seq(
        alias(ci('insert'), $.keyword_insert),
        alias(ci('into'), $.keyword_into),
        field('table', $.identifier),
        optional(field('columns', $.column_list)),
        alias(ci('values'), $.keyword_values),
        field('values', $.value_list),
      ),

    column_list: ($) => seq('(', commaSep1($.identifier), ')'),

    value_list: ($) => seq('(', commaSep1($.expression), ')'),

    update_statement: ($) =>
      seq(
        alias(ci('update'), $.keyword_update),
        field('table', $.identifier),
        alias(ci('set'), $.keyword_set),
        commaSep1($.assignment),
        optional($.where_clause),
      ),

    assignment: ($) =>
      seq(field('column', $.identifier), '=', field('value', $.expression)),

    delete_statement: ($) =>
      seq(
        alias(ci('delete'), $.keyword_delete),
        optional(seq(alias(ci('from'), $.keyword_from), field('table', $.identifier))),
        optional($.where_clause),
      ),

    //
    // Expressions
    //

    expression: ($) =>
      choice(
        $.exists_expression,
        $.case_expression,
        $.between_expression,
        $.in_expression,
        $.binary_expression,
        $.unary_expression,
        $.primary_expression,
      ),

    between_expression: ($) =>
      prec(
        PREC.COMPARE,
        seq(
          field('value', $.primary_expression),
          alias(ci('between'), $.keyword_between),
          field('lower', $.primary_expression),
          alias(ci('and'), $.keyword_and),
          field('upper', $.primary_expression),
        ),
      ),

    in_expression: ($) =>
      prec(
        PREC.COMPARE,
        seq(
          field('value', $.primary_expression),
          alias(ci('in'), $.keyword_in),
          field('set', $.in_list),
        ),
      ),

    in_list: ($) =>
      choice(
        seq('(', commaSep1($.expression), ')'),
        $.subquery,
      ),

    subquery: ($) => seq('(', $.select_statement, ')'),

    exists_expression: ($) =>
      prec(
        PREC.COMPARE,
        seq(
          alias(ci('exists'), $.keyword_exists),
          $.subquery,
        ),
      ),

    case_expression: ($) =>
      seq(
        alias(ci('case'), $.keyword_case),
        repeat1($.when_clause),
        optional($.else_clause),
        alias(ci('end'), $.keyword_end),
      ),

    when_clause: ($) =>
      seq(
        alias(ci('when'), $.keyword_when),
        field('condition', $.expression),
        alias(ci('then'), $.keyword_then),
        field('result', $.expression),
      ),

    else_clause: ($) =>
      seq(
        alias(ci('else'), $.keyword_else),
        field('result', $.expression),
      ),

    binary_expression: ($) =>
      choice(
        prec.left(
          PREC.OR,
          seq(field('left', $.expression), alias(ci('or'), $.keyword_or), field('right', $.expression)),
        ),
        prec.left(
          PREC.AND,
          seq(field('left', $.expression), alias(ci('and'), $.keyword_and), field('right', $.expression)),
        ),
        prec.left(
          PREC.COMPARE,
          seq(
            field('left', $.primary_expression),
            field(
              'operator',
              choice(
                '=',
                '<>',
                '<',
                '>',
                '<=',
                '>=',
                alias(ci('like'), $.keyword_like),
                alias(ci('ilike'), $.keyword_ilike),
              ),
            ),
            field('right', $.primary_expression),
          ),
        ),
        prec.left(
          PREC.ADD,
          seq(
            field('left', $.primary_expression),
            field('operator', choice('+', '-')),
            field('right', $.primary_expression),
          ),
        ),
        prec.left(
          PREC.MULTIPLY,
          seq(
            field('left', $.primary_expression),
            field('operator', choice('*', '/', alias(ci('mod'), $.keyword_mod))),
            field('right', $.primary_expression),
          ),
        ),
      ),

    unary_expression: ($) =>
      prec.right(
        PREC.NOT,
        seq(alias(ci('not'), $.keyword_not), field('operand', $.expression)),
      ),

    primary_expression: ($) =>
      choice(
        $.parenthesized_expression,
        $.function_call,
        $.qualified_identifier,
        $.identifier,
        $.number,
        $.string,
        $.parameter,
        $.hash_param,
      ),

    parenthesized_expression: ($) => seq('(', $.expression, ')'),

    parameter: ($) =>
      choice(
        '?',
        seq(':', $.identifier),
      ),

    hash_param: ($) => seq('#', $.cf_identifier_path, '#'),

    cf_identifier_path: ($) =>
      seq(
        $.identifier,
        repeat(
          choice(
            seq('.', $.identifier),
            seq('[', $.number, ']'),
          ),
        ),
      ),

    // Allow dotted identifiers like u.id or orders.total to
    // appear as a single identifier node in expressions.
    qualified_identifier: ($) =>
      alias(
        seq($.identifier, repeat1(seq('.', $.identifier))),
        $.identifier,
      ),

    // Treat function calls like sum(o.total) as a single
    // identifier-like primary expression for the purposes
    // of this dialect, so they can appear naturally in
    // HAVING, SELECT lists, etc.
    function_call: ($) =>
      alias(
        seq($.identifier, '(', commaSep($.expression), ')'),
        $.identifier,
      ),

    //
    // Terminals
    //

    identifier: (_) =>
      token(
        /[A-Za-z_][A-Za-z0-9_$]*/,
      ),

    number: (_) =>
      token(
        /[0-9]+(\.[0-9]+)?/,
      ),

    string: (_) =>
      token(
        choice(
          /'([^']|'')*'/,
          /"([^"]|"")*"/,
        ),
      ),

    comment: (_) =>
      token(
        choice(
          seq('--', /[^\r\n]*/),
          seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'),
        ),
      ),
  },
});

function sep1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)));
}

