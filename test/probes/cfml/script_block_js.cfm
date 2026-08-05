<!--- Seen in: Lucee context/form.cfm, Mura admin templates --->
<cfoutput>
<script>
	var prv = {};
	prv.validate = function( el, value ) {
		if ( el.message && el.message.length > 0 ) prv.addError( el, el.message );
		else prv.addError( el, "bad" );
	};
</script>
</cfoutput>
