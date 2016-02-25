#include <unistd.h>

void print_char(char c)
{
  /* Prints the character stored in c */
  write(1, &c, 1);
}

void triangles_in_the_term(int h, int n)
{
  int c, i, j;
  /* Loops to print n number of triangles */
  for(c = 0; c < n; c++)
  {
    /* Loops to print h number of lines */
    for (i = 0; i < h; i++)
      {
        /* Prints the leading spaces */
        for (j = h - 1 - i; j > 0; j--)
          print_char(' ');
        /* Prints the asterisks to build the triangle */
        for (j = 0; j < 2 * i + 1; j++)
          print_char('*');
        print_char('\n');
      }
  }
}
