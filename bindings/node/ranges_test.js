// Node extents, which the corpus tests cannot see: they compare tree shape
// only, so a node that runs on past its last token passes them unchanged.

const assert = require('node:assert');
const {test} = require('node:test');

const Parser = require('tree-sitter');

/**
 * The text of every `type` node in `source`, which must parse cleanly.
 *
 * @param {object} language
 * @param {string} source
 * @param {string} type
 * @returns {string[]}
 */
function textOf(language, source, type) {
  const parser = new Parser();
  parser.setLanguage(language);
  const root = parser.parse(source).rootNode;
  assert.ok(!root.hasError, `parse error in ${JSON.stringify(source)}`);
  return root.descendantsOfType(type).map((n) => n.text);
}

// #163: in a tag expression, a statement closed by `}` rather than by `;` got
// its automatic semicolon after the whitespace before the `}`. The statement,
// and every node it closed, ended there too.
test('cfml: a statement closed by } ends at its last token', () => {
  const cfml = require('./cfml');

  assert.deepStrictEqual(
    textOf(cfml, '<cfset x = function(){ return 1 }>', 'return_statement'),
    ['return 1'],
  );
  assert.deepStrictEqual(
    textOf(cfml, '<cfset x = function(){ return 1\n }>', 'return_statement'),
    ['return 1'],
  );
  assert.deepStrictEqual(
    textOf(cfml, '<cfset x = function(){ if (a) { b() }\n }>', 'if_statement'),
    ['if (a) { b() }'],
  );
});

test('cfml: a closure that ends a struct literal ends at its }', () => {
  const cfml = require('./cfml');
  const source = '<cfset x = {\n\ta = function(){ return 1; }\n}>';

  assert.deepStrictEqual(textOf(cfml, source, 'statement_block'), ['{ return 1; }']);
  assert.deepStrictEqual(
    textOf(cfml, source, 'object_assignment_pattern'),
    ['a = function(){ return 1; }'],
  );
});

test('cfscript: the same statements end at their last token', () => {
  const cfscript = require('./cfscript');

  assert.deepStrictEqual(
    textOf(cfscript, 'x = function(){ return 1 };', 'return_statement'),
    ['return 1'],
  );
  assert.deepStrictEqual(
    textOf(cfscript, 'x = {\n\ta = function(){ return 1; }\n};', 'statement_block'),
    ['{ return 1; }'],
  );
});
