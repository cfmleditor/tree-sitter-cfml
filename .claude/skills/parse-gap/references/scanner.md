# The external scanners

Two of them, no generator, and the corpus scan is the only safety net. Read this
before editing either, and when a parse hangs or crashes.

## Contents

- [Which scanner](#which-scanner)
- [The rules of the lexer API](#the-rules-of-the-lexer-api)
- [Infinite loops](#infinite-loops)
- [Diagnosing a hang](#diagnosing-a-hang)
- [Hunting for a bad input](#hunting-for-a-bad-input)
- [Profiling: counting character advances](#profiling-counting-character-advances)

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

**`skip` after `advance` throws the token away.** `skip` does not mean "move on
without consuming" — it means *what came before this was whitespace*, so it
resets the token's START to the current position. Advancing over a word and then
`skip`ping the spaces after it to peek at the next character leaves a zero-width
token sitting where you stopped, with the word covered by no node at all. Use
`advance` for that lookahead instead: once `mark_end` has fixed the end,
advancing past it is the supported way to look further, and the token keeps both
its start and its marked end. This shipped once in `_savecontent_kw` (#82) and
nothing caught it: `npm test` compares S-expressions, which carry no ranges, so
a correctly-shaped tree with a zero-width leaf passes. Print `startIndex` /
`endIndex`, or the node's text, for any token your scanner produces.

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

### The cfml scanner's recovery policy

`common/scanner.h` detects recovery as `AUTOMATIC_SEMICOLON` and `HTML_TEXT`
both valid — a pair no real parse state has, in cfml or cfquery — and then
offers only tokens anchored at a real `<` or at end of input: a comment,
`<`-led text, an implicit end tag. Before #145 it offered nothing, because a
content branch returned its scan's `false` as the scanner's answer. Every other
branch was measured doing harm in recovery, and three of the ways are worth
knowing before adding a branch:

- a scan that reads a *name* at the current position reads one from arbitrary
  text, and an end-tag name that matches the stack pops it;
- at `/>` every delimiter is valid, so whichever branch comes first wins — a CF
  self-closing delimiter popped the enclosing `<cffunction>` at a
  `<cfreturn … />`;
- free-running text mutates nothing and still made things worse: offering it
  cut ERROR bytes by half overall but let recovery swallow whole files that had
  cost 107 bytes before.

**Measure recovery by bytes inside outermost ERROR nodes per failing file, not
by the scan's error count.** A better recovery often *adds* an error line — one
large ERROR becomes two small ones — and the scan reads that as a regression.
Compare per file, and gate on "no file worse" as well as the total.

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

## Profiling: counting character advances

`npm run bench` measures time, and on a shared runner time is often
unmeasurable — a real session recorded **76-86% variance between reps**, with an
untouched control grammar moving further than the change under test. Counting
what the scanner *does* has no such problem: character advances are
deterministic, identical on every run, and unaffected by load.

Instrument `advance`/`skip` with a per-function counter, set a current-function
id at the top of each scan function, and dump from a destructor behind an
environment variable so an ordinary build is untouched when it is off:

```c
/* scratch, never committed */
enum { PF_NONE = 0, PF_scan_html_text, PF_scan_raw_text, /* … */ PF_COUNT };
static const char *pf_names[PF_COUNT] = { "other", "scan_html_text", /* … */ };
static unsigned long pf_adv[PF_COUNT], pf_calls[PF_COUNT];
static int pf_cur = PF_NONE;
__attribute__((destructor)) static void pf_dump(void) {
    if (getenv("CFPROF") == NULL) return;
    for (int i = 0; i < PF_COUNT; i++)
        if (pf_calls[i] || pf_adv[i])
            fprintf(stderr, "PROF\t%s\t%lu\t%lu\n", pf_names[i], pf_calls[i], pf_adv[i]);
}
#define PF_ENTER(id) do { pf_cur = (id); pf_calls[id]++; } while (0)
```

with `advance` becoming `{ pf_adv[pf_cur]++; lexer->advance(lexer, false); }`
and `PF_ENTER(PF_scan_x);` as the first line of each `scan_x`. Then
`npm run build && CFPROF=1 npm run scan corpus 2>prof.txt`.

Three things to know before reading the output:

- **Attribution is last-set-wins.** A helper called from a scan function is
  charged to whichever id was set most recently, which is usually what you want
  (`skip_cfml_comment_body` billed to its caller) but is not a call graph.
- **`common/scanner.h` is compiled twice**, so `cfml` and `cfquery` each print
  their own set of rows. They are separate libraries, not a double count.
- **`npm run scan` parses injected regions by re-parsing them.** When that
  matters, drive the parse from a script that reads each file and calls
  `parser.parse()` exactly once instead.

### Detecting error recovery

In recovery tree-sitter marks *every* external token valid, so the exact test is
to count them at the top of the dispatcher:

```c
unsigned n = 0;
for (unsigned i = 0; i < count; i++) if (valid_symbols[i]) n++;
bool in_recovery = (n == count);
```

Split any counter by that flag when you suspect a scan is firing where the
grammar would never reach it — the failure mode this file documents for
`cfml_template_content`.

### The case study, because both obvious answers were wrong

A profile of the 15,392-file corpus put **71% of all `cfml` scanner character
advances (39.1M of 55.1M) in one function**, `scan_cf_component_content`, which
consumes a whole script component file as a single opaque token. Two hypotheses
followed, and the same instrumentation killed both:

- **"It is firing in error recovery."** Split by the flag above: **0** of 8,824
  full-file scans were in recovery, against 25 cheap calls that were. A recovery
  guard would have saved nothing.
- **"It is scanning files more than once."** 8,824 full scans against a baseline
  of 7,066 files looked like 1.25x. The baseline was wrong: the scan also
  accepts `.cfm` files and the heads `property`, `interface` and `import`, not
  only `component` in a `.cfc`. Counting exactly what it accepts gives **8,239
  files, 36.2 MB** against **8,824 scans, 37.2M characters** — **1.03x**, one
  pass per file, nothing to remove.

**Get the denominator right before believing a ratio.** A hot function is not a
slow one: reading every component body once is what that token costs, and no
scanner change makes it cheaper, because the lexer API has no bulk skip.

What the profile did establish is where *not* to look. The `cfscript` scanner
does 12.6M advances against `cfml`'s 55.1M while parsing ~4x slower per byte, so
its cost is in the parse table rather than the scanner — chase `STATE_COUNT`
there, not character work. And `bench`'s own split is worth reading first: on
that corpus, error-recovery input was 4% of the bytes but **26% of the time**,
which makes fixing a parse gap a throughput change as much as a correctness one.

## Before you commit a scanner change

- `npm run build` (full), `npm test`, `npm run probe`, `npm run lint`
- `npm run fuzz` — mandatory for scanner changes; it is the only thing that
  exercises state transitions systematically
- Full corpus scan diffed against a pre-change baseline; deletions only
- `npm run bench` against a baseline taken on the base commit. A scanner change
  moves throughput without moving a single test — in both directions
- Spot-check truncated inputs by hand: `<cf`, `<!--- x`, `<cfoutput>#a`,
  `<cfquery>SELECT 1`, `queryExecute("`, `x = {`. Each should recover, not hang.
