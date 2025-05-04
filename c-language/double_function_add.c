#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_int(void)
{
    int i;
    printf("정수 값 입력: ");
    scanf("%d", &i);

    return i;
}

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int a = get_int();
    int b = get_int();

    int sum = add(a, b);
    printf("두 정수의 합: %d\n", sum);

    return 0;
}