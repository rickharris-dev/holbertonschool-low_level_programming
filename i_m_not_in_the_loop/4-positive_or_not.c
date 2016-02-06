#include "my_functions.h"

void positive_or_not(int n)
{
  if (n > 0)
    {
      print_char('P');
    }
  if (n < 0)
    {
      print_char('N');
    }
  if (n == 0)
    {
      print_char('Z');
    }
}
