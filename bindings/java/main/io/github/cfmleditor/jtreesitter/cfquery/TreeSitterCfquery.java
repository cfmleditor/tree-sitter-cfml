package io.github.cfmleditor.jtreesitter.cfquery;

import io.github.cfmleditor.jtreesitter.NativeLibrary;
import java.lang.foreign.MemorySegment;
import java.lang.foreign.SymbolLookup;

/** The {@code cfquery} grammar: SQL with {@code #hash#} interpolation, as embedded in {@code <cfquery>}. */
public final class TreeSitterCfquery {
    private static final String SYMBOL = "tree_sitter_cfquery";
    private static final NativeLibrary LIBRARY = new NativeLibrary("tree-sitter-cfquery");

    private TreeSitterCfquery() {}

    /**
     * Get the tree-sitter language for this grammar.
     *
     * @return a pointer to the {@code TSLanguage}
     * @throws UnsatisfiedLinkError if {@code libtree-sitter-cfquery} cannot be found
     */
    public static MemorySegment language() {
        return LIBRARY.call(SYMBOL);
    }

    /**
     * Get the tree-sitter language for this grammar.
     *
     * <p><strong>The {@linkplain java.lang.foreign.Arena Arena} used in the {@code lookup}
     * must not be closed while the language is being used.</strong>
     *
     * @param lookup the symbol lookup to load the language from
     * @return a pointer to the {@code TSLanguage}
     * @throws UnsatisfiedLinkError if the symbol cannot be found
     */
    public static MemorySegment language(SymbolLookup lookup) {
        return NativeLibrary.call(lookup, SYMBOL);
    }
}
