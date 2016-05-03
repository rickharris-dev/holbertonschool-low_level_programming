#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1)); /* Prints each char */
}

void print_string(char *s)
{
  int c;

  c = 0;
  while(s[c] != '\0') {
    print_char(s[c]); /* Prints each char of string */
    c++;
  }
}

void print_array_of_strings(char **a) {
    int c;
    c = 0;
    while (a[c] != NULL) {
      if (c != 0)
        print_char(' '); /* Prints a space between each string */
      print_string(a[c]); /* Prints each string */
      c++;
    }
    print_char('\n'); /* Prints a closing new line char */
}
