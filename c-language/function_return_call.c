// ��ȯ���� �ִ� �Լ�(������ ��ȯ��)
#include <stdio.h>

int SquareFunction(int x)   // �Է�: �Ű� ������ ����
{
    int r = x * x;          // ó��: �Լ��� ����
    return r;               // ���: ��ȯ���� ����
}

int main(void)
{
    int r = SquareFunction(2); // �Լ��� ȣ���ϰ� ��ȯ���� ����
    printf("%d\n", r); // ���: 4

    return 0;
}