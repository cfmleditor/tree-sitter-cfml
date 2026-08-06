<!--- `<cftimer>` times the code between its start and end tags, so it is not a
      void tag. It was listed as one, which made the paired form fail. No corpus
      file uses `<cftimer>` at all, so this rests on the tag's semantics rather
      than on usage evidence. --->
<cftimer label="request" type="inline">
	<cfset result = expensiveCall()>
</cftimer>
