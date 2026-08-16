// Seen in: RustCFML tests/core/test_reserved_word_param_names.cfm, reduced from
// ColdBox coldbox.system.core.util.Util.cfc — `<cfargument name="in" type="array">`
//   function arrToStr( array in ) { return arguments.in; }
// The untyped form `function p_in( in )` already parses; adding the type in
// front of the reserved-word name is what fails. Only `in` is affected —
// `do`, `for`, `eq` and `is` take a type fine.
component {

	function typed_in( array in ) {
		return arguments.in[ 1 ];
	}

}
