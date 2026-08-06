<!--- Seen in: Lucee admin context (server.logging.create.cfm and friends),
      cbfeeds SharedGenerator.cfc
      A dynamic tag name with a static prefix or namespace. The plain
      `<#expr#>` form parses (see dynamic_close_tag.cfc); these do not, on
      master or here. --->
<cfoutput>
<cfloop array="#driver.getCustomFields()#" index="field">
<h#field.getLevel()#>#field.getDisplayName()#</h#field.getLevel()#>
<dc:#container#>#value#</dc:#container#>
</cfloop>
</cfoutput>
