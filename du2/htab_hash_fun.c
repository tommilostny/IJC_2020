/* 
 * htab_hash_fun.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 4.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Rozptylovací funkce pro řetězce (podle http://www.cse.yorku.ca/~oz/hash.html)
 */

#include <stdint.h>
#include "htab.h"

#ifndef HASHTEST //rozptylovací funkce ze zadání (sdbm)

size_t htab_hash_fun(htab_key_t str)
{
	uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}

#else //verze vytvořená podmíněným překladem (djb2)

size_t htab_hash_fun(htab_key_t str)
{
	uint32_t h = 0;
	htab_key_t p = str;

	while (*p != '\0')
        h = ((h << 5) + h) + *p++;
	
	return h;
}

#endif