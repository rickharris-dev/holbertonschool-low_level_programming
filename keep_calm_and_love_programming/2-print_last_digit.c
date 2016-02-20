int print_char(char);

void print_last_digit(int n)
{
  if(n != 0) /* Checks if number is 0 */
    /* Gets absolute value of 0 and get remainder when divied by 10 */
    print_char('0' + ((n*((n > 0) - (n < 0))) % 10));
  else
    print_char('0'); /* If 0 prints 0 */
}
