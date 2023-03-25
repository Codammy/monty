#include "monty.h"

/**
 * main - controls all other functions
 *
 * @argc: number of parameters passed at run time.
 * @argv: arrays of string containg containg parameter
 * Return: Success.
 */
int cmp(char *s, char **st)
{
        int i = 0;

        while (st[i])
        {
                if (!(strcmp(st[i], s)))
                        return (1);
                i++;
        }
        return (0);
}
int main(int argc, char **argv)
{
	char *buf, *lineN, *opcode[] = {
	"push",
	"pall"
	};
	FILE *f;
	int i = 0, j = 0, ln = 1;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!(f = fopen(argv[1], "r")))
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (!feof(f))
	{
		fgetc(f);
		i++;
	}
	fclose(f);
	buf = malloc((sizeof(int) * i));
	if (!buf)
	{
		dprintf(1, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	while (!feof(f))
		buf[j++] = fgetc(f);
	lineN = strtok(buf, "\n");
	while (lineN)
	{
		op(lineN, opcode, &ln, cmp);
		lineN = strtok(NULL, "\n");
	}
	free(buf);
	fclose(f);

	return (0);
}
