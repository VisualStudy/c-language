#include <stdio.h>

int main(void)
{
    int number = 1234;

    // [A] 두 조건이 모두 만족하는 경우
    if (number == 1234 && number >= 1000)
    {
        printf("맞습니다.\n"); // 조건이 모두 참일 때 실행
    }

    // [B] 두 조건 중 하나라도 만족하는 경우
    if (number == 1234 || number <= 1000)
    {
        printf("하나라도 참이면 참\n"); // 하나라도 참일 때 실행
    }

    return 0;
}