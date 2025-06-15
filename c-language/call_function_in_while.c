#include <stdio.h>

int positive(int x)
{
    return x > 0;
}

int main(void)
{
    int n = 3;
    
    while (positive(n))
    {
        printf("n = %d\n", n);
        n--;
    }

    return 0;
}