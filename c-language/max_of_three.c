#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�ִ��� ã�� �Լ� ����
int max(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

// main �Լ�
int main()
{
    int a, b, c;

    // ����ڷκ��� �� ������ �Է� ����
    printf("�� ���� ������ �Է��ϼ���: ");
    scanf("%d %d %d", &a, &b, &c);

    // �ִ��� ����ϰ� ���
    int maximum = max(a, b, c);
    printf("�ִ��� %d�Դϴ�.\n", maximum);

    return 0;
}