#include <stdio.h>

main()
{
    int i = 10, j = 10, k = 30;
    i /= j; /*i = i / j; i = 1*/
    j -= i; // j = j - i; -> 9 
    k %= j; // k = k % j; k = 3
    printf("%d, %d, %d\n", i, j, k); // 1, 9, 3
}