#include <stdio.h>
#pragma warning(disable:4996)

int main(void) // 등차수열 합
{
    int _ = 0;
    int i = 0;
    int n = 0;
    int d = 0;
    int sum = 0; // 초기화
    printf("\n 초항 입력 :  ");
    _ = scanf("%d", &i); // 리셋
    printf("\n 말항 입력 :  ");
    _ = scanf("%d", &n);
    printf("\n 등차 입력 :  ");
    _ = scanf("%d", &d);

    for (int p = i; p <= n; p = p + d)
    {
        sum = sum + p;
    }

    printf("\n\n 1 + 2 + ... + %d = %d", n, sum);

    return 0;
}