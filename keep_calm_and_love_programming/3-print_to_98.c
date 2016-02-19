#include <stdio.h>

void print_to_98(int n)
{
  while(n < 98 || n > 98)
  {
    printf("%d, ",n);
    if(n < 98)
      n++;
    if(n > 98)
      n--;
  }
  printf("98\n");
}
