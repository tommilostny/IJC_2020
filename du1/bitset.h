/*
 * bitset.h
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Rozhraní definující datovou strukturu typu pole bitů a makra/inline funkce s tímto polem pracující.
 */

#pragma once

#include <assert.h>
#include <limits.h>
#include <malloc.h>
#include "error.h"

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

//Velikost jednotky bitového pole v bitech
#define BITLENGTH (sizeof(unsigned long) * CHAR_BIT)

//Vytvoří lokální pole bitů,
//inicializuje první prvek - zadaná velikost;
//bitové pole nuluje
#define bitset_create(array_name, bitset_length) \
	static_assert((bitset_length) > 0, "bitset_create: Velikost pole musi byt vetsi nez 0"); \
	unsigned long array_name[(bitset_length) / BITLENGTH + 2] = { (bitset_length), 0 }

//Dynamicky alokované a nulované pole bitů
#define bitset_alloc(array_name, bitset_length) \
	bitset_t array_name; \
	assert(("bitset_alloc: Chyba alokace pameti" && (array_name = calloc((bitset_length) / BITLENGTH + 2, sizeof(bitset_t))) != NULL)); \
	array_name[0] = bitset_length


#ifndef USE_INLINE //makra

//Uvolní dynamicky alokované bitové pole vytvořené bitset_alloc
#define bitset_free(array_name) \
	free(array_name) 

//První prvek pole - velikost bitového pole
#define bitset_size(array_name) \
	array_name[0]

//Nastaví bit pole na zadaném indexu na hodnotu zadanou výrazem
//nulový výraz:   0
//nenulový výraz: 1
#define bitset_setbit(array_name, index, expression) \
	(index) > bitset_size(array_name) \
	? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)(index), bitset_size(array_name)) , 2 \
	: (expression) \
		? (array_name[(index) / BITLENGTH + 1] |= 1UL << (index) % BITLENGTH) \
		: (array_name[(index) / BITLENGTH + 1] &= ~(1UL << (index) % BITLENGTH))

//Získá hodnotu zadaného bitu na zadaném indexu, vrací hodnotu 0 nebo 1
#define bitset_getbit(array_name, index) \
	((index) > bitset_size(array_name) \
	? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)(index), bitset_size(array_name)) , 2 \
	: !(array_name[(index) / BITLENGTH + 1] & (1UL << (index) % BITLENGTH)) ? 0 : 1)


#else //inline funkce

//Uvolní dynamicky alokované bitové pole vytvořené bitset_alloc
inline void bitset_free(bitset_t array_name)
{
	free(array_name);
}

//První prvek pole - velikost bitového pole
inline unsigned long bitset_size(bitset_t array_name)
{
	return array_name[0];
}

//Nastaví bit pole na zadaném indexu na hodnotu zadanou výrazem
//nulový výraz:   0
//nenulový výraz: 1
inline void bitset_setbit(bitset_t array_name, bitset_index_t index, unsigned char expression)
{
	if (index > bitset_size(array_name))
		error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(array_name)-1);
		
	if (expression)
		array_name[index / BITLENGTH + 1] |= 1UL << index % BITLENGTH;
	else
		array_name[index / BITLENGTH + 1] &= ~(1UL << index % BITLENGTH);
}

//Získá hodnotu zadaného bitu na zadaném indexu, vrací hodnotu 0 nebo 1
inline unsigned char bitset_getbit(bitset_t array_name, bitset_index_t index)
{
	if (index > bitset_size(array_name))
		error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(array_name)-1);

	return !(array_name[(index) / BITLENGTH + 1] & (1UL << (index) % BITLENGTH)) ? 0 : 1;
}

#endif