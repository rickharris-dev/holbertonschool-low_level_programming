#include <limits.h>

int total = 1;

int power(int x, int y)
{
  long test;

  if (x < 0 || y < 0 )
    return -1;
  else if (y == 0)
  {
    x = total;
    total = 1;
    return x;
  }
  else {
    test = total * x;
    if (test > INT_MAX)
      return -1;
    total = test;
    return power(x, y - 1);
  }

  return -1;
}
