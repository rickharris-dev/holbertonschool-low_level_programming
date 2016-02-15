#include "my_functions.h"

void print_combination_4(void)
{
  int a,b,c;                      /* Variable declaration */

  for (a=0, b=1; a<100; a++, b++) /* For loop to find 1st number */
    for(c=b; c<100; c++)          /* For loop to find 2nd number */
      {
	if(a+c!=1)                /* If sum of a,c is not 1 */
	  {
	    print_char(',');      /* Prints a comma */
	    print_char(' ');      /* Prints a space */
	  }
	if(a<10)                  /* Determines if a less than 10 */
	  print_number(0);        /* Prints a zero */
	print_number(a);          /* Prints the 1st number */
	print_char(' ');          /* Prints a space */
	if(c<10)                  /* If 2nd number less than 10 */
	  print_number(0);        /* Prints a zero */
	print_number(c);          /* Prints the second number */
      }
}
