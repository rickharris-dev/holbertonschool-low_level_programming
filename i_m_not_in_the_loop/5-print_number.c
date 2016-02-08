#include "my_functions.h"

int calc_length(int n);               /* Function prototype */
void parse_print(int n, int l, int f);/* Function prototype */

int calc_length(int n)                /* Function to get length of n */
{
  int l;                              /* Variable declaration */

  for (l = 0; n>=1; l++)              /* Determine length of number */ 
  {
    n = n / 10;                       /* Divides n by 10 until < 0 */
  }

  return l;                           /* Returns the length of the number */
}

void parse_print(int n, int l, int f) /* Function to print each digit in n */
{
  while (l > 0)                       /* Loop for the length of n */
  {
    int c,d,i;                        /* Variable declaration. */
    char b;                           /* Variable declaration. */

    for (i = 1, c = 1; l > i; i++)    /* Loop to create divisor */
      {
        c = c * 10;                   /* Multiplies by 10 to create divisor */
      }
    if (l == 1)                       /* Determines if final digit */
      {
	n = n + f;                    /* Adds f =  0 if pos 1 if neg */
      }
    d = (n - (n % c)) / c;            /* Sets d as first digit in n */
    n = n - (d * c);                  /* Removes first digit in n */
    b = '0' + d;                      /* Converts from int to char */
    print_char(b);                    /* Sends number to be printed */
    l--;                              /* Reduces length by one  */
  }  
}

void print_number(int n)              /* Starts print process */
{
  int l,f;                            /* Variable declaration. */

  f = 0;                              /* Sets f = 0 */

  if (n == 0)                         /* Determines if the n is 0 */
    {
      print_char('0');                /* Prints 0 */
    }
  else if (n < 0)                     /* Determines if n is negative */
    {
      print_char('-');                /* Prints - symbol */
      n = (n + 1) * -1;               /* Converts n to absolute value */
      f = 1;                          /* Sets f as 1 if negative */
    }              

  l = calc_length(n);                 /* Stores length of number as l */
  parse_print(n,l,f);                 /* Inititates the print function */
}
