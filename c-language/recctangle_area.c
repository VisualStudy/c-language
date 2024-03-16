#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double width = 0.0;
    double height = 0.0;
    double area = 0.0;
    int _ = 0;

    printf("밑변: "); _ = scanf("%lf", &width);
    printf("높이: "); _ = scanf("%lf", &height);

    area = width * height;


    printf("사각형의 넓이: %.2lf\n", area);

    return 0;
}