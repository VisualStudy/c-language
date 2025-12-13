#include <stdio.h>

void change_value(int **pp)
{
    **pp = 99;
}

int main(void)
{
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("Before:\n");
    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    change_value(pp);

    printf("\nAfter:\n");
    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    return 0;
}