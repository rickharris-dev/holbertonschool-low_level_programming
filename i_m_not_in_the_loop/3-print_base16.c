#include "my_functions.h"

void print_base16(void)
{
  int i;

  for (i = 48; i < 58; i++)
    {
      print_char(i);
    }
  for (i = 65; i < 71; i++)
    {
      print_char(i);
    }
}
