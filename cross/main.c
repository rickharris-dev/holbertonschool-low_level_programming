#include "header.h"

int str_to_int(char *str) {
    /* Converts a string to an integer */
    int i;
    int n;

    n = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] < 48 || str[i] > 57) {
            return -1;
        } else if ((INT_MAX - (n * 10)) < (str[i] - 48)) {
            return -1;
        }
        n = (n * 10) + (str[i] - 48);
    }
    return n;

}

int main(int argc, char **argv) {
    /* Initializes the printing of a cross */
    int n;

    if(argc == 1) {
        /* If no integer prints nothing */
        return 0;
    }

    n = str_to_int(argv[1]);
    if (n == -1) {
        write(1, "Not a valid positive integer\n", 30);
        return 1;
    }
    print_cross(n);
    return 0;
}
