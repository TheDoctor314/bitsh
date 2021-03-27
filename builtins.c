#include "builtins.h"

/* Currently our cd implementation does not
 * resolve '~' as HOME directory and takes no arguments.
 * It is the most basic of implementations.*/
int builtin_cd(Command *cmd)
{
    if(chdir(cmd->args[1]) < 0)
    {
        perror("chdir()");
        return -1;
    }

    return 0;
}
