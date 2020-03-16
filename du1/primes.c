/* 
 * primes.c
 * 
 * Řešení IJC-DU1, příklad a)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Program vypíše posledních 10 prvočísel do 500,000,000 pomocí algoritmu Eratosthenova síta.
 */

#include <stdio.h>
#include <time.h>
#include "eratosthenes.h"

//#define PRIMES_COUNT 100
#define PRIMES_COUNT 500000000

int main()
{
	bitset_create(primes_bitset, PRIMES_COUNT);
	clock_t start;
	int p_cnt = 0;
	bitset_index_t primes[10];

	start = clock();
	Eratosthenes(primes_bitset);

	for (bitset_index_t i = bitset_size(primes_bitset); i >= 2 && p_cnt < 10; i--)
	{
		if (!bitset_getbit(primes_bitset, i))
			primes[p_cnt++] = i;
	}
	while (--p_cnt >= 0)
		printf("%lu\n", primes[p_cnt]);

	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}