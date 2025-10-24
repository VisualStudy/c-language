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

    printf("x°ª: %d\n", x);
    printf("y°ª: %d\n", y);

    return 0;
}