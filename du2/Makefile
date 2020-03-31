# Makefile
#
# Řešení IJC-DU1
# Datum vytovření: 31.3.2020
# Autor: Tomáš Milostný, xmilos02, FIT VUT
# Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
#            g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
# Popis: Program make pro přeložení souborů projektu

all: tail wordcount-cc wordcount

CC = gcc
CXX = g++
CFLAGS = -g -std=c99 -pedantic -Wall -Wextra
CXXFLAGS = -g -std=c++17 -pedantic -Wall
LDFLAGS = -lm

tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount-cc: wordcount-cc.o
	$(CXX) $(CXXFLAGS) $^ -o $@

wordcount: wordcount.o
	$(CC) $(CFLAGS) $^ -o $@


# gcc -MM *.c
tail.o: tail.c
wordcount-cc.o: wordcount.cc
wordcount.o: wordcount.c

.PHONY: clean

clean:
	rm -f *.o
	rm -f primes primes-i steg-decode steg-encode

pack:
	zip xmilos02.zip *.c *.h Makefile

#run:
#	ulimit -s 125000 && ./primes ; ./primes-i
#	./steg-decode du1-obrazek.ppm