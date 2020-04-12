# Makefile
#
# Řešení IJC-DU1
# Datum vytovření: 31.3.2020
# Autor: Tomáš Milostný, xmilos02, FIT VUT
# Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
#            g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
# Popis: Program make pro přeložení souborů projektu

all: tail wordcount-cc wordcount wordcount-dynamic clean_obj

CC = gcc
CXX = g++
CFLAGS = -g -std=c99 -pedantic -Wall -Wextra -O2 -fPIC
CXXFLAGS = -g -std=c++17 -pedantic -Wall -O2

#find -type f | grep "^\./htab_" | grep "\.c$" | sed "s/\.c/\.o/g"
OBJS  = htab_hash_fun.o htab_bucket_count.o htab_init.o htab_size.o htab_clear.o htab_free.o
OBJS += htab_iterator_next.o htab_begin.o htab_end.o htab_find.o htab_lookup_add.o
OBJS += htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_set_value.o htab_erase.o

tail: tail.c
	$(CC) $(CFLAGS) $^ -o $@

wordcount-cc: wordcount.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

wordcount: wordcount.o libhtab.a
	$(CC) $(CFLAGS) -o wordcount -static  wordcount.o -L. -lhtab

wordcount-dynamic: wordcount.o libhtab.so
	$(CC) $(CFLAGS) -o wordcount-dynamic  wordcount.o -L. -lhtab

# create static library 
libhtab.a: $(OBJS)
	ar crs libhtab.a $(OBJS)

# create shared library 
libhtab.so: $(OBJS)
	$(CC) $(CFLAGS) -shared -o libhtab.so $(OBJS)


clean_obj:
	rm -f *.o

clean: clean_obj
	rm -f tail wordcount-cc wordcount wordcount-dynamic libhtab.a libhtab.so

pack:
	zip xmilos02.zip *.c *.cc *.h Makefile

run:
	LD_LIBRARY_PATH="." ./wordcount-dynamic
	./wordcount