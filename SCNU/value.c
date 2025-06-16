#include <stdio.h>

void shiftVal(int a, int b, int c);

int main(void)
{
    int a = 0, b = 10, c = 20;

    shiftVal(a, b, c);

    printf("메인 함수 안 a의 값: %d\n", a);
    printf("메인 함수 안 b의 값: %d\n", b);
    printf("메인 함수 안 c의 값: %d\n", c);

    return 0;
}

void shiftVal(int a, int b, int c)
{
    int temp;
    temp = c;
    c = b;
    b = a;
    a = temp;

    printf("shiftVal 함수 안 옮긴 a의 값: %d\n", a);
    printf("shiftVal 함수 안 옮긴 b의 값: %d\n", b);
    printf("shiftVal 함수 안 옮긴 c의 값: %d\n", c);
}