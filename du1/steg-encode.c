/* 
 * steg-encode.c
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Steganografický enkodér - Program zašifruje tajnou zprávu do souboru.
 *        Znaky zprávy jsou uloženy na nejnižších významový bytech RBG bytů PPM obrázku.
 *        Vybrané byty jsou prvočíla počínaje 23.
 *        Argumentem programu #1 je ppm obrázek zdrojový
 *        Nepovinným argumentem #2 je cílový soubor (výchozí - přepíše zdrojový soubor)
 */

#include <stdio.h>
#include <string.h>
#include "ppm.h"
#include "eratosthenes.h"

int main(int argc, char **argv)
{
	if (argc < 2)
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

	char *message = malloc(bitset_size(primes_bitset));
	if (message == NULL)
	{
		bitset_free(primes_bitset);
		ppm_free(image);
		error_exit("Nedostatek paměti.\n");
	}

	printf("Zadejte zprávu, která bude zakódována do souboru '%s':\n", argv[1]);
	if (fgets(message, bitset_size(primes_bitset), stdin) == NULL)
	{
		free(message);
		bitset_free(primes_bitset);
		ppm_free(image);
		error_exit("Chyba při čtení vstupu.\n");
	}

	size_t message_length = strlen(message);
	message[message_length - 1] = '\0';

	Eratosthenes(primes_bitset);
	bitset_index_t prime_index = 23; //prvočíselný index, začíná na 23

	for (size_t i = 0; i < message_length; i++)
	{
		//pro každý bit písmena
		for (char charbit_index = 0; charbit_index < CHAR_BIT; charbit_index++)
		{
			//najít další prvočíslo
			while (bitset_getbit(primes_bitset, prime_index))
				prime_index++;

			//maskování na 1
			if (message[i] & (1 << charbit_index))
				image->data[prime_index++] |= 0x01;
			
			//maskování na 0
			else
				image->data[prime_index++] &= 0xFE;
		}
	}

	if (ppm_write(image, argv[argc - 1]))
		warning_msg("%s: Nastala chyba při zápisu do souboru.\n", argv[argc - 1]);

	free(message);
	bitset_free(primes_bitset);
	ppm_free(image);
	return 0;
}