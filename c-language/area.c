#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14
#include <stdio.h>

int main(void)
{
    int _;
    float radius;
    float area;

    printf("원의 반지름 입력: ");
    _ = scanf("%f", &radius);
    area = PI * radius * radius;
   
   printf("\n원의 면적 = %.2f\n", area);

    return 0;
}