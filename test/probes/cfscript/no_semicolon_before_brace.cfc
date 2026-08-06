// Seen in: ColdBox system/web/context/InterceptorState.cfc
// ColdBox style omits statement semicolons; the last statement in a block then
// has to get one inserted, which the tag-statement lookahead used to suppress.
component {

	function run() {
		try {
			process()
		} catch ( any e ) {
			announce( "onException", { exception : e } )
			rethrow
		}
	}

}
