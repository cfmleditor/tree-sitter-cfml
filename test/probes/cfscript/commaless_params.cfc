// Seen in: RustCFML tests/core/test_comma_less_params.cfm
//   function f( boolean a = false <newline> boolean b = true ) { … }
// Lucee/ACF/BoxLang treat a newline between parameters as a soft separator and
// tolerate the missing comma; TestBox's BaseSpec.cfc `createMock` relies on it.
// NOT supported in either grammar before this fix. An earlier note here claimed
// it "parses in the embedded CFScript grammar (common/define-grammar.js)"; that
// was measured by parsing a `<cfscript>` block with the `cfml` grammar, where
// the body is opaque `cf_script_content` and literal garbage passes too. Where
// that copy of the rules IS reachable — `<cfset f = function(…){}>` and `#…#` —
// it failed the same way. The two rule definitions were character-identical.
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
