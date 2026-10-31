<!--- Seen in: Galaxie Blog galaxiePlayer.cfm:219
      An attribute value whose opening quote is inside a <cfif> and whose closing
      quote is after it. Recorded `fail` on purpose: a decision to leave it
      unsupported, kept for later consideration (#119). --->
<video <cfif a>poster="<cfoutput>#u#</cfoutput></cfif>" id="p">
</video>
