#!/usr/bin/env node

'use strict';

/**
 * Fetch a real-world CFML corpus from public repositories.
 *
 *   npm run corpus:fetch          # clone the curated list into ./corpus
 *   npm run corpus:fetch -- --list
 *   npm run corpus:fetch -- ortus-boxlang/BoxLang other/repo
 *
 * Each repository is cloned shallowly into a temporary directory; only CFML
 * source files are kept, under `corpus/<owner>_<repo>/`. Then:
 *
 *   npm run scan corpus
 *
 * The corpus is deliberately not committed — it is third-party code under a
 * mix of licences and weighs ~100 MB. `corpus/` is gitignored.
 */

const fs = require('fs');
const path = require('path');
const {join} = path;
const {spawnSync} = require('child_process');

const root = join(__dirname, '..');
const corpusDir = join(root, 'corpus');
const workDir = join(corpusDir, '.work');

// Curated list: large, actively maintained, publicly licensed CFML code bases
// spanning tag-based templates, script components, and embedded SQL.
const REPOS = [
  'lucee/Lucee', // engine + ~4k test-suite files, admin templates
  'ColdBox/coldbox-platform', // MVC framework, script components
  'Ortus-Solutions/TestBox', // BDD test framework
  'Ortus-Solutions/ContentBox', // CMS, tags + script
  'Ortus-Solutions/commandbox', // CLI, heavy script usage
  'Ortus-Solutions/DocBox', // documentation generator
  'coldbox-modules/qb', // query builder, SQL generation
  'coldbox-modules/cborm', // ORM layer
  'coldbox-modules/cbfs',
  'coldbox-modules/cbsecurity',
  'coldbox-modules/cbi18n',
  'ColdBox/coldbox-samples', // sample applications
  'cfwheels/cfwheels', // Rails-style framework, tag templates
  'pixl8/preside-cms', // large CMS
  'MSU-NatSci/MuraCMS', // Mura CMS 7.1, tag-heavy with many <cfquery> blocks
  'valtech-cfml/Slatwall', // commerce platform, ORM + queries
  'framework-one/fw1', // FW/1
  'atuttle/Taffy', // REST framework

  // Second wave, added once the first 25 repos stopped producing new failure
  // signatures: smaller and more specialised code bases, chosen for breadth of
  // idiom rather than size. Modules exercise script components heavily; the
  // Lucee extensions add tag templates and Java interop.
  'coldbox-modules/cbvalidation', // vendored copies of this were already the
  //                                 source of the array-return-type gap
  'coldbox-modules/cbstreams', // Java streams interop, `new java:` heavy
  'coldbox-modules/cbmailservices',
  'coldbox-modules/cbdebugger',
  'coldbox-modules/hyper', // HTTP client
  'coldbox-modules/cbwire', // reactive components, newer idioms
  'coldbox-modules/cbmarkdown',
  'coldbox-modules/cbmessagebox',
  'coldbox-modules/cbq',
  'coldbox-modules/cfmigrations',
  'coldbox-modules/cbSwagger',
  'coldbox-modules/cbjavaloader', // Java interop
  'coldbox-modules/cbantisamy',
  'coldbox-modules/cbfeeds',
  'Ortus-Solutions/coldbox-elixir',
  'pixl8/preside-ext-saml2-sso',
  'lucee/extension-image', // Lucee extensions: tag templates + Java interop
  'lucee/extension-redis',
  'lucee/extension-s3',
  'lucee/extension-esapi',
  'lucee/extension-pdf',
  'cfsimplicity/spreadsheet-cfml',
  'foundeo/cfdocs', // documentation examples
  'ortus-boxlang/BoxLang', // BoxLang's CFML compatibility fixtures
  'lucee/lucee-docs',
  'lucee/script-runner',
  'lucee/extension-mongodb',
  'cfmleditor/cfmleditor', // editor fixtures
];

const EXTENSIONS = /\.(cfc|cfm|cfml|cfs)$/i;

const args = process.argv.slice(2).filter((a) => a !== '--');
if (args.includes('--list')) {
  console.log(REPOS.join('\n'));
  process.exit(0);
}
const repos = args.filter((a) => !a.startsWith('--'));
const targets = repos.length ? repos : REPOS;

/**
 * Recursively copy CFML files, preserving relative layout.
 *
 * @param {string} from
 * @param {string} to
 * @param {string} base
 * @returns {number} number of files copied
 */
function copyCfmlFiles(from, to, base) {
  let count = 0;
  for (const entry of fs.readdirSync(from, {withFileTypes: true})) {
    const full = join(from, entry.name);
    if (entry.isDirectory()) {
      if (entry.name === '.git') continue;
      count += copyCfmlFiles(full, to, base);
    } else if (EXTENSIONS.test(entry.name)) {
      const rel = path.relative(base, full);
      const dest = join(to, rel);
      fs.mkdirSync(path.dirname(dest), {recursive: true});
      fs.copyFileSync(full, dest);
      count++;
    }
  }
  return count;
}

/**
 * Remove a directory tree if present.
 *
 * @param {string} dir
 */
function rmrf(dir) {
  fs.rmSync(dir, {recursive: true, force: true});
}

fs.mkdirSync(workDir, {recursive: true});

let ok = 0;
let failed = 0;
let totalFiles = 0;

for (const repo of targets) {
  const name = repo.replace('/', '_');
  const dest = join(corpusDir, name);
  if (fs.existsSync(dest)) {
    console.log(`skip  ${repo} (already in corpus/)`);
    ok++;
    continue;
  }
  const clone = join(workDir, name);
  rmrf(clone);

  const r = spawnSync('git', ['clone', '--depth', '1', '--quiet', `https://github.com/${repo}.git`, clone], {
    stdio: ['ignore', 'ignore', 'pipe'],
  });
  if (r.status !== 0) {
    const err = r.stderr ? r.stderr.toString().trim().split('\n').pop() : '';
    console.log(`FAIL  ${repo}${err ? ` — ${err}` : ''}`);
    failed++;
    rmrf(clone);
    continue;
  }

  fs.mkdirSync(dest, {recursive: true});
  const count = copyCfmlFiles(clone, dest, clone);
  rmrf(clone);
  totalFiles += count;
  ok++;
  console.log(`ok    ${repo} — ${count} files`);
}

rmrf(workDir);

console.log(`\n${ok} repositor${ok === 1 ? 'y' : 'ies'} in corpus/, ${failed} failed, ${totalFiles} files fetched this run.`);
console.log('Next: npm run scan corpus');

process.exit(failed > 0 && ok === 0 ? 1 : 0);
