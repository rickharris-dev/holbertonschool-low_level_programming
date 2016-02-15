#include "my_functions.h"

void print_combination_2(void)
{
  int a,b,c;                     /* Declares variables */

  for (a=0, b=1; a<10; a++, b++) /* Runs loop until a=10 */
      for(c=b; c<10; c++)        /* Runs loop until c=10 */
	{
	  if(a+c!=1)             /* Determines if a + c is not 1 */
	    {
	      print_char(',');   /* Prints a comma */
	      print_char(' ');   /* Prints a space */
	    }
	  print_number(a);       /* Prints the first digit */
	  print_number(c);       /* Prints the second digit */
	}
}
