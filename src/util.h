#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct
{
    int argc;
    char *argv[];
} Command;

Command* parseCommand(char *line);
void freeCommandStruct(Command *cmd);
size_t arglen(char **argv);


/*debug functions only*/
void printCommandStruct(Command *cmd);

#endif
