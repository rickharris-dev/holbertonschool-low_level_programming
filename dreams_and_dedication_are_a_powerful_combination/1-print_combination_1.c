#include "my_functions.h"

void print_combination_1(void) 
{
  int i;                   /* Declares the int i will be used */

  for (i=0; i<10; i++)     /* For look to continue until i=10 */
    {
      if (i != 0)          /* Determines if i is not 0 */
	{
	  print_char(','); /* Prints a comma */
	  print_char(' '); /* Prints a space */
	}
      print_number(i);     /* Prints the value of i */
    }
}
