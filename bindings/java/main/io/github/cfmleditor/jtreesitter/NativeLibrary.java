package io.github.cfmleditor.jtreesitter;

import java.lang.foreign.Arena;
import java.lang.foreign.FunctionDescriptor;
import java.lang.foreign.Linker;
import java.lang.foreign.MemoryLayout;
import java.lang.foreign.MemorySegment;
import java.lang.foreign.SymbolLookup;
import java.lang.foreign.ValueLayout;

/**
 * Resolves {@code tree_sitter_*} language functions out of a native library.
 *
 * <p>This repository ships three grammars, each built as its own shared
 * library, so the per-grammar classes ({@code TreeSitterCfml} and friends)
 * each hold one instance of this class. It is an implementation detail of
 * those classes rather than part of the supported API.
 */
public final class NativeLibrary {
    private static final ValueLayout VOID_PTR =
            ValueLayout.ADDRESS.withTargetLayout(MemoryLayout.sequenceLayout(Long.MAX_VALUE, ValueLayout.JAVA_BYTE));
    private static final FunctionDescriptor FUNC_DESC = FunctionDescriptor.of(VOID_PTR);
    private static final Linker LINKER = Linker.nativeLinker();

    private final Arena arena = Arena.ofAuto();
    private final String libraryName;
    private volatile SymbolLookup lookup = null;

    /**
     * Create a loader for the given library.
     *
     * @param libraryName the library name without prefix or extension, e.g. {@code tree-sitter-cfml}
     */
    public NativeLibrary(String libraryName) {
        this.libraryName = libraryName;
    }

    /**
     * Call a niladic function returning a pointer, loading the library on first use.
     *
     * @param name the symbol to call, e.g. {@code tree_sitter_cfml}
     * @return the returned pointer
     * @throws UnsatisfiedLinkError if the library or the symbol cannot be found
     */
    public MemorySegment call(String name) {
        var current = lookup;
        if (current == null) {
            synchronized (this) {
                current = lookup;
                if (current == null) {
                    lookup = current = findLibrary();
                }
            }
        }
        return call(current, name);
    }

    /**
     * Call a niladic function returning a pointer, using a caller-supplied lookup.
     *
     * <p><strong>The {@linkplain Arena} used in the {@code lookup}
     * must not be closed while the language is being used.</strong>
     *
     * @param lookup the symbol lookup to resolve {@code name} in
     * @param name the symbol to call, e.g. {@code tree_sitter_cfml}
     * @return the returned pointer
     * @throws UnsatisfiedLinkError if the symbol cannot be found
     */
    public static MemorySegment call(SymbolLookup lookup, String name) {
        var address = lookup.find(name).orElseThrow(() -> unresolved(name));
        try {
            var function = LINKER.downcallHandle(address, FUNC_DESC);
            return (MemorySegment) function.invokeExact();
        } catch (Throwable e) {
            throw new RuntimeException("Call to %s failed".formatted(name), e);
        }
    }

    // libraryLookup goes through the OS loader (LD_LIBRARY_PATH and friends);
    // loadLibrary goes through java.library.path. Try both before giving up,
    // since which one finds the library depends on how it was installed.
    private SymbolLookup findLibrary() {
        try {
            var library = System.mapLibraryName(libraryName);
            return SymbolLookup.libraryLookup(library, arena);
        } catch (IllegalArgumentException ex1) {
            try {
                System.loadLibrary(libraryName);
                return SymbolLookup.loaderLookup();
            } catch (UnsatisfiedLinkError ex2) {
                ex1.addSuppressed(ex2);
                throw ex1;
            }
        }
    }

    private static UnsatisfiedLinkError unresolved(String name) {
        return new UnsatisfiedLinkError("Unresolved symbol: %s".formatted(name));
    }
}
