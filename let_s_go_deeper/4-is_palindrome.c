#include <stdio.h>

int find_if_palindrome(char *s, int i, int c){
  if (c >= i - 1){
    return 1;
  }
  else if (s[c] == s[i - 1 - c]) {
    return find_if_palindrome(s, i, c + 1);
  }
  return 0;
}

int get_length(char *s, int i){
  if (s[i] != '\0'){
    return get_length(s, i + 1);
  }
  return find_if_palindrome(s, i, 0);
}

int is_palindrome(char *s){
  return get_length(s, 0);
}
