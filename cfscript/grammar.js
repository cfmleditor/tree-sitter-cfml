/**
 * @file CFSCRIPT grammar for tree-sitter
 * @author Gareth Edwards, Gavin Baumanis
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

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
    $.cfml_template_content,
    $.cf_comment,
    $.java_class_content,
    $._java_block_open,
  ],

  extras: ($) => [
    $.comment,
    // @ts-ignore
    /[\s\p{Zs}\uFEFF\u2028\u2029\u2060\u200B]/,
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
    $._kw_final,
    $._kw_finally,
    $._kw_for,
    $._kw_function,
    $._kw_if,
    $._kw_import,
    $._kw_in,
    $._kw_include,
    $._kw_instanceof,
    $._kw_interface,
    $._kw_new,
    $._kw_of,
    $._kw_package,
    $._kw_private,
    $._kw_property,
    $._kw_public,
    $._kw_remote,
    $._kw_return,
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
    ],
    ['assign', $.primary_expression],
    ['member', 'new', 'call', $.expression],
    ['declaration', 'literal'],
    [$.primary_expression, $.statement_block, 'object'],
  ],

  conflicts: ($) => [
    [$.object, $.object_pattern],
    [$.primary_expression, $.pattern],
    [$.assignment_expression, $.pattern],
    [$.function_expression, $.function_declaration],
    [$.expression, $.function_expression, $.function_declaration],
    [$.primary_expression, $.path],
    // `public(`, `private(` … — an access modifier starting a member
    // declaration looks exactly like a call until the parser sees what follows.
    // `final X` / `public X` — a member declaration and a function declaration
    // (`final query function f()`) share their prefix.
    [$.primary_expression, $.variable_declaration],
    [$.variable_declaration, $.access_type],
    [$.variable_declaration, $.primary_expression, $._property_name],
    [$.primary_expression, $.parameter_type],
    [$.primary_expression, $.parameter_type, $.pattern],
    [$.parameter_type, $.pattern],
    // `( function ( ... ` is either a parameter typed `Function` or an
    // anonymous function used as a parameter default.
    [$.function_expression, $.parameter_type],
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
    [$.method_definition, $.access_type],
    // `pair` (expression ':' expression) is reachable from `arguments` and
    // `array`, so `case <expr> :` is ambiguous with the start of a pair.
    [$.switch_case, $.expression],
    [$.primary_expression, $.new_expression],
    [$.primary_expression, $.query_tag],
    [$._for_header, $.primary_expression, $.new_expression],
    [$.primary_expression, $.new_expression, $.rest_pattern],
    [$.new_expression, $.pattern],
    [$.primary_expression, $.new_expression, $.pattern],
    [$.primary_expression, $.new_expression, $._property_name],
    [$.function_expression, $.pattern],
    [$.function_expression, $.parameter_type, $.pattern],
    [$._property_name, $.primary_expression, $.query_tag],
    [$.primary_expression, $.query_expression],
    [$._property_name, $.primary_expression, $.query_expression],
    [$.arguments, $.parenthesized_expression],
    [$.expression, $.parenthesized_expression],
    [$.expression, $.expression_statement],

    [$.expression, $.arguments],
    [$.expression, $.assignment_expression],
    [$.expression, $.return_statement],
    [$.expression, $.throw_statement],
    [$.assignment_expression, $._property_name],
    [$.object_assignment_pattern, $._property_name],
    [$.object_assignment_pattern, $.assignment_expression, $._property_name],
    [$.call_expression, $._property_name],
    [$._for_header, $.expression],
    [$.expression, $.for_statement],
    [$.parenthesized_expression, $.expression, $.arguments],
    [$.expression, $.template_substitution],

    // `component (` is ambiguous: the parenthesised attribute list of a
    // `component` declaration, or a call of the reserved identifier
    // `component`. Only what follows the `)` settles it — a `{` means the
    // declaration — so the two readings have to be carried until then.
    // Unlike the `[$.primary_expression, $.call_expression]` conflict the cost
    // table warns about, whose prefix is `identifier (` and so live at every
    // call in the language, this one's prefix is the `Component` *keyword*
    // followed by `(`, which occurs only where that word is actually called.
    // Benchmarked: cfscript 12880 ms before, 12800 ms after, inside a 5.4%
    // run-to-run spread.
    // `f( name : … ` is ambiguous between a `pair` in ordinary `arguments` and
    // a colon-separated `tag_call_attribute`. Only what follows settles it — a
    // comma keeps the pair reading, a space-separated second attribute makes it
    // a tag call — so both have to be carried. Narrower than it looks: the
    // prefix is `identifier ( identifier :`, so the two stacks are live only at
    // a call whose first named argument uses a colon, not at every call.
    // Benchmarked below.
    [$._property_name, $.tag_call_attribute],
    [$.component, $._property_name],
    [$.component, $.primary_expression],
    [$.component, $.primary_expression, $._property_name],
    [$.primary_expression, $.tag_statement],
    [$.expression, $.tag_statement],
    [$.tag_statement, $.expression],
    [$.program, $.statement],
    // The heart of it: at `f( a •= ` the parser cannot tell a tag-call
    // attribute from an ordinary named argument. It only finds out on reaching
    // the value, and on whether a second `name=` follows.
    [$.assignment_expression, $.tag_call_attribute, $.pattern],
    // `cfdirectory( … )` at statement position: `identifier (` could start a
    // tag call, an ordinary call, or a tag statement. Confined to statement
    // position, so unlike the previous formulation it is not live at every
    // call site in the language.
    [$.primary_expression, $._tag_call, $.tag_statement],
    // The same decision at the start of a `{`, where a struct-literal key is
    // also possible.
    [$.primary_expression, $._tag_call, $._property_name, $.tag_statement],
    [$.sequence_expression, $.arguments],
    [$.component_attribute, $.property_declaration],
    [$.parameter_attribute, $.assignment_expression, $.pattern],
    [$.primary_expression, $.parameter_attribute],
  ],

  word: ($) => $.identifier,

  rules: {

    program: ($) => seq(
      repeat(
        choice(
          $.import_statement,
          $.tag_statement,
          $.comment,
        ),
      ),
      choice(
        $.component,
        // `static_initializer` is reachable at the top level as well as inside
        // `component_body`, because that is what an injected region can be.
        // `injections.scm` hands the body of a tag-based component's
        // `<cfscript>` island to this grammar as a bare region, and that region
        // is a *component body* rather than a statement list — so a file that
        // is perfectly valid CFML reported an error inside an editor using the
        // injection queries. `property` already parsed here; `static { … }` was
        // the one component-level construct that did not.
        repeat(choice($.statement, $.static_initializer)),
      ),
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
      // `<!--- … --->` between statements. Deliberately a statement rather than
      // an extra: as an extra it also matched inside a string, so
      // `reReplace( src, "<!---.*?--->", "" )` grew a comment node.
      $.cf_comment,
      alias($.tag_call_statement, $.expression_statement),
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
      $.colon_assignment_statement,
      $.include_statement,

      $.cfml_template,
      $.tag_statement,
      $.query_tag,
      $.component,
    ),

    expression_statement: ($) => seq(
      $._expressions,
      $._semicolon,
    ),

    // `var x = 1`, and the Lucee member forms `final MEMBER = "value"` and
    // `public prop = "prop"` inside a component body.
    variable_declaration: ($) => choice(
      seq(
        choice(
          $._kw_var,
          $._kw_final,
          seq($._kw_final, $._kw_var),
          seq($._kw_var, $._kw_final),
        ),
        commaSep1($.variable_declarator),
        $._semicolon,
      ),
      // `public prop = "prop"`. Access modifiers only — `static` and `abstract`
      // are excluded because `static { … }` and `abstract component { … }` claim
      // those words. The negative dynamic precedence keeps
      // `private component function f()` a function declaration: there the
      // modifier is followed by a return type, not a variable name.
      prec.dynamic(-1, seq(
        alias(choice($._kw_public, $._kw_private, $._kw_package, $._kw_remote), $.access_type),
        // `public final MEMBER = "v";` — the two modifiers combine. `final`
        // alone is the first branch above, and an access modifier alone is this
        // one; only the pair had no reading. It stays after the access modifier
        // because that is the order Lucee writes, and keeping it here rather
        // than in the `choice` above avoids making `final` reachable twice.
        optional(alias($._kw_final, $.access_type)),
        commaSep1(alias($._plain_declarator, $.variable_declarator)),
        $._semicolon,
      )),
    ),

    // A member declaration's name is a plain identifier — no keywords and no
    // scoped name. Accepting keywords here would make `component` after
    // `public` lex as a keyword, and `public component function f()` is a
    // function declaration with a return type, not a member.
    _plain_declarator: ($) => seq(
      // `default` has to be spelled out. Admitting it as a function modifier
      // (`public default any function f()`) makes `_kw_default` valid straight
      // after an access modifier, so it lexes as a keyword here too and
      // `public default = 1;` — an ordinary member named `default` — stopped
      // parsing. Same shape as the `_reserved_identifier` entries elsewhere:
      // a keyword made valid in a new position has to keep its identifier
      // reading in every rule that shared the position.
      field('name', choice($.identifier, alias($._kw_default, $.identifier))),
      optional($._initializer),
    ),

    variable_declarator: ($) => seq(
      // A scoped name is legal in CFML: `var local.result = …`, `var a.b.c = 1`.
      // `_reserved_identifier` has to be spelled out because allowing a
      // `member_expression` here makes keyword-led expressions valid straight
      // after `var`, so `var new = 1` would otherwise lex `new` as a keyword.
      // `var mappings[ key ] = value` is the same idea one step further —
      // declare and index in one statement. Kept next to `member_expression`
      // because CFML treats `a.b` and `a["b"]` as the same access.
      field('name', choice(
        $.identifier,
        alias($._reserved_identifier, $.identifier),
        $.member_expression,
        $.subscript_expression,
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
            // `for ( var local.package in items )` — the scoped name that
            // `variable_declarator` has accepted for `var local.x = 1` since
            // it was widened. This header never got the same widening, so a
            // dotted loop variable parsed without `var` and a plain one parsed
            // with it, and only the combination failed. The
            // `_reserved_identifier` line above is the guard that widening
            // needed, and it is already here.
            $.member_expression,
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
      field('operator', choice($._kw_in, $._kw_of)),
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
      // `try x = nonExistantVariable; catch( any e ){ … }` — Lucee accepts a
      // single unbraced statement as the body. The unbraced alternative is an
      // `expression_statement` rather than a general `$.statement`, which is
      // what the construct needs and is also the only spelling that generates:
      // a `statement_block` *is* reachable as a `$.statement`, so the general
      // form makes the braced body match both alternatives and `try { } { }`
      // ambiguous over which brace pair is the body. A precedence on the
      // `statement_block` arm does not settle that — the competing reduction is
      // `statement_block` → `statement`, outside this rule — and the only other
      // resolutions offered touch `statement` itself, which is live at every
      // statement in the language.
      field('body', choice($.statement_block, $.expression_statement)),
      repeat(field('handler', $.catch_clause)),
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

    // `prec`, not a declared conflict: with `debugger` now a reserved
    // identifier, `debugger;` parses both as this statement and as a bare
    // expression. The statement is the right reading and precedence settles
    // it at generation time, where a conflict would carry two GLR stacks
    // every time the word appears.
    debugger_statement: ($) => prec(1, seq(
      $._kw_debugger,
      $._semicolon,
    )),

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
      choice(
        prec.dynamic(1, $.arguments),
        // `throw message="x" type="y";` — the bodyless tag-statement spelling,
        // which every other tag reaches through `tag_statement`. `throw` cannot:
        // it has this dedicated rule, and `_kw_throw` out-lexes the identifier
        // that `tag_statement` needs in its `tag` slot, so the attribute form
        // had no reading at all. Spelled with `parameter_attribute` exactly as
        // `include_statement` above already spells the same shape — a single
        // `assignment_expression` would not do, because what fails is the
        // *space*-separated pair rather than the first attribute.
        repeat1($.parameter_attribute),
        $._expressions,
      ),
      $._semicolon,
    ),

    include_statement: ($) => prec(1, seq(
      $._kw_include,
      choice(
        seq(repeat1($.parameter_attribute), $._semicolon),
        seq($._expressions, $._semicolon),
      ),
    )),

    empty_statement: (_) => ';',

    // `msSQL.class: 'net.sourceforge.jtds.jdbc.Driver';` — Lucee accepts `:`
    // in place of `=` for an assignment, and Application.cfc files mix the two
    // in adjacent lines. Only the *dotted* form is spelled here: a bare
    // `foo: bar;` is already a `labeled_statement`, and changing that reading
    // would rewrite existing trees for a construct this issue is not about.
    // A `member_expression` can never be a label, so the two cannot collide.
    colon_assignment_statement: ($) => seq(
      field('left', $.member_expression),
      ':',
      field('right', $.expression),
      $._semicolon,
    ),

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
          field('parameter', choice($.identifier, $.nested_identifier, $._destructuring_pattern)),
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
      $.query_expression,
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
      $.template_string,
      $.regex,
      $.true,
      $.false,
      $.null,
      $.object,
      $.array,
      $.ordered_struct,
      $.java_class_block,
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

    component: ($) => prec('literal', seq(
      // One modifier only. The shared scanner skips a *run* of them when it
      // decides a file is a component file, but widening this to `repeat` to
      // match makes `abstract` at the head of a component-body member ambiguous
      // between an `access_type` and a nested component's modifier list, and
      // the conflict then pulls in `variable_declaration` as well (`final
      // MEMBER = "v"`). No corpus file writes two modifiers here — six write
      // `final component`, which this already accepts — so the trade is not
      // worth it. Recorded in LIMITATIONS.md.
      optional(choice($._kw_static, $._kw_abstract, $._kw_final)),
      choice(
        $._kw_component,
        $._kw_interface,
      ),
      // `component( javasettings = { } ) { … }` — Lucee's parenthesised settings
      // list, alongside the bare attribute spelling `component javasettings = { }`
      // that already parsed. Comma-separated inside the parentheses, matching
      // every other parenthesised list in the grammar.
      choice(
        repeat(seq(optional($.tag_linefeed), $.component_attribute)),
        seq('(', commaSep($.component_attribute), ')'),
      ),
      field('body', $.component_body),
    )),

    component_attribute: ($) => choice(
      // `component displayname:"X" { }` — Lucee's `name:value` annotation.
      // The recursive colon arm already existed and already parsed the bare
      // form `component foo:bar { }`; what it could not take was a *quoted*
      // value, because a string is not itself a `component_attribute`. Spelled
      // as a `choice` on the value rather than by adding `$.string` to the
      // arms above, which would also make a bare `component "X" { }` parse.
      seq(
        alias($.identifier, $.attribute_label),
        ':',
        choice($.component_attribute, $.string),
      ),
      seq(
        $.identifier,
        '=',
        $.expression,
      ),
      $.identifier,
    ),

    function_expression: ($) => prec('literal', seq(
      $._kw_function,
      field('name', optional($.identifier)),
      $._call_signature,
      repeat(prec(1, $.assignment_expression)),
      field('body', $.statement_block),
    )),

    // NOTE: these overlap with `_reserved_identifier` (they must stay usable as
    // plain identifiers), so they cannot become `token(prec(1, ...))` keywords
    // without breaking `static['key']` / `query.newQuery()`. Left case-sensitive.
    access_type: ($) => choice(
      $._kw_public,
      $._kw_private,
      $._kw_package,
      $._kw_remote,
      $._kw_static,
      $._kw_final,
      $._kw_abstract,
    ),

    // CFML type names are spelled with the same words as several keywords
    // (`Component listener`, `Static state`, `Final value`). Those words lex as
    // keywords here because `_reserved_identifier` makes them valid at the start
    // of a parameter, so accept them as a type name too.
    parameter_type: ($) => choice(
      keyword('Any'),
      keyword('String'),
      keyword('Numeric'),
      keyword('Xml'),
      keyword('Binary'),
      keyword('Boolean'),
      keyword('Date'),
      $._kw_function,
      keyword('Guid'),
      keyword('Query'),
      keyword('Void'),
      // `Component listener` — `component` lexes as a keyword here because
      // `_reserved_identifier` makes it valid at the start of a parameter, so it
      // never reaches `$.identifier` below.
      alias($._kw_component, $.identifier),
      $.path,
      $.identifier,
    ),

    function_declaration: ($) => prec.right('declaration', seq(
      // The return type may be written either after the modifiers
      // (`public static struct function f()`) or in front of them
      // (`struct public static function f()`, Lucee's StaticFunctions.cfc).
      // The two orders are spelled as separate alternatives rather than by
      // allowing modifiers on both sides of one optional type, which would make
      // `public function f()` ambiguous over which `repeat` takes the modifier
      // and needs a conflict. `repeat1` in the type-first alternative is what
      // keeps them disjoint: with no modifier to follow, only the first
      // alternative matches. A modifier can never be read as the type here —
      // `public` and its neighbours lex as keywords in this state, so they
      // never reach the `$.identifier` in the type slot.
      choice(
        seq(
          // `public default any function returnsany( any obj )` — Lucee's
          // Java-style modifier for a method an `interface` supplies a body
          // for. `Default` is reachable only *after* another modifier, never as
          // the first one, and that restriction is the whole reason this works:
          // a `switch_default` body is an ordinary statement list, so making
          // `default` able to start a declaration makes
          // `switch { default: default any function f(){} }` ambiguous between
          // continuing the first default's body and opening a second label —
          // and the only resolution offered is a conflict of `switch_default`
          // with itself, which cannot be declared. No corpus file writes
          // `default` first, and Lucee's own spelling puts it after `public`.
          optional(seq(
            $.access_type,
            repeat(choice($.access_type, alias($._kw_default, $.access_type))),
          )),
          optional(seq(
            choice($._kw_function, keyword('Query'), $.path, $.identifier),
            // `IValidationError[] function getFieldErrors()` — an array of that
            // type (cbvalidation). The brackets must be empty and adjacent: that
            // is the only thing separating this from a subscript, `User[0]`.
            optional($.array_return_suffix),
          )),
        ),
        seq(
          // `Query` is deliberately absent from the type-first spelling: a
          // leading `Query` is already the head of `query_tag`, and offering it
          // as a return type here makes `query • Abstract` ambiguous between
          // the two. `query public function f()` is not a form anyone writes,
          // while `public query function f()` still goes through the
          // modifiers-first alternative above, which keeps it.
          // `Function` is excluded here for the same lexical reason, and it
          // is the one that actually bit: offering it as a *leading* return
          // type makes an access modifier valid immediately after the word
          // `function`, so in `function static( … )` — a function *named*
          // `static`, from Mura's MuraScope.cfc — `static` stops lexing as an
          // identifier and becomes `_kw_static`. The file parsed cleanly before
          // and the corpus scan is what caught it.
          choice($.path, $.identifier),
          optional($.array_return_suffix),
          repeat1($.access_type),
        ),
      ),
      $._kw_function,
      field('name', $.identifier),
      $._call_signature,
      repeat(prec(1, seq(optional($.tag_linefeed), choice(
        $.assignment_expression,
        // `function f( String x ) access:remote { … }` and `secured:api` —
        // the same `name:value` annotation as on a component, which had no
        // spelling at all in this position. The value is a word or a string;
        // it is not a general expression, which keeps this `:` away from the
        // ternary and from `pair`.
        alias($.function_annotation, $.component_attribute),
        $.identifier,
      )))),
      choice(
        seq(optional($.tag_linefeed), field('body', $.statement_block), optional($._automatic_semicolon)),
        $._semicolon,
      ),
    )),

    function_annotation: ($) => seq(
      alias($.identifier, $.attribute_label),
      ':',
      choice($.identifier, $.string),
    ),

    // A single token, not `seq('[', ']')`: as two tokens the `[` is reachable
    // from `subscript_expression` and `array` in the same state, and the parser
    // cannot tell which until it has read the `]`. Lexing the pair together
    // moves that decision into the lexer, where one character of lookahead
    // settles it.
    array_return_suffix: (_) => token(seq('[', ']')),

    arrow_function: ($) => seq(
      // optional('async'),
      choice(
        field('parameter', choice(
          alias($._reserved_identifier, $.identifier),
          $.identifier,
        )),
        $._call_signature,
      ),
      // Lucee spells a closure `=>` and a lambda `->`. The two differ in how
      // they capture scope at runtime, not in shape, so one rule covers both
      // and the token itself records which was written.
      choice('=>', '->'),
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
        // `string[] v`, and nested `string[][] v` — the mirror of the array
        // return type above, reusing its single `[]` token for the same
        // reason: as two tokens the `[` is reachable from `array_pattern` in
        // this state, and the parser cannot tell which until it has read the
        // `]`. The node keeps its `array_return_suffix` name so the existing
        // `@punctuation.bracket` highlight covers both positions.
        repeat($.array_return_suffix),
        optional(choice(
          $.pattern,
          $.assignment_pattern,
          // `array in`, `array eq`, `query contains` — see `_operator_shaped_name`.
          // The bare name only. `array in = []` stays unsupported: reaching it
          // means aliasing a `seq` to `assignment_pattern`, since that rule's
          // left is a `pattern` and no pattern can reach these words, and that
          // spelling produced a malformed tree — the name outside a nested,
          // duplicated `assignment_pattern` — while adding 5% to the state
          // table. No corpus file gives an operator-shaped parameter a default.
          alias($._operator_shaped_name, $.identifier),
        )),
        repeat($.parameter_attribute),
      ),
      seq(
        optional(keyword('Required')),
        choice($.pattern, $.assignment_pattern),
        repeat($.parameter_attribute),
      ),
    ),

    // CFML's word-shaped operators are legal parameter names, and it is a type
    // in front of the name that makes them fail rather than the name itself.
    // `parameter_type` reaches the slot through `$.identifier`, and
    // `member_expression`'s object is a full `$.expression`, so an expression
    // reading is live at the start of every parameter — which makes a binary
    // operator valid straight after the type, and keyword extraction then hands
    // the word to the operator token. `--debug` shows the lexer emitting
    // `sym:in` for the name in `function f( array in )`. Naming each operator
    // here restores the identifier reading, the same move `_reserved_identifier`
    // makes for keyword-shaped names.
    //
    // Only the type spelling decides it, which is why `string in` and `any in`
    // always parsed: `parameter_type` spells those as `keyword()` tokens and no
    // expression reading survives them. `array`, `query`, `struct` and
    // `component` reach it as identifiers and do not.
    //
    // The patterns are duplicated from the `binary_expression` operator table
    // rather than shared with it: that table pairs each operator with its own
    // precedence and cannot be factored into a single rule. They are the same
    // tokens — identical patterns unify — which is what keeps `a eq b` a
    // `binary_expression` rather than two identifiers. Keep the two lists in
    // step. Multi-word operators (`does not contain`, `greater than or equal
    // to`) are deliberately absent, since no identifier can contain a space.
    _operator_shaped_name: ($) => choice(
      $._kw_in,
      $._kw_instanceof,
      /[aA][nN][dD]/,
      /[oO][rR]/,
      /[xX][oO][rR]/,
      /[mM][oO][dD]/,
      /[lL][tT]/,
      /[lL][tT][eE]/,
      /[lL][eE]/,
      /[eE][qQ]/,
      /[eE][qQ][uU][aA][lL]/,
      /[iI][sS]/,
      /[nN][eE][qQ]/,
      /[cC][oO][nN][tT][aA][iI][nN][sS]/,
      /[cC][tT]/,
      /[nN][cC][tT]/,
      /[gG][tT][eE]/,
      /[gG][eE]/,
      /[gG][tT]/,
      // `not` is deliberately absent, and is the one word here that cannot be
      // added. Every other entry is a *binary* operator, so it only competes
      // with a reading that needs a left operand the name slot has not got.
      // `not` is `unary_operator`, so `function f( array not x )` is genuinely
      // ambiguous — a parameter named `not` followed by another, or `not x` as
      // a unary expression — and `generate` offers only a conflict between
      // `_operator_shaped_name` and `unary_operator`, which would be live at
      // every `!`, `-` and `+` in the language. A parameter named `not` is also
      // the least plausible of the set, and none appears in the corpus.
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

    new_expression: ($) => prec.right('new', choice(
      seq(
        $._kw_new,
        // Standalone token on purpose: inside `new <X>` the extracted keyword
        // would lex as an identifier, breaking the inline-component form.
        $._kw_component,
        repeat(seq(optional($.tag_linefeed), $.component_attribute)),
        field('body', $.component_body),
      ),
      seq(
        $._kw_new,
        // One token including the `:`, not `seq(choice('java','cfml'), ':')`.
        // As separate tokens the bare `java` and `cfml` out-lex `identifier`
        // straight after `new`, so `new java.util.Properties()` lexed `java` as
        // the prefix and then demanded a colon. Requiring the colon inside the
        // token means `java.` simply fails to match it and falls back to an
        // identifier, which is what CFML's Java interop needs.
        optional(field('prefix', alias($._new_type_prefix, $.type_prefix))),
        optional(field('constructor', choice($.primary_expression, $.new_expression))),
        field('arguments', optional(prec.dynamic(1, $.arguments))),
      ),
    )),

    _new_type_prefix: (_) => token(seq(choice('java', 'cfml'), ':')),

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
      // `Test::["f"]()` and `Test::[m]()` — a subscript reached through the
      // static chain, which Lucee accepts alongside the bare `Test::f()` that
      // `member_expression` already handles. `::` is its own token, so unlike a
      // keyword-shaped addition this cannot change how anything else lexes.
      optional(choice(
        field('optional_chain', $.optional_chain),
        field('static_chain', $.static_chain),
      )),
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
        [/[dD][oO][eE][sS]\s[nN][oO][tT]\s[cC][oO][nN][tT][aA][iI][nN]/, 'binary_equality'],
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
    comment: (_) => token(choice(
      seq('//', /[^\r\n\u2028\u2029]*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    )),

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

      const alphanumeric = /[^\x00-\x1F\s\p{Zs}:;`"'@#&?.,\[\]|^&<=>+\-*#/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u2028\u2029]|\\u[0-9a-fA-F]{4}|\\u\{[0-9a-fA-F]+\}/;
      return token(seq('~', alpha, repeat(alphanumeric)));
    },


    this: (_) => keyword('This'),
    super: (_) => keyword('Super'),
    true: (_) => keyword('True'),
    false: (_) => keyword('False'),
    null: (_) => keyword('Null'),
    undefined: (_) => keyword('Undefined'),

    //
    // Expression components
    //

    arguments: ($) => seq(
      '(',
      commaSep(optional(choice($.expression, $.pair, $._hash_always_eval, $.spread_element))),
      ')',
    ),

    // Script-syntax tag calls: `cfdirectory( directory="#d#" action="create" )`.
    //
    // The commas are optional rather than absent. Real code mixes both in one
    // call — Lucee has `cflog(file="#n#" text="load test", type="error",
    // async=false)` and `cfdirectory(action="list", directory=trg, name="x"
    // recurse=true)` — so a rule that required all-spaces would miss most of
    // the corpus cases.
    //
    // Two restrictions keep this from colliding with an ordinary call:
    //
    // 1. Values are narrower than `expression`. With a general expression,
    //    `f( a=1 [x] )` is ambiguous between a second argument and a subscript
    //    on `1`, and tree-sitter's resolution for that is a conflict on
    //    `expression` with itself, which cannot be declared. That ambiguity is
    //    what sank the first attempt at this rule. Every value shape below was
    //    taken from real tag calls in the corpus; none of them is a subscript
    //    or an array literal, so no `[` can ever follow a complete value.
    // 2. At least two arguments are required. A single `f( a=1 )` already
    //    parses through `arguments` above, so admitting it here would add an
    //    ambiguity that buys nothing.
    // A script-syntax tag call is only ever a **statement**. The corpus has 61
    // space-separated tag calls and not one is a sub-expression — no
    // `x = cfdirectory( a="1" b="2" )`, none nested inside another call.
    //
    // That matters for cost, not just tidiness. While this form lived in
    // `call_expression` it was reachable from every expression, so its
    // conflicts were live at every call site in the language, and a large
    // script component (cfwheels `Global.cfc`) went 144 ms -> 401 ms.
    // Aliased to `expression_statement` at the use site, so
    // `cfdirectory( a="1" b="2" );` and `cfdirectory( a="1", b="2" );` produce
    // identical trees — the comma form is an ordinary call in an expression
    // statement, and nothing downstream should have to tell them apart.
    tag_call_statement: ($) => seq(
      alias($._tag_call, $.call_expression),
      $._semicolon,
    ),

    _tag_call: ($) => prec('call', seq(
      field('function', $.identifier),
      field('arguments', alias($.tag_call_arguments, $.arguments)),
    )),

    tag_call_arguments: ($) => seq(
      '(',
      // The first two arguments have no comma between them; after that commas
      // are optional, because real calls mix the two — Lucee writes
      // `cflog(file="#n#" text="load test", type="error", async=false)`.
      //
      // Requiring the space at the *first* junction rather than anywhere is
      // what keeps this tractable. A rule that allowed a leading comma-run
      // would be ambiguous with ordinary `arguments` from the opening paren
      // until the first space, so every comma-separated named call in the
      // language would carry two live GLR stacks — in a grammar that has
      // already had to fix a GLR state explosion once (0.26.29).
      //
      // The corpus says the trade is worth it: of the calls this feature
      // targets, 74 across 32 files put a space at the first junction and 11
      // across 4 files put a comma there. Those 4 files stay unparsed, and are
      // recorded in LIMITATIONS.md.
      $._tag_call_argument,
      $._tag_call_argument,
      repeat(seq(optional(','), $._tag_call_argument)),
      optional(','),
      ')',
    ),

    // Aliased to `assignment_expression` so that `cfdirectory( a="1" b="2" )`
    // and `cfdirectory( a="1", b="2" )` produce identical trees. They mean the
    // same thing, and every highlight query, indent rule and downstream
    // consumer already handles the comma form.
    _tag_call_argument: ($) => alias($.tag_call_attribute, $.assignment_expression),

    tag_call_attribute: ($) => seq(
      field('left', $.identifier),
      // `cfparam (name:"local.d" default:"DDD")` — Lucee spells a script tag
      // call's attributes with either separator. The comma-separated colon form
      // already parsed, but as ordinary `arguments` full of `pair`s rather than
      // through this rule; only the space-separated one had no reading. Both
      // separators produce the same tree here, for the reason the alias above
      // gives: they mean the same thing, and every downstream consumer already
      // handles one of them.
      choice('=', ':'),
      field('right', $._tag_call_value),
    ),

    // Shapes observed in the corpus: quoted strings with and without `#hash#`
    // interpolation, bare variables (`params=p`), dotted paths
    // (`returnType=form.returnType`), booleans (`recurse=true`), numbers, and
    // bare hash expressions.
    _tag_call_value: ($) => choice(
      $.string,
      $.number,
      $.true,
      $.false,
      $.null,
      $.identifier,
      $.member_expression,
      $._hash_always_eval,
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

    component_body: ($) => seq(
      '{',
      repeat(choice($.statement, $.property_declaration, $.static_initializer)),
      '}',
    ),

    static_initializer: ($) => seq($._kw_static, $.statement_block),

    // `classInstance = java { public class C { … } }` — Lucee's inline Java
    // class block (LDEV4001). The body is not CFML and is deliberately kept
    // opaque, which is what the issue asks for: recognising the block is enough
    // for a consumer, and parsing Java is not this grammar's job.
    //
    // The opener is one *internal* token rather than a keyword. `java` must
    // stay an ordinary identifier — `new java.util.Properties()` and
    // `x = java.lang.System` both depend on it, and a `keyword('Java')` valid
    // at expression start is precisely the out-lexing bug that
    // `new java.…` already suffered once. Because the token can only match
    // when a `{` follows, and carries no explicit precedence, longest-match
    // leaves `java.util` to `identifier` untouched. Same trick as
    // `array_return_suffix`.
    java_class_block: ($) => seq(
      $._java_block_open,
      optional($.java_class_content),
      '}',
    ),


    property_declaration: ($) => seq(
      $._kw_property,
      choice(
        prec.dynamic(1, seq(
          optional(field('type', choice($.path, $.identifier))),
          field('name', $.identifier),
          repeat(seq(optional($.tag_linefeed), $.component_attribute)),
        )),
        repeat1(seq(optional($.tag_linefeed), $.component_attribute)),
      ),
      $._semicolon,
    ),

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
      $.hash_expression,
      $.hash_empty,
    ),

    _hash: ($) => '#',

    hash_expression: ($) => seq(
      '#',
      $.expression,
      '#',
    ),

    hash_empty: ($) => token.immediate('##'),

    computed_property_name: ($) => seq(
      '[',
      $.expression,
      ']',
    ),

    // NOTE: these stay case-sensitive on purpose. They must remain usable as
    // plain identifiers (`static['key']`, `query.newQuery()`), and a
    // `token(prec(1, ...))` keyword would always win in the lexer.
    _reserved_identifier: ($) => choice(
      'get',
      'set',
      $._kw_static,
      'export',
      'let',
      $._kw_component,
      $._kw_private,
      $._kw_public,
      $._kw_include,
      keyword('Query'),
      keyword('QueryExecute'),
      $._kw_new,
      $._kw_package,
      $._kw_remote,
      $._kw_abstract,
      $._kw_final,
      // `debugger.log( … )` and `debugger = 1` — Preside's SAML module uses
      // `debugger` as an ordinary scope. Without this the keyword out-lexes
      // the identifier at statement start, though `x = debugger.foo` always
      // parsed because no statement keyword is valid there.
      $._kw_debugger,
      // `function` is deliberately absent. Listing it here made `function` a
      // valid expression start, which in turn made every binary operator —
      // including `instanceof` — valid immediately after it. Keyword extraction
      // then lexed the name in `function instanceOf( ... )` as the operator
      // instead of an identifier. See
      // test/probes/cfscript/function_named_instanceof.cfc.
    ),

    _semicolon: ($) => choice($._automatic_semicolon, ';'),

    /*
        END SCRIPT BASED RULES
      */
    template_string: ($) => seq(
      '`',
      repeat(choice(
        alias($._template_chars, $.string_fragment),
        $.template_substitution,
      )),
      '`',
    ),

    cfml_template: ($) => seq('```', $.cfml_template_content, '```'),

    query_expression: ($) => seq(
      keyword('QueryExecute'),
      '(',
      choice(
        seq('"', $.query_text, '"'),
        seq('\'', $.query_text, '\''),
      ),
      repeat(
        seq(
          '&',
          choice(
            seq('"', $.query_text, '"'),
            seq('\'', $.query_text, '\''),
            $.identifier,
            $.parenthesized_expression,
          ),
        ),
      ),
      repeat(seq(',', $.expression)),
      ')',
    ),

    query_tag: ($) => choice(
      seq(
        keyword('Query'),
        repeat(prec(1, seq(optional($.tag_linefeed), field('arguments', $.assignment_expression)))),
        optional($.tag_linefeed),
        field('body', $.statement_block),
      ),
      // `query name="q" dbtype="query";` — the bodyless spelling. Like `throw`
      // above, `query` cannot reach `tag_statement`, because `Query` is in
      // `_reserved_identifier` and lexes as a keyword in the `tag` slot. The
      // arguments are `repeat1` rather than `repeat` so that a bare `query;`
      // keeps its existing reading as an expression statement, which the
      // "bare reserved words parse as expressions" note in `LIMITATIONS.md`
      // records as deliberate.
      seq(
        keyword('Query'),
        repeat1(prec(1, seq(optional($.tag_linefeed), field('arguments', $.assignment_expression)))),
        $._semicolon,
      ),
    ),

    tag_statement: $ => choice(
      // `param string url.id default="0";` — the shorthand form names a type and
      // the variable before the attributes. The attribute-only form
      // (`param name="url.id" default="0";`) is the second branch below.
      seq(
        // Both the tag and the type stay plain identifiers. Spelling the type as
        // a set of keyword tokens instead would make `array` lex as a keyword
        // wherever this branch is live, which breaks the attribute form of every
        // other tag statement — `loop array=data` loses its `array` identifier.
        // What separates the two forms is what follows the type: a name here, an
        // `=` in the attribute branch below.
        field('tag', $.identifier),
        field('type', alias($.identifier, $.parameter_type)),
        choice(
          // `param numeric url.id default="0";` — a bare name, then attributes.
          field('name', choice($.identifier, $.member_expression)),
          // `param numeric shortBad = "abc";` — the `=` spelling of the same
          // default. The name and its value together are an ordinary
          // `assignment_expression`, and reusing that rule is the point: it
          // already settles where such an expression ends against the automatic
          // semicolon. Spelling this out as a fresh `'=' $.expression` position
          // reopens that question and cannot be resolved locally — `= a + { … }`
          // then has two readings, a binary `+` continuing the value or a unary
          // `+` opening the next statement, and the only offered resolutions are
          // a conflict or a precedence on `binary_expression`/`unary_operator`,
          // both live at every `+` and `-` in the language.
          field('default', $.assignment_expression),
        ),
        field('arguments', repeat(seq(optional($.tag_linefeed), $.assignment_expression, optional(',')))),
        $._semicolon,
      ),
      // `param x;` and `param url.number;` — the untyped shorthand. Spelled as
      // its own branch rather than by making the type above optional: optional
      // there lets the `default` alternative be reached with nothing in front
      // of it, which reopens the boundary against the attribute-only branch
      // below (`tag assignment_expression • {` is then both a default followed
      // by a body and a first attribute), and the only resolution `generate`
      // offers for that is a conflict of `tag_statement` with itself, which
      // cannot be declared. A name is an `identifier` or `member_expression`,
      // never an `assignment_expression`, so this branch cannot collide.
      // No trailing attributes here either: `param foo bar="1";` would then be
      // genuinely ambiguous between this branch (name `foo`, one attribute) and
      // the typed branch above (type `foo`, `bar="1"` as the `default`). The
      // typed branch already accepts every attribute-carrying spelling —
      // `param x default="0";` reads `x` as the type — so nothing is lost.
      seq(
        field('tag', $.identifier),
        // A bare string argument covers `exit "exitTemplate";` (#81) and
        // `pageencoding "utf-8";` (#89) — the same `tag <word-or-string>;`
        // shape as the untyped `param`, and the two tags that write it are
        // otherwise unreachable: `exit;` and `exit method="template";` parse,
        // but the positional string had no reading.
        field('name', choice($.identifier, $.member_expression, $.string)),
        $._semicolon,
      ),
      seq(
        field('tag', $.identifier),
        optional($.tag_linefeed),
        // The space-separated attribute form reaches the bodyless call through
        // `call_expression`, but a tag call with a body is a statement, so it
        // needs the alternative spelled out here too. `cfquery( name="q"
        // datasource="d" ) { ... }` is the common shape.
        optional(field('arguments', choice(
          $.arguments,
          alias($.tag_call_arguments, $.arguments),
        ))),
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
    _kw_final: (_) => keyword('Final'),
    _kw_finally: (_) => keyword('Finally'),
    _kw_for: (_) => keyword('For'),
    _kw_function: (_) => keyword('Function'),
    _kw_if: (_) => keyword('If'),
    _kw_import: (_) => keyword('Import'),
    _kw_in: (_) => keyword('In'),
    _kw_include: (_) => keyword('Include'),
    _kw_instanceof: (_) => keyword('InstanceOf', 'instanceof'),
    _kw_interface: (_) => keyword('Interface'),
    _kw_new: (_) => keyword('New'),
    _kw_of: (_) => keyword('Of'),
    _kw_package: (_) => keyword('Package'),
    _kw_private: (_) => keyword('Private'),
    _kw_property: (_) => keyword('Property'),
    _kw_public: (_) => keyword('Public'),
    _kw_remote: (_) => keyword('Remote'),
    _kw_return: (_) => keyword('Return'),
    _kw_static: (_) => keyword('Static'),
    _kw_switch: (_) => keyword('Switch'),
    _kw_throw: (_) => keyword('Throw'),
    _kw_try: (_) => keyword('Try'),
    _kw_var: (_) => keyword('Var'),
    _kw_while: (_) => keyword('While'),
    _kw_with: (_) => keyword('With'),

  },
});

/**
 * CFML keywords are case-insensitive. Keywords are written in PascalCase and
 * matched in any of the accepted casings, then aliased back to a canonical node
 * name so node names and `.scm` queries stay stable.
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
