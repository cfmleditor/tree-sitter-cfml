#!/usr/bin/env node
'use strict';

const fs = require('fs');
const path = require('path');
const {spawnSync} = require('child_process');
const Parser = require('tree-sitter');
const {cfml, cfscript, cfquery} = require('..');

const dir = process.argv[2];
if (!dir) {
  console.error('Usage: node scripts/scan.js <path> [--language cfml|cfscript|cfquery]');
  console.error('       [--isolate] [--expect <file>] [--update]');
  process.exit(1);
}

const langIdx = process.argv.indexOf('--language');
const forcedLang = langIdx !== -1 ? process.argv[langIdx + 1] : null;

// A parse that crashes the process takes the whole scan with it, so a corpus
// containing one is unscannable in-process. `--isolate` parses each file in a
// child, turning a fatal signal into a reported result. It costs a process per
// file, so it is for small directories (`examples/`), not the 14k-file corpus.
const isolate = process.argv.includes('--isolate');
const noSummary = process.argv.includes('--no-summary');
const update = process.argv.includes('--update');
const expectIdx = process.argv.indexOf('--expect');
const expectFile = expectIdx !== -1 ? process.argv[expectIdx + 1] : null;

// A crash caused by reading past a heap block is probabilistic — whether it
// faults depends on what is mapped after the block, so the same input can pass
// and fail across runs. Classifying such a file from one attempt makes the
// check flaky in both directions, so `--retries` attempts it repeatedly and
// treats "crashed at least once" as the answer. Proving one fixed therefore
// means every attempt came back clean.
const retriesIdx = process.argv.indexOf('--retries');
const retries = retriesIdx !== -1 ? Math.max(1, +process.argv[retriesIdx + 1]) : 1;

const EXTENSIONS = new Set(['.cfm', '.cfml', '.cfc', '.cfs']);

const parserCfml = new Parser();
parserCfml.setLanguage(cfml);

const parserCfscript = new Parser();
parserCfscript.setLanguage(cfscript);

const parserCfquery = new Parser();
parserCfquery.setLanguage(cfquery);

let totalFiles = 0;
let filesWithErrors = 0;
let totalErrors = 0;
let totalCrashes = 0;

/**
 * Recursively collect files with CFML extensions.
 *
 * @param {string} dirPath
 */
function collectFiles(dirPath) {
  const files = [];
  const entries = fs.readdirSync(dirPath, {withFileTypes: true});
  for (const entry of entries) {
    const full = path.join(dirPath, entry.name);
    if (entry.isDirectory()) {
      if (entry.name === 'node_modules' || entry.name === '.git') continue;
      files.push(...collectFiles(full));
    } else if (EXTENSIONS.has(path.extname(entry.name).toLowerCase())) {
      files.push(full);
    }
  }
  return files;
}

/**
 * Recursively find ERROR and MISSING nodes in a parse tree.
 *
 * @param {object} node
 * @param {Array} errors
 */
function findErrors(node, errors) {
  if (node.type === 'ERROR' || node.isMissing) {
    errors.push({
      row: node.startPosition.row + 1,
      col: node.startPosition.column + 1,
      text: node.type === 'ERROR' ?
        node.text.replace(/\n/g, '\\n').slice(0, 60) :
        `missing ${node.type}`,
    });
  }
  for (let i = 0; i < node.childCount; i++) {
    findErrors(node.child(i), errors);
  }
}

/**
 * Print parse errors for a file.
 *
 * @param {string} filePath
 * @param {string} grammar
 * @param {Array} errors
 */
function reportErrors(filePath, grammar, errors) {
  const rel = path.relative(process.cwd(), filePath);
  for (const err of errors) {
    const near = err.text.length > 0 ? ` near "${err.text}"` : '';
    console.log(`${rel}:${err.row}:${err.col}: [${grammar}] parse error${near}`);
    totalErrors++;
  }
}

/**
 * Find all nodes of a given type in the tree.
 *
 * @param {object} node
 * @param {string} type
 * @param {Array} results
 */
function findInjectionNodes(node, type, results) {
  if (node.type === type) {
    results.push(node);
  }
  for (let i = 0; i < node.childCount; i++) {
    findInjectionNodes(node.child(i), type, results);
  }
}

/**
 * Parse injected content with a sub-grammar and report errors.
 *
 * @param {object} parser
 * @param {string} grammar
 * @param {string} sourceText
 * @param {number} startRow
 * @param {string} filePath
 */
