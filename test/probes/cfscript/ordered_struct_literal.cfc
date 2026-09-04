// Seen in: Lucee test/tickets/LDEV3133/test.cfm
//   animals = ${ Aardwolf: "Proteles cristata", … }
//   animals = $[ Aardwolf: "Proteles cristata", … ]
// Lucee's ordered-struct literals, which preserve insertion order where a plain
// `{ … }` does not — that file asserts `structKeyList` comes back in source
// order. It writes BOTH spellings side by side as scenes 4 and 5, so they are
// one feature, not two.
//
// `$[ … ]` previously looked supported and was not: `$` lexed as an ordinary
// identifier, so `$[ x: 1 ]` gave the same tree as `q[ x: 1 ]` — a subscript
// with a slice inside, error-free and wrong.
component {

	function run() {
		var brace = ${
			Aardwolf: "Proteles cristata",
			aardvark: "Orycteropus afer"
		};
		var bracket = $[
			Aardwolf: "Proteles cristata",
			aardvark: "Orycteropus afer"
		];
		var equals = ${ key = "value" };
		var emptyBrace = ${};
		var emptyBracket = $[];
		var emptyColon = [:];

		// Neighbours the two new openers must not swallow.
		var plain = { x: 1 };
		var arr = [ 1, 2 ];
		var slice = q[ x: 1 ];
		var dollar = $;
		var dollarMember = $.foo;
	}

}
