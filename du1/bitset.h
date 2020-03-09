/*
 * bitset.h
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Rozhraní definující datovou strukturu typu pole bitů a makra/inline funkce s tímto polem pracující.
 */

#ifndef BITSET_H
#define BITSET_H

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
#define bitset_create(jmeno_pole, velikost) \
	static_assert((velikost) > 0, "bitset_create: Velikost pole musi byt vetsi nez 0"); \
	unsigned long jmeno_pole[(velikost) / BITLENGTH + 2] = { (velikost), 0 }

//Dynamicky alokované a nulované pole bitů
#define bitset_alloc(jmeno_pole, velikost) \
	bitset_t jmeno_pole; \
	assert(("bitset_alloc: Chyba alokace pameti" && (jmeno_pole = calloc((velikost) / BITLENGTH + 2, sizeof(bitset_t))) != NULL)); \
	jmeno_pole[0] = velikost


#ifndef USE_INLINE //makra

//Uvolní dynamicky alokované bitové pole vytvořené bitset_alloc
#define bitset_free(jmeno_pole) \
	free(jmeno_pole) 

//První prvek pole - velikost bitového pole
#define bitset_size(jmeno_pole) \
	jmeno_pole[0]

//Nastaví bit pole na zadaném indexu na hodnotu zadanou výrazem
//nulový výraz:   0
//nenulový výraz: 1
#define bitset_setbit(jmeno_pole, index, vyraz) \
	(index) > bitset_size(jmeno_pole) \
	? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole)) , 2 \
	: (vyraz) \
		? (jmeno_pole[(index) / BITLENGTH + 1] |= 1UL << (index) % BITLENGTH) \
		: (jmeno_pole[(index) / BITLENGTH + 1] &= ~(1UL << (index) % BITLENGTH))

//Získá hodnotu zadaného bitu na zadaném indexu, vrací hodnotu 0 nebo 1
#define bitset_getbit(jmeno_pole, index) \
	((index) > bitset_size(jmeno_pole) \
	? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole)) , 2 \
	: !(jmeno_pole[(index) / BITLENGTH + 1] & (1UL << (index) % BITLENGTH)) ? 0 : 1)


#else //inline funkce

//Uvolní dynamicky alokované bitové pole vytvořené bitset_alloc
inline void bitset_free(bitset_t jmeno_pole)
{
	free(jmeno_pole);
}

//První prvek pole - velikost bitového pole
inline unsigned long bitset_size(bitset_t jmeno_pole)
{
	return jmeno_pole[0];
}

//Nastaví bit pole na zadaném indexu na hodnotu zadanou výrazem
//nulový výraz:   0
//nenulový výraz: 1
inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, unsigned char vyraz)
{
	if (index > bitset_size(jmeno_pole))
		error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole)-1);
		
	if (vyraz)
		jmeno_pole[index / BITLENGTH + 1] |= 1UL << index % BITLENGTH;
	else
		jmeno_pole[index / BITLENGTH + 1] &= ~(1UL << index % BITLENGTH);
}

//Získá hodnotu zadaného bitu na zadaném indexu, vrací hodnotu 0 nebo 1
inline unsigned char bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
{
	if (index > bitset_size(jmeno_pole))
		error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole)-1);

	return !(jmeno_pole[(index) / BITLENGTH + 1] & (1UL << (index) % BITLENGTH)) ? 0 : 1;
}

#endif //USE_INLINE
#endif //BITSET_H