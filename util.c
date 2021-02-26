#include "util.h"

#define MAX_LEN 256

Command* parseCommand(char *line)
{
    char *copy = strdup(line);
    if(copy == NULL)
    {
        perror("parseCommand() --> strdup()");
        return NULL;
    }

    char *token = NULL, *save_ptr = NULL, *str = copy;

    /*instead of appending and allocating multiple times,
     * we just declare a big ass array
     *
     * using calloc, we get zero initialized chunk, which is needed
     * for call to execvp()
     */
    Command* cmd = calloc(sizeof(Command) + MAX_LEN * sizeof(char *), 1);
    if(cmd == NULL)
    {
        perror("parseCommand() --> calloc()");
    }

    for(int i = 0; ; i++, str = NULL)
    {
        token = strtok_r(str, " ", &save_ptr);
        if(token == NULL)
        {
            //no more tokens
            break;
        }

        char *token_copy = strdup(token);
        if(token_copy == NULL)
        {
            perror("parseCommand() --> strdup()");
            return NULL;
        }

        cmd->args[i] = token_copy;
    }
    free(copy);

    cmd->progName = cmd->args[0];

    return cmd;
}
