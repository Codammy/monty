#include "main.h"

/**
 * _getline - reads line from stream and tokenizes string
 *
 * @stream: Stream to read from
 */
void _getline(FILE *file, char **instruction)
{
	char *buffer = NULL, *tmp;
	size_t s = 0, i = 0;

	if (getline(&buffer, &s, file) == -1)
	{
		free(buffer);
		if (feof(file) == 1)
			exit(EXIT_SUCCESS);
	}

	if (strtok(buffer, "\n"))
	{
		tmp = strtok(buffer, " ");
		i = 0;
		while (tmp)
		{
			instruction[i] = strdup(tmp);
			tmp = strtok(NULL, " ");
			i++;
		}
	}
	free(buffer);
}
