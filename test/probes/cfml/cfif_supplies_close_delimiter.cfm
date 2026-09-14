<!--- A start tag whose closing `>` is written inside a `<cfif>` branch, so each
      branch supplies its own. Seen in: ContentBox
      contentbox-admin/views/authors/editor.cfm:43 (one `href` per branch).
      The spelling that keeps the `>` on the tag's own side —
      `<a <cfif x>href="a"<cfelse>href="b"</cfif>>` — parses, and no rule shape
      makes both work: see LIMITATIONS.md and #119. --->
<a
	title="Back"
	<cfif x>
		href="a">
	<cfelse>
		href="b">
	</cfif>
	Back</a>
