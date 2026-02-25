<cffunction name="validateAndUnzipFile" access="public" output="false" returntype="any">
		<cfargument name="context" type="struct" required="true" />

		<cfif result.bZipError IS true>

			<!--- Don't return any files --->
			<cfset arrFiles = arrayNew(1)>

		<cfelse>

			<cfzip action="unzip" destination="#getTempDirectory()#" file="#ARGUMENTS.zipFilePath#" overwrite="true" />

    </cfif>
		
	</cffunction>