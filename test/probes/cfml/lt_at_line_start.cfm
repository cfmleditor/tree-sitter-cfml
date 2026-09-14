<!--- A bare `<` as the first non-whitespace character on a line. Seen in:
      ContentBox contentbox-filebrowser/views/home/filelisting.cfm
      (a `<-` back-arrow glyph in body text). Mid-line `<` already parses —
      see lt_in_text.cfm. The same rule covers a `<` that opens a text run
      directly after a tag, `[<a href="x"><< Go Back</a>]` in ColdBox's
      TaskManager sample. --->
<p>
	<- back
</p>
