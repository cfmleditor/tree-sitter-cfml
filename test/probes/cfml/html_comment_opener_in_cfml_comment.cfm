<!--- Seen in: Galaxie Blog (admin/adminInterface/postScene.cfm, common/cfc/Renderer.cfc), MuraCMS (core/modules/v1/feed/index.cfm) --->
<!--- Nothing in the data can end the script ("</") or open an HTML comment in it ("<!--"). --->
<cfset postSceneJson = replace( json, "<!--", "<\!--", "all" )>
<!---
	<cfcatch><!-- Error getting Feed <cfoutput>'#feedBean.getName()#'</cfoutput> --></cfcatch>
--->
