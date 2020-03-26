#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1023

int main(int argc, char **argv)
{
	int line_count = 10;
	FILE *file;
	bool file_opened = false;
	bool line_count_changed = false;

	for (int i = 1; i < argc; i++)
	{
		if (!line_count_changed && strcmp(argv[i], "-n") == 0)
		{
			if (i == argc - 1)
				goto error_end;

			char *endptr;
			errno = 0;
			line_count = strtol(argv[++i], &endptr, 10);

			if (errno != 0 || *endptr != '\0' || line_count <= 0)
				goto error_end;

			line_count_changed = true;
		}
		else if (!file_opened && (file = fopen(argv[i], "r")) != NULL)
			file_opened = true;
		else
		{
			error_end:
			fprintf(stderr, "Error: %s: invalid argument\n", argv[i]);
			if (file_opened)
				fclose(file);
			return 1;
		}
	}

	char **lines = malloc(line_count * sizeof(char *));
	if (lines == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory.\n");
		if (file_opened)
			fclose(file);
		return 1;
	}
	
	char line[MAX_LINE_LENGTH];
	for (size_t i = 0; fgets(line, MAX_LINE_LENGTH, file_opened ? file : stdin) ; i++)
	{
		if (i >= MAX_LINE_LENGTH)
			break;

		strcpy(lines[i], line);
		printf("%s", lines[i]);
	}

	if (file_opened)
		fclose(file);
	free(lines);
	return 0;
}