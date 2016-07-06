#include "header.h"

void ht_free(HashTable *hashtable)
{
    int i;
    List *next;
    /* Loops through each array item */
    for (i = hashtable->size - 1; i >= 0; i--) {
        /* Frees each list item at the array item */
        while (hashtable->array[i]) {
            next = hashtable->array[i]->next;
            free(hashtable->array[i]->key);
            free(hashtable->array[i]->value);
            free(hashtable->array[i]);
            hashtable->array[i] = next;
        }
    }
    /* Frees the array pointer memory */
    free(hashtable->array);
    /* Frees the HashTable */
    free(hashtable);
}
