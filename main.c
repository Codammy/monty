#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "monty.h"

/**
 * main - controls all other functions
 *
 * @argc: number of parameters passed at run time.
 * @argv: arrays of string containg containg parameter
 */
int main(int argc, char **argv)
{

	char *buf, *tmp;
	FILE *f, *f2;
	int i = 0, j = 0, lineN = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!(f = fopen(argv[1], "r+")))
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	f2 = f;
	while (!feof(f))
	{
		fgetc(f);
		i++;
	}
	fclose(f);
	buf = malloc((sizeof(i) * i) / 4);
	if (!buf)
	{
		dprintf(1, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	while (!feof(f))
		buf[j++] = fgetc(f);
	while ((tmp = strtok(buf, "\n")))
	{
		printf("%s%d\n", tmp, i - 1);
		i++;
	}
	fclose(f);

	return (0);
}
