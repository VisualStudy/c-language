#include <stdio.h>

int main(void)
{
    int x;
    x = 97;
    char y;
    y = 'a';
    int i;

    //char str[4] = {"a, b, c, \0"}; // ���ڿ��� char �迭��
    //char str[3] = {"abcdef"};      // �����÷�
    /*char str[4] = {"abc\0"};
    char str[4] = {"abc"};
    char str[7] = {"abcd e"};
    char str[100] = {"�����Ӱ� 100 ����"};*/
    char str[] = {"��ٶ�Ÿ �̽����丮��"}; // �Ľ� �������� �ñ��
    char ztr[100];

    for (i = 0; str[i] != '\0'; i++)
    {
        ztr[i] = str[i];
    }
    ztr[i] = '\0';
    printf("%s\n", ztr);

    printf("97�� ���ڷ�: %c\n", x);
    printf("���� a�� ���ڷ�: %d\n", y);
    
    return 0;
}