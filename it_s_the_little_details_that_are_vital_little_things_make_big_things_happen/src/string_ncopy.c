#include "../inc/holbertonschool.h"

char *string_ncopy(char *dest, const char *src, int n)
{
  int i,j,s;

  /* Finds the length of the dest */
  for (i = 0; *(src + i) != '\0'; i++);

  if (i + 1 < n) /* Determines the stop point to the shortest of src or n */
    s = i + 1;
  else
    s = n;

  /* Store source string into dest including '\0' */
  for (j = 0; j < s; j++)
    *(dest + j) = *(src + j);

  for (; j < n; j++)
    *(dest + j) = 00;

  /* Return address of the dest string */
  return dest;
}
