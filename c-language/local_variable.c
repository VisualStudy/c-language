#include <stdio.h>

void PrintNumber(void);

int main(void)
{
    int num = 20; // main �Լ��� ���� ����
    printf("main �ȿ��� num = %d\n", num);

    PrintNumber();

    printf("main �ȿ��� num = %d\n", num);

    return 0;
}

void PrintNumber(void)
{
    int num = 10;  // ���� ����
    printf("print_number �ȿ��� num = %d\n", num);
}