#!/usr/bin/env node

'use strict';

/**
 * Where the fetched real-world corpus lives.
 *
 * `~/corpus` wins when it exists, so one ~100 MB checkout is shared by every
 * clone and git worktree of this repository, and survives `git clean -xdf`
 * (which takes gitignored files, and so takes an in-repo `corpus/` with it).
 * Otherwise the in-repo `corpus/` is used, which is gitignored.
 *
 * The shared directory is never created here — creating `~/corpus` yourself is
 * how you opt in, and its absence is how you opt out.
 */

const fs = require('fs');
const os = require('os');
const {join} = require('path');

const inRepo = join(__dirname, '..', 'corpus');
const shared = join(os.homedir(), 'corpus');

/** @returns {string} Absolute path to the corpus directory to use. */
function corpusDir() {
  return fs.existsSync(shared) ? shared : inRepo;
}

/**
 * Resolve a user-supplied scan target, so the documented `npm run scan corpus`
 * keeps working when the repositories live in `~/corpus`. Only the bare word
 * `corpus` is redirected, and only when it does not exist relative to the cwd;
 * any other path is the caller's to resolve.
 *
 * @param {string} target - The path given on the command line
 * @returns {string} The path to scan
 */
function resolveScanTarget(target) {
  if (fs.existsSync(target)) return target;
  const bare = target.replace(/^\.\//, '').replace(/\/$/, '');
  if (bare === 'corpus') return corpusDir();
  return target;
}

module.exports = {corpusDir, resolveScanTarget, inRepo, shared};
