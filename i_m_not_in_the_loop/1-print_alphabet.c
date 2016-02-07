#include "my_functions.h"

void print_alphabet(void)
{
  /* Declares that the variable i will be an integer */
  int i;

  /* Initiates a for look to cycle through ASCII char values */
  for (i = 97; i < 123; i++)
    {
      /* Calls the print function to print the current ASCII value */
      print_char(i);
    }
}
