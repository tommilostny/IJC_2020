/* 
 * tail.c
 * 
 * Řešení IJC-DU2, příklad 2)
 * Datum vytvoření: 31.3.2020
 * Autor: Tomáš Milostný, xmilos02, FIT VUT
 * Překladač:  gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 * Popis: Program tail vypisující posledních 10 řádků souboru (nebo podle nastavení s parametrem -n).
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1023

int main(int argc, char **argv)
{
	int lines_count = 10;
	FILE *file = stdin;
	bool file_opened = false;
	bool line_count_changed = false;

	//first load program arguments
	for (int i = 1; i < argc; i++)
	{
		if (!line_count_changed && strcmp(argv[i], "-n") == 0)
		{
			if (i == argc - 1)
				goto error_arg;

			char *endptr;
			errno = 0;
			lines_count = strtol(argv[++i], &endptr, 10);

			if (errno != 0 || *endptr != '\0' || lines_count <= 0)
				goto error_arg;

			line_count_changed = true;
		}
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

	//allocate output lines count number of string array members
	char **lines = malloc(lines_count * sizeof(char *));
	if (lines == NULL)
	{
		error_lstruct:
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		if (file_opened)
			fclose(file);
		return 1;
	}

	//allocate all strings in lines array
	for (int i = 0; i < lines_count; i++)
		if ((lines[i] = malloc(MAX_LINE_LENGTH)) == NULL)
		{
			for (int j = 0; j <= i; j++)
				free(lines[j]);
			free(lines);
			goto error_lstruct;
		}
	
	//loading file lines - if no file is opened, use stdin
	char line[MAX_LINE_LENGTH];
	for (int i = 0; fgets(line, MAX_LINE_LENGTH, file); i++)
	{
		//fist lines count lines
		if (i < lines_count)
			strcpy(lines[i], line);
		else
		{
			//shift array members (discard first)
			for (int j = 0; j < lines_count - 1; j++)
				strcpy(lines[j], lines[j + 1]);

			//copy loaded line to the array end
			strcpy(lines[lines_count - 1], line);
		}
	}

	if (file_opened)
		fclose(file);
	for (int i = 0; i < lines_count; i++)
	{
		printf("%s", lines[i]);
		free(lines[i]);
	}
	free(lines);
	return 0;
}