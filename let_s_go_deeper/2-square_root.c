int c = 1;

int square_root(int n)
{
  long test = c * c;

  if (n < 0)
    return -1;
  else if (n == 0)
    return 0;
  else if (test == n)
  {
    n = c;
    c = 1;
    return n;
  }
  else if (test > n)
    return -1;
  c++;
  return square_root(n);
}
