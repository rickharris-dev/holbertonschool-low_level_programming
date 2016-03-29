int x = 0, y = 0, w = 0, m1 = -1, m2 = -1;

int shell_comp(char *s1, char *s2)
{
  if (s1[x] == s2[y] && s1[x] == '\0') {
    x = 0, y = 0, w = 0, m1 = -1, m2 = -1;
    return 1;
  }
  else if (s1[x] == s2[y] && w == 1)
    m1 = x, m2 = y + 1, x++, y++, w = 0;
  else if (s1[x] == s2[y])
    x++, y++, w = 0;
  else if (s2[y] == 42)
    y++, w = 1;
  else if (w == 1 && s1[x] != '\0')
    x++;
  else if (w == 0 && s1[x] != '\0' && m1 > -1)
    x = m1, y = m2, w = 1;
  else if ((w == 0 && s1[x] != '\0') || s1[x] == '\0') {
    x = 0, y = 0, w = 0, m1 = -1, m2 = -1;
    return 0;
  }
  return shell_comp(s1, s2);
}
