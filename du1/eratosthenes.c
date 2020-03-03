#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Eratosthenes(bitset_t array)
{
	bitset_index_t end_bit = sqrt(bitset_size(array));
	for (bitset_index_t i = 2; i < end_bit; i++)
	{
		if (bitset_getbit(array, i) == 0)
		{
			for (bitset_index_t j = i * i; j <= bitset_size(array); j += i)
				bitset_setbit(array, j, 1);
		}		
	}
}
