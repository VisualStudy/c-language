#include <stdio.h>

int SquareFunction(int x)
{
    int r = x * x;
    return r;
}

int main(void)
{
    int r = SquareFunction(2);
    printf("%d\n", r);

    return 0;
}