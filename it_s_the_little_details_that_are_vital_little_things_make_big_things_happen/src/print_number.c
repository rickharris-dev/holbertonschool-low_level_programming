#include "../inc/holbertonschool.h"

void print_number(int n)         /* Starts print process */
{
  int a,l,c,i;                   /* Variable declaration */
  char d;                        /* Variable declaration */
  if (n == 0)                    /* Determines if n is 0 */
    print_char('0');             /* Prints 0 */
  if (n < 0)                     /* Determines if n is negative */
    print_char('-');             /* Prints - symbol */
  n = (n * ((n<=0)-(n>0)));      /* Converts n to absolute value - 1 */
  for (l = 0, a = n; a<=-1; l++) /* Determine length of number */
    a /= 10;                     /* Divides n by 10 until < 0 */
  for (l = l; l > 0; l--)        /* Loop for the length of n */
    {
      for (i=1, c=-1; l>i; i++)  /* Loop to create divisor */
        c *= 10;                 /* Multiples divisor by 10 */
      d = ((n-(n%c))/c);         /* Determines the first digit */
      print_char('0' + d);       /* Sets d as first digit in n */
      n -= (d * c);              /* Removes first digit in n */
    }
}
