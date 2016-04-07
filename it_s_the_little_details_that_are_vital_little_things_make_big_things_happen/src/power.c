#include <limits.h>
#include "../inc/holbertonschool.h"

int power(int x, int y)
{
  long test = x;
  test = test * x;            /* Sets the test value */
  if (x < 0 || y < 0 )
    return -1;                /* Returns -1 if x or y is negative */
  else if (y == 0)
    return 1;                 /* Returns 1 if power is 0 */
  else if (test > INT_MAX)
    return -1;                /* Returns -1 if test is > INT_MAX */

  return x * power(x, y - 1); /* Continues recursion if y > 0 */
}
