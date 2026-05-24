; Indentation for CFML
; See https://tree-sitter.github.io/tree-sitter/syntax-highlighting#indentation

; HTML elements
(element
  (start_tag) @indent)
(element
  (end_tag) @dedent)
(script_element
  (start_tag) @indent)
(script_element
  (end_tag) @dedent)
(style_element
  (start_tag) @indent)
(style_element
  (end_tag) @dedent)

; CF tags with explicit start/end (cfloop, cfmail, etc.)
(cf_tag
  (cf_start_tag) @indent)
(cf_tag
  (cf_end_tag) @dedent)

; CF component tags
(cf_component_open_tag) @indent
(cf_component_close_tag) @dedent

; CF block tags (cfif, cffunction, cfoutput, cfscript, cfquery, cfsavecontent)
(cf_if_tag) @indent
(cf_function_tag) @indent
(cf_output_tag) @indent
(cf_script_tag) @indent
(cf_query_tag) @indent
(cf_savecontent_tag) @indent

; Script-level nodes (expressions inside cfset, cfif, cfreturn, cfscript, etc.)
(statement_block "{" @indent)
(statement_block "}" @dedent)
(switch_body "{" @indent)
(switch_body "}" @dedent)
(object "{" @indent)
(object "}" @dedent)
(object_pattern "{" @indent)
(object_pattern "}" @dedent)
(named_imports "{" @indent)
(named_imports "}" @dedent)
(formal_parameters "(" @indent)
(formal_parameters ")" @dedent)
(arguments "(" @indent)
(arguments ")" @dedent)
(parenthesized_expression "(" @indent)
(parenthesized_expression ")" @dedent)
(array "[" @indent)
(array "]" @dedent)
(array_pattern "[" @indent)
(array_pattern "]" @dedent)
