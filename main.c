#include "main.h"

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
	size_t line = 1;
	char *instruction[2];

	verify_cmdline_arg(ac);
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		instruction[0] = NULL;
		instruction[1] = NULL;
		_getline(file, instruction);
		verify_instruction(instruction, line);
		line++;
	}
	fclose(file);
	return (0);
}
