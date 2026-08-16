<cfscript>
// Seen in: RustCFML tests/oop/test_include_rewrite_freshness.cfm
//   FileWrite( helperAbs, "<cfscript>function fxProbe(){ return 'first'; }</cfscript>" );
// A `</cfscript>` inside a string literal closes the script block early, so
// the rest of the block is parsed as template text and the real closing tag
// becomes a stray end tag. The scanner scans raw script text for the close tag
// without tracking string literals.
FileWrite( helperAbs, "<cfscript>function fxProbe(){ return 'first'; }</cfscript>" );
x = 2;
</cfscript>
