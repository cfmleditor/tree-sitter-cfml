// Seen in: Lucee test/tickets/LDEV1835/interface.cfc
// `default` is a declaration modifier, not interface-only: it is accepted on a
// component too, and with or without an access modifier in front. It is also a
// switch label, which is the whole difficulty — see switch_case/switch_default.
interface {

	public default any function returnsAny( any obj ) {
		return obj;
	}

	default any function alsoDefault( any obj ) {
		return obj;
	}

}
