/* 
 * wordcount.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 31.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač:  gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 */

#include <stdio.h>
#include "htab.h"
#include "htab_types.h"

int main()
{
	htab_t *table = htab_init(2);

	htab_lookup_add(table, "ahoj");
	htab_lookup_add(table, "ahoj");
	htab_lookup_add(table, "heya");
	htab_lookup_add(table, "hey");
	htab_lookup_add(table, "ahoj");
	htab_lookup_add(table, "hey");
	htab_lookup_add(table, "azdar");

	htab_iterator_t it = htab_begin(table);

	for (int i = 1; htab_iterator_valid(it); i++)
	{
		printf("%d: %lu : %s : %d\n", i, it.idx, it.ptr->key, it.ptr->data);
		it = htab_iterator_next(it);
	}

	printf("=============================\n");
	it = htab_find(table, "heya");
	htab_erase(table, it);
	it = htab_begin(table);
	for (int i = 1; htab_iterator_valid(it); i++)
	{
		printf("%d: %lu : %s : %d\n", i, it.idx, it.ptr->key, it.ptr->data);
		it = htab_iterator_next(it);
	}

	htab_free(table);
	return 0;
}