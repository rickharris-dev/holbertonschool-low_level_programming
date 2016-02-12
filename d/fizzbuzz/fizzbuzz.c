#include <stdio.h>

int main(void) 
{
  int i,t,f;                /* Initiates integers variables */

  for (i=1; i <= 100; i++)  /* Starts loop from 1-100 */
    {
      if(i != 1)            /* Determines if i is not 1 */
	printf(" ");        /* Prints space if above not true */
      t = i % 3;            /* Sets t as remainder of i/3 */
      f = i % 5;            /* Sets f as remainder of i/5 */

      if( t && f )          /* Determines if both t & f are not 0 */
	printf("%d",i);     /* Prints the number if above is true */
      else                  /* If t or f is 0 starts next steps */
	{
	  if(!t)            /* Determines if t is 0 */
	    printf("Fizz"); /* Prints Fizz if above is true */
	  if(!f)            /* Determines if f is 0 */
	    printf("Buzz"); /* Prints Buzz if above is true */
	}
    }
  return(0);                /* Returns 0 if function succeeds */
}
