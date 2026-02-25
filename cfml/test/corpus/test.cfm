<table class="tagcontext">
						<cfloop from="1" to="#ArrayLen(arguments.ErrorCollection.TagContext)#" index="i">
							<cfset template = arguments.ErrorCollection.TagContext[i].template />
							<cfset line = arguments.ErrorCollection.TagContext[i].line />
							<tr>
								<td>
									<cfif structKeyExists(arguments.ErrorCollection.TagContext[i], "codePrintHTML") AND i eq 1>#arguments.ErrorCollection.TagContext[i].codePrintHTML#</cfif>
								</td>
							</tr>
						</cfloop>
					</table>