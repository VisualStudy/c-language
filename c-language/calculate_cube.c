#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) 
{
    int input, result, _;
    _ = scanf("%d", &input);
    result = pow(input, 3);
    printf("%d", result);

    return 0;
}