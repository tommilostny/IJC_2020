/* 
 * error.h
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Rozhraní modulu deklarující prototypy funkcí pro výpis chybových hlášení.
 */

#ifndef ERROR_H
#define ERROR_H

//Tisk chybového hlášení ve formátu: CHYBA: [fmt] (formát fmt je formát řetězce funkce printf).
void warning_msg(const char *fmt, ...);

//Tisk chybového hlášení ve formátu: CHYBA: [fmt] (formát fmt je formát řetězce funkce printf).
//Po výpisu je program ukončen voláním funkce exit(1).
void error_exit(const char *fmt, ...);

#endif