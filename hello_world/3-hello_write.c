#include <unistd.h>

int main(void)
{
  write(1, "Hello, C\n", 10);
  return 0;
}
