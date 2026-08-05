<!--- Seen in: TestBox system/reports/assets/mintext.cfm --->
<cfoutput>#getHeaderBanner( testbox )#
<cfloop array="#variables.bundleStats#" index="thisBundle">
<cfif len( url.testBundles )>
<cfcontinue>
</cfif>
#thisBundle.path#
</cfloop>
</cfoutput>
