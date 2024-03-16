#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592654
int main(void)
{
    float r;
    int _ = 0;

    printf("반지름: ");
    _ = scanf("%f", &r);

    printf("원의 넓이: %f\n", ((r * r) * PI));
    printf("원의 둘레 길이: %f\n", (2 * PI * r));

    return 0;
}