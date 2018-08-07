PREFIX=/usr/local
BIN=mex

.PHONY: install
install:
	cp mex $(PREFIX)/bin/$(BIN)

.PHONY: uninstall
	rm $(PREFIX)/bin/$(BIN)
