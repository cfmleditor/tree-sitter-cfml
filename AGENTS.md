# AGENTS

**Purpose:** Help agents complete work **accurately and efficiently** with minimal human interaction. This file is **model- and tool-agnostic** (plain Markdown for any AI assistant or human). **Enforceable** policies (clarification, MUST APPLY capture, deduplication) live in **`.cursor/rules/agent-must-apply-and-clarification.mdc`** - do not restate them here; that path is **Cursor-specific** (reusing those rules elsewhere: [`README.md`](README.md#agent-and-ai-assistant-guidance)).

**Project setup, build, test, and grammar layout:** [`README.md`](README.md).

---

## Workflow

1. **Tight scope** - Confirm what "done" means, constraints, and which grammars or paths are in scope before large edits.

2. **Tiered batches** - Default to **2-4 related sub-tasks** that share dependencies or one failure mode, then verify at a **natural seam** (not one micro-edit per turn, not one giant unverified dump).

3. **Verify at seams** - Run tests / parser checks after a logical unit of work so mistakes do not propagate.

4. **Order by dependency** - Foundation first (grammar, shared externals), verify, then dependent layers.

5. **Cheap follow-ups** - Use paths and minimal failing output; avoid re-explaining the whole repository each turn.

6. **Bias accuracy over minimum turns** when unsure - Rework from huge single diffs usually costs more than smaller verified batches.

---

## Done criteria

- **`tree-sitter test`** and project scripts (e.g. **`npm test`**) pass as required for the change.
- **Done stage:** Grammars, corpus, playground, build scripts, and documentation match the **current** repository state. The repo should be **shippable** - treat a typical PR like a release unless the human specifies otherwise.
- **Generated artifacts** (e.g. parsers under grammar `src/`, bindings as applicable): **fully accurate and committed** at the **Done** point only. Interim steps do not need release-ready artifacts; **Done** does.

---

## CFML runtime and portability

- **Testing:** When a CFML engine is needed (sample code, fixtures, reproductions, or manual checks), use **[Lucee](https://lucee.org/)** as the runtime for testing - not Adobe ColdFusion as a requirement.
- **Lucee documentation (online):** [https://docs.lucee.org/](https://docs.lucee.org/)
- **Portability:** Do **not** design examples or grammar-related assumptions around **Adobe-specific** behavior; targeting Adobe is **not** required. At the same time, **do not** rely on **Lucee-only** features (functions, settings, or semantics that exist only on Lucee). Prefer **portable CFML** that would be reasonable across common engines, so the project stays useful beyond a single vendor.

---

## CI and local parity

Keep toolchain versions aligned with **CI** whenever possible. If a version **must** differ to achieve the goal, say so explicitly (e.g. in commit message or PR description).

---

## Tradeoffs and handoff

If **token budget** conflicts with **correctness**, do the **minimum** that leaves the repo in a **working** state and record what remains so a **new** chat session can continue **without** re-asking the human (e.g. a short note in the task artifact or a follow-up item).

---

## Updating this file

**Do not** add a new section or bullet here if the same intent is already covered by an existing **`AGENTS.md`** item or by a rule under **`.cursor/rules/`**.
