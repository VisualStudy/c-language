#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14
#include <stdio.h>

int main(void)
{
    int _;
    float radius;
    float area;

    printf("���� ������ �Է�: ");
    _ = scanf("%f", &radius);
    area = PI * radius * radius;
   
   printf("\n���� ���� = %.2f\n", area);

    return 0;
}