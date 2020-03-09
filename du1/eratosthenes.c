/* 
 * eratosthenes.c
 * 
 * Řešení IJC-DU1, příklad a)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc 7.4
 * Popis: Implementace algoritmu Eratosthenovo síto pro vyhledávání prvočísel.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t pole)
{
	bitset_setbit(pole, 0, 1);
	bitset_setbit(pole, 1, 1);

	bitset_index_t end_bit = sqrt(bitset_size(pole));
	for (bitset_index_t i = 2; i < end_bit; i++)
	{
		if (bitset_getbit(pole, i) == 0)
		{
			for (bitset_index_t j = i * i; j <= bitset_size(pole); j += i)
				bitset_setbit(pole, j, 1);
		}		
	}
}