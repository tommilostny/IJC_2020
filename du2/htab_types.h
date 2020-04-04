#include "htab.h"

struct htab
{
	size_t size;
	size_t arr_size;
	struct htab_item **ptr;
};

struct htab_item
{
	htab_key_t key;
	htab_value_t data;
	struct htab_item *next;
};