// Seen in: CommandBox (src/cfml/system/endpoints/*.cfc)
//   } catch( any var e ) {
component {

	function run() {
		try {
			doWork();
		} catch( any var e ) {
			rethrow;
		}
	}

}
