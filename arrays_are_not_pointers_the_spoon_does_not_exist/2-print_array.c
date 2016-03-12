int print_char(char c);

void print_number(int n){
  int i,j,k,x;
  char c;
  /* If array value is negative print '-' */
  if (n < 0)
    print_char('-');
  else
    n *= -1;
  /* Find the number of digits in the value */
  for (i = 0, x = n; x <= -1; i++, x /= 10);
  /* Set the divisor */
  for (j = 1; i > 1; i--)
    j *= 10;
  /* Get each number and print it */
  while (j >= 1)
  {
    k = n / j * -1;
    c = '0' + k;
    print_char(c);
    n = n + (j * k);
    j /= 10;
  }
}

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
