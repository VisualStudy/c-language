#include <stdio.h>

int main(void)
{
    int _, n, i, sum = 0;

    printf("정수 입력: ");
    _ = scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

    return 0;
}