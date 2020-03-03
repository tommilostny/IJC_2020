// primes.c
// Řešení IJC-DU1, příklad a), 3.3.2020
// Autor: Tomáš Milostný, FIT
// Přeloženo: gcc 7.4
// ...popis příkladu - poznámky, omezení, atd

#include "eratosthenes.h"
#include <time.h>

//#define PRIMES_COUNT 100
#define PRIMES_COUNT 500000000

int main()
{
	bitset_create(primes_bitset, PRIMES_COUNT);
	clock_t start;
	unsigned char p_cnt = 0;
	unsigned long primes[10];

	start = clock();
	Eratosthenes(primes_bitset);

	for (bitset_index_t i = bitset_size(primes_bitset); i > 2 && p_cnt < 10; i--)
	{
		if (bitset_getbit(primes_bitset, i) == 0)
			primes[p_cnt++] = i;
	}
	
	unsigned char i = 10;
	while (i > 0)
		printf("%lu\n", primes[--i]);

	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
