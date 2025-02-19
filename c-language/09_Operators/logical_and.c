#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

int main(void)
{
    printf("%d\n", 1 && 1); // 1
    printf("%d\n", 1 && 0); // 0
    printf("%d\n", 0 && 1); // 0
    printf("%d\n", 0 && 0); // 0

    printf("\n%d\n", true && true); // 1

    return 0;
}