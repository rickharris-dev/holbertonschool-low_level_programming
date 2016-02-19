#include "my_functions.h"

int main(void)
{
  int total;

  total = print_natural(1024);
  printf("%i\n",total);
  return(0);
}

int print_natural(int n)
{
  int i,sum;

  sum = 0;

  for(i = 0; i < n; i++)
    if(i % 3 == 0 || i % 5 == 0)
      sum = sum + i;
  return(sum);
}
