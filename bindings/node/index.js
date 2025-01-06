const root = require("path").join(__dirname, "..", "..");

module.exports =
  typeof process.versions.bun === "string"
    // Support `bun build --compile` by being statically analyzable enough to find the .node file at build-time
    ? require(`../../prebuilds/${process.platform}-${process.arch}/tree-sitter-cfml.node`)
    : require("node-gyp-build")(root);

try {
  module.exports.cfml.nodeTypeInfo = require("../../cfml/src/node-types.json");
  module.exports.cfhtml.nodeTypeInfo = require("../../cfhtml/src/node-types.json");
  module.exports.cfscript.nodeTypeInfo = require("../../cfscript/src/node-types.json");
} catch (_) { }