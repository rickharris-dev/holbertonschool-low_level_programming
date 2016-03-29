int compare_strings(char *s1, char *s2, int c, int w){
  if (*s2 == '*')
    return compare_strings(s1, ++s2, 0, 1);
  else if (*s1 == *s2 && *s1 != '\0')
    return compare_strings(s1 + 1, ++s2, ++c, w);
  else if (*s1 != *s2 && w == 1)
    return compare_strings(s1 - (c + 1), s2 - c, 0, 1);
  else if (*s1 == *s2)
    return 1;
  return 0;
}

int shell_comp(char *s1, char *s2) {
  return compare_strings(s1, s2, 0, 0);
}
