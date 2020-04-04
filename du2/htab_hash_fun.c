#pragma once

#include "htab.h"
#include <stdint.h>

size_t htab_hash_fun(htab_key_t str)
{
	uint32_t hash = 0;
	const unsigned char *p;

	for (p = (const unsigned char *)str; *p != '\0'; p++)
		hash = 65599 * hash + *p;
	
	return hash;
}