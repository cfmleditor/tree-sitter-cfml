
<cfset result = "##" />

<cfset a = 1 />
<cfset b = "#a#" />
<cfset c = #a# />

<cfdump var="#[a, b, c]#">

<cfoutput>test<cfoutput>test</cfoutput>test</cfoutput>