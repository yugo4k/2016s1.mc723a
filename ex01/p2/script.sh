#!/bin/sh

gcc -Wall -pedantic -O3 -march=core2 -mtune=core2 calc_primo.c main.c -o main
