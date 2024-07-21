// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "TreeSitterCfml",
    products: [
        .library(name: "TreeSitterCfml", targets: ["TreeSitterCfml"]),
    ],
    dependencies: [],
    targets: [
        .target(name: "TreeSitterCfml",
                path: ".",
                exclude: [
                    "Cargo.toml",
                    "Makefile",
                    "binding.gyp",
                    "bindings/go",
                    "bindings/node",
                    "bindings/python",
                    "bindings/rust",
                    "common/common.mak",
                    "common/define-grammar.js",
                    "package.json",
                    "package-lock.json",
                    "pyproject.toml",
                    "setup.py",
                    "test",
                    ".editorconfig",
                    ".github",
                    ".gitignore",
                    ".gitattributes",
                ],
                sources: [
                    "cfml/src/parser.c",
                    "cfml/src/scanner.c",
                    "cfhtml/src/parser.c",
                    "cfhtml/src/scanner.c",
                ],
                resources: [
                    .copy("queries")
                ],
                publicHeadersPath: "bindings/swift",
                cSettings: [.headerSearchPath("cfml/src")])
    ]
)
