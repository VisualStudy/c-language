// 비교 연산자를 사용한 if 문 예시
#include <stdio.h>

int main(void)
{
    int x = 10; // x 초기화

    if (x == 10)
    {
        printf("x는 %d입니다.\n", x);
    }

    if (x != 20) // x가 20이 아닐 경우
    {
        printf("x는 20이 아닙니다.");
    }

    return 0;
}