#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int b[5];

    // �迭 a�� ���� �迭 b�� ����
    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i]; // �ùٸ� ����: b <- a
    }

    // ��� ���
    printf("�迭 b�� ����: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}