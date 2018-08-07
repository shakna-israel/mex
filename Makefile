PREFIX=/usr/local
BIN=mex

.PHONY: install
install:
	cp mex $(PREFIX)/$(BIN)

.PHONY: uninstall
	rm $(PREFIX)/$(BIN)
