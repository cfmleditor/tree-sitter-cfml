<!--- This works --->
<table>

    <tr>
      <cfloop test="1">
        <td><cfoutput>test</cfoutput></td>
      </cfloop>
    </tr>
  </table>

  <!--- This doesn't --->
    <table>

      <cfloop test="1">
    <tr>
        <td><cfoutput>test</cfoutput></td>
      </tr>
    </cfloop>
  </table>