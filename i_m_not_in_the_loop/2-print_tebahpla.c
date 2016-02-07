#include "my_functions.h"

void print_tebahpla(void)
{
  /* Declares the variable i will be an integer */
  int i;

  /* Sets for loop to reverse cycle through ASCII character values */
  for (i = 122; i > 96; i--)
    {
      /* Calls print function to print the current ASCII character */
      print_char(i);
    }
}
