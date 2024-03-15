#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    float num1;
    double num2;
    long double num3;

    scanf("%f %lf %Lf", &num1, &num2, &num3);

    printf("%.15f\n%.15lf\n%.15Lf\n", num1, num2, num3);

    return 0;
}