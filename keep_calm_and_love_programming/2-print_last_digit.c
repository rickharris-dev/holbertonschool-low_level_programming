int print_char(char);

void print_last_digit(int n)
{
  if(n != 0)
    print_char('0' + ((n*((n > 0) - (n < 0))) % 10));
  else
    print_char('0');
}
