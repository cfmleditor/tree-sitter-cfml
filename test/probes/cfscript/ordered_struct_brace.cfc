// Seen in: lucee/Lucee test/tickets/LDEV3133/test.cfm:5, `animals=${ … }` —
// the populated ordered-struct literal. The empty forms `[:]` and `[=]` already
// parsed.
//
// `$[ … ]` is deliberately NOT this construct: `$` is a legal variable name, so
// a bracket after it is an ordinary array-style reference and stays a
// subscript_expression. That is why `$[ 1 ]`, a bare `$` and `$( … )` are
// pinned here alongside the struct. See #80.
component {

	function f() {
		animals = ${ Aardwolf: "Proteles cristata", aardvark: "Orycteropus afer" };
		empty   = ${};
		first   = $[ 1 ];
		$       = 1;
		return animals;
	}

}
