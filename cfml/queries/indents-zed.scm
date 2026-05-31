; Indentation for CFML

; HTML elements
(element (end_tag) @end) @indent
(script_element (end_tag) @end) @indent
(style_element (end_tag) @end) @indent

; CF tags with explicit start/end (cfloop, cfmail, etc.)
(cf_tag (cf_end_tag) @end) @indent

; CF component tags
(cf_component_close_tag) @end
(cf_component_open_tag) @indent

; CF block tags (cfif, cffunction, cfoutput, cfscript, cfquery, cfsavecontent)
(cf_if_tag "</cf" @end) @indent
(cf_function_tag "</cf" @end) @indent
(cf_output_tag "</cf" @end) @indent
(cf_script_tag "</cf" @end) @indent
(cf_query_tag "</cf" @end) @indent
(cf_savecontent_tag "</cf" @end) @indent

; Script-level nodes (expressions inside cfset, cfif, cfreturn, cfscript, etc.)
(statement_block "}" @end) @indent
(switch_body "}" @end) @indent
(object "}" @end) @indent
(object_pattern "}" @end) @indent
(named_imports "}" @end) @indent
(formal_parameters ")" @end) @indent
(arguments ")" @end) @indent
(parenthesized_expression ")" @end) @indent
(array "]" @end) @indent
(array_pattern "]" @end) @indent
