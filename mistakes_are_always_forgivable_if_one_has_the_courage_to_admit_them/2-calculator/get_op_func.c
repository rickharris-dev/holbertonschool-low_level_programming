#include <stdio.h>
int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char c))(int a, int b){
  int i;
  int (*op_func[6])(int, int) = {op_add, op_sub, op_mul, op_div, op_mod};

  i = (c == '+')*1+(c == '-')*2+(c == '*')*3+(c == '/')*4+(c == '%')*5 - 1;
  if (i == -1)
    return NULL;
  return (op_func[i]);
}
