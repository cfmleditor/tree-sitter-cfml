## CFML Parser Enhancements Roadmap

This document tracks planned improvements for the CFML/CFHTML/CFScript Tree-sitter grammars, informed by `tree-sitter-javascript`, `tree-sitter-typescript`, `tree-sitter-html`, and the Lucee CFML ecosystem. The overarching goal is to provide the **best, most flexible CFML parser**, where the grammar is the primary asset for downstream tools.

### 1. Stronger semantic node model

- **Richer function/method modeling**
  - Distinguish more precisely between tag-based functions (`<cffunction>`), script functions, component methods, and closures.
  - Expose structured fields for modifiers and metadata (access, return type, output, hint, displayname, abstract, final, etc.).
- **Components as first-class entities**
  - Model component bodies like classes: explicit nodes for properties, methods, and metadata.
- **Better type hint structure**
  - Represent CFML type hints (argument types, return types, struct/array types) as dedicated type nodes, inspired by TypeScript’s type grammar but aligned with CFML semantics.

### 2. Scope- and keyword-awareness

- Treat common CFML scopes (`variables`, `arguments`, `session`, `application`, etc.) as contextual keywords in appropriate positions.
- Introduce dedicated nodes for scope-qualified identifiers (e.g. `cf_scope_identifier`) so tooling can reason about scope usage.
- Carefully expand contextual keyword support (e.g. `component`, `interface`, `property`) where unambiguous, without over-reserving identifiers.

### 3. Improved error recovery and robustness

- Add targeted error-recovery productions (similar to `__error_recovery` patterns in JS/TS) to:
  - Recover from malformed attributes or expressions inside tags.
  - Handle unclosed tags and control structures more gracefully.
- Make CF query parsing more forgiving so large templates with partial errors still produce mostly usable trees.

### 4. Query (.scm) enhancements for editor UX

- **Highlights**
  - Expand highlight queries to classify CFML scopes, tags, functions, operators, and built-in functions with more granular captures.
  - Add context-sensitive captures for names (e.g. component names, function names, tag attribute names and values).
- **Tags / symbols**
  - Enhance `tags.scm` so symbol outlines show components, functions, important CF tags, and queries with appropriate kinds (`@definition.class`, `@definition.function`, `@definition.tag`, etc.).
- **Indents**
  - Refine indentation queries for CF control tags (`cfif`, `cfloop`, `cftry`, `cfcatch`, `cfcase`, etc.) and mixed script/tag code to match expectations from modern JS/TS grammars.

### 5. Language injections and embedded languages

- Add injection queries for embedded languages:
  - SQL inside `cfquery` bodies.
  - JavaScript inside `<script>` tags and `on*=` attributes.
  - CSS inside `<style>` tags and style attributes.
- Use Tree-sitter-compatible injection patterns where supported by clients.

### 6. Coverage of edge-case CFML constructs

- Audit and ensure coverage (and tests) for:
  - Less common CF tags (`cfthread`, `cflock`, `cfmail`, `cfchart`, etc.).
  - Expression quirks (struct/array literals, member functions vs tag-based APIs, named vs positional arguments).
- For each new construct:
  - Add or adjust grammar rules.
  - Add corpus examples in the appropriate `cfml` / `cfscript` test files.

### 7. Performance and maintainability

- Periodically run performance checks (`tree-sitter parse` on large CFML templates) to identify slow paths.
- Where needed:
  - Reduce ambiguity using precedences or conflict hints.
  - Simplify heavily backtracking rules (especially around hash expressions and tag attributes).
- Continue to factor the grammar into small, focused helper nonterminals to keep it understandable and extensible.

### 8. Documentation and tooling integration

- Maintain a short, versioned feature matrix describing which CFML/Lucee features are fully supported by the grammar.
- Provide a user-facing node type reference (derived from `node-types.json`) to aid LSPs, editors, and other tooling in consuming the parse trees.

