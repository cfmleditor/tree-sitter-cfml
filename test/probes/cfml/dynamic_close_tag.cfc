<!--- Seen in: Taffy examples (anythingtoxml/ArrayToXML.cfc)
      <cfoutput><#node#>#value#</#node#></cfoutput> --->
<cfcomponent>
	<cffunction name="toXml" output="false">
		<cfoutput><#arguments.node#>#arguments.value#</#arguments.node#></cfoutput>
	</cffunction>
</cfcomponent>
