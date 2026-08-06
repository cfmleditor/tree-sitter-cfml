#!/usr/bin/env node

'use strict';

/**
 * Parser throughput benchmark.
 *
 *   npm run bench -- corpus --out before.json
 *   # ...change the grammar, npm run build...
 *   npm run bench -- corpus --baseline before.json
 *
 * Answers one question: did a grammar or scanner change make parsing slower?
 *
 * Why this exists rather than timing `npm run scan`: `scan.js` walks every tree
 * collecting ERROR nodes and re-parses injected regions that it locates *by
 * parsing*. Both costs move when a grammar change moves the error count, so a
 * change that fixes parse errors looks dramatically slower or faster for
 * reasons that have nothing to do with parser speed. Measuring that way once
 * produced a confident "+65% regression" that did not exist.
 *
 * What this does instead:
 *
 * - **Input selection never depends on the parser.** Injected `<cfscript>` and
 *   `<cfquery>` bodies are found by regex, so the byte count fed to each
 *   grammar is identical before and after a change.
 * - **Files are read and sliced up front**, outside the timed region, so disk
 *   and string work do not land in the measurement.
 * - **Only `parser.parse()` is timed.** No tree walking, no node counting.
 * - **Best of N reps, not the mean.** A benchmark on a shared runner competes
 *   with other processes; that noise only ever makes a run slower, so the
 *   fastest rep is the closest to the parser's real cost. The spread across
 *   reps is reported so you can see whether the machine was quiet.
 */

const fs = require('fs');
const path = require('path');
const {join, relative} = path;

const root = join(__dirname, '..');

let Parser; let languages;
try {
  Parser = require('tree-sitter');
  languages = require(root);
} catch (e) {
  console.error('bench: node bindings unavailable (run `npm install` first)');
  console.error(`  ${e.message}`);
  process.exit(1);
}

const args = process.argv.slice(2);
const dir = args.find((a) => !a.startsWith('--'));
const flag = (name, fallback) => {
  const i = args.indexOf(`--${name}`);
  return i === -1 ? fallback : args[i + 1];
};

if (!dir) {
  console.error('Usage: npm run bench -- <dir> [--reps 5] [--out file.json] [--baseline file.json]');
  console.error('  <dir>  a tree of .cfm/.cfc/.cfml/.cfs files, e.g. `corpus` after `npm run corpus:fetch`');
  process.exit(1);
}

const reps = Number(flag('reps', 5));
const outFile = flag('out', null);
const baselineFile = flag('baseline', null);

// Anything below this is machine noise, not a code change. Calibrated by
// running the same commit against itself: repeated best-of-5 runs on an idle
// machine land within about 2%.
const NOISE_FLOOR_PCT = 3;

const TEMPLATE_EXT = new Set(['.cfm', '.cfml', '.cfc']);
const SCRIPT_EXT = new Set(['.cfs']);

// Deliberately regex, not parse-driven: the whole point is that the workload
// handed to each grammar must not shift when the grammar changes. These match
// what the injection queries target closely enough for a throughput number, and
// unlike the real injections they cost the same on every run.
const SCRIPT_BLOCK = /<cfscript\b[^>]*>([\s\S]*?)<\/cfscript\s*>/gi;
const QUERY_BLOCK = /<cfquery\b[^>]*>([\s\S]*?)<\/cfquery\s*>/gi;

// A script-syntax `.cfc` (`component { … }`) is a cfscript file in all but
// extension, and there are far more of those in real projects than there are
// `<cfscript>` blocks. Missing them would leave the cfscript number measuring a
// tenth of its real workload. Detected by stripping leading whitespace and
// comments and looking at the first keyword — deterministic, and crucially not
// dependent on whether the file parses.
const LEADING_TRIVIA = /^(?:\s|\/\*[\s\S]*?\*\/|\/\/[^\n]*|<!---[\s\S]*?--->)*/;
const SCRIPT_COMPONENT_HEAD = /^(?:abstract|final|component|interface|import|private|public|package|remote|static)\b/i;

/**
 * Recursively collect parseable files under a directory.
 *
 * @param {string} start
 * @returns {Array<string>}
 */
function collect(start) {
  const out = [];
  const walk = (d) => {
    let entries;
    try {
      entries = fs.readdirSync(d, {withFileTypes: true});
    } catch {
      return;
    }
    for (const entry of entries) {
      const full = join(d, entry.name);
      if (entry.isDirectory()) {
        if (entry.name === '.git' || entry.name === 'node_modules') continue;
        walk(full);
      } else if (TEMPLATE_EXT.has(path.extname(entry.name).toLowerCase()) ||
                 SCRIPT_EXT.has(path.extname(entry.name).toLowerCase())) {
        out.push(full);
      }
    }
  };
  walk(start);
  // Sorted so two runs feed the parsers in the same order — parse order can
  // matter for allocator behaviour, and a stable order keeps runs comparable.
  return out.sort();
}

/**
 * Build the per-grammar input lists. Runs once, outside the timed region.
 *
 * @param {Array<string>} files
 * @returns {{cfml: Array<string>, cfscript: Array<string>, cfquery: Array<string>}}
 */
