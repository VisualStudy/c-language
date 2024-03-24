#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int i = 5, j = 4, k = 1, L, m;

    L = i > 5 || j != 0; // 1
    m = j <= 4 && k < 1; // 0

    printf("%d, %d\n", L, m);

    return 0;
}