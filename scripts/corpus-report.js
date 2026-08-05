#!/usr/bin/env node

'use strict';

/**
 * Summarise a real-world corpus scan.
 *
 *   npm run corpus:report                  scan ./corpus and cluster the errors
 *   npm run corpus:report -- <dir>         scan another directory
 *   npm run corpus:report -- --from FILE   re-use a saved `npm run scan` output
 *
 * `scripts/scan.js` prints one line per ERROR/MISSING node; on a corpus of
 * thousands of files that is unreadable. This clusters those lines by the shape
 * of the offending source line, so a handful of grammar gaps stop looking like
 * thousands of unrelated failures.
 */

const fs = require('fs');
const path = require('path');
const {join} = path;
const {spawnSync} = require('child_process');

const root = join(__dirname, '..');
const args = process.argv.slice(2).filter((a) => a !== '--');

const fromIdx = args.indexOf('--from');
const fromFile = fromIdx !== -1 ? args[fromIdx + 1] : null;
const topIdx = args.indexOf('--top');
const top = topIdx !== -1 ? Number(args[topIdx + 1]) : 20;
const target = args.find((a, i) => !a.startsWith('--') && args[i - 1] !== '--from' && args[i - 1] !== '--top') ||
  join(root, 'corpus');

const scanRoot = path.resolve(target);

let output;
if (fromFile) {
  output = fs.readFileSync(fromFile, 'utf8');
} else {
  if (!fs.existsSync(target)) {
    console.error(`corpus-report: ${target} does not exist — run \`npm run corpus:fetch\` first.`);
    process.exit(1);
  }
  const r = spawnSync(process.execPath, [join(__dirname, 'scan.js'), target], {
    maxBuffer: 512 * 1024 * 1024,
  });
  output = r.stdout.toString();
}

const LINE = /^(.*?):(\d+):(\d+): \[(\w+)\] parse error(?: near "(.*)")?$/;

const sourceCache = new Map();
/**
 * Read a source file, memoised.
 *
 * @param {string} file
 * @returns {Array<string>}
 */
function sourceLines(file) {
  if (!sourceCache.has(file)) {
    try {
      sourceCache.set(file, fs.readFileSync(file, 'utf8').split('\n'));
    } catch {
      sourceCache.set(file, []);
    }
  }
  return sourceCache.get(file);
}

/**
 * Reduce a source line to a syntactic shape so similar failures cluster.
 *
 * @param {string} line
 * @returns {string}
 */
function shape(line) {
  return line
    .replace(/"[^"]*"|'[^']*'/g, 'STR')
    .replace(/\b\d+(\.\d+)?\b/g, 'NUM')
    .replace(/\b[A-Za-z_$][\w$]*\b/g, 'ID')
    .replace(/\s+/g, ' ')
    .trim()
    .slice(0, 80);
}

const byGrammar = new Map();
const byRepo = new Map();
const firstPerFile = new Map();
const clusters = new Map();
const errorFiles = new Set();
let total = 0;

for (const raw of output.split('\n')) {
  const m = LINE.exec(raw);
  if (!m) continue;
  const [, file, row, col, grammar] = m;
  total++;
  errorFiles.add(file);
  byGrammar.set(grammar, (byGrammar.get(grammar) || 0) + 1);
  const rel = path.relative(scanRoot, path.resolve(file));
  const repo = rel.split(path.sep)[0] || path.dirname(file);
  byRepo.set(repo, (byRepo.get(repo) || 0) + 1);

  // Errors cascade: after the first one the parser is off the rails, so cluster
  // only the first error per file+grammar.
  const key = `${file}\t${grammar}`;
  if (firstPerFile.has(key)) continue;
  firstPerFile.set(key, true);

  const src = (sourceLines(path.resolve(file))[Number(row) - 1] || '').trim();
  const clusterKey = `${grammar} | ${shape(src)}`;
  if (!clusters.has(clusterKey)) clusters.set(clusterKey, {count: 0, samples: []});
  const cluster = clusters.get(clusterKey);
  cluster.count++;
  if (cluster.samples.length < 3) {
    cluster.samples.push(`${file}:${row}:${col}  ${src.slice(0, 120)}`);
  }
}

if (total === 0) {
  console.log('No parse errors found.');
  process.exit(0);
}

console.log(`${total} parse errors across ${errorFiles.size} files\n`);

console.log('by grammar:');
for (const [k, v] of [...byGrammar].sort((a, b) => b[1] - a[1])) {
  console.log(`  ${String(v).padStart(7)}  ${k}`);
}

console.log('\nby repository:');
for (const [k, v] of [...byRepo].sort((a, b) => b[1] - a[1]).slice(0, 25)) {
  console.log(`  ${String(v).padStart(7)}  ${k}`);
}

console.log(`\ntop ${top} distinct failure sites (first error per file, clustered by source shape):`);
for (const [k, c] of [...clusters].sort((a, b) => b[1].count - a[1].count).slice(0, top)) {
  console.log(`\n  ${c.count}x  ${k}`);
  for (const s of c.samples) console.log(`      ${s}`);
}
