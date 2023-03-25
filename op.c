#include "monty.h"

void op(char *line, char **opc, int*ln, int (*cp)(char *, char **))
{
        char *cpy, **tmp;

        cpy = malloc(strlen(line) * sizeof(int));
        strcpy(cpy, line);
        tmp = malloc(sizeof(char *) * 2);
        tmp[0] = strtok(cpy, " ");
        tmp[1] = strtok(NULL, " ");
        if (!(cp(tmp[0], opc)))
        {
                dprintf(2, "L%d: unknown instruction %s\n", *ln, tmp[0]);
                exit(EXIT_FAILURE);
        }
        printf("%s %s\n", tmp[0], tmp[1]);
        *ln++;
}
