// Seen in: Preside tests/unit/api/presideObjects/RelationshipGuidanceTest.cfc
//   var objects = { obj_a.meta = { … }, obj_b.meta = { … } };
component {

	function run() {
		var objects = {
			  obj_a.meta = { tableName="pobj_obj_a", properties = { id = { type="string" } } }
			, obj_b.meta = { tableName="pobj_obj_b", properties = { obj_a = { relatedTo="obj_a" } } }
		};
		var deep = { a.b.c = 1 };
	}

}
