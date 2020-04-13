/* 
 * htab_types.h
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 4.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Privátní definice struktur pro všechny moduly tabulky.
 */

#pragma once

struct htab
{
	size_t size; // aktuální počet záznamů [key,data,next]
	size_t arr_size; // velikost následujícího pole ukazatelů
	struct htab_item **ptr;
};

struct htab_item
{
	htab_key_t key;
	htab_value_t data;
	struct htab_item *next;
};