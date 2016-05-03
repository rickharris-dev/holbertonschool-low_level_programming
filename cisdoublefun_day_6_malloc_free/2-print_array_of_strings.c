#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void print_string(char *s)
{
  int c;

  c = 0;
  while(s[c] != '\0') {
    print_char(s[c]);
    c++;
  }
}

void print_array_of_strings(char **a) {
    int c;
    c = 0;
    while (a[c] != NULL) {
      if (c != 0)
        print_char(' ');
      print_string(a[c]);
      c++;
    }
    print_char('\n');
}
