#include <stdio.h>
#include <stdlib.h>

#include "linenoise.h"

int main(int argc, char *argv[])
{
    char *line = NULL;

    while( (line = linenoise("bitsh> ")) != NULL)
    {
        puts(line);
        free(line);
    }
    return 0;
}
