/* 
 * wordcount.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 31.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 */

#include <stdio.h>
#include "htab.h"

#define MAX_WORD_LENGTH 127

int main()
{
	//TODO: rozmyslet si tuto velikost a odůvodnit to
	htab_t *table = htab_init(8);

	char word[MAX_WORD_LENGTH + 1];
	while(scanf("%s", word) != EOF) //TODO: nahradit get_word z modulu io.c
	{
		//Nalezení/přidání slova do tabulky
		htab_iterator_t i = htab_lookup_add(table, word);

		//Inkrementace nalezené hodnoty (nová hodnota jako 0 + 1)
		htab_iterator_set_value(i, htab_iterator_get_value(i) + 1);
	}

	//Výpis nalezených slov - klíč, hodnota
	for (htab_iterator_t i = htab_begin(table); htab_iterator_valid(i); i = htab_iterator_next(i))
	{
		printf("%s\t%d\n", htab_iterator_get_key(i), htab_iterator_get_value(i));
	}

	htab_free(table);
	return 0;
}