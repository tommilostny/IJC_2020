/* 
 * eratosthenes.c
 * 
 * Řešení IJC-DU1, příklad a)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Implementace algoritmu Eratosthenovo síto pro vyhledávání prvočísel.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t array)
{
	bitset_index_t i;

	//0 a 1 nejsou prvočísla
	for (i = 0; i < 2; i++)
		bitset_setbit(array, i, 1);

	//cyklus začíná ve 2 a končí v odmocnině z počtu bitů pole
	for (bitset_index_t end_bit = sqrt(bitset_size(array)); i < end_bit; i++)
	{
		//bit[i] == 0: prvočíslo
		if (!bitset_getbit(array, i))
		{
			//označíme násobky prvočísla 1 (není prvočíslo)
			for (bitset_index_t j = i * i; j <= bitset_size(array); j += i)
				bitset_setbit(array, j, 1);
		}
	}
}