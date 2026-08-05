// Seen in: Lucee test suite (test/tickets/LDEV4374)
//   mystring[4:13]  /  mystring[4:13:2]  /  mystring[-10:-4]
component {

	function run() {
		var mystring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		writeOutput( mystring[ 4:13 ] );
		writeOutput( mystring[ 4:13:2 ] );
		writeOutput( mystring[ -10:-4 ] );
		writeOutput( mystring[ -10:-4:2 ] );
	}

}
