// error.h
// Řešení IJC-DU1, příklad b), 3.3.2020
// Autor: Tomáš Milostný, xmilos02, FIT VUT
// Přeloženo: gcc 7.4
// ...popis příkladu - poznámky, omezení, atd

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#include "error.c"

#endif