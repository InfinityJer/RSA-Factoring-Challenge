#include <stdio.h>
#include <stdlib.h>
#include "factor.h"

/**
 * main - main function
 *
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *fptr;
    size_t count = 0;
    char *buffer = NULL;
    ssize_t line;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: factor <filename>\n");
        return 1;
    }

    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        return 1;
    }

    while ((line = getline(&buffer, &count, fptr)) != -1)
    {
        factorize(buffer);
    }

    free(buffer);
    fclose(fptr);

    return 0;
}
