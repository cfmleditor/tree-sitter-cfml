#!/usr/bin/env node

const {execSync} = require('child_process');
const {join} = require('path');

for (const dir of ['cfml', 'cfhtml', 'cfscript']) {
  console.log(`building ${dir}`);
  execSync('tree-sitter playground', {
    stdio: 'inherit',
    cwd: join(__dirname, '..', dir),
  });
}
