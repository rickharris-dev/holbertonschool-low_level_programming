#include <stdio.h>

void print_to_98(int n)
{
  while(n != 98) /* Check if n is not 98 */
  {
    printf("%d, ",n); /* Prints n with comma and space */
    if(n < 98) /* Checks if number is less than 98 */
      n++; /* Adds 1 to n */
    if(n > 98) /* Checks if n is greater than 98 */
      n--; /* Subtracts 1 from n */
  }
  printf("98\n"); /* Prints 98 */
}
