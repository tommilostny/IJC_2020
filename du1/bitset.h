// bitset.h
// Řešení IJC-DU1, příklad a), 3.3.2020
// Autor: Tomáš Milostný, xmilos02, FIT VUT
// Přeloženo: gcc 7.4
// ...popis příkladu - poznámky, omezení, atd

#ifndef BITSET_H
#define BITSET_H

#include <assert.h>
#include <limits.h>
#include "error.h"

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

#define BITLENGTH (sizeof(unsigned long) * CHAR_BIT)

#define bitset_create(array_name, size) \
	static_assert(size > 0, "bitset_create: Velikost pole musi byt vetsi nez 0"); \
	unsigned long array_name[(size) / BITLENGTH + 2] = { (size), 0 }

#define bitset_alloc(array_name, size) \
	bitset_t array_name; \
	assert(("bitset_alloc: Chyba alokace pameti", (array_name = malloc((size) / BITLENGTH + 2)) != NULL)); \
	array_name[0] = size; \
	for (size_t i = 1; i < (size) / BITLENGTH + 2; i++) array_name[i] = 0


#ifndef USE_INLINE //makra

#define bitset_free(array_name) \
	free(array_name) 

#define bitset_size(array_name) \
	array_name[0]

#define bitset_setbit(array_name, index, expression) \
	(index) > bitset_size(array_name) \
	? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(array_name)-1) , 2 \
	: (expression) \
		? (array_name[(index) / BITLENGTH + 1] |= 1UL << (index) % BITLENGTH) \
		: (array_name[(index) / BITLENGTH + 1] &= ~(1UL << (index) % BITLENGTH))

#define bitset_getbit(array_name, index) \
	(index) > bitset_size(array_name) \
	? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(array_name)-1) , 2 \
	: (!(array_name[(index) / BITLENGTH + 1] & (1UL << (index) % BITLENGTH)) ? 0 : 1)


#else //inline funkce

static inline void bitset_free(bitset_t array_name)
{
	free(array_name);
}

static inline unsigned long bitset_size(bitset_t array_name)
{
	return array_name[0];
}

static inline void bitset_setbit(bitset_t array_name, bitset_index_t index, unsigned char expression)
{
	if (index > bitset_size(array_name))
		error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(array_name)-1);
		
	if (expression)
		array_name[index / BITLENGTH + 1] |= 1UL << index % BITLENGTH;
	else
		array_name[index / BITLENGTH + 1] &= ~(1UL << index % BITLENGTH);
}

static inline unsigned char bitset_getbit(bitset_t array_name, bitset_index_t index)
{
	if (index > bitset_size(array_name))
	{
		error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(array_name)-1);
		return 2;
	}
	return !(array_name[(index) / BITLENGTH + 1] & (1UL << (index) % BITLENGTH)) ? 0 : 1;
}

#endif //USE_INLINE
#endif //BITSET_H