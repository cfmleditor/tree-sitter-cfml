// Seen in: Lucee's function-listener documentation, not in the corpus.
//   https://docs.lucee.org/recipes/function-listeners.html  (since 6.1)
//   lucee/lucee-docs -> docs/recipes/function-listeners.md
//
// KNOWN GAP (issue #98), the last of the eleven documented forms that does not
// parse.
// "Listening on a Component Instantiation": a `new` expression as the listener
// TARGET, i.e. before the colon. The listener side was the other half of this
// probe and now parses (see function_listener.cfc); the two halves cost very
// differently, which is why only one shipped:
//
//   listener  `f():new component { … }`      +27 states  (+0.5%), 0 conflicts
//   target    `new Query():f(){ … }`        +591 states (+11.3%), 2 conflicts
//
// A bare `new` is itself a complete `new_expression`, so admitting it before a
// `:` makes `New` ambiguous with a label and a property name wherever those are
// live, and the whole new-expression item set forks. Three narrowings were
// measured and none helped; the numbers are in LIMITATIONS.md.
component {

	function run() {
		var threadName = new Query():function( result, error ) {
			thread.result = result;
		};
		var threadName2 = new org.lucee.cfml.Query():function( result, error ) {
			thread.result = result;
		};
	}

}
