<!--- Seen in: tassweb webroot/attendance/bulk_absentee.cfm, line 2105.
      33 `<control:hiddenfield>` custom-tag calls with no end tag, then a
      `<cfloop>`. Each unclosed tag nests inside the one before and costs its
      name's bytes in the serialised tag stack, so the run used up the headroom
      kept for CF tags and the `<cfloop>` was completed as void, leaving its
      `</cfloop>` with no opener. The same shape as #55, on the HTML side. --->
<cfimport prefix="control" taglib="../controls">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<control:hiddenfield id="w_fri_flag" value="#strAbsentee.w_fri_flag#">
	<cfloop from="1" to="#ListLen(temp_list)#" index="i">
		<control:hiddenfield id="w_#i#" value="">
	</cfloop>
