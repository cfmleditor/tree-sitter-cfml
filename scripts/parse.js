#!/usr/bin/env node

const {execSync} = require('child_process');
const {join} = require('path');

for (const dir of ['cfml']) {
  console.log(`parsing ${dir}`);
  execSync('tree-sitter parse /Users/garethedwards/development/tassdev/tassweb/packages/**/*.cfc --quiet --time', {
    stdio: 'inherit',
    cwd: join(__dirname, '..', dir),
  });
}
