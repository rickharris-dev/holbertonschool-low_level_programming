#include "header.h"

HashTable *ht_create(unsigned int size)
{
    HashTable *new;
    unsigned int i;

    new = malloc(sizeof(HashTable));
    if (new == NULL)
        return NULL;
    new->size = size;
    new->array = malloc(sizeof(List *) *  size);
    if (new->array == NULL)
        return NULL;
    for (i = 0; i < size; i++)
        new->array[i] = NULL;
    return new;
}
