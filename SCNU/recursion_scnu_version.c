#include <stdio.h>

int fac(int n);

int main(void)
{
    int a = 5;
    int result = fac(a);
    printf("result: %d\n", result);

    return 0;
}

int fac(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    int x = n * fac(n - 1);

    return x;
}