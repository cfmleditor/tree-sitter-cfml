// Seen in: lucee/Lucee test/tickets/_LDEV3623.cfc:22,
//   greeting = savecontent { writeOutput("G'day World") }
// savecontent in expression position, where the block's output is the value.
// The statement form, `savecontent variable="g" { … }`, is a different rule —
// it goes through the generic tag_statement with `savecontent` as an ordinary
// identifier — and is pinned here too, because the first attempt at #82 broke
// exactly that. See #82.
component {

	function f() {
		greeting = savecontent { writeOutput( "G'day World" ) };
		savecontent variable="g" { writeOutput( "hi" ) }
		return greeting & g;
	}

}
