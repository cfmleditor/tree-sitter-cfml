const root = require('path').join(__dirname, '..', '..');

module.exports = require('node-gyp-build')(root);

try {
  module.exports.cfml.nodeTypeInfo = require('../../cfml/src/node-types.json');
  module.exports.cfhtml.nodeTypeInfo = require('../../cfhtml/src/node-types.json');
} catch (_) {}
