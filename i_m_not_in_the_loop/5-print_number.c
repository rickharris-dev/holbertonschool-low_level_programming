#include "my_functions.h"

int calc_length(int n);              /* Function prototype */
void parse_print(int n, int l);      /* Function prototype */

int calc_length(int n)               /* Function to get length of n */
{
  int l;                             /* Variable declaration */

  for (l = 0; n>=1; l++)             /* Determine length of number */ 
  {
    n = n / 10;                      /* Divides n by 10 until < 0 */
  }

  return l;                          /* Returns the length of the number */
}

void parse_print(int n, int l)       /* Function to print each digit in n */
{
  while (l > 0)                      /* Loop for the length of n */
  {
    int c,d,i;                       /* Variable declaration. */
    char b;                          /* Variable declaration. */

    for (i = 1, c = 1; l > i; i++)   /* Loop to create divisor */
      {
        c = c * 10;                  /* Multiplies by 10 to create divisor */
      }

    d = (n - (n % c)) / c;           /* Sets d as first digit in n */
    n = n - (d * c);                 /* Removes first digit in n */
    b = '0' + d;                     /* Converts from int to char */
    print_char(b);                   /* Sends number to be printed */
    l--;                             /* Reduces length by one  */
  }  
}

void print_number(int n)             /* Starts print process */
{
  int l;                             /* Variable declaration. */

  if (n == 0)                        /* Determines if the n is 0 */
    {
      print_char('0');               /* Prints 0 */
    }
  else if (n < 0)                    /* Determines if n is negative */
    {
      print_char('-');               /* Prints - symbol */
      n = n * -1;                    /* Converts n to absolute value */
    }              

  l = calc_length(n);                /* Stores length of number as l */
  parse_print(n,l);                  /* Inititates the print function */
}
