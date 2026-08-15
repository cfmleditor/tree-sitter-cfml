// Seen in: ortus-boxlang/BoxLang QoQColumnNameTest.cfc:9.
//   var q1 = queryNew( "col" )
//   ```
//   <cfquery …>…</cfquery>
//   ```
// A ``` template fence directly after a statement that omits its semicolon.
// The `cfml_template` itself parses; what the statement before it recovers as
// is the open question, so this probe tracks that recovery rather than the
// fence. It moved from an ERROR wrapping the declaration to a MISSING ";"
// when the scanner stopped scanning for a closing fence during error recovery.
component {

	function run() {
		var q = queryNew( "col" )
		```
		<cfquery name="local.r" dbtype="query">SELECT col FROM q</cfquery>
		```
		return q;
	}

}
