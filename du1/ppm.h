#ifndef PPM
#define PPM

//Můžete omezit max. velikost obrazových dat vhodným implementačním limitem
#define PPM_LIMIT 8000*8000*3

struct ppm
{
	unsigned xsize;
	unsigned ysize;
	char *data;		//RGB 3*xsize*ysize
};

/*
 * načte obsah PPM souboru do touto funkcí dynamicky
 * alokované struktury. Při chybě formátu použije funkci warning_msg
 * a vrátí NULL.  Pozor na "memory leaks".
 */
struct ppm *ppm_read(const char *filename);

/*
 * uvolní paměť dynamicky alokovanou v ppm_read
 */
void ppm_free(struct ppm *p);

#endif