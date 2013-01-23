CC=gcc
CFLAGS=-O2 -Wall -Wextra

PROG=colour-man
PREFIX=/usr/sbin
SRC=./src

$(PROG): $(SRC)/*.c
	$(CC) -o $@ $(CFLAGS) $^
	-strip -s $@

install: $(SRC)/$(PROG)
	cp $^ $(PREFIX)

.PHONY: clean
clean:
	rm -f $(PROG)

