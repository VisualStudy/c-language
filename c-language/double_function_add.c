#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_int(void)
{
    int i;
    printf("���� �� �Է�: ");
    scanf("%d", &i);

    return i;
}

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int a = get_int();
    int b = get_int();

    int sum = add(a, b);
    printf("�� ������ ��: %d\n", sum);

    return 0;
}