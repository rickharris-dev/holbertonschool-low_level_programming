#include <stdio.h>

void fibonacci(long, long);

int main(void)
{
  fibonacci(0,1); /* Calls the function to print sequence */
  return (0); /* Returns 0 */
}

void fibonacci(long a, long b)
{
  int i;
  long c;

  for(i = 0; i < 50; i++) /* Checks if 50th number has printed */
    if(i == 0) /* If it is the first number */
      printf("%ld, ",a); /* Prints a */
    else
    {
      printf("%ld", b); /* Prints b */
      if(i != 49) /* Checks if it is not the last number */
        printf(", "); /* Prints comma and space */
      c = a + b; /* Sets next number */
      a = b; /* Cycles b to a */
      b = c; /* Sets b as the next number */
    }
}
