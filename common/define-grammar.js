/**
 * @file CFML grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const scriptMixin = require('./script-mixin');

// @ts-ignore
module.exports = function defineGrammar(dialect, extraRules) {
  const mixin = scriptMixin(dialect);

  const extra = extraRules ? extraRules() : {};

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
      $._start_tag_name,
      $._script_start_tag_name,
      $._style_start_tag_name,
      $._end_tag_name,
      $._start_cf_tag_name,
      $._end_cf_tag_name,
      $.erroneous_end_tag_name,
      $.erroneous_cf_end_tag_name,
      $.self_closing_tag_delimiter,
      $._cf_self_closing_tag_delimiter,
      $._cf_self_closing_void_tag_delimiter,
      $.implicit_end_tag,
      $.implicit_cf_end_tag,
      $.raw_text,
      $.cf_comment,
      $._close_tag_delim,
      $._close_cf_tag_delim,
      $.html_text,
      $._start_cf_void_name,
      $._start_cf_set_name,
      $._start_cf_return_name,
      $._start_cf_if_name,
      $._end_cf_if_name,
      $._start_cf_elseif_name,
      $._start_cf_else_name,

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

      ...(dialect === 'cfml' ? [$.cf_component_content] : []),
    ],

    supertypes: $ => [
      ...mixin.supertypes($),
      ...(dialect !== 'cfscript' ? [
        $._cf_tags,
      ] : []),
    ],

    inline: ($) => [
      ...mixin.inline($),
    ],

    precedences: ($) => [
      ...mixin.precedences($),
    ],

    conflicts: ($, previous) => previous.concat(
      mixin.conflicts($),
    ),

    rules: {

      program: $ => choice(
        repeat($._node),
        ...(dialect === 'cfml' ? [$.component_file] : []),
      ),

      ...mixin.rules,

      ...(dialect === 'cfml' ? {
        component_file: $ => $.cf_component_content,
      } : {}),

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

      cf_return_tag: $ => prec.right(3, seq(
        $._cf_open_tag,
        $._start_cf_return_name,
        optional($.expression),
        $.cf_selfclose_void_tag_end,
      )),

      // @ts-ignore
      text: $ => /[^<>&\s#\r\n\u2028\u2029]([^<>&#]*[^<>&\s#\r\n\u2028\u2029])?/,
      // cf_tag_close: $ => /<\/cf/i,

      _node: $ => choice(
        $._cf_tags,
        $._hash_dialect_eval,
        $.erroneous_end_tag,
        $.erroneous_cf_end_tag,
        $.text,
        $.doctype,
        $.entity,
        $.element,
        $.script_element,
        $.style_element,
        $.xml_decl,
        $.html_text,
      ),

      _cfoutput_node: $ => choice(
        $.doctype,
        $.entity,
        $.element,
        $._cf_tags,
        $._hash_always_eval,
        $.script_element,
        $.style_element,
        $.text,
        $.erroneous_end_tag,
        $.erroneous_cf_end_tag,
        $.xml_decl,
      ),

      _cf_open_tag: $ => prec.right(1, keyword('<cf')),
      _cf_close_tag: $ => prec.right(1, keyword('</cf')),

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

      cf_tag_attributes: $ => choice(
        // $.style_attribute,
        $.cf_attribute,
        $.quoted_cf_attribute_value,
        $._hash_always_eval,
      ),

      tag_attributes: $ => choice(
        // $.style_attribute,
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

      erroneous_cf_end_tag: $ => prec.right(1, seq(
        '</',
        $.erroneous_cf_end_tag_name,
        alias($._close_cf_tag_delim, '>'),
      )),

      style_element: $ => seq(
        alias($.style_start_tag, $.start_tag),
        optional($.raw_text),
        $.end_tag,
      ),

      // hash_single: $ => '#',

      // @ts-ignore
      hash_value: $ => /[a-zA-Z0-9_-]+/,

      _cf_tag_expression: $ => choice(
        $.expression,
        $._hash_always_eval,
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
        repeat($._cfoutput_node),
        $._cf_close_tag,
        $._end_cf_tag_name,
        alias($._close_cf_tag_delim, '>'),
      )),

      _cf_tags: $ => prec.right(3, choice(
        $.cf_selfclose_tag,
        $.cf_if_tag,
        $.cf_set_tag,
        $.cf_return_tag,
        $.cf_tag,
        $.cf_xml_tag,
        $.cf_query_tag,
        $.cf_script_tag,
        $.cf_savecontent_tag,
        $.cf_output_tag,
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


      entity: _ => /&(([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});/,

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

      ...(extra),
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
};
