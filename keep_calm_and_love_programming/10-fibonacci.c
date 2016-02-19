#include <stdio.h>

unsigned long fibonacci(unsigned long, unsigned long);

int main(void)
{
  unsigned long total;

  total = fibonacci(0,1);
  printf("%lu\n", total);
  return (0);
}

unsigned long fibonacci(unsigned long a, unsigned long b)
{
  unsigned long c, sum;

  while (b < 4000000)
  {
    if(b % 2 == 0)
      sum = sum + b;
    if(a + b > 4000000)
      c = 4000000;
    else
      c = a + b;
    a = b;
    b = c;
  }
  return(sum);
}
