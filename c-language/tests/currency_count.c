#include <stdio.h>

main() {
    int m = 4620;
    int a = m / 1000;
    int b = m % 1000 / 500;
    int c = m % 500 / 100;
    int d = m % 100 / 10;
    printf("1000Won Count : %d\n", a);
    printf(" 500Won Count : %d\n", b);
    printf(" 100Won Count : %d\n", c);
    printf("  10Won Count : %d\n", d);
}