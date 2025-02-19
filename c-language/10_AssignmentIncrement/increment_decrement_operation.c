#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int num1 = 16, num2 = 44;
    int a = num1++; // a = 16, num1 = 17
    int b = --num2; // b = 43, num2 = 43 
    printf("%d", a + b); // 59

    return EXIT_SUCCESS;
}