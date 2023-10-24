#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - main source file
 *
 * @ac: no. of commamd line passed
 * @av: cmd line args
 * Return: 0 on Sucess
 */
int main(int ac, char **av)
{
	FILE *file;
	size_t n = 0, line = 1, i;
	char *buffer = NULL, *tmp, *instruction[2];

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (getline(&buffer, &n, file) == -1)
		{
			if (feof(file) == 1)
				break;
			dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
			exit(EXIT_FAILURE);
		}
		fflush(file);
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
		printf("%s %s\n", instruction[0], instruction[1]);
		free(instruction[0]);
		free(instruction[1]);
		}
	}
	/*if (strcmp(instruction, "push") == 0)
		push(atoi(instruction[1]));
	if (strcmp(instruction, "push") == 0)
		pall();
	if (strcmp(instruction, "push") == 0)
		pint();
	if (strcmp(instruction, "push") == 0)
		pop();
	if (strcmp(instruction, "push") == 0)
		swap();
	if (strcmp(instruction, "push") == 0)
		add();
	if (strcmp(instruction, "push") == 0)
		nop();*/
	fclose(file);
	return (0);
}