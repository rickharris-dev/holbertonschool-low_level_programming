#include <stdio.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
  int i, j, c;
  char a, b, n;
  n = 48;
  for (i = 0; *(n1 + i + 1) != '\0'; i++);
  for (j = 0; *(n2 + j + 1) != '\0'; j++);
  *(r + 99) = '\0';
  for (c = size_r - 2; (i >= 0 || j >= 0 || n != 48) && c >= 0; c--, j--, i--)
  {
    a = *(n1 + i);
    b = *(n2 + j);
    if (i < 0)
      a = 48;
    if (j < 0)
      b = 48;
    *(r + c) = a + b + n - 96;
    n = 48;
    if (*(r + c) > 57)
    {
      n = 49;
      *(r + c) -= 10;
    }
  }
  if (c < 0 && (i >= 0 || j >= 0 || n != 48))
    return 0;
  else if (c >= 0)
      for (i = 0; c < size_r; i++, c++)
        *(r + i) = *(r + c + 1);
  return r;
}
