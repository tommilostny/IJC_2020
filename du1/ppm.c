/* 
 * ppm.c
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Modul pro čtení obrázkových souborů typu PPM.
 */

#include <stdio.h>
#include <malloc.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename)
{
	FILE* ppm_file = fopen(filename, "r");
	if (ppm_file == NULL)
		return NULL;

	struct ppm *p = malloc(sizeof(struct ppm));
	if (p == NULL)
		goto error_end;

	char p6_buffer[2];
	unsigned rgb_size;

	//načtení dat z hlavičky ppm souboru
	if (fscanf(ppm_file, "%c%c\n%u %u\n%u\n", &p6_buffer[0], &p6_buffer[1], &p->xsize, &p->ysize, &rgb_size) != 5)
		goto error_end;

	//kontrola formátu ppm: P6, RGB 255
	if (p6_buffer[0] != 'P' || p6_buffer[1] != '6' || rgb_size != 255)
		goto error_end;

	unsigned image_size = p->xsize * p->ysize * 3;

	//kontrola limitu 8000*8000*3
	if (image_size > PPM_LIMIT)
		goto error_end;

	if ((p->data = malloc(image_size)) == NULL)
		goto error_end;

	//načtení RGB dat
	for (unsigned i = 0; i < image_size; i++)
	{
		if (!fscanf(ppm_file, "%c", &p->data[i]))
			goto error_end;
	}
	
	fclose(ppm_file);
	return p;

	error_end:
		fclose(ppm_file);
		ppm_free(p);
		return NULL;
}

void ppm_free(struct ppm *p)
{
	if (p != NULL)
	{
		free(p->data);
		free(p);
	}
}

int ppm_write(struct ppm *p, const char *filename)
{
	FILE* ppm_file = fopen(filename, "w");

	if (ppm_file == NULL)
		return 1;

	fprintf(ppm_file, "P6\n%u %u\n255\n", p->xsize, p->ysize);

	for (size_t i = 0; i < p->xsize * p->ysize * 3; i++)
	{
		if (fputc(p->data[i], ppm_file) == EOF)
			return 1;
	}

	fclose(ppm_file);
	return 0;
}