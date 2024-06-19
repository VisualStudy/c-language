#include <stdio.h>

//함수 선언
int add(int a, int b);

//함수 정의
int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int result = add(3, 4); // 함수 호출
    printf("결과 : %d\n", result); // 결과: 7

    return 0;
}