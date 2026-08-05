// Seen in: Lucee test suite (test/tickets/LDEV0280, Issue0275)
component {

	static {
		static.counter = 0;
	}

	function run() {
		return static.counter;
	}

}
