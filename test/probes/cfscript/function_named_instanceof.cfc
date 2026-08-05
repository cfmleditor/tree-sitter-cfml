// Seen in: ColdBox system/aop/Matcher.cfc, TestBox system/Assertion.cfc
//   function instanceOf( required classPath ){ ... }
component {

	function instanceOf( required classPath ) {
		variables.instanceOf = arguments.classPath;
		return this;
	}

}
