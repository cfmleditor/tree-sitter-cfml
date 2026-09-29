<!--- An HTML/XML tag name containing `.`: IIS web.config content built in
      cfsavecontent (#169). The end tag used to match nothing, and the ERROR
      swallowed every cffunction after it. --->
<cfcomponent>
<cffunction name="a"><cfsavecontent variable="s"><system.webServer><x/></system.webServer></cfsavecontent></cffunction>
<cffunction name="b"><cfoutput><a.b></a.b></cfoutput></cffunction>
</cfcomponent>
