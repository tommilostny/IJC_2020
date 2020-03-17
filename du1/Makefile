# Makefile
#
# Řešení IJC-DU1
# Datum vytovření: 3.3.2020
# Autor: Tomáš Milostný, xmilos02, FIT VUT
# Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
# Popis: Program make pro přeložení souborů projektu

all: primes primes-i steg-decode steg-encode


CC = gcc
CFLAGS = -g -O2 -std=c11 -pedantic -Wall -Wextra
LDFLAGS = -lm

primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

primes-i: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -DUSE_INLINE

steg-decode: error.o ppm.o eratosthenes.o steg-decode.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

steg-encode: error.o ppm.o eratosthenes.o steg-encode.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)


# gcc -MM *.c
eratosthenes.o: eratosthenes.c bitset.h error.h eratosthenes.h
error.o: error.c
ppm.o: ppm.c error.h ppm.h
primes.o: primes.c bitset.h error.h eratosthenes.h
steg-decode.o: steg-decode.c ppm.h eratosthenes.h bitset.h error.h
steg-encode.o: steg-encode.c
steg-encode.o: steg-encode.c ppm.h eratosthenes.h bitset.h error.h

.PHONY: clean

clean:
	rm -f *.o
	rm -f primes primes-i steg-decode steg-encode

pack:
	zip xmilos02.zip *.c *.h Makefile

run:
	ulimit -s 125000 && ./primes ; ./primes-i
	./steg-decode du1-obrazek.ppm