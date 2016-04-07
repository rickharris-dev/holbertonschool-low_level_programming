#include "../inc/holbertonschool.h"

void print_array(int *a, int n)
{
  int i;
  /* Loop to get each array value */
  for (i = 0; i < n; i++)
  {
    /* If not first value print ', ' */
    if (i != 0)
    {
      print_char(',');
      print_char(' ');
    }
    print_number(*(a + i));
  }
  /* Print new line character */
  print_char('\n');
}
