// Seen in: Lucee test/functions/StructToSorted.cfc and test/functions/structsort.cfc
//   variables.myNumb = StructNew();
//   myNumb.4 = "4";
//   myNumb.3 = "3";
// A struct key that is not a valid identifier, assigned through dot notation.
//
// The read position always worked, which is what #86 was filed on. The cause is
// not the property rule — `identifier` is a permissive negated class that
// happily matches `4` — but the NUMBER token: `.4` is a legal leading-dot float
// (`x = .5` is real CFML), and as the longer match it out-lexed `.` followed by
// a property wherever a number was also valid. At a statement head the
// tag_statement reading keeps a number valid, so `myNumb.4 = 1` died while
// `var myNumb.4 = 1` and `a.b.4 = 1` both parsed — those commit the parser and
// take the tag reading out of play.
component {

	function run() {
		variables.myNumb = structNew();
		myNumb.4 = "4";
		myNumb.3 = "3";
		myNumb.4b = "4b";
		myNumb.4.5 = "nested";

		// Leading-dot floats must still be numbers, everywhere a number can go.
		var a = .5;
		var b = 1 + .5;
		var c = [ .5, .25 ];
		var d = -.0123456789;
		var e = .5e3;
		writeOutput( .75 );
	}

}