function parseInjection(parser, grammar, sourceText, startRow, filePath) {
  const tree = parser.parse(sourceText);
  const errors = [];
  findErrors(tree.rootNode, errors);
  // Adjust row numbers to file-relative positions
  for (const err of errors) {
    err.row += startRow;
  }
  if (errors.length > 0) {
    reportErrors(filePath, grammar, errors);
    return true;
  }
  return false;
}

/**
 * Parse a single file and its injections, reporting any errors.
 *
 * @param {string} filePath
 */
function scanFile(filePath) {
  totalFiles++;
  const buf = fs.readFileSync(filePath);
  if (buf.includes(0)) return; // skip binary files
  const source = buf.toString('utf8');
  const ext = path.extname(filePath).toLowerCase();
  const lang = forcedLang || (ext === '.cfs' ? 'cfscript' : 'cfml');
  let hadErrors = false;

  if (lang === 'cfscript') {
    const tree = parserCfscript.parse(source);
    const errors = [];
    findErrors(tree.rootNode, errors);
    if (errors.length > 0) {
      reportErrors(filePath, 'cfscript', errors);
      hadErrors = true;
    }
  } else if (lang === 'cfquery') {
    const tree = parserCfquery.parse(source);
    const errors = [];
    findErrors(tree.rootNode, errors);
    if (errors.length > 0) {
      reportErrors(filePath, 'cfquery', errors);
      hadErrors = true;
    }
  } else {
    // .cfm, .cfml, .cfc — parse with cfml grammar
    const tree = parserCfml.parse(source);
    const errors = [];
    findErrors(tree.rootNode, errors);
    if (errors.length > 0) {
      reportErrors(filePath, 'cfml', errors);
      hadErrors = true;
    }

    // Injection: cf_script_content → cfscript
    const scriptNodes = [];
    findInjectionNodes(tree.rootNode, 'cf_script_content', scriptNodes);
    for (const node of scriptNodes) {
      // `|| hadErrors`, not plain assignment: a later clean injection must not
      // clear an error already found in the outer parse or an earlier region.
      hadErrors = parseInjection(
        parserCfscript, 'cfscript',
        node.text, node.startPosition.row,
        filePath,
      ) || hadErrors;
    }

    // Injection: cf_component_content → cfscript (component files)
    const componentNodes = [];
    findInjectionNodes(tree.rootNode, 'cf_component_content', componentNodes);
    for (const node of componentNodes) {
      // `|| hadErrors`, not plain assignment: a later clean injection must not
      // clear an error already found in the outer parse or an earlier region.
      hadErrors = parseInjection(
        parserCfscript, 'cfscript',
        node.text, node.startPosition.row,
        filePath,
      ) || hadErrors;
    }

    // Injection: cf_query_content → cfquery
    const queryNodes = [];
    findInjectionNodes(tree.rootNode, 'cf_query_content', queryNodes);
    for (const node of queryNodes) {
      hadErrors = parseInjection(
        parserCfquery, 'cfquery',
        node.text, node.startPosition.row,
        filePath,
      ) || hadErrors;
    }
  }

  if (hadErrors) filesWithErrors++;
}

/**
 * Scan each file in its own child process, so a parse that kills the process
 * is reported rather than ending the scan.
 *
 * @param {Array<string>} files
 * @returns {object} map of relative path to `clean`, `errors:<n>` or `crash`
 */
function scanIsolated(files) {
  const status = {};
  for (const file of files) {
    const argv = [__filename, file, '--no-summary'];
    if (forcedLang) argv.push('--language', forcedLang);
    const rel = path.relative(process.cwd(), file);
    totalFiles++;

    let run = null;
    let crashedAs = null;
    for (let attempt = 0; attempt < retries; attempt++) {
      run = spawnSync(process.execPath, argv, {
        encoding: 'utf8',
        maxBuffer: 64 * 1024 * 1024,
      });
      // The child exits 0 when clean and 1 when it found parse errors. Anything
      // else means it died rather than reporting: a signal on POSIX, a large
      // status (0xC0000005 and friends) on Windows, where a fault is not a
      // signal. The recorded status is the bare word `crash` — which signal or
      // code it was varies by platform and allocator, and pinning that would
      // make the baseline drift for reasons that are not about the parser.
      if (run.signal || (run.status !== 0 && run.status !== 1)) {
        crashedAs = run.signal || `exit ${run.status}`;
        break;
      }
    }

    if (crashedAs) {
      const of = retries > 1 ? ` (1 of up to ${retries} attempts)` : '';
      console.log(`${rel}: [scan] parser crashed (${crashedAs})${of}`);
      status[rel] = 'crash';
      totalCrashes++;
      continue;
    }

    const out = (run.stdout || '').trimEnd();
    if (out) process.stdout.write(`${out}\n`);
    const count = out ? out.split('\n').length : 0;
    if (count > 0) {
      totalErrors += count;
      filesWithErrors++;
      status[rel] = `errors:${count}`;
    } else {
      status[rel] = 'clean';
    }
  }
  return status;
}

