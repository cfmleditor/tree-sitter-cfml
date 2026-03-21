TS ?= tree-sitter

all install uninstall clean:
	$(MAKE) -C cfml $@
	$(MAKE) -C cfhtml $@
	$(MAKE) -C cfscript $@
	$(MAKE) -C cfquery $@

generate:
	cd cfml && $(TS) generate
	cd cfhtml && $(TS) generate
	cd cfscript && $(TS) generate
	cd cfquery && $(TS) generate

test:
	$(TS) test

.PHONY: all install uninstall clean test update generate
