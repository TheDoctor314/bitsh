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
        puts(cmd->progName);
        for(int i = 0; ; i++)
        {
            if(cmd->args[i] == NULL)
                break;

            puts(cmd->args[i]);
        }

        free(line);
        freeCommandStruct(cmd);
    }
    return 0;
}
