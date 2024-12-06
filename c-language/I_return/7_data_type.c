#include <stdio.h>

int main(void)
{
    int a = -10;
    unsigned int b = 10;
    float c = 3.14;
    double d = 2.718281828;
    char e = 'Z';

    printf("Signed Integer: %d\n", a); // 부호가 있는 정수형
    printf("Unsigned Integer: %u\n", b); // 부호가 없는 정수형

    printf("Float: %.2f\n", c); // 소수 2 번째 자리까지 

    printf("Double: %.9f\n", d); // 소수 9 번째 자리까지
    printf("Character: %c\n", e); // 문자
    
    return 0;
}