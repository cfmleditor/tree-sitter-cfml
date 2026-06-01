#!/usr/bin/env node
'use strict';

const fs = require('fs');
const path = require('path');
const Parser = require('tree-sitter');
const {cfml, cfscript, cfquery} = require('..');

const dir = process.argv[2];
if (!dir) {
  console.error('Usage: node scripts/scan.js <directory>');
  process.exit(1);
}

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
  }
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
  let hadErrors = false;

  if (ext === '.cfs') {
    // Pure cfscript
    const tree = parserCfscript.parse(source);
    const errors = [];
    findErrors(tree.rootNode, errors);
    if (errors.length > 0) {
      reportErrors(filePath, 'cfscript', errors);
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
      parseInjection(
        parserCfscript, 'cfscript',
        node.text, node.startPosition.row,
        filePath,
      );
    }

    // Injection: cf_component_content → cfscript (component files)
    const componentNodes = [];
    findInjectionNodes(tree.rootNode, 'cf_component_content', componentNodes);
    for (const node of componentNodes) {
      parseInjection(
        parserCfscript, 'cfscript',
        node.text, node.startPosition.row,
        filePath,
      );
    }

    // Injection: cf_query_content → cfquery
    const queryNodes = [];
    findInjectionNodes(tree.rootNode, 'cf_query_content', queryNodes);
    for (const node of queryNodes) {
      parseInjection(
        parserCfquery, 'cfquery',
        node.text, node.startPosition.row,
        filePath,
      );
    }
  }

  if (hadErrors) filesWithErrors++;
}

// Main
const resolvedDir = path.resolve(dir);
const files = collectFiles(resolvedDir).sort();

const startTime = performance.now();

for (const file of files) {
  scanFile(file);
}

const elapsed = ((performance.now() - startTime) / 1000).toFixed(2);

console.log('');
if (totalErrors === 0) {
  console.log(`No parse errors found in ${totalFiles} files. (${elapsed}s)`);
} else {
  console.log(`Found ${totalErrors} parse error(s) across ${filesWithErrors} file(s) (${totalFiles} files scanned, ${elapsed}s).`);
}

process.exit(totalErrors > 0 ? 1 : 0);
