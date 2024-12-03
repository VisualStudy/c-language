#include <stdio.h>

int main(void)
{
    int num = 255;
    float pi = 3.14159;
    char letter = 'A';
    char str[] = "Hello, C programming!";

    printf("Integer: %d\n", num); // %d ����
    printf("Unsigned Integer: %u\n", num); // %u ��ȣ ���� ����

    printf("Hexadecimal (lowercase): %x\n", num); // %x 16���� �ҹ���
    printf("Hexadceimal (uppercase): %X\n", num); // %X 16���� �빮��

    printf("Floating point: %f\n", pi); // %f: �ε��Ҽ���(float, double)

    printf("character: %c\n", letter); // %c ����
    printf("String: %s\n", str);      //%s ���ڿ�

    return 0;
}