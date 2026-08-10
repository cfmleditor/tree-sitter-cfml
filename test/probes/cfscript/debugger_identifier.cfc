// Seen in: Preside preside-ext-saml2-sso Saml2.cfc.
//   debugger.log( argumentCollection=logArgs );
// `debugger` is a JS leftover statement keyword that CFML does not have,
// but it is a perfectly ordinary variable name in CFML code.
component {

	function run() {
		debugger.log( argumentCollection={ text="x" } );
		debugger.log();
		debugger = 1;
		debugger.a.b = 2;
		var x = debugger.enabled;
	}

}
