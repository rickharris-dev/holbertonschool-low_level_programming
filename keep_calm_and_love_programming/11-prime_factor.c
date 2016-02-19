#include <stdio.h>

int prime(unsigned long, unsigned long, unsigned long);

int main(void)
{
  unsigned long largest, factor, i;

  for (i = 2, factor = 1, largest = 0; largest == 0; i++)
  {
    if (612852475143 / factor % i == 0)
      factor = factor * i;
      if (612852475143 / factor < 4294967294)
        largest = 612852475143 / factor;
  }

  largest = prime(largest, factor, i);
  printf("%lu\n",largest);
  return (0);
}

int prime(unsigned long largest, unsigned long factor, unsigned long i)
{
  while ( i < (largest / 2))
  {
    if (largest % i == 0)
    {
      factor = factor * i;
      largest = largest / i;
    }
    else
      i++;
  }

  return (largest);
}
