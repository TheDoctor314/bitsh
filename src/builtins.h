#ifndef BUILTINS_H
#define BUILTINS_H

#include "util.h"

int builtin_cd(Command *cmd);
int builtin_exit(Command *cmd);

typedef int (*builtinFunc)(Command *);

#endif
