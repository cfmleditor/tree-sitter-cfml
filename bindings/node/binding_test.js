const assert = require('node:assert');
const { test } = require('node:test');

const Parser = require('tree-sitter');

test('can load CFML grammar', () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(require('./cfml')));
});

test('can load CFHTML grammar', () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(require('./cfhtml')));
});

test('can load CFSCRIPT grammar', () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(require('./cfscript')));
});
