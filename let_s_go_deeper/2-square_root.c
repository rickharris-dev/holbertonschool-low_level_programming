int find_square_root(int n, int c) {
  long test = c * c;

  if (n < 0) {
    return -1;
  }
  else if (n == 0){
    return 0;
  }
  else if (test == n) {
    return c;
  }
  else if (test > n){
    return -1;
  }
  return find_square_root(n, c + 1);
}

int square_root(int n)
{
  return find_square_root(n, 1);
}
