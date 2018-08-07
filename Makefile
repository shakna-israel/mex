PREFIX=/usr/local
BIN=mex

.PHONY: install
install:
	cp $(BIN) $(PREFIX)/bin/$(BIN)

.PHONY: uninstall
	rm $(PREFIX)/bin/$(BIN)

all: process
process: mex.c
	$(CC) mex.c -o $(BIN)
