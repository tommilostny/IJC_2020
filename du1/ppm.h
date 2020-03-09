/* 
 * ppm.h
 * 
 * Řešení IJC-DU1, příklad b)
 * Datum vytvoření: 3.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Popis: Rozhraní pro modul ppm.c pro čtení obrázkových souborů typu PPM.
 */

#ifndef PPM_H
#define PPM_H

//Implementační limit pro max. velikost obrazových dat
#define PPM_LIMIT 8000*8000*3

//Struktura pro obrazová data souboru PPM
struct ppm
{
	unsigned xsize;
	unsigned ysize;
	unsigned char *data; //RGB 3*xsize*ysize
};

/*
 * Načte obsah PPM souboru do touto funkcí dynamicky alokované struktury.
 * Při chybě formátu použije funkci warning_msg a vrátí NULL.
 */
struct ppm *ppm_read(const char *filename);

/*
 * Uvolní paměť dynamicky alokované struktury vytvořené ppm_read
 */
void ppm_free(struct ppm *p);

#endif