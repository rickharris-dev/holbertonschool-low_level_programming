#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}
julien@production-503e7013:~/Holberton_School$
