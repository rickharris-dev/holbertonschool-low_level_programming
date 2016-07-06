#include "header.h"

int str_cmp(const char *str1, const char* str2)
{
    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    if (str1[i] != str2[i]) {
        return 0;
    }
    return 1;
}

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
    unsigned int n;
    List *pair;

    n = hash(key, hashtable->size);

    /* Determine if key is in the linked list */
    pair = hashtable->array[n];
    while (pair != NULL) {
        if (str_cmp(pair->key, key))
            break;
        pair = pair->next;
    }
    /* If no key exists in the List */
    if (pair == NULL) {
        pair = malloc(sizeof(List));
        pair->next = hashtable->array[n];
        hashtable->array[n] = pair;
        hashtable->array[n]->key = strdup(key);
        if (hashtable->array[n]->key == NULL)
            return 1;
    } else {
        free(hashtable->array[n]->value);
    }
    hashtable->array[n]->value = strdup(value);
    if (hashtable->array[n]->value == NULL)
        return 1;
    return 0;
}
