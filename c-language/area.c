#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int _;
    float radius;
    float area;

    printf("���� ������ �Է�: ");
    _ = scanf("%f", &radius);
    area = 3.14 * radius * radius;
   
   printf("\n���� ���� = %.2f\n", area);

    return 0;
}