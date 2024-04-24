#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    float radius;
    float area;

    printf("원의 반지름 입력: ");
    scanf("%f", &radius);

    area = 3.14 * radius * radius;
    printf("\n원의 면적 = %.2f\n", area);

    return 0;
}