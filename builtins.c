#include "builtins.h"

int builtin_cd(Command *cmd)
{
    puts("cd working");
    return 0;
}

int builtin_echo(Command *cmd)
{
    puts("echo working");
    return 0;
}
