CC=gcc
CFLAGS=-Wall -pedantic -O3 -mtune=haswell

all: main

main: main.o calc_primo.o
	 $(CC) main.o calc_primo.o -o $@

main.o: main.c calc_primo.h
	$(CC) $(CFLAGS) -c main.c -o $@

calc_primo.o: calc_primo.c calc_primo.h
	$(CC) $(CFLAGS) -c calc_primo.c -o $@

clean:
	rm *.o main
