// Seen in: Mura beanORM.cfc, Preside Renderer.cfc, Slatwall account.cfc,
// Lucee tickets LDEV1718 / LDEV2266 / LDEV0852.
//   var loadArgs[ getPrimaryKey() ] = getValue( x );
component {

	function run() {
		var loadArgs[ getPrimaryKey() ] = getValue( "x" );
		var orderParams['F:account_accountID'] = rc.accountID;
		var mappings[ mapping ] = viewDir & "/" & mapping;
	}

}