/**
 * Compare an isolated scan against a recorded baseline, reporting drift in
 * either direction — a new crash and a fixed one are both worth failing on.
 *
 * @param {object} status
 * @returns {boolean} true when the scan matches the baseline
 */
function checkExpected(status) {
  const file = path.resolve(expectFile);
  if (update) {
    // A `flaky` entry is a human judgement that this file cannot be classified
    // reliably, so an update must not overwrite it with whatever this one run
    // happened to see. Clear it by hand to start asserting the file again.
    const prior = fs.existsSync(file) ?
      (JSON.parse(fs.readFileSync(file, 'utf8')).files || {}) : {};
    const merged = {};
    for (const [key, value] of Object.entries(status)) {
      merged[key] = prior[key] === 'flaky' ? 'flaky' : value;
    }
    const payload = {
      comment: 'Scan status of each file under `examples/`. `clean` = no ' +
        'ERROR/MISSING nodes, `errors:<n>` = that many, `crash` = the parser ' +
        'died, `flaky` = it dies intermittently and is deliberately not ' +
        'asserted (only "did not become ordinary parse errors" is). ' +
        'Regenerate with `npm run scan:examples -- --update`.',
      files: merged,
    };
    fs.writeFileSync(file, `${JSON.stringify(payload, null, 2)}\n`);
    console.log(`updated ${path.relative(process.cwd(), file)}`);
    return true;
  }

  const expected = JSON.parse(fs.readFileSync(file, 'utf8')).files || {};
  const drift = [];
  for (const key of new Set([...Object.keys(expected), ...Object.keys(status)])) {
    const was = expected[key] ?? '(new file)';
    const now = status[key] ?? '(removed)';
    // `flaky` asserts nothing about crash-vs-clean, only that the file did not
    // start producing ordinary parse errors. Some crashes are intermittent in
    // a way retrying cannot pin down — outcomes are not independent between
    // processes — and an assertion that reddens CI at random is worse than one
    // that says plainly it is not asserting.
    if (was === 'flaky') {
      if (now !== 'crash' && now !== 'clean') {
        drift.push(`  ${key}: expected flaky (crash or clean), got ${now}`);
      }
      continue;
    }
    if (was !== now) drift.push(`  ${key}: expected ${was}, got ${now}`);
  }
  if (drift.length === 0) {
    console.log(`matches ${path.relative(process.cwd(), file)}`);
    return true;
  }
  console.log(`\n${drift.length} file(s) drifted from ${path.relative(process.cwd(), file)}:`);
  console.log(drift.join('\n'));
  console.log('\nIf this is a deliberate change, re-run with `-- --update`.');
  return false;
}

// Main
const resolvedDir = path.resolve(dir);
const stat = fs.statSync(resolvedDir);
const files = stat.isFile() ? [resolvedDir] : collectFiles(resolvedDir).sort();

const startTime = performance.now();

let inSync = true;
if (isolate) {
  const status = scanIsolated(files);
  if (expectFile) inSync = checkExpected(status);
} else {
  for (const file of files) {
    scanFile(file);
  }
}

const elapsed = ((performance.now() - startTime) / 1000).toFixed(2);

if (!noSummary) {
  console.log('');
  const crashed = totalCrashes > 0 ?
    `, and crashed the parser on ${totalCrashes} file(s)` : '';
  if (totalErrors === 0) {
    console.log(`No parse errors found in ${totalFiles} files${crashed}. (${elapsed}s)`);
  } else {
    console.log(`Found ${totalErrors} parse error(s) across ${filesWithErrors} file(s)${crashed} (${totalFiles} files scanned, ${elapsed}s).`);
  }
}

// `process.exit()` discards whatever is still buffered when stdout is a pipe,
// which silently truncated `npm run scan <dir> | ...` on large corpora. Set the
// exit code instead and let Node drain stdout before exiting.
// With `--expect`, matching the baseline is success even when it records
// failures: the recorded state is the assertion, exactly as `npm run probe`
// treats `test/probes/expected.json`.
process.exitCode = expectFile ?
  (inSync ? 0 : 1) :
  (totalErrors > 0 || totalCrashes > 0 ? 1 : 0);
