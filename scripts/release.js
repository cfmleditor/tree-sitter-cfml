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

const dryRun = process.argv.includes('--dry-run');
const version = process.argv.filter((a) => a !== '--dry-run')[2];
if (!version || !/^\d+\.\d+\.\d+$/.test(version)) {
  console.error('Usage: npm run release -- <version> [--dry-run]');
  console.error('Example: npm run release -- 0.26.18 --dry-run');
  process.exit(1);
}

// Ensure clean working tree
const status = execSync('git status --porcelain', {cwd: root, encoding: 'utf8'}).trim();
if (status) {
  console.error('Error: working tree is not clean. Commit or stash changes first.');
  process.exit(1);
}

// Ensure tag doesn't already exist
const existingTags = execSync('git tag --list', {cwd: root, encoding: 'utf8'});
if (existingTags.split('\n').includes(`v${version}`)) {
  console.error(`Error: tag v${version} already exists.`);
  process.exit(1);
}

// Ensure new version is greater than current version
const pkg = JSON.parse(readFileSync(join(root, 'package.json'), 'utf8'));
const current = pkg.version.split('.').map(Number);
const next = version.split('.').map(Number);
if (next[0] < current[0] || (next[0] === current[0] && next[1] < current[1]) ||
    (next[0] === current[0] && next[1] === current[1] && next[2] <= current[2])) {
  console.error(`Error: version ${version} is not greater than current ${pkg.version}.`);
  process.exit(1);
}

// Fetch remote and ensure local branch isn't behind
execSync('git fetch', {cwd: root, stdio: 'inherit'});
const behind = execSync('git rev-list --count HEAD..@{u}', {cwd: root, encoding: 'utf8'}).trim();
if (behind !== '0') {
  console.error(`Error: local branch is ${behind} commit(s) behind remote. Pull first.`);
  process.exit(1);
}

async function release() {
  if (dryRun) {
    console.log('[DRY RUN] No changes will be made.\n');
  } else {
    await confirm(
      '\n⚠️  WARNING: This is a LIVE release. Files will be modified, a commit and tag will be created, and changes may be pushed to remote.\n   Continue?',
    );
  }
  console.log(`\n==> Releasing v${version}\n`);

  // 0. Verify changelog has an entry for this version (or [Unreleased] to rename)
  const changelogPath = join(root, 'CHANGELOG.md');
  let changelog = readFileSync(changelogPath, 'utf8');
  const heading = `## [${version}]`;

  if (changelog.indexOf(heading) === -1) {
    // Check for [Unreleased] section to rename
    const unreleasedRe = /## \[Unreleased\]/i;
    if (unreleasedRe.test(changelog)) {
      const afterUnreleased = changelog.split(unreleasedRe)[1].split(/^## \[/m)[0].trim();
      if (!afterUnreleased) {
        console.error('Error: CHANGELOG.md [Unreleased] section is empty. Add change notes.');
        process.exit(1);
      }
      if (!dryRun) {
        changelog = changelog.replace(unreleasedRe, `## [${version}]`);
        writeFileSync(changelogPath, changelog);
      }
      console.log(`==> CHANGELOG.md [Unreleased] renamed to [${version}]`);
    } else {
      console.error(`Error: CHANGELOG.md has no "${heading}" or [Unreleased] section.`);
      console.error('Add release notes before running this script.');
      process.exit(1);
    }
  } else {
    const headingIdx = changelog.indexOf(heading);
    const afterHeading = changelog.slice(headingIdx + heading.length).split(/^## \[/m)[0].trim();
    if (!afterHeading) {
      console.error(`Error: CHANGELOG.md "${heading}" section is empty. Add change notes.`);
      process.exit(1);
    }
    console.log('==> CHANGELOG.md verified');
  }

  if (dryRun) {
    console.log('==> Would update package.json');
    console.log('==> Would update Cargo.toml');
  } else {
    // 1. Update package.json
    console.log('==> Updating package.json');
    run(`npm version ${version} --no-git-tag-version`);

    // 2. Update Cargo.toml
    console.log('==> Updating Cargo.toml');
    const cargoPath = join(root, 'Cargo.toml');
    const cargo = readFileSync(cargoPath, 'utf8');
    writeFileSync(cargoPath, cargo.replace(/^version = ".*"/m, `version = "${version}"`));
    run('cargo check');
  }

  // 3. Build
  console.log('==> Building');
  run('npm run build');

  // 4. Lint
  console.log('==> Linting');
  run('npm run lint');

  // 5. Test
  console.log('==> Testing');
  run('npm test');

  // 6. Docs WASM
  console.log('==> Building docs WASM');
  run('npm run docswasm');

  // 7. Install (rebuild native addon)
  console.log('==> Rebuilding native addon');
  run('npm run install');

  if (dryRun) {
    console.log(`\n==> Would commit and tag v${version}`);
    console.log('==> Would push commit and tag');
    console.log('\n==> Dry run complete. All checks passed.');
    return;
  }

  // 7. Commit and tag
  await confirm(`\n==> Commit and tag v${version}?`);
  run('git add -A');
  run(`git commit -m "v${version}"`);
  run(`git tag "v${version}"`);

  // 8. Push
  await confirm('==> Push commit and tag?');
  run('git push');
  run(`git push origin "v${version}"`);

  console.log(`\n==> Done! v${version} released.`);
  console.log('    npm and crates.io publish will be handled by the GitHub Release workflow.');
}

release();
