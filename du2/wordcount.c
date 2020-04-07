/* 
 * wordcount.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 31.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač:  gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 */

#include <stdio.h>
#include "htab.h"

int main()
{
	htab_t *table = htab_init(42);
	printf("%ld\n", htab_bucket_count(table));

	htab_free(table);
	return 0;
}