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
	struct ppm *image = NULL;
	FILE* ppm_file = fopen(filename, "r");

	if (ppm_file == NULL)
	{
		warning_msg("%s: Soubor nelze otevřít pro čtení.\n", filename);
		return NULL;
	}

	char buffer[2];
	if (fscanf(ppm_file, "%c%c\n", &buffer[0], &buffer[1]) != 2)
	{
		warning_msg("%s: Neplatný soubor.\n", filename);
		goto error_end;
	}
	if (buffer[0] != 'P' || buffer[1] != '6')
	{
		warning_msg("%s: Chybný formát souboru PPM (musí být P6).\n", filename);
		goto error_end;
	}
	
	image = malloc(sizeof(struct ppm));
	if (image == NULL)
	{
		warning_msg("%s: Nedostatek paměti pro alokaci struktury PPM.\n", filename);
		goto error_end;
	}

	unsigned x_size;
	unsigned y_size;
	unsigned rgb_size;
	if (fscanf(ppm_file, "%u %u\n%u\n", &x_size, &y_size, &rgb_size) != 3)
	{
		warning_msg("%s: Chyba načítaní rozměrů obrázku.\nx:%u\ny:%u\nrgb:%u\nbuffer:%s\n", filename, x_size, y_size, rgb_size, buffer);
		goto error_end;
	}
	if (rgb_size != 255)
	{
		warning_msg("%s: RGB formát souboru musí být 255.\n", filename);
		goto error_end;
	}

	unsigned image_size = x_size * y_size * 3;
	if (image_size > PPM_LIMIT)
	{
		warning_msg("%s: Příliš vysoké rozlišení.\n", filename);
		goto error_end;
	}

	image->xsize = x_size;
	image->ysize = y_size;
	image->data = malloc(image_size);
	if (image->data == NULL)
	{
		warning_msg("%s: Nedostatek paměti pro obrazová data.\nRozměr obrázku: %u * %u", filename, x_size, y_size);
		goto error_end;
	}

	for (unsigned i = 0; i < image_size; i++)
	{
		if (!fscanf(ppm_file, "%c", &image->data[i]))
		{
			warning_msg("%s: Chyba při načítání RGB bytů.\n", filename);
			goto error_end;
		}
	}
	
	fclose(ppm_file);
	return image;

	error_end:
		fclose(ppm_file);
		ppm_free(image);
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