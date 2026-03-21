const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

const root = path.join(__dirname, '..');

function paths() {
  const cliDir = path.join(root, 'node_modules', 'tree-sitter-cli');
  return {
    cliDir,
    cliJs: path.join(cliDir, 'cli.js'),
    exe: path.join(cliDir, process.platform === 'win32' ? 'tree-sitter.exe' : 'tree-sitter'),
    installJs: path.join(cliDir, 'install.js'),
  };
}

function ensureTreeSitterBinary() {
  const { cliJs, exe, cliDir, installJs } = paths();
  if (!fs.existsSync(cliJs)) {
    console.error(
      'tree-sitter-cli is not installed. From the repository root, run: npm install'
    );
    process.exit(1);
  }
  if (!fs.existsSync(exe)) {
    console.error(
      'tree-sitter CLI binary missing; running the official install.js download step...'
    );
    const r = spawnSync(process.execPath, [installJs], {
      cwd: cliDir,
      stdio: 'inherit',
    });
    if (r.error) throw r.error;
    if (r.status !== 0) {
      process.exit(r.status ?? 1);
    }
    if (!fs.existsSync(exe)) {
      console.error(
        'tree-sitter CLI binary is still missing. Check network access to GitHub releases.'
      );
      process.exit(1);
    }
  }
}

function spawnTreeSitter(argv, options) {
  ensureTreeSitterBinary();
  const { cliJs } = paths();
  return spawnSync(process.execPath, [cliJs, ...argv], {
    stdio: 'inherit',
    ...options,
  });
}

module.exports = {
  root,
  paths,
  ensureTreeSitterBinary,
  spawnTreeSitter,
};
