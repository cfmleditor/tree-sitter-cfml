{
  "targets": [
    {
      "target_name": "tree_sitter_cfml_binding",
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except",
      ],
      "include_dirs": [
        "cfml/src",
      ],
      "sources": [
        "cfml/src/parser.c",
        "cfml/src/scanner.c",
        "cfhtml/src/parser.c",
        "cfhtml/src/scanner.c",
        "bindings/node/binding.cc",
      ],
      "cflags_c": [
        "-std=c11"
      ]
    }
  ]
}