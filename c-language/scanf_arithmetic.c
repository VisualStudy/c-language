#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int i, j, k;

    scanf("%d %d", &i, &j);

    k = i + j;

    printf("%d + %d = %d\n", i, j, k);

    return 0;
}