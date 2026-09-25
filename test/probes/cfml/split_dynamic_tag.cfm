<!--- Seen in: Taffy examples (anythingtoxml/ArrayToXML.cfc and friends, 8 files)
      A dynamic tag opened in one <cfoutput> and closed in a later one. The
      open tag's element ends with its block, so the close tag has nothing to
      pair with; it should be an erroneous_end_tag, as a stray </p> is. --->
<cfsetting enablecfoutputonly="yes">
<cfoutput>#tabs()#<#nodeName(root)# <cfif hint eq 1>CF_TYPE='array'</cfif>></cfoutput>
	<cfoutput>#body()#</cfoutput>
<cfoutput>#tabs()#</#nodeName(root)#></cfoutput>
