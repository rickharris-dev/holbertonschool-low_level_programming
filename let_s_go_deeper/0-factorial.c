#include <limits.h>

int factorial(int n)
{
  long test = n;
  test = test * (n - 1);
  if (n < 0)
    return -1;
  else if (n == 0)
    return 1;
  else if (test > INT_MAX)
    return -1;
  return n * factorial(n - 1);
}
