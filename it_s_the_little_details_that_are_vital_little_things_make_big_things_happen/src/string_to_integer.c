#include <limits.h>
#include "../inc/holbertonschool.h"

int is_num(char c, int opt)
{
  if (opt == 0) /* Option for value */
  {
    if (c == 45)
        return (-1); /* If '-' returns -1 */
    else if (c >= 48 && c <= 57)
        return(c - 48); /* If int returns value */
    return (10); /* Returns 10 otherwise */
  }
  else /* Options for boolean */
      if (c >= 48 && c <= 57)
        return (1); /* If int returns true */
      return (0);
}

int string_to_integer(char *s)
{
  int i, n, r, sign;
  for (i = 0, n = 0, sign = -1; *(s + i) != '\0'; i++)
  {
    r = is_num(*(s + i), 0); /* Determines val of r */
    if (r == -1 && !(is_num(*(s + i - 1), 1)))
      sign *= r; /* Changes sign if '-' */
    else if (r != 10) /* If int */
      if ( n < INT_MIN / 10 || ( n == INT_MIN / 10 && n == 9))
        return (0); /* Returns if larger/smaller than int max/min */
      else
        n = (n * 10) - r; /* Adds value to n */
    else if (is_num(*(s + i - 1), 1))
      break; /* If not an int breaks loop */
  }
  if (sign < 0 && n == INT_MIN)
    return (0); /* If n > INT_MAX returns 0 */
  else
    n *= sign; /* Sets n to proper sign */
  return(n); /* Returns n */
}
