#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1023

int main(int argc, char **argv)
{
	int lines_count = 10;
	FILE *file;
	bool file_opened = false;
	bool line_count_changed = false;

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

	char **lines = malloc(lines_count * sizeof(char *));
	if (lines == NULL)
	{
		error_lstruct:
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		if (file_opened)
			fclose(file);
		return 1;
	}
	for (size_t i = 0; i < lines_count; i++)
		if ((lines[i] = malloc(MAX_LINE_LENGTH)) == NULL)
		{
			for (size_t j = 0; j <= i; j++)
				free(lines[j]);
			free(lines);
			goto error_lstruct;
		}
	
	char line[MAX_LINE_LENGTH];
	for (size_t i = 0; fgets(line, MAX_LINE_LENGTH, file_opened ? file : stdin); i++)
	{
		if (i < lines_count)
			strcpy(lines[i], line);
		else
		{
			for (size_t j = 0; j < lines_count - 1; j++)
				strcpy(lines[j], lines[j + 1]);
			strcpy(lines[lines_count - 1], line);
		}
	}

	if (file_opened)
		fclose(file);
	for (size_t i = 0; i < lines_count; i++)
	{
		printf("%s", lines[i]);
		free(lines[i]);
	}
	free(lines);
	return 0;
}