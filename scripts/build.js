#!/usr/bin/env node

const {join} = require('path');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

const only = process.env.DIALECT;
for (const dir of (only ? [only] : ['cfml', 'cfhtml', 'cfscript', 'cfquery'])) {
  console.log(`building ${dir}`);
  const r = spawnTreeSitter(['generate'], {cwd: join(root, dir)});
  if (r.status !== 0) {
    process.exit(r.status ?? 1);
  }
}
