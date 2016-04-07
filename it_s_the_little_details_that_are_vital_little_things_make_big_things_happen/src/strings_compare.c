#include "../inc/holbertonschool.h"

int strings_compare(char *s1, const char *s2)
{
  int i;
  /* Compares each char of the string until null terminator */
  for (i = 0; *(s1 + i) == *(s2 + i) && *(s1 + i) != '\0'; i++);
  /* Returns the value of the diff that broke the loop. */
  return *(s1 + i) - *(s2 + i);

}
