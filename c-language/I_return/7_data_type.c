#include <stdio.h>

int main(void)
{
    int a = -10;
    unsigned int b = 10;
    float c = 3.14;
    double d = 2.718281828;
    char e = 'Z';

    printf("Signed Integer: %d\n", a); // ��ȣ�� �ִ� ������
    printf("Unsigned Integer: %u\n", b); // ��ȣ�� ���� ������

    printf("Float: %.2f\n", c); // �Ҽ� 2 ��° �ڸ����� 

    printf("Double: %.9f\n", d); // �Ҽ� 9 ��° �ڸ�����
    printf("Character: %c\n", e); // ����
    
    return 0;
}