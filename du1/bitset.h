#include "error.h"
#include <stdlib.h>
#include <assert.h>

typedef unsigned long* bitset_t;
typedef unsigned long bitset_index_t;

#define USE_INLINE

#ifndef USE_INLINE //makra

#define bitset_create(array_name, size)({  })
#define bitset_alloc(array_name, size)({  })
#define bitset_free(array_name) free(array_name) 
#define bitset_size(array_name)({  })
#define bitset_setbit(array_name, index, expression)({  })
#define bitset_getbit(array_name, index)({  })

#else //inline funkce

static inline void bitset_create(bitset_t array_name, size_t size)
{
	array_name[0] = size;
	size = size / 8 / sizeof(unsigned long) + 2;
	for (size_t i = 1; i < size; i++)
		array_name[i] = 0;
}

static inline void bitset_alloc(bitset_t array_name, size_t size)
{
	array_name = malloc((size / (8 * sizeof(unsigned long)) + 2) * sizeof(unsigned long));
	assert(array_name != NULL && "bitset_alloc: Chyba alokace paměti");
	array_name[0] = size;

	printf("alloc: %ld : %ld:%ld\n\n", array_name[0], array_name[1], array_name[2]);
}

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

#endif