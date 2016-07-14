void bubble_sort(int *array, int size)
/* Function bubble sorts an array of integers */
{
        int i;
        int sorted = 1;
        int swap;

        /* Loops through the array comparing two integers at a time */
        for (i = 0; i < size - 1; i++) {
                if (array[i] > array[i + 1]) {
                        swap = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = swap;
                        sorted = 0;
                }
        }
        /* Recurses over the array until no sorting change is made */
        if (sorted == 1)
                return;
        bubble_sort(array, size);
}
