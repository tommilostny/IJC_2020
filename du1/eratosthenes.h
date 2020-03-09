/* 
 * eratosthenes.h
 * 
 * Řešení IJC-DU1, příklad a)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Implementace algoritmu Eratosthenovo síto pro vyhledávání prvočísel.
 */

#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

#include "bitset.h"

//Eratosthenovo síto (přibližná specifikace):
//   1) Nulujeme bitové pole  p  o rozměru N,
//      p[0]=1; p[1]=1; // 0 a 1 nejsou prvočísla
//      index i nastavit na 2
//   2) Vybereme nejmenší index i, takový, že p[i]==0.
//      Potom je i prvočíslo
//   3) Pro všechny násobky i nastavíme bit p[n*i] na 1
//      ('vyškrtneme' násobky - nejsou to prvočísla)
//   4) i++; dokud nejsme za sqrt(N), opakujeme bod 2 až 4
//      (POZOR: sestavit s matematickou knihovnou parametrem -lm)
//   5) Výsledek: v poli p jsou na prvočíselných indexech hodnoty 0
void Eratosthenes(bitset_t pole);

#endif