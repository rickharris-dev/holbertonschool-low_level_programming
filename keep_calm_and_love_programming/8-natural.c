#include "my_functions.h"

int main(void)
{
  int total;

  total = print_natural(1024); /* Calls print_natural function */
  printf("%i\n",total); /* Prints total from function */
  return(0); /* Returns successful */
}

int print_natural(int n)
{
  int i,sum;

  sum = 0;

  for(i = 0; i < n; i++) /* Starts loop up to 1024 */
    if(i % 3 == 0 || i % 5 == 0) /* Checks for multiples of 3 and 5 */
      sum = sum + i; /* Adds those numbers to the sum */
  return(sum); /* Returns total of multiples */
}
