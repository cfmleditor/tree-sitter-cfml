<!--- The same construct in a tag expression, where the cfml grammar's own
      copy of the script rules applies: a closure in a <cfset>. --->
<cfset copy = function( reader, cb ) {
	while( ( var size = reader.read( cb ) ) != -1 ) {
		writeOutput( size );
	}
}>
