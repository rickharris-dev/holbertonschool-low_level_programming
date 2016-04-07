#include "../inc/holbertonschool.h"

void reverse_string(char *s)
{
    int i,j,len;
    char c;
    len = str_len(s);

    for (i = 0, j = len - 1; i < ((len - 1) / 2); i++, j--)
    {
      c = *(s + i); /* Gets initial char */
      *(s + i) = *(s + j); /* Inverts char */
      *(s + j) = c; /* Sets value to intial char */
    }
}
