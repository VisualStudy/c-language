// else 문을 사용한 두 조건 처리 예시
#include <stdio.h>

int main(void)
{
    int score = 59; // 점수 초기화

    if (score >= 60)
    {
        printf("합격\n"); // 점수가 60 이상일 때 실행
    }
    else
    {
        printf("불합격\n"); // 점수가 60 미만일 때 실행
    }

    return 0;
}