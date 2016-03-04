#include <stdio.h>

void swap_int(int *a, int *b)
{
  int swap;
  swap = *a;
  *a = *b;
  *b = swap;
}
