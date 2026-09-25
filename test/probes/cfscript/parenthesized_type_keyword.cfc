// A CFML built-in type name used as an ordinary expression inside parentheses.
// `x = date` always parsed; `x = (date)` was an ERROR, because inside `(` the
// arrow-function reading keeps `formal_parameters` alive and the word lexed at
// parameter-start, where `parameter_type` spelled it as a keyword token.
//
// Reduced from Preside's system/services/l10n/DateFormatService.cfc, where the
// real shape is `( date[ 2 ] > 0 && date[ 2 ] <= ArrayLen( a ) )`.
component {

	function ordinal( required date date ) {
		var ordinalTypeA = [ "st", "nd", "rd" ];
		var ordinal      = "th"
		var date         = DateFormat( arguments.date, "dd" );

		if ( ( Val( date[1] ) != 1 ) && ( date[ 2 ] > 0 && date[ 2 ] <= ArrayLen( ordinalTypeA ) ) ) {
			ordinal = ordinalTypeA[ date[ 2 ] ];
		}

		return ordinal;
	}

	// Every built-in type name, parenthesised.
	function everyTypeWord() {
		var a = ( any );
		var b = ( string );
		var c = ( numeric );
		var d = ( xml );
		var e = ( binary );
		var f = ( boolean );
		var g = ( date );
		var h = ( guid );
		var i = ( void );
		var j = ( query );
		var k = ( struct );
		var l = ( array );
		return a;
	}

	// The type slots those words also serve must keep working.
	public string function typed( any a, string s, date d, boolean b, numeric n ) {
		return s;
	}

	function arrows() {
		var typedArrow   = ( string s ) => s;
		var untypedArrow = ( s ) => s;
		return untypedArrow;
	}

}
