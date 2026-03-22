#!/usr/bin/env node

const { join } = require('path');
const { spawnTreeSitter, root } = require('./tree-sitter-cli.cjs');

const parsers = ['cfml', 'cfhtml', 'cfscript', 'cfquery'];

for (const dir of parsers) {
  console.log(`building ${dir}`);
  const r = spawnTreeSitter(['playground'], { cwd: join(root, dir) });
  if (r.status !== 0) {
    process.exit(r.status ?? 1);
  }
}
