#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "linenoise.h"
#include "util.h"
#include "builtins.h"

#define PROG_NAME "bitsh"

/*null-terminated list of supported builtins*/
static char *builtins[] = {"cd", NULL};

int runifBuiltin(Command *cmd);

int main(int argc, char *argv[])
{
    char *line = NULL;

    while( (line = linenoise("bitsh> ")) != NULL)
    {
        linenoiseHistoryAdd(line);

        Command *cmd = parseCommand(line);

        int ret = runifBuiltin(cmd);
        if(ret == 0)
            continue;

        pid_t child_pid = fork();
        if(child_pid < 0)
        {
            perror("fork()");
            return 1;
        }
        else if(child_pid == 0)
        {
            //in child
            if( execvp(cmd->progName, cmd->args) < 0) //returns only if something failed
                perror("execvp()");

            return 0;
        }

        int child_status = 0;
        pid_t wpid = waitpid(child_pid, &child_status, 0);

        if(wpid == -1)
        {
            perror("waitpid()");
            return 1;
        }

        free(line);
        freeCommandStruct(cmd);
    }
    return 0;
}

int runifBuiltin(Command *cmd)
{
    static builtinFunc builtinHandler[] = 
    {
        &builtin_cd,
        NULL
    };

    if(cmd->progName == NULL)
        return -1;

    for(int i = 0; ; i++)
    {
        if(builtins[i] == NULL)
            break;

        if(strcmp(cmd->progName, builtins[i]) == 0)
        {
            //add error checking later
            (*builtinHandler[i])(cmd);
            return 0;
        }
    }

    /*if we reach this point then not a builtin*/
    return -1;
}
