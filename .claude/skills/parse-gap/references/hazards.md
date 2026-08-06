# Hazards

Each entry is a way this grammar has actually broken, not a general caution. The
change that triggered it is named so you can judge whether your edit is the same
shape.

## Contents

- [Keyword extraction is lexical](#keyword-extraction-is-lexical)
- [`:` is contested by four rules](#-is-contested-by-four-rules)
- [CFScript exists twice](#cfscript-exists-twice)
- [`extras` match inside string literals](#extras-match-inside-string-literals)
- [A widened rule swallows its neighbours](#a-widened-rule-swallows-its-neighbours)
- [Single-rule conflicts cannot be declared](#single-rule-conflicts-cannot-be-declared)
- [`--update` is a code generator, not a test](#--update-is-a-code-generator-not-a-test)
- [Single-dialect builds leave the bindings stale](#single-dialect-builds-leave-the-bindings-stale)

## Keyword extraction is lexical

This is the one that keeps happening. With `word: $.identifier`, tree-sitter
extracts keyword tokens: when the lexer reads a word, it checks whether a
keyword token matching it is valid *in the current parse state*. If one is, that
is what the word becomes. So making a keyword valid in a new position silently
changes how that word lexes everywhere in that state — including in rules you
did not edit.

**Adding `member_expression` to `variable_declarator`** (to support
`var local.x = 1`) made keyword-led expressions valid after `var`. That broke
`var new = 1` and `for ( var export in … )`, because `new` and `export` now
lexed as keywords where they used to be identifiers. Fixed by naming
`_reserved_identifier` explicitly in the declarator and the for-header, so the
identifier reading stays available.

**Spelling a type slot as `keyword('Any')`, `keyword('Array')`, …** for the
typed `param` statement made those words lex as keywords wherever the branch was
live. `loop array=data item="x"` lost its `array` identifier and became an
ERROR. Fixed by using a plain `$.identifier` for the type and letting what
follows disambiguate — a name means the typed form, an `=` means the attribute
form.

The general move: **when a rule needs a word in a slot, reach for
`$.identifier` before reaching for `keyword()`**. A closed set of keyword tokens
feels more precise and is usually more dangerous. If you genuinely need keyword
tokens, expect to add `_reserved_identifier` alternatives alongside them.

Symptom to watch for: a corpus test failing on a construct that has nothing to
do with your change, where the diff shows an identifier becoming an ERROR.

## `:` is contested by four rules

`pair`, `switch_case`, `slice_expression` and the ternary all want `:`. `pair`
is reachable from `arguments` and `array`, which is why `case <expr> :` is
ambiguous with the start of a pair — see the `[$.switch_case, $.expression]`
conflict and its comment.

The casing work removed conflicts around `:` deliberately. Adding a new `:`
reading (a callback syntax, a type annotation, a label) tends to reintroduce the
`case <expr> :` ambiguity, and the fix is not local. Budget accordingly, and
treat "just one more `:` form" as a medium-risk change however small the diff.

## CFScript exists twice

`cfscript/grammar.js` is a standalone 1,500-line grammar. The CFScript rules
inside `common/define-grammar.js` are a separate copy serving `<cfscript>` in
`.cfm`/`.cfc` files. They have drifted.

So: check both before concluding a construct is unsupported, and change both
when adding one that should work in either place. A probe under
`test/probes/cfml/` and one under `test/probes/cfscript/` is the cheapest way to
keep yourself honest.

## `extras` match inside string literals

`extras` are matched *everywhere* the lexer runs, including inside string
tokens. Adding CFML tag comments (`<!--- … --->`) as an extra made this line
stop parsing:

```cfml
reReplace( src, "<!---.*?--->", "" )
```

The comment rule matched inside the string literal. Fixed by making `cf_comment`
a `statement` instead of an extra — narrower, and it only appears where a
statement can.

If you are about to add something to `extras`, ask what happens when it appears
inside a string, a regex, or a raw-text tag body.

## A widened rule swallows its neighbours

**Allowing member declarations after an access modifier** (`public prop = "x";`)
also matched `public component function init()`, breaking nine corpus files —
the declaration rule was happy to take `component` as the declared name. Fixed
by restricting the member form to `_plain_declarator`, a bare identifier only.

The pattern: when you widen a rule that starts with a common prefix, enumerate
what *else* starts with that prefix. In this grammar that is usually access
modifiers, `var`/`final`, and type names.

## Single-rule conflicts cannot be declared

`tree-sitter generate` sometimes suggests a conflict like `[$.expression]` — a
single rule conflicting with itself. That cannot be declared; conflicts need two
or more distinct rules. This is what blocked script-syntax tag calls
(`cfdirectory( directory="#dir#" action="create" )`), where `f( a=1 [x] )` is
ambiguous between a subscript and a second argument.

When you hit this, the answer is not a conflict declaration but a narrower rule
— for that case, a restricted attribute-value rule that cannot start with `[`.
`prec.dynamic` is the other tool: it lets two readings both survive to the end
of the parse and picks a winner, which works when the ambiguity resolves later.
It does not help when the two readings diverge at the lexer.

## `--update` is a code generator, not a test

`tree-sitter test --update` (and `npm run test:update`) rewrites every
expectation to whatever the parser currently produces. It can never fail. Run it
to fill in a new test you just wrote, then read `git diff` and confirm only your
block changed. If other blocks moved, you changed behaviour somewhere you did
not intend to.

`npm run probe` is the opposite and is the one to trust: it compares against a
committed `expected.json` and fails on drift in *either* direction, so a gap
closing is as visible as a regression.

## Single-dialect builds leave the bindings stale

`DIALECT=cfml npm run build` runs `tree-sitter generate` and stops. It does not
rebuild the native addon. Anything going through the Node bindings —
`npm run probe`, `npm run scan`, `npm run testbindings`, any `require('.')`
one-liner — keeps using the previously compiled parser, and will happily report
that your change did nothing, or that it worked when it did not.

Run a full `npm run build` before believing any binding-based result.
