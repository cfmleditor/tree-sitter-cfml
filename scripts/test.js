#!/usr/bin/env node

const { execSync } = require("child_process");
const { join } = require("path");

// Test all grammars/dialects including the cfquery SQL dialect.
const parsers = ["cfml", "cfhtml", "cfscript", "cfquery"];

for (const dir of parsers) {
  console.log(`testing ${dir}`);
  try {
    execSync("tree-sitter test -u", {
      stdio: "inherit",
      cwd: join(__dirname, "..", dir),
    });
  } catch (error) {
    process.exitCode |= parsers.indexOf(dir) + 1;
  }
}
