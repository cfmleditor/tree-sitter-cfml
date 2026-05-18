#!/usr/bin/env node

const {execSync} = require('child_process');
const {readFileSync, writeFileSync} = require('fs');
const {join} = require('path');
const readline = require('readline');

const root = join(__dirname, '..');

function confirm(message) {
  const rl = readline.createInterface({input: process.stdin, output: process.stdout});
  return new Promise((resolve) => {
    rl.question(`${message} (y/N) `, (answer) => {
      rl.close();
      if (answer.trim().toLowerCase() !== 'y') {
        console.log('Aborted.');
        process.exit(0);
      }
      resolve();
    });
  });
}

function run(cmd, opts) {
  console.log(`  $ ${cmd}`);
  execSync(cmd, {stdio: 'inherit', cwd: root, ...opts});
}

const version = process.argv[2];
if (!version || !/^\d+\.\d+\.\d+$/.test(version)) {
  console.error('Usage: npm run release -- <version>');
  console.error('Example: npm run release -- 0.26.18');
  process.exit(1);
}

// Ensure clean working tree
const status = execSync('git status --porcelain', {cwd: root, encoding: 'utf8'}).trim();
if (status) {
  console.error('Error: working tree is not clean. Commit or stash changes first.');
  process.exit(1);
}

async function release() {
  console.log(`\n==> Releasing v${version}\n`);

  // 0. Verify changelog has an entry for this version
  const changelog = readFileSync(join(root, 'CHANGELOG.md'), 'utf8');
  const heading = `## [${version}]`;
  const headingIdx = changelog.indexOf(heading);
  if (headingIdx === -1) {
    console.error(`Error: CHANGELOG.md has no "${heading}" section.`);
    console.error('Add release notes before running this script.');
    process.exit(1);
  }
  // Check there's content after the heading (not just an empty section)
  const afterHeading = changelog.slice(headingIdx + heading.length).split(/^## \[/m)[0].trim();
  if (!afterHeading) {
    console.error(`Error: CHANGELOG.md "${heading}" section is empty. Add change notes.`);
    process.exit(1);
  }
  console.log('==> CHANGELOG.md verified');

  // 1. Update package.json
  console.log('==> Updating package.json');
  run(`npm version ${version} --no-git-tag-version`);

  // 2. Update Cargo.toml
  console.log('==> Updating Cargo.toml');
  const cargoPath = join(root, 'Cargo.toml');
  const cargo = readFileSync(cargoPath, 'utf8');
  writeFileSync(cargoPath, cargo.replace(/^version = ".*"/m, `version = "${version}"`));
  run('cargo check');

  // 3. Build
  console.log('==> Building');
  run('npm run build');

  // 4. Test
  console.log('==> Testing');
  run('npm test');

  // 5. Docs WASM
  console.log('==> Building docs WASM');
  run('npm run docswasm');

  // 6. Install (rebuild native addon)
  console.log('==> Rebuilding native addon');
  run('npm run install');

  // 7. Commit and tag
  await confirm(`\n==> Commit and tag v${version}?`);
  run('git add -A');
  run(`git commit -m "v${version}"`);
  run(`git tag "v${version}"`);

  // 8. Publish to npm
  await confirm('==> Publish to npm?');
  run('npm publish');

  // 9. Publish to crates.io
  await confirm('==> Publish to crates.io?');
  run('cargo publish --allow-dirty');

  // 10. Push
  await confirm('==> Push commit and tag?');
  run('git push');
  run(`git push origin "v${version}"`);

  console.log(`\n==> Done! v${version} released.`);
}

release();
