#include "monty.h"

int _cmp(char *s, char **st)
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
