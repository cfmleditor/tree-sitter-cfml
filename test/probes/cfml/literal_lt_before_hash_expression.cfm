<!--- Seen in: MuraCMS core/setup/inc/_form.cfm:192
      A literal `<` written before a hash expression. `<#expr#>` is a dynamic
      tag name, so `<#` starts a start tag, and with no `>` before the next `<`
      it never closes; the error is reported on the enclosing element. The
      engine prints the `<` and the value. Recorded `fail` on purpose: a
      decision to leave it unsupported, kept for later consideration (#177). --->
<cfoutput>
<span id="url_example"><#context#/index.cfm/[siteid]?</span>
</cfoutput>
