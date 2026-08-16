// Seen in: RustCFML tests/core/test_comma_less_params.cfm
//   function f( boolean a = false <newline> boolean b = true ) { … }
// Lucee/ACF/BoxLang treat a newline between parameters as a soft separator and
// tolerate the missing comma; TestBox's BaseSpec.cfc `createMock` relies on it.
// Parses in the embedded CFScript grammar (common/define-grammar.js), not in
// the standalone one.
component {

	function f(
		boolean a = false
		boolean b = true
	) {
		return a & "-" & b;
	}

	function g(
		required string name
		numeric count = 5
	) {
		return name & count;
	}

}
