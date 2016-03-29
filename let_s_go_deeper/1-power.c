#include <limits.h>

int power(int x, int y)
{
  long test = x;
  test = test * x;
  if (x < 0 || y < 0 )
    return -1;
  else if (y == 0)
    return 1;
  else if (test > INT_MAX)
    return -1;

  return x * power(x, y - 1);
}
