#include <stdlib.h>

void quick_sort(int *array, int size)
{
        int a = 0;
        int z = size - 1;
        int pivot;
        int swap;
        /* Returns if the partition is sorted */
        if (size < 2)
                return;
        /* Chooses a random pivot point */
        pivot = array[rand() % size];
        /* Swaps values until sorted small to left and larger right */
        while (a < z) {
                while (array[a] < pivot)
                        a++;
                while (array[z] > pivot)
                        z--;
                swap = array[a];
                array[a] = array[z];
                array[z] = swap;
        }
        /* Recursively sorts each partition */
        quick_sort(array, a);
        quick_sort(&array[a + 1], size - a - 1);
}
