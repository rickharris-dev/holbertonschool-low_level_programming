int find_square_root(int n, int c) {
  long test = c * c;                  /* Sets test value */

  if (n < 0)
    return -1;                        /* Returns -1 if n is negative */
  else if (n == 0)
    return 0;                         /* Returns 0 if n is 0 */
  else if (test == n)
    return c;                         /* Returns c if is square root of n */
  else if (test > n)
    return -1;                        /* Returns -1 if no square root */
  return find_square_root(n, c + 1);  /* Continues recursion */
}

int square_root(int n)
{
  return find_square_root(n, 1);      /* Initializes recursion */
}
