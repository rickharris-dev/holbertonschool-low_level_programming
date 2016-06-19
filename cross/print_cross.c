#include "header.h"

void print_spaces(int n) {
    /* Print the number of spaces given */
    int i;

    for(i = 0; i < n; i++) {
        print_char(' ');
    }
}

void print_top_line(int out, int in) {
    /* Prints a line in the top half of the cross */
    print_spaces(out); /* Print outside */
    print_char('\\'); /* Print slash */
    print_spaces(in); /* Print inside */
    print_char('/'); /* Print slash */
    print_spaces(out); /* Print outside */
    print_char('\n'); /* Print new line char */
}

void print_middle_line(int n) {
    /* Prints the middle line of an odd value cross */
    print_spaces(n - 1); /* Print outside */
    print_char('X'); /* Print X */
    print_spaces(n - 1); /* Print outside */
    print_char('\n'); /* Print new line char */
}

void print_bottom_line(int out, int in) {
    /* Prints a line in the bottom half of the cross */
    print_spaces(out); /* Print outside */
    print_char('/'); /* Print slash */
    print_spaces(in); /* Print inside */
    print_char('\\'); /* Print slash */
    print_spaces(out); /* Print outside */
    print_char('\n'); /* Print new line char */
}

void print_cross(int n) {
    /* Prints a cross of the given size */
    int i;

    if(n == 0) {
        return;
    }

    for(i = 0; i < n; i++) {
        if(i < n / 2) {
            print_top_line(i, n - (i * 2) - 2);
        } else if(i == n / 2 && n % 2) {
            print_middle_line(i + 1);
        } else {
            print_bottom_line(n - (i + 1), (i + 1) - (n - i + 1));
        }
    }
}
