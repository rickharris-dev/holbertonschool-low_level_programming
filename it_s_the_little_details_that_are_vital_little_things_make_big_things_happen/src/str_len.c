#include "../inc/holbertonschool.h"

int str_len(char *s)
{
  int i;
  /* Sets loop to find length of string */
  for(i = 0; *(s + i) > 0; i++){}
  /* Returns length of string */
  return (i);
}
