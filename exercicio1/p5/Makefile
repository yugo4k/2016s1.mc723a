CC=gcc
CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2

all: primo primo_omp

primo: primo.c
	$(CC) $(CFLAGS) primo.c -o $@

primo_omp: primo_omp.c
	$(CC) $(CFLAGS) -fopenmp primo_omp.c -o $@

clean:
	rm primo primo_omp
