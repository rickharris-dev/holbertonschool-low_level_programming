#include <unistd.h>
#include "../inc/holbertonschool.h"

int print_char(char c)
{
return (write(1, &c, 1));
}
