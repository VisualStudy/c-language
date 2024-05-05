#include <stdio.h>
#define K 5

int main(void)
{
    int n = 0;
    int b[K] = { 1, 0, 1, 1, 0 };
    int i;
    int j;
    int temp;
    
    for (i = 0; i < K; i++)
    {
        temp = 1;
        for ( j = 1; j <= K - 1 - i ; j++)
        {
            temp = temp * 2; // 1: 16, 2: 8, 3: 4, 4: 2
        }
        n = n + b[i] * temp;
    }

    printf("%d", n);

    return 0;
}