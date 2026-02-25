<cfset downloadUrl = "https:"&#ARGUMENTS.download_url# />

<cfquery name="Test">
  <cfswitch expression="#tmp_budget_no#">
    <cfcase value="1">
        AND	ac.budg1_amt <> 0
    </cfcase>
  </cfswitch>
</cfquery>