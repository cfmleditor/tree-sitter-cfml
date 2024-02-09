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
    $.cf_comment,
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
    $.cf_comment,
  ],

  conflicts: $ => [
    [$.cf_dblquotes_empty, $.cf_dblquotes],
    [$.cf_singlequotes_empty, $.cf_singlequotes],
    [$.cf_bracket_expression, $.cf_function_call],
    [$.cf_return, $.cf_function_call],
    //[$._node, $.cf_function],
    [$.cf_variable, $.text],
    [$.cf_associative, $.cf_function_call],
    [$._cf_expression, $.cf_function_call],
    [$.cf_script_expression, $._cf_member_expression],
    [$.cf_zip_tag, $.cf_zip_tag_standalone],
    [$.cf_transaction_tag, $.cf_transaction_tag_standalone],
    [$.cf_ternary, $.cf_objectkeyassign],
    [$.cf_function_access, $.cf_function_returntype],
    [$.cf_function_argument_name, $.cf_function_argument_type],
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

    cf_tag_start: $ => '<',
    _cf_tag_end: $ => '>',
    cf_tag_selfclose_end: $ => choice('/>',$._cf_tag_end),
    text: $ => /[^<>&\s]([^<>&]*[^<>&\s])?/,
    cf_variable: $ => /[^\s<>}{\(\)#\[\]=,."\'`;&\/\\]+/,
    cf_tag_close: $ => /<\/cf/i,
    cf_true: $ => keyword('true'),
    cf_false: $ => keyword('false'),
    
    cf_operator: $ => choice(
      keyword('and'),
      keyword('or'),
      keyword('eq'),
      keyword('neq'),
      keyword('gte'),
      keyword('lte'),
      keyword('lt'),
      keyword('is'),
      keyword('gt'),
      keyword('>='),
      keyword('==='),
      keyword('+'),
      keyword('*'),
      keyword('/'),
      keyword('-'),
      keyword('=='),
      keyword('<='),
      keyword('&&'),
      keyword('||'),
    ),
    
    cf_prefix_operator: $ => choice(
      keyword('NOT'),
      '!',
    ),

    _node: $ => choice(
      $.doctype,
      $.entity,
      $.element,
      $._cf_tag,
      $.cf_hash,
      $.cf_hash_empty,
      $.script_element,
      $.style_element,
      $.cf_script,
      $.text,
    ),

    cf_script: $ => seq(
      keyword('<cfscript>'),
      repeat(
        $.cf_script_expression,
      ),
      keyword('</cfscript>'),
    ),  

    cf_script_expression: $ => choice(
      $.cf_script_comment,
      $.cf_function,
      seq($._cf_expression,optional(';')),
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

    cf_hash: $ => prec.right(2,seq(
      '#',
      $._cf_expression,
      '#',
    )),

    cf_hash_empty: $ => prec.right(1,seq(
      token('##'),
    )),

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

    _cf_assignment_expression: $ => prec.right(1,seq(
      $._cf_expression,
      $.cf_assignment,
      $._cf_expression,
    )),

    cf_concat: $ => seq(
       '&',
    ),
    
    _cf_expression: $ => choice(
      $._cf_member_expression,
      prec.right(1,$.cf_hash),
      prec.right(2,$.cf_function),
      prec.right(2,$.cf_switch_statement),
      prec.right(2,$.cf_if_statement),
      prec.right(2,seq(optional($._cf_expression),$.cf_period,$._cf_expression)),
      prec.right(2,seq(optional($._cf_expression),$.cf_concat,$._cf_expression)),
      prec.right(2,seq($._cf_expression,$.cf_objectkeyassign,$._cf_expression)),
      prec.right(4,seq($.cf_period,$._cf_expression)),
      prec.right(4,seq($.cf_comma,$._cf_expression)),
      prec.right(5,seq($.cf_prefix_operator,$._cf_expression)),
      prec.right(5,seq($._cf_expression,$.cf_operator,$._cf_expression)),
      prec.right(6,$.cf_function_call),
      prec.right(6,seq(optional($._cf_expression),$.cf_ternary)),
      prec.right(6,$.cf_expression_parens),
      prec.right(6,$.cf_true),
      prec.right(6,$.cf_false),
    ),

    cf_switch_statement: $ => seq(
      $.cf_switch,
      repeat(seq(
        $.cf_case,
        optional($._cf_expression),
        optional($.cf_break),
      )),
      optional(
        seq(
          keyword('defaultcase:'),
          optional($._cf_expression),
        ),
      ),
      keyword('}'),
    ),  

    cf_switch: $ => seq(
      keyword('switch'),
      $.cf_expression_parens,
      keyword('{'),
    ),

    cf_if_statement: $ => seq(
      $.cf_if,
      repeat($.cf_script_expression),
      token('}'),
      repeat($.cf_elseif),
      optional(
        $.cf_else,
      ),
    ),

    cf_if: $ => seq(
       keyword('if'),
       $.cf_expression_parens,
       '{',
    ),

    cf_for_statement: $ => seq(
      keyword('for'),
      $.cf_expression_parens,
      '{',
      repeat($.cf_script_expression),
      '}',
   ),

    cf_elseif: $ => seq(
      keyword('else if'),
      $.cf_expression_parens,
      '{',
      repeat($.cf_script_expression),
      '}',
    ),

    cf_else: $ => seq(
      keyword('else'),
      '{',
      repeat($.cf_script_expression),
      '}',
    ),

    cf_case: $ => seq(
      keyword('case'),
      $._cf_expression,
      keyword(':')
    ),

    cf_break: $ => seq(
      keyword('break'),
      optional(';'),
    ),

    _cf_member_expression: $ => choice(
      $._cf_assignment_expression,
      prec.right(1,$.cf_dblquotes),
      prec.right(1,$.cf_variable),
      prec.right(2,$.cf_dblquotes_empty),
      prec.right(1,$.cf_singlequotes),
      prec.right(2,$.cf_singlequotes_empty),
      prec.right(2,seq(optional($._cf_expression),$.cf_associative)),
      prec.right(6,$.cf_bracket_expression),
    ),

    cf_component_tag: $ => seq(
      keyword('<cfcomponent'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cfcomponent>'),
    ),

    cf_function: $ => seq(
      optional($.cf_function_access),
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
      '\'',
      alias(
        repeat(
          choice(
            alias(/[^'#]+/,$.text),
            $.cf_hash,
            $.cf_hash_empty,
          ),
        ),
        $.quoted_text,
      ),
      '\'',
    ),

    cf_singlequotes_empty: $ => seq(
      '\'',
      '\'',
    ),

    cf_dblquotes: $ => seq(
      '"',
      alias(
        repeat(
          choice(
            /[^"]/,
            $.cf_hash,
            $.cf_hash_empty
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
      repeat($._cf_expression),
      ')',
    ),

    cf_ternary: $ => seq(
      keyword('?'),
      $._cf_expression,
      keyword(':'),
      $._cf_expression,
    ),

    cf_function_name: $ => choice(
      $.cf_variable,
    ),

    cf_function_access: $ => choice(
      $.cf_variable,
    ),

    cf_function_returntype: $ => choice(
      $.cf_variable,
    ),

    cf_function_argument_required: $ => choice(
      keyword('required'),
    ),

    cf_function_argument_type: $ => choice(
      $.cf_variable,
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
      keyword('<cffunction'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cffunction>'),
    ),

    cf_query_tag: $ => seq(
      keyword('<cfquery'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cfquery>'),
    ),

    cf_transaction_tag_standalone: $ => prec.right(1,seq(
      keyword('<cftransaction'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    )),

    cf_transaction_tag: $ => prec.right(2,seq(
      keyword('<cftransaction'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cftransaction>'),
    )),

    cf_try_statement_tag: $ => seq(
      $.cf_try_tag,
      $.cf_catch_tag,
      keyword('</cftry>'),
    ),

    cf_try_tag: $ => seq(
      keyword('<cftry'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
    ),

    cf_switch_statement_tag: $ => seq(
      $.cf_switch_tag,
      repeat($.cf_case_tag),
      optional($.cf_defaultcase_tag),
      keyword('</cfswitch>'),
    ),

    cf_switch_tag: $ => seq(
      keyword('<cfswitch'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
    ),

    cf_wddx_tag: $ => seq(
      keyword('<cfwddx'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_case_tag: $ => seq(
      keyword('<cfcase'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cfcase>'),
    ),

    cf_defaultcase_tag: $ => seq(
      keyword('<cfdefaultcase'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cfdefaultcase>'),
    ),

    cf_catch_tag: $ => seq(
      keyword('<cfcatch'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cfcatch>'),
    ),

    cf_loop_tag: $ => seq(
      keyword('<cfloop'),
      repeat($.cf_attribute),
      $._cf_tag_end,
      repeat($._node),
      keyword('</cfloop>'),
    ),

    cf_argument_tag: $ => seq(
      keyword('<cfargument'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_file_tag: $ => seq(
      keyword('<cffile'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_throw_tag: $ => seq(
      keyword('<cfthrow'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_image_tag: $ => seq(
      keyword('<cfimage'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_directory_tag: $ => seq(
      keyword('<cfdirectory'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_include_tag: $ => seq(
      keyword('<cfinclude'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_continue_tag: $ => seq(
      keyword('<cfcontinue'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_zip_tag: $ => seq(
      keyword('<cfzip'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
      repeat($._node),
      keyword('</cfzip>'),
    ),

    cf_zip_tag_standalone: $ => seq(
      keyword('<cfzip'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_savecontent_tag: $ => seq(
      keyword('<cfsavecontent'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
      repeat($._node),
      keyword('</cfsavecontent>'),
    ),

    cf_output_tag: $ => seq(
      keyword('<cfoutput'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
      repeat($._node),
      keyword('</cfoutput>'),
    ),

    cf_rethrow_tag: $ => seq(
      keyword('<cfrethrow'),
      repeat($.cf_attribute),
      $.cf_tag_selfclose_end,
    ),

    cf_break_tag: $ => seq(
      keyword('<cfbreak'),
      $.cf_tag_selfclose_end,
    ),

    cf_return_tag: $ => seq(
      keyword('<cfreturn'),
      $._cf_expression,
      $.cf_tag_selfclose_end,
    ),

    cf_if_statement_tag: $ => seq(
      $.cf_if_tag,
      repeat($.cf_elseif_tag),
      optional($.cf_else_tag),
      $.cf_if_end_tag,
    ),

    cf_if_tag: $ => seq(
      keyword('<cfif'),
      repeat($._cf_expression),
      $._cf_tag_end,
      repeat($._node),
    ),

    cf_set_tag: $ => seq(
      keyword('<cfset'),
      optional($.cf_var),
      $._cf_expression,
      $.cf_tag_selfclose_end
    ),

    cf_elseif_tag: $ => seq(
      keyword('<cfelseif'),
      repeat($._cf_expression),
      $._cf_tag_end,
      repeat($._node),
    ),

    cf_else_tag: $ => seq(
      keyword('<cfelse'),
      $._cf_tag_end,
      repeat($._node),
    ),

    cf_if_end_tag: $ => seq(
      keyword('</cfif>'),
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

    _cf_tag: $ => choice(
      $.cf_if_statement_tag,
      $.cf_try_statement_tag,
      $.cf_switch_statement_tag,
      $.cf_transaction_tag,
      $.cf_transaction_tag_standalone,
      $.cf_set_tag,
      $.cf_file_tag,
      $.cf_throw_tag,
      $.cf_image_tag,
      $.cf_include_tag,
      $.cf_continue_tag,
      $.cf_directory_tag,
      $.cf_savecontent_tag,
      $.cf_output_tag,
      $.cf_zip_tag,
      $.cf_zip_tag_standalone,
      $.cf_rethrow_tag,
      $.cf_wddx_tag,
      alias($.cf_component_tag,$.cf_component),
      alias($.cf_function_tag,$.cf_function),
      alias($.cf_query_tag,$.cf_query),
      alias($.cf_argument_tag,$.cf_argument),
      alias($.cf_loop_tag,$.cf_loop),
      alias($.cf_break_tag,$.cf_break),
      alias($.cf_return_tag,$.cf_return),
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

    cf_var: $ => keyword('var'),
    cf_if_keyword: $ => keyword('if'),
    cf_elseif_keyword: $ => keyword('elseif'),
    cf_else_keyword: $ => keyword('else'),
    cf_function_keyword: $ => keyword('function'),
    cf_component_keyword: $ => keyword('component'),
    cf_argument_keyword: $ => keyword('argument'),
    cf_return_keyword: $ => keyword('return'),
    _semicolon: $ => ';',

    cf_script_comment: $ => choice(
      token(choice(
        seq('//', /.*/),
        seq(
          '/*',
          /[^*]*\*+([^/*][^*]*\*+)*/,
          '/',
        ),
      )),
    ),
  },
});



function keyword(word) {
  //return word // when debuging
  return alias(reserved(caseInsensitive(word)), word)
}

function reserved(regex) {
  return token(prec(1, new RegExp(regex)))
}

function caseInsensitive(word) {
  return word.split('')
      .map(letter => `[${letter}${letter.toUpperCase()}]`)
      .join('')
}
