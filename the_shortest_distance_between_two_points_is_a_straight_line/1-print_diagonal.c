int print_char(char c);

void print_diagonal(int n)
{
  int i,j;

  /* Prints new line if n is 0 or negative */
  if (n < 1)
    print_char('\n');

  /* Loops through each line of the diagonal */
  for (i = 0; i < n; i++)
  {
    /* Prints a spaces needed to move to diagonal on each line */
    for (j = 0; j < i; j++)
      print_char(' ');
    /* Prints the diagonal and new line */
    print_char('\\');
    print_char('\n');
  }
}
