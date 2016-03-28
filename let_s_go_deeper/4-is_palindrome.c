int i = 0, length = 0, c = 0;

int is_palindrome(char *s){
  /* Find the length of the string */
  if(*(s + i) != '\0' && length != 1) {
    i++;
    return is_palindrome(s);
  }

  length = 1;

  if (c >= i - 1){
    i = 0, length = 0, c = 0;
    return 1;
  }
  else if (s[c] == s[i - 1]) {
    c++, i--;
    return is_palindrome(s);
  }
  i = 0, length = 0, c = 0;
  return 0;
}
