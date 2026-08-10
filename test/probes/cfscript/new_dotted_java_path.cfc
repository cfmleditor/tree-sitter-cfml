// Seen in: Lucee LDEV5120, LDEV4156, LDEV5660, NewOperator.cfc.
//   new java.util.prefs.BackingStoreException( "x" )
// `java` and `cfml` are also the `new java:` / `new cfml:` type prefixes, so a
// bare token for them out-lexed the identifier straight after `new`.
component {

	function run() {
		var a = new java.util.Properties();
		var b = new java.util.prefs.BackingStoreException( "x" );
		var c = new cfml.Widget();
		var d = new java:java.io.File( path );
	}

}
