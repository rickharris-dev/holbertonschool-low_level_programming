#include <limits.h>

int total = 1;

int factorial(int n)
{
  long test;

  if (n < 0)
    return -1;
  else if (n == 0) {
    n = total;
    total = 1;
    return n;
  }
  else {
    test = total * n;
    if (test > INT_MAX)
      return -1;
    total = test;
    return factorial(n - 1);
  }
  return -1;
}
