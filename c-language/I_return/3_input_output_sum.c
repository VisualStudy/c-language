#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num1, num2, sum;

    printf("ù ��° ���� �Է�: ");
    scanf("%d", &num1); // ù ��° ���� �Է� �ޱ�
    printf("�� ��° ���� �Է�: ");
    scanf("%d", &num2); // �� ��° ���� �Է� �ޱ�
    
    sum = num1 + num2; // ������ ���� sum�� ���� num1�� num2�� ������ ����
    printf("ù ��° ���� %d�� �� ��° ���� %d�� ���� %d�Դϴ�.", num1, num2, sum); //�˸°� ������ %d�� ���� �Ҵ� �� ���!

    return 0;
}