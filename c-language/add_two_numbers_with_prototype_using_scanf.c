#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int _;
    int x;
    int y;
    int result;

    printf("�� ���� �Է¹ް� ���غ����?\n");
    
    printf("ù ��° ���� �Է��ؿ�!\n");
    _ = scanf("%d", &x);

    printf("�� ��° ���� �Է��ؿ�!\n");
    _ = scanf("%d", &y);

    printf("���� ���̽��մϴ�! ����� ��������!\n");

    result = add(x, y);

    printf("�� ���� ��: %d", result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}