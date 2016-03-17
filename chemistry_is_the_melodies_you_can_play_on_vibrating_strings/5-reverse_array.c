void reverse_array(int *a, int n)
{
  int i, s;
  for (i = 0, n -= 1; i < n; i++, n--)
  {
    s = *(a + i);
    *(a + i) = *(a + n);
    *(a + n) = s;
  }
  return;
}
