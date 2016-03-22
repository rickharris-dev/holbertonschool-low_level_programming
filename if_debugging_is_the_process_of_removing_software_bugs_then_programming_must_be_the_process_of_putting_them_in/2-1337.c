char *leet(char *c)
{
  int i;
  for (i = 0; c[i] != '\0'; i++)
  {
    if ( c[i] == 'a' || c[i] == 'A')
      c[i] = '4'; /* Replaces a with 4 */
    else if ( c[i] == 'e' || c[i] == 'E')
      c[i] = '3'; /* Replaces e with 3 */
    else if ( c[i] == 'o' || c[i] == 'O')
      c[i] = '0'; /* Replaces o with 0 */
    else if ( c[i] == 't' || c[i] == 'T')
      c[i] = '7'; /* Replaces t with 7 */
    else if ( c[i] == 'l' || c[i] == 'L')
      c[i] = '1'; /* Replaces l with 1 */
  }
  return c;
}
