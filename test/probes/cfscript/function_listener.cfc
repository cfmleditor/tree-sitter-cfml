// Seen in: Lucee test suite (test/general/FunctionListener.cfc)
//   var t = mySuccess():function(result,error) { … }
// The call runs on a background thread and the listener receives its result.
// Lucee accepts a function literal, a struct of onSuccess/onFail, a component
// instance or a variable holding one of those.
component {

	function run() {
		var t1 = mySuccess():function( result, error ) {
			variables.testFunctionListenerV = result;
		};
		var t2 = arrayLen( [ 1, 2, 3 ] ):function( result, error ) {};
		var t3 = local.a.b.c.d():function( result, error ) {};
		var t4 = Query::new( [ "columnName" ] ):function( result, error ) {};
		var t5 = mySuccess():coll1;
		var t6 = myError():{
			onSuccess: function( result ) {}
			,onFail: function( result, error ) {}
		};
		var t7 = logAndFail( "testStruct", "Ruedi Zraggen" ):{};
		var t8 = logAndFail( "testNull", "Peter Lustig" ):nullValue();

		// "Component Listener" — a `new` on the LISTENER side of the colon.
		// Not in the corpus at all; only the documentation has it.
		var t9 = mySuccess():new component {
			function onSuccess( result ) {
				thread.success = result;
			}
		};
		var t10 = logAndFail( "testStruct", "Ruedi Zraggen" ):new component {};
	}

}
