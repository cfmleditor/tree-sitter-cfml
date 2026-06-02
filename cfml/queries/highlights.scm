; Document and structure (from Lucee-style rules)
(program) @document
(doctype) @doctype
(entity) @constant
(html_text) @text

(erroneous_end_tag_name) @tag.error
(erroneous_cf_end_tag_name) @tag.error
(attribute_name) @attribute
(cf_attribute_name) @attribute
(attribute_value) @string
(script_text) @embedded
(style_text) @embedded
(start_tag) @tag
(end_tag) @tag
(self_closing_tag) @tag
(cf_selfclose_tag) @tag
(cf_start_tag_with_selfclose) @tag
(cf_output_tag) @tag
(cf_function_tag) @tag
(cf_script_tag) @tag
(cf_start_tag) @tag
(cf_end_tag) @tag
(cf_if_tag) @tag
(cf_query_tag) @tag
(cf_else_tag) @tag
(cf_elseif_tag) @tag
(cf_return_tag) @tag
(cf_xml_tag) @tag
(cf_component_open_tag) @tag
(cf_component_close_tag) @tag

(tag_name) @tag
(cf_tag_name) @tag

; Variables
;----------

(identifier) @variable

; CFML scopes
;-------------

((identifier) @variable.builtin
 (#match? @variable.builtin "^(?i)(APPLICATION|ARGUMENTS|CGI|CLIENT|COOKIE|FORM|LOCAL|REQUEST|SERVER|SESSION|THIS|URL|VARIABLES)$"))

; Properties
;-----------

(property_identifier) @property

(shorthand_property_identifier) @property

; Function and method definitions
;--------------------------------

(function_expression
  name: (identifier) @function) @definition.function

(function_declaration
  name: (identifier) @function)

(function_declaration
  (access_type) @access_type)

(method_definition
  name: [
    (property_identifier)
    (private_property_identifier)
  ] @function.method)

(method_definition
  name: (property_identifier) @constructor
  (#eq? @constructor "constructor"))

(pair
  key: (property_identifier) @function.method
  value: (function_expression))

(pair
  key: (property_identifier) @function.method
  value: (arrow_function))

(array) @expression

(cf_set_tag) @tag

(assignment_expression
  left: (member_expression
    property: (property_identifier) @function.method)
  right: (arrow_function))

(assignment_expression
  left: (member_expression
    property: (property_identifier) @function.method)
  right: (function_expression))

(variable_declarator
  name: (identifier) @function
  value: (arrow_function))

(variable_declarator
  name: (identifier) @function
  value: (function_expression))

(assignment_expression
  left: (identifier) @function
  right: (arrow_function))

(assignment_expression
  left: (identifier) @function
  right: (function_expression))

; Function and method calls
;--------------------------

(call_expression
  function: (identifier) @function.builtin
  (#match? @function.builtin "^(?i)(abs|acos|addsoaprequestheader|addsoapresponseheader|aigetmetadata|aihas|ajaxlink|ajaxonload|applicationpathcacheclear|applicationstarttime|applicationstop|argon2checkhash|array|arrayappend|arrayavg|arrayclear|arraycontains|arraycontainsnocase|arraydelete|arraydeleteat|arraydeletenocase|arrayeach|arrayevery|arrayfilter|arrayfind|arrayfindall|arrayfindallnocase|arrayfindnocase|arrayfirst|arrayindexexists|arrayinsertat|arrayisdefined|arrayisempty|arraylast|arraylen|arraymap|arraymax|arraymedian|arraymerge|arraymid|arraymin|arraynew|arraypop|arrayprepend|arraypush|arrayreduce|arrayremoveduplicates|arrayresize|arrayreverse|arrayset|arrayshift|arrayslice|arraysome|arraysort|arraysplice|arraysum|arrayswap|arraytolist|arraytostruct|arrayunshift|asc|asin|astfrompath|astfromstring|atn|beat|binarydecode|binaryencode|bitand|bitmaskclear|bitmaskread|bitmaskset|bitnot|bitor|bitshln|bitshrn|bitxor|booleanformat|bundleinfo|cacheclear|cachecount|cachedelete|cacheget|cachegetall|cachegetallids|cachegetdefaultcachename|cachegetmetadata|cachegetproperties|cacheidexists|cachekeyexists|cacheput|cacheregionexists|cacheregionnew|cacheregionremove|cacheremove|cacheremoveall|cachesetproperties|callstackdump|callstackget|canonicalize|ceiling|cfusion_decrypt|cfusion_encrypt|charsetdecode|charsetencode|chr|cjustify|cleartimezone|collectioneach|collectionevery|collectionfilter|collectionmap|collectionreduce|collectionsome|compare|comparenocase|componentcacheclear|componentcachelist|componentinfo|componentlistpackage|compress|configimport|configtranslate|contractpath|cos|createaisession|createdate|createdatetime|createdynamicproxy|createguid|createobject|createodbcdate|createodbcdatetime|createodbctime|createtime|createtimespan|createulid|createuniqueid|createuuid|createwebsocketclient|csrfgeneratetoken|csrfverifytoken|ctcacheclear|ctcachelist|datasourceflushmetacache|dateadd|datecompare|dateconvert|datediff|dateformat|datepart|datetimeformat|day|dayofweek|dayofweekasstring|dayofweekshortasstring|dayofyear|daysinmonth|daysinyear|dbpoolclear|de|debugadd|decimalformat|decodeforhtml|decodefromurl|decrementvalue|decrypt|decryptbinary|deleteclientvariable|deserializejson|directorycopy|directorycreate|directorydelete|directoryexists|directoryinfo|directorylist|directoryrename|dollarformat|dump|duplicate|each|ec2describeinstances|echo|empty|encodeforcss|encodefordn|encodeforhtml|encodeforhtmlattribute|encodeforjavascript|encodeforldap|encodeforsql|encodeforurl|encodeforxml|encodeforxmlattribute|encodeforxpath|encrypt|encryptbinary|entitydelete|entityload|entityloadbyexample|entityloadbypk|entitymerge|entitynamearray|entitynamelist|entitynew|entityreload|entitysave|entitytoquery|esapidecode|esapiencode|evaluate|exp|expandpath|extensionexists|extensioninfo|extensionlist|extract|fileappend|fileclose|filecopy|filedelete|fileexists|filegetmimetype|fileinfo|fileiseof|filemodetosymbolic|filemove|fileopen|fileread|filereadbinary|filereadline|fileseek|filesetaccessmode|filesetattribute|filesetlastmodified|fileskipbytes|filetouch|fileupload|fileuploadall|filewrite|filewriteline|find|findlast|findlastnocase|findnocase|findoneof|firstdayofmonth|fix|floor|formatbasen|generatesecretkey|getapplicationmetadata|getapplicationsettings|getauthuser|getbasetagdata|getbasetaglist|getbasetemplatepath|getcanonicalpath|getclientvariableslist|getcomponentmetadata|getcontextroot|getcurrenttemplatepath|getdirectoryfrompath|getencoding|getfilefrompath|getfileinfo|getfunctioncalledname|getfunctionlist|gethttprequestdata|gethttptimestring|getlocale|getlocaledisplayname|getlocaleinfo|getlocalhostip|getmetadata|getnumericdate|getpagecontext|getprofilesections|getprofilestring|getreadableimageformats|getsoaprequest|getsoaprequestheader|getsoapresponse|getsoapresponseheader|getsystemfreememory|getsystemtotalmemory|gettempdirectory|gettempfile|gettickcount|gettimezoneinfo|gettoken|getuserroles|getvfsmetadata|getwriteableimageformats|hash|hash40|hmac|hour|htmlcodeformat|htmleditformat|iif|imageaddborder|imageblur|imageclearrect|imagecopy|imagecrop|imagedrawarc|imagedrawbeveledrect|imagedrawcubiccurve|imagedrawline|imagedrawlines|imagedrawoval|imagedrawpoint|imagedrawquadraticcurve|imagedrawrect|imagedrawroundrect|imagedrawtext|imageflip|imagegetblob|imagegetbufferedimage|imagegetexifmetadata|imagegetexiftag|imagegetheight|imagegetiptcmetadata|imagegetwidth|imagegrayscale|imageinfo|imagenegative|imagenew|imageoverlay|imagepaste|imageread|imagereadbase64|imageresize|imagerotate|imagerotatedrawingaxis|imagescaletofit|imagesetantialiasing|imagesetbackgroundcolor|imagesetdrawingcolor|imagesetdrawingstroke|imagesetdrawingtransparency|imageshear|imagesheardrawingaxis|imagetranslate|imagetranslatedrawingaxis|imagewrite|imagewritebase64|imagexordrawingmode|incrementvalue|inputbasen|insert|int|invoke|isarray|isbinary|isboolean|isclosure|iscustomfunction|isdate|isdebugmode|isdefined|isempty|isfileobject|isimage|isimagefile|isinstanceof|isipv6|isjson|isleapyear|islocalhost|isnull|isnumeric|isnumericdate|isobject|ispdfobject|isquery|issimplevalue|issoaprequest|isstruct|isuserinanyrole|isuserinrole|isuserloggedin|isvalid|iswddx|isxml|isxmlattribute|isxmldoc|isxmlelem|isxmlnode|isxmlroot|javacast|jsstringformat|lcase|left|len|listappend|listchangedelims|listcompact|listcontains|listcontainsnocase|listdeleteat|listeach|listevery|listfilter|listfind|listfindnocase|listfirst|listgetat|listinsertat|listitemtrim|listlast|listlen|listmap|listprepend|listqualify|listreduce|listremoveduplicates|listrest|listsetat|listsome|listsort|listtoarray|listtrim|listvaluecount|listvaluecountnocase|ljustify|location|log|log10|lscurrencyformat|lsdateformat|lsdatetimeformat|lseurocurrencyformat|lsiscurrency|lsisdate|lsisnumeric|lsnumberformat|lsparsecurrency|lsparsedatetime|lsparseeurocurrency|lsparsenumber|lstimeformat|ltrim|max|mid|min|minute|month|monthasstring|monthshortasstring|now|nullvalue|numberformat|objectequals|objectload|objectsave|ormclearsession|ormcloseallsessions|ormclosesession|ormevictcollection|ormevictentity|ormevictqueries|ormexecutequery|ormflush|ormgetsession|ormgetsessionfactory|ormreload|paragraphformat|parameterexists|parsedatetime|parsenumber|pi|precisionevaluate|preservesinglequotes|quarter|queryaddcolumn|queryaddrow|queryclose|querycolumnarray|querycolumncount|querycolumndata|querycolumnexists|querycolumnlist|queryconvertforgrid|querycurrentrow|querydeletecolumn|querydeleterow|queryeach|queryevery|queryexecute|queryfilter|querygetcell|querygetrow|querykeyexists|querymap|querynew|queryrecordcount|queryreduce|queryrenamecolumn|queryreverse|queryrowdata|querysetcell|queryslice|querysome|querysort|quotedvaluelist|rand|randomize|randrange|reescape|refind|refindnocase|releasecomobject|rematch|rematchnocase|removechars|repeatstring|replace|replacelist|replacelistnocase|replacenocase|rereplace|rereplacenocase|restdeleteapplication|restinitapplication|restsetresponse|reverse|right|rjustify|round|rtrim|second|sendgatewaymessage|serializejson|sessioninvalidate|sessionrotate|setencoding|setlocale|setprofilestring|setvariable|sgn|sin|sleep|soundex|spanexcluding|spanincluding|sqr|stripcr|structappend|structclear|structcopy|structcount|structdelete|structeach|structevery|structfilter|structfind|structfindkey|structfindvalue|structget|structinsert|structisempty|structkeyarray|structkeyexists|structkeylist|structkeytranslate|structmap|structnew|structreduce|structsome|structsort|structtosorted|structupdate|tan|threadjoin|threadterminate|throw|timeformat|tobase64|tobinary|tonumeric|toscript|tostring|trace|transactioncommit|transactionrollback|transactionsetsavepoint|trim|ucase|ucfirst|urldecode|urlencodedformat|urlsessionformat|val|valuearray|valuelist|verifyclient|week|wrap|writedump|writelog|writeoutput|xmlchildpos|xmlelemnew|xmlformat|xmlgetnodetype|xmlnew|xmlparse|xmlsearch|xmltransform|xmlvalidate|year|yesnoformat)$"))

(call_expression
  function: (identifier) @function.call)

(call_expression
  function: (member_expression
    property: [
      (property_identifier)
      (private_property_identifier)
    ] @function.method.call))

; Literals
;---------
((identifier) @variable.builtin
  (#eq? @variable.builtin "self"))

(this) @variable.builtin
(super) @variable.builtin

(cf_var) @keyword

[
  (true)
  (false)
] @boolean

[
  (null)
  (undefined)
] @constant.builtin

[
  (comment)
  (cf_comment)
] @comment @spell

((comment) @comment.documentation
  (#match? @comment.documentation "^/[*][*][^*].*[*]/$"))

((string_fragment) @keyword.directive
  (#eq? @keyword.directive "use strict"))

(string) @string
(text) @string
(hash_empty) @punctuation.special

(regex_pattern) @string.regexp
(regex_flags) @character.special

(regex
  "/" @punctuation.bracket) ; Regex delimiters

(number) @number

(hash_expression
  "#" @punctuation.special)

(unary_operator) @operator

((identifier) @number
  (#any-of? @number "NaN" "Infinity"))

(ordered_struct
  ["[" ":" "]"] @punctuation.bracket)

; Types
;------

(parameter_type) @type
(catch_clause
  type: (catch_type) @type)

; Imports
;--------

(import_path
  (identifier) @module)

; Punctuation
;------------
[
  ";"
  "."
  ","
  ":"
  (optional_chain)
  (static_chain)
] @punctuation.delimiter

(binary_expression
  "/" @operator)

(ternary_expression
  [
    "?"
    ":"
  ] @keyword.conditional.ternary)

(elvis_expression
  "?:" @keyword.conditional.ternary)

[
  "-"
  "--"
  "-="
  "+"
  "++"
  "+="
  "*"
  "*="
  "**"
  "**="
  "/"
  "/="
  "%"
  "%="
  "<"
  "<<="
  "="
  "=="
  "==="
  "!"
  "!="
  "!=="
  "=>"
  ">"
  ">>="
  ">>>="
  "~"
  "^"
  "&"
  "|"
  "^="
  "&="
  "|="
  "&&"
  (logical_or)
  "||"
  "??"
  "&&="
  "||="
  "??="
] @operator

[
  "var"
  "let"
  "const"
  "function"
  "new"
  "return"
  "if"
  "else"
  "for"
  "while"
  "do"
  "switch"
  "case"
  "default"
  "break"
  "continue"
  "try"
  "catch"
  "finally"
  "throw"
  "in"
  "of"
  "instanceof"
  "static"
  "with"
] @keyword

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
  "<"
  ">"
  "</"
] @punctuation.bracket
