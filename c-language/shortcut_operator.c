#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 3;
    int y = 3;

    x = x + 2;
    y += 2;

    printf("x: %d, y: %d\n", x, y);

    return 0;
}