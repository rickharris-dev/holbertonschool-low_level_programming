#include <stdio.h>

unsigned long fibonacci(unsigned long, unsigned long);

int main(void)
{
  unsigned long total;

  total = fibonacci(0,1); /* Sets total as value returned by fibonacci */
  printf("%lu\n", total); /* Prints the value of total */
  return (0);
}

unsigned long fibonacci(unsigned long a, unsigned long b)
{
  unsigned long c, sum;

  while (b < 4000000) /* Starts loop while b < 4000000 */
  {
    if(b % 2 == 0) /* Checks if number is even */
      sum = sum + b; /* Adds the number to the total */
    if(a + b > 4000000) /* Checks if the next number is > 4000000 */
      c = 4000000; /* Stops the loop */
    else
      c = a + b; /* Sets the next number*/
    a = b; /* Cycles numbers in b to a */
    b = c; /* Sets b as the next number */
  }
  return(sum); /* Returns the sum to the main to print */
}
