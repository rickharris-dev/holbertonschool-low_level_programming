#include <stdlib.h>

void quick_sort(int *array, int size)
{
        int a = 0;
        int z = size - 1;
        int pivot;
        int swap;

        if (size < 2) /* Returns if the partition is sorted */
                return;
        pivot = array[rand() % size]; /* Chooses a random pivot point */
        /* Swaps values until sorted small to left and larger right */
        while (a < z) {
                while (array[a] < pivot)
                        a++;
                while (array[z] > pivot)
                        z--;
                if (array[a] > array[z]) {
                        swap = array[a];
                        array[a] = array[z];
                        array[z] = swap;
                } else {
                        a++;
                }
        }
        /* Recursively sorts each partition */
        quick_sort(array, a);
        quick_sort(&array[a], size - a);
}
