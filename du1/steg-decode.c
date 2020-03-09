/* 
 * steg-decode.c
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc 7.4
 * Popis: Steganografický dekodér - Program přečtě zašifrovanou tajnou zprávu ze souboru.
 *        Znaky zprávy jsou uložney na nejnižších významový bytech RBG bytů PPM obrázku.
 *        Vybrané byty jsou prvočíla počínaje 23.
 */

#include "ppm.h"
#include "eratosthenes.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("Too few arguments. Run as ./steg-decode file.ppm\n");
	
	struct ppm *image = ppm_read(argv[1]);
	if (image == NULL)
		return 1;

	bitset_alloc(primes_bitset, image->xsize * image->ysize * 3);
	if (primes_bitset == NULL)
		return 1;

	Eratosthenes(primes_bitset);

	unsigned char secret_character = 0;
	unsigned char c_length = 0; //c_lenght == 8 : complete char c for printing

	for (bitset_index_t i = 23; i < bitset_size(primes_bitset); i++)
	{
		if (!bitset_getbit(primes_bitset, i))
		{
			secret_character |= (0x01 & image->data[i]) << c_length;
			
			if (++c_length == CHAR_BIT)
			{
				if (secret_character == '\0')
					break;

				putchar(secret_character);
				c_length = secret_character = 0;
			}
		}
	}
	putchar('\n');

	bitset_free(primes_bitset);
	ppm_free(image);
	return 0;
}