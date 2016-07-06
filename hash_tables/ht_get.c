#include "header.h"

char *ht_get(HashTable *hashtable, const char *key)
{
    unsigned int n;
    List *pair;
    /* Retrieves the index */
    n = hash(key, hashtable->size);
    /* Sets pointer to list */
    pair = hashtable->array[n];
    /* Loops through list to find key */
    while(pair) {
        if (str_cmp(pair->key, key))
            return pair->value;
        pair = pair->next;
    }
    /* Returns NULL if no key found */
    return NULL;
}
