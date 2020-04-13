/* 
 * htab_iterator_get_key.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 11.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Vrací klíč, cíl musí existovat
 */

#include "htab.h"
#include "htab_types.h"

htab_key_t htab_iterator_get_key(htab_iterator_t it)
{
	return it.ptr->key;
}