<!--- Seen in: Galaxie Blog (common/cfc/StringUtils.cfc, Renderer.cfc) --->
<cfset s = replaceNoCase( s, "<!--<attachScript", "<script", "all" )>
<!--- Replace the end comment --->
<cfset s = replaceNoCase( s, "</attachScript>-->", "</script>", "all" )>
