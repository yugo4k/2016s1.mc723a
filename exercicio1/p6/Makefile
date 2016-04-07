CC=gcc
# CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2
CFLAGS=-Wall -pedantic -O3 -march=amdfam10 -mtune=amdfam10

all: primo_omp primo_sieve primo_sieve_omp

primo_omp: primo_omp.c
	$(CC) $(CFLAGS) -fopenmp primo_omp.c -o $@

primo_sieve: primo_sieve.c
	$(CC) $(CFLAGS) primo_sieve.c -o $@

primo_sieve_omp: primo_sieve_omp.c
	$(CC) $(CFLAGS) -fopenmp -std=c99 primo_sieve_omp.c -o $@

clean:
	rm primo_omp primo_sieve primo_sieve_omp
