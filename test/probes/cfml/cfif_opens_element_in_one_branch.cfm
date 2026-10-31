<!--- Seen in: Galaxie Blog includes/templates/blogContentCss.cfm:58
      An element opened in one <cfif> branch only; its end tag follows the
      </cfif>. An engine runs the <cfif> first, so the output is well formed.
      A tree cannot represent it. Recorded `fail` on purpose: a decision to
      leave it unsupported, kept for later consideration (#119). --->
<cfif not standAlone>
<style>
<cfelse>
<cfcontent type="text/css" />
</cfif>
a { color: red }
</style>
