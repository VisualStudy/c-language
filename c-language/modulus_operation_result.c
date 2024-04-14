#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 무시
#include <stdio.h>

main() {
    int a, b, r;
    scanf("%d %d", &a, &b);
    r = a % b;
    printf("%d", r);
}