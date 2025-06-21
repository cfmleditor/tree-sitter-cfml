TS ?= tree-sitter

all install uninstall clean:
	$(MAKE) -C cfml $@
	$(MAKE) -C cfhtml $@
	$(MAKE) -C cfscript $@

generate:
	cd cfml && $(TS) generate
	cd cfhtml && $(TS) generate
	cd cfscript && $(TS) generate

test:
	$(TS) test

.PHONY: all install uninstall clean test update generate
