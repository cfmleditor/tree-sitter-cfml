<!--- Seen in: Mura CMS core/mura/fileWriter.cfc
      `new` is a legal variable name in CFML. One such <cfset> used to cascade
      into hundreds of ERROR nodes for the rest of the file. --->
<cfcomponent>
	<cffunction name="write">
		<cfset var new = "">
		<cfset new = FileOpen( arguments.file, "write" )>
		<cfreturn new>
	</cffunction>
</cfcomponent>
