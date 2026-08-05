<!--- Seen in: Mura CMS / Slatwall data layers --->
<cfquery name="rs" datasource="#application.dsn#">
	SELECT contentid, title
	FROM   tcontent
	WHERE  siteid = <cfqueryparam cfsqltype="cf_sql_varchar" value="#arguments.siteid#">
	<cfif len( arguments.type )>
	AND    type = <cfqueryparam cfsqltype="cf_sql_varchar" value="#arguments.type#">
	</cfif>
	ORDER  BY #arguments.orderBy#
</cfquery>
