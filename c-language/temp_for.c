#include <stdio.h>

int main(void)
{
    int temp;
    int x, y;
    x = 2;
    y = 5;

    temp = x;
    x = y;
    y = temp;

    printf("x��: %d\n", x);
    printf("y��: %d\n", y);

    return 0;
}