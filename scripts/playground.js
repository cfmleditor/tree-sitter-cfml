#!/usr/bin/env node

const {execSync} = require('child_process');
const {join} = require('path');

const parsers = ['cfml', 'cfhtml', 'cfscript', 'cfquery'];

for (const dir of parsers) {
  console.log(`building ${dir}`);
  execSync('tree-sitter playground', {
    stdio: 'inherit',
    cwd: join(__dirname, '..', dir),
  });
}
