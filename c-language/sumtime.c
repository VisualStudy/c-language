#include <stdio.h>

int main(void)
{
    int _, n, i, sum = 0;

    printf("���� �Է�: ");
    _ = scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

    return 0;
}