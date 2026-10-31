// Seen in: Lucee test/functions/DirectoryCreate.cfc
// A tag comment after the closing brace of a block-bodied tag statement. The
// block ended the statement, but the grammar demanded a `;` there, so the
// comment's `<` was not offered to the scanner and read as less-than.
component {

	function run() {
		cflock( name = "x" ) {
		}
		<!--- end old test code --->
		cftransaction() {
		}
		<!--- c --->
		thread name = "t" {
		}
		<!--- c --->
		x = 1;
	}

}
