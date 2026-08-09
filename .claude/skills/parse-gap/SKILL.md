---
name: parse-gap
description: Workflow for making CFML/CFScript/SQL syntax parse in the tree-sitter-cfml grammars when it currently produces an ERROR node, plus diagnosing a parser that hangs or crashes. Use this whenever the task involves a construct that does not parse, an ERROR or MISSING node, a corpus scan finding, a request to "support" some CFML syntax, a grammar conflict from `tree-sitter generate`, or an external scanner change in `common/scanner.h` or `cfscript/src/scanner.c`. Also use it when a parse looks wrong rather than failing outright — the same reproduce-then-verify loop applies. Worth loading even for a change that looks like a one-line addition to a `choice`, because the verification gate is what catches the damage such changes do elsewhere.
---

# Fixing a parse gap

The hard part of this repo is not writing the rule. It is knowing what else the
rule breaks. Every change in the last round that looked self-contained still
needed a full corpus re-scan to confirm, and three of them were only saved by
that scan. The workflow below is built around that fact.

## 1. Reproduce it as small as you can

Start from the smallest input that still fails, not the file it came from. A
100-node ERROR usually means *one* bad construct near the top of a file that
cost the parser its nesting — the other 99 nodes are cascade, and chasing them
wastes the session.

```bash
node -e "
const Parser=require('tree-sitter'), langs=require('.');
const p=new Parser(); p.setLanguage(langs.cfscript);
console.log(p.parse('param string url.id default=\"0\";').rootNode.toString());
"
```

Swap `cfscript` for `cfml` or `cfquery`. For a `.cfm` file whose failure is
inside `<cfscript>` or `<cfquery>`, parse the *inner* text with the inner
grammar — the outer tree will often look clean because the body is an injection.

Once it is small, save it under `test/probes/<grammar>/<name>.<ext>` with a
comment naming the real-world source. `npm run probe` then tracks it forever and
tells you the moment it starts passing.

## 2. Work out who owns it

| The construct appears in | Edit |
|---|---|
| Tags, HTML, template text | `common/define-grammar.js` (affects `cfml` **and** `cfquery`) |
| SQL inside `<cfquery>` | `common/define-grammar.js`, the `dialect === 'cfquery'` branch |
| CFScript in a `.cfs` file | `cfscript/grammar.js` |
| CFScript inside `<cfscript>` | `common/define-grammar.js` — a *different* copy of the same rules |

The last row is the trap: CFScript exists twice. A construct that should work in
both `.cfs` and `<cfscript>` needs the same change in both files, and they have
drifted, so check rather than assume.

If the construct's boundary is decided by scanning characters rather than by
grammar rules — tag open/close matching, raw text, `#hash#` spans, implicit end
tags — it is scanner work. Read `references/scanner.md` before touching either
scanner; they have no generator to check your work.

## 3. Make the change, expecting the lexer to fight you

`word: $.identifier` means keyword extraction is **lexical**. A rule that makes
a keyword valid in a new position changes how that word lexes in that whole
parse state, including in rules you did not touch and tests you did not read.

`references/hazards.md` catalogues the specific traps, each with the change that
triggered it. Read it before editing declarations, parameters, statement heads,
anything involving `:`, or the type slot of a rule. It will save you a cycle.

The short version, because it comes up most: **prefer a plain `$.identifier`
over a set of `keyword()` tokens** when a rule needs a word in a slot. Let what
*follows* disambiguate. Spelling a type slot as `keyword('Array')` et al. is
what broke `loop array=data item="x"`.

## 4. Run the gate

Every step, in order, on the *whole* project — not the dialect you edited:

```bash
npm run build          # full build; DIALECT=… skips the native addon rebuild
npm test               # corpus tests, all three grammars
npm run probe          # drift in either direction is a signal
npm run lint
```

Then the part CI does not do, and the part that actually catches things:

```bash
npm run corpus:fetch                 # first time only; clones into /corpus
npm run scan corpus > after.txt
diff <(sort before.txt) <(sort after.txt)
```

Take `before.txt` *before* you edit. `npm run corpus:report -- --from after.txt`
clusters what remains by source-line shape when you want to see what is left.

**Read the diff by per-file totals, not by added lines.** A raw diff of
deletions only is the ideal, but added lines are not automatically a regression:
in a file the parser cannot recover in either case, a grammar change shifts
*where* recovery gives up, so old error lines are replaced by different ones.
Count instead:

```bash
for f in $(cat before.txt after.txt | grep -oE '^[^:]+\.cf[cms]?' | sort -u); do
  b=$(grep -cF "$f:" before.txt); a=$(grep -cF "$f:" after.txt)
  [ "$b" != "$a" ] && printf "  %5s -> %-5s %s\n" "$b" "$a" "$f"
done
```

Every file should improve or hold level. If one gets worse, reduce its
construct to a one-liner and parse it in isolation before concluding anything —
the script-syntax tag call change made `PerformanceSuite.cfc` go 186 → 198 while
fixing 101 nodes elsewhere, and the lines it "broke" turned out to parse cleanly
on their own. That file is invalid CFML (a bare `#` where the language needs
`##`), cascades from line 1 both before and after, and is documented as such in
`docs/FAILING-PATTERNS.md`. A file already in that category shifting its
recovery shape is not a reason to back out a fix; a file that *parses* getting
worse is.

If the change touches either scanner, also run `npm run fuzz` — it applies
random edits to every corpus test and re-parses, which is the only thing that
exercises scanner state transitions systematically. CI runs it for grammar and
scanner paths, but locally is where you want to find a hang.

If someone asks whether the change costs performance, use `npm run bench`
(baseline first, then compare) rather than timing `npm run scan`. Scan time
moves with the error count, so a change that fixes parse errors reads as a huge
speedup or slowdown that has nothing to do with the parser.

## 5. Land it

- **Corpus test** for the newly-supported construct. Write the input with a
  `(program)` placeholder, run `npm run test:update`, then check `git diff` to
  confirm only your block changed — `--update` rewrites expectations wholesale
  and can never fail, so it is not a check, it is a code generator.
- **`npm run probe -- --update`** to record probes that flipped to passing.
- **Docs**: `LIMITATIONS.md` lists what does not parse — prune it as well as add
  to it, it goes stale silently. `docs/FAILING-PATTERNS.md` carries the cost and
  risk table; when an estimate there turns out wrong, say so and say why. That
  record is the only calibration the next person gets.
- **`CHANGELOG.md`** under `## [Unreleased]`, grouped by grammar.
- **Commit message**: say what the corpus numbers did, and name anything that
  broke on the way. A fix that needed two attempts is more useful written down
  than a fix that looks like it worked first time.

## Reference files

- `references/hazards.md` — the traps, each with the change that triggered it.
  Read before editing grammar rules.
- `references/scanner.md` — how the external scanners work, what they cannot do,
  and how to diagnose a hang or crash. Read before editing either scanner, or
  when the parser stops responding.
