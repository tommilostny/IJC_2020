#include <stdio.h>
//#include <stdlib.h>

//#include "error.h"
//#include "bitset.h"
//#include <stdbool.h>
//#include "ppm.h"
#include "eratosthenes.h"

#define SETSIZE 160

//#define PPM_DEBUG
#define BITSET_DEBUG

int main()
{
	#ifdef PPM_DEBUG

	struct ppm *myimage = ppm_read("du1-obrazek.ppm");
	ppm_free(myimage);

	#endif

//	#ifdef BITSET_DEBUG
	bitset_create(my_bitset, SETSIZE);

	Eratosthenes(my_bitset);

	for (size_t i = 1; i <= SETSIZE; i++)
	{
		if (!bitset_getbit(my_bitset, i))
			printf("%d\n", i);
	}
	return 0;

	//bitset_getbit(my_bitset, -5);
	//bitset_getbit(my_bitset, 2000);
	//bitset_setbit(my_bitset, -5, 1);
	//bitset_setbit(my_bitset, 2000, 1);
/*
	for (size_t i = 0; i < SETSIZE; i++)
		printf("%d", bitset_getbit(my_bitset, i));
	printf("\n");

	for (size_t i = 0; i <= bitset_size(my_bitset); i++)
	{
		if (bitset_getbit(my_bitset, i) != 0)
			warning_msg("%u: error 0 : %d\n", i, bitset_getbit(my_bitset, i));

		bitset_setbit(my_bitset, i, 1);
		
		if (bitset_getbit(my_bitset, i) == 0)
			warning_msg("%u: error 1: %d\n", i, bitset_getbit(my_bitset, i));

		printf("%d", bitset_getbit(my_bitset, i));
	}

	printf("\n%ld, %lu, %lu, %lu\n\n", my_bitset[0], my_bitset[1], my_bitset[2], my_bitset[3]);

	printf("\n:%d:%d:%d\n", bitset_getbit(my_bitset, 71), bitset_getbit(my_bitset, 70), bitset_getbit(my_bitset, 0));

	bitset_alloc(my_bitset2, 150);
	printf("%ld, %ld, %ld, %ld\n\n", my_bitset2[0], my_bitset2[1], my_bitset2[2], my_bitset2[3]);

	printf("size1: %ld\nsize2: %ld\n", bitset_size(my_bitset), bitset_size(my_bitset2));

	printf("------------ALLOC-------------\n");
	for (bitset_index_t i = 0; i <= bitset_size(my_bitset2); i++)
	{
		printf("%d", bitset_getbit(my_bitset2, i));
	}
	printf("\n");
	for (bitset_index_t i = 0; i <= bitset_size(my_bitset2); i++)
	{
		bitset_setbit(my_bitset2, i, 1);
		printf("%d", bitset_getbit(my_bitset2, i));
	}
	printf("\n------------------------------\n");

	bitset_free(my_bitset2);

	//error_exit("nechyba\n");
	#endif
*/
	return 0;
}