#include <stdio.h>

// �Լ� ���� ("�Լ� ����"�̶�� ��. prototype)
int add(int a, int b); // �����ݷ� ����

int main(void)
{
    int result = add(3, 7); // �Լ� ȣ�� �� ��ȯ���� ������ ���� result�� ����
    printf("%d\n", result);

    return 0;
}

// �Լ� ���� (�Լ� ��ü: body)
int add(int a, int b)
{
    return a + b;
}

// �Լ� ���Ǵ� �Լ� ������ ���� ��� ���� �Լ� ������ ���� ����