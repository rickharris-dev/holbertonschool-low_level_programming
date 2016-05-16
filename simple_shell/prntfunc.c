#include "hdr.h"

int print_char(char c)
/* Prints char to standard output */
{
        return (write(1, &c, 1));
}

void write_string(char *str)
/* Sends each char in string to be printed */
{
        int i;
        for (i = 0; str[i] != '\0'; i++)
                print_char(str[i]);
}
