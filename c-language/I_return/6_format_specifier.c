#include <stdio.h>

int main(void)
{
    int num = 255;
    float pi = 3.14159;
    char letter = 'A';
    char str[] = "Hello, C programming!";

    printf("Integer: %d\n", num);
    printf("Unsigned Integer: %u\n", num);
    printf("Hexadecimal (lowercase): %x\n", num);
    printf("Hexadceimal (uppercase): %X\n", num);
    printf("Floating point: %f\n", pi);
    printf("character: %c\n", letter);
    printf("String: %s\n", str);

    return 0;
}