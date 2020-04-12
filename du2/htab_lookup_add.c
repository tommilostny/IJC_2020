/* 
 * htab_lookup_add.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 11.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
        - pokud jej nalezne, vrátí iterátor na záznam
        - pokud nenalezne, automaticky přidá záznam a vrátí iterátor
 */

#include <stdlib.h>
#include <string.h>
#include "htab.h"
#include "htab_types.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key)
{
	htab_iterator_t iterator = htab_find(t, key);

	if (htab_iterator_equal(iterator, htab_end(t)))
	{
		//Záznam nenalezen, vytvoření nového a přidání na konec řádku
		struct htab_item *new_item = malloc(sizeof(struct htab_item));

		char* new_key = malloc(strlen(key));
		strcpy(new_key, key);
		new_item->key = new_key;

		new_item->next = NULL;

		size_t index = htab_hash_fun(key) % htab_bucket_count(t);

		//Prázdný řádek, první záznam
		if (t->ptr[index] == NULL)
		{
			t->ptr[index] = new_item;
		}
		else //Vložení na konec řádku tabulky
		{
			iterator.ptr = t->ptr[index];
			while (iterator.ptr->next != NULL)
				iterator = htab_iterator_next(iterator);

			iterator.ptr->next = new_item;
		}
		iterator.idx = index;
		iterator.ptr = new_item;
		t->size++;
	}

	return iterator;
}