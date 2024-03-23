#include <stdio.h>

int main(void)
{
    int i = 10, j = 10, k = 30;

    i /= j; // i = i / j; => i = 1
    j -= i; // j = j - 1; => j = 9
    k %= j; // k = k % 9; => k = 3

    printf("%d, %d, %d\n", i, j, k);

    return 0;
}