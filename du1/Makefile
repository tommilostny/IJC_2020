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


primes:
	$(CC) $(CFLAGS) primes.c -o primes -lm

primes-i:
	$(CC) $(CFLAGS) primes.c -o primes-i -lm -DUSE_INLINE

steg-decode:
	$(CC) $(CFLAGS) steg-decode.c -o steg-decode -lm

debug:
	$(CC) $(CFLAGS) debug.c -o debug

clean:
	rm -f *.o
	rm -f primes primes-i steg-decode steg-encode

pack:
	zip xmilos02.zip *.c *.h Makefile

run:
	time ./primes
	time ./primes-i
#	./steg-decode du1-obrazek.ppm