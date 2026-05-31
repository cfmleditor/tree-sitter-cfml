#!/usr/bin/env node

const {join} = require('path');
const {spawnSync} = require('child_process');
const {spawnTreeSitter, spawnTreeSitterAsync, root} = require('./tree-sitter-cli.cjs');

const only = process.env.DIALECT;
const dirs = only ? [only] : ['cfml', 'cfscript', 'cfquery'];

if (dirs.length === 1) {
  console.log(`building ${dirs[0]}`);
  const r = spawnTreeSitter(['generate'], {cwd: join(root, dirs[0])});
  if (r.status !== 0) {
    process.exit(r.status ?? 1);
  }
} else {
  Promise.all(
    dirs.map((dir) => {
      console.log(`building ${dir}`);
      return spawnTreeSitterAsync(['generate'], {cwd: join(root, dir)}).then(
        (code) => ({dir, code}),
      );
    }),
  ).then((results) => {
    const failed = results.filter((r) => r.code !== 0);
    if (failed.length > 0) {
      for (const f of failed) {
        console.error(`${f.dir}: generate failed (exit ${f.code})`);
      }
      process.exit(1);
    }
    // Rebuild native addon
    const rb = spawnSync('npx', ['node-gyp', 'rebuild'], {cwd: root, stdio: 'inherit'});
    if (rb.status !== 0) {
      console.error('native addon rebuild failed');
      process.exit(rb.status ?? 1);
    }
  });
}
