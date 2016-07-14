void insertion_sort(int *array, int size)
{
        int i;
        int j;
        int swap;

        /* Loops through the array */
        for (i = 0; i < size; i++) {
                /* Swaps the value in sorted list to the insertion point */
                for (j = i; j > 0; j--) {
                        if (array[j] < array[j - 1]) {
                                swap = array[j];
                                array[j] = array[j - 1];
                                array[j - 1] = swap;
                        } else {
                                break;
                        }
                }
        }
}
