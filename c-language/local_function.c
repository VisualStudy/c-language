#include <stdio.h>

void PrintLocal();

int main(void)
{
    PrintLocal();
    PrintLocal(); // �� ��° ȣ�� -> ���� ������ ���� ������

    return 0;
}

void PrintLocal()
{
    int local = 1; // �Լ� ȣ�� �ø��� ���� ������
    printf("���� ���� local�� �� = %d (�ּ�: %p)\n", local, &local);
}