#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "linenoise.h"

int main(int argc, char *argv[])
{
    char *line = NULL;

    while( (line = linenoise("bitsh> ")) != NULL)
    {
        puts(line);

        /*let's break the line into tokens using strtok_r()
         * and print them as a list
         */
        char *str = line, *token = NULL, *save_ptr = NULL;

        for(int i = 0; ; i++, str = NULL)
        {
            token = strtok_r(str, " ", &save_ptr);
            if(token == NULL)
            {
                //no more tokens
                break;
            }
            printf("%d. %s\n", i+1, token);
        }

        free(line);
    }
    return 0;
}
