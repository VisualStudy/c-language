#include <stdio.h>
#pragma warning (disable:4996)

int main(void)
{
    int i = 0; // �� �Է� ���� �� �ʱ�ȭ
    int _ = 0; // scanf ��� ����
    printf("���ϴ� �� �Է� :  ");
    _ = scanf("%d", &i);

    for (int j = 1; j <= 9; j++) // �Է� ���� �ܿ� 1 ~ 9���� ���ϱ�
    {
        printf("\n %d * %d = %d", i, j, i * j);
    }

    return 0;
}