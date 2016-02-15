#include "my_functions.h"

void print_combination_3(void)
{
  int a,b,c,d,e,f;                         /* Variable declaration */

  for (a=0, b=1, c=2; a<10; a++, b++, c++) /* For loop to find 1st digit */
    for(d=b, e=c; d<10; d++, e++)          /* For loop to find 2nd digit */
      for(f=e; f<10; f++)                  /* For loop to find 3rd digit */
	{
	  if(a+d+f!=3)                     /* If sum of a,d,f is not 3 */
	    {
	      print_char(',');             /* Prints a comma */
	      print_char(' ');             /* Prints a space */
	    }
	  print_number(a);                 /* Prints the 1st digit */
	  print_number(d);                 /* Prints the 2nd digit */
	  print_number(f);                 /* Prints the 3rd digit */
	}
}
