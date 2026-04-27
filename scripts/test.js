#!/usr/bin/env node

const {join} = require('path');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

const only = process.env.DIALECT;
const parsers = only ? [only] : ['cfml', 'cfhtml', 'cfscript', 'cfquery'];

for (const dir of parsers) {
  console.log(`testing ${dir}`);
  try {
    const r = spawnTreeSitter(['test', '--update'], {cwd: join(root, dir)});
    if (r.status !== 0) {
      process.exitCode |= parsers.indexOf(dir) + 1;
    }
  } catch {
    process.exitCode |= parsers.indexOf(dir) + 1;
  }
}
