#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char x;
    x = 'a';
    
    printf("%d\n", x);
    printf("%c\n", x);
    
    printf("-----------\n");

    int y;
    y = 97;

    printf("%d\n", y);
    printf("%c\n", y);

    printf("-----------------\n");

    char z;
    z = 'a';
    z = z + 1;

    printf("%d\n", z);
    printf("%c\n", z);

    printf("------\n");

    z = z - 32;

    printf("%d\n", z);
    printf("%c\n", z);

    printf("----------\n");

    z = z - 31;

    printf("%d\n", z);
    printf("%c\n", z);

    printf("----------------------\n");

    y = y - 31;

    printf("%d\n", y);
    printf("%c\n", y);

    return EXIT_SUCCESS;
}