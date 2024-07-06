// 조건의 동등성을 확인하는 예제
#include <stdio.h>

int main(void)
{
    const double PI = 3.14; // PI 값 초기화

    if (PI == 3.14) // PI가 3.14와 같은지 확인
    {
        printf("PI는 3.14입니다.\n"); // 조건이 참일 때 실행
    }
    else
    {
        printf("PI는 3.14가 아닙니다.\n "); // 조건이 거짓일 때 실행
    }

    return 0;
}