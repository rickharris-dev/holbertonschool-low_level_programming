#include "header.h"

HashTable *ht_create(unsigned int size)
{
    HashTable *new;
    unsigned int i;

    /* Create new HashTable */
    new = malloc(sizeof(HashTable));
    if (new == NULL)
        return NULL;
    /* Sets the size of the HashTable */
    new->size = size;
    /* Allocates mem for array */
    new->array = malloc(sizeof(List *) *  size);
    if (new->array == NULL)
        return NULL;
    /* Sets the default value to NULL */
    for (i = 0; i < size; i++)
        new->array[i] = NULL;
    /* Returns the new HashTable */
    return new;
}
