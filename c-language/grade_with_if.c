#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)   // 오직 if, else if, else문만 사용하여 성적 계산하기
{
    int score;
    int _;
    printf("성적 입력: ");
    _ = scanf("%d", &score);
    if (score >= 90)
    {
        printf("A\n");
    }
    else if (score >= 80)
    {
        printf("B\n");
    }
    else if (score >= 70)
    {
        printf("C\n");
    }
    else if (score >= 60)
    {
        printf("D\n");
    }
    else
    {
        printf("F\n");
    }

    return 0;
}