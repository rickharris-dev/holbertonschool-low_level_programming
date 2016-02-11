#include "my_functions.h"

void print_combination_3(void)
{
  int a,b,c,d,e,f;

  for (a=0, b=1, c=2; a<10; a++, b++, c++)
    for(d=b, e=c; d<10; d++, e++)
      for(f=e; f<10; f++)
	{
	  if(a+d+f!=3)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	  print_number(a);
	  print_number(d);
	  print_number(f);
	}
}
