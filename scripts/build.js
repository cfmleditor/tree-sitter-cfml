#!/usr/bin/env node

const { join } = require('path');
const { spawnTreeSitter, root } = require('./tree-sitter-cli.cjs');

for (const dir of ['cfml', 'cfhtml', 'cfscript', 'cfquery']) {
  console.log(`building ${dir}`);
  const r = spawnTreeSitter(['generate'], { cwd: join(root, dir) });
  if (r.status !== 0) {
    process.exit(r.status ?? 1);
  }
}

console.log('building native addon');
execSync('node-gyp rebuild', {
  stdio: 'inherit',
  cwd: join(__dirname, '..'),
});
