#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, ap);

	va_end(ap);
}

void error_exit(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, ap);

	va_end(ap);
	exit(1);
}