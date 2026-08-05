<!--- Seen in: ColdBox tests/suites/eventCachingCollisions/Application.cfc,
      Mura admin templates --->
<cfcomponent output="false">
	<cfset COLDBOX_CONFIG_FILE = "">

	<cfsetting showdebugoutput="false">

	<cffunction name="onRequestStart"><cfreturn true></cffunction>
</cfcomponent>
