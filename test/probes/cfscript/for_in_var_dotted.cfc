// Seen in: RustCFML tests/core/test_forin_keyword_member_access.cfm
//   for ( var local.package in items ) { … }
// A dotted loop variable is fine without `var` (`for ( local.pkg in items )`)
// and a plain name is fine with it (`for ( var pkg in items )`); only the
// combination fails.
component {

	function runForInKeyword( items ) {
		for ( var local.package in items ) {
			writeOutput( local.package );
		}
		return local.package;
	}

}
