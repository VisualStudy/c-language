#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sumsum(void)
{
    printf("�̰� sumsum() �Լ��Դϴ�.\n");
    printf("*\n");
    printf("asterisk\n");
}

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
};