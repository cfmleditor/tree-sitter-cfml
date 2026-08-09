#!/usr/bin/env node

/**
 * Serve the tree-sitter playground for one grammar.
 *
 *   npm run playground                 # cfml
 *   DIALECT=cfscript npm run playground
 *
 * One grammar, not all three: `tree-sitter playground` starts a server and
 * blocks, so a loop over the dialects could only ever reach the first. It also
 * has to run from the dialect's own directory — from the repo root the CLI
 * cannot find a `grammar.js` and panics with "Failed to get Wasm filename".
 */

const {join} = require('path');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

const dialect = process.env.DIALECT || 'cfml';
if (!['cfml', 'cfscript', 'cfquery'].includes(dialect)) {
  console.error(`playground: unknown DIALECT "${dialect}" (expected cfml, cfscript or cfquery)`);
  process.exit(1);
}

console.log(`playground: serving ${dialect}`);
const r = spawnTreeSitter(['playground'], {cwd: join(root, dialect)});
process.exit(r.status === null ? 1 : r.status);
