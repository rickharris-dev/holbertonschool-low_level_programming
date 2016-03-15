int print_char(char c);

void print_line(int n)
{
  int i;
  /* Prints the number of underscores = to n if > 0*/
  if (n > 0)
    for (i = 0; i < n; i++)
      print_char('_');
  /* Prints a new line in all cases */
  print_char('\n');
}
