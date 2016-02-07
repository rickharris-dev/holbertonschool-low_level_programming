#include "my_functions.h"

int calc_length(int n) 
{
  /*  */
  int l;

  /*  */
  for (l = 0; n>=1; l++) 
  {
    /*  */
    n = n / 10;
  }

  /*  */
  return l;
}

void parse_print(int n, int l)
{
  /*  */
  while (l > 0)
  {
    /*  */
    int c,d,i;
    /*  */
    char b;
    /*  */
    c = 1;

    /*  */
    for (i = 1; l > i; i++)
      {
	/*  */
        c = c * 10;
      }

    /*  */
    d = (n - (n % c)) / c;
    /*  */
    n = n - (d * c);
    /*  */
    b = '0' + d;
    /*  */
    print_char(b);
    /*  */
    l--;
  }  
}

void send_print(

void print_number(int n)
{
  int l;

  if (n == 0)
    {
      print_char('0');
    }
  else if (n < 0)
    {
      print_char('-');
      n = n * -1;
    }              

  l = calc_length(n);
  parse_print(n,l);
}
