// ppm.c
// Řešení IJC-DU1, příklad b), 3.3.2020
// Autor: Tomáš Milostný, xmilos02, FIT VUT
// Přeloženo: gcc 7.4
// ...popis příkladu - poznámky, omezení, atd

#include <stdio.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename)
{
	struct ppm *image = NULL;
	FILE* ppm_file = fopen(filename, "rb");

	if (ppm_file == NULL)
	{
		warning_msg("%s: Unable to open file.\n", filename);
		return NULL;
	}

	char buffer[2];
	if (fscanf(ppm_file, "%c%c\n", &buffer[0], &buffer[1]) != 2)
	{
		warning_msg("%s: Invalid file format.\n", filename);
		goto error_end;
	}
	if (buffer[0] != 'P' || buffer[1] != '6')
	{
		warning_msg("%s: Invalid PPM file format (must be P6).\n", filename);
		goto error_end;
	}
	
	image = malloc(sizeof(struct ppm));
	if (image == NULL)
	{
		warning_msg("%s: Unable to allocate memory.\n", filename);
		goto error_end;
	}

	unsigned x_size;
	unsigned y_size;
	unsigned rgb_size;
	if (fscanf(ppm_file, "%u %u\n%u\n", &x_size, &y_size, &rgb_size) != 3)
	{
		warning_msg("%s: Error loading image size.\nx:%u\ny:%u\nrgb:%u\nbuffer:%s\n", filename, x_size, y_size, rgb_size, buffer);
		goto error_end;
	}
	if (rgb_size != 255)
	{
		warning_msg("%s: RGB format must be 255.\n", filename);
		goto error_end;
	}

	unsigned image_size = x_size * y_size * 3;
	if (image_size > PPM_LIMIT)
	{
		warning_msg("%s: Image resolution is too large.\n", filename);
		goto error_end;
	}

	image->xsize = x_size;
	image->ysize = y_size;

	
	image->data = malloc(image_size);
	if (image->data == NULL)
	{
		warning_msg("%s: Unable to allocate memory.\n", filename);
		goto error_end;
	}

	for (unsigned i = 0; i < image_size; i++)
	{
		if (!fscanf(ppm_file, "%c", &image->data[i]))
		{
			warning_msg("%s: Error occured while reading RGB bytes.\n", filename);
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