# Construct probes

Each file here is a minimal reduction of a CFML construct found in public code
bases (see [`../../CORPUS.md`](../../CORPUS.md)). The header comment in every
probe names the project it was reduced from.

`expected.json` records whether the grammars currently parse each probe cleanly:

- `pass` — the file and its injected regions parse with no ERROR/MISSING nodes.
  A probe flipping to `fail` is a regression.
- `fail` — a known grammar gap. A probe flipping to `pass` is a fix.

```bash
npm run probe              # report, and fail on any drift from expected.json
npm run probe -- --update  # rewrite expected.json to current behaviour
```

Probes are parsed the way an editor would parse them: the `cfml` grammar for
`.cfm`/`.cfc`, the `cfscript` grammar for `.cfs`, plus the `cfscript` and
`cfquery` injections declared by `injections.scm`.

Unlike `cf*/test/corpus/`, probes assert nothing about tree shape — only whether
a construct parses at all. Once a gap is fixed, promote the construct to a real
corpus test so its tree is pinned too.
