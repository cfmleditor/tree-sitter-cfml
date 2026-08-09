#!/usr/bin/env node

/**
 * Build the WASM `npm start` needs, for the dialect it will serve.
 *
 *   npm run prestart                 # cfml
 *   DIALECT=cfscript npm run prestart
 *
 * Note this is **not** the same output as `npm run docswasm`, despite both
 * running `tree-sitter build --wasm`. `tree-sitter playground` looks for
 * `tree-sitter-<dialect>.wasm` beside the grammar it is serving, while
 * `docswasm` writes to `docs/` for the static page published from there.
 *
 * It used to run from the repo root, which fails — there is no `grammar.js`
 * there, only in `cfml/`, `cfscript/` and `cfquery/`.
 */

const {join} = require('path');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

const dialect = process.env.DIALECT || 'cfml';
if (!['cfml', 'cfscript', 'cfquery'].includes(dialect)) {
  console.error(`prestart: unknown DIALECT "${dialect}" (expected cfml, cfscript or cfquery)`);
  process.exit(1);
}

console.log(`prestart: building ${dialect} wasm`);
const r = spawnTreeSitter(['build', '--wasm'], {cwd: join(root, dialect)});
process.exit(r.status === null ? 1 : r.status);
