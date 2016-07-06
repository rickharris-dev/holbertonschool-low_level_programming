#include "header.h"

int str_cmp(const char *str1, const char* str2)
{
    int i;
    /* Checks each char in the string */
    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    /* Checks that strings terminate at same point */
    if (str1[i] != str2[i]) {
        return 0;
    }
    return 1;
}

List *find_list(HashTable *hashtable, const char *key, int n)
{
    List *pair;
    /* Determine if key is in the linked list */
    pair = hashtable->array[n];
    while (pair != NULL) {
        if (str_cmp(pair->key, key))
            break;
        pair = pair->next;
    }
    return pair; /* Returns pointer to List item or NULL */
}

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
    unsigned int n;
    List *pair;

    n = hash(key, hashtable->size);
    pair = find_list(hashtable, key, n);
    if (pair == NULL) { /* Creates List if no pair found */
        pair = malloc(sizeof(List));
        pair->next = hashtable->array[n];
        hashtable->array[n] = pair;
        hashtable->array[n]->key = strdup(key);
        if (hashtable->array[n]->key == NULL)
            return 1;
    } else { /* Frees the current value if key exists */
        free(hashtable->array[n]->value);
    }
    /* Sets value for all cases */
    hashtable->array[n]->value = strdup(value);
    if (hashtable->array[n]->value == NULL)
        return 1;
    return 0;
}
