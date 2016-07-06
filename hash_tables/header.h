#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
int print_char(char c);
HashTable *ht_create(unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);
char *ht_get(HashTable *hashtable, const char *key);
void ht_free(HashTable *hashtable);
int str_cmp(const char *str1, const char* str2);
