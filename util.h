#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *progName;
    char *args[];
} Command;

Command* parseCommand(char *line);
void freeCommandStruct(Command *cmd);


/*debug functions only*/
void printCommandStruct(Command *cmd);
