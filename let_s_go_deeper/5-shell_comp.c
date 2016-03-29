char* advance_s2_to_char(char *s2){
  if (*s2 == 42)
    return advance_s2_to_char(s2 + 1);
  return s2;
}

char* advance_s1_to_match(char *s1, char *s2){
  if (*s1 != *s2 && *s1 != '\0')
    return advance_s1_to_match(s1 + 1, s2);
  return s1;
}

int shell_comp(char *s1, char *s2)
{
  static int c = 0;
  static int w = 0;
  int r = 0;
  if (*s2 == 42){
    w = 1;
    s2 = advance_s2_to_char(s2);
    s1 = advance_s1_to_match(s1, s2);
    c = 0;
    return shell_comp(s1, s2);
  } else if (*s1 == *s2 && *s1 != '\0') {
    c++;
    return shell_comp(s1 + 1, s2 + 1);
  } else if (*s1 != *s2 && w == 1) {
    w = 0;
    return shell_comp(s1 - c + 1, s2 - c - 1);
  } else if (*s1 == *s2)
    r = 1;
  c = 0;
  w = 0;
  return r;
}
