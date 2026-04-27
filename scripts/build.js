#!/usr/bin/env node

const {join} = require('path');
const {spawnTreeSitter, spawnTreeSitterAsync, root} = require('./tree-sitter-cli.cjs');

const only = process.env.DIALECT;
const dirs = only ? [only] : ['cfml', 'cfhtml', 'cfscript', 'cfquery'];

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
  });
}
