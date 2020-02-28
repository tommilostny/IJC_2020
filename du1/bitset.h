#ifndef BITSET_H
#define BITSET_H

#include <assert.h>
#include <limits.h>
#include "error.h"

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

#define BITLENGTH (sizeof(unsigned long) * (CHAR_BIT))

#define bitset_create(array_name, size) \
	static_assert(size > 0, "bitset_create: Velikost pole musi byt vetsi nez 0"); \
	unsigned long array_name[size / BITLENGTH + 2] = { size, 0 }

#define bitset_alloc(array_name, size) \
	bitset_t array_name; \
	assert((array_name = malloc(size / BITLENGTH + 2)) != NULL && "bitset_alloc: Chyba alokace pameti"); \
	array_name[0] = size; \
	for (size_t i = 1; i < size / BITLENGTH + 2; i++) array_name[i] = 0


#ifndef USE_INLINE //makra

#define bitset_free(array_name) free(array_name) 

#define bitset_size(array_name) array_name[0]

#define bitset_setbit(array_name, index, expression)({  })

#define bitset_getbit(array_name, index)({  })


#else //inline funkce

static inline void bitset_free(bitset_t array_name)
{
	free(array_name);
}

static inline size_t bitset_size(bitset_t array_name)
{
	return array_name[0];
}

static inline void bitset_setbit(bitset_t array_name, bitset_index_t index, unsigned char expression)
{

}

static inline void bitset_getbit(bitset_t array_name, bitset_index_t index)
{

}

#endif //USE_INLINE
#endif //BITSET_H