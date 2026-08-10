// Seen in: coldbox-modules/cbjavaloader BXLoader.cfc:77.
//   return getRequestClassLoader().getURLs().map( target -> target.toString() )
// Lucee spells a closure `=>` and a lambda `->`; only `=>` was in the grammar.
component {

	function run() {
		var a = t -> t.b();
		var b = ( x, y ) -> x + y;
		var c = t -> { return t.b(); };
		var d = getURLs().map( target -> target.toString() );
		var e = arr.filter( (i) -> i > 0 ).map( j -> j * 2 );
		return a;
	}

}
