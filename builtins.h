#ifndef BUILTINS_H
#define BUILTINS_H

#include "util.h"

int builtin_cd(Command *cmd);

typedef int (*builtinFunc)(Command *);

#endif
