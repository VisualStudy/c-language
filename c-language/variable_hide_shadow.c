#include <stdio.h>

int value = 100; // ���� ����

void ShowValue()
{
    int value = 50; // ���� ���� (�̸��� ���� ������ ����)
    printf("�Լ� ���ο��� value = %d\n", value); // ���� ������ ��µ�
}

int main(void)
{
    ShowValue();
    // ���� ���� �Լ� �ȿ� ���� ���� value�� �߰��Ѵٸ� ���� ������ ��. �׷��� ������ ������ �����Ƿ� ���� ������ ��µ�.
    printf("main���� ���� ���� value = %d\n", value); //���� ���� ���

    return 0;
}