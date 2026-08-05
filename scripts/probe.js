#!/usr/bin/env node

'use strict';

/**
 * Real-world construct probes.
 *
 * Each file under `test/probes/` is a minimal reduction of a construct found in
 * public CFML code (see `CORPUS.md`). `test/probes/expected.json`
 * records whether the grammars currently parse it cleanly.
 *
 *   npm run probe            # report + fail on any drift from expected.json
 *   npm run probe -- --update  # rewrite expected.json to current behaviour
 *
 * A probe flipping `pass` -> `fail` is a regression. A probe flipping
 * `fail` -> `pass` is a fix: re-run with `--update` and commit the new file.
 */

const fs = require('fs');
const path = require('path');
const {join, relative} = path;

const root = join(__dirname, '..');
const probeDir = join(root, 'test', 'probes');
const expectedFile = join(probeDir, 'expected.json');
const update = process.argv.includes('--update');

let Parser; let languages;
try {
  Parser = require('tree-sitter');
  languages = require(root);
} catch (e) {
  console.error('probe: node bindings unavailable (run `npm install` first)');
  console.error(`  ${e.message}`);
  process.exit(1);
}

const parsers = {};
for (const name of ['cfml', 'cfscript', 'cfquery']) {
  parsers[name] = new Parser();
  parsers[name].setLanguage(languages[name]);
}

/**
 * Collect ERROR / MISSING positions in a tree.
 *
 * @param {object} node
 * @param {Array<string>} out
 * @param {string} prefix
 * @returns {Array<string>}
 */
function collectErrors(node, out, prefix) {
  if (node.type === 'ERROR' || node.isMissing) {
    out.push(`${prefix}${node.startPosition.row + 1}:${node.startPosition.column + 1}`);
  }
  for (let i = 0; i < node.childCount; i++) {
    collectErrors(node.child(i), out, prefix);
  }
  return out;
}

/**
 * Collect nodes of a given type.
 *
 * @param {object} node
 * @param {string} type
 * @param {Array<object>} out
 * @returns {Array<object>}
 */
function collectNodes(node, type, out) {
  if (node.type === type) out.push(node);
  for (let i = 0; i < node.childCount; i++) {
    collectNodes(node.child(i), type, out);
  }
  return out;
}

/**
 * Parse one probe file the way an editor would: the outer grammar plus the
 * injections `injections.scm` declares.
 *
 * @param {string} file
 * @returns {Array<string>} error locations, empty when the file parses cleanly
 */
function probe(file) {
  const source = fs.readFileSync(file, 'utf8');
  const ext = path.extname(file).toLowerCase();

  if (ext === '.cfs') {
    return collectErrors(parsers.cfscript.parse(source).rootNode, [], '');
  }

  const tree = parsers.cfml.parse(source);
  const errors = collectErrors(tree.rootNode, [], '');

  for (const type of ['cf_script_content', 'cf_component_content']) {
    for (const node of collectNodes(tree.rootNode, type, [])) {
      const sub = parsers.cfscript.parse(node.text);
      errors.push(...collectErrors(sub.rootNode, [], 'cfscript@'));
    }
  }
  for (const node of collectNodes(tree.rootNode, 'cf_query_content', [])) {
    const sub = parsers.cfquery.parse(node.text);
    errors.push(...collectErrors(sub.rootNode, [], 'cfquery@'));
  }

  return errors;
}

/**
 * Recursively list probe files.
 *
 * @param {string} dir
 * @returns {Array<string>}
 */
function collectProbes(dir) {
  const out = [];
  for (const entry of fs.readdirSync(dir, {withFileTypes: true}).sort((a, b) => a.name.localeCompare(b.name))) {
    const full = join(dir, entry.name);
    if (entry.isDirectory()) {
      out.push(...collectProbes(full));
    } else if (/\.(cfc|cfm|cfml|cfs)$/i.test(entry.name)) {
      out.push(full);
    }
  }
  return out;
}

const expected = fs.existsSync(expectedFile) ?
  JSON.parse(fs.readFileSync(expectedFile, 'utf8')) :
  {probes: {}};

const files = collectProbes(probeDir);
const actual = {};
const drift = [];

const width = Math.max(...files.map((f) => relative(probeDir, f).length));

for (const file of files) {
  const key = relative(probeDir, file).split(path.sep).join('/');
  const errors = probe(file);
  const status = errors.length === 0 ? 'pass' : 'fail';
  actual[key] = status;

  const want = expected.probes[key];
  const detail = errors.length ? `${errors.length} error(s) @ ${errors.slice(0, 3).join(', ')}` : '';

  if (want === undefined) {
    console.log(`  ?  ${key.padEnd(width)}  ${status}  (new probe) ${detail}`);
    drift.push([key, '(new)', status]);
  } else if (want === status) {
    const mark = status === 'pass' ? '✓' : '•';
    console.log(`  ${mark}  ${key.padEnd(width)}  ${status}  ${status === 'fail' ? `known gap: ${detail}` : ''}`);
  } else {
    console.log(`  ✗  ${key.padEnd(width)}  ${status}  expected ${want}  ${detail}`);
    drift.push([key, want, status]);
  }
}

const passing = Object.values(actual).filter((s) => s === 'pass').length;
console.log(`\n${passing}/${files.length} probes parse cleanly`);

if (update) {
  fs.writeFileSync(expectedFile, JSON.stringify({
    comment: expected.comment,
    probes: actual,
  }, null, 2) + '\n');
  console.log(`updated ${relative(root, expectedFile)}`);
} else if (drift.length) {
  console.error(`\n${drift.length} probe(s) drifted from expected.json:`);
  for (const [key, want, got] of drift) {
    console.error(`  ${key}: expected ${want}, got ${got}`);
  }
  console.error('\nIf this is a deliberate grammar change, re-run with `--update`.');
  process.exitCode = 1;
}
