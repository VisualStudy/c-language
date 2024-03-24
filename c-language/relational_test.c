#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int a = 5, b = 10, c = 15, d = 30, result;

    result = (((((a * 3) + b) > d) || ((c - (b / a)) <= d)) && 1);

    printf("%d\n", result);

    return EXIT_SUCCESS;
}