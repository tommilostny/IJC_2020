/* 
 * htab_find.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 11.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul hledání v tabulce.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_types.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key)
{
	htab_iterator_t it;
	it.t = t;
	it.idx = (htab_hash_fun(key) % htab_bucket_count(t));
	it.ptr = t->ptr[it.idx];

	while (it.ptr != NULL)
	{
		if (it.ptr->key == key)
			return it;

		if (it.ptr->next != NULL)
			it = htab_iterator_next(it);
	}
	return htab_end(t);
}