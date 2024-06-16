#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//최댓값을 찾는 함수 정의
int max(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

// main 함수
int main()
{
    int a, b, c;

    // 사용자로부터 세 정수를 입력 받음
    printf("세 개의 정수를 입력하세요: ");
    scanf("%d %d %d", &a, &b, &c);

    // 최댓값을 계산하고 출력
    int maximum = max(a, b, c);
    printf("최댓값은 %d입니다.\n", maximum);

    return 0;
}