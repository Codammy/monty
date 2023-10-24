#include "main.h"

/**
 * verify_cmdline_arg - Checks if cmdline args meets requirement
 *
 * @n: number of args
 */
void verify_cmdline_arg(int n)
{
	if (n != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * verify_instruction - Checks for correct instruction
 *
 * @instruction: opcode instruction
 */
void verify_instruction(char **instruction, size_t line)
{
	char *buffer = instruction[0];
	if (strcmp(buffer, "push") == 0)
			push(atoi(instruction[1]));
	else if (strcmp(buffer, "pall") == 0)
		pall();
	else if (strcmp(buffer, "pint") == 0)
		pint();
	else if (strcmp(buffer, "pop") == 0)
		pop();
	else if (strcmp(buffer, "swap") == 0)
		swap();
	else if (strcmp(buffer, "add") == 0)
		add();
	else if (strcmp(buffer, "nop") == 0)
		nop();
	else
	{
		dprintf(STDERR_FILENO, "L%lu: unknown instruction %s\n", line, buffer);
		exit(EXIT_FAILURE);
	}
}
