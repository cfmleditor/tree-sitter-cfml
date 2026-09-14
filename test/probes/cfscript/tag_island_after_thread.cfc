// Seen in: lucee/Lucee test/tickets/LDEV4157/test4157.cfc.
//   thread name="t" { … }
//   ```
//   <cfset var res = "works">
//   ```
//   thread action="join" name="t";
// A ``` tag island after a statement that ends in `}` and omits its semicolon.
// The fence used to suppress the automatic semicolon — the JavaScript scanner
// this one descends from must not insert one before a template literal — so
// the `thread` statement came out MISSING ";". See #118, and
// cfml_template_after_bare_statement.cfc for the same cause after an
// expression statement.
component {

	function foo() {
		thread name="t" {
			thread.test = "thread";
		}

		```
			<cfset var res = "works">
		```
		thread action="join" name="t";

		return res;
	}

}
