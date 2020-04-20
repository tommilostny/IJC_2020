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
#include "io.h"

#define MAX_WORD_LENGTH 127

int main()
{
	/* Konstanta sdbm 65599 (/2 = 32799, /4 = 16399, ...)
	 *
	 * time ./wordcount-dynamic </usr/share/dict/words :    ~ 6.5s
	 * time ./wordcount-cc </usr/share/dict/words      :    ~ 6.9s
	 * 
	 * Testovací ~13 MB soubor náhodně generovaného textu:
	 * 	wordcount-dynamic : ~0.18s
	 *  wordcount-cc      : ~0.55s
	 */
	htab_t *table = htab_init(16399);
	if (table == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		return 1;
	}

	char word[MAX_WORD_LENGTH];
	int gw_status, warning_cnt = 0;

	//Načtení slova ze vstupu
	do { gw_status = get_word(word, MAX_WORD_LENGTH, stdin);

		if (word[0] != '\0')
		{
			//Nalezení/přidání slova do tabulky
			htab_iterator_t i = htab_lookup_add(table, word);

			//Chyba alokace paměti v lookup add
			if (htab_iterator_equal(i, htab_end(table)))
			{
				fprintf(stderr, "Error: Unable to allocate memory.\n");
				htab_free(table);
				return 1;
			}

			//Inkrementace nalezené hodnoty (nová hodnota jako 0 + 1)
			htab_iterator_set_value(i, htab_iterator_get_value(i) + 1);
		}

		//Chyba příliš dlouhého slova
		if (gw_status == LONG_WORD_ERROR)
		{
			//Výpis maximálně jednoho varování
			if (warning_cnt < 1)
			{
				fprintf(stderr, "Warning: %s: word is too long (max length = %d).\n\n", word, MAX_WORD_LENGTH);
				warning_cnt++;
			}
			//Posunutí za nejbližší mezeru, před další slovo
			while ((gw_status = getchar()) != EOF && !isspace(gw_status));
		}	
	}
	while (gw_status != EOF);

	//Výpis nalezených slov - klíč, hodnota
	for (htab_iterator_t i = htab_begin(table); htab_iterator_valid(i); i = htab_iterator_next(i))
	{
		printf("%s\t%d\n", htab_iterator_get_key(i), htab_iterator_get_value(i));
	}

	htab_free(table);
	return 0;
}