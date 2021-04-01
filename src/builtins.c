#include "builtins.h"

/* Currently our cd implementation does not
 * resolve '~' as HOME directory and takes no arguments.
 * It is the most basic of implementations.*/
int builtin_cd(Command *cmd)
{
    if(chdir(cmd->argv[1]) < 0)
    {
        perror("chdir()");
        return -1;
    }

    return 0;
}

int builtin_exit(Command *cmd)
{
    if( arglen(cmd->argv) > 2)
    {
        fputs("exit: Too many arguments\n", stderr);
        return 0;
    }

    int rc = 0;
    if(cmd->argv[1] != NULL)
    {
        char *p_end;
        rc = strtol(cmd->argv[1], &p_end, 10);
    }

    freeCommandStruct(cmd);

    exit(rc);
}
