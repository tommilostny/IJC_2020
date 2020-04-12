/* 
 * htab_begin.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 11.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Iterátor odkazující na první záznam.
 */

#include "htab.h"
#include "htab_types.h"

htab_iterator_t htab_begin(const htab_t * t)
{
	htab_iterator_t it;
	it.t = t;
	it.idx = 0;
	it.ptr = t->ptr[0];

	while (it.ptr == NULL)
		it.ptr = t->ptr[++it.idx];

	return it;
}