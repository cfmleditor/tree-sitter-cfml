// Seen in: Lucee test suite and admin context
//   cfdirectory( directory="#dir#" action="create" mode="777" );
component {

	function run() {
		cfdirectory( directory="#getTempDirectory()#" action="create" mode="777" );
		cfheader( statuscode="404" statustext="Invalid access" );
	}

}
