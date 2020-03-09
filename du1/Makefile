# Makefile
#
# Řešení IJC-DU1
# Datum vytovření: 3.3.2020
# Autor: Tomáš Milostný, xmilos02, FIT VUT
# Překladač: gcc 7.4
# Popis: Program make pro přeložení souborů projektu
#		 clean: Smaže všechny binární soubory s příponou .o a spustitelné programy
#		 run:   Vytvoří a spustí všechny spustitelné programy (./primes, ./primes-i, ./steg-decode du1-obrazek.ppm)
#        pack:  Zabalí zip balíček se soubory k odevzdání

default_target: all

CC=gcc

CFLAGS=-g -O2 -std=c11 -pedantic -Wall -Wextra

all: primes primes-i steg-decode #steg-encode


primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) error.o eratosthenes.o primes.o -o primes -lm

primes-i: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) error.o eratosthenes.o primes.o -o primes-i -lm -DUSE_INLINE

steg-decode: error.o ppm.o eratosthenes.o steg-decode.o
	$(CC) $(CFLAGS) error.o ppm.o eratosthenes.o steg-decode.o -o steg-decode -lm


# gcc -MM *.c
# závislosti programů
eratosthenes.o: eratosthenes.c bitset.h error.h eratosthenes.h
error.o: error.c
ppm.o: ppm.c error.h ppm.h
primes.o: primes.c bitset.h error.h eratosthenes.h
steg-decode.o: steg-decode.c ppm.h eratosthenes.h bitset.h error.h
steg-encode.o: steg-encode.c


clean:
	rm -f *.o
	rm -f primes primes-i steg-decode steg-encode

pack:
	zip xmilos02.zip *.c *.h Makefile

run: all
	./primes
	./primes-i
	./steg-decode du1-obrazek.ppm