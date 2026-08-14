import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import io.github.cfmleditor.jtreesitter.cfml.TreeSitterCfml;
import io.github.cfmleditor.jtreesitter.cfquery.TreeSitterCfquery;
import io.github.cfmleditor.jtreesitter.cfscript.TreeSitterCfscript;
import io.github.treesitter.jtreesitter.Language;
import io.github.treesitter.jtreesitter.Parser;
import io.github.treesitter.jtreesitter.Tree;
import org.junit.jupiter.api.Test;

/**
 * Smoke test for the three grammars: each language loads out of its own shared
 * library, and each parses a small sample of its dialect without error.
 */
public class TreeSitterCfmlTest {
    @Test
    public void testCfml() {
        var language = new Language(TreeSitterCfml.language());
        assertEquals("cfml", language.getName());
        assertParses(language, "<cfif x GT 0>#x#</cfif>", "program");
    }

    @Test
    public void testCfscript() {
        var language = new Language(TreeSitterCfscript.language());
        assertEquals("cfscript", language.getName());
        assertParses(language, "function greet( required string name ) { return \"hi #name#\"; }", "program");
    }

    @Test
    public void testCfquery() {
        var language = new Language(TreeSitterCfquery.language());
        assertEquals("cfquery", language.getName());
        assertParses(language, "SELECT id FROM users WHERE id = #arguments.id#", "program");
    }

    private static void assertParses(Language language, String source, String rootType) {
        try (var parser = new Parser(language)) {
            Tree tree = parser.parse(source).orElseThrow();
            try (tree) {
                var root = tree.getRootNode();
                assertEquals(rootType, root.getType());
                assertFalse(root.hasError(), () -> "parse error in: " + source);
                assertTrue(root.getChildCount() > 0);
            }
        }
    }
}
