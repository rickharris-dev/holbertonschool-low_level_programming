int i = 2;
int max;

int is_prime_number(int n)
{
  if (i == 2)
    max = n;

  if (n < 2)
    return 0;
  else if (n % i == 0)
    return 0;
  else if (i > max) {
    i = 2;
    return 1;
  }

  max = n / i;
  i++;
  return is_prime_number(n);
}
