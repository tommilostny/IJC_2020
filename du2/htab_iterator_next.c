/* 
 * htab_iterator_next.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 11.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Posun iterátoru na další záznam v tabulce.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_types.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
	if (htab_iterator_valid(it))
	{
		//Další záznam je konec řádku
		if ((it.ptr = it.ptr->next) == NULL)
		{
			//Nalezení nejbližšího existujícího záznamu
			for (size_t i = it.idx + 1; i < htab_bucket_count(it.t); i++)
			{
				it.ptr = it.t->ptr[i];
				it.idx = i;

				if (it.ptr != NULL)
					break;
			}
		}
	}
	return it;
}