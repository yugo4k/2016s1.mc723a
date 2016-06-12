CC=gcc
# CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2
CFLAGS=-Wall -pedantic -O3 -march=amdfam10 -mtune=amdfam10

all: primo_compet

primo_compet: primo_compet.c
	$(CC) $(CFLAGS) -fopenmp primo_compet.c -o $@

clean:
	rm primo_compet
