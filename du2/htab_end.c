/* 
 * htab_end.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 5.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Iterátor označující (neexistující) první záznam za koncem.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_types.h"

htab_iterator_t htab_end(const htab_t * t)
{
	struct htab_iterator it;
	it.t = t;
	it.idx = t->arr_size - 1;
	it.ptr = t->ptr[it.idx];

	while (it.ptr != NULL)
		it = htab_iterator_next(it);
	
	return it;
}