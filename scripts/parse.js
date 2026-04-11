#!/usr/bin/env node

const {join, resolve} = require('path');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

const file = process.argv[2];
const parsers = ['cfml', 'cfhtml', 'cfscript', 'cfquery'];

for (const dir of parsers) {
  console.log(`parsing ${dir}`);
  const argv = file ?
    ['parse', resolve(process.cwd(), file)] :
    ['parse', '--quiet', '--time'];
  const r = spawnTreeSitter(argv, {cwd: join(root, dir)});
  if (r.status !== 0) {
    process.exit(r.status ?? 1);
  }
}
