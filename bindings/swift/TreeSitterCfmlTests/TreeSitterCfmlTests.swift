import XCTest
import SwiftTreeSitter
import TreeSitterCfml

final class TreeSitterCfmlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_cfml())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Cfml grammar")
    }
}
