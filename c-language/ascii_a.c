#include <stdio.h>

int main(void)
{
    int x;
    x = 97;
    
    char y;
    y = 'a';

    int str[4] = {"a, b, c, \0"};

    printf("97�� ���ڷ�: %c\n", x);
    printf("���� a�� ���ڷ�: %d\n", y);

    return 0;
}