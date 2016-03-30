#include <limits.h>

int factorial(int n)
{
  long test = n;                /* Sets test == n */
  test = test * (n - 1);        /* Sets test value */
  if (n < 0)                    
    return -1;                  /* Returns -1 if value is negative */
  else if (n == 0)
    return 1;                   /* Returns 1 if a factorial of 0 */
  else if (test > INT_MAX)
    return -1;                  /* If test is greater than INT_MAX returns 0 */
  return n * factorial(n - 1);  /* Uses recursion to continue factorial */
}
