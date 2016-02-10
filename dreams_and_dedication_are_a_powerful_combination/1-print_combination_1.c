#include "my_functions.h"

void print_combination_1(void)
{
  int i;

  for (i=0; i<10; i++)
    {
      if (i != 0)
	{
	  print_char(',');
	  print_char(' ');
	}
      print_number(i);
    }
}
