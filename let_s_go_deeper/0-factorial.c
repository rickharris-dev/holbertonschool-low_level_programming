#include <limits.h>

int factorial(int n)
{
  int total;
  long test;

  if (n < 0)
    return -1;
  else if (n == 0)
    return 1;

  for (total = 1, test = 1; n > 0; n--)
  {
    test *= n;
    if (test > INT_MAX)
      return -1;
    total = test;
  }

  return total;
}
