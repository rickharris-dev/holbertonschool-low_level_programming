#include "my_functions.h"

void print_number(int n)
{
  int length, a;

  if (n == 0)
    {
      print_char('0');
    }

  if (n < 0)
    {
      print_char('-');
      n = n * -1;
    }              

  a = n;

  for (length = 0; a >= 1; length++)
    {
      a = a / 10;
    }

  while (length > 0)
    {
      int c,d,i;
      char b;
      c = 1;
      for (i = 1; length > i; i++)
	{
	  c = c * 10;
	}
      d = (n - (n % c)) / c;
      n = n - (d * c);
      b = '0' + d;
      print_char(b);
      length--;
    }
}
