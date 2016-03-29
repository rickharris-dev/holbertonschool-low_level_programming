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

int compare_strings(char *s1, char *s2, int c, int w){
  if (*s2 == 42){
    s2 = advance_s2_to_char(s2);
    s1 = advance_s1_to_match(s1, s2);
    return compare_strings(s1, s2, 0, 1);
  }
  else if (*s1 == *s2 && *s1 != '\0')
    return compare_strings(s1 + 1, s2 + 1, c + 1, w);
  else if (*s1 != *s2 && w == 1)
    return compare_strings(s1 - c + 1, s2 - c - 1, 0, 0);
  else if (*s1 == *s2)
    return 1;
  return 0;
}

int shell_comp(char *s1, char *s2) {
  return compare_strings(s1, s2, 0, 0);
}
