/* 
 * error.c
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Modul definující funkce pro výpis chybových hlášení.
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

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