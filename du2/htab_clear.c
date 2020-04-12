/* 
 * htab_clear.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 5.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul zrušení všech položek, tabulka zůstane prázdná.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_types.h"

void htab_clear(htab_t * t)
{
	for (size_t i = 0; i < htab_bucket_count(t); i++)
	{
		if (t->ptr[i] != NULL)
		{
			//Smazání všech záznamů v neprázdném řádku
			struct htab_item *item = t->ptr[i]->next;
			while (item != NULL)
			{
				struct htab_item *next = item->next;
				free(item);
				item = next;
			}
			free(t->ptr[i]);
		}
	}
	t->size = 0;
}