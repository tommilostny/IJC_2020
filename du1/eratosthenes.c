#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Eratosthenes(bitset_t pole)
{
	bitset_index_t end_bit = sqrt(bitset_size(pole));
	for (bitset_index_t i = 2; i < end_bit; i++)
	{
		if (!bitset_getbit(pole, i))
		{
			for (bitset_index_t j = i * i; j <= bitset_size(pole); j += i)
				bitset_setbit(pole, j, 1);
		}
	}
}
