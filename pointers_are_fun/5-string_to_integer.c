#include <stdio.h>
#include <limits.h>

int str_len(char *s)
{
  int i;

  for(i = 0; *(s + i) > 0; i++){}

  return (i);
}

int get_sign(char *s, int first)
{
  int i, sign;

  for(i = 0, sign = -1; i < first; i++)
    if (*(s + i) == 45)
      sign *= -1;
  return (sign);

}

int find_first_number(char *s, int len)
{
  int i;

  for (i = 0; i < len; i++)
    if (48 <= *(s + i) && *(s + i) <= 57)
      return (i);
  return (i);
}

int find_last_number(char *s, int len, int first)
{
  for (; first < len; first++)
    if (48 > *(s + first) || *(s + first) > 57)
      return(first);
  return(first);
}

int string_to_integer(char *s)
{
  int i, n, len, first, last, sign;
  /* Get the length of the string */
  len = str_len(s);
  first = find_first_number(s, len);
  last = find_last_number(s, len, first);
  sign = get_sign(s, first);

  /* Start for loop to cycle through string */
  for (i = first, n = 0; i <= last; i++)
  {
    if(48 <= *(s + i) && *(s + i) <= 57)
    {
      if ((n * 10) - (*(s + i) - 48) == 0 || (n < (INT_MIN / 10)) || ((n == (INT_MIN / 10)) && *(s + i) == 9))
        return (0);
      else
        n = (n * 10) - (*(s + i) - 48);
    }
  }
    if (n == INT_MIN && sign == -1)
      return (0);
    else
      n *= sign;
  return(n);
}
