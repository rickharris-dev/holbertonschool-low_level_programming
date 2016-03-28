int square_root(int n)
{
  int c;
  long test;

  if (n < 0)
    return -1;
  else if (n == 0)
    return 0;

  for (c = 1; c <= n; c++)
  {
    test = c * c;
    if (test == n)
      return c;
    else if (test > n)
      return -1;
  }

  return -1;
}
