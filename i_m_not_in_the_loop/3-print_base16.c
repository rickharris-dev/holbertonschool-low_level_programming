#include "my_functions.h"

void print_base16(void)
{
  /* Declares the variable i will be an integer */
  int i;

  /* Sets a for loop to cycle through 0-9 ASCII values */
  for (i = 48; i < 58; i++)
    {
      /* Calls print_char function to print current value of i */
      print_char(i);
    }

  /* Sets a for look to cycle through A-F ASCII values */
  for (i = 65; i < 71; i++)
    {
      /* Calls print_char function to print current value of i */
      print_char(i);
    }
}
