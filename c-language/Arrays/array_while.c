// �迭�� ������ while ���� ����Ͽ� �ݺ������� ����ϴ� ����
#include <stdio.h>

int main(void)
{
    char see[] = "C language\n"; // ���� �迭 ���� �� �ʱ�ȭ

    int index = 0; // �ε��� ���� �ʱ�ȭ
    while (see[index]); // ���� �ε����� ���� ���
    {
        putchar(see[index]); // ���� �ε����� ���� ���
        index++; // �ε��� ����
    }

    return 0;
}