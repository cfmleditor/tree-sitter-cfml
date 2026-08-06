<!--- Seen in: Mura core/modules/v1/feedslideshow/index.cfm
      A CFML comment inside a <script> element, containing a `#` (a URL
      anchor). CFML strips the comment before evaluating, so the `#` must not
      open a hash expression. --->
<cfoutput>
<script>
<!--- Conditional for iOS6, see https://gist.github.com/kTmnh/3798925/#comment-592093 --->
if ( /(iPhone|iPad|iPod)\sOS\s6/.test( navigator.userAgent ) ) {
	init( #variables.delay# );
}
</script>
</cfoutput>
