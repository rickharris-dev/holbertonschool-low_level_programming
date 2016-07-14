#include <stdlib.h>
#include <string.h>

void quick_sort_str_array(char **array, int size)
{
        int a = 0;
        int z = size - 1;
        char *pivot;
        char *swap;

        if (size < 2) /* Returns if the partition is sorted */
                return;
        pivot = array[rand() % size]; /* Chooses a random pivot point */
        /* Swaps values until sorted small to left and larger right */
        while (a < z) {
                while (strcmp(array[a], pivot) < 0)
                        a++;
                while (strcmp(array[z], pivot) > 0)
                        z--;
                if (strcmp(array[a], array[z]) != 0) {
                        swap = array[a];
                        array[a] = array[z];
                        array[z] = swap;
                } else {
                        a++;
                }
        }
        /* Recursively sorts each partition */
        quick_sort_str_array(array, a);
        quick_sort_str_array(&array[a + 1], size - a - 1);
}

void sort_str_array(char **array)
{
        int size;
        /* Gets the length of the array */
        for (size = 0; array[size] != NULL; size++);
        /* Initializes the sorting process */
        quick_sort_str_array(array, size);
}
