<div test="color: #<cfoutput>#scrollHeight#</cfoutput>"></div>
<cfset result = "##" />

<cfset a = 1 />
<cfset b = "#a#" />
<cfset c = #a# />

<cfdump var="#[a, b, c]#">

<cfoutput>test<cfoutput>test</cfoutput>test</cfoutput>