/* 
 * htab_hash_fun.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 4.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Rozptylovací funkce pro řetězce (podle http://www.cse.yorku.ca/~oz/hash.html - sdbm)
 */

#include <stdint.h>
#include "htab.h"

#ifndef HASHTEST //rozptylovací funkce sdbm ze zadání

size_t htab_hash_fun(htab_key_t str)
{
	uint32_t hash = 0;
	const unsigned char *p;

	for (p = (const unsigned char *)str; *p != '\0'; p++)
		hash = 65599 * hash + *p;
	
	return hash;
}

#else //vlastní verze vytvořená podmíněným překladem

size_t htab_hash_fun(htab_key_t str)
{

}

#endif