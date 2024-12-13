#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자 입력: ");
    scanf("%d", &num);

    // if-else 조건문
    if (num > 0)
    {
        printf("The number is positive.\n");
    }
    else if (num < 0)
    {
        printf("The number is negative.\n");
    }
    else
    {
        printf("The number is zero.\n");
    }

    // 삼항 연산자
    printf("The number is %s.\n", (num % 2 == 0) ? "even" : "odd");

    return 0;
}