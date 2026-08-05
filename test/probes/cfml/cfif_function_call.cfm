<!--- Seen in: Lucee admin context (debugging.templates.create.cfm) --->
<cfoutput>
<cfloop array="#driver.getCustomFields()#" index="field">
<cfif isInstanceOf( field, "Group" )>ok</cfif>
</cfloop>
</cfoutput>
