#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    int _;

    char str1[100];
    char str2[100];

    // ����ڷκ��� ù ��° ���ڿ� �Է� �ޱ�
    printf("ù ��° ���ڿ��� �Է��ϼ���: ");
    _ = scanf("%s", str1);

    // ����ڷκ��� �� ��° ���ڿ� �Է� �ޱ�
    printf("�� ��° ���ڿ��� �Է��ϼ���: ");
    _ = scanf("%s", str2);

    // ���ڿ� ��
    int result = strcmp(str1, str2);

    if (result == 0)
    {
        printf("�� ���ڿ��� �����ϴ�.\n");
    }
    else if (result < 0)
    {
        printf("ù ��° ���ڿ��� �� ��° ���ڿ����� ���������� �տ� �ֽ��ϴ�.\n");
    }
    else
    {
        printf("ù ��° ���ڿ��� �� ��° ���ڿ����� ���������� �ڿ� �ֽ��ϴ�.\n");
    }

    return 0;
}