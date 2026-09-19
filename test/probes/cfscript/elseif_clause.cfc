// `elseif` written as one word, beside the two-word `else if`.
// Lucee's own core/src/main/java/resource/component/org/lucee/cfml/Query.cfc,
// cfwheels' vendor/wheels/Public.cfc, CommandBox's server/status.cfc and
// Preside's admin/emailCenter/Layouts.cfc all use it.
//
// Before the fix this parsed CLEANLY with the wrong tree: `elseif ( c )` became
// a call or a tag_statement and the branch became a sibling rather than an
// alternative, so only 2 of the 5 corpus files ever reported an error.
component {

	function chain( x ) {
		if ( x == 1 ) {
			return "one";
		}
		elseif ( x == 2 ) {
			return "two";
		}
		elseif ( x == 3 ) {
			return "three";
		}
		else {
			return "many";
		}
	}

	// `elseif` keeps its identifier reading everywhere else.
	function identifiers() {
		elseif = 1;
		elseif();
		var also = { elseif: 2 };
		return also.elseif;
	}

}
