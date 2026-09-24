#!/usr/bin/env node

'use strict';

/**
 * Fail if any keyword token is left out of tree-sitter's keyword extraction.
 *
 *   npm run check:keywords              # all three dialects
 *   DIALECT=cfscript npm run check:keywords
 *   node scripts/check-keywords.js <repo-root>   # check another checkout
 *
 * `keyword()` in both grammar files makes each keyword ONE token, a
 * case-insensitive regex at `prec(1)`. That is safe only while the token is
 * keyword-extracted: the keyword lexer runs after `identifier` has matched a
 * whole word, so `while_value` stays one identifier. A keyword that is NOT
 * extracted is lexed by the main lexer instead, and there `prec(1)` lets it
 * out-lex a longer identifier — `while_value` becomes `while` + `_value`, but
 * only in states where `while` is valid, so no test is guaranteed to notice.
 *
 * `tree-sitter generate` excludes a candidate silently (only `--log` says so),
 * and it has done so for reasons far from the keyword itself: a JavaScript
 * `\uXXXX` escape in `identifier` once kept sixteen keywords out, and a plain
 * `'get'` written beside `keyword('Get')` knocks both out. So this reads the
 * generated sources directly, the same files every binding compiles:
 *
 * - the keyword names, from `src/grammar.json`: every alias whose content is a
 *   `prec`'d token over a pattern made only of `[xX]` letter classes, which is
 *   exactly what `keyword()` emits (`<cf` has a `<` and can never be extracted,
 *   so it is not checked);
 * - the terminal symbols carrying those names, from `ts_symbol_names` in
 *   `src/parser.c`;
 * - the symbols the keyword lexer accepts, from `ts_lex_keywords`.
 *
 * Every terminal carrying a keyword's name must be accepted by the keyword
 * lexer. A second token with the same name (the `'get'` case) fails too.
 */

const fs = require('fs');
const {join, resolve} = require('path');

const root = resolve(process.argv[2] ?? join(__dirname, '..'));
const dialects = process.env.DIALECT ? [process.env.DIALECT] : ['cfml', 'cfscript', 'cfquery'];

const KEYWORD_PATTERN = /^(?:\[[a-z][A-Z]\])+$/;

/**
 * @param {unknown} rule - A node of `grammar.json`'s rule tree
 * @param {Set<string>} names - Collects keyword alias names
 */
function collectKeywordNames(rule, names) {
  if (!rule || typeof rule !== 'object') return;
  // ALIAS → TOKEN → PREC → PATTERN, the shape keyword() emits.
  const token = rule.type === 'ALIAS' ? rule.content : undefined;
  const prec = token?.type === 'TOKEN' ? token.content : undefined;
  const pattern = prec?.type === 'PREC' ? prec.content : undefined;
  if (pattern?.type === 'PATTERN' && KEYWORD_PATTERN.test(pattern.value)) {
    names.add(rule.value);
  }
  for (const value of Object.values(rule)) collectKeywordNames(value, names);
}

/**
 * @param {string} dialect
 * @returns {string[]} Problems found; empty when every keyword is extracted
 */
function check(dialect) {
  const src = join(root, dialect, 'src');
  const grammar = JSON.parse(fs.readFileSync(join(src, 'grammar.json'), 'utf8'));
  const parser = fs.readFileSync(join(src, 'parser.c'), 'utf8');

  const keywords = new Set();
  for (const rule of Object.values(grammar.rules)) collectKeywordNames(rule, keywords);
  if (keywords.size === 0) {
    return [`no keyword() tokens found in ${dialect}/src/grammar.json — has keyword() changed shape?`];
  }

  const tokenCount = Number(/^#define TOKEN_COUNT (\d+)$/m.exec(parser)?.[1]);
  const enumBody = /enum ts_symbol_identifiers \{([\s\S]*?)\n\};/.exec(parser)?.[1];
  const namesBody = /static const char \* const ts_symbol_names\[\] = \{([\s\S]*?)\n\};/.exec(parser)?.[1];
  const keywordLexer = /static bool ts_lex_keywords\([\s\S]*?\n\}\n/.exec(parser)?.[0];
  if (!tokenCount || !enumBody || !namesBody || !keywordLexer) {
    return [`could not read the tables in ${dialect}/src/parser.c — has the generated layout changed?`];
  }

  /** @type {Map<string, number>} */
  const index = new Map();
  for (const m of enumBody.matchAll(/^\s+(\w+) = (\d+),$/gm)) index.set(m[1], Number(m[2]));
  const extracted = new Set([...keywordLexer.matchAll(/ACCEPT_TOKEN\((\w+)\)/g)].map((m) => m[1]));

  /** @type {Map<string, string[]>} name -> terminal symbols carrying it */
  const terminals = new Map();
  for (const m of namesBody.matchAll(/^\s+\[(\w+)\] = "((?:[^"\\]|\\.)*)",$/gm)) {
    const [, symbol, name] = m;
    const i = index.get(symbol);
    if (i === undefined || i >= tokenCount || !keywords.has(name)) continue;
    terminals.set(name, [...(terminals.get(name) ?? []), symbol]);
  }

  const problems = [];
  for (const name of [...keywords].sort()) {
    for (const symbol of terminals.get(name) ?? []) {
      if (!extracted.has(symbol)) {
        problems.push(`${dialect}: keyword "${name}" (${symbol}) is not keyword-extracted`);
      }
    }
  }
  console.log(`${dialect.padEnd(9)} ${keywords.size} keywords, ` +
    `${[...terminals.values()].flat().length} terminals, ${problems.length} not extracted`);
  return problems;
}

const problems = dialects.flatMap(check);
if (problems.length > 0) {
  console.error('\n' + problems.join('\n'));
  console.error('\nRun `tree-sitter generate --log` in that dialect and grep "Keywords - exclude"' +
    ' for the reason; see keyword() in cfscript/grammar.js.');
  process.exitCode = 1;
}
