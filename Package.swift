// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "TreeSitterCfml",
    products: [
        .library(name: "TreeSitterCfml", targets: ["TreeSitterCfml", "TreeSitterCfhtml", "TreeSitterCfscript"]),
    ],
    dependencies: [],
    targets: [
        .target(name: "TreeSitterCfml",
                path: "cfml",
                exclude: [
                ],
                sources: [
                    "src/parser.c",
                    "src/scanner.c"
                ],
                resources: [
                    .copy("queries")
                ],
                publicHeadersPath: "bindings/swift",
                cSettings: [.headerSearchPath("src")])
        .target(name: "TreeSitterCfhtml",
                path: "cfhtml",
                exclude: [
                ],
                sources: [
                    "src/parser.c",
                    "src/scanner.c"
                ],
                resources: [
                    .copy("queries")
                ],
                publicHeadersPath: "bindings/swift",
                cSettings: [.headerSearchPath("src")])
        .target(name: "TreeSitterCfscript",
                path: "cfscript",
                exclude: [
                ],
                sources: [
                    "src/parser.c",
                    "src/scanner.c"
                ],
                resources: [
                    .copy("queries")
                ],
                publicHeadersPath: "bindings/swift",
                cSettings: [.headerSearchPath("src")])
    ]
)
