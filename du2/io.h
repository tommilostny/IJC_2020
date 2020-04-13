/* 
 * io.h
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 13.4.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Modul čtení slova ze standardního vstupu.
 */

#pragma once

#include <stdio.h>
#include <ctype.h>

#define LONG_WORD_ERROR -2

/*
 * Čte jedno slovo ze souboru f do zadaného pole znaků
 * a vrátí délku slova (z delších slov načte prvních max-1 znaků,
 * a zbytek přeskočí). Funkce vrací EOF, pokud je konec souboru.
 * Poznámka: Slovo je souvislá posloupnost znaků oddělená isspace znaky.
 */
int get_word(char *s, int max, FILE *f);