// Seen in: Lucee test suite (test/general/StaticMembersInvoke.cfc)
//   java:java.lang.Double::valueOf("123")
//   cfml:Query::new( … )
// The `java:` / `cfml:` prefix names the type SYSTEM a static call resolves
// against, the same prefix `new java:foo.Bar()` takes. Without it the parser
// read `java:` as a label or a struct key and dropped the static call.
component {

	function run() {
		var a = cfml:Query::new( [ "columnName" ] );
		var b = java:java.lang.Double::valueOf( "123" );
		var c = JAVA:java.lang.System::currentTimeMillis();
		cfml:Query::new( [ "x" ] );

		// Neighbours the prefix must NOT swallow: the colon only makes a prefix
		// when a dotted name and `::` follow it.
		cfml: while ( true ) { break cfml; }
		var d = { cfml: 1, java: 2 };
		var e = new cfml:Query();
		var f = javaCast( "int", 1 );
		var g = cfml::foo();
	}

}
