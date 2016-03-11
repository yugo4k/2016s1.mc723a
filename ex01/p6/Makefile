CC=gcc
CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2

all: primo_omp

primo_omp: primo_omp.c
	$(CC) $(CFLAGS) -fopenmp primo_omp.c -o $@

clean:
	rm primo_omp
