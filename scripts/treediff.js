#!/usr/bin/env node
/**
 * Compare TREE SHAPE between a baseline parser and this working tree's parser,
 * across the corpus.
 *
 * `npm run scan` reports ERROR / MISSING nodes, so it detects parses that go
 * missing. It cannot detect a parse that goes wrong: a change that turns a
 * correct tree into a different, equally error-free tree moves nothing in its
 * output, and a probe cannot see it either, because probes assert on error
 * nodes. Several real defects have been found only this way — a subscript
 * assignment read as a tag statement across 104 files, `{ a = 1 }` read as JS
 * destructuring across 2,698, and a `java { … }` opener swallowing a tag body.
 *
 *   npm run treediff -- ../base-worktree
 *   npm run treediff -- ../base-worktree corpus
 *
 * The baseline is a git worktree at the commit to compare against, with its
 * native addon built:
 *
 *   git worktree add ../base-worktree origin/master
 *   ln -s "$PWD/node_modules" ../base-worktree/node_modules
 *   (cd ../base-worktree && npx node-gyp rebuild)
 *
 * `node-gyp rebuild` compiles the committed parser sources under each dialect's `src/`; it does not
 * regenerate them, so the baseline is exactly what that commit ships.
 *
 * Only files the BASELINE parses cleanly are compared. A file that already
 * errors legitimately shifts where recovery gives up, so a shape change there
 * says nothing; a shape change in a file that parsed cleanly is unambiguous.
 *
 * BOTH sides must have their native addon built from their own committed
 * sources, or the comparison is meaningless. This is easy to get wrong and
 * produces convincing false positives: an addon left over from a `npm run
 * build` whose regenerated sources were later discarded will differ from the
 * baseline for reasons that have nothing to do with any grammar change. Two
 * files were once reported as "fixed" on that basis and were not. Rebuild both
 * sides with `npx node-gyp rebuild` — which compiles, and does not regenerate —
 * before trusting a result, and sanity-check the tool by pointing it at the
 * same commit it is running from: that must report zero changes.
 *
 * Local-only, like `npm run bench`: it needs the corpus and a second built
 * parser, which is too much for CI.
 */

const fs = require('fs');
const path = require('path');
const crypto = require('crypto');
const {spawnSync} = require('child_process');
const Parser = require('tree-sitter');
const head = require('..');

const baseDir = process.argv[2];
const {corpusDir, resolveScanTarget} = require('./corpus-dir');
const dir = process.argv[3] ? resolveScanTarget(process.argv[3]) : corpusDir();

if (!baseDir || baseDir.startsWith('--')) {
  console.error('usage: npm run treediff -- <baseline-worktree> [corpus-dir]');
  process.exit(1);
}

const addon = path.resolve(baseDir, 'build/Release/tree_sitter_cfml_binding.node');
if (!fs.existsSync(addon)) {
  console.error(`treediff: no built parser at ${addon}`);
  console.error('treediff: run `npx node-gyp rebuild` in the baseline worktree first');
  process.exit(1);
}
const base = require(addon);

/**
 * Which grammar owns a file, matching how the parsers are actually used.
 *
 * @param {string} file path being classified
 * @returns {string} grammar name
 */
function grammarFor(file) {
  return /\.(cfc|cfs)$/i.test(file) ? 'cfscript' : 'cfml';
}

/**
 * Every parseable file under a directory.
 *
 * @param {string} root directory to walk
 * @returns {Array<string>} file paths
 */
function collect(root) {
  const out = [];
  (function walk(d) {
    for (const e of fs.readdirSync(d, {withFileTypes: true})) {
      const f = path.join(d, e.name);
      if (e.isDirectory()) {
        if (e.name !== '.git') walk(f);
      } else if (/\.(cfm|cfml|cfc|cfs)$/i.test(e.name)) {
        out.push(f);
      }
    }
  })(root);
  return out;
}

