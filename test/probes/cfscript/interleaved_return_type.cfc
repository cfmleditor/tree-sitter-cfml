// Seen in: lucee/Lucee test/general/modifiers/All.cfc, the file whose whole
// purpose is enumerating modifier spellings. A return type written between two
// modifiers rather than before or after the run. The type-first spelling landed
// in #88; this is the third position. See #117.
component {

	public struct static function a() {}

	final whatever package function b() {}

	package whatever final function c() {}

}
