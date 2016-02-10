#include "my_functions.h"

void print_combination_2(void)
{
  int a,b,c;

  for (a=0, b=1; a<10; a++, b++)
      for(c=b; c<10; c++)
	{
	  if(a+c!=1)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	  print_number(a);
	  print_number(c);
	}
}
