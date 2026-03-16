#!/usr/bin/env node

const { execSync } = require("child_process");
const { join } = require("path");

// Build all grammars/dialects used by this package.
const grammars = ["cfml", "cfhtml", "cfscript", "cfquery"];

for (const dir of grammars) {
  console.log(`building ${dir}`);
  execSync("tree-sitter generate", {
    stdio: "inherit",
    cwd: join(__dirname, "..", dir),
  });
}
