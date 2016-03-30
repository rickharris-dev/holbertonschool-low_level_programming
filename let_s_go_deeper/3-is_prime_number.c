int find_if_prime(int n, int i){
  if (n < 2)
    return 0;                     /* Returns 0 if value < 1st prime */
  else if (i > n - 1)
    return 1;                     /* Returns 1 if no divisor found */
  else if (n % i == 0)
    return 0;                     /* Returns 0 if divisor found */
  return find_if_prime(n, i + 1); /* Continues recursion */
}

int is_prime_number(int n)
{
  return find_if_prime(n, 2);     /* Initializes recursion */
}
