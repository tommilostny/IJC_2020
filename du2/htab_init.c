#pragma once

#include "htab.h"
#include "htab_types.h"
#include <stdlib.h>

htab_t *htab_init(size_t n)
{
	htab_t *tab;

	tab->size = 0;
	tab->arr_size = n;
	tab->ptr = malloc(n * sizeof(struct htab_item *));

	return tab;
}