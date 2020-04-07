/* 
 * htab_init.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 5.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač:  gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul funkce vracející počet prvků tabulky (.size).
 */

#include "htab.h"
#include "htab_types.h"

size_t htab_size(const htab_t * t)
{
	return t->size;
}