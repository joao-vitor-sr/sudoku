# sudoku - sudoku game in CLI
# See LICENSE file for copyright and License details.
POSIX:

include config.mk

SRC = main.cpp

install:
	$(CC) $(CFLAGS) -o sudoku main.cpp
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f sudoku $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/sudoku

uninstall:
	rm -f $(DESTDIR)$(PREfIX)/bin/sudoku
