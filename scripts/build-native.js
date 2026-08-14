#!/usr/bin/env node

// Build the shared libraries the Java binding loads at runtime, into build/native/:
//
//   libtree-sitter.so             the tree-sitter runtime, from the copy vendored
//                                 by the `tree-sitter` npm package (so the version
//                                 is pinned by package-lock.json, not by whatever
//                                 the machine happens to have installed)
//   libtree-sitter-cfml.so        the three grammars
//   libtree-sitter-cfscript.so
//   libtree-sitter-cfquery.so
//
// `make` builds the grammar libraries too, but leaves each one in its own dialect
// directory and does not build the runtime, which jtreesitter also needs. This
// puts all four in one directory so `java.library.path` can be a single entry.

const {execFileSync} = require('child_process');
const {mkdirSync, rmSync, existsSync} = require('fs');
const {join} = require('path');
const {root} = require('./tree-sitter-cli.cjs');

const platform = process.platform;
if (platform === 'win32') {
  console.error(
    'scripts/build-native.js targets Unix toolchains (cc). On Windows, build the\n' +
      'grammars with MinGW-w64 by hand or use the Node/Python bindings instead.',
  );
  process.exit(1);
}

const soext = platform === 'darwin' ? 'dylib' : 'so';
const outDir = join(root, 'build', 'native');
const vendor = join(root, 'node_modules', 'tree-sitter', 'vendor', 'tree-sitter', 'lib');

if (!existsSync(vendor)) {
  console.error(`missing ${vendor}\nrun npm install first`);
  process.exit(1);
}

const cc = process.env.CC || 'cc';
const shared = platform === 'darwin' ? ['-dynamiclib'] : ['-shared'];

/**
 * Compile one shared library.
 *
 * @param {string} name library name, without the `lib` prefix or extension
 * @param {string[]} sources source files to compile
 * @param {string[]} includes directories to add to the include path
 * @param {string} std the C standard to compile against
 */
function build(name, sources, includes, std = 'c11') {
  const out = join(outDir, `lib${name}.${soext}`);
  const args = [
    `-std=${std}`,
    '-fPIC',
    '-O2',
    ...shared,
    ...includes.map((i) => `-I${i}`),
    ...sources,
    '-o',
    out,
  ];
  console.log(`building lib${name}.${soext}`);
  execFileSync(cc, args, {cwd: root, stdio: 'inherit'});
}

rmSync(outDir, {recursive: true, force: true});
mkdirSync(outDir, {recursive: true});

// gnu11 rather than c11 for the runtime: it uses fdopen/fileno, which strict
// ISO mode hides, leaving them implicitly declared as returning int.
build(
  'tree-sitter',
  [join(vendor, 'src', 'lib.c')],
  [join(vendor, 'include'), join(vendor, 'src')],
  'gnu11',
);

for (const dialect of ['cfml', 'cfscript', 'cfquery']) {
  const src = join(root, dialect, 'src');
  // cfml also has tag.c; cfquery and cfscript keep the same tables in a header.
  const sources = [join(src, 'parser.c'), join(src, 'scanner.c')];
  if (existsSync(join(src, 'tag.c'))) {
    sources.push(join(src, 'tag.c'));
  }
  build(`tree-sitter-${dialect}`, sources, [src]);
}

console.log(`\nwrote ${outDir}`);
