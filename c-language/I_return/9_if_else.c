#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num;
    printf("���� �Է�: ");
    scanf("%d", &num);

    // if-else ���ǹ�
    if (num > 0)
    {
        printf("The number is positive.\n");
    }
    else if (num < 0)
    {
        printf("The number is negative.\n");
    }
    else
    {
        printf("The number is zero.\n");
    }

    // ���� ������
    printf("The number is %s.\n", (num % 2 == 0) ? "even" : "odd");

    return 0;
}