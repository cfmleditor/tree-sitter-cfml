// Seen in: Preside tests/unit/api/presideObjects/RelationshipGuidanceTest.cfc,
// RustCFML tests/types/test_dotted_key_struct_literals.cfm, Lucee LDEV3113.cfc.
// An unquoted dotted key builds a nested struct: `{ a.b = 1 }` is `{ a = { b = 1 } }`.
// A quoted key (`{ "a.b" = 1 }`) is one key with a dot in its name.
component {
	function f() {
		var objects = {
			  obj_a.meta = { tableName = "pobj_obj_a" }
			, obj_b.meta = { tableName = "pobj_obj_b" }
		};
		var colon = { c.d: "test" };
		return objects;
	}
}
