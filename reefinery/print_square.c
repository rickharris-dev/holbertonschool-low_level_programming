int print_char(char);
void print_line(int);
void print_middle(int);

void print_square(int n)
{
  int i;

  if (n < 1)  /* If less than 1 then nothing is printed */
    return;
  else if (n == 1) /* If equal to 1 then print o */
    {
      print_char('o');
      print_char('\n');
    }
  else /* All other cases follow the algorithm */
    {
      /* Prints the first line */
      print_line(n);

      /* Determines number of lines needed */
      for (i = 0; i < n - 2; i++)
	print_middle(n); /* Prints each middle line */

      /* Prints the last line */
      print_line(n); 
    }
}

void print_line(int n)
{
  int i;

  print_char('o');
  for (i = 0; i < n - 2; i++)
    print_char('-');
  print_char('o');
  print_char('\n');
}

void print_middle(int n)
{
  int i;

  print_char('|');
  for(i = 0; i < n - 2; i++)
    print_char(' ');
  print_char('|');
  print_char('\n');
}
