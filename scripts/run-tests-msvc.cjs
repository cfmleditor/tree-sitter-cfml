#!/usr/bin/env node
'use strict';

const {spawnSync} = require('child_process');
const fs = require('fs');
const os = require('os');
const path = require('path');

const root = path.join(__dirname, '..');
const testJs = path.join(__dirname, 'test.js');

if (process.platform !== 'win32') {
  const r = spawnSync(process.execPath, [testJs], {cwd: root, stdio: 'inherit'});
  process.exit(r.status === null ? 1 : r.status);
}

const programFilesX86 = process.env['ProgramFiles(x86)'] || 'C:\\Program Files (x86)';
const vswhere = path.join(
  programFilesX86,
  'Microsoft Visual Studio',
  'Installer',
  'vswhere.exe',
);

/** @returns {string|null} VS installation root from vswhere, or null */
function findVsInstallPath() {
  if (!fs.existsSync(vswhere)) {
    return null;
  }
  const wr = spawnSync(
    vswhere,
    [
      '-products',
      '*',
      '-requires',
      'Microsoft.VisualStudio.Component.VC.Tools.x86.x64',
      '-property',
      'installationPath',
    ],
    {encoding: 'utf8'},
  );
  if (wr.status !== 0 || !wr.stdout) {
    return null;
  }
  return wr.stdout.trim().split(/\r?\n/)[0] || null;
}

const installPath =
  findVsInstallPath() ||
  path.join(programFilesX86, 'Microsoft Visual Studio', '2022', 'BuildTools');

const vcvars64 = path.join(
  installPath,
  'VC',
  'Auxiliary',
  'Build',
  'vcvars64.bat',
);

if (!fs.existsSync(vcvars64)) {
  console.error(
    'MSVC C++ toolchain not found. Install Visual Studio 2022 Build Tools with the Desktop development with C++ workload (or full VS with the same).\n',
    `Expected: ${vcvars64}`,
  );
  process.exit(1);
}

const batPath = path.join(os.tmpdir(), `tree-sitter-cfml-test-${process.pid}-${Date.now()}.bat`);
const batBody = [
  '@echo off',
  `call "%TS_VCVARS%"`,
  'set CC=cl',
  'set CXX=cl',
  '"%TS_NODE%" "%TS_TEST%"',
].join('\r\n');

let status = 1;
try {
  fs.writeFileSync(batPath, batBody, 'utf8');
  const r = spawnSync(process.env.ComSpec || 'cmd.exe', ['/d', '/c', batPath], {
    cwd: root,
    stdio: 'inherit',
    env: {
      ...process.env,
      TS_VCVARS: vcvars64,
      TS_NODE: process.execPath,
      TS_TEST: testJs,
    },
  });
  status = r.status === null ? 1 : r.status;
} finally {
  try {
    fs.unlinkSync(batPath);
  } catch {
    /* ignore missing temp file */
  }
}

process.exit(status);
