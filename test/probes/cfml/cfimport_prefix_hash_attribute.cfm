<!--- Seen in: tassweb webroot/academicreports/resultFormats_list.cfm, lines 96-100.
      A custom tag's attributes are evaluated, so a `#...#` in one may hold a
      string with quotes of its own. Read as an HTML attribute, the inner `"`
      closed the value, and the `=` inside the string then left an attribute
      with no name — a MISSING node. --->
<cfimport prefix="control" taglib="../controls">
<control:newentitybutton
			link=""
			click="loadpopupwindow('combomaint', 'p_resultFormatsClone.cfm?action=add&security=#formatPerms#&set_code=&sub_level=&sub_code=&obj_code=&backURL=#URLEncodedFormat("resultFormats_list.cfm?&set_code=#FORM.set_code#&sub_level=#FORM.sub_level#&sub_code=#FORM.sub_code#&obj_code=&unit_flg=#result.unit_flg#")#', 'Clone Result Format', false, '');"
			text="Clone"
			image="../images/p_toolbar/clone.gif" />
