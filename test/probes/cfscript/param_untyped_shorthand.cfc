// Seen in: Lucee test/jira/Jira2605/index.cfm (`param url.number;`)
// The typed shorthand (`param numeric x;`) and the attribute form
// (`param name="x" type="numeric";`) both parse; the untyped shorthand did not.
// Two bare identifiers cannot be told apart as type-vs-name, so the name has to
// be its own branch or it gets labelled a `parameter_type`.
component {

	function run() {
		param x;
		param url.number;
		param numeric typed;
		return x;
	}

}
