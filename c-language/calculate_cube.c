#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

main() {
    int input, result;
    scanf("%d", &input);
    result = pow(input, 3);
    printf("%d", result);
}