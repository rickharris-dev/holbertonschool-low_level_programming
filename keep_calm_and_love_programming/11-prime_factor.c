#include <stdio.h>

int main(void)
{
  unsigned long largest, factor, i;

  /* Starts for loop */
  for (i = 2, factor = 1; i < 612852475143 / factor; i++)
  {
    if (612852475143 / factor % i == 0) /* Checks if i is a factor */
      factor = factor * i; /* Adds i to factor */
      largest = 612852475143 / factor; /* Remainder of n and current factor */
  }

  printf("%lu\n",largest); /* Prints the largest prime factor */
  return (0); /* Returns successful */
}
