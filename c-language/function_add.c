#include <stdio.h>

//�Լ� ����
int add(int a, int b);

//�Լ� ����
int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int result = add(3, 4); // �Լ� ȣ��
    printf("��� : %d\n", result); // ���: 7

    return 0;
}