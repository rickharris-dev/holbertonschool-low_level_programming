#include "header.h"

void ht_free(HashTable *hashtable)
{
    int i;
    List *next;

    for (i = hashtable->size - 1; i >= 0; i--) {
        while (hashtable->array[i]) {
            next = hashtable->array[i]->next;
            free(hashtable->array[i]->key);
            free(hashtable->array[i]->value);
            free(hashtable->array[i]);
            hashtable->array[i] = next;
        }
    }
    free(hashtable->array);
    free(hashtable);
}