const hash = (s) => crypto.createHash('sha1').update(s).digest('hex').slice(0, 16);
const parsers = {};
for (const name of ['cfml', 'cfscript']) {
  parsers[name] = {
    head: Object.assign(new Parser(), {}),
    base: Object.assign(new Parser(), {}),
  };
  parsers[name].head.setLanguage(head[name]);
  parsers[name].base.setLanguage(base[name]);
}

// Generated sources differing from HEAD means the built addon may not match
// what is committed, which is the most common way to get a false positive here.
const dirtyGenerated = spawnSync('git',
  ['status', '--porcelain', '--', '*/src/'], {encoding: 'utf8'}).stdout || '';
if (dirtyGenerated.trim()) {
  console.log('treediff: WARNING — generated sources differ from HEAD:');
  for (const line of dirtyGenerated.trim().split('\n')) console.log(`  ${line}`);
  console.log('treediff: the working-tree addon may not match these; `npx node-gyp rebuild` first.\n');
}

const files = collect(dir);
console.log(`treediff: ${files.length} files under ${dir}, baseline ${baseDir}\n`);

const stats = {};
const examples = {};
const delta = {};

for (const file of files) {
  let src;
  try {
    src = fs.readFileSync(file, 'utf8');
  } catch {
    continue;
  }
  if (src.length > 400000) continue;
  const name = grammarFor(file);
  const s = (stats[name] ||= {compared: 0, changed: 0, skipped: 0, newErrors: 0});

  let bt; let ht;
  try {
    bt = parsers[name].base.parse(src).rootNode;
    ht = parsers[name].head.parse(src).rootNode;
  } catch {
    continue;
  }
  // A file the baseline already fails on shifts its recovery shape for reasons
  // unrelated to the change, so it cannot be judged.
  if (bt.hasError) {
    s.skipped++;
    continue;
  }
  s.compared++;
  const a = bt.toString();
  const b = ht.toString();
  if (hash(a) === hash(b)) continue;

  s.changed++;
  if (ht.hasError) s.newErrors++;
  (examples[name] ||= []).push(file);

  // Node-type frequency delta. "104 files changed" is alarming and tells you
  // nothing; knowing every change moved `tag_statement` to `expression_statement`
  // and nothing moved back is what makes a result readable.
  const count = (str) => {
    const m = {};
    for (const tok of str.match(/\(([a-z_]+)/g) || []) {
      const t = tok.slice(1);
      m[t] = (m[t] || 0) + 1;
    }
    return m;
  };
  const ca = count(a); const cb = count(b);
  const d = (delta[name] ||= {});
  for (const k of new Set([...Object.keys(ca), ...Object.keys(cb)])) {
    const diff = (cb[k] || 0) - (ca[k] || 0);
    if (diff) d[k] = (d[k] || 0) + diff;
  }
}

let anyChange = false;
for (const name of ['cfml', 'cfscript']) {
  const s = stats[name];
  if (!s) continue;
  console.log(`${name.padEnd(9)} compared ${s.compared}   changed ${s.changed}   ` +
    `(skipped ${s.skipped} the baseline already failed)`);
  if (s.changed === 0) continue;
  anyChange = true;
  if (s.newErrors) {
    console.log(`  ${s.newErrors} of the changed files now contain an ERROR node — look at these first`);
  }
  const d = Object.entries(delta[name]).sort((x, y) => Math.abs(y[1]) - Math.abs(x[1]));
  console.log('  node-type delta (this tree minus baseline):');
  for (const [k, v] of d.slice(0, 10)) {
    console.log(`    ${(v > 0 ? '+' : '') + v}`.padEnd(12) + k);
  }
  for (const f of examples[name].slice(0, 10)) console.log(`    changed: ${f}`);
  if (examples[name].length > 10) {
    console.log(`    … and ${examples[name].length - 10} more`);
  }
  console.log('');
}

if (!anyChange) {
  console.log('\nNo tree shape changed. A refactor or an unreachable-rule removal should look like this.');
} else {
  console.log('Read the node-type delta before the file list. Changes that all move the same');
  console.log('direction are usually one fix; a mixed delta usually means two things happened.');
}
