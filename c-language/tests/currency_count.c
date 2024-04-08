#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int m = 4620;
    int a = m / 1000; // a = 4620 / 1000 => 4
    int b = m % 1000 / 500; // b = 4620 % 1000 / 500 => 1
    int c = m % 500 / 100; // c = 4620 % 500 / 100 => 1
    int d = m % 100 / 10; // d = 4620 % 100 / 10 => 2
    printf("1000Won Count : %d\n", a); // 4
    printf(" 500Won Count : %d\n", b); // 1
    printf(" 100Won Count : %d\n", c); // 1
    printf("  10Won Count : %d\n", d); // 2

    return EXIT_SUCCESS;
}