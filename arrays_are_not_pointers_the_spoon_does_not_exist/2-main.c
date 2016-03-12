#include <limits.h>
void print_array(int *a, int n);

int main(void)
{
  int array[5];

  array[0] = 98;
  array[1] = 402;
  array[2] = 198;
  array[3] = INT_MAX;
  array[4] = INT_MIN;
  print_array(array, 5);
  return (0);
}
