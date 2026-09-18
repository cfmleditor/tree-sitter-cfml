// Seen in: lucee/Lucee test/tickets/LDEV4062/LDEV4062.cfm, whose own output
// string is "lambda expression works without body({})". An arrow function with
// no body at all; both spellings, with and without parameters.
//
// The controls matter as much as the construct here: spelling the body
// `optional()` in the grammar takes the empty reading for `() => obj.method( … )`
// and broke 13 cfwheels spec files, so a body that IS present is pinned too.
// See #116.
component {

	function f() {
		x = () => ;
		y = (a) -> ;
		expect( () => mod.create( a = 1 ) ).toThrow();
		return x;
	}

}
