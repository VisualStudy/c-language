#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 무시
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int a, b, r, _;
    _ = scanf("%d %d", &a, &b);
    r = a % b;
    printf("%d", r);

    return EXIT_SUCCESS;
}