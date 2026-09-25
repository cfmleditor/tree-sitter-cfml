// `var jql &= ' ORDER BY key DESC';` — a `var` declaration whose initializer is
// a compound assignment rather than a plain one, against a name already
// declared with `var` earlier in the same function.
//
// Lucee's own core/src/main/cfml/context/admin/Jira.cfc does this, as do
// Slatwall's SmartList.cfc and Product.cfc and CommandBox's Print.cfc.
component {

	function build( array stati ) {
		var jql = "project = x";
		if ( arrayLen( stati ) ) {
			jql &= " AND status in ()";
		}
		var jql &= " ORDER BY key DESC";

		var total = 0;
		var total += getReviews()[ 1 ].getRating();

		var local.note = "a";
		var local.note &= "b";

		return jql;
	}

	// The plain forms must keep working unchanged.
	function controls() {
		var a = 1, b = 2;
		var mappings[ key ] = value;
		var new = 1;
		var bare;
		bare &= "no var";
		return a;
	}

}
