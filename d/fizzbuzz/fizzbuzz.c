#include <stdio.h>

int main(void) 
{
  int i,t,f;

  for (i=1; i <= 100; i++)
    {
      if(i != 1)
	printf(" ");
      t = i % 3;
      f = i % 5;

      if( t && f )
	printf("%d",i);
      else
	{
	  if(!t)
	    printf("Fizz");
	  if(!f)
	    printf("Buzz");
	}
    }
  return(0);
}
