/* 
 * htab_init.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 4.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul inicializace tabulky.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_types.h"

htab_t *htab_init(size_t n)
{
	htab_t *tab;
	if ((tab = malloc(sizeof(htab_t))) != NULL)
	{
		if ((tab->ptr = calloc(n, sizeof(struct htab_item))) != NULL)
		{ 
			tab->size = 0;
			tab->arr_size = n;
			
			return tab;
		}
		free(tab);
	}
	return NULL;
}