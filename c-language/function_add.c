#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int add(int a, int b);

//�Լ� ����
int add(int a, int b)
{
    int _ = 0;

    printf("ù ��° ���� �� ��° �� ���ϱ�\n");

    printf("ù ��° �� :  ");
    _ = scanf("%d", &a);

    printf("�� ���� �� :  ");
    _ = scanf("%d", &b);
    
    return a + b;
}

int main(void)
{
    int result = add(3, 4); // �Լ� ȣ��
    printf("��� : %d\n", result); // ���: 7

    return 0;
}