#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
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
