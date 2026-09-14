<!--- The whole tag opening written inside the `<cfif>` branches, with the
      shared attributes and the closing `>` after the `</cfif>`. Seen in:
      ContentBox contentbox-admin/views/settings/rawSettingsTable.cfm:102.
      Unlike its sibling probe this one is not merely expensive: the tag node
      and the conditional node would have to overlap, which a tree-sitter tree
      cannot represent. See LIMITATIONS.md and #119. --->
<cfif x>
	<a
		disabled="disabled"
<cfelse>
	<a
		class="confirmIt"
</cfif>
	title="Delete"
>
