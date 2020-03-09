/* 
 * error.h
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc 7.4
 * Popis: Rozhraní modulu deklarující prototypy funkcí pro výpis chybových hlášení.
 */

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#endif