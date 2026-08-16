<!--- Seen in: RustCFML tests/tags/test_tag_attribute_escaped_quotes.cfm
      <cfparam name="sq" default='x ''y'' z'>
      The doubled-quote escape is accepted inside a double-quoted tag attribute
      value ("" on the line below parses) but not inside a single-quoted one.
      `quoted_cf_attribute_value` in common/define-grammar.js lists '""' as an
      alternative in its double-quoted branch and has no "''" counterpart in
      the single-quoted branch. --->
<cfparam name="dq" default="p ""q"" r">
<cfparam name="sq" default='x ''y'' z'>
