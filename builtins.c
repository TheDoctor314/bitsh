#include "builtins.h"

int builtin_cd(Command *cmd)
{
    if(chdir(cmd->args[1]) < 0)
    {
        perror("chdir()");
        return -1;
    }

    return 0;
}
