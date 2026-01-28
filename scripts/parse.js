#!/usr/bin/env node

const {execSync} = require('child_process');
const {join, resolve} = require('path');

const file = process.argv[2];

for (const dir of ['cfml']) {
  console.log(`parsing ${dir}`);
  const cmd = file 
    ? `tree-sitter parse ${resolve(process.cwd(), file)}` 
    : 'tree-sitter parse --quiet --time';
  execSync(cmd, {
    stdio: 'inherit',
    cwd: join(__dirname, '..', dir),
  });
}
