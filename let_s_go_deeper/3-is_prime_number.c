int is_prime_number(int n)
{
  int i, max;
  if (n < 2)
    return 0;

  for (max = n, i = 2; i <= max; i++)
  {
    if (n % i == 0)
      return 0;
    max = n / i;
  }

  return 1;
}
