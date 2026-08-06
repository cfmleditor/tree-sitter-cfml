<!--- Seen in: ColdBox tests/suites/eventCachingCollisions/Application.cfc,
      Mura admin templates.
      `<cfsetting>` is a void tag — `</cfsetting>` does not appear once in the
      12,549-file corpus — so it must not swallow what follows. --->
<cfcomponent output="false">
	<cfset COLDBOX_CONFIG_FILE = "">

	<cfsetting showdebugoutput="false">

	<cffunction name="onRequestStart"><cfreturn true></cffunction>
</cfcomponent>
