#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "linenoise.h"
#include "util.h"

int main(int argc, char *argv[])
{
    char *line = NULL;

    while( (line = linenoise("bitsh> ")) != NULL)
    {
        puts(line);

        Command *cmd = parseCommand(line);

        if( execvp(cmd->progName, cmd->args) < 0) //returns only if something failed
            perror("execvp()");

        puts("This should be unreachable");

        free(line);
        freeCommandStruct(cmd);
    }
    return 0;
}
