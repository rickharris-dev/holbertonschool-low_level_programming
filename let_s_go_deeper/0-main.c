#include <stdio.h>

int factorial(int n);

int main(void)
{
  int r;

  r = factorial(1);
  printf("%d\n", r);
  r = factorial(5);
  printf("%d\n", r);
  r = factorial(2147483647);
  printf("%d\n", r);
  r = factorial(-1024);
  printf("%d\n", r);
  return (0);
}
