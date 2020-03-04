// error.c
// Řešení IJC-DU1, příklad b), 3.3.2020
// Autor: Tomáš Milostný, xmilos02, FIT VUT
// Přeloženo: gcc 7.4
// ...popis příkladu - poznámky, omezení, atd

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...)
{
	va_list parameters;
	va_start(parameters, fmt);

	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, parameters);

	va_end(parameters);
}

void error_exit(const char *fmt, ...)
{
	va_list parameters;
	va_start(parameters, fmt);

	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, parameters);

	va_end(parameters);
	exit(1);
}