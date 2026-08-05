// Seen in: Lucee context/gateway/AsynchronousEvents.cfc
//   public function init( string id, Struct config, Component listener ) { ... }
component accessors=true {

	public function init( string id, Struct config, Component listener ) {
		variables.listener = arguments.listener;
		return this;
	}

}
