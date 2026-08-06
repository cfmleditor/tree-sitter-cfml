#!/usr/bin/env node

'use strict';

/**
 * Fuzz the parsers with the tree-sitter CLI's built-in fuzzer.
 *
 *   npm run fuzz                    # all three dialects
 *   DIALECT=cfscript npm run fuzz   # one dialect
 *   FUZZ_ITERATIONS=10 FUZZ_EDITS=3 npm run fuzz
 *
 * The fuzzer applies random edits to every corpus test and checks that an
 * incremental re-parse matches a fresh one, which is what exercises the
 * external scanner.
 *
 * `cfscript` used to run at a reduced budget because runs hung. That was a real
 * parser bug, not a fuzzer quirk: `scan_query_text` looped until the closing
 * quote with no EOF check, so `queryExecute("` spun forever. Fixed, and the
 * budget is back in line with the other two — a 30-iteration, 5-edit soak now
 * finishes in under a second.
 */

const {join} = require('path');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

// [iterations, edits] per dialect.
const BUDGETS = {
  cfml: [10, 3],
  cfquery: [10, 3],
  cfscript: [10, 3],
};

const only = process.env.DIALECT;
const dialects = only ? [only] : Object.keys(BUDGETS);

for (const dialect of dialects) {
  const [defaultIterations, defaultEdits] = BUDGETS[dialect] || [10, 3];
  const iterations = process.env.FUZZ_ITERATIONS || String(defaultIterations);
  const edits = process.env.FUZZ_EDITS || String(defaultEdits);

  console.log(`fuzzing ${dialect} (iterations=${iterations}, edits=${edits})`);
  const started = Date.now();
  const r = spawnTreeSitter(
    ['fuzz', '--iterations', iterations, '--edits', edits],
    {cwd: join(root, dialect)},
  );
  console.log(`  ${dialect}: ${((Date.now() - started) / 1000).toFixed(1)}s`);
  if (r.status !== 0) {
    console.error(`${dialect}: fuzzing failed (exit ${r.status ?? 1})`);
    process.exitCode = 1;
  }
}
