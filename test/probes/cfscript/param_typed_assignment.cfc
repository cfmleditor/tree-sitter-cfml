// Seen in: RustCFML tests/tags/test_tags_param.cfm
//   param numeric shortBad = "abc";
// `param_typed.cfm` covers `param numeric x default="…"`, which parses. The
// `=` spelling of the same shorthand does not — the default is only reachable
// through the `default=` attribute.
component {

	function run() {
		param numeric shortBad = "abc";
		param string label = "x";
		return shortBad;
	}

}
