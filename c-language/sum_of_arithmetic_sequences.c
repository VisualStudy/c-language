#include <stdio.h>
#pragma warning(disable:4996)

int main(void) // �������� ��
{
    int _ = 0;
    int i = 0;
    int n = 0;
    int d = 0;
    int sum = 0; // �ʱ�ȭ
    printf("\n ���� �Է� :  ");
    _ = scanf("%d", &i); // ����
    printf("\n ���� �Է� :  ");
    _ = scanf("%d", &n);
    printf("\n ���� �Է� :  ");
    _ = scanf("%d", &d);

    for (int p = i; p <= n; p = p + d)
    {
        sum = sum + p;
    }

    printf("\n\n 1 + 2 + ... + %d = %d", n, sum);

    return 0;
}