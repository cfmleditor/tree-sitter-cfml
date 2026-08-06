// Seen in: Lucee test/tickets/LDEV3133 (`$[ Aardwolf:"...", aardvark:"..." ]`)
// A subscript index holding more than one pair. `master` parsed it as a
// sequence of pairs; `slice_expression` covers the single-colon form only.
// Not idiomatic CFML — Lucee uses it in a parser ticket.
component {

	function run() {
		return a[ b: "c", d: "e" ];
	}

}
