CC=gcc
# CFLAGS=-Wall -pedantic
CFLAGS=-Wall -pedantic -O3 -march=core2 -mtune=core2

all: main primo

primo: primo.o
	$(CC) primo.o -o $@

primo.o: primo.c
	$(CC) $(CFLAGS) -c primo.c -o $@

main: main.o calc_primo.o
	 $(CC) main.o calc_primo.o -o $@

main.o: main.c calc_primo.h
	$(CC) $(CFLAGS) -c main.c -o $@

calc_primo.o: calc_primo.c calc_primo.h
	$(CC) $(CFLAGS) -c calc_primo.c -o $@

clean:
	rm *.o main primo
