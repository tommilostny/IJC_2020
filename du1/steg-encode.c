/* 
 * steg-encode.c
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Steganografický enkodér - Program zašifruje tajnou zprávu do souboru.
 *        Znaky zprávy jsou uložney na nejnižších významový bytech RBG bytů PPM obrázku.
 *        Vybrané byty jsou prvočíla počínaje 23.
 */

#include <stdio.h>
#include "ppm.h"
#include "eratosthenes.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("Nedostatečný počet argumentů.\nSpusťte program jako: ./steg-encode soubor.ppm\n");

	struct ppm *image = ppm_read(argv[1]);
	if (image == NULL)
		return 1;

	bitset_alloc(primes_bitset, image->xsize * image->ysize * 3);
	if (primes_bitset == NULL)
	{
		ppm_free(image);
		return 1;
	}

	unsigned char *message = malloc(bitset_size(primes_bitset));
	if (message == NULL)
	{
		bitset_free(primes_bitset);
		ppm_free(image);
		error_exit("Nedostatek paměti.\n");
	}

	printf("Zadejte zprávu, která bude zakódována do souboru '%s':\n", argv[1]);
	if (scanf("%s", message) == EOF)
	{
		free(message);
		bitset_free(primes_bitset);
		ppm_free(image);
		error_exit("Chyba při čtení vstupu.\n");
	}
	//printf("%s\n", message);

	//Eratosthenes(primes_bitset);

	free(message);
	bitset_free(primes_bitset);
	ppm_free(image);
	return 0;
}