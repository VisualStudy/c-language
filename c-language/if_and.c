#include <stdio.h>

int main(void)
{
    int number = 1234;

    // [A] �� ������ ��� �����ϴ� ���
    if (number == 1234 && number >= 1000)
    {
        printf("�½��ϴ�.\n"); // ������ ��� ���� �� ����
    }

    // [B] �� ���� �� �ϳ��� �����ϴ� ���
    if (number == 1234 || number <= 1000)
    {
        printf("�ϳ��� ���̸� ��\n"); // �ϳ��� ���� �� ����
    }

    return 0;
}