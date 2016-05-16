#include "hdr.h"

void handle_comments(char **argv)
/* Recognizes comments and updates argv */
{
        int i;
        int com;

        com = 0;
        for (i = 0; argv[i] != NULL; i++) {
                if (argv[i][0] == '#' || com) {
                        if (!com)
                                com = 1;
                        free(argv[i]);
                        argv[i] = NULL;
                }
        }
}
