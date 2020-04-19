/* 
 * tail.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 31.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Program tail vypisující posledních 10 řádků souboru (nebo podle nastavení s parametrem -n).
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1023

//Kontrola překročení limitu MAX_LINE_LENGTH
bool check_line(char *line)
{
	static int warning_cnt = 0;
	int len = strlen(line);

	if (len == MAX_LINE_LENGTH - 1)
	{
		line[len - 1] = '\n';
		if (warning_cnt < 1)
		{
			fprintf(stderr, "Warning: file contains a long line exceeding limit (%d characters).\n", MAX_LINE_LENGTH);
			warning_cnt++;
		}
		return false;
	}
	return true;
}

//Načítání řádků ze souboru, přeskočí prvních n řádků
void print_skip_first_lines(FILE *file, int n)
{
	char line[MAX_LINE_LENGTH];
	bool read_status = true;
	for (int i = 0; fgets(line, MAX_LINE_LENGTH, file); i++)
	{
		if (read_status)
		{
			//Kontrola řádku na překročení limitu, případně zkrácení a přeskočení dalšího čtení
			read_status = check_line(line);

			if (i >= n - 1)
				printf("%s", line);
		}
		else
			read_status = true;
	}
}

//Načítání řádků ze souboru, vypíše posledních n řádků
int print_last_lines(FILE *file, int n)
{
	//Pole řádků pro výpis
	char **lines = malloc(n * sizeof(char *));
	if (lines == NULL)
	{
		error_lstruct:
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		return 1;
	}

	//Alokace prvků pole řádků
	for (int i = 0; i < n; i++)
	{
		if ((lines[i] = malloc(MAX_LINE_LENGTH)) == NULL)
		{
			//Chyba alokace
			for (int j = 0; j <= i; j++)
				free(lines[j]);
			free(lines);
			goto error_lstruct;
		}
	}

	//Načítání řádků ze souboru/stdin
	char line[MAX_LINE_LENGTH];
	bool read_status = true;
	for (int i = 0; fgets(line, MAX_LINE_LENGTH, file); i++)
	{
		if (read_status)
		{
			//Kontrola řádku na překročení limitu, případně zkrácení a přeskočení dalšího čtení
			read_status = check_line(line);

			//Prvních n řádků
			if (i < n)
				strcpy(lines[i], line);
			else
			{
				//Posun prvků pole, smazání nejstaršího řádku
				for (int j = 0; j < n - 1; j++)
					strcpy(lines[j], lines[j + 1]);

				//Načtení řádku na poslední pozici v poli
				strcpy(lines[n - 1], line);
			}
		}
		else
			read_status = true;
	}
	
	//Výpis a dealokace načtených řádků
	for (int i = 0; i < n; i++)
	{
		printf("%s", lines[i]);
		free(lines[i]);
	}
	free(lines);
	return 0;
}

int main(int argc, char **argv)
{
	//Výchozí nastavení
	int lines_count = 10;
	FILE *file = stdin;
	bool file_opened = false;
	bool line_count_changed = false;
	bool skip_first_mode = false;

	//Načítání argumentů
	for (int i = 1; i < argc; i++)
	{
		//Přepínač -n, není nastaven
		if (!line_count_changed && strcmp(argv[i], "-n") == 0)
		{
			//-n je poslední argument, chybí číslo
			if (++i == argc)
				goto error_arg;

			//+ u čísla - přeskočí první řádky a vypíše zbytek
			if (argv[i][0] == '+')
				skip_first_mode = true;

			//Načtení nastavení počtu řádků
			char *endptr;
			errno = 0;
			lines_count = strtol(argv[i], &endptr, 10);

			//Chyba od strtol/záporné číslo
			if (errno != 0 || *endptr != '\0' || lines_count <= 0)
				goto error_arg;

			line_count_changed = true;
		}
		//Otevření nového souboru
		else if (!file_opened && (file = fopen(argv[i], "r")) != NULL)
			file_opened = true;
		else
		{
			error_arg:
			fprintf(stderr, "Error: %s: invalid argument\n", argv[i]);
			if (file_opened)
				fclose(file);
			return 1;
		}
	}

	//+ u čísla (argument -n) - přeskočí první řádky a vypíše zbytek
	if (skip_first_mode)
	{
		print_skip_first_lines(file, lines_count);
	}
	else //Výpis posledních n řádků souboru/stdin
	{
		print_last_lines(file, lines_count);
	}

	if (file_opened)
		fclose(file);
	return 0;
}