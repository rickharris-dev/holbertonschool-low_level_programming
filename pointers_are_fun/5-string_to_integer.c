#include <limits.h>

int is_num(char c, int opt)
{
  if (opt == 0)
  {
    if (c == 45)
        return (-1);
    else if (c >= 48 && c <= 57)
        return(c - 48);
    return (10);
  }
  else
      if (c >= 48 && c <= 57)
        return (1);
      return (0);
}

int string_to_integer(char *s)
{
  int i, n, r, sign;

  for (i = 0, n = 0, sign = -1; *(s + i) != '\0'; i++)
  {
    r = is_num(*(s + i), 0);
    if (r == -1 && !(is_num(*(s + i - 1), 1)))
      sign *= r;
    else if (r != 10)
      if ( n < INT_MIN / 10 || ( n == INT_MIN / 10 && n == 9))
        return (0);
      else
        n = (n * 10) - r;
    else if (is_num(*(s + i - 1), 1))
      break;
  }
  if (sign < 0 && n == INT_MIN)
    return (0);
  else
    n *= sign;

  return(n);
}
