#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;

    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)   // 짝수인지 확인
        {
            sum += i;
        }
    }

    printf("1~100 중 짝수만 더한 값: %d\n", sum);

    return 0;
}
