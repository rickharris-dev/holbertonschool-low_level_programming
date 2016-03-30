int find_if_palindrome(char *s, int i, int c){
  if (c >= i)
    return 1;                             /* Returns 1 if palindrome */
  else if (s[c] == s[i - c])
    return find_if_palindrome(s, i, ++c); /* Continues if more to check */
  return 0;                               /* Continues if not a palindrome */
}

int get_length(char *s, int i){
  if (s[i] != '\0')
    return get_length(s, ++i);            /* Continues to find full length */
  else if (i < 2)
    return 0;                             /* Returns 0 if 1 char or less */
  return find_if_palindrome(s, --i, 0);   /* Initializes palindrome test */
}

int is_palindrome(char *s){
  return get_length(s, 0);                /* Initializes count for length */
}
