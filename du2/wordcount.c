/* 
 * wordcount.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 31.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 */

#include <stdio.h>
#include "htab.h"
#include "htab_types.h"

int main()
{
	htab_t *table = htab_init(8);

	char word[256];
	while(scanf("%s", word) != EOF)
	{
		htab_lookup_add(table, word).ptr->data++;
	}

	for (htab_iterator_t i = htab_begin(table); htab_iterator_valid(i); i = htab_iterator_next(i))
	{
		printf("%s\t%d\n", i.ptr->key, i.ptr->data);
	}

	htab_free(table);
	return 0;
}