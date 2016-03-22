#include <stdio.h>

char *process_total(int c, int i, int j, char n, char *r, int size_r)
{
  if (c < 0 && (i >= 0 || j >= 0 || n != 48))
    return 0; /* If it doesn't fit in r then returns 0 */
  else if (c >= 0) /* If first digit isn't at r[0], moves the numbers */
      for (i = 0; c < size_r; i++, c++)
        *(r + i) = *(r + c + 1);
  return r; /* Returns the number */
}

char *infinite_add(char *n1, char *n2, char *r, int size_r){
  int i, j, c;
  char a, b, n;
  n = 48;
  for (i = 0; *(n1 + i + 1) != '\0'; i++); /* Finds length of n1 */
  for (j = 0; *(n2 + j + 1) != '\0'; j++); /* Finds length of n2 */
  *(r + 99) = '\0'; /* Sets the null terminator at end of new string */
  for (c = size_r - 2; (i >= 0 || j >= 0 || n != 48) && c >= 0; c--, j--, i--) {
    a = *(n1 + i); /* Retrieves last char in n1 */
    b = *(n2 + j); /* Retrieves last char in n2 */
    if (i < 0)
      a = 48; /* Sets value to 0 if no more numbers* */
    if (j < 0)
      b = 48; /* Sets value to 0 if no more numbers* */
    *(r + c) = a + b + n - 96; /* Totals the two numbers and carryover */
    n = 48; /* Sets the carryover back to 0 */
    if (*(r + c) > 57) { /* If total 10 or more */
      n = 49; /* Sets the carryover to 1 */
      *(r + c) -= 10; /* Subtracts 10 from value */
    }
  }
  return process_total(c, i, j, n, r, size_r);
}
