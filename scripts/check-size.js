#!/usr/bin/env node

'use strict';

/**
 * Compare the parse tables of each grammar against a base, and fail when one
 * grows past a budget.
 *
 *   npm run check:size                        # working tree against origin/master
 *   node scripts/check-size.js --base v0.26.37
 *   node scripts/check-size.js --base v0.26.37 --head v0.26.36   # two commits
 *   node scripts/check-size.js --max-growth 10
 *   node scripts/check-size.js --allow-growth # report, never fail
 *
 * `STATE_COUNT` is what the gate reads. Nothing else in the workflow sees it:
 * a grammar change that admits an existing rule into a new position can double
 * a table and still pass every test, probe and corpus scan — a statement as an
 * arrow-function body took cfscript from 4,984 to 10,005 states (#75), and
 * aliasing the word operators the obvious way added 13–15% to every grammar,
 * both with the whole suite green. Only a size check sees either, and a manual
 * one gets forgotten on exactly the changes that look harmless.
 *
 * Large states and `parser.c` are reported alongside but do not gate: they move
 * with the state count, and one number is easier to set a budget for.
 *
 * The files are read from git, not generated, so this needs no build and takes
 * seconds. `--head` defaults to the working tree, which is the committed tree
 * in CI and lets a local run see a regenerated parser before it is committed.
 *
 * In CI the base is `HEAD^1` of the pull request's merge commit — the base
 * branch as GitHub merged it — so the delta is exactly what the pull request
 * adds, even when the base has moved on since the branch was cut. A deliberate
 * increase is let through by the `grammar-size-ok` label, which the workflow
 * passes as `--allow-growth`. With `GITHUB_STEP_SUMMARY` set, the table is
 * written to the job summary as well, so a pull request that shrinks the tables
 * shows that too.
 */

const {execFileSync} = require('child_process');
const fs = require('fs');
const path = require('path');

const root = path.join(__dirname, '..');
const dialects = ['cfml', 'cfquery', 'cfscript'];

/**
 * @param {string} flag
 * @param {string} fallback
 * @returns {string}
 */
function option(flag, fallback) {
  const i = process.argv.indexOf(flag);
  return i >= 0 && process.argv[i + 1] ? process.argv[i + 1] : fallback;
}

const base = option('--base', 'origin/master');
const head = option('--head', '');
const maxGrowth = Number(option('--max-growth', '5'));
const allowGrowth = process.argv.includes('--allow-growth');

/**
 * @param {string} ref - a commit, or '' for the working tree
 * @param {string} file - repo-relative path
 * @returns {string | null} the file's contents, or null if it does not exist there
 */
function read(ref, file) {
  if (!ref) {
    const p = path.join(root, file);
    return fs.existsSync(p) ? fs.readFileSync(p, 'utf8') : null;
  }
  try {
    return execFileSync('git', ['show', `${ref}:${file}`],
      {cwd: root, encoding: 'utf8', maxBuffer: 1 << 30, stdio: ['ignore', 'pipe', 'ignore']});
  } catch {
    return null;
  }
}

/**
 * @param {string} text - a generated parser.c
 * @returns {{states: number, large: number, bytes: number}}
 */
function measure(text) {
  /** @param {string} name */
  const define = (name) => Number(new RegExp(`^#define ${name} (\\d+)`, 'm').exec(text)?.[1]);
  return {states: define('STATE_COUNT'), large: define('LARGE_STATE_COUNT'), bytes: Buffer.byteLength(text)};
}

/**
 * @param {number} before
 * @param {number} after
 * @returns {number} percentage change
 */
function pct(before, after) {
  return before === 0 ? 0 : (after - before) / before * 100;
}

/**
 * @param {number} before
 * @param {number} after
 * @param {(n: number) => string} fmt
 * @returns {string}
 */
function cell(before, after, fmt) {
  if (before === after) return `${fmt(after)} (=)`;
  const p = pct(before, after);
  return `${fmt(before)} → ${fmt(after)} (${p > 0 ? '+' : ''}${p.toFixed(1)}%)`;
}

const count = (/** @type {number} */ n) => n.toLocaleString('en-US');
const mb = (/** @type {number} */ n) => `${(n / 1048576).toFixed(1)} MB`;

if (!read(base, 'cfml/src/parser.c')) {
  console.error(`::error::Cannot read the base parsers at \`${base}\` — fetch it, or pass --base.`);
  process.exit(1);
}

const rows = [];
const over = [];
for (const dialect of dialects) {
  const file = `${dialect}/src/parser.c`;
  const before = read(base, file);
  const after = read(head, file);
  if (!after) {
    console.error(`::error::${file} is missing at ${head || 'the working tree'}.`);
    process.exit(1);
  }
  if (!before) {
    rows.push(`| \`${dialect}\` | new: ${count(measure(after).states)} | | |`);
    continue;
  }
  const b = measure(before);
  const a = measure(after);
  rows.push(`| \`${dialect}\` | ${cell(b.states, a.states, count)} | ${cell(b.large, a.large, count)} | ${cell(b.bytes, a.bytes, mb)} |`);
  if (pct(b.states, a.states) > maxGrowth) {
    over.push(`${dialect}: STATE_COUNT ${count(b.states)} → ${count(a.states)} ` +
      `(+${pct(b.states, a.states).toFixed(1)}%, budget ${maxGrowth}%)`);
  }
}

const table = [
  `Parse tables, \`${head || 'working tree'}\` against \`${base}\`:`,
  '',
  '| | `STATE_COUNT` | large states | `parser.c` |',
  '|---|---|---|---|',
  ...rows,
  '',
].join('\n');

console.log(table);
if (process.env.GITHUB_STEP_SUMMARY) {
  fs.appendFileSync(process.env.GITHUB_STEP_SUMMARY, `### Grammar size\n\n${table}\n`);
}

if (over.length === 0) {
  console.log(`Every grammar is within the ${maxGrowth}% STATE_COUNT budget.`);
} else if (allowGrowth) {
  console.log('Over budget, allowed:');
  for (const line of over) console.log(`  ${line}`);
} else {
  for (const line of over) console.error(`::error::${line}`);
  console.error('\nA state count past the budget is usually a rule admitted into a new position; see ' +
    '"Check STATE_COUNT" in .claude/skills/parse-gap/SKILL.md. If the growth is deliberate and ' +
    'measured, add the `grammar-size-ok` label to the pull request, or run with --allow-growth.');
  process.exitCode = 1;
}
