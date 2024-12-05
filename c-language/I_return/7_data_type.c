#include <stdio.h>

int main(void)
{
    int a = -10;
    unsigned int b = 10;
    float c = 3.14;
    double d = 2.718281828;
    char e = 'Z';

    printf("Signed Integer: %d\n", a);
    printf("Unsigned Integer: %u\n", b);

    printf("Float: %.2f\n", c);

    printf("Double: %.9f\n", d);
    printf("Character: %c\n", e);
    
    return 0;
}