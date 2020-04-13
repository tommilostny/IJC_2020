/* 
 * htab_clear.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 5.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul zrušení všech položek, tabulka zůstane prázdná.
 */

#include "htab.h"

void htab_clear(htab_t * t)
{
	htab_iterator_t it = htab_begin(t);
	while (htab_size(t) > 0)
	{
		htab_iterator_t next = htab_iterator_next(it);
		htab_erase(t, it);
		it = next;
	}
}