#include "../inc/holbertonschool.h"

void positive_or_not(int n)
{
  /* Determines if n is greater than 0 */
  if (n > 0)
    {
      /* Calls print function to print P to denote positive */
      print_char('P');
    }

  /* Determines if n is less than 0 */
  if (n < 0)
    {
      /* Calls print function to print N to denote negative */
      print_char('N');
    }

  /* Determines if n is equal to 0 */
  if (n == 0)
    {
      /* Calls print function to print Z to denote zero */
      print_char('Z');
    }
}
