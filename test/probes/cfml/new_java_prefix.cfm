<!--- The `new java:` / `new cfml:` type prefix, which cfscript accepted but the
      shared cfml grammar did not — a drift between the two CFScript rule sets
      rather than a gap in either. --->
<cfset x = new java:java.io.File( expandPath( "." ) )>
<cfset y = new cfml:foo.Bar()>
<cfset z = new java.util.Properties()>
