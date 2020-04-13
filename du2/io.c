/* 
 * io.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 13.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul čtení slova ze standardního vstupu.
 */

#include "io.h"

int get_word(char *s, int max, FILE *f)
{
	for (int i = 0; i < max - 1; i++)
	{
		int c = fgetc(f);
		if (c == EOF || isspace(c))
		{
			s[i] = '\0';
			return c == EOF ? EOF : i;
		}
		s[i] = c;
	}
	
	//Chyba - dlouhé slovo
	s[max - 1] = '\0';
	return LONG_WORD_ERROR;
}