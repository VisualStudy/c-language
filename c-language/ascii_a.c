#include <stdio.h>

int main(void)
{
    int x;
    x = 97;
    
    char y;
    y = 'a';

    char str[4] = {"a, b, c, \0"}; // ���ڿ��� char �迭��
    char str[3] = {"abcdef"};      // �����÷�
    char str[4] = {"abc\0"};
    char str[4] = {"abc"};

    printf("97�� ���ڷ�: %c\n", x);
    printf("���� a�� ���ڷ�: %d\n", y);

    return 0;
}