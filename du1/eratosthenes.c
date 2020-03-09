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
	bitset_index_t i;

	//0 a 1 nejsou prvočísla
	for (i = 0; i < 2; i++)
		bitset_setbit(pole, i, 1);

	//cyklus začíná ve 2 a končí v odmocnině z počtu bitů pole
	bitset_index_t end_bit = sqrt(bitset_size(pole));
	for ( ; i < end_bit; i++)
	{
		//bit[i] == 0: prvočíslo
		if (!bitset_getbit(pole, i))
		{
			//označíme násobky prvočísla 1 (není prvočíslo)
			for (bitset_index_t j = i * i; j <= bitset_size(pole); j += i)
				bitset_setbit(pole, j, 1);
		}		
	}
}