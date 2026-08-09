#!/usr/bin/env node

/**
 * `npm start` — the same thing as `npm run playground`, kept because `start` is
 * the conventional name and `prestart` builds the WASM it needs.
 *
 * It used to run `tree-sitter playground` from the repo root, which panics:
 * the CLI derives the WASM filename from the grammar in the current directory,
 * and there is no grammar at the root of a three-grammar repo.
 */

require('./playground.js');
