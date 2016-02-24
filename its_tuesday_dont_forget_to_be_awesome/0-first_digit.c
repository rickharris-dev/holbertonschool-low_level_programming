int first_digit(int n)
{
  /* Obtain the absolute value of the number */
  n = n * (( n < 0 ) - (n > 0));

  /* Finds the first digit */
  while (n < -9)
    n = n / 10;

  /* Return 1st digit of n */
  return(n * -1);
}
