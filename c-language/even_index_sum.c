#include <stdio.h>

int main(void)
{
    int i = 0, sum = 0;
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for ( i = 0; i < 10; i = i + 2)
    {
        sum = sum + a[i];
    }
    
    printf("%d\n", sum);
    printf("%d", i);

    return 0;
}