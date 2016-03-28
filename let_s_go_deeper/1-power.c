#include <limits.h>

int power(int x, int y)
{
  int n, total;
  long test;

  if (x < 0 || y < 0 )
    return -1;
  else if (x == 0)
    return 0;
  else if (y == 0)
    return 1;

  for (n = 0, test = 1; n < y; n++)
  {
    test = test * x;
    if (test > INT_MAX)
      return -1;
    total = test;
  }

  return total;
}
