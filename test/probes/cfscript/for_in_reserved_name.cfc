// Seen in: Preside ScheduledExportService.cfc (`for ( var export in … )`),
// cfwheels performance.cfc (`for ( var query in … )`)
// A keyword-shaped loop variable in a for-in header.
component {

	function run() {
		for ( var export in nonRunningExports ) {
			runExport( export.id );
		}
		for ( var query in request.wheels.queries ) {
			log( query.sql );
		}
	}

}
