// Seen in: ContentBox build patches, CommandBox ServerService.cfc, Lucee tests
//   var local.thisPerm = permissionService.findWhere( { permission = x } );
component {

	function run() {
		var local.thisPerm = getService().findWhere( { permission = "admin" } );
		var a.b.c.d        = 1;
		return local.thisPerm;
	}

}
