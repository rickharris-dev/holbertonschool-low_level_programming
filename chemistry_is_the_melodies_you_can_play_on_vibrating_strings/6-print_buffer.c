#include <stdio.h>
int print_char(char c);

void print_hexchar(int i)
{
  if (i < 10)
    print_char(i + '0');                       /* Prints digits of hex */
  else
    print_char(i + 87);                        /* Prints letters of hex*/
  return;
}

void print_hexloc(int i)
{
  int j,k,l;

  for (l = 0, k = i; k >= 1; l++, k = k / 16); /* Find the length of i in hex */
  for (j = 0; j < 8 - l; j++)                  /* Print the leading zeros */
    print_char('0');
  while (i > 1)                                /* Print each digit of loc */
    if (i > 16)
    {
      print_hexchar(i / 16);                   /* Prints the leading digit */
      i = i % 16;
      if (i == 0)                              /* If the remainder is 0 */
        print_hexchar(0);                      /* Prints a zero char */
    }
    else
    {
      print_hexchar(i);                        /* Prints last char if not 0 */
      i = i / 16;
    }
  print_char(':');
  print_char(' ');
  return;
}

void print_hexnum (int i, int s)
{
  if (s)
  {
    print_hexchar(i / 16);                     /* Prints first digit */
    print_hexchar(i % 16);                     /* Prints second digit */
  }
  else
  {
    print_char(' ');                           /* Prints spaces once size */
    print_char(' ');                           /* limit is reached */
  }
  return;
}

void print_buffer(char *b, int size)
{
  int i, j, k, l;
  fflush(stdout);                              /* Prints stdout buffer*/
  for (i = 0; i < size; i = i + 10)            /* Rotates every 10 characters */
  {
    print_hexloc(i);                           /* Prints memory loc rel to b */
    for (j = 0; j < 10; j += 2)
    {
      for (k = 0; k < 2 && i + j + k < size; k++)
        print_hexnum(*(b + i + j + k), 1);     /* Prints numbers in hex */
      for (k = k; k < 2 && i + j + k >= size; k++)
        print_hexnum(*(b + i + j + k), 0);     /* Prints spaces after limit */
      print_char(' ');                         /* Prints separater */
    }
    for (l = 0; l < 10; l++)
    {
      if (*(b + i + l) > 31 && *(b + i + l) < 127 && i + l < size)
        print_char(*(b + i + l));              /* Writes printable char */
      else if (i + l < size)
        print_char('.');                       /* Writes . if non-print char */
    }
    print_char('\n');                          /* Ends with new line */
  }
}
