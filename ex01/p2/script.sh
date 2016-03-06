#!/bin/sh

gcc -pedantic -Wall -O3 -mtune=haswell -o main main.c calc_primo.c
