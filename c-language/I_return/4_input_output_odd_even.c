#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int number;
    printf("�� �Է�: ");
    scanf("%d", &number);

    if (number % 2 == 0) // ���� ���� number�� 2�� �������� �� �������� 0�̶��
    {
        printf("%d, �ʴ� ¦���α�!", number);
    }
    else // 2�� �������� �� �������� 0�� �ƴ϶��(�� if ��ȣ �� ������ �ƴ� ��츦 ����)
    {
        printf("%d, �ʴ� Ȧ����!", number);
    }
    
    return 0;
}