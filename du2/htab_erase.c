/* 
 * htab_erase.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 11.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Ruší záznam v tabulce.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_types.h"

void htab_erase(htab_t * t, htab_iterator_t it)
{
	if (htab_iterator_valid(it))
	{
		struct htab_item *p = t->ptr[it.idx];

		//Ukazatel iterátoru není poslední v řádku
		if (p->next != NULL)
		{
			//Ukazatel je první v řádku tabulky
			if (p == it.ptr)
			{
				t->ptr[it.idx] = p->next;
			}
			else
			{
				//Nalezení předchůdce ukazatele iterátoru
				while (p->next != it.ptr)
					p = p->next;
				
				//Následník it.ptr nahradí it.ptr
				p->next = it.ptr->next;
			}
		}

		if (it.ptr == t->ptr[it.idx])
			t->ptr[it.idx] = NULL;

		free(it.ptr);
		t->size--;
	}
}