#include <stdio.h>

int main(void)
{
    int n, i, sum = 0;

    printf("���� �Է�: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

    return 0;
}