#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 선언
int add(int a, int b);

//함수 정의
int add(int a, int b)
{
    int _ = 0;

    printf("첫 번째 값과 두 번째 값 더하기\n");

    printf("첫 번째 값 :  ");
    _ = scanf("%d", &a);

    printf("두 번쨰 값 :  ");
    _ = scanf("%d", &b);
    
    return a + b;
}

int main(void)
{
    int result = add(3, 4); // 함수 호출
    printf("결과 : %d\n", result); // 결과: 7

    return 0;
}