function buildWorkload(files) {
  const work = {cfml: [], cfscript: [], cfquery: []};
  for (const file of files) {
    let text;
    try {
      text = fs.readFileSync(file, 'utf8');
    } catch {
      continue;
    }
    if (SCRIPT_EXT.has(path.extname(file).toLowerCase())) {
      work.cfscript.push(text);
      continue;
    }
    // Templates go to cfml whatever their syntax — that is what an editor opens
    // them with, and the injection is cfml's job.
    work.cfml.push(text);
    if (SCRIPT_COMPONENT_HEAD.test(text.replace(LEADING_TRIVIA, ''))) {
      work.cfscript.push(text);
    }
    for (const m of text.matchAll(SCRIPT_BLOCK)) {
      if (m[1].trim()) work.cfscript.push(m[1]);
    }
    for (const m of text.matchAll(QUERY_BLOCK)) {
      if (m[1].trim()) work.cfquery.push(m[1]);
    }
  }
  return work;
}

/**
 * Time one full pass over one grammar's inputs.
 *
 * @param {object} parser
 * @param {Array<string>} inputs
 * @returns {number} milliseconds
 */
function timePass(parser, inputs) {
  const started = process.hrtime.bigint();
  for (const text of inputs) {
    parser.parse(text);
  }
  return Number(process.hrtime.bigint() - started) / 1e6;
}

console.log(`bench: collecting from ${dir}`);
const files = collect(dir);
if (files.length === 0) {
  console.error(`bench: no .cfm/.cfml/.cfc/.cfs files under ${dir}`);
  process.exit(1);
}
const work = buildWorkload(files);

const parsers = {};
for (const name of ['cfml', 'cfscript', 'cfquery']) {
  parsers[name] = new Parser();
  parsers[name].setLanguage(languages[name]);
}

const bytes = {};
for (const name of Object.keys(work)) {
  bytes[name] = work[name].reduce((n, s) => n + Buffer.byteLength(s), 0);
}

console.log(`bench: ${files.length} files -> ` +
  Object.keys(work).map((n) => `${n} ${work[n].length} inputs / ${(bytes[n] / 1e6).toFixed(1)} MB`).join(', '));
console.log(`bench: ${reps} timed reps after a warm-up (reporting the fastest)\n`);

const result = {reps, files: files.length, grammars: {}};

for (const name of ['cfml', 'cfscript', 'cfquery']) {
  if (work[name].length === 0) continue;
  timePass(parsers[name], work[name]); // warm-up: JIT, allocator, page cache
  const times = [];
  for (let i = 0; i < reps; i++) {
    times.push(timePass(parsers[name], work[name]));
  }
  const best = Math.min(...times);
  const worst = Math.max(...times);
  result.grammars[name] = {
    ms: Number(best.toFixed(1)),
    spreadPct: Number(((worst - best) / best * 100).toFixed(1)),
    bytes: bytes[name],
    bytesPerMs: Math.round(bytes[name] / best),
    inputs: work[name].length,
  };
  const r = result.grammars[name];
  console.log(`  ${name.padEnd(9)} ${String(r.ms).padStart(9)} ms   ` +
    `${String(r.bytesPerMs).padStart(7)} bytes/ms   (spread across reps ${r.spreadPct}%)`);
}

// A wide spread means the machine was busy, and a comparison against it can
// only detect regressions bigger than the noise. Say so rather than quietly
// widening the threshold, because a masked regression looks exactly like a
// clean result.
const noisiest = Math.max(...Object.values(result.grammars).map((r) => r.spreadPct));
if (noisiest > 10) {
  console.log(`\nnote: reps varied by up to ${noisiest}% — this machine is busy. Anything`);
  console.log(`      smaller than that is undetectable here; raise --reps or close other work.`);
}

if (baselineFile) {
  const base = JSON.parse(fs.readFileSync(baselineFile, 'utf8'));
  console.log(`\nvs ${relative(process.cwd(), baselineFile)}:\n`);
  let regressed = false;
  for (const name of Object.keys(result.grammars)) {
    const b = base.grammars?.[name];
    if (!b) continue;
    const now = result.grammars[name];
    const delta = (now.ms - b.ms) / b.ms * 100;
    // A delta smaller than the noise floor, or smaller than this run's own
    // spread across reps, is not evidence of anything.
    const meaningful = Math.abs(delta) > NOISE_FLOOR_PCT && Math.abs(delta) > now.spreadPct;
    const verdict = !meaningful ? 'no change' : delta > 0 ? 'SLOWER' : 'faster';
    if (meaningful && delta > 0) regressed = true;
    console.log(`  ${name.padEnd(9)} ${String(b.ms).padStart(9)} -> ${String(now.ms).padStart(9)} ms   ` +
      `${delta >= 0 ? '+' : ''}${delta.toFixed(1)}%   ${verdict}`);
  }
  if (regressed) {
    console.log('\nA slowdown above the noise floor. Re-run both sides once more before believing it —');
    console.log('and check the input counts above match, since a differing workload invalidates the comparison.');
    process.exitCode = 1;
  }
}

if (outFile) {
  fs.writeFileSync(outFile, `${JSON.stringify(result, null, 2)}\n`);
  console.log(`\nwrote ${relative(process.cwd(), outFile)}`);
}
