## Process this file with automake to generate Makefile.in

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = src include doc

export: dist
	scp $(PACKAGE)-$(VERSION).tar.gz $(WEB_SERVE):$(WEB_PATH)/software/.
	ssh $(WEB_SERVE) "cd $(WEB_PATH)/software ; \rm -f $(PACKAGE).tar.gz ; ln -s $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE).tar.gz; \rm -fr $(PACKAGE); mkdir $(PACKAGE)"
	scp -r doc/html $(WEB_SERVE):$(WEB_PATH)/software/$(PACKAGE)/.
	ssh $(WEB_SERVE) "cd $(WEB_PATH)/software; sed -e 's%<\!-- binary version --><td>.*</td>%<\!-- binary version --><td>$(VERSION)</td>%' index.html > junk.html; mv junk.html index.html"
	ssh $(WEB_SERVE) "cd $(WEB_PATH)/software; sed -e 's%<\!-- binary date --><td>.*</td>%<\!-- binary date --><td>$(DATE)</td>%' index.html > junk.html; mv junk.html index.html"

ALIASES = Binary

.PHONY : $(ALIASES)

DATE   = $(shell date)

progdir = @bindir@/@PACKAGE@

prog_DATA = $(ALIASES)

$(ALIASES):
	@echo '#' > $(ALIASES)
	@echo '# This file defines aliases for the $(PACKAGE) v$(VERSION) software.' >> $(ALIASES)
	@echo '# Source it to define them.' >> $(ALIASES)
	@echo '#' >> $(ALIASES)
	@echo 'alias binfo     $(progdir)/binfo'      >> $(ALIASES)
	@echo 'alias edisc     $(progdir)/edisc'      >> $(ALIASES)
	@echo 'alias wdsolve   $(progdir)/wdsolve'    >> $(ALIASES)
	@echo ' ' >> $(ALIASES)
	@echo 'echo " "' >> $(ALIASES)
	@echo 'echo "Welcome to $(PACKAGE) version $(VERSION), built $(DATE)"' >> $(ALIASES)
	@echo 'echo " "' >> $(ALIASES)
	@echo 'echo "Commands available are: binfo, edisc, wdsolve"' >> $(ALIASES)
	@echo 'echo " "' >> $(ALIASES)
	@echo 'echo "Point a browser at ${prefix}/html/$(PACKAGE)/index.html for help."' >> $(ALIASES)
	@echo 'echo " "' >> $(ALIASES)
