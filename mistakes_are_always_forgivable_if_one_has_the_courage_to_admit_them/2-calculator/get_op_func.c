#include <stdio.h>
int op_add(int, int); /* Function prototypes */
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char c))(int a, int b){
  int i;
  char op[6] = {'+', '-', '*', '/', '%'};
  int (*op_func[6])(int, int) = {op_add, op_sub, op_mul, op_div, op_mod};

  for (i = 0; i < 5; i++)
    if (c == op[i]) /* Checks for a matching operator */
      return op_func[i]; /* Return pointer to the function */
  return NULL; /* If no match found, returns NULL */
}
