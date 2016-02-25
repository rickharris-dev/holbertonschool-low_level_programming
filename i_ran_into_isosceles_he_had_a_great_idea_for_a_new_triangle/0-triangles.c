#include <unistd.h>

void print_char(char c)
{
  write(1, &c, 1);
}

void triangles_in_the_term(int h, int n)
{
  int c, i, j;
  for(c = 0; c < n; c++)
  {
    for (i = 0; i < h; i++)
      {
        for (j = h - 1 - i; j > 0; j--)
          print_char(' ');
        for (j = 0; j < 2 * i + 1; j++)
          print_char('*');
        print_char('\n');
      }
  }
}
