<!--- Seen in: ColdBox tests/perf-harness/PerformanceSuite.cfc
      A bare `#` inside a cfscript string. CFML requires `##`, so this is an
      error in the engines too — it is here to pin the blast radius. --->
<cfscript>
	md.append( "# ColdBox Performance Analysis Report" );
	md.append( "" );
</cfscript>
