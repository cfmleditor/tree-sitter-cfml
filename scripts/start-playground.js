#!/usr/bin/env node

const { spawnTreeSitter, root } = require('./tree-sitter-cli.cjs');

const r = spawnTreeSitter(['playground'], { cwd: root });
process.exit(r.status === null ? 1 : r.status);
