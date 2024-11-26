#!/usr/bin/env node

const {execSync} = require('child_process');
const {join} = require('path');

const parsers = ['cfml', 'cfhtml', 'cfscript'];

for (const dir of parsers) {
  console.log(`testing ${dir}`);
  try {
    execSync('tree-sitter test', {
      stdio: 'inherit',
      cwd: join(__dirname, '..', dir),
    });
  // eslint-disable-next-line no-unused-vars
  } catch (error) {
    process.exitCode |= parsers.indexOf(dir) + 1;
  }
}
