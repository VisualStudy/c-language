#include <stdio.h>

void ShowGarbage();

int main(void)
{
    ShowGarbage();
    return 0;
}

void ShowGarbage()
{
    int x; // �ʱ�ȭ���� ���� showGarbage �Լ� �� ���� ����
    printf("�ʱ�ȭ���� ���� ���� ���� x�� ��: %d\n", x);
}