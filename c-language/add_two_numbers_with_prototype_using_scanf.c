#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int _;
    int x;
    int y;
    int result;

    printf("두 수를 입력받고 더해볼까요?\n");
    
    printf("첫 번째 값을 입력해요!\n");
    _ = scanf("%d", &x);

    printf("두 번째 값도 입력해요!\n");
    _ = scanf("%d", &y);

    printf("아주 나이스합니다! 결과를 공개하죠!\n");

    result = add(x, y);

    printf("두 수의 합: %d", result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}