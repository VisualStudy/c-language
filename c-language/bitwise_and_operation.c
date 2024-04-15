#include <stdio.h>

int main(void) {
    int a, b, result;
    a = 7; // a = 0111
    b = 4; // b = 0100 
    result = a & b; // 0100 = 4
    printf("%d", result); // 4
}