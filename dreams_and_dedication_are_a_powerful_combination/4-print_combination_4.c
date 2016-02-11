#include "my_functions.h"

void print_combination_4(void)
{
  int a,b,c;

  for (a=0, b=1; a<100; a++, b++)
    for(c=b; c<100; c++)
      {
	if(a+c!=1)
	  {
	    print_char(',');
	    print_char(' ');
	  }
	if(a<10)
	  print_number(0);
	print_number(a);
	print_char(' ');
	if(c<10)
	  print_number(0);
	print_number(c);
      }
}
