#!/usr/bin/env node

const {execSync} = require('child_process');
const {join} = require('path');

for (const dir of ['cfml', 'cfhtml', 'cfscript', 'cfquery']) {
  console.log(`building ${dir}`);
  execSync('tree-sitter generate', {
    stdio: 'inherit',
    cwd: join(__dirname, '..', dir),
  });
}

console.log('building native addon');
execSync('node-gyp rebuild', {
  stdio: 'inherit',
  cwd: join(__dirname, '..'),
});
