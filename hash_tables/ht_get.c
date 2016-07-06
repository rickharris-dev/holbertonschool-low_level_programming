#include "header.h"

char *ht_get(HashTable *hashtable, const char *key)
{
    unsigned int n;
    List *pair;

    n = hash(key, hashtable->size);
    pair = hashtable->array[n];

    while(pair) {
        if (str_cmp(pair->key, key))
            return pair->value;
        pair = pair->next;
    }

    return NULL;
}
