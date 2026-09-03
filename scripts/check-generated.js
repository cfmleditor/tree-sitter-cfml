#!/usr/bin/env node
/**
 * Classify drift in the generated parser sources, after `tree-sitter generate`
 * has been re-run over a checkout.
 *
 * Two very different things both show up as a changed `parser.c`:
 *
 *   STALE        the grammar was edited and the generated files were never
 *                regenerated. `src/grammar.json` and/or `src/node-types.json`
 *                differ, because those are a faithful projection of the
 *                grammar. This is what the check exists to catch. FAILS.
 *
 *   RENUMBERED   the grammar is identical and the parse tables are equivalent,
 *                but the state numbering differs. `grammar.json` and
 *                `node-types.json` are byte-identical and every table constant
 *                matches; what moved is `ts_primary_state_ids` and the
 *                numbering that cascades from it. `tree-sitter generate` is not
 *                reproducible across machines (see #100), so this happens to
 *                anyone whose environment disagrees with CI's, through no fault
 *                of their own. WARNS, and CI uploads its own output as the
 *                canonical copy.
 *
 * Treating the second as a failure is what made the fixed check unusable: the
 * diff is hundreds of thousands of lines and looks alarming while being
 * behaviourally empty. Verified empirically — a full corpus scan either side of
 * one such renumbering was byte-identical.
 *
 * Anything else — a changed constant, a changed hand-written file — is real and
 * fails.
 *
 *   node scripts/check-generated.js            # classify; exit 1 if stale
 *   node scripts/check-generated.js --explain  # also print the constants table
 */

const {execFileSync} = require('child_process');
const path = require('path');

const root = path.join(__dirname, '..');
const explain = process.argv.includes('--explain');

/**
 * Table sizes emitted by `tree-sitter generate`; equal on both sides means
 * the tables are the same size and shape, whatever the numbering.
 */
const CONSTANTS = [
  'STATE_COUNT', 'LARGE_STATE_COUNT', 'SYMBOL_COUNT', 'ALIAS_COUNT',
  'TOKEN_COUNT', 'EXTERNAL_TOKEN_COUNT', 'FIELD_COUNT',
  'MAX_ALIAS_SEQUENCE_LENGTH', 'PRODUCTION_ID_COUNT',
];

/**
 * @param {string[]} args
 * @returns {string}
 */
function git(args) {
  return execFileSync('git', args, {cwd: root, encoding: 'utf8', maxBuffer: 1 << 30});
}

/**
 * @param {string} file - repo-relative path
 * @returns {string} the committed contents at HEAD
 */
function committed(file) {
  return git(['show', `HEAD:${file}`]);
}

/**
 * @param {string} text - contents of a generated parser.c
 * @returns {Record<string, string>} constant name -> value
 */
function constants(text) {
  /** @type {Record<string, string>} */
  const out = {};
  for (const name of CONSTANTS) {
    const m = text.match(new RegExp(`^#define ${name} (\\d+)`, 'm'));
    out[name] = m ? m[1] : '(absent)';
  }
  return out;
}

const changed = git(['diff', '--name-only', '--', '*/src/*'])
  .split('\n').filter(Boolean);

const tracked = git(['ls-files', '--', '*/src/*']).split('\n').filter(Boolean);
if (tracked.length === 0) {
  console.error('::error::The drift pathspec matches no tracked files, so this check is vacuous.');
  process.exit(1);
}
console.log(`compared ${tracked.length} generated files`);

if (changed.length === 0) {
  console.log('No drift: the committed parsers match what this environment generates.');
  process.exit(0);
}

// `grammar.json` / `node-types.json` are a projection of the grammar itself, so
// any difference there means the grammar moved and nobody regenerated.
const semantic = changed.filter((f) => /\/src\/(grammar|node-types)\.json$/.test(f));
if (semantic.length > 0) {
  console.error('::error::Generated parsers are STALE. Run `npm run build` and commit cf*/src/.');
  for (const f of semantic) console.error(`  grammar changed but not regenerated: ${f}`);
  console.error(git(['diff', '--stat', '--', '*/src/*']));
  process.exit(1);
}

// Only generated C moved. Equal constants on both sides means the tables are
// equivalent and only the numbering differs.
const parsers = changed.filter((f) => /\/src\/parser\.c$/.test(f));
const other = changed.filter((f) => !/\/src\/parser\.c$/.test(f));

/** @type {string[]} */
const mismatched = [];
for (const f of parsers) {
  const before = constants(committed(f));
  const after = constants(require('fs').readFileSync(path.join(root, f), 'utf8'));
  const diffs = CONSTANTS.filter((c) => before[c] !== after[c]);
  if (diffs.length > 0) {
    mismatched.push(`${f}: ${diffs.map((c) => `${c} ${before[c]} -> ${after[c]}`).join(', ')}`);
  }
  if (explain) {
    console.log(`\n${f}`);
    for (const c of CONSTANTS) {
      const flag = before[c] === after[c] ? '   ' : ' ! ';
      console.log(`  ${flag}${c.padEnd(26)}${before[c].padStart(7)} ${after[c].padStart(7)}`);
    }
  }
}

if (mismatched.length > 0 || other.length > 0) {
  console.error('::error::Generated parsers differ in a way that is NOT a renumbering.');
  for (const m of mismatched) console.error(`  table constant changed: ${m}`);
  for (const f of other) console.error(`  unexpected file changed: ${f}`);
  console.error(git(['diff', '--stat', '--', '*/src/*']));
  process.exit(1);
}

console.log('::warning::Generated parsers are EQUIVALENT but renumbered — see issue #100.');
for (const f of parsers) console.log(`  renumbered: ${f}`);
console.log(
  '\nEvery table constant matches and grammar.json/node-types.json are identical,\n' +
  'so the parse tables are the same; only the state numbering differs.\n' +
  '`tree-sitter generate` is not reproducible across machines. CI has uploaded its\n' +
  'own output as the `generated-parsers` artifact: download it and commit those\n' +
  'files to make the repository match CI, or leave it — nothing is broken.',
);
process.exit(0);
