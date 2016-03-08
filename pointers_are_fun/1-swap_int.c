void swap_int(int *a, int *b)
{
  int swap;
  /* Stores int in var swap */
  swap = *a;
  /* Moves int from ptr b to ptr a */
  *a = *b;
  /* Moves int orig in ptr to ptr b */
  *b = swap;
}
