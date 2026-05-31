#!/usr/bin/env node

const {join} = require('path');
const {readdirSync, writeFileSync, unlinkSync} = require('fs');
const {spawnTreeSitter, root} = require('./tree-sitter-cli.cjs');

const only = process.env.DIALECT;
const parsers = only ? [only] : ['cfml', 'cfscript', 'cfquery'];

// Create a temporary empty file for query validation (cross-platform)
const emptyFile = join(root, '.query-validate-tmp');
writeFileSync(emptyFile, '');

for (const dir of parsers) {
  console.log(`testing ${dir}`);
  try {
    const r = spawnTreeSitter(['test', '--update'], {cwd: join(root, dir)});
    if (r.status !== 0) {
      process.exitCode |= parsers.indexOf(dir) + 1;
    }
  } catch {
    process.exitCode |= parsers.indexOf(dir) + 1;
  }

  // Validate .scm query files
  const queriesDir = join(root, dir, 'queries');
  let scmFiles;
  try {
    scmFiles = readdirSync(queriesDir).filter(f => f.endsWith('.scm'));
  } catch {
    scmFiles = [];
  }
  if (scmFiles.length) {
    console.log(`  validating ${scmFiles.length} query files`);
  }
  for (const scm of scmFiles) {
    const scmPath = join(queriesDir, scm);
    try {
      const r = spawnTreeSitter(['query', '--quiet', scmPath, emptyFile], {cwd: join(root, dir), stdio: 'pipe'});
      if (r.status !== 0) {
        const err = r.stderr ? r.stderr.toString().trim() : '';
        const out = r.stdout ? r.stdout.toString().trim() : '';
        console.error(`  ✗ ${dir}/queries/${scm}`);
        if (err) console.error(`    ${err}`);
        if (out) console.error(`    ${out}`);
        process.exitCode |= 1;
      } else {
        console.log(`  ✓ ${dir}/queries/${scm}`);
      }
    } catch (e) {
      console.error(`  ✗ ${dir}/queries/${scm}: ${e.message}`);
      process.exitCode |= 1;
    }
  }
}

try { unlinkSync(emptyFile); } catch {}
