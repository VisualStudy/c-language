#include <stdio.h>

int main(void)
{
    int num = 255;
    float pi = 3.14159;
    char letter = 'A';
    char str[] = "Hello, C programming!";

    printf("Integer: %d\n", num); // %d 정수
    printf("Unsigned Integer: %u\n", num); // %u 부호 없는 정수

    printf("Hexadecimal (lowercase): %x\n", num); // %x 16진수 소문자
    printf("Hexadceimal (uppercase): %X\n", num); // %X 16진수 대문자

    printf("Floating point: %f\n", pi); // %f: 부동소수점(float, double)

    printf("character: %c\n", letter); // %c 문자
    printf("String: %s\n", str);      //%s 문자열

    return 0;
}