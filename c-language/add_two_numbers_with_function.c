#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int x = 100;
    int y = 200;
    int result;

    result = add(x, y);

    printf("두 수의 합: %d\n", result);

    return 0;
}