CC=gcc
# CFLAGS=-Wall -pedantic
# CFLAGS=-Wall -pedantic -O0
# CFLAGS=-Wall -pedantic -O1
# CFLAGS=-Wall -pedantic -O2
CFLAGS=-Wall -pedantic -O3
# CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2
# CFLAGS=-Wall -pedantic -O3 -mtune=haswell

all: primo

primo: primo.o
	$(CC) primo.o -o $@

primo.o: primo.c
	$(CC) $(CFLAGS) -c primo.c -o $@

clean:
	rm *.o primo
