CC=gcc
# CFLAGS=-Wall -pedantic
# CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2
# CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2 -pg
# CFLAGS=-Wall -pedantic -O0 -march=core2 -mtune=core2 -pg
# CFLAGS=-Wall -pedantic -O2 -march=core2 -mtune=core2 -pg
CFLAGS=-Wall -pedantic -O1 -march=core2 -mtune=core2 -pg

primo: primo.c
	$(CC) $(CFLAGS) primo.c -o $@

clean:
	rm primo
