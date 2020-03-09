# Makefile
# Řešení IJC-DU1, 3.3.2020
# Autor:     Tomáš Milostný, xmilos02, FIT VUT
# Přeloženo: gcc 7.4
# TODO:popis upravit
# Popis: Zajisti preklad pouze zmenenych nebo neexistujicich souboru
#				 clean: smaze vsechny .o a binarni soubory
#				 run: spusti primes a primes-i stylem "time ./program"
#							a steg-decode stylem "./steg-decode du1-obrazek.ppm"

default_target: all

CC=gcc

CFLAGS=-g -O2 -std=c11 -pedantic -Wall -Wextra

all: clean primes primes-i steg-decode #steg-encode


primes: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) error.o eratosthenes.o primes.o -o $@ -lm

primes-i: error.o eratosthenes.o primes.o
	$(CC) $(CFLAGS) error.o eratosthenes.o primes.o -o $@ -lm -DUSE_INLINE

steg-decode: error.o ppm.o eratosthenes.o steg-decode.o
	$(CC) $(CFLAGS) error.o ppm.o eratosthenes.o steg-decode.o -o $@ -lm


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

run:
	time ./primes
	time ./primes-i
#	./steg-decode du1-obrazek.ppm