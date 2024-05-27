#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    // 정수를 입력해서 평균내기 (단, 음수가 입력될 시 종료)
    int i = 0;
    int n = 0;
    int _ = 0;
    int sum = 0;

    while (1)
    {
        printf("\n 정수 입력 :  ");
        _ = scanf("%d", &n);

        if (n < 0) break;

        sum = sum + n;
        i++;
    }

    printf("\n\n 평균 = %lf", sum / (double)i);

    return 0;
}