// Seen in: CommandBox system/util/FileSystem.cfc, MultiSelect.cfc,
// ProgressableDownloader.cfc and system-commands/commands/run.cfc
//   while( ( var size = reader.read( cb ) ) != -1 ) { … }
// Lucee reads `var <name>` as a local-scope variable anywhere a variable can
// go (AbstrCFMLExprTransformer.scope), so the assignment in the condition both
// declares and tests.
component {

	function copy( reader, cb ) {
		while( ( var size = reader.read( cb ) ) != -1 ) {
			writeOutput( size );
		}
		while( var key = next() ) {
			writeOutput( key );
		}
	}

}
