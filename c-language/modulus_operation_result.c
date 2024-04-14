#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
    int a, b, r;
    scanf("%d %d", &a, &b);
    r = a % b;
    printf("%d", r);
}