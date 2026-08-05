// Seen in: cbfeeds (FeedReader.cfc), Lucee test suite
//   }Catch(Any e){
component {

	function run() {
		Try {
			doWork();
		}Catch(Any e){
			WriteOutput( e.message );
		}
	}

}
