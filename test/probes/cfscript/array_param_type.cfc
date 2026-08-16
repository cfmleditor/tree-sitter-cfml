// Seen in: RustCFML tests/functions/test_fn_type_enforcement.cfm
//   function argStringArray( string[] v ) { return "ok"; }
// The mirror image of `array_return_type.cfc`, which parses: the `X[]` type
// works in return position but not in parameter position. The nested
// `string[][]` form fails the same way.
component {

	function argStringArray( string[] v ) {
		return "ok";
	}

	function argNestedArray( string[][] v ) {
		return "ok";
	}

}
