#include <stdio.h>

void fibonacci(long, long);

int main(void)
{
  fibonacci(0,1);
  return (0);
}

void fibonacci(long a, long b)
{
  int i;
  long c;

  for(i = 0; i < 50; i++)
    if(i == 0)
      printf("%ld, ",a);
    else
    {
      printf("%ld", b);
      if(i != 49)
        printf(", ");
      c = a + b;
      a = b;
      b = c;
    }
}
