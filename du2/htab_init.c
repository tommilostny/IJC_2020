/* 
 * htab_init.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 4.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač:  gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul inicializace tabulky.
 */

#include "htab.h"
#include "htab_types.h"
#include <stdlib.h>

htab_t *htab_init(size_t n)
{
	static htab_t tab;

	tab.size = 0;
	tab.arr_size = n;
	tab.ptr = malloc(n * sizeof(struct htab_item *));

	return &tab;
}