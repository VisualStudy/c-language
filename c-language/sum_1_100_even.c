#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;

    for (i = 2; i <= 100; i + 2)
    {
        sum = sum + i;
    }

    printf("1~100 �� ¦���� ���� ��: %d\n", sum);

    return 0;
}