# The external scanners

Two of them, no generator, and the corpus scan is the only safety net. Read this
before editing either, and when a parse hangs or crashes.

## Contents

- [Which scanner](#which-scanner)
- [The rules of the lexer API](#the-rules-of-the-lexer-api)
- [Infinite loops](#infinite-loops)
- [Diagnosing a hang](#diagnosing-a-hang)
- [Hunting for a bad input](#hunting-for-a-bad-input)

## Which scanner

- `common/scanner.h` — `cfml` and `cfquery`. Roughly 1,900 lines: tag name
  matching against the tables in `common/tag.h`, implicit end tags, raw-text
  bodies (`<script>`, `<style>`, `<cfsavecontent>`), `#hash#` spans, HTML text.
  Dialect differences are `#ifdef`-gated. `cfml/src/scanner.c` and
  `cfquery/src/scanner.c` are thin wrappers that `#include` it.
- `cfscript/src/scanner.c` — `cfscript` only. Roughly 500 lines: automatic
  semicolon insertion, template chars, the ternary `?` / elvis split, query
  text, tag linefeeds, CFML comments in script bodies.

They share nothing. A fix in one is not a fix in the other.

## The rules of the lexer API

`advance(lexer)` consumes a character into the token; `skip(lexer)` consumes it
as leading whitespace/extra; `lexer->mark_end(lexer)` sets where the token ends.

Three properties drive most scanner bugs:

**You cannot rewind.** Once you have advanced past a character it is gone. If
you peek at what follows a `<` and then return `false`, the dispatcher below you
resumes *after* the `<` and never sees the tag or comment that started there.
This broke every CFML comment in the corpus on the first attempt at treating a
bare `<` as text. The fix was to only peek once some text had already been
collected, which guarantees a `true` return, so the consumed character is always
covered by a successful token. A `<` at the very start of a run falls through to
the tag rules untouched.

**`valid_symbols` tells you what the parser will accept here, and that is the
only context you get.** Turning `>` into text is safe precisely when no closing
delimiter is valid — `CLOSE_TAG_DELIM`, `CLOSE_CF_TAG_DELIM`,
`SELF_CLOSING_TAG_DELIMITER`, `CF_SELF_CLOSING_TAG_DELIMITER`,
`CF_SELF_CLOSING_VOID_TAG_DELIMITER`. Where none is expected, the parser is not
inside a tag, so `>` cannot be closing one.

**Zero-width tokens are legal but must not repeat.** ASI works by returning
`true` having consumed nothing. That is fine as long as the resulting parse
state no longer accepts the token; if it does, the parser loops forever emitting
the same empty token.

## In error recovery, every external token is valid

`valid_symbols` is all-true while the parser is recovering. A scan that is cheap
where the grammar actually reaches it — because it only runs after some opening
delimiter — will run at *every* recovery step instead, and a scan that ends at
EOF ends at EOF each time. Returning `false` afterwards does not refund it.

`cfml_template_content` (the body of a ``` fence) is only reachable straight
after the opening fence, so its scan looked bounded. Unguarded in recovery it
searched every remaining byte for a closing fence that ordinary CFML does not
contain: 3,060 calls over 400 corpus script components did 25.1M of the
scanner's 25.13M character advances on 2.2 MB of input, and 52% of every
instruction the parse retired. `npm test`, the probes and the corpus scan were
all green — the output was right, it just cost 1.6× more than it needed to.

Detect recovery by naming a token the grammar never makes valid alongside yours,
and stand down:

```c
if (valid_symbols[CFML_TEMPLATE_CONTENT]) {
    if (valid_symbols[AUTOMATIC_SEMICOLON]) return false;  // recovery
    return scan_cfml_template_content(lexer);
}
```

Return `false` rather than falling through, so the branches below still see the
state they used to. Anything that scans to a delimiter — raw text, query and
script bodies, `#hash#` spans — wants the same guard, and `npm run bench` is the
only gate that can see it missing.

## Infinite loops

`advance()` is a **no-op once `lexer->lookahead` is 0**. So any loop of the form

```c
while (lexer->lookahead != TERMINATOR) { ...; advance(lexer); }
```

spins forever on unterminated input. Every character-consuming loop needs
`lexer->lookahead != 0` in its condition, or a `break` that fires at EOF.

This is not hypothetical: `scan_query_text` in `cfscript/src/scanner.c` looped
to the closing `"` with no EOF check, so `queryExecute("` hung the parser
forever — including in an editor, mid-keystroke. It was adapted from a JSX
scanner that *did* check; the check was dropped in the copy.

Counter-bounded loops (`while (i < len)`) are fine as long as the counter
advances unconditionally on every path.

When you add or edit a loop, ask: what does this do on input that ends in the
middle of the thing I am scanning? That is the state an editor is in on every
keystroke.

## Diagnosing a hang

The Node wrapper is not where the work happens. `node_modules/tree-sitter-cli/cli.js`
spawns a Rust binary; if you attach a debugger to the `node` process you will
see it idle in `epoll_pwait` and learn nothing. Find the child:

```bash
# in one shell: start the hanging command in the background, note its pid
# then:
pgrep -P <node-pid>                       # the tree-sitter child
gdb -p <child-pid> -batch -ex "bt 20"     # its stack
```

A stack ending in `tree_sitter_<lang>_external_scanner_scan` with 100% CPU is a
scanner loop. The frame below it usually names the character it is stuck on —
`__iswspace (wc=0)` means it is looping on EOF.

For a hang under the Node bindings instead, remember the parse is synchronous:
the process freezes, so you cannot catch it from inside. Run the parse in a
child process that writes each candidate input to a file *before* parsing it,
then read that file after the child times out. See the next section.

## Hunting for a bad input

`npm run fuzz` finds these, but only across a whole run and only sometimes — the
mutation has to happen to produce the bad shape. If a fuzz run hangs
intermittently, do not conclude the fuzzer is flaky on the strength of one clean
retry. Run the same case twenty times; a 2-in-20 reproduction rate looks like
zero at n=1.

To minimise from a fuzzer hang to a one-liner: take the mutated input the
fuzzer was on, then bisect it by hand against a small runner that parses one
file with a timeout. Delete half, re-test, repeat. Going from a mutated
four-line corpus test to `queryExecute("` took about ten iterations of that.

To search for a bad input from scratch, mutate a seed with random
inserts/deletes in a loop, writing each candidate to disk before parsing, and
run the whole thing under `timeout`. Whatever is on disk when it dies is the
culprit. Bias the inserted characters toward the ones the scanner branches on —
`{ } ; " # < > ( ) = :` — rather than uniform ASCII.

## Before you commit a scanner change

- `npm run build` (full), `npm test`, `npm run probe`, `npm run lint`
- `npm run fuzz` — mandatory for scanner changes; it is the only thing that
  exercises state transitions systematically
- Full corpus scan diffed against a pre-change baseline; deletions only
- `npm run bench` against a baseline taken on the base commit. A scanner change
  moves throughput without moving a single test — in both directions
- Spot-check truncated inputs by hand: `<cf`, `<!--- x`, `<cfoutput>#a`,
  `<cfquery>SELECT 1`, `queryExecute("`, `x = {`. Each should recover, not hang.
